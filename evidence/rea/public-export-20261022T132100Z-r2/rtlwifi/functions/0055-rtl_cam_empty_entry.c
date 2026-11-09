/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12ad0; aliases: rtl_cam_empty_entry
 */

void rtl_cam_empty_entry(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  uVar2 = 0;
  do {
    rtl_write_dword(iVar3,*(undefined4 *)(*(int *)(iVar3 + 0xb8fc) + 0x80));
    uVar1 = uVar2 + (param_2 & 0xff) * 8;
    uVar2 = uVar2 + 1 & 0xff;
    rtl_write_dword(iVar3,*(undefined4 *)(*(int *)(iVar3 + 0xb8fc) + 0x7c),uVar1 | 0x80010000);
  } while (uVar2 != 8);
  return;
}

