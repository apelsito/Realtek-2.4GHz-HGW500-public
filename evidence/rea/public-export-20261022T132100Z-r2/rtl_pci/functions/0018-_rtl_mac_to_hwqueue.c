/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x105e8; aliases: _rtl_mac_to_hwqueue
 */

undefined1 _rtl_mac_to_hwqueue(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_28 [12];
  
  uVar1 = **(ushort **)(param_2 + 0xbc);
  if ((uVar1 & 0xfc) == 0x80) {
    return 4;
  }
  if ((uVar1 & 8) == 0) {
    return 6;
  }
  iVar5 = *(int *)(param_1 + 0x40);
  uVar2 = *(ushort *)(param_2 + 0x5c);
  if (hgw500_eapol_mgnt_queue != '\0') {
    (*(code *)&memset)(auStack_28,0,0xc);
    iVar4 = rtl_pci_hgw500_match_eapol(param_1,param_2,uVar1,auStack_28);
    if (iVar4 != 0) {
      if (__print_once_24 != '\0') {
        return 6;
      }
      __print_once_24 = 1;
      (*(code *)&printk)(&DAT_ram_00014c34);
      return 6;
    }
  }
  sVar3 = *(short *)(iVar5 + 0x690);
  if (sVar3 == 2) {
    if ((uVar1 & 0xfc) != 0x48) {
LAB_ram_000106b2:
      return *(undefined1 *)((int)&ac_to_hwq + (uVar2 & 0xff));
    }
  }
  else if ((sVar3 != 0xf) || ((*(byte *)(*(int *)(param_2 + 0xbc) + 4) & 1) == 0))
  goto LAB_ram_000106b2;
  return 7;
}

