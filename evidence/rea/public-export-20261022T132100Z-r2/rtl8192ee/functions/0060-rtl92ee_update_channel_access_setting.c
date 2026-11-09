/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14524; aliases: rtl92ee_update_channel_access_setting
 */

void rtl92ee_update_channel_access_setting(int param_1)

{
  int iVar1;
  undefined2 local_12;
  
  iVar1 = *(int *)(param_1 + 0x40);
  local_12 = 0;
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x50))(param_1,0x12,iVar1 + 0x58a);
  if (*(char *)(iVar1 + 0x584) == '\0') {
    local_12 = 0xa0a;
  }
  else {
    local_12 = 0xe0e;
  }
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x50))(param_1,0xe,&local_12);
  return;
}

