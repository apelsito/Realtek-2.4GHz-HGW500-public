/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1106c; aliases: rtl_pci_tx_chk_waitq_insert
 */

char rtl_pci_tx_chk_waitq_insert(int param_1,int param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  
  puVar4 = *(ushort **)(param_3 + 0xbc);
  uVar2 = *puVar4;
  if ((~uVar2 & 0x300) == 0) {
    puVar4 = puVar4 + 0xf;
  }
  else {
    puVar4 = puVar4 + 0xc;
  }
  if ((((param_2 != 0) && (iVar6 = *(int *)(param_1 + 0x40), *(char *)(iVar6 + 0x6e1) != '\0')) &&
      ((uVar2 & 0x7c) != 0x48)) && ((uVar2 & 0xfc) != 0xa4)) {
    uVar2 = *puVar4;
    uVar5 = (byte)uVar2 & 0xf;
    if (((*(char *)(param_2 + uVar5 * 0x18 + 0x124) == '\x03') &&
        (uVar3 = _rtl_mac_to_hwqueue(param_1,param_3), uVar3 < 4)) &&
       ((((byte)uVar2 & 8) == 0 && (cVar1 = *(char *)(iVar6 + uVar5 + 0xb884), cVar1 != '\0')))) {
      *(int *)(((uint)&stack0xffffffec & 0xffffe000) + 4) =
           *(int *)(((uint)&stack0xffffffec & 0xffffe000) + 4) + 0x200;
      (*(code *)&skb_queue_tail)(uVar5 * 0xc + 0x4f0 + iVar6,param_3);
      (*(code *)&__local_bh_enable_ip)(0x1110c,0x200);
      return cVar1;
    }
  }
  return '\0';
}

