/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x107c4; aliases: rtl_send_smps_action
 */

undefined4 rtl_send_smps_action(int param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_68;
  undefined2 local_64;
  undefined1 auStack_60 [56];
  
  iVar5 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(auStack_60,0,0x38);
  local_68 = 0;
  local_64 = 0;
  (*(code *)&memset)(auStack_60,0,0x38);
  if ((((*(char *)(iVar5 + 0x4ea) != '\0') || (param_2 == 0)) || (*(char *)(iVar5 + 0x698) == '\0'))
     || ((*(int *)(iVar5 + 0xb314) != 0 || ((*(uint *)(iVar5 + 0xb904) & 1) == 0)))) {
    return 0;
  }
  iVar3 = iVar5 + 0xa9f8;
  if (*(int *)(iVar5 + 0x3f4) != 3) {
    iVar3 = iVar5 + 0x566;
  }
  (*(code *)&memcpy)(&local_68,iVar3,6);
  iVar6 = *(int *)(param_1 + 0x40);
  iVar3 = (*(code *)&__netdev_alloc_skb)(0,*(int *)(param_1 + 0x4c) + 0x1b,0xa20);
  if (iVar3 == 0) {
    return 1;
  }
  iVar4 = *(int *)(param_1 + 0x4c);
  *(int *)(iVar3 + 0xbc) = *(int *)(iVar3 + 0xbc) + iVar4;
  *(int *)(iVar3 + 0xb0) = *(int *)(iVar3 + 0xb0) + iVar4;
  puVar2 = (undefined2 *)(*(code *)&skb_put)(iVar3,0x1b);
  (*(code *)&memset)(puVar2,0,0x1b);
  (*(code *)&memcpy)(puVar2 + 2,param_2 + 0x14,6);
  (*(code *)&memcpy)(puVar2 + 5,iVar6 + 0xa9f8,6);
  (*(code *)&memcpy)(puVar2 + 8,&local_68,6);
  *puVar2 = 0xd0;
  puVar2[0xc] = 0x107;
  switch(param_3) {
  case 0:
  case 4:
    (*(code *)&warn_slowpath_fmt)("drivers/net/wireless/realtek/rtlwifi/base.c",0x98a,9,0);
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 1;
    break;
  case 3:
    uVar1 = 3;
    break;
  default:
    goto switchD_ram_0001093c_default;
  }
  *(undefined1 *)(puVar2 + 0xd) = uVar1;
switchD_ram_0001093c_default:
  *(char *)(param_2 + 500) = (char)param_3;
  *(undefined1 *)(iVar3 + 0x20) = 0;
  *(byte *)(iVar3 + 0x1c) = *(byte *)(iVar3 + 0x1c) & 0xf8 | **(byte **)(param_1 + 0x14) & 7;
  (**(code **)(*(int *)(iVar5 + 0xb900) + 0xc))(param_1,param_2,iVar3,auStack_60);
  return 1;
}

