/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10090; aliases: pci_read8_sync
 */

undefined1 pci_read8_sync(int param_1,int param_2)

{
  return *(undefined1 *)(param_2 + *(int *)(param_1 + 0x738));
}

