/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1365c; aliases: rtl_op_sta_add
 */

undefined4 rtl_op_sta_add(int param_1,int *param_2,uint *param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_3 == (uint *)0x0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x40);
  *(int *)(((uint)&stack0xffffffe8 & 0xffffe000) + 4) =
       *(int *)(((uint)&stack0xffffffe8 & 0xffffe000) + 4) + 0x200;
  puVar2 = *(undefined4 **)(iVar3 + 0xb8d0);
  *(uint **)(iVar3 + 0xb8d0) = param_3 + 0x42;
  param_3[0x42] = iVar3 + 0xb8cc;
  param_3[0x43] = (uint)puVar2;
  *puVar2 = param_3 + 0x42;
  (*(code *)&__local_bh_enable_ip)(0x13672,0x200);
  if (*(int *)(iVar3 + 0x6d0) == 0) {
    if (*param_3 < 0x10) {
      uVar1 = 2;
    }
    else {
      uVar1 = 4;
    }
    if (*(char *)((int)param_3 + 0x1e) != '\0') {
      uVar1 = 0x10;
    }
    *(undefined1 *)((int)param_3 + 0x1f1) = uVar1;
    *(undefined1 *)((int)param_3 + 0x1f2) = 0;
    if (*param_2 != 1) goto LAB_ram_000136fe;
    uVar1 = 4;
  }
  else {
    if (*(int *)(iVar3 + 0x6d0) != 1) goto LAB_ram_000136fe;
    if (*(char *)((int)param_3 + 0x1e) == '\0') {
      uVar1 = 1;
    }
    else {
      uVar1 = 0x20;
    }
    if ((char)param_3[0xd] != '\0') {
      uVar1 = 0x40;
    }
    *(undefined1 *)((int)param_3 + 0x1f1) = uVar1;
    *(undefined1 *)((int)param_3 + 0x1f2) = 0;
    uVar1 = 1;
    if (*param_2 != 1) goto LAB_ram_000136fe;
  }
  *(undefined1 *)((int)param_3 + 0x1f1) = uVar1;
  *(undefined1 *)((int)param_3 + 0x1f2) = 0;
LAB_ram_000136fe:
  if (*(char *)(iVar3 + 0x4dd) != '\0') {
    *param_3 = *param_3 & 0xfffffff0;
  }
  (*(code *)&memcpy)((int)param_3 + 0x1f5,param_3 + 5,6);
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x54))(param_1,param_3,0,1);
  return 0;
}

