/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11178; aliases: rtl_beacon_statistic
 */

void rtl_beacon_statistic(int param_1,int param_2)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar1 + 0x3f4) != 2) {
    return;
  }
  if (*(uint *)(iVar1 + 0x4d0) < 2) {
    return;
  }
  puVar2 = *(ushort **)(param_2 + 0xbc);
  if (((*puVar2 & 0xfc) != 0x80) && ((*puVar2 & 0xfc) != 0x50)) {
    return;
  }
  if (*(uint *)(param_2 + 0x50) < 0x2d) {
    return;
  }
  if ((puVar2[8] == *(ushort *)(iVar1 + 0x566) && puVar2[9] == *(ushort *)(iVar1 + 0x568)) &&
      *(ushort *)(iVar1 + 0x56a) == puVar2[10]) {
    *(int *)(iVar1 + 47000) = *(int *)(iVar1 + 47000) + 1;
  }
  return;
}

