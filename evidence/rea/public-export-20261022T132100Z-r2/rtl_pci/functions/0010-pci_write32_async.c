/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100e8; aliases: pci_write32_async
 */

void pci_write32_async(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 + *(int *)(param_1 + 0x738)) = param_3;
  return;
}

