/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15594; aliases: read_efuse_byte
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void read_efuse_byte(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  
  iVar4 = *(int *)(param_1 + 0x40);
  rtl_write_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 1,param_2 & 0xff);
  uVar2 = rtl_read_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 2);
  sVar5 = 0;
  rtl_write_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 2,uVar2 & 0xfc | param_2 >> 8 & 3
                );
  uVar2 = rtl_read_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 3);
  rtl_write_byte(iVar4,*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x4c) + 3,uVar2 & 0x7f);
  iVar3 = (**(code **)(iVar4 + 0x758))(iVar4,*(undefined4 *)(*(int *)(iVar4 + 0xb8fc) + 0x4c));
  while( true ) {
    if ((iVar3 < 0) || (sVar5 == 10000)) break;
    sVar5 = sVar5 + 1;
    iVar3 = (**(code **)(iVar4 + 0x758))(iVar4,*(undefined4 *)(*(int *)(iVar4 + 0xb8fc) + 0x4c));
  }
  iVar3 = (int)((ulonglong)_loops_per_jiffy * 0x147aeb8 >> 0x20);
  _DAT_auxregs_0008 = 0x1566a;
  _DAT_auxregs_000c = 0x1566e;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = (**(code **)(iVar4 + 0x758))(iVar4);
  *param_3 = uVar1;
  return;
}

