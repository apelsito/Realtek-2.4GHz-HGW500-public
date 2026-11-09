/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10014; aliases: is_power_of_2
 */

bool is_power_of_2(uint param_1)

{
  if (param_1 != 0) {
    return (param_1 - 1 & param_1) == 0;
  }
  return false;
}

