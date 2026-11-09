/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100f8; aliases: rtl_pci_hgw500_be_summary_should_log
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rtl_pci_hgw500_be_summary_should_log(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 < 9) {
    return 1;
  }
  iVar1 = is_power_of_2();
  if (iVar1 == 0) {
    uVar2 = (uint)((hgw500_be_tx_summary_last + 100) - _jiffies) >> 0x1f;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

