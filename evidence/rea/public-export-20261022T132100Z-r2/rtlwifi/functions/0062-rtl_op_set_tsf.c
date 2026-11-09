/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12fd0; aliases: rtl_op_set_tsf
 */

void rtl_op_set_tsf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar1 + 0x590) = param_3;
  *(undefined4 *)(iVar1 + 0x594) = param_4;
  local_9 = *(int *)(iVar1 + 0x3f4) == 1;
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x50))(param_1,0x54,&local_9);
  return;
}

