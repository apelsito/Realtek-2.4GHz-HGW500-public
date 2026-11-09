/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14cd0; aliases: rtl_set_rfreg
 */

void rtl_set_rfreg(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00014ce2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xc0))();
  return;
}

