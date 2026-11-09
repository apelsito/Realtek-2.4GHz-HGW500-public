/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18ce8; aliases: set_tx_desc_tx_buffer_size
 */

void set_tx_desc_tx_buffer_size(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xffff0000 | param_2;
  return;
}

