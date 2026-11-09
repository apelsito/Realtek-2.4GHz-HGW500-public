/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16d10; aliases: rtl_lps_enter_core
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_lps_enter_core(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar1 + 0xb2f6) == '\0') {
    return;
  }
  if (*(char *)(iVar1 + 0xa3cd) != '\0') {
    return;
  }
  if (*(char *)(iVar1 + 0xb7c8) != '\0') {
    return;
  }
  if (*(byte *)(iVar1 + 0x4eb) < 5) {
    return;
  }
  if (*(int *)(iVar1 + 0x3f4) == 1) {
    return;
  }
  if (*(int *)(iVar1 + 0x4d0) != 2) {
    return;
  }
  (*(code *)&mutex_lock)(iVar1 + 0x3c);
  rtl_lps_set_psmode(param_1,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

