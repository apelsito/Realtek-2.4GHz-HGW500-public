/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18118; aliases: rtl_op_start
 */

int rtl_op_start(int param_1)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x40);
  cVar1 = *(char *)(iVar5 + 0x698);
  uVar4 = *(uint *)(iVar5 + 0xb904) & 1;
  (*(code *)&printk)(&DAT_ram_00019e2c,cVar1 == '\0',uVar4);
  if (cVar1 == '\0') {
    if (uVar4 != 0) {
      (*(code *)&mutex_lock)(iVar5 + 0x24);
      (*(code *)&printk)(&DAT_ram_00019ef4);
      iVar3 = (**(code **)(*(int *)(iVar5 + 0xb900) + 4))(param_1);
      (*(code *)&printk)(&DAT_ram_00019f20,iVar3,*(char *)(iVar5 + 0x698) == '\0');
      if (iVar3 == 0) {
        rtl_watch_dog_timer_callback(iVar5 + 0x4c);
      }
      (*(code *)&mutex_unlock)(iVar5 + 0x24);
      return iVar3;
    }
    puVar2 = &DAT_ram_00019eb0;
  }
  else {
    puVar2 = &DAT_ram_00019e74;
  }
  (*(code *)&printk)(puVar2);
  return 0;
}

