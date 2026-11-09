/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16cc0; aliases: rtl92ee_phy_query_bb_reg
 */

uint rtl92ee_phy_query_bb_reg(int param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = rtl_read_dword(*(undefined4 *)(param_1 + 0x40));
  bVar1 = calculate_bit_shift(param_3);
  return (param_3 & uVar2) >> (bVar1 & 0x1f);
}

