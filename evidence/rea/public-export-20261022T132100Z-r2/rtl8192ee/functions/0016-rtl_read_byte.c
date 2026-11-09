/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x114cc; aliases: rtl_read_byte
 */

void rtl_read_byte(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000114d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x750))();
  return;
}

