/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10020; aliases: rtl_init_rx_config
 */

void rtl_init_rx_config(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00010038. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0x4c))
            (param_1,0x2c,*(int *)(param_1 + 0x40) + 0x4e0);
  return;
}

