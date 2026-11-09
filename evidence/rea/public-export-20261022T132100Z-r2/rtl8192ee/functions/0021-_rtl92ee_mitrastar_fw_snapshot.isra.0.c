/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x115dc; aliases: _rtl92ee_mitrastar_fw_snapshot.isra.0
 */

/* WARNING: Control flow encountered bad instruction data */

void _rtl92ee_mitrastar_fw_snapshot_isra_0(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  if (iVar1 != 0) {
    rtl_read_dword(param_1,0x80);
    (**(code **)(param_1 + 0x754))(param_1,2);
    (**(code **)(param_1 + 0x754))(param_1,0x1c);
    rtl_read_dword(param_1,0x100);
    rtl_read_byte(param_1,0x1cc);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

