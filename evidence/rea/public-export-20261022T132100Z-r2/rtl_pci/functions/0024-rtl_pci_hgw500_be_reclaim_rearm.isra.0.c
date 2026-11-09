/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10a84; aliases: rtl_pci_hgw500_be_reclaim_rearm.isra.0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 rtl_pci_hgw500_be_reclaim_rearm_isra_0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (((((hgw500_tx_reclaim_poll == '\0') || (hgw500_tx_queue_guard == '\0')) ||
       (hgw500_be_queue_guard_stopped == '\0')) ||
      ((iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar1 == 0 ||
       (*(short *)(param_1 + 0x690) != 0xc)))) ||
     ((*(char *)(param_1 + 0xba9b) != '\0' ||
      ((*(char *)(param_1 + 0xba9a) != '\0' || (*(char *)(param_1 + 0x698) == '\0')))))) {
    uVar3 = 0;
  }
  else {
    uVar2 = rearm_count_6 + 1;
    rearm_count_6 = uVar2;
    uVar3 = (*(code *)&mod_delayed_work_on)(1,_system_wq,param_1 + 0xb8,1);
    if ((uVar2 < 9) || (iVar1 = is_power_of_2(uVar2), iVar1 != 0)) {
      (*(code *)&printk)(&DAT_ram_00014d6c,uVar2,param_2,1,*(undefined4 *)(param_1 + 0xbae4),uVar3,
                         hgw500_be_queue_guard_stopped,*(undefined2 *)(param_1 + 0xbaf4),
                         *(undefined2 *)(param_1 + 0xbaf2));
    }
  }
  return uVar3;
}

