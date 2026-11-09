/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18cc0; aliases: set_txbuffer_desc_len_with_offset
 */

void set_txbuffer_desc_len_with_offset(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + param_2 * 0x10);
  *puVar1 = *puVar1 & 0xffff0000 | param_3 & 0xffff;
  return;
}

