/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11584; aliases: _rtl92ee_enable_fw_download.isra.0
 */

void _rtl92ee_enable_fw_download_isra_0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar1 = rtl_read_byte(param_1,0x80);
    uVar2 = 0x80;
    uVar1 = uVar1 & 0xfe;
  }
  else {
    rtl_write_byte(param_1,0x80,5);
    uVar1 = rtl_read_byte(param_1,0x82);
    uVar2 = 0x82;
    uVar1 = uVar1 & 0xf7;
  }
  (**(code **)(param_1 + 0x740))(param_1,uVar2,uVar1);
  if (*(char *)(*(int *)(param_1 + 0xb8fc) + 1) == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00011528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x750))(param_1,uVar2);
  return;
}

