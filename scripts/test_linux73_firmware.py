"""Run the selected RTL8192EE firmware entry points with mocked hardware.

The fixture compiles the actual C function bodies. It exercises image bounds,
mailbox lengths, rate reports and the last checksum polling attempt under ASan
and UBSan. The optional firmware remains local and is read without modification.
Run with native Linux GCC and an absent output directory.
"""

import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]

sys.path.insert(0, str(ROOT / "scripts"))
from c_source import function


PREFIX = r'''
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint16_t __le16;
typedef uint32_t __le32;
#define le16_to_cpu(value) (value)
#define BIT(bit) (1U << (bit))
#define FW_8192C_SIZE 0x8000U
#define FW_8192C_POLLING_TIMEOUT_COUNT 3000U
#define FW_8192C_POLLING_DELAY 5U
#define FWDL_CHKSUM_RPT BIT(2)
#define MCUFWDL_RDY BIT(1)
#define WINTINI_RDY BIT(6)
#define REG_MCUFWDL 0x80U
#define IS_FW_HEADER_EXIST(header) \
    ((le16_to_cpu((header)->signature) & 0xfff0) == 0x92e0)
#define rtl_dbg(...) ((void)0)
#define pr_err(...) ((void)0)
#define pr_info(...) ((void)0)
#define pr_warn(...) ((void)0)
#define WARN_ONCE(condition, ...) (condition)
#define WARN_ON_ONCE(condition) (condition)
#define is_power_of_2(value) ((value) && !((value) & ((value) - 1)))
enum version_8192e { VERSION_TEST };
struct rtl_hal {
    u8 *pfirmware;
    u32 fwsize;
    u16 fw_version;
    u16 fw_subversion;
    enum version_8192e version;
    bool mac_func_enable;
    bool fw_ready;
};
struct rtl_priv { struct rtl_hal rtlhal; };
struct ieee80211_hw { struct rtl_priv *priv; };
#define rtl_priv(hw) ((hw)->priv)
#define rtl_hal(priv) (&(priv)->rtlhal)
static bool rtl92ee_hgw500_tx_rate_trace;
static bool board_retry;
static unsigned download_calls, mmio_calls, cleanup_calls;
static u8 *download_pointer;
static u32 download_size;
static int download_result[2];
static bool download_timeout[2];
static unsigned checksum_after, ready_after, polling_phase, phase_reads;
static unsigned mailbox_calls, mailbox_length;
static u8 mailbox_data[7];
static unsigned rate_calls;
static u8 selected_rate;
static bool selected_collision;
static int of_machine_is_compatible(const char *name)
{
    (void)name;
    return board_retry;
}
static bool _rtl92ee_mitrastar_warm_fw_retry(void) { return board_retry; }
static void _rtl92ee_mitrastar_fw_snapshot(struct ieee80211_hw *hw,
                                          const char *point, unsigned attempt)
{
    (void)hw; (void)point; (void)attempt;
}
static void _rtl92ee_mitrastar_fw_cleanup(struct ieee80211_hw *hw,
                                         unsigned attempt)
{
    (void)hw; (void)attempt;
    cleanup_calls++;
}
static u32 rtl_read_dword(struct rtl_priv *priv, unsigned reg)
{
    (void)priv; (void)reg;
    mmio_calls++;
    phase_reads++;
    if (!polling_phase)
        return checksum_after && phase_reads >= checksum_after ? FWDL_CHKSUM_RPT : 0;
    return ready_after && phase_reads >= ready_after ? WINTINI_RDY : 0;
}
static u8 rtl_read_byte(struct rtl_priv *priv, unsigned reg)
{
    (void)priv; (void)reg;
    mmio_calls++;
    return 0;
}
static void rtl_write_dword(struct rtl_priv *priv, unsigned reg, u32 value)
{
    (void)priv; (void)reg; (void)value;
    mmio_calls++;
    polling_phase = 1;
    phase_reads = 0;
}
static void rtl_write_byte(struct rtl_priv *priv, unsigned reg, u8 value)
{
    (void)priv; (void)reg; (void)value;
    mmio_calls++;
}
static void rtl92ee_firmware_selfreset(struct ieee80211_hw *hw) { (void)hw; }
static void udelay(unsigned delay) { (void)delay; }
static int _rtl92ee_download_fw_once(struct ieee80211_hw *hw,
                                    enum version_8192e version,
                                    u8 *data, u32 size, bool *timeout)
{
    (void)hw; (void)version;
    assert(download_calls < 2);
    download_pointer = data;
    download_size = size;
    *timeout = download_timeout[download_calls];
    return download_result[download_calls++];
}
static void _rtl92ee_fill_h2c_command(struct ieee80211_hw *hw, u8 id,
                                     u32 length, u8 *data)
{
    (void)hw; (void)id;
    assert(length <= sizeof(mailbox_data));
    mailbox_calls++;
    mailbox_length = length;
    memcpy(mailbox_data, data, length);
}
static void rtl92ee_dm_dynamic_arfb_select(struct ieee80211_hw *hw,
                                          u8 rate, bool collision)
{
    (void)hw;
    rate_calls++;
    selected_rate = rate;
    selected_collision = collision;
}
'''


TESTS = r'''
static struct rtl_priv priv;
static struct ieee80211_hw hw = { .priv = &priv };
static unsigned cases;
static void reset(void)
{
    memset(&priv, 0, sizeof(priv));
    download_calls = mmio_calls = cleanup_calls = 0;
    download_result[0] = download_result[1] = 0;
    download_timeout[0] = download_timeout[1] = false;
    board_retry = false;
    mailbox_calls = mailbox_length = rate_calls = 0;
    polling_phase = phase_reads = 0;
    checksum_after = ready_after = 1;
}
static void image_reject(u8 *data, u32 size)
{
    reset();
    priv.rtlhal.pfirmware = data;
    priv.rtlhal.fwsize = size;
    assert(rtl92ee_download_fw(&hw, false) != 0);
    assert(!download_calls && !mmio_calls && !cleanup_calls);
    cases++;
}
static void image_accept(u8 *data, u32 size, unsigned offset)
{
    reset();
    priv.rtlhal.pfirmware = data;
    priv.rtlhal.fwsize = size;
    assert(!rtl92ee_download_fw(&hw, false));
    assert(download_calls == 1 && download_pointer == data + offset);
    assert(download_size == size - offset);
    assert(!mmio_calls && !cleanup_calls);
    if (offset) {
        struct rtlwifi_firmware_header *header = (void *)data;
        assert(priv.rtlhal.fw_version == header->version);
        assert(priv.rtlhal.fw_subversion == header->subversion);
    } else {
        assert(!priv.rtlhal.fw_version && !priv.rtlhal.fw_subversion);
    }
    cases++;
}
static void images(void)
{
    image_reject(NULL, 1);
    u8 *data = calloc(1, FW_8192C_SIZE + 1);
    assert(data);
    image_reject(data, 0);
    image_reject(data, FW_8192C_SIZE + 1);
    /* Legacy headerless images retain every nonempty supported size. */
    for (unsigned size = 1; size <= FW_8192C_SIZE; size++)
        image_accept(data, size, 0);
    struct rtlwifi_firmware_header *header = (void *)data;
    header->signature = 0x92e1;
    header->version = 19;
    header->subversion = 3;
    for (unsigned cut = 2; cut <= sizeof(*header); cut++)
        image_reject(data, cut);
    for (unsigned size = sizeof(*header) + 1; size <= FW_8192C_SIZE; size++)
        image_accept(data, size, sizeof(*header));
    /* The bounded loader preserves the existing board-scoped retry policy. */
    reset();
    priv.rtlhal.pfirmware = data;
    priv.rtlhal.fwsize = sizeof(*header) + 1;
    board_retry = true;
    checksum_after = 0;
    download_result[0] = -EIO;
    download_timeout[0] = true;
    assert(!rtl92ee_download_fw(&hw, false));
    assert(download_calls == 2 && cleanup_calls == 1);
    cases++;
    reset();
    priv.rtlhal.pfirmware = data;
    priv.rtlhal.fwsize = sizeof(*header) + 1;
    board_retry = true;
    checksum_after = 0;
    download_result[0] = -EIO;
    assert(rtl92ee_download_fw(&hw, false) == -EIO);
    assert(download_calls == 1 && !cleanup_calls);
    cases++;
    free(data);
}
static void polling(void)
{
    unsigned checks[] = { 1, 2999, 3000, 3001 };
    for (unsigned i = 0; i < sizeof(checks) / sizeof(*checks); i++) {
        reset();
        checksum_after = checks[i];
        bool timeout = true;
        assert(!_rtl92ee_fw_free_to_go(&hw, &timeout));
        assert(!timeout);
        cases++;
    }
    reset();
    checksum_after = 0;
    bool timeout = false;
    assert(_rtl92ee_fw_free_to_go(&hw, &timeout) == -EIO && timeout);
    cases++;
    reset();
    ready_after = 0;
    assert(_rtl92ee_fw_free_to_go(&hw, &timeout) == -EIO && !timeout);
    cases++;
}
static void mailbox(void)
{
    u8 data[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (unsigned length = 0; length <= sizeof(data); length++) {
        reset();
        priv.rtlhal.fw_ready = true;
        rtl92ee_fill_h2c_cmd(&hw, 0x40, length, data);
        if (length >= 1 && length <= 7) {
            assert(mailbox_calls == 1 && mailbox_length == length);
            assert(!memcmp(mailbox_data, data, length));
        } else {
            assert(!mailbox_calls);
        }
        cases++;
    }
    reset();
    priv.rtlhal.fw_ready = true;
    rtl92ee_fill_h2c_cmd(&hw, 0x40, 1, NULL);
    assert(!mailbox_calls);
    cases++;
    reset();
    rtl92ee_fill_h2c_cmd(&hw, 0x40, 7, data);
    assert(!mailbox_calls);
    cases++;
}
static void rate_reports(void)
{
    reset();
    rtl92ee_c2h_ra_report_handler(&hw, NULL, 0);
    assert(!rate_calls);
    cases++;
    for (unsigned length = 1; length <= 4; length++) {
        u8 *data = calloc(1, length);
        assert(data);
        data[0] = 0x8f;
        if (length == 4)
            data[3] = 1;
        reset();
        rtl92ee_c2h_ra_report_handler(&hw, data, length);
        assert(rate_calls == 1 && selected_rate == 15);
        assert(selected_collision == (length == 4));
        cases++;
        free(data);
    }
}
static void selected_firmware(const char *path)
{
    FILE *file = fopen(path, "rb");
    assert(file && !fseek(file, 0, SEEK_END));
    long size = ftell(file);
    assert(size > 32 && size <= FW_8192C_SIZE);
    rewind(file);
    u8 *data = malloc((size_t)size);
    assert(data && fread(data, 1, (size_t)size, file) == (size_t)size);
    fclose(file);
    assert(IS_FW_HEADER_EXIST((struct rtlwifi_firmware_header *)data));
    image_accept(data, (u32)size, sizeof(struct rtlwifi_firmware_header));
    free(data);
}
int main(int argc, char **argv)
{
    _Static_assert(sizeof(struct rtlwifi_firmware_header) == 32, "firmware header");
    assert(argc <= 2);
    images();
    polling();
    mailbox();
    rate_reports();
    if (argc == 2)
        selected_firmware(argv[1]);
    printf("{\"cases\":%u,\"invalid_image_mmio_calls\":0}\n", cases);
    return 0;
}
'''


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=ROOT / "kernel/radio2g-linux-7.3-v1/overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c")
    parser.add_argument("--firmware", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--cc", default="gcc")
    args = parser.parse_args()
    if args.output.exists():
        parser.error("Choose an absent output directory")
    args.output.mkdir(parents=True)
    text = args.source.read_text()
    wifi = args.source.parent.parent / "wifi.h"
    header = function(wifi.read_text(), "struct rtlwifi_firmware_header {") + ";\n"
    bodies = [function(text, signature) for signature in (
        "static int _rtl92ee_fw_free_to_go(", "int rtl92ee_download_fw(",
        "void rtl92ee_fill_h2c_cmd(", "void rtl92ee_c2h_ra_report_handler(")]
    fixture = args.output / "firmware-entrypoints.c"
    fixture.write_text(PREFIX + header + "\n".join(bodies) + TESTS, newline="\n")
    binary = args.output / "firmware-entrypoints"
    command = [args.cc, "-std=gnu11", "-O1", "-g", "-fsanitize=address,undefined",
               "-fno-omit-frame-pointer", "-Wall", "-Wextra", str(fixture), "-o", str(binary)]
    compiled = subprocess.run(command, capture_output=True)
    (args.output / "compile.log").write_bytes(compiled.stdout + compiled.stderr)
    if compiled.returncode:
        raise RuntimeError(compiled.stderr.decode(errors="replace"))
    command = [str(binary)]
    if args.firmware:
        command.append(str(args.firmware))
    tested = subprocess.run(command, capture_output=True)
    (args.output / "run.log").write_bytes(tested.stdout + tested.stderr)
    if tested.returncode:
        raise RuntimeError(tested.stderr.decode(errors="replace"))
    pins = {str(path): digest(path) for path in (Path(__file__), args.source, wifi, fixture, binary)}
    if args.firmware:
        pins[str(args.firmware)] = digest(args.firmware)
    result = {"status": "PASS_ACTUAL_RTL8192EE_FIRMWARE_ENTRYPOINTS_ASAN_UBSAN",
              "hardware_accessed": False, **json.loads(tested.stdout), "pins": pins,
              "limits": ["Actual driver C bodies with mocked register access, download and mailbox writes.",
                         "No MCU execution, radio traffic or physical acceptance."]}
    (args.output / "result.json").write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
