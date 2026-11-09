/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1223c; aliases: _rtl_pci_rx_work
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtl_pci_rx_work(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iStack_48;
  int iStack_44;
  
  uVar2 = work_count_15;
  iVar8 = *(int *)(param_1 + -0xb8);
  iVar9 = *(int *)(iVar8 + 0x40);
  uVar10 = work_count_15 + 1;
  work_count_15 = uVar10;
  (*(code *)&memset)(&iStack_48,0,0x10);
  if (((*(char *)(iVar9 + 0xba9b) == '\0') && (*(char *)(iVar9 + 0xba9a) == '\0')) &&
     (bVar1 = false, *(char *)(param_1 + 0x5e0) != '\0')) {
    iVar7 = 0;
    do {
      iVar4 = _rtl_pci_rx_interrupt(iVar8,0x20);
      (**(code **)(param_1 + 0x6a0))(param_1 + -0xb8,0x3b4);
      iVar7 = iVar7 + 1;
      if (iVar4 != 0x20) goto LAB_ram_00012314;
      (*(code *)&_cond_resched)();
    } while (iVar7 != 4);
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
LAB_ram_00012314:
  if (*(char *)(iVar9 + 0xba9b) == '\0') {
    iVar7 = 0;
    if (((*(char *)(iVar9 + 0xba9a) == '\0') && (*(char *)(param_1 + 0x5e0) != '\0')) && (bVar1)) {
      iVar7 = (*(code *)&queue_delayed_work_on)(1,_system_wq,param_1,1);
    }
  }
  else {
    iVar7 = 0;
  }
  uVar5 = arch_local_irq_save();
  iVar3 = topaz_deferred_intb;
  iVar4 = topaz_deferred_inta;
  iStack_48 = topaz_deferred_inta;
  iStack_44 = topaz_deferred_intb;
  topaz_deferred_inta = 0;
  topaz_deferred_intb = 0;
  if (iVar4 != 0 || iVar3 != 0) {
    _rtl_pci_topaz_tx_complete(iVar8,&iStack_48,"rx-work");
  }
  if (((hgw500_tx_reclaim_poll != '\0') && (hgw500_tx_queue_guard != '\0')) &&
     ((hgw500_be_queue_guard_stopped != '\0' &&
      ((iVar4 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar4 != 0 &&
       (*(short *)(param_1 + 0x5d8) == 0xc)))))) {
    uVar6 = *(undefined4 *)(iVar9 + 0xbae4);
    uVar11 = poll_count_14 + 1;
    poll_count_14 = uVar11;
    _rtl_pci_tx_isr(iVar8,1);
    if ((uVar11 < 9) || (iVar4 = is_power_of_2(uVar11), iVar4 != 0)) {
      (*(code *)&printk)(&DAT_ram_000152d8,uVar11,1,uVar6,*(undefined4 *)(iVar9 + 0xbae4),
                         hgw500_be_queue_guard_stopped,*(undefined2 *)(iVar9 + 0xbaf4),
                         *(undefined2 *)(iVar9 + 0xbaf2));
    }
  }
  if (((*(char *)(iVar9 + 0xba9b) == '\0') && (*(char *)(iVar9 + 0xba9a) == '\0')) &&
     (*(char *)(param_1 + 0x5e0) != '\0')) {
    if ((hgw500_tx_reclaim_poll == '\0') || (hgw500_be_queue_guard_stopped == '\0')) {
      if (iVar7 != 0) goto LAB_ram_000124a0;
    }
    else {
      if (iVar7 != 0) goto LAB_ram_000124a0;
      rtl_pci_hgw500_be_reclaim_rearm_isra_0(*(undefined4 *)(iVar8 + 0x40),"rx-work");
    }
    (**(code **)(*(int *)(*(int *)(param_1 + 0xb844) + 0xc) + 0x24))(iVar8);
  }
LAB_ram_000124a0:
  Auxregs0028 = uVar5;
  if (((8 < uVar10) && ((uVar2 & 0xffffffef) != 0xf)) &&
     (((uVar2 & 0xffffffbf) != 0x3f && (uVar10 != 0x100)))) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

