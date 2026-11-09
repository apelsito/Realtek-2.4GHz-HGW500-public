/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12e14; aliases: rtl_op_configure_filter
 */

void rtl_op_configure_filter(int param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *param_3;
  iVar3 = *(int *)(param_1 + 0x40);
  *param_3 = uVar4 & 0x76;
  if (param_2 == 0) {
    return;
  }
  if ((param_2 & 2) == 0) {
    bVar1 = false;
  }
  else {
    uVar2 = *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x28) | *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x2c);
    if ((uVar4 & 2) == 0) {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) & ~uVar2;
    }
    else {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) | uVar2;
    }
    bVar1 = true;
  }
  if ((param_2 & 4) != 0) {
    uVar4 = *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x30);
    if ((*param_3 & 4) == 0) {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) & ~uVar4;
    }
    else {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) | uVar4;
    }
    bVar1 = true;
  }
  if ((((param_2 & 0x10) != 0) && (1 < *(uint *)(iVar3 + 0x4d0))) &&
     ((*(uint *)(iVar3 + 0x3f4) & 0xfffffffb) != 3)) {
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x30))(param_1,(*param_3 & 0x10) == 0);
    bVar1 = false;
  }
  if ((param_2 & 0x20) != 0) {
    uVar4 = *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x34);
    if ((*param_3 & 0x20) == 0) {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) & ~uVar4;
    }
    else {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) | uVar4;
    }
    bVar1 = true;
  }
  if ((param_2 & 0x40) == 0) {
    if (!bVar1) {
      return;
    }
  }
  else {
    uVar4 = *(uint *)(*(int *)(iVar3 + 0xb8fc) + 0x38);
    if ((*param_3 & 0x40) == 0) {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) & ~uVar4;
    }
    else {
      *(uint *)(iVar3 + 0x4e0) = *(uint *)(iVar3 + 0x4e0) | uVar4;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00012f5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x2c,iVar3 + 0x4e0);
  return;
}

