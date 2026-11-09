/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1581c; aliases: _check_condition.isra.0
 */

uint _check_condition_isra_0(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0xcdcdcdcd) {
    return 1;
  }
  if ((((uint)*(byte *)(param_1 + 0xa9f5) == (param_2 & 0xff)) || ((param_2 & 0xff) == 0xff)) &&
     ((uVar1 = param_2 >> 8 & 0xff, (uVar1 & *(uint *)(param_1 + 0x68c)) != 0 || (uVar1 == 7)))) {
    return param_2 >> 0x13 & 1;
  }
  return 0;
}

