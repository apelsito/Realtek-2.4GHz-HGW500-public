/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11f80; aliases: rtl_rx_agg_start
 */

undefined4 rtl_rx_agg_start(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char local_15;
  
  iVar3 = *(int *)(param_1 + 0x40);
  local_15 = '\0';
  if (((param_2 == 0) || (8 < (param_3 & 0xffff))) ||
     ((iVar2 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104))(), iVar2 != 0 &&
      ((**(code **)(*(int *)(iVar3 + 0xb9ac) + 0x70))(iVar3,&local_15,0,0), local_15 != '\0')))) {
    uVar1 = 0xffffffea;
  }
  else if (param_2 == -0x108) {
    uVar1 = 0xfffffffa;
  }
  else {
    *(undefined1 *)(param_2 + (param_3 & 0xffff) * 0x18 + 0x125) = 1;
    uVar1 = 0;
  }
  return uVar1;
}

