/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14b28; aliases: efuse_one_byte_read
 */

undefined4 efuse_one_byte_read(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_1 + 0x40);
  rtl_write_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 1,param_2 & 0xff);
  iVar6 = *(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c);
  uVar2 = rtl_read_byte(iVar4,iVar6 + 2);
  rtl_write_byte(iVar4,iVar6 + 2,uVar2 & 0xfc | param_2 >> 8 & 3);
  cVar5 = '\0';
  rtl_write_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 3,0x72);
  while (uVar2 = rtl_read_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 3),
        (uVar2 & 0x80) == 0) {
    if (cVar5 == 'd') goto LAB_ram_00014bc4;
    cVar5 = cVar5 + '\x01';
  }
  if (cVar5 == 'd') {
LAB_ram_00014bc4:
    uVar1 = 0xff;
    uVar3 = 0;
  }
  else {
    uVar1 = rtl_read_byte(iVar4,*(undefined4 *)(*(int *)(iVar4 + 0xb8fc) + 0x4c));
    uVar3 = 1;
  }
  *param_3 = uVar1;
  return uVar3;
}

