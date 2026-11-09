/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x151f8; aliases: calculate_bit_shift
 */

int calculate_bit_shift(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if (__warned_6 == '\0') {
      __warned_6 = '\x01';
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/../wifi.h",0xc16,9,0);
    }
  }
  else {
    iVar1 = norm(-param_1 & param_1);
    if ((int)(-param_1 & param_1) < 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + 1;
    }
    iVar1 = 0x1f - iVar1;
  }
  return iVar1;
}

