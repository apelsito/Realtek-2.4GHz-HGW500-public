/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14798; aliases: rtl_bb_delay
 */

void rtl_bb_delay(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 - 0xf9U < 6) {
    rtl_addr_delay(param_2);
    return;
  }
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xb8))
            (param_1,param_2,0xffffffff,param_3);
  __udelay(1);
  return;
}

