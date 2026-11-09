/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11b8c; aliases: rtl92ee_download_fw
 */

undefined4 rtl92ee_download_fw(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *puVar5;
  int iVar6;
  char local_21;
  
  iVar3 = *(int *)(param_1 + 0x40);
  iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  puVar5 = *(ushort **)(iVar3 + 0x6b0);
  if (puVar5 == (ushort *)0x0) {
    uVar4 = 1;
  }
  else {
    iVar6 = *(int *)(iVar3 + 0x6ac);
    *(ushort *)(iVar3 + 0x6b4) = puVar5[2];
    *(ushort *)(iVar3 + 0x6b6) = (ushort)(byte)puVar5[3];
    if ((*puVar5 & 0xfff0) == 0x92e0) {
      puVar5 = puVar5 + 0x10;
      iVar6 = iVar6 + -0x20;
    }
    if ((*(char *)(iVar3 + 0x631) != '\0') &&
       (uVar2 = rtl_read_byte(iVar3,0x80), (uVar2 & 0x80) != 0)) {
      rtl_write_byte(iVar3,0x80,0);
      rtl92ee_firmware_selfreset(param_1);
    }
    if ((iVar1 != 0) && (uVar2 = rtl_read_dword(iVar3,0x80), (~uVar2 & 0x42) == 0)) {
      (*(code *)&printk)(&DAT_ram_0001cd68,uVar2);
      _rtl92ee_mitrastar_fw_cleanup(param_1,0);
    }
    _rtl92ee_mitrastar_fw_snapshot_isra_0(*(undefined4 *)(param_1 + 0x40),"attempt-start",0);
    iVar3 = _rtl92ee_download_fw_once_isra_0(param_1,puVar5,iVar6,&local_21);
    _rtl92ee_mitrastar_fw_snapshot_isra_0(*(undefined4 *)(param_1 + 0x40),"attempt-result",0);
    uVar4 = 0;
    if (iVar3 != 0) {
      if ((iVar1 == 0) || (local_21 == '\0')) {
        uVar4 = 0xfffffffb;
      }
      else {
        (*(code *)&printk)(&DAT_ram_0001cdd8);
        _rtl92ee_mitrastar_fw_cleanup(param_1,1);
        uVar4 = _rtl92ee_download_fw_once_isra_0(param_1,puVar5,iVar6,&local_21);
        _rtl92ee_mitrastar_fw_snapshot_isra_0(*(undefined4 *)(param_1 + 0x40),"attempt-result",1);
      }
    }
  }
  return uVar4;
}

