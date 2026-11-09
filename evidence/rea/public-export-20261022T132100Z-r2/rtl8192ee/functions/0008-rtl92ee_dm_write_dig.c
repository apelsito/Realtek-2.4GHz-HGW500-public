/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x101a4; aliases: rtl92ee_dm_write_dig
 */

void rtl92ee_dm_write_dig(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  param_2 = param_2 & 0xff;
  if (*(char *)(iVar2 + 0xb93d) == '\0') {
    if ((*(uint *)(iVar2 + 0xb92c) != param_2) &&
       (rtl_set_bbreg(param_1,0xc50,0x7f,param_2), *(char *)(iVar2 + 0x889) != '\0')) {
      rtl_set_bbreg(param_1,0xc58);
    }
    uVar1 = *(undefined4 *)(iVar2 + 0xb92c);
    *(uint *)(iVar2 + 0xb92c) = param_2;
    *(undefined4 *)(iVar2 + 0xb928) = uVar1;
  }
  return;
}

