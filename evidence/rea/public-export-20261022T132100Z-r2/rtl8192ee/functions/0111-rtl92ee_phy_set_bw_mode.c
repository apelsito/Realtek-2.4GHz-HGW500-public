/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17bb0; aliases: rtl92ee_phy_set_bw_mode
 */

void rtl92ee_phy_set_bw_mode(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar1 + 0x88b) != '\0') {
    return;
  }
  *(undefined1 *)(iVar1 + 0x88b) = 1;
  if (*(char *)(iVar1 + 0x698) != '\0') {
    rtl92ee_phy_set_bw_mode_callback();
    return;
  }
  *(undefined1 *)(iVar1 + 0x88b) = 0;
  return;
}

