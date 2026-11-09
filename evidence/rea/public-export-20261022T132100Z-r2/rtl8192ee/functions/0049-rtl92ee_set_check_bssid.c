/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13d40; aliases: rtl92ee_set_check_bssid
 */

void rtl92ee_set_check_bssid(int param_1,char param_2)

{
  int iVar1;
  uint local_14;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar1 + 0xb314) != 0) {
    return;
  }
  if (param_2 == '\0') {
    local_14 = *(uint *)(iVar1 + 0xcc88) & 0xffffff3f;
    _rtl92ee_set_bcn_ctrl_reg_isra_0(iVar1,0x10,0);
    (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x50))(param_1,0x2c,&local_14);
  }
  else {
    local_14 = *(uint *)(iVar1 + 0xcc88) | 0xc0;
    (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x50))(param_1,0x2c,&local_14);
    _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),0,0x10);
  }
  return;
}

