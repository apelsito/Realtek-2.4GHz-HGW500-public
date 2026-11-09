/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1003c; aliases: rtl_mrate_idx_to_arfr_id
 */

uint rtl_mrate_idx_to_arfr_id(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  
  param_2 = param_2 & 0xff;
  iVar2 = *(int *)(param_1 + 0x40);
  switch(param_2) {
  case 0:
    param_2 = (uint)(*(char *)(iVar2 + 0x889) == '\0');
    break;
  case 1:
  case 3:
    if (*(char *)(iVar2 + 0x889) == '\0') {
      param_2 = 5;
    }
    else {
      param_2 = 4;
    }
    break;
  case 2:
    if (*(char *)(iVar2 + 0x889) == '\0') {
      param_2 = 3;
    }
    break;
  case 4:
switchD_ram_00010056_caseD_4:
    param_2 = 6;
    break;
  case 6:
    param_2 = 8;
    break;
  case 7:
    if (param_3 < 0x11) {
      if (1 < param_3) {
        return 7 - (0x10014U >> ((byte)param_3 & 0x1f) & 1) & 0xff;
      }
    }
    else if (param_3 == 0x80) goto switchD_ram_00010056_caseD_4;
  case 5:
    param_2 = 7;
    break;
  case 8:
    cVar1 = *(char *)(iVar2 + 0x889);
    goto LAB_ram_000100ca;
  case 9:
    cVar1 = *(char *)(iVar2 + 0x889);
    if (*(char *)(iVar2 + 0x88a) != '\x02') {
      if (cVar1 != '\0') {
        return 0xc;
      }
      return 0xb;
    }
LAB_ram_000100ca:
    if (cVar1 == '\0') {
      param_2 = 10;
    }
    else {
      param_2 = 9;
    }
    break;
  default:
    param_2 = 0;
  }
  return param_2;
}

