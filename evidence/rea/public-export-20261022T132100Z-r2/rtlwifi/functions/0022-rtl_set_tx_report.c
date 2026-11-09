/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10cf4; aliases: rtl_set_tx_report
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_set_tx_report(int param_1,int param_2,int param_3,uint *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(byte *)(param_1 + 3) & 0x10) == 0) {
    return;
  }
  iVar5 = *(int *)(param_3 + 0x40);
  uVar2 = arch_local_irq_save();
  iVar4 = *(int *)(iVar5 + 0xb2c0) + 1;
  *(int *)(iVar5 + 0xb2c0) = iVar4;
  uVar1 = _jiffies;
  Auxregs0028 = uVar2;
  uVar3 = iVar4 * 4 & 0xff;
  *(short *)(iVar5 + 0xb2c4) = (short)uVar3;
  *(undefined4 *)(iVar5 + 0xb2c8) = uVar1;
  *param_4 = uVar3;
  param_4[1] = *(uint *)(iVar5 + 0xb2c8);
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x80000;
  *(uint *)(param_2 + 0x18) = uVar3 | *(uint *)(param_2 + 0x18) & 0xfffff000;
  return;
}

