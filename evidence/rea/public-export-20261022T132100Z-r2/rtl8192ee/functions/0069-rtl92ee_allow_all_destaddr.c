/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14a94; aliases: rtl92ee_allow_all_destaddr
 */

void rtl92ee_allow_all_destaddr(int param_1,char param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  uVar2 = *(uint *)(iVar1 + 0xcc88) | 1;
  if (param_2 == '\0') {
    uVar2 = *(uint *)(iVar1 + 0xcc88) & 0xfffffffe;
  }
  *(uint *)(iVar1 + 0xcc88) = uVar2;
  if (param_3 != '\0') {
    rtl_write_dword(iVar1,0x608);
    return;
  }
  return;
}

