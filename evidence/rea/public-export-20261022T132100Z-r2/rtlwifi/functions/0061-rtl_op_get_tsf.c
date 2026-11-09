/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12f9c; aliases: rtl_op_get_tsf
 */

undefined8 rtl_op_get_tsf(int param_1)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  local_c = 0;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0x4c))
            (param_1,0x54,&local_c);
  return CONCAT44(uStack_8,local_c);
}

