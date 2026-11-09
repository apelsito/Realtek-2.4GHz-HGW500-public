/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16e48; aliases: rtl92ee_phy_bb_config
 */

undefined4 rtl92ee_phy_bb_config(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  
  iVar11 = *(int *)(param_1 + 0x40);
  *(undefined4 *)(iVar11 + 0x75c) = 0x870;
  *(undefined4 *)(iVar11 + 0x7a4) = 0x870;
  *(undefined4 *)(iVar11 + 0x764) = 0x860;
  *(undefined4 *)(iVar11 + 0x7ac) = 0x864;
  *(undefined4 *)(iVar11 + 0x768) = 0x860;
  *(undefined4 *)(iVar11 + 0x7b0) = 0x864;
  *(undefined4 *)(iVar11 + 0x76c) = 0x840;
  *(undefined4 *)(iVar11 + 0x7b4) = 0x844;
  *(undefined4 *)(iVar11 + 0x77c) = 0x824;
  *(undefined4 *)(iVar11 + 0x7c4) = 0x82c;
  *(undefined4 *)(iVar11 + 0x79c) = 0x8a0;
  *(undefined4 *)(iVar11 + 0x7e4) = 0x8a4;
  *(undefined4 *)(iVar11 + 0x7a0) = 0x8b8;
  *(undefined4 *)(iVar11 + 0x7e8) = 0x8bc;
  uVar2 = (**(code **)(iVar11 + 0x754))(iVar11,2);
  rtl_write_word(iVar11,2,uVar2 | 0x2003);
  rtl_write_byte(iVar11,0x1f,7);
  rtl_write_byte(iVar11,2,0xe3);
  rtl_write_byte(iVar11,0x25,0x80);
  uVar3 = rtl_read_dword(iVar11,0x4c);
  rtl_write_dword(iVar11,0x4c,uVar3 | 0x800000);
  iVar12 = *(int *)(param_1 + 0x40);
  phy_config_bb_with_hdr_file_isra_0(param_1,0);
  iVar10 = *(int *)(param_1 + 0x40);
  uVar6 = 0;
  uVar8 = 0;
  uVar3 = 0;
  do {
    for (; uVar6 < 4; uVar6 = uVar6 + 1 & 0xff) {
      for (; uVar8 < 0xc; uVar8 = uVar8 + 1 & 0xff) {
        *(undefined4 *)(iVar10 + (uVar6 * 0x54 + uVar3 * 0x150 + uVar8) * 4 + 0x1640) = 0;
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 != 4);
  if (*(char *)(iVar12 + 0xa9e3) == '\0') {
    *(undefined1 *)(iVar12 + 0xfbe) = 0;
    iVar10 = 0;
    do {
      uVar3 = (&RTL8192EE_PHY_REG_ARRAY_PG)[iVar10];
      if (uVar3 < 0xcdcdcdcd) {
        uVar6 = (&DAT_ram_00021080)[iVar10];
        if (uVar6 == 0x86c) {
          uVar6 = 3;
        }
        else if (uVar6 < 0x86d) {
          if (uVar6 == 0x83c) {
LAB_ram_0001734e:
            uVar6 = 4;
          }
          else if (uVar6 < 0x83d) {
            if (uVar6 == 0x834) {
LAB_ram_00017352:
              uVar6 = 1;
            }
            else {
              if (uVar6 == 0x838) goto LAB_ram_00017356;
              bVar13 = uVar6 == 0x830;
LAB_ram_00017272:
              if (bVar13) {
LAB_ram_0001734a:
                uVar6 = 0;
              }
              else {
LAB_ram_00017274:
                uVar8 = (uVar6 & 0xfff) - 0xc20;
                if (uVar8 < 0x2d) {
                  uVar6 = uVar8 >> 2 & 0xff;
                }
                else {
                  uVar6 = (uVar6 & 0xfff) - 0xe20;
                  if (0x2c < uVar6) goto LAB_ram_0001734a;
                  uVar6 = uVar6 >> 2 & 0xff;
                }
              }
            }
          }
          else if (uVar6 == 0x84c) {
LAB_ram_0001735a:
            uVar6 = 6;
          }
          else {
            if (uVar6 == 0x868) goto LAB_ram_0001735e;
            bVar13 = uVar6 == 0x848;
LAB_ram_0001729e:
            if (!bVar13) goto LAB_ram_00017274;
            uVar6 = 5;
          }
        }
        else {
          if (uVar6 == 0xe10) goto LAB_ram_0001734e;
          if (uVar6 < 0xe11) {
            if (uVar6 == 0xe04) goto LAB_ram_00017352;
            if (uVar6 != 0xe08) {
              bVar13 = uVar6 == 0xe00;
              goto LAB_ram_00017272;
            }
LAB_ram_00017356:
            uVar6 = 2;
          }
          else {
            if (uVar6 == 0xe18) goto LAB_ram_0001735a;
            if (uVar6 != 0xe1c) {
              bVar13 = uVar6 == 0xe14;
              goto LAB_ram_0001729e;
            }
LAB_ram_0001735e:
            uVar6 = 7;
          }
        }
        if (uVar3 < 2) {
          if ((uint)((&DAT_ram_00021078)[iVar10] | (&DAT_ram_0002107c)[iVar10]) < 4) {
            *(undefined4 *)
             (*(int *)(param_1 + 0x40) +
              ((&DAT_ram_0002107c)[iVar10] * 0x54 + (&DAT_ram_00021078)[iVar10] * 0x150 +
               uVar3 * 0x540 + uVar6) * 4 + 0x1640) = (&DAT_ram_00021088)[iVar10];
          }
        }
      }
      iVar10 = iVar10 + 6;
    } while (iVar10 != 0xa8);
  }
  iVar9 = *(int *)(param_1 + 0x40);
  iVar10 = 0;
  do {
    if (iVar10 == 0) {
      bVar1 = (byte)((uint)*(undefined4 *)(iVar9 + 0x164c) >> 0x18);
      *(byte *)(*(int *)(param_1 + 0x40) + 0x4040) = (bVar1 >> 4) * '\n' + (bVar1 & 0xf);
    }
    else {
      *(byte *)(*(int *)(param_1 + 0x40) + 0x4058) =
           ((byte)(*(uint *)(iVar9 + 0x1b8c) >> 4) & 0xf) * '\n' +
           ((byte)*(uint *)(iVar9 + 0x1b8c) & 0xf);
    }
    iVar5 = iVar10 * 0x18;
    iVar4 = iVar9 + 0x800 + iVar10 * 0x540;
    *(byte *)(*(int *)(param_1 + 0x40) + iVar5 + 0x4041) =
         (*(byte *)(iVar4 + 0xe47) >> 4) * '\n' + (*(byte *)(iVar4 + 0xe47) & 0xf);
    *(byte *)(*(int *)(param_1 + 0x40) + iVar5 + 0x4042) =
         (*(byte *)(iVar4 + 0xe57) >> 4) * '\n' + (*(byte *)(iVar4 + 0xe57) & 0xf);
    *(byte *)(*(int *)(param_1 + 0x40) + iVar5 + 0x4049) =
         (*(byte *)(iVar4 + 0xfaf) >> 4) * '\n' + (*(byte *)(iVar4 + 0xfaf) & 0xf);
    bVar13 = iVar10 != 1;
    iVar10 = 1;
  } while (bVar13);
  iVar9 = *(int *)(param_1 + 0x40);
  iVar10 = 0;
  do {
    if (iVar10 == 0) {
      uVar7 = *(undefined1 *)(*(int *)(param_1 + 0x40) + 0x4040);
      _phy_convert_txpower_dbm_to_relative_value(iVar9 + 0x1648,1,1,uVar7);
      iVar5 = iVar9 + 0x164c;
    }
    else {
      uVar7 = *(undefined1 *)(*(int *)(param_1 + 0x40) + 0x4058);
      _phy_convert_txpower_dbm_to_relative_value(iVar9 + 0x1b8c,0,0,uVar7);
      iVar5 = iVar9 + 0x1b88;
    }
    iVar4 = iVar10 * 0x18;
    _phy_convert_txpower_dbm_to_relative_value(iVar5,1,3,uVar7);
    uVar7 = *(undefined1 *)(*(int *)(param_1 + 0x40) + iVar4 + 0x4041);
    uVar3 = -iVar10 & 0x540;
    iVar5 = iVar9 + 0x75c;
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0xee4 + iVar5,0,3,uVar7);
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0xee8 + iVar5,0,3,uVar7);
    uVar7 = *(undefined1 *)(*(int *)(param_1 + 0x40) + iVar4 + 0x4042);
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0xef4 + iVar5,0,3,uVar7);
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0xef8 + iVar5,0,3,uVar7);
    uVar7 = *(undefined1 *)(*(int *)(param_1 + 0x40) + iVar4 + 0x4049);
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0x104c + iVar5,0,3,uVar7);
    _phy_convert_txpower_dbm_to_relative_value(uVar3 + 0x1050 + iVar5,0,3,uVar7);
    bVar13 = iVar10 != 1;
    iVar10 = 1;
  } while (bVar13);
  phy_config_bb_with_hdr_file_isra_0(param_1,1);
  iVar10 = rtl_get_bbreg(param_1,0x824,0x200);
  *(bool *)(iVar12 + 0xfbf) = iVar10 != 0;
  rtl_set_bbreg(param_1,0x2c,0xfff000,(*(byte *)(iVar11 + 0xaa02) & 0x3f) * 0x41);
  return 1;
}

