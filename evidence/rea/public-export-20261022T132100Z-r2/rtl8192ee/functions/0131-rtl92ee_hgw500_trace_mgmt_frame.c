/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18bec; aliases: rtl92ee_hgw500_trace_mgmt_frame
 */

char rtl92ee_hgw500_trace_mgmt_frame(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  
  cVar6 = hgw500_mgmt_trace;
  if ((((hgw500_mgmt_trace == '\0') ||
       (iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar1 == 0)) ||
      (*(short *)(*(int *)(param_1 + 0x40) + 0x690) != 0xc)) || ((param_2 & 0xc) != 0)) {
    return '\0';
  }
  param_2 = param_2 & 0xfc;
  if (param_2 == 0x40) {
    iVar1 = 0;
  }
  else {
    if (param_2 != 0x50) {
      if (param_2 == 0xb0) {
        iVar1 = 2;
      }
      else if (param_2 == 0) {
        iVar1 = 3;
      }
      else if (param_2 == 0x10) {
        iVar1 = 4;
      }
      else if (param_2 == 0x20) {
        iVar1 = 5;
      }
      else if (param_2 == 0x30) {
        iVar1 = 6;
      }
      else if (param_2 == 0xc0) {
        iVar1 = 7;
      }
      else if (param_2 == 0xa0) {
        iVar1 = 8;
      }
      else {
        if (param_2 != 0xd0) {
          return '\0';
        }
        iVar1 = 9;
      }
      uVar5 = 0x40;
      goto LAB_ram_00018c82;
    }
    iVar1 = 1;
  }
  uVar5 = 0x10;
LAB_ram_00018c82:
  puVar2 = (uint *)(param_3 + iVar1 * 4);
  uVar4 = *puVar2;
  uVar3 = uVar4 + 1;
  *puVar2 = uVar3;
  if (uVar5 < uVar3) {
    cVar6 = (uVar4 & uVar3) == 0;
  }
  return cVar6;
}

