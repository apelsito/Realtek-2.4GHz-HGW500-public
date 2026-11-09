/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16d50; aliases: rtl92ee_phy_query_rf_reg
 */

uint rtl92ee_phy_query_rf_reg(void)

{
  byte bVar1;
  uint uVar2;
  uint in_r3;
  
  uVar2 = _rtl92ee_phy_rf_serial_read();
  bVar1 = calculate_bit_shift(in_r3);
  return (in_r3 & uVar2) >> (bVar1 & 0x1f);
}

