/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x167f4; aliases: rtl_swlps_rf_awake
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_swlps_rf_awake(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if ((*(char *)(iVar1 + 0xb2f4) != '\0') && (*(int *)(iVar1 + 0x4d0) == 2)) {
    if ((*(int *)(iVar1 + 0xb308) < 0) && ((*(uint *)(iVar1 + 0xb304) & 0x80) != 0)) {
      (**(code **)(*(int *)(iVar1 + 0xb900) + 0x1c))();
      *(uint *)(iVar1 + 0xb304) = *(uint *)(iVar1 + 0xb304) & 0xffffff7f;
    }
    (*(code *)&mutex_lock)(iVar1 + 0x3c);
    rtl_ps_set_rf_state_isra_0(param_1,0,0x20000000);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

