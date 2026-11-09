/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x175b0; aliases: rtl92ee_phy_get_hw_reg_originalvalue
 */

void rtl92ee_phy_get_hw_reg_originalvalue(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  uVar1 = rtl_get_bbreg(param_1,0xc50,0xff);
  *(undefined1 *)(iVar3 + 0x40f0) = uVar1;
  uVar1 = rtl_get_bbreg(param_1,0xc58,0xff);
  *(undefined1 *)(iVar3 + 0x40f1) = uVar1;
  uVar1 = rtl_get_bbreg(param_1,0xc60,0xff);
  *(undefined1 *)(iVar3 + 0x40f2) = uVar1;
  uVar1 = rtl_get_bbreg(param_1,0xc68,0xff);
  *(undefined1 *)(iVar3 + 0x40f3) = uVar1;
  uVar1 = rtl_get_bbreg(param_1,0xc38,0xff);
  *(undefined1 *)(iVar3 + 0x9f90) = uVar1;
  uVar2 = rtl_get_bbreg(param_1,0xc34,0xffffffff);
  *(undefined4 *)(iVar3 + 0x9f94) = uVar2;
  return;
}

