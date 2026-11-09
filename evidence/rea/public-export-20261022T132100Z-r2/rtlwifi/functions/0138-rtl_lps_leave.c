/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16e94; aliases: rtl_lps_leave
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_lps_leave(int param_1,char param_2)

{
  if (param_2 != '\0') {
    rtl_lps_leave_core();
    return;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xb995) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

