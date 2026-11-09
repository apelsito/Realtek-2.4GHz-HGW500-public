/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x164c4; aliases: rtl_ips_nic_on
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_ips_nic_on(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  (*(code *)&cancel_delayed_work_sync)(iVar2 + 0x114);
  (*(code *)&mutex_lock)(iVar2 + 0x30);
  if ((*(char *)(iVar2 + 0xb2fd) != '\0') && (*(int *)(iVar2 + 0xb314) != 0)) {
    if ((*(char *)(iVar2 + 0xb2eb) == '\0') && (*(uint *)(iVar2 + 0xb300) < 0x10000001)) {
      *(undefined4 *)(iVar2 + 0xb310) = 0;
      *(undefined1 *)(iVar2 + 0xb2e9) = 0;
      _rtl_ps_inactive_ps(param_1);
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x104))();
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar2 + 0xb9ac) + 0x1c))(iVar2,*(undefined1 *)(iVar2 + 0xb310));
      }
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

