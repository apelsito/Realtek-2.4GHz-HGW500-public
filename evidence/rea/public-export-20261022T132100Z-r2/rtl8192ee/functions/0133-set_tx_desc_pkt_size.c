/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18cd8; aliases: set_tx_desc_pkt_size
 */

void set_tx_desc_pkt_size(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xffff0000 | param_2;
  return;
}

