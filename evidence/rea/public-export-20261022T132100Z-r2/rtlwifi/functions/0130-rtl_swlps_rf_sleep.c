/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16898; aliases: rtl_swlps_rf_sleep
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_swlps_rf_sleep(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (((((*(char *)(iVar2 + 0xb318) != '\0') && (*(char *)(iVar2 + 0xa3cd) == '\0')) &&
       (*(int *)(iVar2 + 0x3f4) != 1)) &&
      ((*(int *)(iVar2 + 0x4d0) == 2 && (4 < *(byte *)(iVar2 + 0x4eb))))) &&
     ((*(char *)(iVar2 + 0xb7c8) == '\0' && (*(char *)(iVar2 + 0xb2ea) == '\0')))) {
    (*(code *)&mutex_lock)(iVar2 + 0x3c);
    rtl_ps_set_rf_state_isra_0(param_1,1,0x20000000);
    (*(code *)&mutex_unlock)(iVar2 + 0x3c);
    if (((*(uint *)(iVar2 + 0xb308) & 1) != 0) && ((*(uint *)(iVar2 + 0xb304) & 0x80) == 0)) {
      (**(code **)(*(int *)(iVar2 + 0xb900) + 0x20))(param_1);
      *(uint *)(iVar2 + 0xb304) = *(uint *)(iVar2 + 0xb304) | 0x80;
    }
    if (*(uint *)(iVar2 + 0xb320) == 0) {
      uVar1 = (uint)*(byte *)(param_1 + 0xe);
      if (uVar1 == 1) {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = *(uint *)(iVar2 + 0xb320) & 0xff;
    }
    if (5 < uVar1) {
      uVar1 = 5;
    }
    (*(code *)&__msecs_to_jiffies)(*(ushort *)(*(int *)(iVar2 + 0x3f0) + 0x20) * uVar1 + -0x28);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

