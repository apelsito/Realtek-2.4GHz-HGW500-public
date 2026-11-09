"""Exercise the real RTL8192EE RX descriptor and PHY parsing functions.

The fixture uses the selected descriptor getters and driver C bodies with
mocked mac80211 notification helpers. Exact-size receive allocations and
sanitizers check short frames, offsets, PHY reports and C2H records.
"""

import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
from c_source import function


PREFIX = r'''
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint16_t __le16;
typedef uint32_t __le32;
#define __packed __attribute__((packed))
#define BIT(bit) (1U << (bit))
#define GENMASK(high, low) ((0xffffffffU >> (31 - (high))) & (0xffffffffU << (low)))
#define le32_get_bits(value, mask) (((value) & (mask)) >> __builtin_ctz(mask))
#define le32_to_cpu(value) (value)
#define le16_to_cpu(value) (value)
#define cpu_to_le16(value) (value)
#define IS_LITTLE_ENDIAN 1
#define RX_DRV_INFO_SIZE_UNIT 8
#define NORMAL_RX 0
#define C2H_PACKET 1
#define TX_REPORT2 2
#define RTL92EE_RX_HAL_IS_CCK_RATE(rate) ((rate) <= 3)
#define RX_FLAG_FAILED_FCS_CRC BIT(0)
#define RX_FLAG_MACTIME_START BIT(1)
#define RX_FLAG_DECRYPTED BIT(2)
#define RATE_INFO_BW_40 1
#define RX_ENC_HT 1
#define WLAN_CATEGORY_PUBLIC 4
#define WLAN_CATEGORY_HT 7
#define WLAN_CATEGORY_WNM_UNPROTECTED 11
#define WLAN_CATEGORY_SELF_PROTECTED 15
#define WLAN_CATEGORY_UNPROT_DMG 20
#define WLAN_CATEGORY_VHT 21
#define WLAN_CATEGORY_VENDOR_SPECIFIC 127
#define unlikely(value) (value)
#define min_t(type, first, second) ((type)(first) < (type)(second) ? (type)(first) : (type)(second))
#define pr_info(...) ((void)0)
#define pr_info_once(...) ((void)0)
#define rtl_dbg(...) ((void)0)
struct ieee80211_hdr {
    __le16 frame_control, duration_id;
    u8 addr1[6], addr2[6], addr3[6];
    __le16 seq_ctrl;
    u8 addr4[6];
} __packed;
struct ieee80211_qos_hdr {
    __le16 frame_control, duration_id;
    u8 addr1[6], addr2[6], addr3[6];
    __le16 seq_ctrl, qos_ctrl;
} __packed;
struct sk_buff { u8 *data; unsigned capacity; };
#define skb_tailroom(skb) ((skb)->capacity)
struct channel { unsigned center_freq, band; };
struct rtl_mac { u8 bssid[6]; };
struct rtl_efuse { u8 dev_addr[6]; };
struct rtl_priv {
    struct rtl_mac mac;
    struct rtl_efuse efuse;
    struct { struct { unsigned num_qry_beacon_pkt, num_non_be_pkt; } dbginfo; } dm;
};
struct ieee80211_hw {
    struct rtl_priv *priv;
    struct { struct { struct channel *chan; } chandef; } conf;
};
#define rtl_priv(hw) ((hw)->priv)
#define rtl_mac(priv) (&(priv)->mac)
#define rtl_efuse(priv) (&(priv)->efuse)
struct rtl_stats {
    unsigned packet_report_type, length, rx_drvinfo_size, rx_bufshift;
    unsigned icv, crc, hwerror, decrypted, rate, shortpreamble;
    unsigned isampdu, isfirst_ampdu, timestamp_low, rx_is40mhzpacket;
    unsigned is_ht, is_cck, macid, macid_valid_entry[2];
    int recvsignalpower;
    u8 psaddr[6];
};
struct ieee80211_rx_status {
    unsigned freq, band, flag, bw, encoding, rate_idx, mactime;
    int signal;
};
static unsigned cases, phy_calls, process_calls, c2h_calls, sa_calls;
static unsigned hgw500_mgmt_rx_trace_count;
static u16 get_unaligned_le16(const void *pointer)
{
    const u8 *bytes = pointer;
    return bytes[0] | ((u16)bytes[1] << 8);
}
static bool ieee80211_is_ctl(__le16 fc) { return (fc & 0x0c) == 4; }
static bool ieee80211_is_data(__le16 fc) { return (fc & 0x0c) == 8; }
static bool ieee80211_is_data_qos(__le16 fc) { return (fc & 0x8c) == 0x88; }
static bool ieee80211_is_beacon(__le16 fc) { return (fc & 0xfc) == 0x80; }
static bool ieee80211_is_action(__le16 fc) { return (fc & 0xfc) == 0xd0; }
static bool ieee80211_is_disassoc(__le16 fc) { return (fc & 0xfc) == 0xa0; }
static bool ieee80211_is_deauth(__le16 fc) { return (fc & 0xfc) == 0xc0; }
static bool ieee80211_has_protected(__le16 fc) { return fc & 0x4000; }
static bool ieee80211_has_tods(__le16 fc) { return fc & 0x0100; }
static bool ieee80211_has_fromds(__le16 fc) { return fc & 0x0200; }
static unsigned ieee80211_hdrlen(__le16 fc)
{
    if (ieee80211_is_ctl(fc))
        return (fc & 0xfc) == 0xc4 || (fc & 0xfc) == 0xd4 ? 10 : 16;
    unsigned length = ieee80211_has_tods(fc) && ieee80211_has_fromds(fc) ? 30 : 24;
    if (ieee80211_is_data_qos(fc))
        length += 2;
    return length;
}
static u8 *ieee80211_get_SA(struct ieee80211_hdr *header)
{
    sa_calls++;
    if (ieee80211_has_tods(header->frame_control) && ieee80211_has_fromds(header->frame_control))
        return header->addr4;
    return ieee80211_has_fromds(header->frame_control) ? header->addr3 : header->addr2;
}
static u8 *ieee80211_get_DA(struct ieee80211_hdr *header)
{
    return ieee80211_has_tods(header->frame_control) ? header->addr3 : header->addr1;
}
static void ether_addr_copy(u8 *destination, const u8 *source) { memcpy(destination, source, 6); }
static void eth_zero_addr(u8 *address) { memset(address, 0, 6); }
static bool ether_addr_equal(const u8 *first, const u8 *second) { return !memcmp(first, second, 6); }
static bool is_multicast_ether_addr(const u8 *address) { return address[0] & 1; }
static bool of_machine_is_compatible(const char *name) { (void)name; return true; }
static void rtl92ee_hgw500_trace_c2h(struct ieee80211_hw *hw, const u8 *frame, unsigned length)
{
    (void)hw;
    for (unsigned index = 0; index < length; index++)
        assert(frame[index] == 0);
    c2h_calls++;
}
static void rtl92ee_hgw500_request_oem_tx_report(struct ieee80211_hw *hw, unsigned macid)
{
    (void)hw; (void)macid;
}
static unsigned rtlwifi_rate_mapping(struct ieee80211_hw *hw, bool ht, bool vht, unsigned rate)
{
    (void)hw; (void)ht; (void)vht;
    return rate;
}
static bool rtl92ee_hgw500_trace_mgmt_frame(struct ieee80211_hw *hw, __le16 fc, unsigned count)
{
    (void)hw; (void)fc; (void)count;
    return false;
}
static void rtl_process_phyinfo(struct ieee80211_hw *hw, u8 *frame, struct rtl_stats *status)
{
    (void)hw; (void)frame; (void)status;
    process_calls++;
}
'''


PHY_STUB = r'''
static void _rtl92ee_query_rxphystatus(struct ieee80211_hw *hw,
                                      struct rtl_stats *status, u8 *desc,
                                      struct rx_fwinfo *info, bool match,
                                      bool self, bool beacon)
{
    (void)hw; (void)status; (void)desc; (void)match; (void)self; (void)beacon;
    const u8 *bytes = (const u8 *)info;
    for (unsigned index = 0; index < sizeof(struct phy_status_rpt); index++)
        assert(bytes[index] == 0);
    phy_calls++;
}
'''


TESTS = r'''
static void receive(unsigned capacity, unsigned length, unsigned units,
                    unsigned shift, bool phy, bool c2h, __le16 fc, bool expected)
{
    u8 *data = calloc(1, capacity ? capacity : 1);
    assert(data);
    unsigned offset = 24 + units * 8 + shift;
    if (!c2h && capacity >= offset + 2) {
        data[offset] = fc & 0xff;
        data[offset + 1] = fc >> 8;
    }
    __le32 desc[6] = { length | (units << 16) | (shift << 24) | (phy ? BIT(26) : 0),
                      0, c2h ? BIT(28) : 0, 0, 0, 0 };
    struct rtl_priv priv = {0};
    struct channel channel = { .center_freq = 2412, .band = 0 };
    struct ieee80211_hw hw = { .priv = &priv, .conf.chandef.chan = &channel };
    struct rtl_stats status = {0};
    struct ieee80211_rx_status rx = {0};
    struct sk_buff skb = { .data = data, .capacity = capacity };
    phy_calls = process_calls = c2h_calls = sa_calls = 0;
    bool result = rtl92ee_rx_query_desc(&hw, &status, &rx, (u8 *)desc, &skb);
    assert(result == expected);
    if (!expected) {
        assert(!phy_calls && !process_calls && !c2h_calls);
    } else if (c2h) {
        assert(c2h_calls == 1 && !phy_calls && !process_calls);
    } else {
        assert(!c2h_calls && phy_calls == (unsigned)phy && process_calls == (unsigned)phy);
        assert(rx.freq == 2412);
        if (ieee80211_hdrlen(fc) < 16) {
            assert(!sa_calls);
            for (unsigned index = 0; index < sizeof(status.psaddr); index++)
                assert(!status.psaddr[index]);
        }
    }
    free(data);
    cases++;
}
int main(void)
{
    _Static_assert(sizeof(struct phy_status_rpt) == 28, "PHY report size");
    /* Exact allocations expose reads beyond the descriptor-declared record. */
    for (unsigned shift = 0; shift < 4; shift++) {
        for (unsigned units = 0; units < 16; units++) {
            unsigned offset = 24 + units * 8 + shift;
            for (unsigned length = 0; length <= 64; length++) {
                receive(offset + length, length, units, shift, false, false, 0x0080,
                        length >= 24);
                receive(offset + length, length, units, shift, true, false, 0x0080,
                        length >= 24 && units >= 4);
                receive(offset + length, length, units, shift, true, true, 0, true);
                if (length)
                    receive(offset + length - 1, length, units, shift, false, false, 0x0080, false);
            }
        }
        unsigned offset = 24 + 32 + shift;
        receive(offset + 10, 10, 4, shift, true, false, 0x00d4, true); /* ACK */
        receive(offset + 10, 10, 4, shift, true, false, 0x00c4, true); /* CTS */
        receive(offset + 14, 14, 4, shift, true, false, 0x00d4, true); /* ACK + FCS */
        receive(offset + 16, 16, 4, shift, true, false, 0x00c4, true); /* CTS + trailer */
        receive(offset + 16, 16, 4, shift, true, false, 0x00b4, true); /* RTS */
        receive(offset + 24, 24, 4, shift, true, false, 0x00d0, false);
        receive(offset + 25, 25, 4, shift, true, false, 0x00d0, true);
        receive(offset + 24, 24, 4, shift, true, false, 0x40d0, true);
        receive(24, 1, 4, shift, false, true, 0, false);
    }
    printf("{\"cases\":%u,\"rejected_record_phy_calls\":0}\n", cases);
    return 0;
}
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=ROOT / "kernel/radio2g-linux-7.3-v1/overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c")
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--cc", default="gcc")
    args = parser.parse_args()
    if args.output.exists():
        parser.error("Choose an absent output directory")
    args.output.mkdir(parents=True)
    text = args.source.read_text()
    header_path = args.source.with_suffix(".h")
    header = header_path.read_text()
    getters = re.findall(r"\b(get_rx_(?:desc|status_desc|rpt2_desc)_\w+)\(",
                         function(text, "bool rtl92ee_rx_query_desc("))
    getter_bodies = []
    for name in sorted(set(getters)):
        signature = re.search(r"static inline \w+ " + name + r"\(", header).group()
        getter_bodies.append(function(header, signature))
    structures = [function(header, signature) + " __packed;\n" for signature in (
        "struct phy_rx_agc_info_t {", "struct phy_status_rpt {", "struct rx_fwinfo {")]
    bodies = [function(text, signature) for signature in (
        "static bool rtl92ee_is_robust_mgmt_frame_unaligned(",
        "static void _rtl92ee_translate_rx_signal_stuff(",
        "bool rtl92ee_rx_query_desc(")]
    robust_stub = "\n#define _ieee80211_is_robust_mgmt_frame(header) rtl92ee_is_robust_mgmt_frame_unaligned((const u8 *)(header), (header)->frame_control)\n"
    fixture = args.output / "rx-query.c"
    fixture.write_text(PREFIX + "\n".join(structures + getter_bodies) + PHY_STUB +
                       bodies[0] + robust_stub + "\n".join(bodies[1:]) + TESTS, newline="\n")
    binary = args.output / "rx-query"
    compiled = subprocess.run([args.cc, "-std=gnu11", "-O1", "-g",
                               "-fsanitize=address,undefined", "-fno-omit-frame-pointer",
                               "-Wall", "-Wextra", str(fixture), "-o", str(binary)], capture_output=True)
    (args.output / "compile.log").write_bytes(compiled.stdout + compiled.stderr)
    if compiled.returncode:
        raise RuntimeError(compiled.stderr.decode(errors="replace"))
    tested = subprocess.run([str(binary)], capture_output=True)
    (args.output / "run.log").write_bytes(tested.stdout + tested.stderr)
    if tested.returncode:
        raise RuntimeError(tested.stderr.decode(errors="replace"))
    pins = {str(path): hashlib.sha256(path.read_bytes()).hexdigest()
            for path in (Path(__file__), args.source, header_path, fixture, binary)}
    result = {"status": "PASS_ACTUAL_RTL8192EE_RX_QUERY_ASAN_UBSAN", "hardware_accessed": False,
              **json.loads(tested.stdout), "pins": pins,
              "limits": ["Real descriptor getters, query and PHY frame parsing with mocked mac80211 notifications.",
                         "No actual DMA, device register access or radio traffic."]}
    (args.output / "result.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
