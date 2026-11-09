/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15920; aliases: efuse_write_1byte
 */

void efuse_write_1byte(int param_1,uint param_2,undefined1 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if ((param_2 & 0xffff) < *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x70)) {
    rtl_write_byte(iVar3,*(undefined4 *)(*(int *)(iVar3 + 0xb8fc) + 0x4c),param_3);
    rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 1,param_2 & 0xff);
    uVar2 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 2);
    iVar4 = 0;
    rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 2,
                   uVar2 & 0xfc | (param_2 & 0xffff) >> 8 & 3);
    bVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
    rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3,bVar1 | 0x80);
    uVar2 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
    do {
      if ((uVar2 & 0x80) == 0) {
        return;
      }
      iVar4 = iVar4 + 1;
      uVar2 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
    } while (iVar4 != 100);
  }
  return;
}

