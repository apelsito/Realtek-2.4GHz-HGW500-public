/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14b64; aliases: rtl92ee_sw_led_off
 */

void rtl92ee_sw_led_off(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 4) == 1) {
    iVar2 = *(int *)(param_1 + 0x40);
    uVar1 = (**(code **)(iVar2 + 0x758))(iVar2,0x44);
    rtl_write_dword_constprop_0(iVar2,uVar1 & 0xdfffffff | 0xdfdfffff);
  }
  *(undefined1 *)(param_2 + 8) = 0;
  return;
}

