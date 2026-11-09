/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16dd8; aliases: rtl_lps_leave_core
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_lps_leave_core(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  (*(code *)&mutex_lock)(iVar1 + 0x3c);
  if ((*(char *)(iVar1 + 0xb2f6) != '\0') && (*(int *)(iVar1 + 0xb2f0) != 0)) {
    if ((*(int *)(iVar1 + 0xb308) < 0) &&
       (((*(uint *)(iVar1 + 0xb304) & 0x80) != 0 && (*(int *)(iVar1 + 0x68c) == 0)))) {
      (**(code **)(*(int *)(iVar1 + 0xb900) + 0x1c))(param_1);
      *(uint *)(iVar1 + 0xb304) = *(uint *)(iVar1 + 0xb304) & 0xffffff7f;
    }
    rtl_lps_set_psmode(param_1,0);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

