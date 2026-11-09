/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14c58; aliases: rtl_fw_block_write
 */

void rtl_fw_block_write(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x40);
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    rtl_write_byte(uVar2,uVar1 + 0x1000,*(undefined1 *)(param_2 + uVar1));
  }
  return;
}

