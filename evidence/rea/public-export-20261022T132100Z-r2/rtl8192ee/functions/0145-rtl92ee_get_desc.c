/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b068; aliases: rtl92ee_get_desc
 */

undefined8 rtl92ee_get_desc(int param_1,uint *param_2,char param_3,char param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  
  if (param_3 == '\0') {
    if (param_4 == '\x04') {
      uVar1 = param_2[6];
    }
    else {
      if (param_4 != '\x05') {
        if (param_4 == '\0') goto LAB_ram_0001b0ae;
        if (__warned_12 == '\0') {
          __warned_12 = '\x01';
          pcVar4 = "rtl8192ee: ERR rxdesc :%d not processed\n";
          uVar2 = 0x654;
          goto LAB_ram_0001b09a;
        }
        goto LAB_ram_0001b0aa;
      }
      uVar1 = *param_2 & 0x3fff;
    }
  }
  else if (param_4 == '\0') {
LAB_ram_0001b0ae:
    uVar1 = *param_2 >> 0x1f;
  }
  else {
    if (param_4 == '\x03') {
      uVar1 = param_2[5];
      if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0x10) + 0x14) == '\0') {
        uVar3 = 0;
      }
      else {
        uVar3 = param_2[6];
      }
      goto LAB_ram_0001b0d4;
    }
    if (__warned_13 == '\0') {
      __warned_13 = '\x01';
      pcVar4 = "rtl8192ee: ERR txdesc :%d not processed\n";
      uVar2 = 0x643;
LAB_ram_0001b09a:
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c",uVar2,9,pcVar4);
    }
LAB_ram_0001b0aa:
    uVar1 = 0;
  }
  uVar3 = 0;
LAB_ram_0001b0d4:
  return CONCAT44(uVar3,uVar1);
}

