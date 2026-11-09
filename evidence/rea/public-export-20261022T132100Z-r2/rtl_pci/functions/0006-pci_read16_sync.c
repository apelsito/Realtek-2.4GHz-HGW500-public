/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100a4; aliases: pci_read16_sync
 */

undefined2 pci_read16_sync(int param_1,int param_2)

{
  return *(undefined2 *)(param_2 + *(int *)(param_1 + 0x738));
}

