/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17674; aliases: rtl92ee_phy_set_txpower_level
 */

void rtl92ee_phy_set_txpower_level(int param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar2 + 0xaa01) != '\0') {
    for (uVar1 = 0; uVar1 < *(byte *)(iVar2 + 0x9f98); uVar1 = uVar1 + 1) {
      local_24 = 0x3020100;
      if (*(int *)(*(int *)(param_1 + 0x40) + 0x6d0) == 0) {
        phy_set_txpower_index_by_rate_array
                  (param_1,uVar1,*(undefined1 *)(*(int *)(param_1 + 0x40) + 0x88a),param_2,&local_24
                   ,4);
      }
      local_24 = 0x7060504;
      local_20 = 0xb0a0908;
      phy_set_txpower_index_by_rate_array
                (param_1,uVar1,*(undefined1 *)(*(int *)(param_1 + 0x40) + 0x88a),param_2,&local_24,8
                );
      local_24 = 0xf0e0d0c;
      local_20 = 0x13121110;
      phy_set_txpower_index_by_rate_array
                (param_1,uVar1,*(undefined1 *)(*(int *)(param_1 + 0x40) + 0x88a),param_2,&local_24,8
                );
      if (1 < *(byte *)(iVar2 + 0x9f98)) {
        local_24 = 0x17161514;
        local_20 = 0x1b1a1918;
        phy_set_txpower_index_by_rate_array
                  (param_1,uVar1,*(undefined1 *)(*(int *)(param_1 + 0x40) + 0x88a),param_2,&local_24
                   ,8);
      }
    }
  }
  return;
}

