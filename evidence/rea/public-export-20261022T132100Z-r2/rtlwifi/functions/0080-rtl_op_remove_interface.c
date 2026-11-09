/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x139d8; aliases: rtl_op_remove_interface
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_op_remove_interface(int param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  (*(code *)&mutex_lock)(iVar1 + 0x24);
  if (((*param_2 < 8) && ((0x8aU >> ((byte)*param_2 & 0x1f) & 1) != 0)) &&
     (*(char *)(iVar1 + 0x217) == '\x01')) {
    *(undefined1 *)(iVar1 + 0x217) = 0;
    (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x48))
              (param_1,0,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x130));
  }
  *(undefined1 *)(iVar1 + 0x4dd) = 0;
  *(undefined4 *)(iVar1 + 0x3f0) = 0;
  *(undefined4 *)(iVar1 + 0x4d0) = 0;
  eth_zero_addr(iVar1 + 0x566);
  *(undefined4 *)(iVar1 + 0x56c) = 0;
  *(undefined4 *)(iVar1 + 0x3f4) = 0;
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x2c))(param_1,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

