/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16cf0; aliases: rtl92ee_phy_set_bb_reg
 */

void rtl92ee_phy_set_bb_reg(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x40);
  if (param_3 != 0xffffffff) {
    uVar2 = rtl_read_dword(uVar3);
    bVar1 = calculate_bit_shift(param_3);
    param_4 = param_4 << (bVar1 & 0x1f) | uVar2 & ~param_3;
  }
  rtl_write_dword(uVar3,param_2,param_4);
  return;
}

