/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14758; aliases: rtl_rfreg_delay
 */

void rtl_rfreg_delay(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 - 0xf9U < 6) {
    rtl_addr_delay(param_3);
    return;
  }
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xc0))();
  __udelay(1);
  return;
}

