/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1873c; aliases: __udelay.constprop.0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __udelay_constprop_0(void)

{
  int iVar1;
  
  iVar1 = (int)((ulonglong)_loops_per_jiffy * 0x68dbc >> 0x20);
  _DAT_auxregs_0008 = 0x18754;
  _DAT_auxregs_000c = 0x18758;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

