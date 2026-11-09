/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10e38; aliases: rtl_pci_enable_aspm
 */

void rtl_pci_enable_aspm(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if ((*(char *)(iVar1 + 0xb2ed) != '\0') && (*(char *)(iVar1 + 0xccc3) != '\x04')) {
    _rtl_pci_platform_switch_device_pci_aspm_isra_0
              (iVar1,*(byte *)(iVar1 + 0xccbc) | *(byte *)(iVar1 + 0xccad));
    if ((*(uint *)(iVar1 + 0xb308) & 2) != 0) {
      _rtl_pci_switch_clk_req_isra_0(*(undefined4 *)(param_1 + 0x40),0x100);
      *(uint *)(iVar1 + 0xb304) = *(uint *)(iVar1 + 0xb304) | 2;
    }
    __udelay(100);
    return;
  }
  return;
}

