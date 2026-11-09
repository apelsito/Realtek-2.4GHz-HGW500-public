/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x159fc; aliases: read_efuse
 */

void read_efuse(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  byte local_3c;
  undefined1 local_3b;
  ushort local_3a;
  
  iVar13 = *(int *)(param_1 + 0x40);
  iVar15 = iVar13 + 0xb800;
  iVar4 = *(int *)(iVar13 + 0xb8fc);
  local_3a = 0;
  uVar12 = *(uint *)(iVar4 + 0x6c);
  uVar11 = *(uint *)(iVar4 + 0x70);
  local_3b = 0;
  if (*(uint *)(iVar4 + 0x68) < (param_3 & 0xffff) + (param_2 & 0xffff)) {
    return;
  }
  iVar4 = (*(code *)&__kmalloc)(*(uint *)(iVar4 + 0x68),0xb20);
  if (iVar4 == 0) {
    return;
  }
  iVar1 = kmalloc_array_constprop_0(4,4);
  if (iVar1 != 0) {
    uVar9 = 0;
    do {
      iVar2 = kmalloc_array_constprop_0(uVar12 & 0xffff,2);
      *(int *)(iVar1 + uVar9 * 4) = iVar2;
      if (iVar2 == 0) goto LAB_ram_00015cca;
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 != 4);
    uVar12 = uVar12 & 0xffff;
    for (uVar9 = 0; uVar9 < uVar12; uVar9 = uVar9 + 1 & 0xffff) {
      uVar7 = 0;
      do {
        iVar2 = uVar7 * 4;
        uVar7 = uVar7 + 1 & 0xffff;
        *(undefined2 *)(*(int *)(iVar1 + iVar2) + uVar9 * 2) = 0xffff;
      } while (uVar7 != 4);
    }
    read_efuse_byte(param_1,0,&local_3c);
    uVar9 = (uint)local_3c;
    if (uVar9 == 0xff) {
      uVar7 = 0;
    }
    else {
      local_3a = local_3a + 1;
      uVar7 = 1;
    }
    while ((uVar5 = uVar7, uVar9 != 0xff && (uVar5 < uVar11))) {
      if ((uVar9 & 0x1f) == 0xf) {
        read_efuse_byte(param_1,uVar5,&local_3c);
        uVar7 = uVar5 + 1 & 0xffff;
        uVar14 = local_3c & 0xf;
        if (uVar14 != 0xf) {
          uVar3 = (int)(uint)local_3c >> 1 & 0x78U | uVar9 >> 5;
          uVar5 = uVar7;
          goto LAB_ram_00015b8a;
        }
        read_efuse_byte(param_1,uVar7,&local_3c);
        uVar9 = (uint)local_3c;
        if ((uVar9 != 0xff) && (uVar7 < uVar11)) {
          uVar7 = uVar5 + 2 & 0xffff;
        }
      }
      else {
        uVar3 = uVar9 >> 4;
        uVar14 = uVar9 & 0xf;
LAB_ram_00015b8a:
        if (uVar3 < uVar12) {
          uVar7 = 0;
          uVar9 = uVar5;
          do {
            uVar5 = uVar9;
            if ((uVar14 & 1) == 0) {
              read_efuse_byte(param_1,uVar9,&local_3c);
              piVar10 = (int *)(iVar1 + uVar7 * 4);
              local_3a = local_3a + 1;
              uVar5 = uVar9 + 1 & 0xffff;
              *(ushort *)(*piVar10 + uVar3 * 2) = (ushort)local_3c;
              if (uVar11 <= uVar5) break;
              read_efuse_byte(param_1,uVar5,&local_3c);
              local_3a = local_3a + 1;
              uVar5 = uVar9 + 2 & 0xffff;
              puVar6 = (ushort *)(*piVar10 + uVar3 * 2);
              *puVar6 = (ushort)local_3c << 8 | *puVar6;
              if (uVar11 <= uVar5) break;
            }
            uVar7 = uVar7 + 1 & 0xffff;
            uVar14 = uVar14 >> 1;
            uVar9 = uVar5;
          } while (uVar7 != 4);
        }
        read_efuse_byte(param_1,uVar5,&local_3c);
        uVar9 = (uint)local_3c;
        uVar7 = uVar5;
        if ((uVar9 != 0xff) && (uVar5 < uVar11)) {
          local_3a = local_3a + 1;
          uVar7 = uVar5 + 1 & 0xffff;
        }
      }
    }
    for (uVar9 = 0; uVar9 < uVar12; uVar9 = uVar9 + 1 & 0xffff) {
      uVar7 = 0;
      do {
        piVar10 = (int *)(iVar1 + uVar7 * 4);
        puVar8 = (undefined1 *)(iVar4 + (uVar7 + uVar9 * 4) * 2);
        uVar7 = uVar7 + 1 & 0xffff;
        *puVar8 = (char)*(undefined2 *)(*piVar10 + uVar9 * 2);
        puVar8[1] = (char)((ushort)*(undefined2 *)(*piVar10 + uVar9 * 2) >> 8);
      } while (uVar7 != 4);
    }
    for (uVar12 = 0; uVar12 < (param_3 & 0xffff); uVar12 = uVar12 + 1 & 0xffff) {
      *(undefined1 *)(param_4 + uVar12) = *(undefined1 *)(iVar4 + (param_2 & 0xffff) + uVar12);
    }
    *(ushort *)(iVar13 + 0xa9e0) = local_3a;
    local_3b = (*(code *)&__udivsi3)((uint)local_3a * 100,uVar11);
    *(undefined1 *)(iVar13 + 0xa9e2) = local_3b;
    (**(code **)(*(int *)(*(int *)(iVar15 + 0xfc) + 0xc) + 0x50))(param_1,0x39,&local_3a);
    (**(code **)(*(int *)(*(int *)(iVar15 + 0xfc) + 0xc) + 0x50))(param_1,0x38,&local_3b);
LAB_ram_00015cca:
    uVar11 = 0;
    do {
      iVar13 = uVar11 * 4;
      uVar11 = uVar11 + 1 & 0xffff;
      (*(code *)&kfree)(*(undefined4 *)(iVar1 + iVar13));
    } while (uVar11 != 4);
    (*(code *)&kfree)(iVar1);
  }
  (*(code *)&kfree)(iVar4);
  return;
}

