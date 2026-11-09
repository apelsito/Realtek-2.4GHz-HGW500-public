/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10eb8; aliases: rtl_pci_stop
 */

void rtl_pci_stop(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (((*(char *)(iVar3 + 0xba99) != '\0') && (*(char *)(iVar3 + 0xcc8c) != '\0')) &&
     (*(char *)(iVar3 + 0xba9a) == '\0')) {
    (*(code *)&disable_irq)(*(undefined4 *)(*(int *)(iVar3 + 0xba94) + 0x170));
    *(undefined1 *)(iVar3 + 0xba9a) = 1;
    (*(code *)&printk)(&DAT_ram_00014de4,&DAT_ram_00014ddc,
                       *(undefined4 *)(*(int *)(iVar3 + 0xba94) + 0x170));
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104))();
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar3 + 0xb9ac) + 0x38))(iVar3);
  }
  if (*(int *)(iVar3 + 0xb9ac) != 0) {
    (**(code **)(*(int *)(iVar3 + 0xb9ac) + 8))(iVar3);
  }
  *(undefined1 *)(iVar3 + 0x698) = 0;
  *(undefined1 *)(iVar3 + 0xba9b) = 1;
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x28))(param_1);
  (*(code *)&cancel_delayed_work_sync)(iVar3 + 0xb8);
  (*(code *)&cancel_work_sync)(iVar3 + 0x1f0);
  uVar2 = arch_local_irq_save();
  cVar4 = '\0';
  do {
    if (*(char *)(iVar3 + 0xb2ea) == '\0') {
LAB_ram_00010fc0:
      *(undefined1 *)(iVar3 + 0xb2ea) = 1;
      Auxregs0028 = uVar2;
      (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x18))(param_1);
      if (*(int *)(iVar3 + 0xb8f8) != 0) {
        (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x90))(param_1,7);
        uVar2 = arch_local_irq_save();
        *(undefined1 *)(iVar3 + 0xb2ea) = 0;
        Auxregs0028 = uVar2;
        rtl_pci_enable_aspm(param_1);
        return;
      }
      return;
    }
    Auxregs0028 = uVar2;
    if (cVar4 == 'e') {
      uVar2 = arch_local_irq_save();
      goto LAB_ram_00010fc0;
    }
    __udelay(1000);
    cVar4 = cVar4 + '\x01';
    uVar2 = arch_local_irq_save();
  } while( true );
}

