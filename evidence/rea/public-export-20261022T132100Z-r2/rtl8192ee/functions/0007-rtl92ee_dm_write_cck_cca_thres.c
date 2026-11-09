/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1015c; aliases: rtl92ee_dm_write_cck_cca_thres
 */

void rtl92ee_dm_write_cck_cca_thres(int param_1,char param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar2 + 0xb946) != param_2) {
    rtl_write_byte(iVar2,0xa0a,param_2);
  }
  uVar1 = *(undefined1 *)(iVar2 + 0xb946);
  *(char *)(iVar2 + 0xb946) = param_2;
  *(undefined1 *)(iVar2 + 0xb945) = uVar1;
  return;
}

