/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1507c; aliases: _rtl92ee_config_rf_reg
 */

void _rtl92ee_config_rf_reg
               (undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  if ((param_2 == 0xfe) || (param_2 == 0xffe)) {
    iVar2 = 0x31;
    do {
      iVar2 = iVar2 + -1;
      __udelay(1000);
    } while (iVar2 != -1);
  }
  else {
    rtl_set_rfreg(param_1,param_4,param_5,0xfffff,param_3);
    __udelay(1);
    if (param_2 == 0xb6) {
      uVar1 = rtl_get_rfreg(param_1,param_4,0xb6,0xffffffff);
      cVar3 = '\0';
      __udelay(1);
      do {
        if (uVar1 >> 8 == param_3 >> 8) {
          return;
        }
        rtl_set_rfreg(param_1,param_4,param_5,0xfffff,param_3);
        __udelay(1);
        cVar3 = cVar3 + '\x01';
        uVar1 = rtl_get_rfreg(param_1,param_4,0xb6,0xffffffff);
      } while (cVar3 != '\x06');
    }
    else if (param_2 == 0xb2) {
      uVar1 = rtl_get_rfreg(param_1,param_4,0xb2,0xffffffff);
      cVar3 = '\0';
      __udelay(1);
      do {
        if (param_3 == uVar1) {
          return;
        }
        rtl_set_rfreg(param_1,param_4,param_5,0xfffff,param_3);
        __udelay(1);
        rtl_set_rfreg(param_1,param_4,0x18,0xfffff,0xfc07);
        __udelay(1);
        cVar3 = cVar3 + '\x01';
        uVar1 = rtl_get_rfreg(param_1,param_4,0xb2,0xffffffff);
      } while (cVar3 != '\x06');
    }
  }
  return;
}

