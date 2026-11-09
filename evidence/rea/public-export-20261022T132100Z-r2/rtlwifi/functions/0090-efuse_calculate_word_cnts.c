/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14978; aliases: efuse_calculate_word_cnts
 */

uint efuse_calculate_word_cnts(uint param_1)

{
  uint uVar1;
  
  uVar1 = ~param_1 & 1;
  if ((param_1 & 2) == 0) {
    uVar1 = uVar1 + 1;
  }
  if ((param_1 & 4) == 0) {
    uVar1 = uVar1 + 1;
  }
  if ((param_1 & 8) == 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

