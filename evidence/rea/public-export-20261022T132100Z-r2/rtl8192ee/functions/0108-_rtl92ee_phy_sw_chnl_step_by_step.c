/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17798; aliases: _rtl92ee_phy_sw_chnl_step_by_step
 */

undefined4
_rtl92ee_phy_sw_chnl_step_by_step(int param_1,int param_2,char *param_3,byte *param_4,int *param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_330 [2];
  uint auStack_328 [62];
  int aiStack_230 [64];
  int aiStack_130 [64];
  
  iVar6 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(local_330,0,0x100);
  (*(code *)&memset)(aiStack_230,0,0x100);
  (*(code *)&memset)(aiStack_130,0,0x100);
  bVar1 = *(byte *)(iVar6 + 0x9f98);
  local_330[1] = 0;
  auStack_328[0] = 0;
  auStack_328[1] = 0;
  auStack_328[2] = 0;
  auStack_328[3] = 0;
  auStack_328[4] = 0;
  auStack_328[5] = 0;
  aiStack_230[0] = 0;
  aiStack_230[1] = 0;
  aiStack_230[2] = 0;
  aiStack_230[3] = 0;
  local_330[0] = 1;
  if ((0xd < param_2 - 1U) && (__warned_2 == '\0')) {
    __warned_2 = '\x01';
    (*(code *)&warn_slowpath_fmt)
              ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c",0x721,9,
               "rtl8192ee: illegal channel for Zebra: %d\n",param_2);
  }
  aiStack_130[0] = 6;
  aiStack_130[1] = 0x18;
  aiStack_130[3] = 10;
  aiStack_130[2] = param_2;
  aiStack_130[4] = 0;
  aiStack_130[5] = 0;
  aiStack_130[6] = 0;
  aiStack_130[7] = 0;
  while( true ) {
    cVar2 = *param_3;
    if (cVar2 == '\x01') {
      piVar5 = aiStack_130 + (uint)*param_4 * 4;
    }
    else if (cVar2 == '\x02') {
      piVar5 = aiStack_230 + (uint)*param_4 * 4;
    }
    else {
      if (cVar2 != '\0') {
        (*(code *)&printk)(&DAT_ram_0001d29c);
        return 1;
      }
      piVar5 = local_330 + (uint)*param_4 * 4;
    }
    if (*piVar5 != 0) break;
    if (cVar2 == '\x02') {
      return 1;
    }
    *param_3 = cVar2 + '\x01';
    *param_4 = 0;
  }
  switch(*piVar5) {
  case 1:
    rtl92ee_phy_set_txpower_level(param_1,param_2);
    break;
  case 3:
    rtl_write_dword(iVar6,piVar5[1],piVar5[2]);
    break;
  case 4:
    rtl_write_word(iVar6,piVar5[1],(short)piVar5[2]);
    break;
  case 5:
    rtl_write_byte(iVar6,piVar5[1],(char)piVar5[2]);
    break;
  case 6:
    for (uVar7 = 0; uVar7 < bVar1; uVar7 = uVar7 + 1 & 0xff) {
      iVar3 = iVar6 + uVar7 * 4;
      iVar4 = piVar5[1];
      *(uint *)(iVar3 + 0x9f78) = *(uint *)(iVar3 + 0x9f78) & 0xfffff00 | piVar5[2];
      rtl_set_rfreg(param_1,uVar7,iVar4,0x3ff);
    }
  }
  *param_5 = piVar5[3];
  *param_4 = *param_4 + 1;
  return 0;
}

