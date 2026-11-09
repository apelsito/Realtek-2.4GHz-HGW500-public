/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12548; aliases: rtl_c2hcmd_launcher
 */

void rtl_c2hcmd_launcher(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x40);
  iVar5 = 0;
  while( true ) {
    uVar1 = arch_local_irq_save();
    piVar4 = *(int **)(iVar6 + 0xb8d4);
    if (piVar4 == (int *)(iVar6 + 0xb8d4)) {
      piVar4 = (int *)0x0;
    }
    else if (piVar4 != (int *)0x0) {
      *(int *)(iVar6 + 0xb8dc) = *(int *)(iVar6 + 0xb8dc) + -1;
      iVar3 = *piVar4;
      piVar2 = (int *)piVar4[1];
      *piVar4 = 0;
      piVar4[1] = 0;
      *(int **)(iVar3 + 4) = piVar2;
      *piVar2 = iVar3;
    }
    Auxregs0028 = uVar1;
    if (piVar4 == (int *)0x0) break;
    iVar5 = iVar5 + 1;
    if (param_2 != 0) {
      rtl_c2h_content_parsing(param_1,piVar4);
    }
    (*(code *)&__dev_kfree_skb_any)(piVar4,1);
    if (iVar5 == 200) {
      return;
    }
  }
  return;
}

