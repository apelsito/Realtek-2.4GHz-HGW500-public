/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17964; aliases: rtl_reg_notifier
 */

void rtl_reg_notifier(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  (*(code *)&wiphy_to_ieee80211_hw)();
  _rtl_reg_apply_radar_flags(param_1);
  if (*(int *)(param_2 + 0xc) == 3) {
    _rtl_reg_apply_beaconing_flags(param_1,3);
    piVar2 = *(int **)(param_1 + 0xcc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *piVar2;
      uVar1 = (*(code *)&freq_reg_info)(param_1,*(undefined4 *)(iVar3 + 0x26c));
      if (((uVar1 < 0xfffff001) && ((*(uint *)(uVar1 + 0x54) & 0x80) == 0)) &&
         ((*(uint *)(iVar3 + 0x274) & 2) != 0)) {
        *(uint *)(iVar3 + 0x274) = *(uint *)(iVar3 + 0x274) & 0xfffffffd;
      }
      iVar3 = *piVar2;
      uVar1 = (*(code *)&freq_reg_info)(param_1,*(undefined4 *)(iVar3 + 0x2a4));
      if (((uVar1 < 0xfffff001) && ((*(uint *)(uVar1 + 0x54) & 0x80) == 0)) &&
         ((*(uint *)(iVar3 + 0x2ac) & 2) != 0)) {
        *(uint *)(iVar3 + 0x2ac) = *(uint *)(iVar3 + 0x2ac) & 0xfffffffd;
      }
    }
  }
  return;
}

