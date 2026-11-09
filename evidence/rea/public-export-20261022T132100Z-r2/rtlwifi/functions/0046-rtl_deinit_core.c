/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x125fc; aliases: rtl_deinit_core
 */

void rtl_deinit_core(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0x40);
  rtl_c2hcmd_launcher(param_1,0);
  iVar6 = *(int *)(param_1 + 0x40);
  piVar1 = *(int **)(iVar6 + 0xb2e0);
  piVar4 = (int *)**(int **)(iVar6 + 0xb2e0);
  while (piVar1 != (int *)(iVar6 + 0xb2e0)) {
    piVar2 = (int *)piVar1[1];
    iVar3 = *piVar1;
    *(int **)(iVar3 + 4) = piVar2;
    *piVar2 = iVar3;
    *piVar1 = 0x100;
    piVar1[1] = 0x122;
    (*(code *)&kfree)();
    *(int *)(iVar6 + 0xb2dc) = *(int *)(iVar6 + 0xb2dc) + -1;
    piVar1 = piVar4;
    piVar4 = (int *)*piVar4;
  }
  rtl_free_entries_from_ack_queue(param_1,0);
  if (*(int *)(iVar5 + 0xe4) != 0) {
    (*(code *)&destroy_workqueue)();
    *(undefined4 *)(iVar5 + 0xe4) = 0;
  }
  return;
}

