/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b560; aliases: _rtl92ee_mitrastar_fw_cleanup
 */

/* WARNING: Control flow encountered bad instruction data */

void _rtl92ee_mitrastar_fw_cleanup(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  _rtl92ee_mitrastar_fw_snapshot_isra_0(iVar2,"cleanup-before",param_2);
  _rtl92ee_enable_fw_download_isra_0(*(undefined4 *)(param_1 + 0x40),0);
  rtl_write_dword(iVar2,0x80,0);
  rtl92ee_firmware_selfreset(param_1);
  rtl_write_dword(iVar2,0x80,0);
  *(undefined1 *)(iVar2 + 0x6ba) = 0;
  *(undefined1 *)(iVar2 + 0x6b9) = 0;
  __udelay(0x32);
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2","cleanup-after",param_2);
  if (iVar2 == 0) {
    return;
  }
  rtl_read_dword(iVar1,0x80);
  (**(code **)(iVar1 + 0x754))(iVar1,2);
  (**(code **)(iVar1 + 0x754))(iVar1,0x1c);
  rtl_read_dword(iVar1,0x100);
  rtl_read_byte(iVar1,0x1cc);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

