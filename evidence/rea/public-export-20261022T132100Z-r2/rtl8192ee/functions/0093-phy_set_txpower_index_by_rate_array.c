/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x153b8; aliases: phy_set_txpower_index_by_rate_array
 */

void phy_set_txpower_index_by_rate_array
               (int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  sbyte sVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  
  uVar9 = param_4 - 1U & 0xff;
  uVar10 = 0;
  if (uVar9 < 0xe) {
    uVar10 = uVar9;
  }
  uVar9 = 0;
  do {
    uVar6 = (uint)*(byte *)(param_5 + uVar9);
    iVar11 = *(int *)(param_1 + 0x40);
    if (uVar6 < 4) {
      uVar12 = (uint)*(byte *)(iVar11 + 0xa600 + param_2 * 0xe + uVar10 + 0x585);
    }
    else {
      iVar2 = iVar11 + 0xa600 + param_2 * 0x3b;
      uVar12 = (uint)*(byte *)(iVar2 + uVar10 + 0x5bd);
      if (uVar6 - 4 < 8) {
        uVar12 = *(byte *)(iVar2 + 0xa59) + uVar12 & 0xff;
      }
      else if (param_3 == 0) {
        if (uVar6 - 0xc < 0x10) {
          uVar12 = *(byte *)(iVar2 + 0x881) + uVar12;
          if (uVar6 - 0x14 < 8) {
            pbVar3 = (byte *)(iVar2 + 0x882);
LAB_ram_000154e8:
            uVar12 = uVar12 + *pbVar3;
          }
LAB_ram_000154de:
          uVar12 = uVar12 & 0xff;
        }
      }
      else if ((param_3 == 1) && (uVar6 - 0xc < 0x10)) {
        uVar12 = *(byte *)(iVar2 + 0x96d) + uVar12;
        if (uVar6 - 0x14 < 8) {
          pbVar3 = (byte *)(iVar2 + 0x96e);
          goto LAB_ram_000154e8;
        }
        goto LAB_ram_000154de;
      }
    }
    if (*(char *)(iVar11 + 0xb293) == '\x02') {
      uVar6 = 0;
      goto LAB_ram_0001560c;
    }
    switch(uVar6) {
    case 0:
      uVar7 = 2;
      uVar4 = uVar6;
      goto switchD_ram_00015530_caseD_4;
    case 1:
    case 2:
      uVar7 = (uint)(param_2 == 1) << 1;
      if (param_2 == 0) {
        uVar7 = 3;
      }
      break;
    case 3:
      uVar4 = 0;
      uVar7 = uVar6;
      goto switchD_ram_00015530_caseD_3;
    case 4:
    case 5:
    case 6:
    case 7:
      uVar7 = 0;
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      uVar7 = 1;
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      uVar7 = 4;
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      uVar7 = 5;
      break;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
      uVar7 = 6;
      goto LAB_ram_00015518;
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
      uVar7 = 7;
LAB_ram_00015518:
      uVar4 = 1;
      goto LAB_ram_0001551a;
    default:
      if (__warned_5 == '\0') {
        __warned_5 = '\x01';
        (*(code *)&warn_slowpath_fmt)
                  ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c",0x476,9,
                   "rtl8192ee: Rate_Section is Illegal\n");
      }
      if (__warned_4 == '\0') {
        __warned_4 = '\x01';
        (*(code *)&warn_slowpath_fmt)
                  ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c",0x4b5,9,
                   "rtl8192ee: Rate_Section is Illegal\n");
      }
      uVar7 = 0;
      uVar4 = 0;
      goto switchD_ram_00015530_caseD_4;
    }
    uVar4 = 0;
LAB_ram_0001551a:
    switch(uVar6) {
    case 2:
    case 6:
    case 10:
    case 0xe:
    case 0x12:
    case 0x16:
    case 0x1a:
      sVar5 = 0x10;
      break;
    case 3:
    case 7:
    case 0xb:
    case 0xf:
    case 0x13:
    case 0x17:
    case 0x1b:
switchD_ram_00015530_caseD_3:
      sVar5 = 0x18;
      break;
    case 4:
    case 8:
    case 0xc:
    case 0x10:
    case 0x14:
    case 0x18:
switchD_ram_00015530_caseD_4:
      sVar5 = 0;
      break;
    default:
      sVar5 = 8;
    }
    uVar6 = *(uint *)(iVar11 + (uVar4 * 0x54 + param_2 * 0x150 + uVar7) * 4 + 0x1640) >> sVar5;
LAB_ram_0001560c:
    uVar6 = uVar6 + uVar12;
    if (0x3f < (uVar6 & 0xff)) {
      uVar6 = 0x3f;
    }
    bVar1 = *(byte *)(param_5 + uVar9);
    if (param_2 != 0) {
      if (param_2 != 1) goto switchD_ram_00015640_default;
      uVar8 = 0xff;
      switch(bVar1) {
      case 0:
        uVar8 = 0xff00;
        goto LAB_ram_00015796;
      case 1:
        uVar8 = 0xff0000;
        goto LAB_ram_00015796;
      case 2:
        uVar8 = 0xff000000;
LAB_ram_00015796:
        iVar11 = 0x838;
        goto LAB_ram_0001567c;
      case 3:
        goto switchD_ram_0001575a_caseD_3;
      case 4:
        break;
      case 5:
        uVar8 = 0xff00;
        break;
      case 6:
        uVar8 = 0xff0000;
        break;
      case 7:
        uVar8 = 0xff000000;
        break;
      case 8:
        goto switchD_ram_0001575a_caseD_8;
      case 9:
        uVar8 = 0xff00;
        goto switchD_ram_0001575a_caseD_8;
      case 10:
        uVar8 = 0xff0000;
        goto switchD_ram_0001575a_caseD_8;
      case 0xb:
        uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_8:
        iVar11 = 0x834;
        goto LAB_ram_0001567c;
      case 0xc:
        goto switchD_ram_0001575a_caseD_c;
      case 0xd:
        uVar8 = 0xff00;
        goto switchD_ram_0001575a_caseD_c;
      case 0xe:
        uVar8 = 0xff0000;
        goto switchD_ram_0001575a_caseD_c;
      case 0xf:
        uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_c:
        iVar11 = 0x83c;
        goto LAB_ram_0001567c;
      case 0x10:
        goto switchD_ram_0001575a_caseD_10;
      case 0x11:
        uVar8 = 0xff00;
        goto switchD_ram_0001575a_caseD_10;
      case 0x12:
        uVar8 = 0xff0000;
        goto switchD_ram_0001575a_caseD_10;
      case 0x13:
        uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_10:
        iVar11 = 0x848;
        goto LAB_ram_0001567c;
      case 0x14:
        goto switchD_ram_0001575a_caseD_14;
      case 0x15:
        uVar8 = 0xff00;
        goto switchD_ram_0001575a_caseD_14;
      case 0x16:
        uVar8 = 0xff0000;
        goto switchD_ram_0001575a_caseD_14;
      case 0x17:
        uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_14:
        iVar11 = 0x84c;
        goto LAB_ram_0001567c;
      case 0x18:
        goto switchD_ram_0001575a_caseD_18;
      case 0x19:
        uVar8 = 0xff00;
        goto switchD_ram_0001575a_caseD_18;
      case 0x1a:
        uVar8 = 0xff0000;
        goto switchD_ram_0001575a_caseD_18;
      case 0x1b:
        uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_18:
        iVar11 = 0x868;
        goto LAB_ram_0001567c;
      default:
        goto switchD_ram_00015640_default;
      }
      iVar11 = 0x83;
      goto LAB_ram_000156f2;
    }
    uVar8 = 0xff;
    switch(bVar1) {
    case 0:
      uVar8 = 0xff00;
      iVar11 = 0xe08;
      goto LAB_ram_0001567c;
    case 1:
      uVar8 = 0xff00;
      goto switchD_ram_0001575a_caseD_3;
    case 2:
      uVar8 = 0xff0000;
      goto switchD_ram_0001575a_caseD_3;
    case 3:
      uVar8 = 0xff000000;
switchD_ram_0001575a_caseD_3:
      iVar11 = 0x86c;
      goto LAB_ram_0001567c;
    case 4:
      break;
    case 5:
      uVar8 = 0xff00;
      break;
    case 6:
      uVar8 = 0xff0000;
      break;
    case 7:
      uVar8 = 0xff000000;
      break;
    case 8:
      goto switchD_ram_00015640_caseD_8;
    case 9:
      uVar8 = 0xff00;
      goto switchD_ram_00015640_caseD_8;
    case 10:
      uVar8 = 0xff0000;
      goto switchD_ram_00015640_caseD_8;
    case 0xb:
      uVar8 = 0xff000000;
switchD_ram_00015640_caseD_8:
      iVar11 = 0xe04;
      goto LAB_ram_0001567c;
    case 0xc:
      goto switchD_ram_00015640_caseD_c;
    case 0xd:
      uVar8 = 0xff00;
      goto switchD_ram_00015640_caseD_c;
    case 0xe:
      uVar8 = 0xff0000;
      goto switchD_ram_00015640_caseD_c;
    case 0xf:
      uVar8 = 0xff000000;
switchD_ram_00015640_caseD_c:
      iVar11 = 0xe1;
LAB_ram_000156f2:
      iVar11 = iVar11 << 4;
      goto LAB_ram_0001567c;
    case 0x10:
      goto switchD_ram_00015640_caseD_10;
    case 0x11:
      uVar8 = 0xff00;
      goto switchD_ram_00015640_caseD_10;
    case 0x12:
      uVar8 = 0xff0000;
      goto switchD_ram_00015640_caseD_10;
    case 0x13:
      uVar8 = 0xff000000;
switchD_ram_00015640_caseD_10:
      iVar11 = 0xe14;
      goto LAB_ram_0001567c;
    case 0x14:
      goto switchD_ram_00015640_caseD_14;
    case 0x15:
      uVar8 = 0xff00;
      goto switchD_ram_00015640_caseD_14;
    case 0x16:
      uVar8 = 0xff0000;
      goto switchD_ram_00015640_caseD_14;
    case 0x17:
      uVar8 = 0xff000000;
switchD_ram_00015640_caseD_14:
      iVar11 = 0xe18;
      goto LAB_ram_0001567c;
    case 0x18:
      goto switchD_ram_00015640_caseD_18;
    case 0x19:
      uVar8 = 0xff00;
      goto switchD_ram_00015640_caseD_18;
    case 0x1a:
      uVar8 = 0xff0000;
      goto switchD_ram_00015640_caseD_18;
    case 0x1b:
      uVar8 = 0xff000000;
switchD_ram_00015640_caseD_18:
      iVar11 = 0xe1c;
      goto LAB_ram_0001567c;
    default:
      goto switchD_ram_00015640_default;
    }
    iVar11 = 0xe00;
LAB_ram_0001567c:
    rtl_set_bbreg(param_1,iVar11,uVar8,uVar6 & 0xff);
switchD_ram_00015640_default:
    uVar9 = uVar9 + 1 & 0xff;
    if (param_6 <= uVar9) {
      return;
    }
  } while( true );
}

