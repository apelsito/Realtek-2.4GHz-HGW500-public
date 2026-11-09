/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12dd8; aliases: __udelay
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __udelay(uint param_1)

{
  int iVar1;
  
  iVar1 = (int)((ulonglong)_loops_per_jiffy * (ulonglong)param_1 >> 0x20) * 0x68dbc +
          (int)((ulonglong)(_loops_per_jiffy * param_1) * 0x68dbc >> 0x20);
  _DAT_auxregs_0008 = 0x12e0c;
  _DAT_auxregs_000c = 0x12e10;
  do {
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

