/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1202c; aliases: rtl_tx_agg_oper
 */

undefined4 rtl_tx_agg_oper(undefined4 param_1,int param_2,uint param_3)

{
  if ((param_2 != 0) && ((param_3 & 0xffff) < 9)) {
    *(undefined1 *)(param_2 + (param_3 & 0xffff) * 0x18 + 0x124) = 3;
    return 0;
  }
  return 0xffffffea;
}

