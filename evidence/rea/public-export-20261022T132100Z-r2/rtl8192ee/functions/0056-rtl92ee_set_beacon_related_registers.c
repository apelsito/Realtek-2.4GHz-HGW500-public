/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14158; aliases: rtl92ee_set_beacon_related_registers
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl92ee_set_beacon_related_registers(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x40);
  uVar3 = *(uint *)(iVar1 + 0x5a0);
  cVar2 = '\0';
  if (*(char *)(iVar1 + 0xba99) != '\0') {
    if (*(char *)(iVar1 + 0xba9a) == '\0') {
      cVar2 = *(char *)(iVar1 + 0xba98);
      if ((cVar2 != '\0') &&
         ((*(code *)&disable_irq)(*(undefined4 *)(*(int *)(iVar1 + 0xba94) + 0x170)),
         __print_once_3 == '\0')) {
        __print_once_3 = '\x01';
        (*(code *)&printk)(&DAT_ram_0001cf18,*(undefined4 *)(*(int *)(iVar1 + 0xba94) + 0x170));
      }
    }
    else {
      cVar2 = '\0';
    }
  }
  rtl92ee_disable_interrupt(param_1);
  rtl_write_word(iVar1,0x55a,2);
  rtl_write_word(iVar1,0x554,uVar3 & 0xffff);
  rtl_write_word(iVar1,0x510,0x660f);
  rtl_write_byte(iVar1,0x55e,0x18);
  rtl_write_byte(iVar1,0x55f,0x18);
  rtl_write_byte(iVar1,0x606,0x30);
  uVar3 = *(uint *)(iVar1 + 0xcca4);
  *(uint *)(iVar1 + 0xcca4) = uVar3 | 8;
  rtl_write_byte(iVar1,0x550,uVar3 & 0xff | 8);
  if (cVar2 == '\0') {
    return;
  }
  rtl92ee_enable_interrupt(param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

