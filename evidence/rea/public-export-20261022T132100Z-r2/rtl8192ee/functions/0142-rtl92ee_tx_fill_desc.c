/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x19e8c; aliases: rtl92ee_tx_fill_desc
 */

void rtl92ee_tx_fill_desc
               (int param_1,ushort *param_2,uint *param_3,undefined4 *param_4,uint *param_5,
               int param_6,int param_7,uint param_8,byte *param_9)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  ushort *puVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  ushort uVar23;
  ushort uVar24;
  int iVar25;
  undefined4 uVar26;
  uint uVar27;
  undefined4 uVar28;
  uint uVar29;
  uint uVar30;
  byte bVar31;
  
  param_8 = param_8 & 0xff;
  iVar25 = *(int *)(param_1 + 0x40);
  uVar30 = (uint)*param_2;
  uVar13 = **(ushort **)(param_7 + 0xbc);
  if ((uVar13 & 0xfc) == 0x80) {
    uVar3 = 0x10;
  }
  else if (((uVar13 & 8) == 0) ||
          (((((param_8 == 6 &&
              (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar6 != 0
              )) && ((uVar13 & 0xc) == 8)) &&
            ((iVar6 = (*(code *)&ieee80211_hdrlen)(uVar13),
             iVar6 + 0xcU <= *(uint *)(param_7 + 0x50) &&
             (pcVar12 = (char *)(*(int *)(param_7 + 0xbc) + iVar6), *pcVar12 == -0x56)))) &&
           ((((pcVar12[1] == -0x56 && ((pcVar12[2] == '\x03' && (pcVar12[3] == '\0')))) &&
             (pcVar12[4] == '\0')) && ((pcVar12[5] == '\0' && (*(short *)(pcVar12 + 6) == -0x7178)))
            ))))) {
    uVar3 = 0x12;
  }
  else {
    uVar3 = (uint)*(byte *)(param_7 + 0x88);
  }
  uVar24 = param_2[0xb];
  uVar13 = *param_2;
  if (*(uint *)(iVar25 + 0x3f4) == 2) {
    bVar31 = *(byte *)(iVar25 + 0x587);
  }
  else if (((*(uint *)(iVar25 + 0x3f4) & 0xfffffffd) == 1) && (param_6 != 0)) {
    bVar31 = *(byte *)(param_6 + 0x1c) & 2;
  }
  else {
    bVar31 = 0;
  }
  (*(code *)&rtl_get_tcb_desc)(param_1,param_5,param_6,param_7,param_9);
  if (*(char *)(iVar25 + 0x6e1) != '\0') {
    (*(code *)&skb_push)(param_7,8);
    (*(code *)&memset)(*(undefined4 *)(param_7 + 0xbc),0,8);
  }
  uVar4 = dma_map_single_attrs_constprop_0
                    (*(int *)(iVar25 + 0xba94) + 0x74,*(undefined4 *)(param_7 + 0xbc),
                     *(undefined4 *)(param_7 + 0x50));
  if (uVar4 == 0xffffffff) {
    return;
  }
  uVar5 = (uint)(uVar24 >> 4);
  if (param_4 != (undefined4 *)0x0) {
    rtl92ee_pre_fill_tx_bd_desc(param_1,param_4,param_3,param_8,param_7,uVar4);
  }
  uVar29 = uVar30 & 0xc;
  if (((uVar30 & 0xfc) == 0x48) || (uVar29 == 4)) {
    uVar27 = 1;
LAB_ram_00019fee:
    if (*(char *)(iVar25 + 0x6e1) == '\0') {
      *param_3 = *param_3 & 0xff00ffff | 0x280000;
    }
    else {
      param_3[1] = param_3[1] & 0xe0ffffff | 0x1000000;
      *param_3 = *param_3 & 0xff00ffff | 0x300000;
      if (param_9[9] != 0) {
        puVar16 = *(uint **)(param_7 + 0xbc);
        (*(code *)&memset)(puVar16,0,8);
        bVar1 = param_9[9];
        uVar14 = *puVar16;
        *puVar16 = uVar14 & 0xfffffff0 | bVar1 & 0xf;
        uVar7 = *(uint *)(param_9 + 0xc);
        if (param_9[9] != 1) {
          if ((uVar7 & 3) == 0) {
            iVar6 = 4;
          }
          else {
            iVar6 = 8 - (uVar7 & 3);
          }
          uVar7 = uVar7 + *(int *)(param_9 + 0x10) + iVar6;
        }
        uVar11 = (uVar7 & 0x7fff) << 4;
        uVar14 = uVar14 & 0xfff80000 | bVar1 & 0xf;
        *puVar16 = uVar11 | uVar14;
        uVar7 = *(uint *)(param_9 + 0x14);
        if (3 < param_9[9]) {
          if ((uVar7 & 3) == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = 8 - (uVar7 & 3);
          }
          uVar7 = uVar7 + *(int *)(param_9 + 0x18) + iVar6;
        }
        uVar7 = (uVar7 & 3) << 0x10;
        uVar14 = uVar11 & 0xfffcffff | uVar14;
        *puVar16 = uVar7 | uVar14;
        uVar11 = *(uint *)(param_9 + 0x1c);
        if (5 < param_9[9]) {
          if ((uVar11 & 3) == 0) {
            iVar6 = 4;
          }
          else {
            iVar6 = 8 - (uVar11 & 3);
          }
          uVar11 = uVar11 + *(int *)(param_9 + 0x20) + iVar6;
        }
        *puVar16 = uVar7 | uVar14 & 0xffffffc3 | (uVar11 & 0xf) << 2;
        uVar7 = puVar16[1];
        uVar11 = uVar11 >> 4 & 0xff;
        puVar16[1] = uVar11 | uVar7 & 0xffffff00;
        uVar14 = *(uint *)(param_9 + 0x24);
        if (7 < param_9[9]) {
          if ((uVar14 & 3) == 0) {
            iVar6 = 4;
          }
          else {
            iVar6 = 8 - (uVar14 & 3);
          }
          uVar14 = uVar14 + *(int *)(param_9 + 0x28) + iVar6;
        }
        uVar11 = uVar11 | uVar7 & 0x1ff00;
        puVar16[1] = uVar14 << 0x11 | uVar11;
        uVar7 = *(uint *)(param_9 + 0x2c);
        if (9 < param_9[9]) {
          if ((uVar7 & 3) == 0) {
            iVar6 = 4;
          }
          else {
            iVar6 = 8 - (uVar7 & 3);
          }
          uVar7 = uVar7 + *(int *)(param_9 + 0x30) + iVar6;
        }
        puVar16[1] = uVar7 << 0x14 | uVar14 << 0x11 & 0xfffff | uVar11;
      }
    }
    param_3[4] = param_3[4] & 0xffffffc0 | param_9[6] & 0x3f;
    bVar1 = param_9[3];
    if (uVar29 == 0) {
      param_9[3] = bVar1 | 4;
      iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
      if ((iVar6 != 0) && (((uVar30 & 0xfc) == 0xb0 || ((uVar30 & 0xdc) == 0x10)))) {
        switch(hgw500_mgmt_reply_rate) {
        case 1:
          uVar7 = 0;
          break;
        case 2:
          uVar7 = 1;
          break;
        default:
          goto switchD_ram_0001a1e6_caseD_3;
        case 6:
          uVar7 = 4;
          break;
        case 0xb:
          uVar7 = 3;
        }
        param_9[6] = (byte)uVar7;
        *param_9 = *param_9 & 0xfc;
        param_9[3] = param_9[3] & 0xf6;
        param_3[4] = param_3[4] & 0xffffffc0 | uVar7;
        iVar6 = (*(code *)&___ratelimit)(_rs_8,"rtl92ee_tx_fill_desc");
        if (iVar6 != 0) {
          uVar10 = rtl92ee_mgmt_subtype_name(uVar30);
          (*(code *)&printk)(&DAT_ram_0001d9a0,uVar10,hgw500_mgmt_reply_rate,param_9[6]);
        }
      }
    }
    else if (*(char *)(iVar25 + 0xb3c8) == '\0') {
      param_9[3] = bVar1 & 0xfb;
    }
    else {
      param_9[3] = bVar1 | 4;
      param_3[4] = param_3[4] & 0xffffffc0 | 3;
    }
switchD_ram_0001a1e6_caseD_3:
    if ((((hgw500_force_data_mcs7 == '\0') ||
         (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar6 == 0)) ||
        (param_6 == 0)) || ((uVar29 != 8 || (*(char *)(iVar25 + 0xb3c8) != '\0')))) {
LAB_ram_0001a5be:
      if (((hgw500_force_data_11m != '\0') &&
          (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar6 != 0))
         && ((param_6 != 0 && ((uVar29 == 8 && (*(char *)(iVar25 + 0xb3c8) == '\0')))))) {
        if ((*param_2 & 0x100) == 0) {
          uVar13 = param_2[2];
        }
        else {
          uVar13 = param_2[8];
        }
        if ((uVar13 & 1) == 0) {
          param_9[3] = param_9[3] & 0xf3 | 4;
          param_3[4] = param_3[4] & 0xffffffc0 | 3;
          if (__print_once_17 == '\0') {
            __print_once_17 = '\x01';
            puVar8 = &DAT_ram_0001da6c;
            goto LAB_ram_0001a3c2;
          }
          goto code_r0x0001a3cc;
        }
      }
      if ((((hgw500_force_data_mcs15 != '\0') &&
           (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"),
           cVar2 = hgw500_force_data_ht40sgi, iVar6 != 0)) && (param_6 != 0)) &&
         ((uVar29 == 8 && (*(char *)(iVar25 + 0xb3c8) == '\0')))) {
        if ((*param_2 & 0x100) == 0) {
          uVar13 = param_2[2];
        }
        else {
          uVar13 = param_2[8];
        }
        if ((uVar13 & 1) == 0) {
          bVar1 = param_9[3];
          param_9[3] = bVar1 & 0xf3 | 4;
          if ((cVar2 != '\0') && (bVar31 != 0)) {
            *param_9 = *param_9 & 0xfc | 1;
            param_9[3] = bVar1 & 0xf2 | 4 | *(byte *)(param_6 + 0x1c) >> 6 & 1;
          }
          param_3[4] = param_3[4] & 0xffffffc0 | 0x1b;
          if (__print_once_16 == '\0') {
            __print_once_16 = '\x01';
            (*(code *)&printk)(&DAT_ram_0001dab0,hgw500_force_data_ht40sgi,*param_9 & 3,
                               param_9[3] & 1,bVar31);
          }
        }
      }
    }
    else {
      if ((*param_2 & 0x100) == 0) {
        uVar13 = param_2[2];
      }
      else {
        uVar13 = param_2[8];
      }
      if ((uVar13 & 1) != 0) goto LAB_ram_0001a5be;
      param_9[6] = 0x13;
      *param_9 = *param_9 & 0xfc;
      param_9[3] = param_9[3] & 0xf2 | 0xc;
      param_3[4] = param_3[4] & 0xffffffc0 | 0x13;
      if (__print_once_18 == '\0') {
        __print_once_18 = '\x01';
        puVar8 = &DAT_ram_0001d9f8;
LAB_ram_0001a3c2:
        (*(code *)&printk)(puVar8);
      }
    }
code_r0x0001a3cc:
    if ((*param_5 & 0x40) != 0) {
      param_3[2] = param_3[2] | 0x1000;
      param_3[3] = param_3[3] & 0xffc1ffff | 0x280000;
    }
    param_3[9] = param_3[9] & 0xff000fff | uVar5 << 0xc;
    uVar14 = param_3[3];
    uVar7 = (uint)((*param_9 & 0x60) == 0x20) << 0xc;
    param_3[3] = uVar7 | uVar14 & 0xffffcfff;
    uVar11 = (*param_9 & 0x40) << 5 | uVar7 | uVar14 & 0xffffc7ff;
    param_3[3] = uVar11;
    uVar7 = param_3[4];
    uVar15 = (param_9[2] & 0x1f) << 0x18;
    param_3[4] = uVar15 | uVar7 & 0xe0ffffff;
    uVar14 = param_3[5];
    uVar17 = (param_9[1] >> 1 & 1) << 0xd;
    param_3[5] = uVar14 & 0xfffe1fff | uVar17;
    if (param_9[2] < 0xc) {
      uVar18 = (uint)(*param_9 >> 7);
    }
    else {
      uVar18 = param_9[1] & 1;
    }
    param_3[5] = uVar14 & 0xfffe0fff | uVar17 | uVar18 << 0xc;
    if (param_9[0x34] != 0) {
      uVar11 = uVar11 | 0x8000;
      param_3[3] = uVar11;
    }
    uVar14 = uVar14 & 0xfffe0ff0 | uVar17 | uVar18 << 0xc;
    if (bVar31 == 0) {
      uVar11 = uVar11 & 0xfeffffff;
      param_3[3] = uVar11;
    }
    else if ((*param_9 & 3) == 1) {
      uVar11 = uVar11 | 0x1000000;
      param_3[3] = uVar11;
      uVar14 = uVar14 | 3;
    }
    else {
      uVar11 = uVar11 & 0xfeffffff;
      param_3[3] = uVar11;
      uVar14 = uVar14 | *(byte *)(iVar25 + 0x58d) & 0xf;
    }
    param_3[5] = uVar14;
    uVar14 = *param_3;
    bVar1 = param_9[3];
    *param_3 = uVar14 & 0xefffffff;
    uVar7 = (bVar1 & 1) << 6 | uVar15 | uVar7 & 0xe0ffffbf;
    param_3[4] = uVar7;
    if (param_6 != 0) {
      param_3[2] = (*(byte *)(param_6 + 0x20) & 7) << 0x14 | param_3[2] & 0xff8fffff;
    }
    if (param_5[7] != 0) {
      uVar15 = *(uint *)(param_5[7] + 8);
      if (uVar15 == 0xfac04) {
        uVar17 = param_3[1] | 0xc00000;
      }
      else {
        uVar17 = param_3[1] & 0xff3fffff;
        if (uVar15 < 0xfac05) {
          if (uVar15 == 0xfac01 || uVar15 == 0xfac02) {
LAB_ram_0001a56a:
            uVar17 = uVar17 | 0x400000;
          }
        }
        else if (uVar15 == 0xfac05) goto LAB_ram_0001a56a;
      }
      param_3[1] = uVar17;
    }
    param_3[1] = param_3[1] & 0xffffe0ff | (uVar3 & 0x1f) << 8;
    param_3[4] = uVar7 | 0x1ff00;
    uVar7 = (param_9[3] & 8) << 7;
    param_3[3] = uVar11 & 0xfffffbff | uVar7;
    param_3[3] = (param_9[3] & 4) << 6 | uVar11 & 0xfffffaff | uVar7;
    if (((uVar30 & 0x8c) == 0x88) && (*(char *)(iVar25 + 0x564) != '\0')) {
      param_3[2] = param_3[2] | 0x2000;
      *param_3 = uVar14 & 0xefffffff | 0x2000000;
    }
    (*(code *)&rtl_set_tx_report)(param_9,param_3,param_1,param_7 + 0x38);
    iVar6 = 1;
  }
  else {
    uVar27 = ~(uint)(uVar13 >> 10) & 1;
    if ((uVar24 & 0xf) == 0) goto LAB_ram_00019fee;
    iVar6 = 0;
  }
  uVar7 = *param_3 & 0xf3ffffff | iVar6 << 0x1b | uVar27 << 0x1a;
  *param_3 = uVar7;
  param_3[10] = uVar4;
  if (*(char *)(iVar25 + 0xa011) == '\0') {
    uVar4 = (param_9[4] + 0xc & 0x1f) << 0x10 | param_3[1] & 0xffe0ffff;
    param_3[1] = uVar4;
    bVar1 = param_9[4];
  }
  else {
    uVar4 = (param_9[4] & 0x1f) << 0x10 | param_3[1] & 0xffe0ffff;
    param_3[1] = uVar4;
    bVar1 = param_9[5];
  }
  param_3[1] = uVar4 & 0xffffff80 | bVar1 & 0x7f;
  param_3[2] = param_3[2] & 0xfffdffff | (uVar27 ^ 1) << 0x11;
  if ((*param_2 & 0x100) == 0) {
    uVar13 = param_2[2];
    puVar9 = param_2 + 2;
  }
  else {
    uVar13 = param_2[8];
    puVar9 = param_2 + 8;
  }
  if (((uVar13 & 1) != 0) || ((*puVar9 & puVar9[1] & puVar9[2]) == 0xffff)) {
    *param_3 = uVar7 | 0x1000000;
  }
  if ((((rtl92ee_hgw500_tx_rate_trace != '\0') &&
       (iVar6 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar6 != 0)) &&
      (param_8 == 1)) && ((param_6 != 0 && (uVar29 == 8)))) {
    if ((*param_2 & 0x100) == 0) {
      uVar13 = param_2[2];
    }
    else {
      uVar13 = param_2[8];
    }
    if (((uVar13 & 1) == 0) &&
       ((uVar4 = rate_trace_count_6 + 1, rate_trace_count_6 = uVar4, uVar4 < 0x21 ||
        (iVar6 = is_power_of_2(uVar4), iVar6 != 0)))) {
      puVar9 = *(ushort **)(param_7 + 0xbc);
      bVar1 = param_9[3];
      if ((~*puVar9 & 0x300) == 0) {
        puVar9 = puVar9 + 0xf;
      }
      else {
        puVar9 = puVar9 + 0xc;
      }
      (*(code *)&printk)(&DAT_ram_0001db28,uVar4,*(undefined4 *)(param_7 + 0x50),(byte)*puVar9 & 0xf
                         ,param_9[5],param_9[4],param_9[6],bVar1 >> 2 & 1,bVar1 >> 3 & 1,
                         (byte)*param_5 >> 6 & 1,bVar1 & 1,*param_9 & 3,bVar31,uVar3,*param_3,
                         param_3[1],param_3[2],param_3[3],param_3[4],param_3[5]);
    }
  }
  if (*(uint *)(param_7 + 0x50) < 0x18) {
    return;
  }
  iVar6 = rtl92ee_hgw500_trace_mgmt_frame(param_1,uVar30);
  if (iVar6 == 0) {
    return;
  }
  uVar10 = rtl92ee_mgmt_subtype_name(uVar30);
  if (*(uint *)(param_7 + 0x50) < 0x1d || param_2 + 5 == (ushort *)0x0) {
    uVar24 = 0;
    uVar13 = 0;
    uVar23 = 0;
  }
  else {
    uVar13 = param_2[0xc];
    uVar24 = param_2[0xd];
    uVar23 = param_2[0xe];
  }
  if (param_4 == (undefined4 *)0x0) {
    uVar21 = 0;
    uVar20 = 0;
    uVar19 = 0;
    uVar22 = 0;
  }
  else {
    uVar22 = *param_4;
    uVar19 = param_4[1];
    uVar20 = param_4[2];
    uVar21 = param_4[3];
    if (0x17 < *(ushort *)(iVar25 + param_8 * 0x2c + 0xbac4)) {
      uVar26 = param_4[4];
      uVar28 = param_4[5];
      goto LAB_ram_0001aa7e;
    }
  }
  uVar26 = 0;
  uVar28 = 0;
LAB_ram_0001aa7e:
  (*(code *)&printk)(&DAT_ram_0001dbf4,uVar10,uVar30,*(uint *)(param_7 + 0x50),param_8,uVar3,uVar5,
                     param_9[6],param_9[3] >> 2 & 1,bVar31,param_6 != 0,param_2 + 2,param_2 + 5,
                     param_2 + 8,uVar13,uVar24,uVar23,*param_3,param_3[1],param_3[2],param_3[3],
                     param_3[7],uVar22,uVar19,uVar20,uVar21,uVar26,uVar28);
  return;
}

