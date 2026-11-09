/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100d8; aliases: pci_write16_async
 */

void pci_write16_async(int param_1,int param_2,undefined2 param_3)

{
  *(undefined2 *)(param_2 + *(int *)(param_1 + 0x738)) = param_3;
  return;
}

