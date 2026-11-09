/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11078; aliases: rtl_tx_ackqueue
 */

void rtl_tx_ackqueue(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  piVar2 = *(int **)(iVar1 + 0xb2d4);
  *param_2 = iVar1 + 0xb2d0;
  param_2[1] = (int)piVar2;
  *(int **)(iVar1 + 0xb2d4) = param_2;
  *piVar2 = (int)param_2;
  *(int *)(iVar1 + 0xb2d8) = *(int *)(iVar1 + 0xb2d8) + 1;
  return;
}

