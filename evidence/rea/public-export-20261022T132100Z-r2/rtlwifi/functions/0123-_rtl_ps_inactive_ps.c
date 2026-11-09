/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x163f0; aliases: _rtl_ps_inactive_ps
 */

void _rtl_ps_inactive_ps(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar1 + 0xb2eb) = 1;
  if ((((*(int *)(iVar1 + 0xb310) == 0) && (*(int *)(iVar1 + 0x68c) == 0)) &&
      ((*(uint *)(iVar1 + 0xb308) & 1) != 0)) && ((*(uint *)(iVar1 + 0xb304) & 0x80) != 0)) {
    (**(code **)(*(int *)(iVar1 + 0xb900) + 0x1c))();
    *(uint *)(iVar1 + 0xb304) = *(uint *)(iVar1 + 0xb304) & 0xffffff7f;
  }
  rtl_ps_set_rf_state_isra_0(param_1,*(undefined4 *)(iVar1 + 0xb310),0x10000000);
  if (((*(int *)(iVar1 + 0xb310) == 2) && (*(int *)(iVar1 + 0x68c) == 0)) &&
     (((*(uint *)(iVar1 + 0xb308) & 1) != 0 && ((*(uint *)(iVar1 + 0xb304) & 0x80) == 0)))) {
    (**(code **)(*(int *)(iVar1 + 0xb900) + 0x20))(param_1);
    *(uint *)(iVar1 + 0xb304) = *(uint *)(iVar1 + 0xb304) | 0x80;
  }
  *(undefined1 *)(iVar1 + 0xb2eb) = 0;
  return;
}

