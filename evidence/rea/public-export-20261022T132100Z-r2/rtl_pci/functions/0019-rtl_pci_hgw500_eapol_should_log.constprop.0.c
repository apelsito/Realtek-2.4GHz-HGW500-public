/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x106c0; aliases: rtl_pci_hgw500_eapol_should_log.constprop.0
 */

undefined4 rtl_pci_hgw500_eapol_should_log_constprop_0(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar1 = rx_count_12 + 1;
    rx_count_12 = uVar1;
  }
  else {
    uVar1 = tx_count_13 + 1;
    tx_count_13 = uVar1;
  }
  *param_2 = uVar1;
  if (0x40 < uVar1) {
    uVar2 = is_power_of_2();
    return uVar2;
  }
  return 1;
}

