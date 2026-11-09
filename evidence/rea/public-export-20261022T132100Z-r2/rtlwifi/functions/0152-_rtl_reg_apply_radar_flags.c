/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17768; aliases: _rtl_reg_apply_radar_flags
 */

void _rtl_reg_apply_radar_flags(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xd0);
  if (piVar3 == (int *)0x0) {
    return;
  }
  for (uVar2 = 0; uVar2 < (uint)piVar3[3]; uVar2 = uVar2 + 1) {
    iVar1 = *piVar3 + uVar2 * 0x38;
    if (((*(int *)(iVar1 + 4) - 0x148cU & 0xffff) < 0x1b9) && ((*(uint *)(iVar1 + 0xc) & 1) == 0)) {
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 10;
    }
  }
  return;
}

