/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17ab8; aliases: rtl_evm_db_to_percentage
 */

uint rtl_evm_db_to_percentage(char param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = -(int)param_1;
  if (iVar1 < 0x21) {
    uVar2 = iVar1 * (uint)(0 < iVar1) * 3;
  }
  else {
    uVar2 = 100;
  }
  return uVar2 & 0xff;
}

