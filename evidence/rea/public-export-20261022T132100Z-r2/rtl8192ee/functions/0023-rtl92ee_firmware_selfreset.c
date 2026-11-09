/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11984; aliases: rtl92ee_firmware_selfreset
 */

void rtl92ee_firmware_selfreset(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x40);
  uVar2 = rtl_read_byte(uVar3,0x1d);
  rtl_write_byte(uVar3,0x1d,uVar2 & 0xfe);
  uVar2 = rtl_read_byte(uVar3,3);
  rtl_write_byte(uVar3,3,uVar2 & 0xfb);
  __udelay(0x32);
  bVar1 = rtl_read_byte(uVar3,0x1d);
  rtl_write_byte(uVar3,0x1d,bVar1 | 1);
  bVar1 = rtl_read_byte(uVar3,3);
  rtl_write_byte(uVar3,3,bVar1 | 4);
  return;
}

