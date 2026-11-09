/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14d80; aliases: efuse_one_byte_write.isra.0
 */

void efuse_one_byte_write_isra_0(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  
  rtl_write_byte(param_1,*(int *)(*(int *)(param_1 + 0xb8fc) + 0x4c) + 1,param_2 & 0xff);
  iVar3 = *(int *)(*(int *)(param_1 + 0xb8fc) + 0x4c);
  uVar1 = rtl_read_byte(param_1,iVar3 + 2);
  rtl_write_byte(param_1,iVar3 + 2,uVar1 & 0xfc | param_2 >> 8 & 3);
  rtl_write_byte(param_1,*(undefined4 *)(*(int *)(param_1 + 0xb8fc) + 0x4c),param_3);
  rtl_write_byte(param_1,*(int *)(*(int *)(param_1 + 0xb8fc) + 0x4c) + 3,0xf2);
  for (cVar2 = '\0';
      (uVar1 = rtl_read_byte(param_1,*(int *)(*(int *)(param_1 + 0xb8fc) + 0x4c) + 3),
      (uVar1 & 0x80) != 0 && (cVar2 != 'd')); cVar2 = cVar2 + '\x01') {
  }
  return;
}

