/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x125ec; aliases: rtl_c2hcmd_wq_callback
 */

void rtl_c2hcmd_wq_callback(int param_1)

{
  rtl_c2hcmd_launcher(*(undefined4 *)(param_1 + -0xf8),1);
  return;
}

