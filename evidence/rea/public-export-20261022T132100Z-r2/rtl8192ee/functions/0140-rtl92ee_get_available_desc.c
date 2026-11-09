/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x19a08; aliases: rtl92ee_get_available_desc
 */

uint rtl92ee_get_available_desc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  
  if ((param_2 & 0xff) < 8) {
    uVar3 = *(undefined2 *)(CSWTCH_176 + (param_2 & 0xff) * 2);
  }
  else {
    uVar3 = 0x3a8;
  }
  uVar2 = rtl_read_dword(*(undefined4 *)(param_1 + 0x40),uVar3);
  uVar4 = uVar2 >> 0x10 & 0xfff;
  iVar1 = uVar4 - (uVar2 & 0xfff);
  if ((uVar2 & 0xfff) < uVar4) {
    uVar2 = iVar1 - 1;
  }
  else {
    uVar2 = iVar1 + 0x1ff;
  }
  return uVar2 & 0xffff;
}

