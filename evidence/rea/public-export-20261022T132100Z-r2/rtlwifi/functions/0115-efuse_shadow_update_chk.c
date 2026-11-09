/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15f74; aliases: efuse_shadow_update_chk
 */

bool efuse_shadow_update_chk(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = 0;
  iVar5 = *(int *)(param_1 + 0x40);
  uVar2 = 0;
  iVar1 = 0;
  do {
    iVar6 = 0;
    uVar3 = 0;
    do {
      iVar8 = (uVar2 & 0x1f) * 8 + uVar3;
      iVar7 = iVar5 + 0xa600 + iVar8;
      if ((*(char *)(iVar7 + -0x20) != *(char *)(iVar7 + 0x1e0)) ||
         (iVar7 = iVar5 + 0xa600 + iVar8 + 1, *(char *)(iVar7 + -0x20) != *(char *)(iVar7 + 0x1e0)))
      {
        iVar1 = iVar1 + 1;
        iVar6 = 1;
      }
      uVar4 = uVar3 + 2;
      uVar3 = uVar4 & 0xff;
    } while ((char)uVar4 != '\b');
    uVar2 = uVar2 + 1 & 0xff;
    iVar9 = iVar9 + iVar6;
  } while (uVar2 != 0x10);
  return (iVar9 + iVar1 * 2 & 0xffffU) + (uint)*(ushort *)(iVar5 + 0xa9e0) <
         0x200U - *(int *)(*(int *)(iVar5 + 0xb8fc) + 0x74);
}

