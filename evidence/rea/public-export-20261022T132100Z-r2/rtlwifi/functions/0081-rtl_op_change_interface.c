/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13aa8; aliases: rtl_op_change_interface
 */

void rtl_op_change_interface
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined1 param_4)

{
  rtl_op_remove_interface();
  *param_2 = param_3;
  *(undefined1 *)((int)param_2 + 0x28e) = param_4;
  rtl_op_add_interface(param_1,param_2);
  return;
}

