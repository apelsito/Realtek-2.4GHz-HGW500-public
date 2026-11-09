/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x103c8; aliases: rtl_tx_report_handler
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_tx_report_handler(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)(param_1 + 0x40);
  bVar1 = param_2[6];
  if ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0x18) & 4) == 0) {
    bVar2 = *param_2;
  }
  else {
    bVar2 = param_2[7];
  }
  *(ushort *)(iVar4 + 0xb2cc) = (ushort)bVar1;
  piVar5 = *(int **)(iVar4 + 0xb2d0);
  while( true ) {
    if (piVar5 == (int *)(iVar4 + 0xb2d0)) {
      return;
    }
    if (piVar5[0xe] == (uint)bVar1) break;
    piVar5 = (int *)*piVar5;
  }
  (*(code *)&skb_unlink)(piVar5,iVar4 + 0xb2d0);
  ieee80211_tx_info_clear_status(piVar5 + 6);
  if ((bVar2 & 0xc0) == 0) {
    uVar3 = piVar5[6] | 0x200;
  }
  else {
    uVar3 = piVar5[6] & 0xfffffdff;
  }
  piVar5[6] = uVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

