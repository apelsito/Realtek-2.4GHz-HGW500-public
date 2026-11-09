/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10630; aliases: rtlwifi_rate_mapping
 */

int rtlwifi_rate_mapping(int param_1,char param_2,char param_3,char param_4)

{
  if (param_3 == '\0') {
    if (param_2 == '\0') {
      if (**(int **)(param_1 + 0x14) == 0) {
        switch(param_4) {
        case '\x01':
switchD_ram_00010670_caseD_1:
          return 1;
        case '\x02':
switchD_ram_00010670_caseD_2:
          return 2;
        case '\x03':
switchD_ram_00010670_caseD_3:
          return 3;
        case '\x04':
switchD_ram_00010670_caseD_4:
          return 4;
        case '\x05':
switchD_ram_00010670_caseD_5:
          return 5;
        case '\x06':
switchD_ram_00010670_caseD_6:
          return 6;
        case '\a':
switchD_ram_00010670_caseD_7:
          return 7;
        case '\b':
          goto switchD_ram_00010670_caseD_8;
        case '\t':
          goto switchD_ram_00010670_caseD_9;
        case '\n':
          goto switchD_ram_00010670_caseD_a;
        case '\v':
          goto switchD_ram_00010670_caseD_b;
        }
      }
      else {
        switch(param_4) {
        case '\x05':
          goto switchD_ram_00010670_caseD_1;
        case '\x06':
          goto switchD_ram_00010670_caseD_2;
        case '\a':
          goto switchD_ram_00010670_caseD_3;
        case '\b':
          goto switchD_ram_00010670_caseD_4;
        case '\t':
          goto switchD_ram_00010670_caseD_5;
        case '\n':
          goto switchD_ram_00010670_caseD_6;
        case '\v':
          goto switchD_ram_00010670_caseD_7;
        }
      }
    }
    else {
      switch(param_4) {
      case '\r':
        goto switchD_ram_00010670_caseD_1;
      case '\x0e':
        goto switchD_ram_00010670_caseD_2;
      case '\x0f':
        goto switchD_ram_00010670_caseD_3;
      case '\x10':
        goto switchD_ram_00010670_caseD_4;
      case '\x11':
        goto switchD_ram_00010670_caseD_5;
      case '\x12':
        goto switchD_ram_00010670_caseD_6;
      case '\x13':
        goto switchD_ram_00010670_caseD_7;
      case '\x14':
switchD_ram_00010670_caseD_8:
        return 8;
      case '\x15':
switchD_ram_00010670_caseD_9:
        return 9;
      case '\x16':
switchD_ram_00010670_caseD_a:
        return 10;
      case '\x17':
switchD_ram_00010670_caseD_b:
        return 0xb;
      case '\x18':
        return 0xc;
      case '\x19':
        return 0xd;
      case '\x1a':
        return 0xe;
      case '\x1b':
        return 0xf;
      }
    }
  }
  else if ((byte)(param_4 - 0x2d) < 0x13) {
    return (int)(char)CSWTCH_129[(byte)(param_4 - 0x2d)];
  }
  return 0;
}

