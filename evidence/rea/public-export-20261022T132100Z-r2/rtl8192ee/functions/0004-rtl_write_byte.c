/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10078; aliases: rtl_write_byte
 */

void rtl_write_byte(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x740))();
  if (*(char *)(*(int *)(param_1 + 0xb8fc) + 1) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x000100b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x750))(param_1,param_2);
    return;
  }
  return;
}

