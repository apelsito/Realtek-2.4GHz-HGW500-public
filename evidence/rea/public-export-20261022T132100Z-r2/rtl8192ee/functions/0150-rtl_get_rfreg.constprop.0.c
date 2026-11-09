/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b618; aliases: rtl_get_rfreg.constprop.0
 */

void rtl_get_rfreg_constprop_0(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001b630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xbc))();
  return;
}

