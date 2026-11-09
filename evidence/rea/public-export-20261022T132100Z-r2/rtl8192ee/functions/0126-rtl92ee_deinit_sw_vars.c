/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1897c; aliases: rtl92ee_deinit_sw_vars
 */

void rtl92ee_deinit_sw_vars(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar1 + 0x6b0) != 0) {
    (*(code *)&vfree)();
    *(undefined4 *)(iVar1 + 0x6b0) = 0;
  }
  return;
}

