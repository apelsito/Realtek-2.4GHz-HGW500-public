/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x19a48; aliases: rtl92ee_pre_fill_tx_bd_desc
 */

void rtl92ee_pre_fill_tx_bd_desc
               (int param_1,uint *param_2,undefined4 param_3,uint param_4,int param_5,uint param_6)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  uint uVar16;
  bool bVar17;
  uint local_50;
  
  param_4 = param_4 & 0xff;
  iVar8 = param_4 * 0x2c;
  iVar14 = *(int *)(param_1 + 0x40);
  uVar10 = *(uint *)(param_5 + 0x50);
  sVar1 = *(short *)(iVar14 + 0xbc00 + iVar8 + -0x13c);
  iVar5 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  if ((iVar5 == 0) || (hgw500_tx_page_units != 4)) {
    iVar5 = 2;
  }
  else {
    iVar5 = 4;
  }
  uVar4 = *(ushort *)(iVar14 + 0xbc00 + iVar8 + -0x13a);
  local_50 = uVar10 + 0x28;
  if ((*(char *)(iVar14 + 0x6e1) == '\0') || (3 < param_4)) {
    bVar2 = false;
  }
  else {
    local_50 = uVar10 + 0x30;
    bVar2 = true;
  }
  if (((((hgw500_txbd_be_data_split == '\0') ||
        (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar6 == 0)) ||
       (param_4 != 1)) || ((*(short *)(iVar14 + 0xbaf0) != 0x40 || (bVar2)))) || (uVar10 < 0x18)) {
LAB_ram_00019b16:
    uVar11 = 0;
  }
  else {
    pbVar15 = *(byte **)(param_5 + 0xbc);
    if ((*pbVar15 & 0xc) != 8) goto LAB_ram_00019b16;
    uVar7 = (*(code *)&ieee80211_hdrlen)(*(undefined2 *)pbVar15);
    uVar11 = uVar7 & 0xffff;
    if ((((uVar7 & 0xffff) + 8 <= uVar10) &&
        (pbVar15 = pbVar15 + (uVar7 & 0xffff), *pbVar15 == 0xaa)) &&
       ((pbVar15[1] == 0xaa && (pbVar15[2] == 3)))) {
      uVar11 = uVar7 + 8 & 0xffff;
    }
    bVar17 = uVar11 < uVar10;
    if (0x17 < uVar11) goto LAB_ram_00019ba6;
  }
  bVar17 = false;
LAB_ram_00019ba6:
  uVar7 = (*(code *)&__udivsi3)(local_50,iVar5 << 7);
  if (iVar5 * uVar7 * 0x80 < local_50) {
    uVar7 = uVar7 + 1;
  }
  uVar13 = (uint)uVar4 * 0x40 + *(int *)(iVar14 + iVar8 + 0xbaa4);
  if (sVar1 == 0x20) {
    puVar12 = *(ushort **)(param_5 + 0xbc);
    (*(code *)&memset)(param_2,0,0x20);
    (*(code *)&memset)(param_3,0,0x28);
    iVar8 = (uint)(param_4 < 4) << 3;
    if (*(char *)(iVar14 + 0x6e1) == '\0') {
      iVar8 = 0;
    }
    *param_2 = *param_2 & 0xc000 | iVar8 + 0x28U | (uVar7 & 0x7fff) << 0x10;
    cVar3 = hgw500_txbd_mgmt_split;
    param_2[1] = uVar13;
    if (((((cVar3 == '\0') ||
          (iVar8 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar8 == 0))
         || (bVar2)) || (uVar10 < 0x18)) ||
       ((((uVar4 = *puVar12, (uVar4 & 0xec) != 0xa0 && ((uVar4 & 0xdc) != 0x10)) &&
         ((uVar4 & 0xfc) != 0xc0)) ||
        ((uVar4 = (*(code *)&ieee80211_hdrlen)(), uVar4 < 0x18 ||
         (uVar11 = (uint)uVar4, uVar10 <= uVar11)))))) {
      param_2[2] = uVar10;
      param_2[3] = param_6;
    }
    else {
      param_2[3] = param_6;
      param_2[2] = uVar11;
      param_2[4] = uVar10 - uVar11;
      param_2[5] = param_6 + uVar11;
      iVar8 = (*(code *)&___ratelimit)(_rs_10,"rtl92ee_pre_fill_tx_bd_desc");
      if (iVar8 != 0) {
        (*(code *)&printk)(&DAT_ram_0001d8f4,param_4,uVar10,uVar11,uVar10 - uVar11);
      }
    }
  }
  else {
    uVar16 = 1;
    *param_2 = *param_2 & 0xc000;
    do {
      set_txbuffer_desc_len_with_offset(param_2,uVar16,0);
      puVar9 = param_2 + uVar16 * 4;
      uVar16 = uVar16 + 1 & 0xff;
      *puVar9 = *puVar9 & 0x7fffffff;
      puVar9[1] = 0;
      puVar9[2] = 0;
    } while (uVar16 != 4);
    (*(code *)&memset)(param_3,0,0x28);
    if ((*(char *)(iVar14 + 0x6e1) == '\0') || (3 < param_4)) {
      uVar16 = *param_2 & 0xffffc000 | 0x28;
    }
    else {
      uVar16 = *param_2 & 0xffffc000 | 0x30;
    }
    param_2[1] = uVar13;
    *param_2 = (uVar7 & 0x7fff) << 0x10 | uVar16 & 0x8000ffff;
    param_2[2] = 0;
    if (bVar17) {
      set_txbuffer_desc_len_with_offset(param_2,1,uVar11);
      param_2[4] = param_2[4] & 0x7fffffff;
      param_2[5] = param_6;
      param_2[6] = 0;
      set_txbuffer_desc_len_with_offset(param_2,2,uVar10 - uVar11);
      param_2[8] = param_2[8] & 0x7fffffff;
      cVar3 = __print_once_19;
      param_2[9] = param_6 + uVar11;
      param_2[10] = 0;
      if (cVar3 == '\0') {
        __print_once_19 = '\x01';
        (*(code *)&printk)(&DAT_ram_0001d944,param_4,uVar11,uVar10 - uVar11);
      }
    }
    else {
      set_txbuffer_desc_len_with_offset(param_2,1,uVar10);
      param_2[5] = param_6;
      param_2[4] = param_2[4] & 0x7fffffff;
      param_2[6] = 0;
    }
  }
  set_tx_desc_pkt_size(param_3,uVar10 & 0xffff);
  set_tx_desc_tx_buffer_size(param_3,uVar10 & 0xffff);
  return;
}

