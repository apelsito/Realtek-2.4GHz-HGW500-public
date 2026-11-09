/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14ad4; aliases: rtl_write_dword.constprop.0
 */

void rtl_write_dword_constprop_0(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x748))(param_1,0x44,param_2);
  if (*(char *)(*(int *)(param_1 + 0xb8fc) + 1) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00014b0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x758))(param_1,0x44);
    return;
  }
  return;
}

