/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x145f0; aliases: rtl_op_tx
 */

void rtl_op_tx(int param_1,undefined4 *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_54 [56];
  
  iVar5 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(auStack_54,0,0x38);
  uVar4 = trace_count_0 + 1;
  trace_count_0 = uVar4;
  (*(code *)&memset)(auStack_54,0,0x38);
  if (uVar4 < 0x21) {
    (*(code *)&printk)(&DAT_ram_00019f60,uVar4,*(undefined4 *)(param_3 + 0x50),
                       **(undefined2 **)(param_3 + 0xbc),*(char *)(iVar5 + 0x698) == '\0',
                       *(undefined4 *)(iVar5 + 0xb314),*(uint *)(iVar5 + 0xb904) & 1);
  }
  if ((*(char *)(iVar5 + 0x698) == '\0') || (*(int *)(iVar5 + 0xb314) != 0)) {
    if (0x20 < uVar4) goto LAB_ram_000146ae;
    puVar1 = &DAT_ram_00019fb4;
  }
  else {
    if ((*(uint *)(iVar5 + 0xb904) & 1) != 0) {
      iVar2 = (**(code **)(*(int *)(iVar5 + 0xb900) + 0x18))(param_1,*param_2,param_3);
      if (uVar4 < 0x21) {
        (*(code *)&printk)(&DAT_ram_0001a024,uVar4);
      }
      if (iVar2 != 0) {
        return;
      }
      uVar3 = (**(code **)(*(int *)(iVar5 + 0xb900) + 0xc))(param_1,*param_2,param_3,auStack_54);
      if (0x20 < uVar4) {
        return;
      }
      (*(code *)&printk)(&DAT_ram_0001a058,uVar4,uVar3);
      return;
    }
    if (0x20 < uVar4) goto LAB_ram_000146ae;
    puVar1 = &DAT_ram_00019fec;
  }
  (*(code *)&printk)(puVar1,uVar4);
LAB_ram_000146ae:
  (*(code *)&__dev_kfree_skb_any)(param_3,1);
  return;
}

