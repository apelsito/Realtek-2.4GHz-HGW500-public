/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14a34; aliases: efuse_read_1byte
 */

undefined4 efuse_read_1byte(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (*(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x70) <= (param_2 & 0xffff)) {
    return 0xff;
  }
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 1,param_2 & 0xff);
  uVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 2);
  iVar4 = 0;
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 2,
                 uVar1 & 0xfc | (param_2 & 0xffff) >> 8 & 3);
  uVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
  rtl_write_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3,uVar1 & 0x7f);
  uVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
  do {
    if ((uVar1 & 0x80) != 0) break;
    iVar4 = iVar4 + 1;
    uVar1 = rtl_read_byte(iVar3,*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x4c) + 3);
  } while (iVar4 != 1000);
                    /* WARNING: Could not recover jumptable at 0x00014b10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = rtl_read_byte(iVar3,*(undefined4 *)(*(int *)(iVar3 + 0xb8fc) + 0x4c));
  return uVar2;
}

