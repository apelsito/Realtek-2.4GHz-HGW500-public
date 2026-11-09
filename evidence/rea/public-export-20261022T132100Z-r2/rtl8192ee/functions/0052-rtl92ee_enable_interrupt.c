/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13ed4; aliases: rtl92ee_enable_interrupt
 */

void rtl92ee_enable_interrupt(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  rtl_write_dword(iVar1,0xb0,*(undefined4 *)(iVar1 + 0xcc90));
  rtl_write_dword(iVar1,0xb8,*(undefined4 *)(iVar1 + 0xcc94));
  *(undefined1 *)(iVar1 + 0xba98) = 1;
  return;
}

