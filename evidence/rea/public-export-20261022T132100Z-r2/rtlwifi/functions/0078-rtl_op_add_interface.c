/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13798; aliases: rtl_op_add_interface
 */

undefined4 rtl_op_add_interface(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_1d;
  
  iVar2 = *(int *)(param_1 + 0x40);
  local_1d = 0x30;
  if (*(int *)(iVar2 + 0x3f0) != 0) {
    return 0xffffffa1;
  }
  param_2[0xa8] = param_2[0xa8] | 1;
  rtl_ips_nic_on();
  (*(code *)&mutex_lock)(iVar2 + 0x24);
  iVar1 = *param_2;
  if (*(char *)((int)param_2 + 0x28e) != '\0') {
    if (iVar1 == 2) goto switchD_ram_00013820_caseD_8;
    if (iVar1 == 3) goto switchD_ram_00013820_caseD_9;
  }
  switch(iVar1) {
  default:
    uVar3 = 0xffffffa1;
    (*(code *)&printk)(&DAT_ram_00019d38);
    goto LAB_ram_000139a8;
  case 8:
switchD_ram_00013820_caseD_8:
    *(undefined1 *)(iVar2 + 0x4dd) = 2;
  case 2:
    if (*(char *)(iVar2 + 0x217) == '\x01') {
      *(undefined1 *)(iVar2 + 0x217) = 0;
      (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x48))
                (param_1,0,*(undefined4 *)(*(int *)(iVar2 + 0xb8fc) + 0x130));
    }
    break;
  case 9:
switchD_ram_00013820_caseD_9:
    *(undefined1 *)(iVar2 + 0x4dd) = 3;
  case 1:
  case 3:
  case 7:
    *(undefined4 *)(iVar2 + 0x4d0) = 2;
    (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x40))(param_1);
    if (*(int *)(iVar2 + 0x6d0) == 0) {
      uVar3 = 0xfff;
    }
    else {
      uVar3 = 0xff0;
    }
    *(undefined4 *)(iVar2 + 0x580) = uVar3;
    (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x50))(param_1,2,iVar2 + 0x580);
    local_1d = 7;
  }
  if (*(char *)(iVar2 + 0x4dd) != '\0') {
    *(undefined4 *)(iVar2 + 0x580) = 0xff0;
    (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x50))(param_1,2,iVar2 + 0x580);
  }
  *(int **)(iVar2 + 0x3f0) = param_2;
  *(int *)(iVar2 + 0x3f4) = *param_2;
  (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x2c))(param_1);
  (*(code *)&memcpy)(iVar2 + 0x210,param_2 + 0xa2,6);
  (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x50))(param_1,0,iVar2 + 0x210);
  *(undefined1 *)(iVar2 + 0x599) = local_1d;
  *(undefined1 *)(iVar2 + 0x598) = local_1d;
  uVar3 = 0;
  (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x50))(param_1,0x35,&local_1d);
LAB_ram_000139a8:
  (*(code *)&mutex_unlock)(iVar2 + 0x24);
  return uVar3;
}

