#!/bin/sh
set -eu
src=$1
overlay=$2
# The rtlwifi sources below are the reviewed Linux 5.10.260 Topaz target
# versions.  Copying them before marker-gated patches makes the overlay
# idempotent even when an interrupted build left a partially applied .rej.
cp "$overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c" \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.c"
cp "$overlay/files/drivers/net/wireless/realtek/rtlwifi/wifi.h" \
	"$src/drivers/net/wireless/realtek/rtlwifi/wifi.h"
cp "$overlay/files/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c" \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c"
cp "$overlay/files/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h" \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h"

if ! grep -q 'buffer_desc_stride' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.h"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-tx2-pci-header.patch"
fi
if ! grep -q 'txbd_compact32' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.h"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-tx2-pci-mode.patch"
fi


if ! grep -q 'OMRTL stage=probe-enter' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-probe-trace-topaz.patch"
fi

if ! grep -q 'get_unaligned_le16(&hwinfo\[0\])' \
	"$src/drivers/net/wireless/realtek/rtlwifi/efuse.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-arc-unaligned-efuse-topaz.patch"
fi

if ! grep -q 'OMRTL92 stage=module-init-enter' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtl8192ee-module-init-trace-topaz.patch"
fi

if ! grep -q 'dev_addr\[ETH_ALEN\] __aligned(2)' \
	"$src/drivers/net/wireless/realtek/rtlwifi/wifi.h"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-arc-align-efuse-dev-addr-topaz.patch"
fi

if ! grep -q 'OMRTL stage=op-start-enter' \
	"$src/drivers/net/wireless/realtek/rtlwifi/core.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-runtime-trace-topaz.patch"
fi

if ! grep -q 'OMRTL stage=tx-enter' \
	"$src/drivers/net/wireless/realtek/rtlwifi/core.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-tx-trace-topaz.patch"
fi

if ! grep -q 'bool irq_line_lifecycle_managed;' "$src/drivers/net/wireless/realtek/rtlwifi/pci.h"; then
 patch -d "$src" -p1 --forward < "$overlay/patches/rtlwifi-pci-irq-lifecycle-topaz.patch"
fi

if ! grep -q 'OMRTL stage=irq-line-noautoen' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-pci-irq-noautoen-topaz.patch"
fi

if ! grep -Eq 'OMRTL stage=irq-deferred-(handled|acked)' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-pci-managed-deferred-handled-topaz.patch"
fi

if ! grep -q 'OMRTL stage=irq-deferred-acked' \
	"$src/drivers/net/wireless/realtek/rtlwifi/pci.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-pci-managed-deferred-ack-topaz.patch"
fi

if ! grep -q 'OMRTL stage=beacon-irq-window protected' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-rtl8192ee-topaz-beacon-irq-window.patch"
fi

if ! grep -q 'OMRTLTX6 stage=txbd-system-width' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-tx6-global-txbd-width.patch"
fi

if ! grep -q 'hgw500_tx_pbp_256' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtl8192ee-mitrastar-tx26-pbp-width-override.patch"
fi

if ! grep -q 'OMRTL92 stage=tx-poll-beacon-trigger' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-rtl8192ee-topaz-beacon-poll.patch"
fi

if ! grep -q 'OMRTLTXCLOSE id=' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-tx-close-diag.patch"
fi

cp "$overlay/files/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c" \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c"

if ! grep -q 'OMRTL stage=ap-swcrypto-fallback accepted' \
	"$src/drivers/net/wireless/realtek/rtlwifi/core.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-ap-swcrypto.patch"
fi

if ! grep -q 'OMRTLAMPDU stage=tx-start-rejected' \
	"$src/drivers/net/wireless/realtek/rtlwifi/core.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-tx-ampdu-lab.patch"
fi

if ! grep -q 'OMRTLACK stage=policy-active' \
	"$src/drivers/net/wireless/realtek/rtlwifi/base.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-honest-tx-ack-lab.patch"
fi

if ! grep -q 'OMRTL92 stage=fw-warm-preclean reason=residual-ready' \
	"$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c"; then
	patch -d "$src" -p1 --forward < \
		"$overlay/patches/rtlwifi-mitrastar-warm-preclean-topaz.patch"
fi

# The retained F363 hw.o encodes WARN_ONCE at line 1621. One missing blank
# line in the historical patch context shifts that diagnostic byte only.
python3 - "$src/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c" <<'PYFIX'
from pathlib import Path
import sys
p = Path(sys.argv[1]); lines = p.read_text().splitlines()
needle = 'WARN_ONCE(true, "rtl8192ee: invalid aci:'
positions = [i for i, line in enumerate(lines) if needle in line]
assert len(positions) == 1
if positions[0] + 1 == 1620:
    lines.insert(positions[0], '')
    p.write_text('\n'.join(lines) + '\n')
else:
    assert positions[0] + 1 == 1621, 'unexpected F363 WARN_ONCE line'
PYFIX
