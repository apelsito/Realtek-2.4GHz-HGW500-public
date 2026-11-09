/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13f5c; aliases: rtl92ee_card_disable
 */

void rtl92ee_card_disable(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  *(uint *)(iVar4 + 0xb304) = *(uint *)(iVar4 + 0xb304) | 8;
  *(undefined4 *)(iVar4 + 0x4d0) = 0;
  _rtl92ee_set_media_status(param_1,0);
  if ((*(char *)(iVar4 + 0x62c) != '\0') || (0x20000000 < *(uint *)(iVar4 + 0xb300))) {
    (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x90))(param_1,7);
  }
  iVar3 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar3 + 0x631) = 0;
  (*(code *)&rtl_hal_pwrseqcmdparsing)(iVar3,0xff,0xf,4,rtl8192E_enter_lps_flow);
  rtl_write_byte(iVar3,0x1f,0);
  uVar2 = rtl_read_byte(iVar3,0x80);
  if (((uVar2 & 0x80) != 0) && (*(char *)(iVar3 + 0x6ba) != '\0')) {
    rtl92ee_firmware_selfreset(param_1);
  }
  uVar2 = rtl_read_byte(iVar3,3);
  rtl_write_byte(iVar3,3,uVar2 & 0xfb);
  rtl_write_byte(iVar3,0x80,0);
  (*(code *)&rtl_hal_pwrseqcmdparsing)(iVar3,0xff,0xf,4,rtl8192E_card_disable_flow);
  uVar2 = rtl_read_byte(iVar3,0x1d);
  rtl_write_byte(iVar3,0x1d,uVar2 & 0xfe);
  bVar1 = rtl_read_byte(iVar3,0x1d);
  rtl_write_byte(iVar3,0x1d,bVar1 | 1);
  rtl_write_byte(iVar3,0x1c,0xe);
  iVar3 = (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x104))();
  if (iVar3 == 0) {
    *(undefined1 *)(iVar4 + 0x93c) = 0;
  }
  return;
}

