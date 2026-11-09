/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13f20; aliases: rtl92ee_disable_interrupt
 */

void rtl92ee_disable_interrupt(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  rtl_write_dword(iVar1,0xb0,0);
  rtl_write_dword(iVar1,0xb8,0);
  *(undefined1 *)(iVar1 + 0xba98) = 0;
  return;
}

