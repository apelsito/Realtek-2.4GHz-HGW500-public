/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14a50; aliases: rtl92ee_bt_hw_init
 */

void rtl92ee_bt_hw_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x104))();
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00014a80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(iVar2 + 0xb9ac) + 0x14))(iVar2);
    return;
  }
  return;
}

