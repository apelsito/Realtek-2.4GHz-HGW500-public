/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12a20; aliases: rtl_cam_reset_all_entry
 */

void rtl_cam_reset_all_entry(int param_1)

{
  rtl_write_dword(*(int *)(param_1 + 0x40),
                  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0x7c),0xc0000000);
  return;
}

