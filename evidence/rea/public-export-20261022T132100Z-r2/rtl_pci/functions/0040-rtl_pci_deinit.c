/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x127ac; aliases: rtl_pci_deinit
 */

void rtl_pci_deinit(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  (*(code *)&synchronize_irq)(*(undefined4 *)(*(int *)(iVar1 + 0xba94) + 0x170));
  (*(code *)&cancel_delayed_work_sync)(iVar1 + 0xb8);
  (*(code *)&tasklet_kill)(iVar1 + 0x88);
  (*(code *)&tasklet_kill)(iVar1 + 0xa0);
  (*(code *)&cancel_work_sync)(iVar1 + 0x1f0);
  _rtl_pci_free_rx_ring_isra_0(*(undefined4 *)(param_1 + 0x40),0);
  _rtl_pci_free_rx_ring_isra_0(*(undefined4 *)(param_1 + 0x40),1);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    _rtl_pci_free_tx_ring(param_1,iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 9);
  return;
}

