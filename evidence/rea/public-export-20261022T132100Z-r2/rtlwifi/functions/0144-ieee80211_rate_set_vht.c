/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17290; aliases: ieee80211_rate_set_vht
 */

void ieee80211_rate_set_vht(byte *param_1,byte param_2,char param_3)

{
  *param_1 = (param_3 + -1) * '\x10' | param_2;
  return;
}

