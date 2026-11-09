/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13108; aliases: rtl_addr_delay
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_addr_delay(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0xf9:
    break;
  case 0xfa:
    break;
  case 0xfb:
    break;
  case 0xfc:
    halt_baddata();
  case 0xfd:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xfe:
    iVar1 = 0x31;
    do {
      iVar1 = iVar1 + -1;
      __udelay(1000);
    } while (iVar1 != -1);
    return;
  default:
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

