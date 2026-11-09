/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16b8c; aliases: rtl_lps_set_psmode
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_lps_set_psmode(int param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte local_1d;
  
  iVar3 = *(int *)(param_1 + 0x40);
  uVar4 = (uint)param_2;
  local_1d = 0;
  if ((((*(int *)(iVar3 + 0x3f4) != 1) && (*(int *)(iVar3 + 0x4d0) == 2)) &&
      ((*(uint *)(iVar3 + 0xb2f0) != uVar4 || (uVar4 != 0)))) &&
     ((*(uint *)(iVar3 + 0xb2f0) = uVar4, *(char *)(iVar3 + 0xb2f6) != '\0' &&
      (*(char *)(iVar3 + 0xb2fb) != '\0')))) {
    if (uVar4 == 0) {
      *(ushort *)(iVar3 + 0xb36c) = (ushort)param_2;
      local_1d = param_2;
      (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x44,&local_1d);
      if (*(char *)(iVar3 + 0xb34e) != '\0') {
        rtl_p2p_ps_cmd(param_1,1);
      }
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104))();
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar3 + 0xb9ac) + 0x20))(iVar3,0);
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x40);
      uVar2 = (*(code *)&jiffies_to_msecs)(_jiffies - *(int *)(iVar1 + 0xb330));
      if (((uVar2 < 2000) || (*(int *)(iVar1 + 0x4d0) != 2)) || (*(int *)(iVar1 + 0x3f4) == 1)) {
        *(undefined4 *)(iVar3 + 0xb2f0) = 0;
      }
      else {
        iVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104))();
        if (iVar1 != 0) {
          (**(code **)(*(int *)(iVar3 + 0xb9ac) + 0x20))(iVar3,uVar4);
        }
        local_1d = 1;
        *(undefined1 *)(iVar3 + 0xb36c) = *(undefined1 *)(iVar3 + 0xb2f7);
        *(undefined1 *)(iVar3 + 0xb36d) = 2;
        (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x44,&local_1d);
      }
    }
  }
  return;
}

