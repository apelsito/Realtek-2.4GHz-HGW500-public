/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12a3c; aliases: rtl_cam_mark_invalid
 */

void rtl_cam_mark_invalid(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x40);
  iVar1 = *(int *)(iVar5 + 0xa3d0);
  iVar2 = *(int *)(iVar5 + 0xb8fc);
  if (iVar1 == 2) {
    uVar4 = *(uint *)(iVar2 + 0x98);
  }
  else if (iVar1 == 5) {
    uVar4 = *(uint *)(iVar2 + 0xa0);
  }
  else if (iVar1 == 1) {
    uVar4 = *(uint *)(iVar2 + 0x94);
  }
  else {
    uVar4 = *(uint *)(iVar2 + 0x9c);
  }
  rtl_write_dword(iVar5,*(undefined4 *)(iVar2 + 0x80),(uVar4 & 0xffff) << 2 | param_2 & 3 | 0x8000);
  uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0xb8fc) + 0x7c);
  (**(code **)(iVar5 + 0x748))(iVar5,uVar3,(param_2 & 0xff) << 3 | 0x80010000);
  if (*(char *)(*(int *)(iVar5 + 0xb8fc) + 1) == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000129bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar5 + 0x758))(iVar5,uVar3);
  return;
}

