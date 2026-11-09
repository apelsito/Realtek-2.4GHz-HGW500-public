/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1812c; aliases: rtl92ee_phy_lc_calibrate
 */

void rtl92ee_phy_lc_calibrate(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar4 = *(int *)(param_1 + 0x40);
  for (iVar5 = 0; (*(char *)(iVar4 + 0x4ea) != '\0' && (iVar5 != 2000)); iVar5 = iVar5 + 0x32) {
    __udelay(0x32);
  }
  *(undefined1 *)(iVar4 + 0x892) = 1;
  uVar6 = *(undefined4 *)(param_1 + 0x40);
  uVar1 = rtl_read_byte(uVar6,0xd03);
  if ((uVar1 & 0x70) == 0) {
    uVar2 = 0;
    rtl_write_byte(uVar6,0x522,0xff);
  }
  else {
    rtl_write_byte(uVar6,0xd03,uVar1 & 0x8f);
    uVar2 = rtl_get_rfreg(param_1,0,0,0xfff);
    rtl_set_rfreg(param_1,0,0,0xfff,uVar2 & 0x8ffff | 0x10000);
  }
  uVar3 = rtl_get_rfreg(param_1,0,0x18,0xfff);
  iVar5 = 99;
  rtl_set_rfreg(param_1,0,0x18,0xfff,uVar3 | 0x8000);
  do {
    iVar5 = iVar5 + -1;
    __udelay(1000);
  } while (iVar5 != -1);
  if ((uVar1 & 0x70) == 0) {
    rtl_write_byte(uVar6,0x522,0);
  }
  else {
    rtl_write_byte(uVar6,0xd03,uVar1);
    rtl_set_rfreg(param_1,0,0,0xfff,uVar2);
  }
  *(undefined1 *)(iVar4 + 0x892) = 0;
  return;
}

