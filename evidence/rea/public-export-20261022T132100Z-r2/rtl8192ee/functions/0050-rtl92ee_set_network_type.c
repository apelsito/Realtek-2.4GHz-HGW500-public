/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13dcc; aliases: rtl92ee_set_network_type
 */

undefined4 rtl92ee_set_network_type(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  iVar1 = _rtl92ee_set_media_status();
  if (iVar1 == 0) {
    uVar3 = 0;
    if (*(int *)(iVar4 + 0x4d0) == 2) {
      if ((param_2 & 0xfffffffb) == 3) {
        return 0;
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    rtl92ee_set_check_bssid(param_1,uVar2);
  }
  else {
    uVar3 = 0xffffffa1;
  }
  return uVar3;
}

