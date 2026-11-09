/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11e98; aliases: rtl_check_tx_report_acked
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint rtl_check_tx_report_acked(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(short *)(iVar1 + 0xb2c4) != *(short *)(iVar1 + 0xb2cc)) {
    return (uint)((300 - _jiffies) + *(int *)(iVar1 + 0xb2c8)) >> 0x1f;
  }
  return 1;
}

