/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10fe8; aliases: rtl_deinit_deferred_work
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_deinit_deferred_work(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  (*(code *)&timer_delete_sync)(iVar1 + 0x4c);
  (*(code *)&cancel_delayed_work_sync)(iVar1 + 0xe8);
  if (param_2 == '\0') {
    (*(code *)&cancel_delayed_work_sync)(iVar1 + 0x114);
  }
  else {
    (*(code *)&cancel_delayed_work)();
  }
  (*(code *)&cancel_delayed_work_sync)(iVar1 + 0x16c);
  (*(code *)&cancel_delayed_work_sync)(iVar1 + 0x198);
  (*(code *)&cancel_delayed_work_sync)(iVar1 + 0x1c4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

