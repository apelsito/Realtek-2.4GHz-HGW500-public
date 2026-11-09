/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16010; aliases: efuse_shadow_write
 */

void efuse_shadow_write(int param_1,char param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  
  param_3 = param_3 & 0xffff;
  if (param_2 == '\x01') {
    puVar1 = (undefined1 *)(*(int *)(param_1 + 0x40) + param_3 + 0xa7e0);
    uVar3 = param_4;
  }
  else if (param_2 == '\x02') {
    iVar2 = *(int *)(param_1 + 0x40) + 0xa600 + param_3;
    *(char *)(iVar2 + 0x1e0) = (char)param_4;
    puVar1 = (undefined1 *)(iVar2 + 0x1e1);
    uVar3 = param_4 >> 8;
  }
  else {
    if (param_2 != '\x04') {
      return;
    }
    iVar2 = *(int *)(param_1 + 0x40) + 0xa600 + param_3;
    *(char *)(iVar2 + 0x1e0) = (char)param_4;
    *(char *)(iVar2 + 0x1e1) = (char)(param_4 >> 8);
    uVar3 = param_4 >> 0x18;
    *(char *)(iVar2 + 0x1e2) = (char)(param_4 >> 0x10);
    puVar1 = (undefined1 *)(iVar2 + 0x1e3);
  }
  *puVar1 = (char)uVar3;
  return;
}

