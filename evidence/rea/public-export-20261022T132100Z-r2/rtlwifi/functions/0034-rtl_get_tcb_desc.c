/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11744; aliases: rtl_get_tcb_desc
 */

void rtl_get_tcb_desc(int param_1,int param_2,int param_3,int param_4,ushort *param_5)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  bool bVar11;
  
  iVar10 = *(int *)(param_1 + 0x40);
  puVar9 = *(ushort **)(param_4 + 0xbc);
  uVar2 = *puVar9;
  if ((*(byte *)(param_2 + 10) & 1) == 0) {
    uVar5 = (uint)*(char *)(param_2 + 8);
    if ((*(byte *)(param_2 + 10) & 0x20) != 0) {
      if ((int)uVar5 >> 4 == 1) {
        iVar6 = *(int *)(*(int *)(iVar10 + 0xb8fc) + 0x184);
      }
      else {
        iVar6 = *(int *)(*(int *)(iVar10 + 0xb8fc) + 0x178);
      }
      uVar5 = ((uVar5 & 0xf) + iVar6) - 9;
      goto LAB_ram_000117b6;
    }
    if ((int)uVar5 < 0) {
      if (__warned_4 == '\0') {
        __warned_4 = '\x01';
        (*(code *)&warn_slowpath_fmt)("include/net/mac80211.h",0xa90,9,0);
      }
LAB_ram_0001193a:
      uVar5 = 0;
    }
    else {
      iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x38) + (*(byte *)(param_2 + 4) & 7) * 4 + 0xcc)
                      + 4) + uVar5 * 0xc;
      if (iVar6 == 0) goto LAB_ram_0001193a;
      uVar5 = (uint)*(byte *)(iVar6 + 6);
    }
  }
  else {
    uVar5 = *(int *)(*(int *)(iVar10 + 0xb8fc) + 0x16c) + (*(byte *)(param_2 + 8) - 0xf);
LAB_ram_000117b6:
    uVar5 = uVar5 & 0xff;
  }
  if ((*(int *)(iVar10 + 0x6d0) == 1) &&
     (uVar7 = *(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x148), uVar5 < uVar7)) {
    uVar5 = uVar7;
  }
  *(byte *)(param_5 + 3) = (byte)uVar5;
  iVar6 = rtl_is_tx_report_skb(param_1,param_4);
  if (iVar6 != 0) {
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 0x10;
  }
  if ((uVar2 & 0xc) != 8) {
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 4;
    if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) == 0) {
      bVar3 = 7;
    }
    else {
      bVar3 = rtl_mrate_idx_to_arfr_id(param_1,7);
    }
    *(byte *)(param_5 + 2) = bVar3;
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 8;
    *(byte *)((int)param_5 + 5) = 0;
    *(byte *)param_5 = (byte)*param_5 & 0xfc;
    return;
  }
  if ((*(char *)(param_2 + 8) == '\0') || ((uVar2 & 0xfc) == 0x48)) {
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 4;
    if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) == 0) {
      bVar3 = 7;
    }
    else {
      bVar3 = rtl_mrate_idx_to_arfr_id(param_1,7);
    }
    *(byte *)(param_5 + 2) = bVar3;
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 8;
  }
  else {
    if (param_3 == 0) {
LAB_ram_00011a04:
      if (*(short *)(iVar10 + 0x588) == 2) {
        bVar3 = (byte)*(undefined4 *)(*(int *)(iVar10 + 0xb8fc) + 0x144);
      }
      else {
        bVar3 = (byte)*(undefined4 *)(*(int *)(iVar10 + 0xb8fc) + 0x164);
      }
    }
    else if (*(char *)(param_3 + 0x34) == '\0') {
      if (*(char *)(param_3 + 0x1e) == '\0') goto LAB_ram_00011a04;
      iVar10 = *(int *)(*(int *)(param_1 + 0x40) + 0xb8fc);
      if ((*(char *)(*(int *)(param_1 + 0x40) + 0x889) == '\x02') &&
         (*(char *)(param_3 + 0x22) != '\0')) {
        bVar3 = (byte)*(undefined4 *)(iVar10 + 0x16c);
      }
      else {
        bVar3 = (byte)*(undefined4 *)(iVar10 + 0x168);
      }
    }
    else {
      uVar2 = *(ushort *)(param_3 + 0x40);
      iVar10 = *(int *)(*(int *)(param_1 + 0x40) + 0xb8fc);
      if (*(char *)(*(int *)(param_1 + 0x40) + 0x889) == '\x02') {
        if ((uVar2 & 0xc) != 0xc) {
          if ((uVar2 & 0xc) == 0) {
            bVar3 = (byte)*(undefined4 *)(iVar10 + 0x17c);
          }
          else if ((uVar2 & 0xc) == 4) {
            bVar3 = (byte)*(undefined4 *)(iVar10 + 0x180);
          }
          else {
            bVar3 = (byte)*(undefined4 *)(iVar10 + 0x184);
          }
          goto LAB_ram_000119a4;
        }
      }
      if ((uVar2 & 3) == 0) {
        bVar3 = (byte)*(undefined4 *)(iVar10 + 0x170);
      }
      else if ((uVar2 & 3) == 1) {
        bVar3 = (byte)*(undefined4 *)(iVar10 + 0x174);
      }
      else {
        bVar3 = (byte)*(undefined4 *)(iVar10 + 0x178);
      }
    }
LAB_ram_000119a4:
    *(byte *)(param_5 + 3) = bVar3;
  }
  if ((puVar9[2] & 1) != 0) {
    *(byte *)param_5 = (byte)*param_5 | 4;
  }
  iVar10 = *(int *)(param_1 + 0x40);
  iVar6 = *(int *)(iVar10 + 0xb8fc);
  if ((*(uint *)(iVar6 + 0x18) & 1) == 0) {
    bVar3 = 7;
  }
  else {
    bVar3 = rtl_mrate_idx_to_arfr_id(param_1,7,4);
  }
  if (param_3 != 0) {
    bVar3 = *(byte *)(param_3 + 499);
  }
  if ((*(byte *)((int)param_5 + 3) & 0xc) == 0xc) goto switchD_ram_000118da_caseD_4;
  switch(*(undefined4 *)(iVar10 + 0x3f4)) {
  case 1:
  case 7:
    if ((*param_5 & 0xc) == 0) goto switchD_ram_000118da_caseD_3;
    *(byte *)(param_5 + 3) = (byte)*(undefined4 *)(iVar6 + 0x13c);
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 4;
    if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) == 0) {
      bVar4 = 7;
    }
    else {
      bVar4 = rtl_mrate_idx_to_arfr_id(param_1,7);
    }
    goto LAB_ram_00011a2a;
  case 2:
    bVar4 = 0;
LAB_ram_00011a2a:
    *(byte *)(param_5 + 2) = bVar4;
    break;
  case 3:
switchD_ram_000118da_caseD_3:
    *(byte *)(param_5 + 2) = bVar3;
  }
switchD_ram_000118da_caseD_4:
  if (*(char *)(iVar10 + 0xa011) != '\0') {
    *(byte *)(param_5 + 2) = bVar3;
    switch(*(undefined4 *)(iVar10 + 0x3f4)) {
    case 1:
    case 3:
      if (param_3 == 0) {
        *(byte *)((int)param_5 + 5) = 0;
      }
      else {
        if (*(short *)(param_3 + 0x1a) == 0) {
          bVar3 = 1;
        }
        else {
          bVar3 = (char)*(short *)(param_3 + 0x1a) + 1;
        }
        *(byte *)((int)param_5 + 5) = bVar3;
      }
      break;
    case 2:
    case 7:
      *(byte *)((int)param_5 + 5) = 0;
      if ((param_3 == 0) || ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) == 0)) {
        uVar2 = *(ushort *)(iVar10 + 0x588);
        if (uVar2 == 0x40) {
          if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) == 0) {
            bVar3 = 8;
          }
          else {
            uVar8 = 8;
LAB_ram_00011b02:
            bVar3 = rtl_mrate_idx_to_arfr_id(param_1,uVar8);
          }
        }
        else if (uVar2 == 0x80) {
          if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
            uVar8 = 9;
            goto LAB_ram_00011b02;
          }
          bVar3 = 9;
        }
        else if (uVar2 == 0x10) {
          if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
            uVar8 = 0;
            goto LAB_ram_00011b02;
          }
          bVar3 = 0;
        }
        else if (uVar2 == 0x20) {
          if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
            uVar8 = 1;
            goto LAB_ram_00011b02;
          }
          bVar3 = 1;
        }
        else if ((uVar2 & 4) == 0) {
          if ((uVar2 & 2) == 0) {
            if ((uVar2 & 1) == 0) break;
            if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
              uVar8 = 5;
              goto LAB_ram_00011b02;
            }
            bVar3 = 5;
          }
          else {
            if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
              uVar8 = 6;
              goto LAB_ram_00011b02;
            }
            bVar3 = 6;
          }
        }
        else {
          if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 1) != 0) {
            uVar8 = 4;
            goto LAB_ram_00011b02;
          }
          bVar3 = 4;
        }
        *(byte *)(param_5 + 2) = bVar3;
      }
    }
  }
  iVar10 = *(int *)(param_1 + 0x40);
  *(byte *)param_5 = (byte)*param_5 & 0xfc;
  uVar5 = (uint)(byte)param_5[3];
  if (param_3 == 0) goto code_r0x00011d06;
  switch(*(undefined4 *)(iVar10 + 0x3f4)) {
  case 1:
  case 3:
  case 7:
    if (*(char *)(param_3 + 0x1e) != '\0') {
      bVar11 = (*(ushort *)(param_3 + 0x1c) & 2) == 0;
LAB_ram_00011c74:
      if (!bVar11) goto switchD_ram_00011b44_caseD_4;
    }
    break;
  case 2:
    if (*(char *)(iVar10 + 0x587) != '\0') {
      bVar11 = *(char *)(param_3 + 0x1e) == '\0';
      goto LAB_ram_00011c74;
    }
    break;
  default:
switchD_ram_00011b44_caseD_4:
    if ((((byte)*param_5 & 0xc) != 0) || (uVar5 <= *(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x164)))
    break;
    *(byte *)param_5 = (byte)*param_5 & 0xfc | 1;
    if ((*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x18) & 2) == 0) break;
    switch(*(undefined4 *)(iVar10 + 0x3f4)) {
    case 1:
    case 3:
    case 7:
      break;
    case 2:
      if (*(char *)(iVar10 + 0x55f) == '\0') goto code_r0x00011d06;
      break;
    default:
      goto switchD_ram_00011cc2_caseD_4;
    }
    if (*(char *)(param_3 + 0x34) != '\0') {
switchD_ram_00011cc2_caseD_4:
      if (*(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x16c) < uVar5) {
        *(byte *)param_5 = (byte)*param_5 & 0xfc | 2;
      }
    }
  }
code_r0x00011d06:
  iVar10 = *(int *)(param_1 + 0x40);
  uVar7 = *(uint *)(param_2 + 8);
  bVar3 = *(byte *)((int)param_5 + 3) & 0xfd;
  *(byte *)((int)param_5 + 3) = bVar3;
  if ((uVar5 != *(uint *)(*(int *)(iVar10 + 0xb8fc) + 0x138)) && ((uVar7 >> 0xd & 4) != 0)) {
    *(byte *)((int)param_5 + 3) = bVar3 | 2;
  }
  uVar5 = *(uint *)(param_2 + 8);
  iVar10 = *(int *)(param_1 + 0x40);
  *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) & 0xfe;
  if ((param_3 == 0) ||
     (((*(char *)(param_3 + 0x1e) == '\0' && (*(char *)(param_3 + 0x34) == '\0')) ||
      (bVar3 = *(byte *)(param_3 + 0x1c), (bVar3 & 0x60) == 0)))) goto code_r0x00011db8;
  switch(*(undefined4 *)(iVar10 + 0x3f4)) {
  case 1:
  case 3:
  case 7:
    cVar1 = *(char *)(param_3 + 0x34);
    bVar4 = bVar3 & 2;
    break;
  case 2:
    bVar4 = *(byte *)(iVar10 + 0x587);
    cVar1 = *(char *)(iVar10 + 0x55f);
    break;
  default:
    goto switchD_ram_00011d7c_caseD_4;
  }
  if (cVar1 == '\0') {
    if (bVar4 == 0) {
switchD_ram_00011d7c_caseD_4:
      bVar11 = (bVar3 & 0x20) == 0;
    }
    else {
      bVar11 = (bVar3 & 0x40) == 0;
    }
  }
  else {
    bVar11 = (*(byte *)(param_3 + 0x38) & 0x20) == 0;
  }
  if (!bVar11) {
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) | 1;
  }
  if ((uVar5 >> 0xd & 0x80) == 0) {
    *(byte *)((int)param_5 + 3) = *(byte *)((int)param_5 + 3) & 0xfe;
  }
code_r0x00011db8:
  iVar10 = *(int *)(param_1 + 0x40);
  uVar5 = *(uint *)(param_2 + 8) >> 0xd;
  *param_5 = *param_5 & 0xf82f;
  if ((uVar5 & 2) == 0) {
    if ((uVar5 & 1) == 0) {
      return;
    }
    bVar3 = (byte)*param_5 | 0x20;
  }
  else {
    bVar3 = (byte)*param_5 & 0x9f | 0x60;
  }
  *(byte *)param_5 = bVar3;
  *(byte *)(param_5 + 1) = (byte)*(undefined4 *)(*(int *)(iVar10 + 0xb8fc) + 0x158);
  return;
}

