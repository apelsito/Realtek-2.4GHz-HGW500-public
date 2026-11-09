/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12834; aliases: rtl_pci_disconnect
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_pci_disconnect(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xb4);
  iVar3 = *(int *)(iVar2 + 0x40);
  (*(code *)&wait_for_completion)(iVar3 + 4);
  uVar1 = arch_local_irq_save();
  *(uint *)(iVar3 + 0xb904) = *(uint *)(iVar3 + 0xb904) & 0xfffffffe;
  Auxregs0028 = uVar1;
  if (*(char *)(iVar3 + 0x216) == '\x01') {
    (*(code *)&ieee80211_unregister_hw)(iVar2);
    *(undefined1 *)(iVar3 + 0x216) = 0;
  }
  else {
    (*(code *)&rtl_deinit_deferred_work)(iVar2,0);
    (**(code **)(*(int *)(iVar3 + 0xb900) + 8))(iVar2);
  }
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x28))(iVar2);
  (*(code *)&rtl_deinit_rfkill)(iVar2);
  rtl_pci_deinit(iVar2);
  (*(code *)&rtl_deinit_core)(iVar2);
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 4))(iVar2);
  if (*(char *)(iVar3 + 0xcc8c) != '\0') {
    rtl_pci_irq_line_release_isra_0(*(undefined4 *)(iVar2 + 0x40),"disconnect-balance");
    (*(code *)&free_irq)(*(undefined4 *)(*(int *)(iVar3 + 0xba94) + 0x170),iVar2);
    *(undefined1 *)(iVar3 + 0xcc8c) = 0;
  }
  if (*(int *)(iVar3 + 0x738) != 0) {
    (*(code *)&pci_release_regions)(param_1);
  }
  (*(code *)&pci_disable_device)(param_1);
  rtl_pci_disable_aspm(iVar2);
  *(undefined4 *)(param_1 + 0xb4) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

