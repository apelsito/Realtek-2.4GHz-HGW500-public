/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10384; aliases: ieee80211_tx_info_clear_status
 */

/* WARNING: Control flow encountered bad instruction data */

void ieee80211_tx_info_clear_status(int param_1)

{
  *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xe0;
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xe0;
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) & 0xe0;
  *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xe0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

