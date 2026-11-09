cmd_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o := @TOOLCHAIN_ROOT@/bin/arc-snps-linux-uclibc-gcc -Wp,-MMD,drivers/net/wireless/realtek/rtlwifi/rtl8192ee/.table.o.d -nostdinc -isystem @TOOLCHAIN_ROOT@/bin/../lib/gcc/arc-snps-linux-uclibc/15.2.0/include -I@KERNEL_SOURCE@/arch/arc/include -I./arch/arc/include/generated -I@KERNEL_SOURCE@/include -I./include -I@KERNEL_SOURCE@/arch/arc/include/uapi -I./arch/arc/include/generated/uapi -I@KERNEL_SOURCE@/include/uapi -I./include/generated/uapi -include @KERNEL_SOURCE@/include/linux/kconfig.h -include @KERNEL_SOURCE@/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=@KERNEL_SOURCE@/= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -fno-common -pipe -fno-builtin -mmedium-calls -D__linux__ -mcpu=arc700 -fsection-anchors -mno-sdata -fcall-used-gp -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -Os -fno-allow-store-data-races -Wframe-larger-than=1024 -fno-stack-protector -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-dangling-pointer -fomit-frame-pointer -ftrivial-auto-var-init=zero -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-zero-length-bounds -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fno-builtin-wcslen -Wno-packed-not-aligned -ffile-prefix-map=@HISTORICAL_OUTPUT@=/f358-output -I @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee -I ./drivers/net/wireless/realtek/rtlwifi/rtl8192ee  -DMODULE -mlong-calls -mno-millicode  -DKBUILD_BASENAME='"table"' -DKBUILD_MODNAME='"rtl8192ee"' -c -o drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.c

source_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o := @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.c

deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o := \
  @KERNEL_SOURCE@/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  @KERNEL_SOURCE@/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/cc/has/asm/inline.h) \
  @KERNEL_SOURCE@/include/linux/compiler_attributes.h \
  @KERNEL_SOURCE@/include/linux/compiler-gcc.h \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
    $(wildcard include/config/kcov.h) \
  @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.h \
  @KERNEL_SOURCE@/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  @KERNEL_SOURCE@/include/uapi/linux/types.h \
  arch/arc/include/generated/uapi/asm/types.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/types.h \
  @KERNEL_SOURCE@/include/asm-generic/int-ll64.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/int-ll64.h \
  arch/arc/include/generated/uapi/asm/bitsperlong.h \
  @KERNEL_SOURCE@/include/asm-generic/bitsperlong.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/bitsperlong.h \
  @KERNEL_SOURCE@/include/uapi/linux/posix_types.h \
  @KERNEL_SOURCE@/include/linux/stddef.h \
  @KERNEL_SOURCE@/include/uapi/linux/stddef.h \
  @KERNEL_SOURCE@/include/linux/compiler_types.h \
  arch/arc/include/generated/uapi/asm/posix_types.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/posix_types.h \

drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o: $(deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o)

$(deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.o):
