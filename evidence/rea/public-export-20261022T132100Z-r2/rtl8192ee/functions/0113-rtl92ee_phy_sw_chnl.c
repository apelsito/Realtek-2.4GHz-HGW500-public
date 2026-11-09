/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17c64; aliases: rtl92ee_phy_sw_chnl
 */

undefined1 rtl92ee_phy_sw_chnl(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar2 + 0x88c) == '\0') {
    uVar1 = 0;
    if (*(char *)(iVar2 + 0x88b) == '\0') {
      if ((0xe < *(byte *)(iVar2 + 0x88f)) && (__warned_3 == '\0')) {
        __warned_3 = '\x01';
        (*(code *)&warn_slowpath_fmt)
                  ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c",0x6f0,9,
                   "rtl8192ee: WIRELESS_MODE_G but channel>14");
      }
      *(undefined2 *)(iVar2 + 0x88c) = 1;
      *(undefined1 *)(iVar2 + 0x88e) = 0;
      if (*(char *)(iVar2 + 0x698) == '\0') {
        *(undefined1 *)(iVar2 + 0x88c) = 0;
      }
      else {
        rtl92ee_phy_sw_chnl_callback(param_1);
        *(undefined1 *)(iVar2 + 0x88c) = 0;
      }
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

