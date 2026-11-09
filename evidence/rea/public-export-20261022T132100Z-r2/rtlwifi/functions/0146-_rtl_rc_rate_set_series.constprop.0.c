/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x172a8; aliases: _rtl_rc_rate_set_series.constprop.0
 */

void _rtl_rc_rate_set_series_constprop_0
               (int param_1,int param_2,char *param_3,int param_4,byte param_5,int param_6,
               int param_7)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  short sVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  
  if (param_2 == 0) {
    bVar7 = 0;
    bVar5 = 0;
    bVar6 = 0;
    sVar4 = 0;
  }
  else {
    sVar4 = *(short *)(param_2 + 0x1f1);
    bVar6 = *(byte *)(param_2 + 0x1c) & 0x20;
    bVar7 = *(byte *)(param_2 + 0x38) & 0x20;
    bVar5 = *(byte *)(param_2 + 0x1c) & 0x40;
  }
  bVar2 = param_3[1];
  param_3[1] = bVar2 & 0xe0 | param_5 & 0x1f;
  *param_3 = (char)param_6 * (0 < param_6);
  if (param_7 != 0) {
    return;
  }
  if (*(char *)(param_4 + 0x14) != '\0') {
    param_3[1] = param_5 & 0x1f | (bVar2 >> 5 | 4) << 5;
    param_3[2] = param_3[2];
  }
  if ((*(uint *)(param_1 + 0x3f4) & 0xfffffffd) == 1) {
    if (param_2 == 0) goto LAB_ram_000173a0;
    if ((*(ushort *)(param_2 + 0x1c) & 2) != 0) {
      param_3[1] = param_3[1];
      param_3[2] = param_3[2] | 4;
    }
    if (*(char *)(param_2 + 0x34) == '\0') goto LAB_ram_000173a0;
LAB_ram_0001737e:
    bVar2 = param_3[1];
    uVar1 = (uint)(byte)param_3[2] << 3 | (uint)(bVar2 >> 5);
    uVar3 = uVar1 | 0x200;
  }
  else {
    if (*(char *)(param_1 + 0x55f) != '\0') goto LAB_ram_0001737e;
    if (*(char *)(param_1 + 0x587) == '\0') goto LAB_ram_000173a0;
    bVar2 = param_3[1];
    uVar1 = (uint)(byte)param_3[2] << 3 | (uint)(bVar2 >> 5);
    uVar3 = uVar1 | 0x20;
  }
  param_3[1] = bVar2 & 0x1f | (byte)((uVar1 & 7) << 5);
  param_3[2] = (char)(uVar3 >> 3);
LAB_ram_000173a0:
  if (bVar7 != 0 || (bVar6 != 0 || bVar5 != 0)) {
    param_3[1] = param_3[1];
    param_3[2] = param_3[2] | 0x10;
  }
  if (param_2 != 0) {
    if ((*(char *)(param_2 + 0x1e) != '\0') && ((sVar4 - 0x10U & 0xffef) == 0)) {
      param_3[1] = param_3[1];
      param_3[2] = param_3[2] | 1;
    }
    if ((*(char *)(param_2 + 0x34) != '\0') && (((sVar4 - 0x40U & 0xffbf) == 0 || (sVar4 == 0x100)))
       ) {
      param_3[1] = param_3[1];
      param_3[2] = param_3[2] | 0x20;
    }
  }
  return;
}

