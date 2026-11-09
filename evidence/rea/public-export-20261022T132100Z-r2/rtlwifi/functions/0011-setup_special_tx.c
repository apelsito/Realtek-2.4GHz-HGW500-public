/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1030c; aliases: setup_special_tx
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void setup_special_tx(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  *(undefined1 *)(param_1 + 0x2cf2) = 1;
  iVar1 = (**(code **)(*(int *)(param_1[0x2e3f] + 0xc) + 0x104))();
  if (iVar1 != 0) {
    (**(code **)(param_1[0x2e6b] + 0x50))(param_1,param_3);
  }
  rtl_lps_leave(uVar2,0);
  *(undefined4 *)(param_2 + 0x48) = _jiffies;
  return;
}

