#!/usr/bin/env python3
"""Exercise the real RTL PCI RX and C2H functions with host fault injection."""

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

SOURCE = ROOT / "kernel/radio2g-linux-7.3-v1/overlay/drivers/net/wireless/realtek/rtlwifi"

PRE = r'''
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint16_t __le16;
typedef uint64_t dma_addr_t;
#define likely(x) (x)
#define unlikely(x) (x)
#define min_t(type, a, b) ((type)(a) < (type)(b) ? (type)(a) : (type)(b))
#define lower_32_bits(x) ((u32)(x))
#define le16_to_cpu(x) (x)
#define DMA_FROM_DEVICE 1
#define RTL_PCI_RX_MPDU_QUEUE 0
#define RTL_PCI_MAX_RX_COUNT 4
#define FCS_LEN 4
#define C2H_PACKET 1
#define NL80211_IFTYPE_AP 3
#define BAND_ON_2_4G 0
#define COMP_ERR 0
#define COMP_FW 0
#define COMP_TX_REPORT 0
#define DBG_WARNING 0
#define DBG_LOUD 0
#define DBG_TRACE 0
#define DBG_DMESG 0
#define HW_DESC_RX_PREPARE 1
#define HW_DESC_RXBUFF_ADDR 2
#define HW_DESC_RXPKT_LEN 3
#define HW_DESC_RXOWN 4
#define HW_DESC_RXERO 5
#define HW_DESC_OWN 6
#define U8_MAX 255
#define C2H_DATA_OFFSET 2
#define GET_C2H_CMD_ID(data) ((data)[0])
#define GET_C2H_DATA_PTR(data) ((data) + C2H_DATA_OFFSET)
#define RTL_SPEC_EXT_C2H 4
#define GET_TX_REPORT_SN_V1(data) ((data)[6])
#define GET_TX_REPORT_ST_V1(data) ((data)[0] & 0xc0)
#define GET_TX_REPORT_RETRY_V1(data) ((data)[2] & 0x3f)
#define GET_TX_REPORT_SN_V2(data) ((data)[6])
#define GET_TX_REPORT_ST_V2(data) ((data)[7] & 0xc0)
#define GET_TX_REPORT_RETRY_V2(data) ((data)[8] & 0x3f)
#define C2H_DBG 0
#define C2H_TXBF 1
#define C2H_TX_REPORT 3
#define C2H_RA_RPT 4
#define C2H_BT_INFO 9
#define C2H_BT_MP 11
#define rtl_dbg(...) ((void)0)
#define pr_info_once(...) ((void)0)
#define pr_info(...) ((void)0)
#define skb_queue_walk(queue, skb) for ((skb) = NULL; (skb) != NULL; )
struct device { int unused; };
struct pci_dev { struct device dev; };
struct ieee80211_hdr { __le16 frame_control; u16 duration; u8 addr1[6], addr2[6], addr3[6]; __le16 seq_ctrl; };
struct ieee80211_rx_status { int signal; };
struct rtl_stats {
 int signal, rate, rx_drvinfo_size, rx_bufshift, packet_report_type;
 bool crc, hwerror, icv, is_ht, is_cck;
};
struct sk_buff { u8 *head, *data, *tail, *end; unsigned int len; _Alignas(16) u8 cb[48]; struct ieee80211_rx_status rx_status; };
struct sk_buff_head { unsigned int qlen; };
struct rtl_rx_desc { u32 dword[8]; };
struct rtl_rx_buffer_desc { u32 dword[4]; };
struct rtl8192_rx_ring {
 struct rtl_rx_desc *desc;
 struct rtl_rx_buffer_desc *buffer_desc;
 unsigned int idx, next_rx_rp;
 struct sk_buff *rx_buf[RTL_PCI_MAX_RX_COUNT];
};
struct rtl_pci { struct pci_dev *pdev; struct rtl8192_rx_ring rx_ring[2]; unsigned int rxringcount; u16 rxbuffersize; };
struct ieee80211_hw;
struct rtl_hal_ops {
 void (*set_desc)(struct ieee80211_hw *, u8 *, bool, int, u8 *);
 u32 (*get_desc)(struct ieee80211_hw *, u8 *, bool, int);
 unsigned int (*rx_desc_buff_remained_cnt)(struct ieee80211_hw *, u8);
 bool (*query_rx_desc)(struct ieee80211_hw *, struct rtl_stats *, struct ieee80211_rx_status *, u8 *, struct sk_buff *);
 void (*rx_check_dma_ok)(struct ieee80211_hw *, u8 *, u8);
 void (*led_control)(struct ieee80211_hw *, int);
 void (*c2h_ra_report_handler)(struct ieee80211_hw *, u8 *, u8);
 bool (*get_btc_status)(void);
};
struct rtl_btc_ops {
 void (*btc_btinfo_notify)(void *, u8 *, u8);
 void (*btc_btmpinfo_notify)(void *, u8 *, u8);
};
struct rtlwifi_tx_info { u16 sn; };
struct rtl_tx_report { struct sk_buff_head queue; u16 last_recv_sn; };
struct rtl_cfg { struct rtl_hal_ops *ops; unsigned int spec_ver; };
struct rtl_priv {
 struct rtl_pci pci;
 struct rtl_cfg *cfg;
 bool use_new_trx_flow;
 struct { int num_rx_inperiod, num_tx_inperiod; } link_info;
 struct { unsigned int rxbytesunicast; } stats;
 struct { int opmode; } mac80211;
 struct { int current_bandtype; } rtlhal;
 struct { struct rtl_btc_ops *btc_ops; } btcoexist;
 struct { void *rtl_wq; int c2hcmd_wq; } works;
 struct sk_buff_head c2hcmd_queue;
 struct rtl_tx_report tx_report;
};
struct ieee80211_hw { struct rtl_priv *priv; };
struct rtl_pci_hgw500_eapol { u16 hdr_len, eapol_len, key_info, key_len; u8 version, type, key_desc; };
static bool hgw500_eapol_trace;
static unsigned int allocations, mappings, unmaps, freed, delivered, commands;
static unsigned int fail_alloc, fail_map, remaining, packet_length, driver_info, buffer_shift;
static __le16 frame_control;
static bool query_accept = true, packet_command, next_multicast;
static unsigned int serial, map_order, unmap_order, prepare_order, barrier_order, publish_order;
static unsigned int own_order, address_order, length_order, query_calls;
static struct sk_buff *buffers[128];
static dma_addr_t live_maps[128];
static unsigned int buffer_count, map_count;
static struct rtl_priv *rtl_priv(struct ieee80211_hw *hw) { return hw->priv; }
static struct rtl_priv *rtl_pcipriv(struct ieee80211_hw *hw) { return hw->priv; }
static struct rtl_pci *rtl_pcidev(struct rtl_priv *priv) { return &priv->pci; }
static void dma_wmb(void) { barrier_order = ++serial; }
static void dma_rmb(void) { ++serial; }
static u8 *skb_tail_pointer(struct sk_buff *skb) { return skb->tail; }
static int skb_tailroom(struct sk_buff *skb) { return (int)(skb->end - skb->tail); }
static int skb_headroom(struct sk_buff *skb) { return (int)(skb->data - skb->head); }
static struct sk_buff *dev_alloc_skb(unsigned int bytes) {
 if (++allocations == fail_alloc) return NULL;
 struct sk_buff *skb = calloc(1, sizeof(*skb)); assert(skb);
 skb->head = malloc(bytes); assert(skb->head);
 skb->data = skb->tail = skb->head; skb->end = skb->head + bytes;
 memset(skb->head, 0, bytes);
 assert(buffer_count < 128); buffers[buffer_count++] = skb;
 return skb;
}
static bool mapping_live(dma_addr_t address) {
 if (!address) return false;
 for (unsigned int i = 0; i < map_count; i++) if (live_maps[i] == address) return true;
 return false;
}
static dma_addr_t dma_map_single(struct device *dev, void *data, unsigned int bytes, int direction) {
 (void)dev; (void)data; (void)bytes; assert(direction == DMA_FROM_DEVICE);
 if (++mappings == fail_map) return UINT64_MAX;
 dma_addr_t address = 0x100000000ULL + mappings * 0x1000;
 assert(map_count < 128); live_maps[map_count++] = address;
 map_order = ++serial; return address;
}
static bool dma_mapping_error(struct device *dev, dma_addr_t address) { (void)dev; return address == UINT64_MAX; }
static void dma_unmap_single(struct device *dev, dma_addr_t address, unsigned int bytes, int direction) {
 (void)dev; (void)bytes; assert(direction == DMA_FROM_DEVICE); assert(mapping_live(address));
 for (unsigned int i = 0; i < map_count; i++) if (live_maps[i] == address) live_maps[i] = 0;
 unmaps++; unmap_order = ++serial;
}
static void dev_kfree_skb_any(struct sk_buff *skb) {
 assert(skb); assert(!mapping_live(*(dma_addr_t *)skb->cb));
 for (unsigned int i = 0; i < buffer_count; i++) if (buffers[i] == skb) buffers[i] = NULL;
 free(skb->head); free(skb); freed++;
}
#define kfree_skb dev_kfree_skb_any
static void skb_reserve(struct sk_buff *skb, unsigned int bytes) {
 assert(skb->len == 0); assert(bytes <= (unsigned int)skb_tailroom(skb));
 skb->data += bytes; skb->tail += bytes;
}
static void skb_put(struct sk_buff *skb, unsigned int bytes) {
 assert(bytes <= (unsigned int)skb_tailroom(skb)); skb->tail += bytes; skb->len += bytes;
}
static void skb_push(struct sk_buff *skb, unsigned int bytes) {
 assert(bytes <= (unsigned int)skb_headroom(skb)); skb->data -= bytes; skb->len += bytes;
}
static void skb_trim(struct sk_buff *skb, unsigned int bytes) { assert(bytes <= skb->len); skb->len = bytes; skb->tail = skb->data + bytes; }
static bool of_machine_is_compatible(const char *name) { (void)name; return true; }
static __le16 rtl_get_fc(struct sk_buff *skb) { assert(skb->len >= 2); __le16 fc; memcpy(&fc, skb->data, 2); return fc; }
static struct ieee80211_hdr *rtl_get_hdr(struct sk_buff *skb) { return (struct ieee80211_hdr *)skb->data; }
static int ieee80211_hdrlen(__le16 fc) { return (fc & 0x0c) == 4 ? 10 : 24; }
static bool ieee80211_is_data(__le16 fc) { return (fc & 0x0c) == 8; }
static bool ieee80211_is_beacon(__le16 fc) { return fc == 0x80; }
static bool ieee80211_is_probe_resp(__le16 fc) { return fc == 0x50; }
static bool ieee80211_has_protected(__le16 fc) { return fc & 0x4000; }
static bool ieee80211_has_retry(__le16 fc) { return fc & 0x800; }
static bool is_broadcast_ether_addr(const u8 *address) { return address[0] == 0xff; }
static bool is_multicast_ether_addr(const u8 *address) { return address[0] & 1; }
#define IEEE80211_SKB_RXCB(skb) (&(skb)->rx_status)
#define LED_CTL_RX 1
static bool rtl_pci_hgw500_match_eapol(struct ieee80211_hw *hw, struct sk_buff *skb, __le16 fc, struct rtl_pci_hgw500_eapol *meta) { (void)hw; (void)skb; (void)fc; (void)meta; return false; }
static bool rtl_pci_hgw500_eapol_should_log(bool tx, unsigned int *event) { (void)tx; (void)event; return false; }
#define rtl_is_special_data(...) ((void)0)
#define rtl_collect_scan_list(...) ((void)0)
#define rtl_beacon_statistic(...) ((void)0)
#define rtl_p2p_info(...) ((void)0)
#define rtl_swlps_beacon(...) ((void)0)
#define rtl_recognize_peer(...) ((void)0)
#define rtl_lps_leave(...) ((void)0)
static void rtl_c2hcmd_enqueue(struct ieee80211_hw *, struct sk_buff *);
static void _rtl_pci_rx_to_mac80211(struct ieee80211_hw *hw, struct sk_buff *skb, struct ieee80211_rx_status status) {
 (void)hw; (void)status; assert(skb->len == packet_length); assert((uintptr_t)skb->data % 2 == 0);
 assert(rtl_get_fc(skb) == frame_control); delivered++; dev_kfree_skb_any(skb);
}
static void fake_set_desc(struct ieee80211_hw *hw, u8 *entry, bool tx, int name, u8 *value) {
 (void)entry; assert(!tx);
 struct rtl_pci *pci = &hw->priv->pci;
 struct sk_buff *skb = pci->rx_ring[0].rx_buf[pci->rx_ring[0].idx];
 assert(skb && mapping_live(*(dma_addr_t *)skb->cb));
 if (name == HW_DESC_RX_PREPARE) { assert(mapping_live(*(dma_addr_t *)value)); prepare_order = ++serial; }
 if (name == HW_DESC_RXBUFF_ADDR) address_order = ++serial;
 if (name == HW_DESC_RXPKT_LEN) length_order = ++serial;
 if (name == HW_DESC_RXOWN) {
  assert(*value == 1 && address_order < barrier_order && length_order < barrier_order);
  own_order = prepare_order = ++serial; if (remaining) remaining--;
 }
 if (name == HW_DESC_RXERO) assert(*value == 1);
}
static u32 fake_get_desc(struct ieee80211_hw *hw, u8 *entry, bool tx, int name) {
 (void)hw; (void)entry; assert(!tx); return name == HW_DESC_OWN ? remaining == 0 : packet_length;
}
static unsigned int fake_remaining(struct ieee80211_hw *hw, u8 queue) { (void)hw; (void)queue; return remaining; }
static bool fake_query(struct ieee80211_hw *hw, struct rtl_stats *stats, struct ieee80211_rx_status *status, u8 *desc, struct sk_buff *skb) {
 (void)hw; (void)status; (void)desc; query_calls++;
 assert(!mapping_live(*(dma_addr_t *)skb->cb));
 stats->rx_drvinfo_size = driver_info; stats->rx_bufshift = buffer_shift;
 stats->packet_report_type = packet_command ? C2H_PACKET : 0;
 unsigned int offset = driver_info + buffer_shift + (hw->priv->use_new_trx_flow ? 24 : 0);
 if (offset + packet_length <= (unsigned int)skb_tailroom(skb)) {
  if (packet_command) {
   if (packet_length) skb->data[offset] = C2H_BT_INFO;
  } else {
   struct ieee80211_hdr header = { .frame_control = frame_control };
   header.addr1[0] = next_multicast ? 1 : 2;
   memcpy(skb->data + offset, &header, min_t(unsigned int, packet_length, sizeof(header)));
   next_multicast = true;
  }
 }
 return query_accept;
}
static void fake_dma_check(struct ieee80211_hw *hw, u8 *entry, u8 queue) { (void)hw; (void)entry; (void)queue; }
static void fake_led(struct ieee80211_hw *hw, int action) { (void)hw; (void)action; }
static bool fake_btc(void) { return false; }
static void rtl_write_word(struct rtl_priv *priv, unsigned int reg, unsigned int value) {
 assert(reg == 0x3b4 && value < priv->pci.rxringcount);
 assert(prepare_order < barrier_order && barrier_order > publish_order);
 publish_order = ++serial; assert(remaining); remaining--;
}
static struct rtlwifi_tx_info *rtl_tx_skb_cb_info(struct sk_buff *skb) { return (struct rtlwifi_tx_info *)skb->cb; }
#define skb_unlink(...) ((void)0)
#define rtl_tx_status(...) ((void)0)
static void skb_queue_tail(struct sk_buff_head *queue, struct sk_buff *skb) { (void)skb; queue->qlen++; commands++; }
static void queue_delayed_work(void *queue, void *work, unsigned int delay) { (void)queue; (void)work; (void)delay; }
'''

POST = r'''
static struct rtl_hal_ops ops = {
 .set_desc = fake_set_desc, .get_desc = fake_get_desc,
 .rx_desc_buff_remained_cnt = fake_remaining, .query_rx_desc = fake_query,
 .rx_check_dma_ok = fake_dma_check, .led_control = fake_led, .get_btc_status = fake_btc,
};
static struct rtl_cfg cfg = { .ops = &ops };
static struct pci_dev pdev;
static struct rtl_priv priv;
static struct ieee80211_hw hw = { .priv = &priv };
static struct rtl_rx_buffer_desc descriptors[RTL_PCI_MAX_RX_COUNT];
static struct rtl_rx_desc old_descriptors[RTL_PCI_MAX_RX_COUNT];
static void clean(void) {
 for (unsigned int i = 0; i < buffer_count; i++) if (buffers[i]) {
  dma_addr_t address = *(dma_addr_t *)buffers[i]->cb;
  if (mapping_live(address)) dma_unmap_single(&pdev.dev, address, 256, DMA_FROM_DEVICE);
  dev_kfree_skb_any(buffers[i]);
 }
 buffer_count = map_count = 0;
}
static void reset(bool new_flow) {
 clean(); memset(&priv, 0, sizeof(priv)); cfg.spec_ver = 0;
 priv.cfg = &cfg; priv.use_new_trx_flow = new_flow;
 priv.pci.pdev = &pdev; priv.pci.rxringcount = RTL_PCI_MAX_RX_COUNT; priv.pci.rxbuffersize = 256;
 priv.pci.rx_ring[0].buffer_desc = descriptors; priv.pci.rx_ring[0].desc = old_descriptors;
 allocations = mappings = unmaps = freed = delivered = commands = query_calls = 0;
 serial = map_order = unmap_order = prepare_order = barrier_order = publish_order = 0;
 own_order = address_order = length_order = 0;
 fail_alloc = fail_map = remaining = 0; query_accept = true; packet_command = next_multicast = false;
 packet_length = 32; driver_info = 16; buffer_shift = 0; frame_control = 8;
 for (unsigned int i = 0; i < RTL_PCI_MAX_RX_COUNT; i++) {
  u8 *entry = new_flow ? (u8 *)&descriptors[i] : (u8 *)&old_descriptors[i];
  assert(_rtl_pci_init_one_rxdesc(&hw, entry, 0, i));
 }
 serial = map_order = unmap_order = prepare_order = barrier_order = publish_order = 0;
 remaining = 1;
}
static void receive_cases(void) {
 reset(true); buffer_shift = 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1);
 assert(delivered == 1 && map_order < unmap_order && prepare_order < publish_order);
 assert(priv.pci.rx_ring[0].idx == 1 && priv.pci.rx_ring[0].next_rx_rp == 1);
 reset(true); struct sk_buff *original = priv.pci.rx_ring[0].rx_buf[0];
 fail_alloc = allocations + 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1);
 assert(priv.pci.rx_ring[0].rx_buf[0] == original && unmaps == 0 && freed == 0 && delivered == 0);
 assert(mapping_live(*(dma_addr_t *)original->cb) && publish_order > prepare_order);
 reset(true); original = priv.pci.rx_ring[0].rx_buf[0]; fail_map = mappings + 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1);
 assert(priv.pci.rx_ring[0].rx_buf[0] == original && unmaps == 0 && freed == 1 && query_calls == 0);
 reset(true); query_accept = false;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0 && freed == 1);
 reset(true); packet_length = 240;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0 && freed == 1);
 reset(true); packet_length = 216;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 1);
 reset(true); packet_length = 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0);
 reset(true); packet_length = 27;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0);
 reset(true); packet_length = 28;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 1);
 reset(true); frame_control = 0xd4; packet_length = 13;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0);
 reset(true); frame_control = 0xd4; packet_length = 14;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 1);
 reset(true); packet_command = true; packet_length = 2;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0 && commands == 1);
 reset(true); packet_command = true; packet_length = 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && delivered == 0 && commands == 0);
 reset(true); remaining = 2;
 assert(_rtl_pci_rx_interrupt(&hw, 2) == 2 && delivered == 2);
 assert(priv.link_info.num_rx_inperiod == 1 && priv.stats.rxbytesunicast == 32);
 reset(false); fail_alloc = allocations + 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && unmaps == 0 && own_order > barrier_order);
 reset(false); priv.pci.rx_ring[0].idx = 3; fail_alloc = allocations + 1;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && priv.pci.rx_ring[0].idx == 0);
 reset(true); priv.pci.rx_ring[0].idx = priv.pci.rx_ring[0].next_rx_rp = 3;
 assert(_rtl_pci_rx_interrupt(&hw, 1) == 1 && priv.pci.rx_ring[0].next_rx_rp == 0);
}
static void command_cases(void) {
 reset(true);
 for (unsigned int bytes = 0; bytes < 2; bytes++) {
  struct sk_buff *skb = dev_alloc_skb(bytes); skb_put(skb, bytes);
  rtl_c2hcmd_enqueue(&hw, skb); assert(commands == 0);
 }
 struct sk_buff *skb = dev_alloc_skb(258); skb_put(skb, 258); rtl_c2hcmd_enqueue(&hw, skb); assert(commands == 0);
 skb = dev_alloc_skb(257); skb_put(skb, 257); rtl_c2hcmd_enqueue(&hw, skb); assert(commands == 1);
 for (unsigned int length = 0; length <= 9; length++) {
  u8 *data = malloc(length); assert(data || length == 0); if (length) memset(data, 0, length);
  if (length > 6) data[6] = 23;
  cfg.spec_ver = 0; priv.tx_report.last_recv_sn = 7; rtl_tx_report_handler(&hw, data, length);
  assert(priv.tx_report.last_recv_sn == (length >= 7 ? 23 : 7));
  cfg.spec_ver = RTL_SPEC_EXT_C2H; priv.tx_report.last_recv_sn = 7; rtl_tx_report_handler(&hw, data, length);
  assert(priv.tx_report.last_recv_sn == (length >= 9 ? 23 : 7)); free(data);
 }
}
int main(void) {
 receive_cases(); command_cases(); clean();
 puts("PASS real RTL PCI RX mapping, ownership, framing, C2H bounds"); return 0;
}
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cc", default="gcc")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    pci = (SOURCE / "pci.c").read_text()
    base = (SOURCE / "base.c").read_text()
    functions = [
        function(pci, "static void _rtl_pci_prepare_one_rxdesc("),
        function(pci, "static int _rtl_pci_init_one_rxdesc("),
        function(pci, "static unsigned int _rtl_pci_rx_interrupt("),
        function(base, "void rtl_tx_report_handler("),
        function(base, "static bool rtl_c2h_fast_cmd("),
        function(base, "void rtl_c2hcmd_enqueue("),
    ]
    # The fast C2H parser is not needed to test the enqueue boundary.
    parser_stub = "static void rtl_c2h_content_parsing(struct ieee80211_hw *hw, struct sk_buff *skb) { (void)hw; (void)skb; }\n"
    fixture = args.output / "pci_rx_fixture.c"
    fixture.write_text(PRE + parser_stub + "\n".join(functions) + POST)
    binary = args.output / "pci_rx_fixture"
    command = [args.cc, "-std=gnu11", "-O1", "-g", "-fno-omit-frame-pointer", "-fsanitize=address,undefined", "-fno-pie", "-no-pie", str(fixture), "-o", str(binary)]
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
        "scope": "Host execution of production RX and C2H functions with fault injection",
        "hardware_accessed": False,
        "source_sha256": {name: hashlib.sha256((SOURCE / name).read_bytes()).hexdigest() for name in ("pci.c", "base.c")},
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
