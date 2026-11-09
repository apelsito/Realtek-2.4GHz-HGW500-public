/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14c08; aliases: efuse_get_current_size
 */

ushort efuse_get_current_size(undefined4 param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  byte local_d;
  
  uVar2 = 0;
  while (((iVar3 = efuse_one_byte_read(param_1,uVar2,&local_d), iVar3 != 0 && (uVar2 < 0x200)) &&
         (local_d != 0xff))) {
    sVar1 = efuse_calculate_word_cnts(local_d & 0xf);
    uVar2 = uVar2 + 1 + sVar1 * 2;
  }
  return uVar2;
}

