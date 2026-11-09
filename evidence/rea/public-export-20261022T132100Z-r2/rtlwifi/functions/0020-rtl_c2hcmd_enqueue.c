/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x109ac; aliases: rtl_c2hcmd_enqueue
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_c2hcmd_enqueue(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)param_2[0x2f] == '\v') {
    rtl_c2h_content_parsing();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar3 = *(int *)(param_1 + 0x40);
  uVar1 = arch_local_irq_save();
  piVar2 = *(int **)(iVar3 + 0xb8d8);
  *param_2 = iVar3 + 0xb8d4;
  param_2[1] = (int)piVar2;
  *(int **)(iVar3 + 0xb8d8) = param_2;
  *piVar2 = (int)param_2;
  *(int *)(iVar3 + 0xb8dc) = *(int *)(iVar3 + 0xb8dc) + 1;
  Auxregs0028 = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

