/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16330; aliases: rtl_ps_set_rf_state.isra.0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_ps_set_rf_state_isra_0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x40);
  uVar3 = 0;
  while (*(char *)(iVar2 + 0xb2ea) != '\0') {
    while (*(char *)(iVar2 + 0xb2ea) != '\0') {
      uVar3 = uVar3 + 1;
      _DAT_auxregs_0008 = 0x16374;
      _DAT_auxregs_000c = 91000;
      iVar4 = (int)((ulonglong)_loops_per_jiffy * 0x1999a660 >> 0x20);
      do {
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (100 < uVar3) {
        _DAT_auxregs_0008 = 0x16374;
        _DAT_auxregs_000c = 91000;
        return;
      }
    }
  }
  *(undefined1 *)(iVar2 + 0xb2ea) = 1;
  if ((param_2 == 1) || (param_2 == 2)) {
    *(uint *)(iVar2 + 0xb300) = param_3 | *(uint *)(iVar2 + 0xb300);
  }
  else {
    if (param_2 != 0) {
      (*(code *)&printk)(&DAT_ram_0001a1bc);
      goto LAB_ram_000163ae;
    }
    uVar1 = *(uint *)(iVar2 + 0xb300) & ~param_3;
    *(uint *)(iVar2 + 0xb300) = uVar1;
    if (uVar1 != 0) goto LAB_ram_000163ae;
  }
  (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x8c))();
LAB_ram_000163ae:
  *(undefined1 *)(iVar2 + 0xb2ea) = 0;
  return;
}

