#!/usr/bin/env python3
"""Run real RTL PCI ring allocation/unwind functions under injected failures."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
from c_source import function

SOURCE = ROOT / "kernel/radio2g-linux-7.3-v1/overlay/drivers/net/wireless/realtek/rtlwifi/pci.c"

PRE = r'''
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef unsigned long ulong;
typedef uint64_t dma_addr_t;
#define DMA_FROM_DEVICE 1
#define DMA_TO_DEVICE 2
#define GFP_KERNEL 0
#define RTL_PCI_MAX_RX_QUEUE 2
#define RTL_PCI_MAX_TX_QUEUE_COUNT 9
#define RTL_PCI_MAX_RX_COUNT 4
#define RTL8192EE_BCN_TXBD_APERTURE_BYTES 256
#define BEACON_QUEUE 4
#define COMP_INIT 0
#define DBG_LOUD 0
#define HW_DESC_RX_PREPARE 1
#define HW_DESC_RXBUFF_ADDR 2
#define HW_DESC_RXPKT_LEN 3
#define HW_DESC_RXOWN 4
#define HW_DESC_RXERO 5
#define HW_DESC_TX_NEXTDESC_ADDR 6
#define lower_32_bits(x) ((u32)(x))
#define rtl_dbg(...) ((void)0)
#define pr_info(...) ((void)0)
#define pr_err(...) ((void)0)
struct device { int unused; };
struct pci_dev { struct device dev; };
struct sk_buff { u8 *data; unsigned int len; _Alignas(16) u8 cb[48]; };
struct sk_buff_head { unsigned int qlen; };
struct rtl_rx_desc { u32 dword[8]; };
struct rtl_rx_buffer_desc { u32 dword[4]; };
struct rtl_tx_desc { u32 dword[16]; };
struct rtl_tx_buffer_desc { u32 dword[16]; };
struct rtl8192_rx_ring {
 struct rtl_rx_desc *desc;
 struct rtl_rx_buffer_desc *buffer_desc;
 dma_addr_t dma;
 unsigned int idx;
 struct sk_buff *rx_buf[RTL_PCI_MAX_RX_COUNT];
};
struct rtl8192_tx_ring {
 struct rtl_tx_desc *desc;
 struct rtl_tx_buffer_desc *buffer_desc;
 dma_addr_t dma, buffer_desc_dma;
 unsigned int idx, entries, buffer_desc_stride, cur_tx_rp, cur_tx_wp;
 struct sk_buff_head queue;
};
struct rtl_pci {
 struct pci_dev *pdev;
 struct rtl8192_rx_ring rx_ring[RTL_PCI_MAX_RX_QUEUE];
 struct rtl8192_tx_ring tx_ring[RTL_PCI_MAX_TX_QUEUE_COUNT];
 unsigned int rxringcount, txringcount[RTL_PCI_MAX_TX_QUEUE_COUNT];
 u16 rxbuffersize;
 bool txbd_compact32, irq_line_lifecycle_managed;
};
struct ieee80211_hw;
struct rtl_hal_ops { void (*set_desc)(struct ieee80211_hw *, u8 *, bool, int, u8 *); };
struct rtl_hal_cfg { struct rtl_hal_ops *ops; };
struct rtl_priv { struct rtl_pci pci; struct rtl_hal_cfg *cfg; bool use_new_trx_flow; };
struct ieee80211_hw { struct rtl_priv *priv; };
#define rtl_priv(hw) ((hw)->priv)
#define rtl_pcipriv(hw) ((hw)->priv)
#define rtl_pcidev(p) (&(p)->pci)
struct allocation {
 void *pointer, *raw;
 dma_addr_t dma;
 size_t bytes;
 bool live;
};
static struct allocation coherent[32], streaming[32];
static unsigned int coherent_calls, map_calls, skb_calls, skb_live;
static unsigned int fail_coherent, unalign_coherent, fail_skb, fail_map;
static unsigned int maps_live, coherent_live, prepared;
static bool compact;
static struct rtl_priv priv;
static struct ieee80211_hw hw = { .priv = &priv };
static struct pci_dev pdev;

static void *dma_alloc_coherent(struct device *dev, size_t bytes, dma_addr_t *dma, int flags)
{
 (void)dev; (void)flags;
 unsigned int call = ++coherent_calls;
 assert(call < 32 && bytes > 0);
 if (call == fail_coherent) return NULL;
 size_t raw_bytes = (bytes + 511) & ~(size_t)255;
 void *raw = aligned_alloc(256, raw_bytes);
 assert(raw);
 memset(raw, 0, raw_bytes);
 void *pointer = (u8 *)raw + (call == unalign_coherent ? 1 : 0);
 *dma = 0x100000000ULL + call * 4096;
 coherent[call] = (struct allocation){pointer, raw, *dma, bytes, true};
 coherent_live++;
 return pointer;
}
static void dma_free_coherent(struct device *dev, size_t bytes, void *pointer, dma_addr_t dma)
{
 (void)dev;
 unsigned int call = (dma - 0x100000000ULL) / 4096;
 assert(call > 0 && call < 32 && coherent[call].live);
 assert(coherent[call].pointer == pointer && coherent[call].bytes == bytes);
 assert(coherent[call].dma == dma);
 free(coherent[call].raw);
 coherent[call].live = false;
 coherent_live--;
}
static struct sk_buff *dev_alloc_skb(unsigned int bytes)
{
 if (++skb_calls == fail_skb) return NULL;
 struct sk_buff *skb = calloc(1, sizeof(*skb));
 assert(skb);
 skb->data = calloc(1, bytes);
 assert(skb->data);
 skb_live++;
 return skb;
}
static u8 *skb_tail_pointer(struct sk_buff *skb) { return skb->data + skb->len; }
static dma_addr_t dma_map_single(struct device *dev, void *pointer, size_t bytes, int direction)
{
 (void)dev;
 assert(direction == DMA_FROM_DEVICE);
 unsigned int call = ++map_calls;
 assert(call < 32);
 if (call == fail_map) return UINT64_MAX;
 dma_addr_t dma = 0x200000000ULL + call * 4096;
 streaming[call] = (struct allocation){pointer, NULL, dma, bytes, true};
 maps_live++;
 return dma;
}
static bool dma_mapping_error(struct device *dev, dma_addr_t dma)
{
 (void)dev;
 return dma == UINT64_MAX;
}
static void dma_unmap_single(struct device *dev, dma_addr_t dma, size_t bytes, int direction)
{
 (void)dev;
 assert(direction == DMA_FROM_DEVICE);
 unsigned int call = (dma - 0x200000000ULL) / 4096;
 assert(call > 0 && call < 32 && streaming[call].live);
 assert(streaming[call].dma == dma && streaming[call].bytes == bytes);
 streaming[call].live = false;
 maps_live--;
}
static void kfree_skb(struct sk_buff *skb)
{
 assert(skb && skb_live);
 for (unsigned int i = 1; i < 32; i++)
  assert(!streaming[i].live || streaming[i].pointer != skb->data);
 free(skb->data);
 free(skb);
 skb_live--;
}
static void skb_queue_head_init(struct sk_buff_head *queue) { queue->qlen = 0; }
static unsigned int skb_queue_len(struct sk_buff_head *queue) { return queue->qlen; }
static struct sk_buff *__skb_dequeue(struct sk_buff_head *queue)
{
 (void)queue;
 assert(!"TX data queues are empty during initialization");
 return NULL;
}
static u8 *rtl_pci_txbd_entry(struct rtl8192_tx_ring *ring, unsigned int idx)
{
 return (u8 *)ring->buffer_desc + idx * ring->buffer_desc_stride;
}
static dma_addr_t _rtl_pci_tx_buffer_addr(struct ieee80211_hw *hw, struct rtl8192_tx_ring *ring, u8 *entry)
{
 (void)hw; (void)ring; (void)entry;
 assert(!"TX data queues are empty during initialization");
 return 0;
}
static bool rtl_pci_txbd_queue_compact(struct rtl_priv *rtlpriv, struct rtl_pci *rtlpci, unsigned int prio)
{
 (void)rtlpriv; (void)rtlpci; (void)prio;
 return compact;
}
static void dma_wmb(void) {}
static void fake_set_desc(struct ieee80211_hw *hw, u8 *entry, bool tx, int field, u8 *value)
{
 (void)hw;
 assert(entry);
 if (field == HW_DESC_RX_PREPARE) {
  dma_addr_t dma = *(dma_addr_t *)value;
  unsigned int call = (dma - 0x200000000ULL) / 4096;
  assert(call > 0 && call < 32 && streaming[call].live);
  prepared++;
 } else if (field == HW_DESC_RXOWN || field == HW_DESC_RXERO) {
  assert(!tx && *value == 1);
 }
}
static struct rtl_hal_ops ops = { .set_desc = fake_set_desc };
static struct rtl_hal_cfg cfg = { .ops = &ops };
'''

POST = r'''
static void assert_empty(void)
{
 assert(coherent_live == 0 && maps_live == 0 && skb_live == 0);
 for (unsigned int i = 0; i < RTL_PCI_MAX_RX_QUEUE; i++) {
  assert(!priv.pci.rx_ring[i].desc && !priv.pci.rx_ring[i].buffer_desc);
  for (unsigned int j = 0; j < priv.pci.rxringcount; j++)
   assert(!priv.pci.rx_ring[i].rx_buf[j]);
 }
 for (unsigned int i = 0; i < RTL_PCI_MAX_TX_QUEUE_COUNT; i++)
  assert(!priv.pci.tx_ring[i].desc && !priv.pci.tx_ring[i].buffer_desc);
}
static void reset(bool new_flow, bool use_compact)
{
 assert_empty();
 memset(&priv, 0, sizeof(priv));
 memset(coherent, 0, sizeof(coherent));
 memset(streaming, 0, sizeof(streaming));
 coherent_calls = map_calls = skb_calls = prepared = 0;
 fail_coherent = unalign_coherent = fail_skb = fail_map = 0;
 priv.cfg = &cfg;
 priv.use_new_trx_flow = new_flow;
 priv.pci.pdev = &pdev;
 priv.pci.rxringcount = RTL_PCI_MAX_RX_COUNT;
 priv.pci.rxbuffersize = 256;
 priv.pci.txbd_compact32 = compact = use_compact;
 priv.pci.irq_line_lifecycle_managed = true;
 for (unsigned int i = 0; i < RTL_PCI_MAX_TX_QUEUE_COUNT; i++)
  priv.pci.txringcount[i] = i + 2;
}
static void retry_after_failure(void)
{
 assert_empty();
 fail_coherent = unalign_coherent = fail_skb = fail_map = 0;
 coherent_calls = map_calls = skb_calls = prepared = 0;
 assert(_rtl_pci_init_trx_ring(&hw) == 0);
 assert(coherent_live == (priv.use_new_trx_flow ? 20 : 11));
 assert(skb_live == 8 && maps_live == 8);
 assert(_rtl_pci_deinit_trx_ring(&hw) == 0);
 assert_empty();
 assert(_rtl_pci_deinit_trx_ring(&hw) == 0);
 assert_empty();
}
static void allocation_cases(bool new_flow, bool use_compact)
{
 unsigned int coherent_points = new_flow ? 20 : 11;
 for (unsigned int i = 1; i <= coherent_points; i++) {
  reset(new_flow, use_compact);
  fail_coherent = i;
  assert(_rtl_pci_init_trx_ring(&hw) == -ENOMEM);
  retry_after_failure();
  reset(new_flow, use_compact);
  unalign_coherent = i;
  assert(_rtl_pci_init_trx_ring(&hw) == -ENOMEM);
  retry_after_failure();
 }
 for (unsigned int i = 1; i <= 8; i++) {
  reset(new_flow, use_compact);
  fail_skb = i;
  assert(_rtl_pci_init_trx_ring(&hw) == -ENOMEM);
  retry_after_failure();
  reset(new_flow, use_compact);
  fail_map = i;
  assert(_rtl_pci_init_trx_ring(&hw) == -ENOMEM);
  retry_after_failure();
 }
}
int main(void)
{
 allocation_cases(true, false);
 allocation_cases(true, true);
 allocation_cases(false, false);
 puts("PASS real RTL PCI rings: 150 injected failures, exact-size frees, retry and idempotent release");
 return 0;
}
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cc", default="gcc")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    pci = SOURCE.read_text()
    functions = [function(pci, signature) for signature in (
        "static void _rtl_pci_prepare_one_rxdesc(",
        "static int _rtl_pci_init_one_rxdesc(",
        "static int _rtl_pci_init_tx_ring(",
        "static int _rtl_pci_init_rx_ring(",
        "static void _rtl_pci_free_tx_ring(",
        "static void _rtl_pci_free_rx_ring(",
        "static int _rtl_pci_init_trx_ring(",
        "static int _rtl_pci_deinit_trx_ring(",
    )]
    fixture = args.output / "pci_rings_fixture.c"
    fixture.write_text(PRE + "\n".join(functions) + POST)
    binary = args.output / "pci_rings_fixture"
    command = [args.cc, "-std=gnu11", "-O1", "-g", "-fno-omit-frame-pointer",
               "-fsanitize=address,undefined", "-fno-pie", "-no-pie", str(fixture), "-o", str(binary)]
    build = subprocess.run(command, capture_output=True, text=True)
    (args.output / "build.log").write_text(build.stdout + build.stderr)
    if build.returncode:
        raise RuntimeError(build.stderr)
    environment = os.environ.copy()
    environment.update(ASAN_OPTIONS="detect_leaks=1", UBSAN_OPTIONS="halt_on_error=1")
    result = subprocess.run([str(binary)], env=environment, capture_output=True, text=True)
    (args.output / "run.log").write_text(result.stdout + result.stderr)
    report = {
        "status": "PASS" if result.returncode == 0 else "FAIL",
        "scope": "Host execution of production PCI ring functions with 150 injected allocation/mapping failures",
        "hardware_accessed": False,
        "source_sha256": hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
        "sanitizers": ["address", "undefined", "leak"],
        "run_output": result.stdout,
        "exit_code": result.returncode,
    }
    (args.output / "result.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(report, indent=2))
    if result.returncode:
        raise RuntimeError(result.stderr)


if __name__ == "__main__":
    main()
