/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11f44; aliases: rtl_tx_agg_stop
 */

undefined4 rtl_tx_agg_stop(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  if ((param_3 != 0) && ((param_4 & 0xffff) < 9)) {
    *(undefined1 *)(param_3 + (param_4 & 0xffff) * 0x18 + 0x124) = 0;
    (*(code *)&ieee80211_stop_tx_ba_cb_irqsafe)(param_2,param_3 + 0x14);
    return 0;
  }
  return 0xffffffea;
}

