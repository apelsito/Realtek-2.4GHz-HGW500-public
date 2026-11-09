/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x110a8; aliases: rtl_watch_dog_timer_callback
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_watch_dog_timer_callback(int param_1)

{
  (*(code *)&queue_delayed_work_on)(1,*(undefined4 *)(param_1 + 0x98),param_1 + 0x9c,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

