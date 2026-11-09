/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x140dc; aliases: rtl92ee_interrupt_recognized
 */

void rtl92ee_interrupt_recognized(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  uVar1 = rtl_read_dword(iVar2,0xb4);
  *param_2 = uVar1 & *(uint *)(iVar2 + 0xcc90);
  rtl_write_dword(iVar2,0xb4);
  uVar1 = rtl_read_dword(iVar2,0xbc);
  param_2[1] = uVar1 & *(uint *)(iVar2 + 0xcc94);
  (**(code **)(iVar2 + 0x748))();
  if (*(char *)(*(int *)(iVar2 + 0xb8fc) + 1) == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00012f2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x758))(iVar2,0xbc);
  return;
}

