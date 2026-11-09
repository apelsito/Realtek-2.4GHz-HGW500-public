/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16d7c; aliases: rtl92ee_phy_set_rf_reg
 */

void rtl92ee_phy_set_rf_reg(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  
  if (param_4 != 0xfffff) {
    uVar2 = _rtl92ee_phy_rf_serial_read();
    bVar1 = calculate_bit_shift(param_4);
    param_5 = param_5 << (bVar1 & 0x1f) | uVar2 & ~param_4;
  }
  rtl_set_bbreg(param_1,*(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 0x48 + 0x76c),
                0xffffffff,(param_3 & 0xff) << 0x14 | param_5 & 0xfffff);
  return;
}

