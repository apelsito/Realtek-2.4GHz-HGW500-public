/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13168; aliases: _rtl92ee_stop_tx_beacon.isra.0
 */

void _rtl92ee_stop_tx_beacon_isra_0(int param_1)

{
  uint uVar1;
  
  uVar1 = rtl_read_byte(param_1,0x422);
  rtl_write_byte(param_1,0x422,uVar1 & 0xbf);
  rtl_write_byte(param_1,0x541,100);
  uVar1 = rtl_read_byte(param_1,0x542);
  (**(code **)(param_1 + 0x740))(param_1,0x542,uVar1 & 0xfe);
  if (*(char *)(*(int *)(param_1 + 0xb8fc) + 1) == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00012d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x750))(param_1,0x542);
  return;
}

