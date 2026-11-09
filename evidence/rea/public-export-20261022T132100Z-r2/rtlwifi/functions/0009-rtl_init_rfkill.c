/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10258; aliases: rtl_init_rfkill
 */

void rtl_init_rfkill(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  char local_15;
  
  iVar3 = *(int *)(param_1 + 0x40);
  local_15 = '\0';
  *(undefined1 *)(iVar3 + 0x720) = 1;
  (*(code *)&wiphy_rfkill_set_hw_state)(*(undefined4 *)(param_1 + 0x38),0);
  bVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x80))(param_1,&local_15);
  if (local_15 != '\0') {
    if (*(char *)(iVar3 + 0x720) == '\0') {
      puVar2 = &DAT_ram_000198e4;
    }
    else {
      puVar2 = &DAT_ram_000198e0;
    }
    (*(code *)&printk)(&DAT_ram_000198e8,puVar2);
    *(byte *)(iVar3 + 0x720) = bVar1;
    (*(code *)&wiphy_rfkill_set_hw_state)(*(undefined4 *)(param_1 + 0x38),bVar1 ^ 1);
  }
  (*(code *)&wiphy_rfkill_start_polling)(*(undefined4 *)(param_1 + 0x38));
  return;
}

