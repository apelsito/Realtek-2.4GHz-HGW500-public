/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13740; aliases: rtl_pci_hgw500_be_summary_log
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_pci_hgw500_be_summary_log(int param_1,undefined4 param_2,undefined4 param_3)

{
  hgw500_be_tx_summary_last = _jiffies;
  (*(code *)&printk)(&DAT_ram_00014b80,param_2,param_3,hgw500_be_tx_enter_count,
                     hgw500_be_tx_complete_count,hgw500_be_tx_enter_bytes,
                     hgw500_be_tx_complete_bytes,*(undefined4 *)(param_1 + 0x18),
                     hgw500_be_tx_max_queued,*(undefined2 *)(param_1 + 0x28),
                     *(undefined2 *)(param_1 + 0x26),*(undefined4 *)(param_1 + 0xc),
                     hgw500_be_queue_guard_stopped);
  return;
}

