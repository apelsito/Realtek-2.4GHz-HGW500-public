/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x110e0; aliases: rtl_free_entries_from_ack_queue
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_free_entries_from_ack_queue(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40) + 0xb2d0;
  piVar1 = *(int **)(*(int *)(param_1 + 0x40) + 0xb2d0);
  piVar2 = (int *)*piVar1;
  while (piVar1 != (int *)iVar3) {
    if ((param_2 == 0) || (-1 < (_jiffies + -100) - piVar1[0xf])) {
      (*(code *)&skb_unlink)(piVar1,iVar3);
      ieee80211_tx_info_clear_status(piVar1 + 6);
      piVar1[6] = piVar1[6] & 0xfffffdff;
      (*(code *)&ieee80211_tx_status_irqsafe)(param_1,piVar1);
    }
    piVar1 = piVar2;
    piVar2 = (int *)*piVar2;
  }
  return;
}

