/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12008; aliases: rtl_rx_agg_stop
 */

undefined4 rtl_rx_agg_stop(undefined4 param_1,int param_2,uint param_3)

{
  if ((param_2 != 0) && ((param_3 & 0xffff) < 9)) {
    *(undefined1 *)(param_2 + (param_3 & 0xffff) * 0x18 + 0x125) = 0;
    return 0;
  }
  return 0xffffffea;
}

