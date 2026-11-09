/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17650; aliases: rtl92ee_phy_get_txpower_level
 */

void rtl92ee_phy_get_txpower_level(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(byte *)(*(int *)(param_1 + 0x40) + 0x40f5) >> 1) - 8;
  iVar2 = (*(byte *)(*(int *)(param_1 + 0x40) + 0x40f4) >> 1) - 7;
  *param_2 = iVar1 * (uint)(iVar1 > iVar2) + iVar2 * (uint)(iVar1 <= iVar2);
  return;
}

