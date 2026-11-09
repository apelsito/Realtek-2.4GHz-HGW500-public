/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17e70; aliases: init_module, rtl_core_module_init
 */

undefined4 init_module(void)

{
  int iVar1;
  
  iVar1 = rtl_rate_control_register();
  if (iVar1 != 0) {
    (*(code *)&printk)(&DAT_ram_00019ab4);
  }
  return 0;
}

