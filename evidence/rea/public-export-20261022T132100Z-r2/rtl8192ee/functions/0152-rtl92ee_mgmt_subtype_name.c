/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1c558; aliases: rtl92ee_mgmt_subtype_name
 */

char * rtl92ee_mgmt_subtype_name(uint param_1)

{
  param_1 = param_1 & 0xfc;
  if (param_1 == 0x40) {
    return "probe_req";
  }
  if (param_1 == 0x50) {
    return "probe_resp";
  }
  if (param_1 == 0xb0) {
    return "auth";
  }
  if (param_1 == 0) {
    return "assoc_req";
  }
  if (param_1 == 0x10) {
    return "assoc_resp";
  }
  if (param_1 == 0x20) {
    return "reassoc_req";
  }
  if (param_1 == 0x30) {
    return "reassoc_resp";
  }
  if (param_1 != 0xc0) {
    if (param_1 == 0xa0) {
      return "disassoc";
    }
    if (param_1 != 0xd0) {
      return "mgmt_other";
    }
    return "action";
  }
  return "deauth";
}

