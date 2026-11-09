/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16578; aliases: rtl_swlps_beacon
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_swlps_beacon(uint *param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1[0x10];
  if ((((((*(int *)(uVar3 + 0x3f4) == 2) && (*(char *)(uVar3 + 0xb2f4) != '\0')) &&
        (*(int *)(uVar3 + 0x4d0) == 2)) &&
       ((*(char *)(uVar3 + 0xb318) != '\0' && (*(char *)(uVar3 + 0xb2f6) == '\0')))) &&
      (((*param_1 & 2) != 0 && (((*param_2 & 0xfc) == 0x80 && (0x2c < param_3)))))) &&
     ((param_2[8] == *(ushort *)(uVar3 + 0x566) && param_2[9] == *(ushort *)(uVar3 + 0x568)) &&
      *(ushort *)(uVar3 + 0x56a) == param_2[10])) {
    *(undefined4 *)(uVar3 + 0xb338) = _jiffies;
    iVar2 = rtl_find_ie(param_2,param_3 - 4,5);
    if ((iVar2 != 0) && (3 < *(byte *)(iVar2 + 1))) {
      if (*(char *)((int)param_1 + 0xe) == '\0') {
        if (__warned_2 == '\0') {
          __warned_2 = '\x01';
          (*(code *)&warn_slowpath_fmt)("drivers/net/wireless/realtek/rtlwifi/ps.c",0x203,9,0);
        }
      }
      else {
        *(uint *)(uVar3 + 0xb320) = (uint)*(byte *)(iVar2 + 2);
      }
      bVar1 = *(byte *)(iVar2 + 4);
      *(byte *)(uVar3 + 0xb31b) = bVar1 & 1;
      if ((bVar1 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
  return;
}

