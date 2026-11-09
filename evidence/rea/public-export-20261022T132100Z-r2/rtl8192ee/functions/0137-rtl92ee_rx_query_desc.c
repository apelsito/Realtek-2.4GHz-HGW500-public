/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18dec; aliases: rtl92ee_rx_query_desc
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
rtl92ee_rx_query_desc(int param_1,ushort *param_2,undefined4 *param_3,uint *param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  ushort *puVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  ushort *puVar15;
  char cVar16;
  byte bVar17;
  ushort uVar18;
  uint uVar19;
  int iVar20;
  ushort uVar21;
  int iVar22;
  ushort *puVar23;
  ushort uVar24;
  int iVar25;
  uint uVar26;
  ushort *puVar27;
  int iVar28;
  char cVar29;
  bool bVar30;
  int iStack_64;
  undefined1 local_58;
  undefined1 uStack_57;
  
  uVar26 = *param_4;
  uVar19 = param_4[2];
  *(byte *)(param_2 + 0x41) = (byte)((uVar19 & 0x10000000) >> 0x1a);
  param_2[0x15] = (ushort)*param_4 & 0x3fff;
  iVar20 = (*(ushort *)((int)param_4 + 2) & 0xf) * 8;
  *(char *)((int)param_2 + 0x41) = (char)iVar20;
  bVar5 = (byte)param_2[0x1b];
  uVar14 = *(byte *)((int)param_4 + 3) & 3;
  *(char *)(param_2 + 0x21) = (char)uVar14;
  uVar8 = *param_4;
  bVar17 = (byte)((uVar8 & 0x8000) >> 0xd);
  *(byte *)(param_2 + 0x1b) = bVar5 & 0xfb | bVar17;
  uVar9 = (*param_4 & 0x4000) >> 0xe;
  bVar4 = (byte)uVar9 | (byte)((uVar8 & 0x8000) >> 0xf) | (byte)(uVar9 << 1);
  *(byte *)(param_2 + 0x1b) = bVar4 | bVar5 & 0xf8 | bVar17;
  bVar3 = (byte)((~*param_4 & 0x8000000) >> 0x16);
  *(byte *)(param_2 + 0x1b) = bVar4 | bVar5 & 0xd8 | bVar17 | bVar3;
  uVar9 = param_4[3];
  *(byte *)((int)param_2 + 0x13) = (byte)uVar9 & 0x3f;
  *(byte *)(param_2 + 0x1b) =
       bVar4 | bVar5 & 0xd0 | bVar17 | bVar3 | (byte)((param_4[3] & 0x100) >> 5);
  *(char *)((int)param_2 + 0x43) = (char)((param_4[1] & 0x8000) >> 0xf);
  uVar8 = (param_4[1] & 0x8000) >> 0xf;
  bVar5 = (byte)uVar8;
  if (uVar8 == 1) {
    bVar5 = (byte)(param_4[1] >> 0x10) & 1;
  }
  *(byte *)(param_2 + 0x22) = bVar5;
  *(uint *)(param_2 + 0x1c) = param_4[5];
  *(char *)((int)param_2 + 0x45) = (char)((param_4[3] & 0x200) >> 9);
  *(byte *)(param_2 + 0x3c) = (byte)(param_4[3] >> 6) & 1;
  *(bool *)((int)param_2 + 0x77) = (uVar9 & 0x3c) == 0;
  *(uint *)(param_2 + 0x42) = param_4[1] & 0x7f;
  puVar23 = (ushort *)(*(int *)(param_5 + 0xbc) + uVar14 + 0x18 + iVar20);
  if (((uVar19 & 0x10000000) == 0x10000000) &&
     (iVar20 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar20 != 0)) {
    if (hgw500_oem_tx_report == '\0') {
      return 1;
    }
    uVar24 = param_2[0x15];
    iVar20 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
    if (iVar20 == 0) {
      return 1;
    }
    if (uVar24 < 2) {
      (*(code *)&printk)(&DAT_ram_0001d59c,uVar24);
      return 1;
    }
    uVar8 = hgw500_oem_tx_report_count + 1;
    uVar7 = *puVar23;
    cVar16 = *(char *)((int)puVar23 + 1);
    hgw500_oem_tx_report_count = uVar8;
    if ((uVar8 < 9) || (iVar20 = is_power_of_2(uVar8), iVar20 != 0)) {
      uVar18 = 0x10;
      if (uVar24 < 0x11) {
        uVar18 = uVar24;
      }
      (*(code *)&printk)(&DAT_ram_0001d5cc,uVar8,(char)uVar7,cVar16,uVar24 - 2,uVar18,puVar23);
    }
    if ((char)uVar7 != '\x04') {
      return 1;
    }
    if ((ushort)(uVar24 - 2) < 0xc) {
      (*(code *)&printk)(&DAT_ram_0001d618,uVar8,(int)(short)(uVar24 - 2),0xc);
      return 1;
    }
    iVar20 = 0;
    do {
      pcVar10 = (char *)((int)puVar23 + (-iVar20 & 6U) + 2);
      if (*pcVar10 != -1) {
        (*(code *)&printk)(&DAT_ram_0001d660,uVar8,iVar20,*pcVar10,*(undefined2 *)(pcVar10 + 1),
                           *(undefined2 *)(pcVar10 + 3),pcVar10[5]);
      }
      bVar1 = iVar20 != 1;
      iVar20 = 1;
    } while (bVar1);
    return 1;
  }
  *(ushort *)(param_3 + 7) =
       *(ushort *)(param_3 + 7) & 0xe000 |
       (ushort)*(undefined4 *)(*(int *)(param_1 + 0x14) + 4) & 0x1fff;
  *(char *)(param_3 + 9) = (char)**(undefined4 **)(param_1 + 0x14);
  iVar20 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  if ((iVar20 == 0) || (uVar8 = (uint)puVar23 & 1, uVar8 == 0)) {
    uVar24 = *puVar23;
    if (((uVar24 & 0xfc) - 0xa0 & 0xffdc) == 0) {
LAB_ram_000195d4:
      uVar8 = 1;
    }
    else if ((uVar24 & 0xfc) == 0xd0) {
      if ((uVar24 & 0x4000) != 0) goto LAB_ram_000195d4;
      bVar5 = (byte)puVar23[0xc];
      if (bVar5 < 0x16) {
        if (bVar5 < 4) goto LAB_ram_000195d4;
        uVar8 = ~(0x308890U >> (bVar5 & 0x1f)) & 1;
      }
      else {
        uVar8 = (uint)(bVar5 != 0x7f);
      }
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    uVar24 = *puVar23;
    if (((uVar24 & 0xfc) - 0xa0 & 0xffdc) == 0) {
LAB_ram_0001957c:
      uVar8 = 1;
    }
    else if ((uVar24 & 0xfc) == 0xd0) {
      if ((uVar24 & 0x4000) != 0) goto LAB_ram_0001957c;
      bVar5 = (byte)puVar23[0xc];
      if (bVar5 < 0x16) {
        if (3 < bVar5) {
          uVar8 = ~(0x308890U >> (bVar5 & 0x1f)) & 1;
        }
      }
      else {
        uVar8 = (uint)(bVar5 != 0x7f);
      }
    }
    else {
      uVar8 = 0;
    }
    if (__print_once_21 == '\0') {
      __print_once_21 = '\x01';
      (*(code *)&printk)(&DAT_ram_0001d6c4,(char)param_2[0x21],*(undefined1 *)((int)param_2 + 0x41))
      ;
    }
  }
  if (((param_2[0x1b] & 1) == 0) && ((uVar24 & 0xc) == 8)) {
    uVar14 = *(uint *)(param_2 + 0x42);
    uVar9 = uVar14 & 0xff;
    uStack_57 = 0xff;
    if (0x3e < uVar9) {
      uVar9 = 2;
    }
    local_58 = (undefined1)uVar9;
    if (((hgw500_oem_tx_report != '\0') &&
        (iVar20 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar20 != 0))
       && (-1 < (_jiffies + -100) - hgw500_oem_tx_report_last_request)) {
      if (uVar9 != 2) {
        uStack_57 = 2;
      }
      hgw500_oem_tx_report_last_request = _jiffies;
      uVar9 = hgw500_oem_tx_report_request_count + 1;
      hgw500_oem_tx_report_request_count = uVar9;
      rtl92ee_fill_h2c_cmd(param_1,0x43,2,&local_58);
      if ((uVar9 < 9) || (iVar20 = is_power_of_2(uVar9), iVar20 != 0)) {
        (*(code *)&printk)(&DAT_ram_0001d718,uVar9,uVar14 & 0xff,local_58,uStack_57,0x43);
      }
    }
  }
  if ((param_2[0x1b] & 2) != 0) {
    param_3[6] = param_3[6] | 0x20;
  }
  if (*(char *)((int)param_2 + 0x45) != '\0') {
    *(byte *)((int)param_3 + 0x1f) = *(byte *)((int)param_3 + 0x1f) & 0xe3 | 0xc;
  }
  if ((char)param_2[0x3c] != '\0') {
    *(byte *)((int)param_3 + 0x1f) = *(byte *)((int)param_3 + 0x1f) & 0xfc | 1;
  }
  uVar9 = param_3[6];
  param_3[6] = uVar9 | 0x80;
  if ((param_2[0x1b] & 0x20) != 0) {
    if ((uVar8 == 0) && ((uVar24 & 0x4000) != 0)) {
      uVar9 = uVar9 | 2;
    }
    else {
      uVar9 = uVar9 & 0xfffffffd;
    }
    param_3[6] = uVar9 | 0x80;
  }
  uVar6 = (*(code *)&rtlwifi_rate_mapping)
                    (param_1,(char)param_2[0x3c],0,*(undefined1 *)((int)param_2 + 0x13));
  *(undefined1 *)((int)param_3 + 0x21) = uVar6;
  if (((char)param_2[0x3c] != '\0') && (__print_once_20 == '\0')) {
    __print_once_20 = '\x01';
    (*(code *)&printk)(&DAT_ram_0001d770,*(undefined1 *)((int)param_2 + 0x13),uVar6,
                       *(undefined1 *)((int)param_2 + 0x45),*(undefined1 *)((int)param_2 + 0x43),
                       (char)param_2[0x22],param_4[3]);
  }
  *param_3 = *(undefined4 *)(param_2 + 0x1c);
  param_3[1] = 0;
  if ((uVar26 & 0x4000000) == 0) goto LAB_ram_00019732;
  iVar20 = *(int *)(param_5 + 0xbc);
  uVar8 = (uint)(byte)param_2[0x21];
  iVar22 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(&local_58,0,0x1e);
  iVar25 = uVar8 + 0x18 + iVar20;
  puVar27 = (ushort *)(iVar20 + *(byte *)((int)param_2 + 0x41) + uVar8 + 0x18);
  iVar20 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  puVar11 = puVar27;
  if ((iVar20 != 0) && (((uint)puVar27 & 1) != 0)) {
    uVar7 = 0x1e;
    if (param_2[0x15] < 0x1f) {
      uVar7 = param_2[0x15];
    }
    (*(code *)&memset)(&local_58,0,0x1e);
    (*(code *)&memcpy)(&local_58,puVar27,uVar7);
    if (__print_once_22 == '\0') {
      __print_once_22 = '\x01';
      (*(code *)&printk)(&DAT_ram_0001d7e0,(char)param_2[0x21],*(undefined1 *)((int)param_2 + 0x41))
      ;
    }
    puVar11 = (ushort *)&local_58;
  }
  uVar7 = *puVar11;
  if ((~uVar7 & 0x300) == 0) {
    uVar18 = puVar11[0xc];
    puVar15 = puVar11 + 0xc;
  }
  else if ((uVar7 & 0x200) == 0) {
    uVar18 = puVar11[5];
    puVar15 = puVar11 + 5;
  }
  else {
    uVar18 = puVar11[8];
    puVar15 = puVar11 + 8;
  }
  *param_2 = uVar18;
  param_2[1] = puVar15[1];
  param_2[2] = puVar15[2];
  if ((uVar7 & 0xc) == 4) {
LAB_ram_00019622:
    bVar1 = false;
    bVar2 = false;
    bVar30 = false;
  }
  else {
    puVar15 = puVar11 + 2;
    if (((uVar7 & 0x100) == 0) && (puVar15 = puVar11 + 5, puVar15 == (ushort *)0x0)) {
      puVar15 = puVar11 + 8;
    }
    if (((*(ushort *)(iVar22 + 0x566) != *puVar15 || *(ushort *)(iVar22 + 0x568) != puVar15[1]) ||
         puVar15[2] != *(ushort *)(iVar22 + 0x56a)) || ((param_2[0x1b] & 7) != 0))
    goto LAB_ram_00019622;
    bVar2 = true;
    bVar30 = (puVar11[2] == *(ushort *)(iVar22 + 0xa9f8) &&
             puVar11[3] == *(ushort *)(iVar22 + 0xa9fa)) &&
             puVar11[4] == *(ushort *)(iVar22 + 0xa9fc);
    bVar1 = true;
  }
  if ((uVar7 & 0xfc) == 0x80) {
    if (bVar1) {
      *(short *)(*(int *)(param_1 + 0x40) + 0xa074) =
           *(short *)(*(int *)(param_1 + 0x40) + 0xa074) + 1;
LAB_ram_000194ac:
      if ((uVar7 & 0x8c) == 0x88) {
        if ((*puVar11 & 0x100) == 0) {
          uVar7 = puVar11[2];
        }
        else {
          uVar7 = puVar11[8];
        }
        if (((uVar7 & 1) == 0) && ((9U >> ((byte)puVar11[0xc] & 0xf) & 1) == 0)) {
          *(short *)(*(int *)(param_1 + 0x40) + 0xa076) =
               *(short *)(*(int *)(param_1 + 0x40) + 0xa076) + 1;
        }
      }
    }
    else {
      bVar1 = true;
    }
  }
  else if (bVar1) {
    bVar1 = false;
    goto LAB_ram_000194ac;
  }
  iVar20 = *(int *)(param_1 + 0x40);
  *(bool *)(param_2 + 0x3b) = bVar2;
  *(bool *)((int)param_2 + 0x79) = bVar30;
  *(bool *)(param_2 + 0x3d) = bVar1;
  param_2[0x28] = 0xffff;
  if (*(char *)((int)param_2 + 0x77) == '\0') {
    iStack_64 = 0;
    cVar16 = '\0';
    iVar22 = 0;
    do {
      iVar28 = (int)param_2 + iVar22;
      cVar16 = cVar16 + *(char *)(iVar20 + iVar22 + 0xa012);
      *(byte *)(iVar28 + 0x6c) = ((*(byte *)(iVar25 + iVar22) & 0x3f) - 0x37) * '\x02';
      iVar13 = (*(code *)&rtl_query_rxpwrpercentage)();
      *(char *)(iVar28 + 0x4c) = (char)iVar13;
      uVar8 = iVar22 + 1;
      iStack_64 = iStack_64 + iVar13;
      iVar22 = 1;
    } while (uVar8 != 2);
    cVar29 = (*(byte *)(iVar25 + 4) >> 1) + 0x92;
    uVar12 = (*(code *)&rtl_query_rxpwrpercentage)((int)cVar29);
    *(undefined4 *)(param_2 + 0x24) = uVar12;
    *(undefined4 *)(param_2 + 0x44) = uVar12;
    *(char *)(param_2 + 0x1a) = cVar29;
    iVar20 = 0;
    *(int *)(param_2 + 0x18) = (int)cVar29;
    if (7 < (byte)(*(char *)((int)param_2 + 0x13) - 0x14U)) {
      uVar8 = 1;
    }
    do {
      uVar6 = (*(code *)&rtl_evm_db_to_percentage)((int)*(char *)(iVar25 + iVar20 + 0xd));
      if (bVar2) {
        if (iVar20 == 0) {
          *(undefined1 *)(param_2 + 0x16) = uVar6;
        }
        *(undefined1 *)((int)param_2 + iVar20 + 0x50) = uVar6;
      }
      uVar9 = iVar20 + 1;
      iVar20 = 1;
    } while (uVar9 < uVar8);
    if (bVar2) {
      *(uint *)(*(int *)(param_1 + 0x40) + 0xa08c) = (uint)*(byte *)(iVar25 + 9);
      *(uint *)(*(int *)(param_1 + 0x40) + 0xa090) = (uint)*(byte *)(iVar25 + 10);
      iVar20 = *(int *)(*(int *)(param_1 + 0x40) + 0xa0a0);
      if (iVar20 == -1) {
        iVar20 = 0;
      }
      else {
        iVar20 = iVar20 + 1;
      }
      *(int *)(*(int *)(param_1 + 0x40) + 0xa0a0) = iVar20;
    }
    if (cVar16 != '\0') {
      uVar8 = (*(code *)&__udivsi3)(iStack_64,cVar16);
      goto LAB_ram_00019716;
    }
  }
  else {
    bVar5 = *(byte *)(iVar25 + 5);
    uVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xb4))
                      (param_1,0x824,0x200);
    uVar9 = uVar9 & 0xff;
    bVar17 = bVar5 & 0x1f;
    switch(bVar5 >> 5) {
    case 1:
      bVar17 = 4 - bVar17;
      break;
    case 2:
      if (uVar9 == 0) {
        bVar17 = 2 - bVar17;
      }
      else {
        bVar17 = ~bVar17;
      }
      break;
    case 3:
      bVar17 = 0xfb - bVar17;
      break;
    case 4:
      bVar17 = 0xf5 - bVar17;
      break;
    case 5:
      bVar17 = 0xf2 - bVar17;
      break;
    case 6:
      bVar17 = 0xea - bVar17;
      break;
    case 7:
      if (bVar17 < 0x1c) {
        bVar17 = 0xe9 - bVar17;
        break;
      }
      cVar16 = -100;
      goto LAB_ram_00019650;
    default:
      bVar17 = 7 - bVar17;
    }
    cVar16 = bVar17 << 1;
LAB_ram_00019650:
    uVar8 = (*(code *)&rtl_query_rxpwrpercentage)((int)(char)(cVar16 + '\x10'));
    if (uVar9 == 0) {
      if (uVar8 < 0x50) {
        if ((uVar8 - 0x14 & 0xff) < 0x3b) {
          uVar8 = uVar8 + 3 & 0xff;
          goto LAB_ram_000196c8;
        }
      }
      else {
        uVar8 = (((int)uVar8 >> 1) + uVar8 * 2) - 0x78 & 0xff;
      }
      if (100 < uVar8) {
        uVar8 = 100;
      }
      uVar8 = uVar8 & 0xff;
    }
LAB_ram_000196c8:
    *(uint *)(param_2 + 0x24) = uVar8;
    *(uint *)(param_2 + 0x44) = uVar8;
    *(int *)(param_2 + 0x18) = (int)(char)(cVar16 + '\x10');
    if (bVar2) {
      if (uVar8 < 0x29) {
        uVar9 = (uint)*(byte *)(iVar25 + 4);
        if (uVar9 < 0x41) {
          if (uVar9 < 0x14) goto LAB_ram_0001982e;
          uVar6 = (*(code *)&__divsi3)(uVar9 * -100 + 0x1900,0x2c);
        }
        else {
          uVar6 = 0;
        }
      }
      else {
LAB_ram_0001982e:
        uVar6 = 100;
      }
      *(undefined1 *)(param_2 + 0x16) = uVar6;
      *(undefined1 *)(param_2 + 0x28) = uVar6;
      *(undefined1 *)((int)param_2 + 0x51) = 0xff;
    }
LAB_ram_00019716:
    uVar6 = (*(code *)&rtl_signal_scale_mapping)(param_1,uVar8);
    *(undefined1 *)((int)param_2 + 0x35) = uVar6;
  }
  (*(code *)&rtl_process_phyinfo)(param_1,puVar27,param_2);
LAB_ram_00019732:
  *(char *)((int)param_3 + 0x26) = (char)param_2[0x18] + '\n';
  if ((0x17 < param_2[0x15]) &&
     (iVar20 = rtl92ee_hgw500_trace_mgmt_frame(param_1,uVar24,hgw500_mgmt_rx_trace_count),
     iVar20 != 0)) {
    uVar12 = rtl92ee_mgmt_subtype_name(uVar24);
    if (param_2[0x15] < 0x1d || puVar23 + 5 == (ushort *)0x0) {
      uVar18 = 0;
      uVar7 = 0;
      uVar21 = 0;
    }
    else {
      uVar7 = puVar23[0xc];
      uVar18 = puVar23[0xd];
      uVar21 = puVar23[0xe];
    }
    (*(code *)&printk)(&DAT_ram_0001d834,uVar12,uVar24,param_2[0x15],
                       *(undefined1 *)((int)param_2 + 0x41),(char)param_2[0x21],
                       *(undefined1 *)((int)param_2 + 0x13),*(undefined1 *)((int)param_3 + 0x21),
                       (char)param_2[0x3c],*(undefined1 *)((int)param_2 + 0x77),
                       (byte)param_2[0x1b] >> 1 & 1,(byte)param_2[0x1b] >> 2 & 1,
                       (int)*(char *)((int)param_3 + 0x26),puVar23 + 2,puVar23 + 5,puVar23 + 8,uVar7
                       ,uVar18,uVar21);
  }
  if ((char)param_2[0x41] == '\x02') {
    *(uint *)(param_2 + 0x46) = param_4[4];
    *(uint *)(param_2 + 0x48) = param_4[5];
  }
  return 1;
}

