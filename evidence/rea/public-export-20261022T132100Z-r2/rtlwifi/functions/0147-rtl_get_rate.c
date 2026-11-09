/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17470; aliases: rtl_get_rate
 */

void rtl_get_rate(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  char cVar8;
  ushort uVar9;
  bool bVar10;
  char local_2f [3];
  
  iVar5 = *(int *)(param_4 + 0xc);
  uVar9 = **(ushort **)(iVar5 + 0xbc) & 0xc;
  (*(code *)&memset)(local_2f,0,3);
  uVar1 = *(byte *)(param_1 + 0x889) - 2 & 0xff;
  if (uVar1 < 7) {
    cVar8 = *(char *)((int)&CSWTCH_30 + uVar1);
  }
  else {
    cVar8 = '\x01';
  }
  if (param_2 == 0) {
    sVar6 = 0;
  }
  else {
    sVar6 = *(short *)(param_2 + 0x1f1);
  }
  iVar2 = rtl_is_special_data(*(undefined4 *)(param_1 + 0x3ec),iVar5,1,0);
  if (iVar2 != 0) {
    cVar4 = '\0';
    goto LAB_ram_0001757a;
  }
  cVar4 = '\0';
  if (uVar9 != 8) goto LAB_ram_0001757a;
  if (*(int *)(param_1 + 0x6d0) == 0) {
    if (sVar6 == 2) {
      cVar4 = '\x03';
      goto LAB_ram_0001757a;
    }
    if (sVar6 == 4) {
      cVar4 = '\v';
      goto LAB_ram_0001757a;
    }
    if (sVar6 != 0x10) {
      bVar10 = sVar6 == 0x80;
      goto LAB_ram_00017556;
    }
LAB_ram_00017546:
    if (cVar8 != '\x01') {
      cVar4 = '\x0f';
      goto LAB_ram_0001757a;
    }
  }
  else if (sVar6 != 1) {
    if (sVar6 != 0x20) {
      bVar10 = sVar6 == 0x40;
LAB_ram_00017556:
      if (bVar10) {
        if (*(int *)(param_2 + 0x84) == 0) {
          uVar3 = 8;
        }
        else {
          uVar3 = 9;
        }
        ieee80211_rate_set_vht(local_2f,uVar3,cVar8);
        cVar4 = local_2f[0];
      }
      goto LAB_ram_0001757a;
    }
    goto LAB_ram_00017546;
  }
  cVar4 = '\a';
LAB_ram_0001757a:
  _rtl_rc_rate_set_series_constprop_0(param_1,param_2,iVar5 + 0x20,param_4,1,(int)cVar4,uVar9 != 8);
  if (uVar9 == 8) {
    uVar1 = 1;
    do {
      uVar7 = uVar1 + 1 & 0xff;
      _rtl_rc_rate_set_series_constprop_0
                (param_1,param_2,uVar1 * 3 + iVar5 + 0x20,param_4,uVar1,
                 (int)(char)(cVar4 - (char)uVar1),0);
      uVar1 = uVar7;
    } while (uVar7 != 4);
  }
  return;
}

