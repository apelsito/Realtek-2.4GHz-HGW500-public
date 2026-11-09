/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x129cc; aliases: rtl_cam_delete_one_entry
 */

undefined4 rtl_cam_delete_one_entry(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  rtl_write_dword(iVar1,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x80),0);
  rtl_write_dword(iVar1,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x7c),param_3 << 3 | 0x80010000);
  return 0;
}

