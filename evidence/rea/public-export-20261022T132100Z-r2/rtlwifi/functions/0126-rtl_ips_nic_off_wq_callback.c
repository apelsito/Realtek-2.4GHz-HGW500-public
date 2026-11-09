/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x166c4; aliases: rtl_ips_nic_off_wq_callback
 */

void rtl_ips_nic_off_wq_callback(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + -0xcc);
  iVar3 = *(int *)(iVar4 + 0x40);
  if ((((*(int *)(iVar3 + 0x3f4) == 2) && (*(char *)(iVar3 + 0x4de) == '\0')) &&
      (*(int *)(iVar3 + 0x4d0) == 0)) &&
     ((*(char *)(iVar3 + 0x698) != '\0' && (*(char *)(iVar3 + 0xa3cd) == '\0')))) {
    pcVar2 = *(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0xf8);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(iVar4);
    }
    if (((*(char *)(iVar3 + 0xb2fd) != '\0') && (*(int *)(iVar3 + 0xb314) == 0)) &&
       ((*(char *)(iVar3 + 0xb2eb) == '\0' &&
        ((*(int *)(iVar3 + 0x4d0) == 0 && (*(char *)(iVar3 + 0x4ea) == '\0')))))) {
      *(undefined4 *)(iVar3 + 0xb310) = 2;
      *(undefined1 *)(iVar3 + 0xb2e9) = 1;
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104))();
      if (iVar1 != 0) {
        (**(code **)(*(int *)(iVar3 + 0xb9ac) + 0x1c))(iVar3,*(undefined1 *)(iVar3 + 0xb310));
      }
      _rtl_ps_inactive_ps(iVar4);
      return;
    }
  }
  return;
}

