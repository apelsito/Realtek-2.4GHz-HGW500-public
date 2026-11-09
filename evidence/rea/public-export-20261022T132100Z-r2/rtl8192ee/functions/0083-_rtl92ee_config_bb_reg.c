/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14e14; aliases: _rtl92ee_config_bb_reg
 */

void _rtl92ee_config_bb_reg(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  switch(param_2) {
  case 0xf9:
    uVar1 = 1;
    break;
  case 0xfa:
    uVar1 = 5;
    break;
  case 0xfb:
    uVar1 = 0x32;
    break;
  case 0xfc:
    uVar1 = 1000;
    break;
  case 0xfd:
    uVar1 = 5000;
    break;
  case 0xfe:
    iVar2 = 0x31;
    do {
      iVar2 = iVar2 + -1;
      __udelay(1000);
    } while (iVar2 != -1);
    goto LAB_ram_00014e5a;
  default:
    rtl_set_bbreg(param_1,param_2,0xffffffff,param_3);
    goto LAB_ram_00014e5a;
  }
  __udelay(uVar1);
LAB_ram_00014e5a:
                    /* WARNING: Could not recover jumptable at 0x00014e64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __udelay(1);
  return;
}

