/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x19960; aliases: rtl92ee_rx_desc_buff_remained_cnt
 */

uint rtl92ee_rx_desc_buff_remained_cnt(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x40);
  iVar2 = (param_2 & 0xff) * 0x814;
  uVar3 = rtl_read_dword(iVar6,0x3b4);
  uVar5 = uVar3 & 0x7ff;
  if (*(ushort *)(iVar6 + 0xbc00 + iVar2 + 0x868) != uVar5) {
    uVar3 = rtl_read_dword(iVar6,0x3b4);
    uVar5 = uVar3 & 0x7ff;
  }
  uVar3 = uVar3 >> 0x10 & 0x7ff;
  if (uVar3 == 0) {
    if (start_rx_11 == '\0') {
      return 0;
    }
  }
  else {
    uVar4 = uVar3;
    if (uVar5 < uVar3) {
      uVar4 = uVar3 - uVar5;
    }
    start_rx_11 = '\x01';
    bVar1 = uVar5 < uVar3;
    uVar3 = uVar4;
    if (bVar1) {
      uVar4 = uVar4 - 1;
      goto LAB_ram_000199c4;
    }
  }
  uVar4 = (uVar3 - uVar5) + 0x1ff;
LAB_ram_000199c4:
  if ((uVar4 & 0xffff) != 0) {
    *(short *)(iVar6 + 0xbc00 + iVar2 + 0x868) = (short)uVar5;
  }
  return uVar4 & 0xffff;
}

