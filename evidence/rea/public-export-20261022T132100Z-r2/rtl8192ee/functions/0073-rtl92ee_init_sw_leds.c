/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14bb0; aliases: rtl92ee_init_sw_leds
 */

void rtl92ee_init_sw_leds(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(int *)(iVar1 + 0xb2a8) = param_1;
  *(undefined4 *)(iVar1 + 0xb2ac) = 1;
  *(undefined1 *)(iVar1 + 0xb2b0) = 0;
  *(int *)(iVar1 + 0xb2b4) = param_1;
  *(undefined4 *)(iVar1 + 0xb2b8) = 2;
  *(undefined1 *)(iVar1 + 0xb2bc) = 0;
  return;
}

