/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100b8; aliases: pci_read32_sync
 */

undefined4 pci_read32_sync(int param_1,int param_2)

{
  return *(undefined4 *)(param_2 + *(int *)(param_1 + 0x738));
}

