/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1052c; aliases: rtl_collect_scan_list
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_collect_scan_list(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  ushort *puVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar7 + 0x4ea) != '\0') {
    puVar6 = *(ushort **)(param_2 + 0xbc);
    if (((*puVar6 & 0xfc) == 0x80) || ((*puVar6 & 0xfc) == 0x50)) {
      uVar1 = arch_local_irq_save();
      for (piVar5 = *(int **)(iVar7 + 0xb2e0); piVar5 != (int *)(iVar7 + 0xb2e0);
          piVar5 = (int *)*piVar5) {
        iVar2 = (*(code *)&memcmp)(piVar5 + 2,puVar6 + 8,6);
        if (iVar2 == 0) {
          piVar3 = (int *)piVar5[1];
          iVar2 = *piVar5;
          *(int **)(iVar2 + 4) = piVar3;
          *piVar3 = iVar2;
          *piVar5 = (int)piVar5;
          piVar5[1] = (int)piVar5;
          if (piVar5 != (int *)0x0) goto code_r0x000105ee;
          break;
        }
      }
      piVar5 = (int *)(*(code *)&kmem_cache_alloc)(_DAT_ram_0f00026c,0xa20);
      if (piVar5 != (int *)0x0) {
        (*(code *)&memcpy)(piVar5 + 2,puVar6 + 8,6);
        *(int *)(iVar7 + 0xb2dc) = *(int *)(iVar7 + 0xb2dc) + 1;
code_r0x000105ee:
        piVar5[4] = _jiffies;
        puVar4 = *(undefined4 **)(iVar7 + 0xb2e4);
        *(int **)(iVar7 + 0xb2e4) = piVar5;
        *piVar5 = iVar7 + 0xb2e0;
        piVar5[1] = (int)puVar4;
        *puVar4 = piVar5;
      }
      Auxregs0028 = uVar1;
    }
  }
  return;
}

