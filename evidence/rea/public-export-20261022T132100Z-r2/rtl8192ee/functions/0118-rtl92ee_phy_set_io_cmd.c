/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x183ec; aliases: rtl92ee_phy_set_io_cmd
 */

undefined4 rtl92ee_phy_set_io_cmd(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 & 0xfffffffd) != 0) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar2 + 0x891) == '\0') {
    *(undefined1 *)(iVar2 + 0x891) = 1;
    *(uint *)(iVar2 + 0x884) = param_2;
    iVar2 = *(int *)(param_1 + 0x40);
    if (*(int *)(iVar2 + 0x884) == 0) {
      *(char *)(iVar2 + 0x87c) = (char)*(undefined4 *)(iVar2 + 0xb92c);
      rtl92ee_dm_write_dig(param_1,0x17);
      *(undefined1 *)(iVar2 + 0x880) = *(undefined1 *)(iVar2 + 0xb946);
      rtl92ee_dm_write_cck_cca_thres(param_1,0x40);
    }
    else if (*(int *)(iVar2 + 0x884) == 2) {
      rtl92ee_dm_write_dig(param_1,*(undefined1 *)(iVar2 + 0x87c));
      rtl92ee_dm_write_cck_cca_thres(param_1,*(undefined1 *)(iVar2 + 0x880));
      rtl92ee_phy_set_txpower_level(param_1,*(undefined1 *)(iVar2 + 0x88f));
    }
    *(undefined1 *)(iVar2 + 0x891) = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

