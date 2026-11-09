/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16e70; aliases: rtl_lps_change_work_callback
 */

void rtl_lps_change_work_callback(int param_1)

{
  if (*(char *)(*(int *)(*(int *)(param_1 + -0x1a8) + 0x40) + 0xb995) != '\0') {
    rtl_lps_enter_core();
    return;
  }
  rtl_lps_leave_core();
  return;
}

