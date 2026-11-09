/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1c650; aliases: cleanup_module, rtl92ee_module_exit
 */

/* WARNING: Control flow encountered bad instruction data */

void cleanup_module(void)

{
  (*(code *)&printk)(&DAT_ram_0001d4a4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

