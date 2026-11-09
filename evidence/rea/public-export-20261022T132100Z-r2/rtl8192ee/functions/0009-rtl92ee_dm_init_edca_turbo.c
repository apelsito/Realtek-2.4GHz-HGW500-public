/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10238; aliases: rtl92ee_dm_init_edca_turbo
 */

void rtl92ee_dm_init_edca_turbo(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined2 *)(iVar1 + 0xa00a) = 0;
  *(undefined1 *)(iVar1 + 0xa00c) = 0;
  return;
}

