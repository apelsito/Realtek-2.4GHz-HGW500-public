/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15038; aliases: efuse_shadow_read
 */

void efuse_shadow_read(int param_1,char param_2,uint param_3,uint *param_4)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  
  param_3 = param_3 & 0xffff;
  if (param_2 == '\x01') {
    *(undefined1 *)param_4 = *(undefined1 *)(*(int *)(param_1 + 0x40) + param_3 + 0xa7e0);
    return;
  }
  if (param_2 == '\x02') {
    iVar4 = *(int *)(param_1 + 0x40) + 0xa600 + param_3;
    bVar1 = *(byte *)(iVar4 + 0x1e0);
    *(ushort *)param_4 = (ushort)bVar1;
    *(ushort *)param_4 = CONCAT11(*(undefined1 *)(iVar4 + 0x1e1),bVar1);
    return;
  }
  if (param_2 != '\x04') {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x40) + 0xa600 + param_3;
  bVar1 = *(byte *)(iVar4 + 0x1e0);
  *param_4 = (uint)bVar1;
  uVar2 = CONCAT11(*(undefined1 *)(iVar4 + 0x1e1),bVar1);
  *param_4 = (uint)uVar2;
  uVar3 = CONCAT12(*(undefined1 *)(iVar4 + 0x1e2),uVar2);
  *param_4 = (uint)uVar3;
  *param_4 = CONCAT13(*(undefined1 *)(iVar4 + 0x1e3),uVar3);
  return;
}

