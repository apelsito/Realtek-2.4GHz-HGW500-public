/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1071c; aliases: rtl_get_hal_edca_param
 */

uint rtl_get_hal_edca_param(undefined4 param_1,int param_2,uint param_3,ushort *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if (param_3 == 4) {
    if (*(char *)(param_2 + 0x1c) == '\0') {
LAB_ram_0001073a:
      iVar4 = 0x14;
    }
    else {
      iVar4 = 9;
    }
    iVar3 = 10;
  }
  else {
    if (param_3 < 5) {
      bVar5 = param_3 == 1;
LAB_ram_00010738:
      if (!bVar5) goto LAB_ram_0001073a;
    }
    else if (param_3 != 0x40) {
      if (0x40 < param_3) {
        bVar5 = param_3 == 0x80;
        goto LAB_ram_00010738;
      }
      if ((param_3 - 0x10 & 0xffffffef) != 0) goto LAB_ram_0001073a;
    }
    iVar4 = 9;
    iVar3 = 0x10;
  }
  uVar1 = fls(param_4[2]);
  uVar2 = fls(param_4[1]);
  return ((byte)param_4[3] & 0xf) * iVar4 + iVar3 |
         (uVar1 & 0xf) << 0xc | (uVar2 & 0xf) << 8 | (*param_4 & 0x7ff) << 0x10;
}

