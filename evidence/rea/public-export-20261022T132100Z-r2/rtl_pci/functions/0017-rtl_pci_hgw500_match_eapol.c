/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x104d0; aliases: rtl_pci_hgw500_match_eapol
 */

undefined4 rtl_pci_hgw500_match_eapol(int param_1,int param_2,uint param_3,undefined2 *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar2 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
  if ((((((iVar2 == 0) || (*(short *)(*(int *)(param_1 + 0x40) + 0x690) != 0xc)) ||
        ((param_3 & 0xc) != 8)) ||
       ((iVar2 = (*(code *)&ieee80211_hdrlen)(param_3), *(uint *)(param_2 + 0x50) < iVar2 + 0xcU ||
        (pcVar4 = (char *)(*(int *)(param_2 + 0xbc) + iVar2), *pcVar4 != -0x56)))) ||
      ((pcVar4[1] != -0x56 || ((pcVar4[2] != '\x03' || (pcVar4[3] != '\0')))))) ||
     ((pcVar4[4] != '\0' || ((pcVar4[5] != '\0' || (*(short *)(pcVar4 + 6) != -0x7178)))))) {
    uVar3 = 0;
  }
  else {
    (*(code *)&memset)(param_4,0,0xc);
    *param_4 = (short)iVar2;
    *(char *)(param_4 + 2) = pcVar4[8];
    cVar1 = pcVar4[9];
    *(char *)((int)param_4 + 5) = cVar1;
    param_4[1] = (ushort)(byte)pcVar4[0xb] + (ushort)(byte)pcVar4[10] * 0x100;
    if ((iVar2 + 0x11U <= *(uint *)(param_2 + 0x50)) && (cVar1 == '\x03')) {
      *(char *)(param_4 + 3) = pcVar4[0xc];
      param_4[4] = (ushort)(byte)pcVar4[0xe] + (ushort)(byte)pcVar4[0xd] * 0x100;
      param_4[5] = (ushort)(byte)pcVar4[0x10] + (ushort)(byte)pcVar4[0xf] * 0x100;
    }
    uVar3 = 1;
  }
  return uVar3;
}

