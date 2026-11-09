/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1524c; aliases: _rtl92ee_phy_simularity_compare.isra.0
 */

undefined4 _rtl92ee_phy_simularity_compare_isra_0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  byte local_10 [4];
  
  local_10[0] = 0xff;
  local_10[1] = 0xff;
  puVar9 = (undefined4 *)(param_1 + param_2 * 0x20);
  iVar6 = param_3 * 0x20 + param_1;
  uVar10 = 0;
  uVar4 = 0;
  do {
    uVar5 = uVar4;
    bVar2 = (byte)uVar5;
    if ((1 << (bVar2 & 0x1f) & 0xaaU) == 0) {
      if (uVar5 == 8) {
        if (uVar10 == 0) {
          if (local_10[0] == 0xff) {
            uVar3 = 1;
          }
          else {
            iVar6 = 0;
            do {
              *(undefined4 *)(param_1 + iVar6 * 4 + 0x60) =
                   *(undefined4 *)(param_1 + (uint)local_10[0] * 0x20 + iVar6 * 4);
              bVar1 = iVar6 != 1;
              iVar6 = 1;
            } while (bVar1);
            uVar3 = 0;
          }
          if (local_10[1] == 0xff) {
            return uVar3;
          }
          iVar6 = 4;
          do {
            *(undefined4 *)(param_1 + iVar6 * 4 + 0x60) =
                 *(undefined4 *)(param_1 + (uint)local_10[1] * 0x20 + iVar6 * 4);
            bVar1 = iVar6 != 5;
            iVar6 = 5;
          } while (bVar1);
        }
        else {
          if ((uVar10 & 3) == 0) {
            *(undefined4 *)(param_1 + 0x60) = *puVar9;
            *(undefined4 *)(param_1 + 100) = puVar9[1];
          }
          if ((uVar10 & 0xc) == 0) {
            *(undefined4 *)(param_1 + 0x68) = puVar9[2];
            *(undefined4 *)(param_1 + 0x6c) = puVar9[3];
          }
          if ((uVar10 & 0x30) == 0) {
            *(undefined4 *)(param_1 + 0x70) = puVar9[4];
            *(undefined4 *)(param_1 + 0x74) = puVar9[5];
          }
          if ((uVar10 & 0xc0) == 0) {
            *(undefined4 *)(param_1 + 0x78) = puVar9[6];
            *(undefined4 *)(param_1 + 0x7c) = puVar9[7];
          }
        }
        return 0;
      }
      uVar8 = puVar9[uVar5];
      uVar4 = *(uint *)(iVar6 + uVar5 * 4);
    }
    else {
      uVar8 = puVar9[uVar5];
      uVar4 = *(uint *)(uVar5 * 4 + iVar6);
      if ((uVar8 & 0x200) != 0) {
        uVar8 = uVar8 | 0xfffffc00;
      }
      if ((uVar4 & 0x200) != 0) {
        uVar4 = uVar4 | 0xfffffc00;
      }
    }
    if ((int)uVar4 < (int)uVar8) {
      uVar8 = uVar8 - uVar4;
    }
    else {
      uVar8 = uVar4 - uVar8;
    }
    uVar4 = uVar5 + 1;
    if (5 < uVar8) {
      if (((uVar5 & 0xfffffffb) == 2) && (uVar10 == 0)) {
        if ((puVar9 + uVar5)[1] + puVar9[uVar5] == 0) {
          local_10[uVar5 >> 2] = (byte)param_3;
        }
        else {
          piVar7 = (int *)(iVar6 + uVar5 * 4);
          if (piVar7[1] + *piVar7 == 0) {
            local_10[uVar5 >> 2] = (byte)param_2;
          }
          else {
            uVar10 = 1 << (bVar2 & 0x1f);
          }
        }
      }
      else {
        uVar10 = uVar10 | 1 << (bVar2 & 0x1f);
      }
    }
  } while( true );
}

