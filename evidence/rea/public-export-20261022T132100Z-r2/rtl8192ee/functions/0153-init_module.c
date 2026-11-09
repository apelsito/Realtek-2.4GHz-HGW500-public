/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1c600; aliases: init_module, rtl92ee_module_init
 */

/* WARNING: Control flow encountered bad instruction data */

void init_module(void)

{
  (*(code *)&printk)(&DAT_ram_0001d438,rtl92ee_mod_params[0x13],rtl92ee_mod_params[0x14],
                     rtl92ee_mod_params._24_4_,rtl92ee_mod_params[0x10],rtl92ee_mod_params[0x12],
                     rtl92ee_mod_params._12_4_);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

