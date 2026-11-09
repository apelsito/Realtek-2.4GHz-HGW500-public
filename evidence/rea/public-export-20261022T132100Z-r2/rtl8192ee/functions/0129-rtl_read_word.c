/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18bcc; aliases: rtl_read_word
 */

void rtl_read_word(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00018bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x754))();
  return;
}

