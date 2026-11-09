/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14ce8; aliases: _rtl92ee_phy_rf_serial_read
 */

void _rtl92ee_phy_rf_serial_read(int param_1,int param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x40);
  uVar3 = rtl_get_bbreg(param_1,0x824,0xffffffff);
  iVar1 = param_2 * 0x48;
  iVar6 = iVar6 + 0x800;
  uVar4 = uVar3;
  if (param_2 != 0) {
    uVar4 = rtl_get_bbreg(param_1,*(undefined4 *)(iVar6 + iVar1 + -0x84),0xffffffff);
  }
  rtl_set_bbreg(param_1,0x824,0xffffffff,uVar3 & 0x7fffffff);
  rtl_set_bbreg(param_1,*(undefined4 *)(iVar6 + iVar1 + -0x84),0xffffffff,
                (param_3 & 0xff) << 0x17 | uVar4 & 0x807fffff | 0x80000000);
  __udelay(0x14);
  if (param_2 == 0) {
    uVar5 = 0x820;
LAB_ram_00014dc8:
    cVar2 = rtl_get_bbreg(param_1,uVar5);
    if (cVar2 != '\0') {
      uVar5 = *(undefined4 *)(iVar1 + iVar6 + -0x60);
      goto LAB_ram_00014de4;
    }
  }
  else if (param_2 == 1) {
    uVar5 = 0x828;
    goto LAB_ram_00014dc8;
  }
  uVar5 = *(undefined4 *)(iVar6 + iVar1 + -100);
LAB_ram_00014de4:
  rtl_get_bbreg(param_1,uVar5,0xfffff);
  return;
}

