/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12d6c; aliases: rtl_cam_reset_sec_info
 */

void rtl_cam_reset_sec_info(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar1 + 0xa3ce) = 0;
  *(undefined4 *)(iVar1 + 0xa3d0) = 0;
  *(undefined4 *)(iVar1 + 0xa3d4) = 0;
  (*(code *)&memset)(iVar1 + 0xa49c,0,0x131);
  (*(code *)&memset)(iVar1 + 0xa5cd,0,5);
  *(undefined4 *)(iVar1 + 0xa5d4) = 0;
  return;
}

