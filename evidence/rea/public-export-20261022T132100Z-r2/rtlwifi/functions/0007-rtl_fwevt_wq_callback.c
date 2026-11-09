/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x101e8; aliases: rtl_fwevt_wq_callback
 */

void rtl_fwevt_wq_callback(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000101fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x17c) + 0x40) + 0xb8fc) + 0xc) + 0xf0
              ))();
  return;
}

