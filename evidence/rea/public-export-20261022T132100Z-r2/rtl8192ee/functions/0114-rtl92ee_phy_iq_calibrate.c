/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17d08; aliases: rtl92ee_phy_iq_calibrate
 */

void rtl92ee_phy_iq_calibrate(int param_1,char param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_118 [36];
  undefined1 auStack_f4 [60];
  uint local_b8 [32];
  
  iVar9 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(local_b8,0,0x80);
  (*(code *)&memcpy)(auStack_118,&DAT_ram_0001c764,0x24);
  if (param_2 != '\0') {
    _rtl92ee_phy_reload_adda_registers(param_1,auStack_118,iVar9 + 0x914,9);
    return;
  }
  uVar6 = 0;
  do {
    local_b8[uVar6] = 0;
    local_b8[uVar6 + 8] = 0;
    local_b8[uVar6 + 0x10] = 0;
    uVar2 = uVar6 + 1 & 0xff;
    local_b8[uVar6 + 0x18] = (0x55U >> ((byte)uVar6 & 0x1f) & 1) << 8;
    uVar6 = uVar2;
  } while (uVar2 != 8);
  cVar8 = '\0';
  do {
    _rtl92ee_phy_iq_calibrate_constprop_0(param_1,local_b8,cVar8);
    if (cVar8 == '\x01') {
      iVar3 = _rtl92ee_phy_simularity_compare_isra_0(local_b8,0,1);
      if (iVar3 != 0) break;
    }
    else if (cVar8 == '\x02') {
      iVar3 = _rtl92ee_phy_simularity_compare_isra_0(local_b8,0,2);
      if (iVar3 == 0) {
        iVar3 = _rtl92ee_phy_simularity_compare_isra_0(local_b8,1,2);
        if (iVar3 == 0) {
          iVar3 = 3;
        }
        else {
          iVar3 = 1;
        }
        goto LAB_ram_00017e36;
      }
      break;
    }
    cVar8 = cVar8 + '\x01';
  } while( true );
  iVar3 = 0;
LAB_ram_00017e36:
  uVar6 = local_b8[iVar3 * 8];
  *(uint *)(iVar9 + 0x898) = local_b8[iVar3 * 8 + 1];
  uVar2 = local_b8[iVar3 * 8 + 4];
  *(uint *)(iVar9 + 0x894) = uVar6;
  uVar10 = local_b8[iVar3 * 8 + 2];
  *(uint *)(iVar9 + 0x8a4) = uVar2;
  uVar2 = local_b8[iVar3 * 8 + 6];
  *(uint *)(iVar9 + 0x8a8) = local_b8[iVar3 * 8 + 5];
  if (uVar6 != 0) {
    uVar4 = rtl_get_bbreg(param_1,0xc80,0xffffffff);
    uVar6 = local_b8[iVar3 * 8];
    if ((uVar6 & 0x200) != 0) {
      uVar6 = uVar6 | 0xfffffc00;
    }
    uVar6 = uVar6 * (uVar4 >> 0x16);
    rtl_set_bbreg(param_1,0xc80,0x3ff,uVar6 >> 8);
    rtl_set_bbreg(param_1,0xc4c,0x80000000,uVar6 >> 7 & 1);
    uVar6 = local_b8[iVar3 * 8 + 1];
    if ((uVar6 & 0x200) != 0) {
      uVar6 = uVar6 | 0xfffffc00;
    }
    uVar6 = uVar6 * (uVar4 >> 0x16);
    uVar4 = uVar6 >> 8;
    rtl_set_bbreg(param_1,0xc94,0xf0000000,(int)uVar4 >> 6 & 0xf);
    rtl_set_bbreg(param_1,0xc80,0x3f0000,uVar4 & 0x3f);
    rtl_set_bbreg(param_1,0xc4c,0x20000000,uVar6 >> 7 & 1);
    if (uVar10 != 0) {
      rtl_set_bbreg(param_1,0xc14,0x3ff,local_b8[iVar3 * 8 + 2]);
      uVar6 = local_b8[iVar3 * 8 + 3];
      rtl_set_bbreg(param_1,0xc14,0xfc00,uVar6 & 0x3f);
      rtl_set_bbreg(param_1,0xca0,0xf0000000,(int)uVar6 >> 6 & 0xf);
    }
  }
  uVar10 = rtl_get_bbreg(param_1,0xc80,0xffffffff);
  uVar6 = local_b8[iVar3 * 8 + 4];
  if ((uVar6 & 0x200) != 0) {
    uVar6 = uVar6 | 0xfffffc00;
  }
  uVar6 = uVar6 * (uVar10 >> 0x16);
  rtl_set_bbreg(param_1,0xc80,0x3ff,uVar6 >> 8);
  rtl_set_bbreg(param_1,0xc4c,0x8000000,uVar6 >> 7 & 1);
  uVar6 = local_b8[iVar3 * 8 + 5];
  if ((uVar6 & 0x200) != 0) {
    uVar6 = uVar6 | 0xfffffc00;
  }
  uVar6 = uVar6 * (uVar10 >> 0x16);
  uVar10 = uVar6 >> 8;
  rtl_set_bbreg(param_1,0xc9c,0xf0000000,(int)uVar10 >> 6 & 0xf);
  rtl_set_bbreg(param_1,0xc88,0x3f0000,uVar10 & 0x3f);
  rtl_set_bbreg(param_1,0xc4c,0x2000000,uVar6 >> 7 & 1);
  if (uVar2 != 0) {
    rtl_set_bbreg(param_1,0xc1c,0x3ff,local_b8[iVar3 * 8 + 6]);
    uVar6 = local_b8[iVar3 * 8 + 7];
    rtl_set_bbreg(param_1,0xc1c,0xfc00,uVar6 & 0x3f);
    rtl_set_bbreg(param_1,0xc78,0xf0000000,(int)uVar6 >> 6 & 0xf);
  }
  bVar1 = *(byte *)(iVar9 + 0x88f);
  iVar5 = (*(code *)&memcpy)(auStack_f4,&DAT_ram_0001d350,0x3b);
  if (0xe < bVar1) {
    uVar6 = 0xe;
    do {
      if (*(byte *)(iVar5 + uVar6) == bVar1) {
        uVar6 = uVar6 - 0xd & 0xff;
        goto LAB_ram_0001808c;
      }
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 != 0x3b);
  }
  uVar6 = 0;
LAB_ram_0001808c:
  uVar2 = 0;
  do {
    iVar7 = uVar2 + iVar3 * 8;
    iVar5 = uVar6 * 9 + uVar2;
    uVar2 = uVar2 + 1 & 0xff;
    *(uint *)(iVar9 + 0x800 + iVar5 * 4 + 0x148) = local_b8[iVar7];
  } while (uVar2 != 8);
  *(undefined1 *)(iVar9 + 0x800 + uVar6 * 0x24 + 0x144) = 1;
  _rtl92ee_phy_save_adda_registers(param_1,auStack_118,iVar9 + 0x914,9);
  return;
}

