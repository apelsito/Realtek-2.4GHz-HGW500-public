/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14ef8; aliases: _rtl92ee_phy_save_adda_registers
 */

void _rtl92ee_phy_save_adda_registers(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = uVar3 * 4;
    uVar2 = rtl_get_bbreg(param_1,*(undefined4 *)(param_2 + uVar3 * 4),0xffffffff);
    uVar3 = uVar3 + 1;
    *(undefined4 *)(param_3 + iVar1) = uVar2;
  } while (uVar3 < param_4);
  return;
}

