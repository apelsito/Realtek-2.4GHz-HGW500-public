/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x162dc; aliases: rtl_ps_disable_nic
 */

undefined4 rtl_ps_disable_nic(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  rtl_deinit_deferred_work(param_1,1);
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x28))(param_1);
  (*(code *)&tasklet_kill)(iVar1 + 0x88);
  (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x18))(param_1);
  return 1;
}

