/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11edc; aliases: rtl92ee_set_fw_media_status_rpt_cmd
 */

void rtl92ee_set_fw_media_status_rpt_cmd(undefined4 param_1,byte param_2)

{
  ushort local_8;
  undefined1 local_6;
  
  local_6 = 0;
  local_8 = param_2 & 0xff01;
  rtl92ee_fill_h2c_cmd(param_1,1,3,&local_8);
  return;
}

