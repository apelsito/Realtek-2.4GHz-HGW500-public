/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10248; aliases: rtl92ee_dm_init_rate_adaptive_mask
 */

void rtl92ee_dm_init_rate_adaptive_mask(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar1 + 0xb379) = 0;
  *(bool *)(iVar1 + 0xa011) = *(char *)(iVar1 + 0xa032) == '\x01';
  *(undefined2 *)(iVar1 + 0xb3c4) = 0x2300;
  *(undefined1 *)(iVar1 + 0xb3c6) = 0;
  *(undefined4 *)(iVar1 + 0xb37c) = 0x32;
  *(undefined4 *)(iVar1 + 0xb388) = 0x14;
  return;
}

