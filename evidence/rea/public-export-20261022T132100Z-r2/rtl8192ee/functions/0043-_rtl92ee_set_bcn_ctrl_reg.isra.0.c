/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x131c8; aliases: _rtl92ee_set_bcn_ctrl_reg.isra.0
 */

void _rtl92ee_set_bcn_ctrl_reg_isra_0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (param_2 | *(uint *)(param_1 + 0xcca4)) & ~param_3;
  *(uint *)(param_1 + 0xcca4) = uVar1;
  rtl_write_byte(param_1,0x550,uVar1 & 0xff);
  return;
}

