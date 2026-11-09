/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11f14; aliases: rtl_tx_agg_start
 */

undefined4 rtl_tx_agg_start(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  if ((param_3 != 0) && ((param_4 & 0xffff) < 9)) {
    if (param_3 != -0x108) {
      *(undefined1 *)(param_3 + (param_4 & 0xffff) * 0x18 + 0x124) = 2;
      return 1;
    }
    return 0xfffffffa;
  }
  return 0xffffffea;
}

