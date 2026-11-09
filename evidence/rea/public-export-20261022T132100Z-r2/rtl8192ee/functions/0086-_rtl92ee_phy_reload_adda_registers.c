/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14f4c; aliases: _rtl92ee_phy_reload_adda_registers
 */

void _rtl92ee_phy_reload_adda_registers(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = uVar3 * 4;
    iVar2 = uVar3 * 4;
    uVar3 = uVar3 + 1;
    rtl_set_bbreg(param_1,*(undefined4 *)(param_2 + iVar2),0xffffffff,
                  *(undefined4 *)(param_3 + iVar1));
  } while (uVar3 < param_4);
  return;
}

