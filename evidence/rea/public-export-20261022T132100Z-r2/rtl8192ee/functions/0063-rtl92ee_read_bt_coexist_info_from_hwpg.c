/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x147b0; aliases: rtl92ee_read_bt_coexist_info_from_hwpg
 */

void rtl92ee_read_bt_coexist_info_from_hwpg(int param_1,char param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (param_2 == '\0') {
    uVar3 = 1;
    uVar2 = 0;
    if (*(byte *)(param_3 + 0xc1) >> 5 != 1) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 1;
    uVar2 = 1;
  }
  *(undefined1 *)(iVar1 + 0xb9b1) = uVar3;
  *(undefined1 *)(iVar1 + 0xb9b0) = 9;
  *(undefined1 *)(iVar1 + 0xb9b2) = uVar2;
  return;
}

