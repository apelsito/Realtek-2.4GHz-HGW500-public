/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15868; aliases: efuse_initialize
 */

void efuse_initialize(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  bVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x20) + 1);
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x20) + 1,bVar1 | 0x20);
  uVar2 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x1c) + 1);
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x1c) + 1,uVar2 & 0xfe);
  bVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x48) + 3);
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x48) + 3,bVar1 | 0x80);
  rtl_write_byte(iVar3,0x2f8,3);
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3,0x72);
  return;
}

