/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x177a4; aliases: _rtl_reg_apply_beaconing_flags
 */

void _rtl_reg_apply_beaconing_flags(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 5;
  iVar4 = 0;
  do {
    piVar6 = *(int **)(param_1 + iVar4 * 4 + 0xcc);
    if (piVar6 != (int *)0x0) {
      for (uVar3 = 0; uVar3 < (uint)piVar6[3]; uVar3 = uVar3 + 1) {
        iVar2 = *piVar6 + uVar3 * 0x38;
        if ((0x1b8 < (*(int *)(iVar2 + 4) - 0x148cU & 0xffff)) &&
           (uVar1 = *(uint *)(iVar2 + 0xc), (uVar1 & 8) == 0)) {
          if (param_2 == 3) {
            uVar1 = (*(code *)&freq_reg_info)(param_1);
            if ((uVar1 < 0xfffff001) && ((*(uint *)(uVar1 + 0x54) & 0x80) == 0)) {
              uVar1 = *(uint *)(iVar2 + 0xc);
LAB_ram_00017846:
              *(uint *)(iVar2 + 0xc) = uVar1 & 0xfffffffd;
            }
          }
          else if (*(char *)(iVar2 + 0x1c) != '\0') goto LAB_ram_00017846;
        }
      }
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + 1;
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

