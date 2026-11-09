/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17be4; aliases: rtl92ee_phy_sw_chnl_callback
 */

void rtl92ee_phy_sw_chnl_callback(int param_1)

{
  int iVar1;
  int iVar2;
  int local_14;
  
  iVar2 = *(int *)(param_1 + 0x40);
  local_14 = 0;
  if (*(char *)(iVar2 + 0x698) != '\0') {
    do {
      if (*(char *)(iVar2 + 0x88c) == '\0') {
        return;
      }
      iVar1 = _rtl92ee_phy_sw_chnl_step_by_step
                        (param_1,*(undefined1 *)(iVar2 + 0x88f),iVar2 + 0x88d,iVar2 + 0x88e,
                         &local_14);
      if (iVar1 != 0) {
        *(undefined1 *)(iVar2 + 0x88c) = 0;
        return;
      }
      iVar1 = local_14;
    } while (local_14 == 0);
    do {
      iVar1 = iVar1 + -1;
      __udelay(1000);
    } while (iVar1 != 0);
  }
  return;
}

