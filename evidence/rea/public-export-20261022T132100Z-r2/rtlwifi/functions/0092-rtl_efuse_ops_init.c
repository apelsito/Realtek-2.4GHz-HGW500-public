/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x149d4; aliases: rtl_efuse_ops_init
 */

void rtl_efuse_ops_init(int param_1)

{
  *(undefined ***)(*(int *)(param_1 + 0x40) + 0xa5d8) = &efuse_ops;
  return;
}

