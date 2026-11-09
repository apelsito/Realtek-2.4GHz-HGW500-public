/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x135ec; aliases: rtl_op_sta_remove
 */

undefined4 rtl_op_sta_remove(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  
  if (param_3 != 0) {
    *(undefined1 *)(param_3 + 0x1f1) = 0;
    *(undefined1 *)(param_3 + 0x1f2) = 0;
    *(undefined1 *)(param_3 + 499) = 0;
    *(int *)(((uint)auStack_4 & 0xffffe000) + 4) =
         *(int *)(((uint)auStack_4 & 0xffffe000) + 4) + 0x200;
    piVar1 = *(int **)(param_3 + 0x10c);
    iVar2 = *(int *)(param_3 + 0x108);
    *(int **)(iVar2 + 4) = piVar1;
    *piVar1 = iVar2;
    *(undefined4 *)(param_3 + 0x108) = 0x100;
    *(undefined4 *)(param_3 + 0x10c) = 0x122;
    (*(code *)&__local_bh_enable_ip)(0x135ee,0x200);
    return 0;
  }
  return 0;
}

