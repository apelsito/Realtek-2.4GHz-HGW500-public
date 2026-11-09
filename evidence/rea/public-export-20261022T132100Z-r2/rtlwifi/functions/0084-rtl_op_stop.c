/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1450c; aliases: rtl_op_stop
 */

void rtl_op_stop(int param_1)

{
  int iVar1;
  char local_19;
  
  iVar1 = *(int *)(param_1 + 0x40);
  local_19 = '\0';
  if (*(char *)(iVar1 + 0x698) != '\0') {
    (**(code **)(*(int *)(*(int *)(iVar1 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x5c,&local_19);
    if (*(int *)(iVar1 + 0xb314) == 2) {
      rtl_ips_nic_on(param_1);
    }
    (*(code *)&mutex_lock)(iVar1 + 0x24);
    if ((local_19 == '\0') || (*(char *)(iVar1 + 0x6ee) == '\0')) {
      *(undefined4 *)(iVar1 + 0x4d0) = 0;
      eth_zero_addr(iVar1 + 0x566);
      *(undefined4 *)(iVar1 + 0x56c) = 0;
      rtl_cam_reset_sec_info(param_1);
      rtl_deinit_deferred_work(param_1,0);
    }
    (**(code **)(*(int *)(iVar1 + 0xb900) + 8))(param_1);
    (*(code *)&mutex_unlock)(iVar1 + 0x24);
  }
  return;
}

