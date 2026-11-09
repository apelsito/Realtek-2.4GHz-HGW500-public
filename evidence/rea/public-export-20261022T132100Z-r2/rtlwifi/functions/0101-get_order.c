/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14d60; aliases: get_order
 */

void get_order(int param_1)

{
  fls(param_1 - 1U >> 0xd);
  return;
}

