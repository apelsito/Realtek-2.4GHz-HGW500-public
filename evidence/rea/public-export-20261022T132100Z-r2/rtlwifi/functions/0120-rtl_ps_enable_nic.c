/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x161e0; aliases: rtl_ps_enable_nic
 */

undefined4 rtl_ps_enable_nic(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar3 + 0x68c) == 0) {
    (**(code **)(*(int *)(iVar3 + 0xb900) + 0x14))();
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x14))(param_1);
  if (iVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x35,iVar3 + 0x599);
    *(uint *)(iVar3 + 0xb304) = *(uint *)(iVar3 + 0xb304) & 0xfffffff7;
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x38))(param_1);
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x7c))(param_1);
    iVar1 = *(int *)(param_1 + 0x18);
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x34);
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        if (*(uint *)(*(int *)(param_1 + 0x14) + 4) < *(uint *)(param_1 + 0x1c)) {
          iVar1 = 3;
        }
      }
      else {
        if (iVar1 != 0) {
          (*(code *)&warn_slowpath_fmt)("include/net/cfg80211.h",0x30c,9,0);
        }
        iVar1 = 0;
      }
    }
    (*pcVar4)(param_1,iVar1);
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x24))(param_1);
    rtl_watch_dog_timer_callback(iVar3 + 0x4c);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

