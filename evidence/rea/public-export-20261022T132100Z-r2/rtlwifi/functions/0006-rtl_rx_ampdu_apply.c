/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10178; aliases: rtl_rx_ampdu_apply
 */

void rtl_rx_ampdu_apply(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_f;
  char local_e;
  byte local_d;
  
  local_f = 0;
  local_e = '\0';
  local_d = 0;
  iVar3 = param_1[0x2e6b];
  iVar2 = (**(code **)(*(int *)(param_1[0x2e3f] + 0xc) + 0x104))();
  if (iVar2 != 0) {
    (**(code **)(iVar3 + 0x70))(param_1,&local_f,&local_e,&local_d);
  }
  if (local_e == '\0') {
    uVar1 = 0x40;
  }
  else {
    uVar1 = (ushort)local_d;
  }
  *(ushort *)(*param_1 + 0x6c) = uVar1;
  return;
}

