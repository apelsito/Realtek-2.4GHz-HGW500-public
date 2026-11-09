/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17a30; aliases: rtl_signal_scale_mapping
 */

int rtl_signal_scale_mapping(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (0x14 < param_2) {
    if (0x3c < param_2) {
      if (param_2 - 0x3dU < 0x28) {
        param_2 = (param_2 >> 2) + 0x4b;
      }
      return param_2;
    }
    if (param_2 < 0x29) {
      if (0x1e < param_2) {
        return param_2 + 0x24;
      }
      return param_2 + 0x22;
    }
    return (param_2 >> 1) + 0x3a;
  }
  if (4 < param_2) {
    iVar1 = (*(code *)&__divsi3)((param_2 + -5) * 2,3);
    return iVar1 + 0x2a;
  }
  if (3 < param_2 - 1U) {
    return param_2;
  }
  switch(param_2) {
  case 2:
    return 0x12;
  case 3:
    return 0x1b;
  case 4:
    return 0x24;
  default:
    return 9;
  }
}

