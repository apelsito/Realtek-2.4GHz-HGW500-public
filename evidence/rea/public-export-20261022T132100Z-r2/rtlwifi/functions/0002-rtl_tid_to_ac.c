/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10014; aliases: rtl_tid_to_ac
 */

undefined1 rtl_tid_to_ac(uint param_1)

{
  return *(undefined1 *)((int)&tid_to_ac + (param_1 & 0xff));
}

