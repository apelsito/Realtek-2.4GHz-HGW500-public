/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b110; aliases: rtl92ee_is_tx_desc_closed
 */

byte rtl92ee_is_tx_desc_closed(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  param_2 = param_2 & 0xff;
  iVar7 = *(int *)(param_1 + 0x40);
  param_3 = param_3 & 0xffff;
  if (param_2 < 8) {
    uVar5 = *(undefined2 *)(CSWTCH_176 + param_2 * 2);
  }
  else {
    uVar5 = 0x3a8;
  }
  uVar2 = rtl_read_dword(iVar7,uVar5);
  uVar9 = uVar2 >> 0x10 & 0xfff;
  iVar3 = param_2 * 0x2c + iVar7 + 0xbc00;
  uVar11 = (uint)*(ushort *)(iVar3 + -0x13a);
  *(short *)(iVar3 + -0x138) = (short)uVar9;
  if (uVar9 < uVar11) {
    bVar14 = uVar11 <= param_3 || param_3 < uVar9;
  }
  else if (uVar11 < uVar9) {
    bVar14 = uVar11 < param_3 && param_3 < uVar9;
  }
  else {
    bVar14 = uVar9 != param_3;
  }
  if (*(char *)(iVar7 + 0x62c) == '\0') {
    bVar6 = bVar14 | (0x20000000 < *(uint *)(iVar7 + 0xb300) || param_2 == 4);
    if (3 < param_2) goto code_r0x0001b1f2;
    if (bVar6 == 0) {
      stop_report_cnt_4 = stop_report_cnt_4 + '\x01';
      goto code_r0x0001b1f2;
    }
LAB_ram_0001b346:
    stop_report_cnt_4 = '\0';
  }
  else if (param_2 < 4) goto LAB_ram_0001b346;
  bVar6 = 1;
code_r0x0001b1f2:
  if ((((hgw500_tx_close_diag != '\0') &&
       (iVar3 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar3 != 0)) &&
      (param_2 == 1)) && (bVar6 == 0)) {
    bVar1 = *(byte *)(*(int *)(iVar7 + 0xbacc) + param_3 * 0x40 + 3);
    uVar10 = close_diag_count_3 + 1;
    if (*(char *)(iVar7 + 0xba10) == '\0') {
      uVar8 = 0;
    }
    else {
      uVar8 = *(uint *)(*(int *)(iVar7 + 0xbae8) + *(ushort *)(iVar7 + 0xbaf0) * param_3);
    }
    uVar12 = *(uint *)(iVar7 + 0xbae4);
    if (close_diag_max_queued_2 < uVar12) {
      uVar13 = 1;
      close_diag_max_queued_2 = uVar12;
      if (uVar12 < *(int *)(iVar7 + 0xbad8) - 2U) {
        uVar13 = 0;
      }
    }
    else {
      uVar13 = 0;
    }
    close_diag_count_3 = uVar10;
    if ((uVar10 < 0x11) || (uVar4 = is_power_of_2(uVar10), ((uVar4 | uVar13) & 0xff) != 0)) {
      (*(code *)&printk)(&DAT_ram_0001dfa4,uVar10,1,param_3,uVar9,uVar11,uVar9,uVar2 & 0xfff,
                         *(undefined4 *)(iVar7 + 0xbad8),uVar12,bVar1 >> 7,uVar8 >> 0x1f,uVar2);
    }
  }
  return bVar6;
}

