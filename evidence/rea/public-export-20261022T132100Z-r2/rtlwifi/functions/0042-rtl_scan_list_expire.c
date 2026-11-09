/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12050; aliases: rtl_scan_list_expire
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_scan_list_expire(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *(int *)(param_1 + 0x40);
  uVar1 = arch_local_irq_save();
  piVar5 = *(int **)(iVar6 + 0xb2e0);
  piVar7 = (int *)**(int **)(iVar6 + 0xb2e0);
  while (piVar5 != (int *)(iVar6 + 0xb2e0)) {
    uVar2 = (*(code *)&jiffies_to_msecs)(_jiffies - piVar5[4]);
    if (179999 < uVar2) {
      piVar3 = (int *)piVar5[1];
      iVar4 = *piVar5;
      *(int **)(iVar4 + 4) = piVar3;
      *piVar3 = iVar4;
      *piVar5 = 0x100;
      piVar5[1] = 0x122;
      *(int *)(iVar6 + 0xb2dc) = *(int *)(iVar6 + 0xb2dc) + -1;
      (*(code *)&kfree)(piVar5);
    }
    piVar5 = piVar7;
    piVar7 = (int *)*piVar7;
  }
  Auxregs0028 = uVar1;
  *(char *)(iVar6 + 0xb9b4) = (char)*(undefined4 *)(iVar6 + 0xb2dc);
  return;
}

