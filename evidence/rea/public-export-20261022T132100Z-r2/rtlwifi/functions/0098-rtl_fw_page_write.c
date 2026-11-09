/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14ca0; aliases: rtl_fw_page_write
 */

void rtl_fw_page_write(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x40);
  uVar1 = rtl_read_byte(uVar2,0x82);
  rtl_write_byte(uVar2,0x82,param_2 & 7 | uVar1 & 0xf8);
  rtl_fw_block_write(param_1,param_3,param_4);
  return;
}

