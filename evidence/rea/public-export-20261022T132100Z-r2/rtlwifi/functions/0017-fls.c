/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10708; aliases: fls
 */

int fls(int param_1)

{
  int iVar1;
  
  iVar1 = norm(param_1);
  if (param_1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + 1;
  }
  return 0x20 - iVar1;
}

