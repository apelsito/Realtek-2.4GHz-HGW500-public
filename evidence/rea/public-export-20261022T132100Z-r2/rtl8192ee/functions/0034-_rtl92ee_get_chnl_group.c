/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1253c; aliases: _rtl92ee_get_chnl_group
 */

char _rtl92ee_get_chnl_group(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x83) {
    if (0x7b < param_1) {
      return '\a';
    }
    if (param_1 < 0x41) {
      if (0x3b < param_1) {
        return '\x03';
      }
      if (0x30 < param_1) {
        return (param_1 - 0x32 < 9) << 1;
      }
      if (0x2b < param_1) {
        return '\x01';
      }
      if ((param_1 < 0xf) && (uVar1 = param_1 - 3 & 0xff, uVar1 < 0xc)) {
        return CSWTCH_99[uVar1];
      }
    }
    else {
      if (param_1 < 0x73) {
        if (param_1 < 0x6c) {
          return (param_1 - 100 < 7) << 2;
        }
        return '\x05';
      }
      if (param_1 - 0x74 < 7) {
        return '\x06';
      }
    }
  }
  else if (param_1 < 0xa2) {
    if (0x9c < param_1) {
      return '\v';
    }
    if (param_1 < 0x91) {
      if (param_1 < 0x8c) {
        return ((param_1 + 0x7c & 0xff) < 7) << 3;
      }
      return '\t';
    }
    if ((param_1 + 0x6b & 0xff) < 7) {
      return '\n';
    }
  }
  else if (param_1 < 0xac) {
    if (0xa4 < param_1) {
      return '\f';
    }
  }
  else if ((param_1 + 0x53 & 0xff) < 5) {
    return '\r';
  }
  return '\0';
}

