/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x103f0; aliases: rtl_pci_hgw500_be_summary_active
 */

undefined4 rtl_pci_hgw500_be_summary_active(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (hgw500_be_tx_summary != '\0') {
    iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      if (*(short *)(param_1 + 0x690) != 0xc) {
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  return 0;
}

