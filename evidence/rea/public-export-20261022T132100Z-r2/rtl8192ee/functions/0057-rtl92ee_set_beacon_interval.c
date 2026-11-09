/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x142a8; aliases: rtl92ee_set_beacon_interval
 */

void rtl92ee_set_beacon_interval(int param_1)

{
  rtl_write_word(*(int *)(param_1 + 0x40),0x554,*(undefined2 *)(*(int *)(param_1 + 0x40) + 0x5a0));
  return;
}

