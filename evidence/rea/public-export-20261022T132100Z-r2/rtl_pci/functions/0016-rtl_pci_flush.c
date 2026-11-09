/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1043c; aliases: rtl_pci_flush
 */

void rtl_pci_flush(int param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar3 + 0x4ec) == '\0') {
    iVar1 = 8;
    uVar2 = 0;
    do {
      if ((((param_2 & 1 << ((byte)iVar1 & 0x1f)) == 0) ||
          (*(int *)(iVar3 + iVar1 * 0x2c + 0xbab8) == 0)) || (iVar1 - 4U < 2)) {
        iVar1 = iVar1 + -1;
      }
      else {
        (*(code *)&msleep)(0x14);
        if (*(int *)(iVar3 + 0xb314) == 2) {
          return;
        }
        if (*(char *)(iVar3 + 0x698) == '\0') {
          return;
        }
        uVar2 = uVar2 + 1;
        if (199 < uVar2) {
          return;
        }
      }
    } while (iVar1 != -1);
  }
  return;
}

