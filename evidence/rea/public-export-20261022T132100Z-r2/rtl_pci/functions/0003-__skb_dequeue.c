/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10028; aliases: __skb_dequeue
 */

int * __skb_dequeue(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)*param_1;
  if (param_1 == piVar2) {
    piVar2 = (int *)0x0;
  }
  else if (piVar2 != (int *)0x0) {
    param_1[2] = param_1[2] + -1;
    iVar3 = *piVar2;
    piVar1 = (int *)piVar2[1];
    *piVar2 = 0;
    piVar2[1] = 0;
    *(int **)(iVar3 + 4) = piVar1;
    *piVar1 = iVar3;
  }
  return piVar2;
}

