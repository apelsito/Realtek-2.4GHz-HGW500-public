/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13018; aliases: rtl_op_reset_tsf
 */

void rtl_op_reset_tsf(int param_1)

{
  undefined1 local_5 [5];
  
  local_5[0] = 0;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0x50))
            (param_1,0x57,local_5);
  return;
}

