/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17ad4; aliases: rtl_process_phyinfo
 */

void rtl_process_phyinfo(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  
  if (*(char *)(param_3 + 0x76) != '\0') {
    if ((*(char *)(param_3 + 0x79) != '\0') || (*(char *)(param_3 + 0x7a) != '\0')) {
      iVar12 = *(int *)(param_1 + 0x40);
      *(int *)(iVar12 + 0xb43c) = *(int *)(iVar12 + 0xb43c) + *(int *)(param_3 + 0x48);
      iVar6 = *(int *)(iVar12 + 0xb5f0) + 0x2d18;
      *(int *)(iVar12 + 0xb438) = *(int *)(iVar12 + 0xb438) + 1;
      uVar9 = *(uint *)(iVar12 + 0xb5f4);
      iVar11 = uVar9 + 1;
      *(int *)(iVar12 + 0xb5f4) = iVar11;
      if (99 < uVar9) {
        *(undefined4 *)(iVar12 + 0xb5f4) = 100;
        *(int *)(iVar12 + 0xb5f8) = *(int *)(iVar12 + 0xb5f8) - *(int *)(iVar12 + iVar6 * 4);
        iVar11 = 100;
      }
      uVar9 = *(int *)(iVar12 + 0xb5f0) + 1;
      iVar7 = (uint)*(byte *)(param_3 + 0x35) + *(int *)(iVar12 + 0xb5f8);
      *(int *)(iVar12 + 0xb5f8) = iVar7;
      if (99 < uVar9) {
        uVar9 = 0;
      }
      *(uint *)(iVar12 + iVar6 * 4) = (uint)*(byte *)(param_3 + 0x35);
      *(uint *)(iVar12 + 0xb5f0) = uVar9;
      uVar9 = (*(code *)&__udivsi3)(iVar7,iVar11);
      iVar11 = ((int)((uVar9 & 0xff) + 1) >> 1) + -0x5f;
      *(int *)(iVar12 + 0xb440) = iVar11;
      *(char *)(param_3 + 0x10) = (char)iVar11;
      if (*(char *)(param_3 + 0x77) == '\0') {
        bVar3 = *(byte *)(iVar12 + 0x9f98);
        for (uVar9 = 0; uVar9 < bVar3; uVar9 = uVar9 + 1 & 0xff) {
          iVar11 = iVar12 + uVar9;
          uVar13 = (uint)*(byte *)(iVar11 + 0xb444);
          iVar6 = param_3 + uVar9;
          if (uVar13 == 0) {
            uVar13 = (uint)*(byte *)(iVar6 + 0x4c);
            *(byte *)(iVar11 + 0xb444) = *(byte *)(iVar6 + 0x4c);
          }
          bVar2 = *(byte *)(iVar6 + 0x4c);
          cVar5 = (*(code *)&__divsi3)(uVar13 * 0x13 + (uint)bVar2,0x14);
          if (uVar13 < bVar2) {
            cVar5 = cVar5 + '\x01';
          }
          *(char *)(iVar11 + 0xb444) = cVar5;
          *(uint *)(iVar12 + (uVar9 + 0x2d07) * 4) = (uint)*(byte *)(iVar6 + 0x70);
          iVar7 = param_3 + uVar9 * 2;
          *(undefined1 *)(iVar11 + 0xb448) = *(undefined1 *)(iVar6 + 0x54);
          iVar11 = iVar12 + uVar9 * 2;
          *(undefined2 *)(iVar11 + 0xb44e) = *(undefined2 *)(iVar7 + 0x58);
          *(undefined2 *)(iVar11 + 0xb456) = *(undefined2 *)(iVar7 + 0x60);
        }
      }
    }
    iVar11 = *(int *)(param_1 + 0x40);
    if ((*(int *)(iVar11 + 0x3f4) == 2) ||
       (iVar6 = (*(code *)&ieee80211_find_sta)
                          (*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3f0),param_3), iVar6 == 0))
    {
      uVar9 = *(uint *)(iVar11 + 0x9ffc);
      iVar6 = 0;
      iVar12 = 0;
    }
    else {
      iVar12 = iVar6 + 0x108;
      uVar9 = *(uint *)(iVar6 + 0x1e8);
    }
    uVar13 = *(uint *)(param_3 + 0x48);
    if ((int)uVar9 < 0) {
      uVar9 = uVar13;
    }
    iVar7 = (*(code *)&__udivsi3)(uVar9 * 0x13 + uVar13,0x14);
    if (uVar9 < uVar13) {
      iVar7 = iVar7 + 1;
    }
    if (iVar6 == 0) {
      *(int *)(iVar11 + 0x9ffc) = iVar7;
    }
    else {
      *(char *)(iVar12 + 0xe0) = (char)iVar7;
      *(char *)(iVar12 + 0xe1) = (char)((uint)iVar7 >> 8);
      *(char *)(iVar12 + 0xe2) = (char)((uint)iVar7 >> 0x10);
      *(char *)(iVar12 + 0xe3) = (char)((uint)iVar7 >> 0x18);
    }
    iVar6 = *(int *)(param_1 + 0x40);
    iVar11 = *(int *)(iVar6 + 0xb42c);
    if (iVar11 == 0) {
      iVar11 = *(int *)(param_3 + 0x30);
      *(int *)(iVar6 + 0xb42c) = iVar11;
    }
    iVar12 = *(int *)(param_3 + 0x30);
    if (iVar11 < iVar12) {
      iVar7 = 5;
    }
    else if (iVar12 < iVar11) {
      iVar7 = -5;
    }
    else {
      iVar7 = 0;
    }
    uVar8 = (*(code *)&__divsi3)(iVar11 * 5 + iVar12 + iVar7,6);
    *(undefined4 *)(iVar6 + 0xb42c) = uVar8;
    if (*(char *)(param_3 + 0x2c) != '\0') {
      iVar12 = *(int *)(param_1 + 0x40);
      uVar9 = *(uint *)(iVar12 + 0xb790);
      iVar11 = uVar9 + 1;
      *(int *)(iVar12 + 0xb790) = iVar11;
      iVar6 = *(int *)(iVar12 + 0xb78c) + 0x2d7f;
      if (0x13 < uVar9) {
        *(undefined4 *)(iVar12 + 0xb790) = 0x14;
        *(int *)(iVar12 + 0xb794) = *(int *)(iVar12 + 0xb794) - *(int *)(iVar12 + iVar6 * 4);
        iVar11 = 0x14;
      }
      uVar9 = *(int *)(iVar12 + 0xb78c) + 1;
      iVar7 = (uint)*(byte *)(param_3 + 0x2c) + *(int *)(iVar12 + 0xb794);
      *(int *)(iVar12 + 0xb794) = iVar7;
      if (0x13 < uVar9) {
        uVar9 = 0;
      }
      *(uint *)(iVar12 + iVar6 * 4) = (uint)*(byte *)(param_3 + 0x2c);
      *(uint *)(iVar12 + 0xb78c) = uVar9;
      uVar8 = (*(code *)&__udivsi3)(iVar7,iVar11);
      *(undefined4 *)(iVar12 + 0xb430) = uVar8;
      *(undefined4 *)(iVar12 + 0xb434) = uVar8;
      iVar11 = 0;
      do {
        bVar3 = *(byte *)(param_3 + iVar11 + 0x68);
        if (bVar3 != 0xff) {
          pbVar10 = (byte *)(iVar12 + iVar11 + 0xb44c);
          uVar9 = (uint)*pbVar10;
          if (uVar9 == 0) {
            uVar9 = (uint)bVar3;
            *pbVar10 = bVar3;
          }
          uVar4 = (*(code *)&__divsi3)(uVar9 * 0x13 + (int)*(char *)(param_3 + iVar11 + 0x68),0x14);
          *(undefined1 *)(iVar12 + iVar11 + 0xb44c) = uVar4;
        }
        bVar1 = iVar11 != 1;
        iVar11 = 1;
      } while (bVar1);
    }
    return;
  }
  return;
}

