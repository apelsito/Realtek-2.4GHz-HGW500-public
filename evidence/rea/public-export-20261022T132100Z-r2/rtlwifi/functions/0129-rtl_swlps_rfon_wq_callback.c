/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1688c; aliases: rtl_swlps_rfon_wq_callback
 */

void rtl_swlps_rfon_wq_callback(int param_1)

{
  rtl_swlps_rf_awake(*(undefined4 *)(param_1 + -0x150));
  return;
}

