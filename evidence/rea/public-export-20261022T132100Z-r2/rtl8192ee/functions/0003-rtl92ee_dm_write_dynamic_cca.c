/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10030; aliases: rtl92ee_dm_write_dynamic_cca
 */

void rtl92ee_dm_write_dynamic_cca(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(byte *)(iVar1 + 0xb3d2) != param_2) {
    rtl_set_bbreg(param_1,0xc6c,0x180,param_2);
  }
  *(char *)(iVar1 + 0xb3d2) = (char)param_2;
  return;
}

