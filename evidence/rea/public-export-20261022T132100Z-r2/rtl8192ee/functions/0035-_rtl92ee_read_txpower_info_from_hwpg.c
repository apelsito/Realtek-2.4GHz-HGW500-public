/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1261c; aliases: _rtl92ee_read_txpower_info_from_hwpg
 */

void _rtl92ee_read_txpower_info_from_hwpg(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  byte *pbVar8;
  char cVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte local_144 [56];
  byte local_10c [32];
  byte local_ec [16];
  byte local_dc [32];
  byte local_bc [24];
  char local_a4 [24];
  byte local_8c [16];
  byte local_7c [80];
  
  iVar12 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(local_bc,0,0x90);
  (*(code *)&memset)(local_144,0,0x88);
  if ((*(char *)(param_3 + 0x11) == -1) || (param_2 != 0)) {
    iVar2 = 0;
    do {
      iVar6 = 0;
      do {
        iVar3 = iVar6 + iVar2 * 6 + -0x2c;
        local_bc[iVar3 + 0x2c] = 0x2d;
        iVar6 = iVar6 + 1;
        local_a4[iVar3 + 0x2c] = '-';
      } while (iVar6 != 6);
      iVar6 = 0;
      do {
        if (iVar6 == 0) {
          local_7c[iVar2 * 4 + 0x10] = 2;
          puVar4 = &stack0xffffffd4 + iVar2 * 4;
          uVar7 = 4;
        }
        else {
          puVar4 = &stack0xffffffd4 + iVar6 + iVar2 * 4;
          uVar7 = 0xfe;
          puVar4[-0x40] = 0xfe;
          puVar4[-0x30] = 0xfe;
          puVar4[-0x60] = 0xfe;
        }
        iVar6 = iVar6 + 1;
        puVar4[-0x50] = uVar7;
      } while (iVar6 != 4);
      iVar6 = 0;
      do {
        local_144[iVar6 + iVar2 * 0xe] = 0x2a;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0xe);
      iVar6 = 0;
      do {
        iVar3 = (iVar2 + 0xe) * 4;
        if (iVar2 + 0x12 == 0) {
          local_144[iVar3] = 4;
          local_144[0] = (byte)iVar6;
        }
        else {
          local_144[(iVar2 + 0x12) * 4] = 0xfe;
          local_144[iVar3] = 0xfe;
          local_ec[iVar2 * 4] = 0xfe;
        }
        iVar6 = iVar6 + 1;
        local_dc[iVar2 * 4] = 0xfe;
      } while (iVar6 != 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 != 4);
  }
  else {
    *(undefined1 *)(iVar12 + 0xaa01) = 1;
    iVar2 = 0x10;
    iVar6 = 0;
    do {
      iVar3 = 0;
      do {
        bVar1 = *(byte *)(param_3 + iVar2);
        iVar2 = iVar2 + 1;
        if (bVar1 == 0xff) {
          bVar1 = 0x2d;
        }
        local_bc[iVar3 + iVar6 * 6] = bVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 6);
      iVar3 = 0;
      do {
        cVar9 = *(char *)(param_3 + iVar2);
        iVar11 = iVar3 + iVar6 * 6;
        if (cVar9 == -1) {
          cVar9 = '-';
        }
        iVar3 = iVar3 + 1;
        local_a4[iVar11] = cVar9;
        iVar2 = iVar2 + 1;
      } while (iVar3 != 5);
      iVar3 = 0;
      do {
        pbVar8 = (byte *)(param_3 + iVar2);
        if (iVar3 == 0) {
          local_7c[iVar6 * 4 + 0x20] = 0;
          bVar1 = *pbVar8;
          if (bVar1 == 0xff) {
            local_bc[(iVar6 + 0x14) * 4] = 2;
            bVar1 = 4;
          }
          else {
            bVar10 = bVar1 >> 4;
            if ((bVar10 & 8) != 0) {
              bVar10 = bVar10 | 0xf0;
            }
            local_bc[(iVar6 + 0x14) * 4] = bVar10;
            if ((bVar1 & 8) == 0) {
              bVar1 = bVar1 & 0xf;
            }
            else {
              bVar1 = bVar1 | 0xf0;
            }
          }
          local_7c[iVar6 * 4] = bVar1;
          local_bc[(iVar6 + 0xc) * 4] = 0;
          iVar2 = iVar2 + 1;
        }
        else {
          bVar1 = *pbVar8;
          iVar11 = iVar6 * 4;
          if (bVar1 == 0xff) {
            local_7c[iVar3 + iVar11 + 0x20] = 0xfe;
            bVar1 = 0xfe;
          }
          else {
            bVar10 = bVar1 >> 4;
            if ((bVar10 & 8) != 0) {
              bVar10 = bVar10 | 0xf0;
            }
            local_7c[iVar3 + iVar11 + 0x20] = bVar10;
            if ((bVar1 & 8) == 0) {
              bVar1 = bVar1 & 0xf;
            }
            else {
              bVar1 = bVar1 | 0xf0;
            }
          }
          iVar5 = iVar3 + iVar11 + -0x2c;
          local_7c[iVar5 + 0x3c] = bVar1;
          bVar1 = pbVar8[1];
          if (bVar1 == 0xff) {
            local_7c[iVar5 + 0x2c] = 0xfe;
            bVar1 = 0xfe;
          }
          else {
            bVar10 = bVar1 >> 4;
            if ((bVar10 & 8) != 0) {
              bVar10 = bVar10 | 0xf0;
            }
            local_7c[iVar3 + iVar11] = bVar10;
            if ((bVar1 & 8) == 0) {
              bVar1 = bVar1 & 0xf;
            }
            else {
              bVar1 = bVar1 | 0xf0;
            }
          }
          local_8c[iVar3 + iVar11] = bVar1;
          iVar2 = iVar2 + 2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
      iVar3 = 0;
      do {
        bVar1 = *(byte *)(param_3 + iVar2);
        iVar11 = iVar3 + iVar6 * 0xe;
        if (bVar1 == 0xff) {
          bVar1 = 0xfe;
        }
        iVar3 = iVar3 + 1;
        local_144[iVar11] = bVar1;
        iVar2 = iVar2 + 1;
      } while (iVar3 != 0xe);
      iVar3 = 0;
      do {
        iVar11 = iVar2;
        if (iVar3 == 0) {
          bVar1 = *(byte *)(param_3 + iVar11);
          local_144[(iVar6 + 0x16) * 4] = 0;
          if (iVar6 + 0x12 == 0) {
            local_144[0] = 0;
            bVar1 = 4;
          }
          else {
            bVar10 = bVar1 >> 4;
            if ((bVar10 & 8) != 0) {
              bVar10 = bVar10 | 0xf0;
            }
            local_144[(iVar6 + 0x12) * 4] = bVar10;
            if ((bVar1 & 8) == 0) {
              bVar1 = bVar1 & 0xf;
            }
            else {
              bVar1 = bVar1 | 0xf0;
            }
          }
          local_10c[iVar6 * 4] = bVar1;
        }
        else {
          bVar1 = *(byte *)(param_3 + iVar11);
          iVar2 = iVar6 * 4;
          if (bVar1 == 0xff) {
            local_ec[iVar3 + iVar2] = 0xfe;
            bVar1 = 0xfe;
          }
          else {
            bVar10 = bVar1 >> 4;
            if ((bVar10 & 8) != 0) {
              bVar10 = bVar10 | 0xf0;
            }
            local_ec[iVar3 + iVar2] = bVar10;
            if ((bVar1 & 8) == 0) {
              bVar1 = bVar1 & 0xf;
            }
            else {
              bVar1 = bVar1 | 0xf0;
            }
          }
          local_10c[iVar3 + iVar2 + 0x10] = bVar1;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar11 + 1;
      } while (iVar3 != 4);
      pbVar8 = (byte *)(param_3 + iVar11 + 1);
      bVar1 = *pbVar8;
      if (bVar1 == 0xff) {
        bVar10 = 0xfe;
        bVar1 = 0xfe;
      }
      else {
        bVar10 = bVar1 >> 4;
        bVar1 = bVar1 & 0xf;
      }
      iVar3 = iVar6 * 4;
      local_10c[iVar3 + 2] = bVar1;
      bVar1 = pbVar8[1];
      local_10c[iVar3 + 1] = bVar10;
      if (bVar1 == 0xff) {
        bVar1 = 0xfe;
      }
      else {
        bVar1 = bVar1 & 0xf;
      }
      local_10c[iVar3 + 3] = bVar1;
      iVar2 = iVar11 + 3;
      iVar11 = 1;
      do {
        bVar1 = local_10c[iVar11 + iVar3];
        if (bVar1 == 0xff) {
          bVar1 = 0xfe;
LAB_ram_000128c4:
          local_10c[iVar11 + iVar3] = bVar1;
        }
        else if ((bVar1 & 8) != 0) {
          bVar1 = bVar1 | 0xf0;
          goto LAB_ram_000128c4;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 != 4);
      iVar11 = 0;
      do {
        if (*(byte *)(param_3 + iVar2) == 0xff) {
          local_dc[iVar11 + iVar3] = 0xfe;
        }
        else {
          bVar1 = *(byte *)(param_3 + iVar2) >> 4;
          if ((bVar1 & 8) != 0) {
            bVar1 = bVar1 | 0xf0;
          }
          local_dc[iVar11 + iVar3] = bVar1;
        }
        iVar11 = iVar11 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar11 != 4);
      iVar6 = iVar6 + 1;
    } while (iVar6 != 4);
  }
  uVar13 = 0;
  do {
    uVar14 = 0;
    while( true ) {
      iVar3 = _rtl92ee_get_chnl_group((int)(char)(uVar14 + 1));
      iVar2 = uVar13 * 0xe;
      iVar6 = uVar13 * 0x3b;
      iVar3 = iVar3 + uVar13 * 6 + -0x2c;
      cVar9 = local_a4[iVar3 + 0x2c];
      iVar11 = iVar12 + 0xa600;
      if (uVar14 == 0xd) break;
      *(byte *)(iVar2 + iVar11 + uVar14 + 0x585) = local_bc[iVar3 + 0x2c];
      *(char *)(iVar11 + iVar6 + uVar14 + 0x5bd) = cVar9;
      uVar14 = uVar14 + 1 & 0xff;
    }
    *(byte *)(iVar11 + iVar2 + 0x592) = local_bc[uVar13 * 6 + 5];
    *(char *)(iVar11 + iVar6 + 0x5ca) = cVar9;
    uVar14 = 0;
    do {
      iVar3 = _rtl92ee_get_chnl_group((&channel5g)[uVar14]);
      iVar5 = iVar11 + iVar6 + uVar14;
      uVar14 = uVar14 + 1 & 0xff;
      *(byte *)(iVar5 + 0xb45) = local_144[iVar3 + iVar2];
    } while (uVar14 != 0x31);
    uVar14 = 0;
    do {
      iVar3 = _rtl92ee_get_chnl_group((&channel5g_80m)[uVar14]);
      iVar3 = iVar3 + iVar2 + -0x22c;
      iVar5 = iVar11 + uVar13 * 7 + uVar14;
      uVar14 = uVar14 + 1 & 0xff;
      *(char *)(iVar5 + 0xc31) =
           (char)((int)((uint)local_144[iVar3 + 0x22d] + (uint)local_144[iVar3 + 0x22c]) >> 1);
    } while (uVar14 != 7);
    uVar14 = 0;
    do {
      iVar2 = uVar14 + uVar13 * 4 + -0x2c;
      iVar3 = iVar11 + iVar6 + uVar14;
      *(byte *)(iVar3 + 0x795) = local_8c[iVar2 + 0x2c];
      *(byte *)(iVar3 + 0xa59) = local_7c[iVar2 + 0x2c];
      bVar1 = local_7c[iVar2 + 0x4c];
      *(byte *)(iVar3 + 0x881) = local_7c[iVar2 + 0x3c];
      iVar2 = uVar14 + uVar13 * 4 + -0x22c;
      *(byte *)(iVar3 + 0x96d) = bVar1;
      iVar3 = iVar11 + uVar13 * 4 + uVar14;
      *(byte *)(iVar3 + 0xc4d) = local_10c[iVar2 + 0x22c];
      *(byte *)(iVar3 + 0xc5d) = local_10c[iVar2 + 0x23c];
      bVar1 = local_dc[iVar2 + 0x22c];
      *(byte *)(iVar3 + 0xc6d) = local_ec[iVar2 + 0x22c];
      uVar14 = uVar14 + 1 & 0xff;
      *(byte *)(iVar3 + 0xc7d) = bVar1;
    } while (uVar14 != 4);
    uVar13 = uVar13 + 1 & 0xff;
  } while (uVar13 != 4);
  if (param_2 == 0) {
    cVar9 = *(char *)(param_3 + 0xba);
    *(char *)(iVar12 + 0xb294) = cVar9;
    if (cVar9 == -1) goto LAB_ram_00012c74;
    *(char *)(iVar12 + 0xb295) = cVar9;
  }
  else {
LAB_ram_00012c74:
    *(undefined1 *)(iVar12 + 0xb29e) = 1;
    *(undefined2 *)(iVar12 + 0xb294) = 0x1a1a;
    if (param_2 != 0) goto LAB_ram_00012ca6;
  }
  *(byte *)(iVar12 + 0xb293) = *(byte *)(param_3 + 0xc1) & 7;
  if (*(char *)(param_3 + 0xc1) != -1) {
    return;
  }
LAB_ram_00012ca6:
  *(undefined1 *)(iVar12 + 0xb293) = 0;
  return;
}

