/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10da0; aliases: rtl_pci_disable_aspm
 */

void rtl_pci_disable_aspm(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 local_11;
  
  iVar2 = *(int *)(param_1 + 0x40);
  bVar1 = *(byte *)(iVar2 + 0xccbc);
  local_11 = 0;
  if ((*(char *)(iVar2 + 0xb2ed) != '\0') && (*(char *)(iVar2 + 0xccc3) != '\x04')) {
    if ((*(uint *)(iVar2 + 0xb308) & 2) != 0) {
      *(uint *)(iVar2 + 0xb304) = *(uint *)(iVar2 + 0xb304) & 0xfffffffd;
      _rtl_pci_switch_clk_req_isra_0(*(undefined4 *)(param_1 + 0x40),0);
    }
    (*(code *)&pci_read_config_byte)(*(undefined4 *)(iVar2 + 0xba94),0x80,&local_11);
    _rtl_pci_platform_switch_device_pci_aspm_isra_0(*(undefined4 *)(param_1 + 0x40),bVar1 & 0xfc);
  }
  return;
}

