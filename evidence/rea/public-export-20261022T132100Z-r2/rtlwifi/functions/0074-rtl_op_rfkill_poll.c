/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x133e0; aliases: rtl_op_rfkill_poll
 */

void rtl_op_rfkill_poll(int param_1)

{
  uint uVar1;
  int iVar2;
  char local_15;
  
  iVar2 = *(int *)(param_1 + 0x40);
  local_15 = '\0';
  if ((*(uint *)(iVar2 + 0xb904) & 1) != 0) {
    (*(code *)&mutex_lock)(iVar2 + 0x24);
    uVar1 = (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x80))(param_1,&local_15);
    if ((local_15 != '\0') && (*(byte *)(iVar2 + 0x720) != uVar1)) {
      *(char *)(iVar2 + 0x720) = (char)uVar1;
      (*(code *)&wiphy_rfkill_set_hw_state)(*(undefined4 *)(param_1 + 0x38),(uVar1 ^ 1) & 0xff);
    }
    (*(code *)&mutex_unlock)(iVar2 + 0x24);
  }
  return;
}

