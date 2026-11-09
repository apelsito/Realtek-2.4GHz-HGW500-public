/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13e30; aliases: rtl92ee_set_qos
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl92ee_set_qos(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x40);
  rtl92ee_dm_init_edca_turbo();
  switch(param_2) {
  case 0:
    return;
  case 1:
    uVar2 = 0xa44f;
    uVar1 = 0x50c;
    break;
  case 2:
    uVar2 = 0x5e4322;
    uVar1 = 0x504;
    break;
  case 3:
    uVar2 = 0x2f3222;
    uVar1 = 0x500;
    break;
  default:
    if (__warned_4 != '\0') {
      return;
    }
    __warned_4 = 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  rtl_write_dword(uVar3,uVar1,uVar2);
  return;
}

