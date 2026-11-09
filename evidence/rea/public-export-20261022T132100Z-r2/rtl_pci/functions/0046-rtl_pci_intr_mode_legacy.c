/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13800; aliases: rtl_pci_intr_mode_legacy
 */

int rtl_pci_intr_mode_legacy(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_r14;
  int iVar3;
  bool bVar4;
  
  iVar2 = *(int *)(param_1 + 0x40);
  bVar4 = *(char *)(iVar2 + 0xba99) != '\0';
  if (bVar4) {
    unaff_r14 = 1;
  }
  if (bVar4) {
    iVar3 = unaff_r14 << 0x13;
  }
  else {
    iVar3 = 0x80;
  }
  iVar1 = (*(code *)&request_threaded_irq)
                    (*(undefined4 *)(*(int *)(iVar2 + 0xba94) + 0x170),_rtl_pci_interrupt,0,iVar3,
                     "rtl_pci",param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(iVar2 + 0xcc8c) = 1;
    if (*(char *)(iVar2 + 0xba99) != '\0') {
      *(undefined1 *)(iVar2 + 0xba9a) = 1;
      (*(code *)&printk)(&DAT_ram_00014c88,*(undefined4 *)(*(int *)(iVar2 + 0xba94) + 0x170),iVar3);
    }
    *(undefined1 *)(iVar2 + 0xccb9) = 0;
    iVar1 = 0;
  }
  return iVar1;
}

