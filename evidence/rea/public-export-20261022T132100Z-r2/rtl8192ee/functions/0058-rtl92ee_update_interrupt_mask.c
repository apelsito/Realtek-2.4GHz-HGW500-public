/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x142c4; aliases: rtl92ee_update_interrupt_mask
 */

void rtl92ee_update_interrupt_mask(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0xcc90) = param_2 | *(uint *)(iVar1 + 0xcc90);
  }
  if (param_3 != 0) {
    *(uint *)(iVar1 + 0xcc90) = *(uint *)(iVar1 + 0xcc90) & ~param_3;
  }
  rtl92ee_disable_interrupt();
  rtl92ee_enable_interrupt(param_1);
  return;
}

