/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11050; aliases: rtl_pci_hgw500_guard_high.isra.0
 */

uint rtl_pci_hgw500_guard_high_isra_0(int param_1)

{
  uint uVar1;
  
  if (param_1 - 1U <= hgw500_tx_queue_guard_high) {
    return param_1 - 1U;
  }
  uVar1 = 2;
  if (1 < hgw500_tx_queue_guard_high) {
    uVar1 = hgw500_tx_queue_guard_high;
  }
  return uVar1;
}

