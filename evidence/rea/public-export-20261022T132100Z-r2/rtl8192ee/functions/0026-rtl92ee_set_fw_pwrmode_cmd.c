/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11d20; aliases: rtl92ee_set_fw_pwrmode_cmd
 */

void rtl92ee_set_fw_pwrmode_cmd(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  undefined1 local_34;
  byte local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 uStack_30;
  byte local_2f;
  
  iVar7 = *(int *)(param_1 + 0x40);
  param_2 = param_2 & 0xff;
  (*(code *)&memset)(&local_34,0,7);
  iVar8 = *(int *)(iVar7 + 0xb9ac);
  iVar2 = (**(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x104))();
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = (**(code **)(iVar8 + 0x6c))(iVar7);
  }
  iVar2 = (**(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x104))();
  uVar4 = 0;
  if (iVar2 != 0) {
    uVar4 = (**(code **)(iVar8 + 0x74))(iVar7);
  }
  if (iVar3 == 0) {
    uVar4 = param_2;
    if (param_2 == 2) {
      uVar9 = 2;
      bVar6 = 1;
      goto LAB_ram_00011dd6;
    }
    if (param_2 != 3) goto LAB_ram_00011db6;
    uVar9 = *(undefined1 *)(iVar7 + 0xb2fa);
  }
  else {
LAB_ram_00011db6:
    if (uVar4 == 1) {
      uVar9 = 2;
      bVar6 = 0;
      goto LAB_ram_00011dd6;
    }
    uVar9 = 4;
  }
  bVar6 = 2;
LAB_ram_00011dd6:
  if (*(char *)(iVar7 + 0x4dd) != '\0') {
    uVar9 = 2;
    bVar6 = 1;
  }
  if (uVar4 == 0) {
    bVar1 = 0x40;
    uStack_30 = 0xc;
  }
  else if (iVar3 == 0) {
    bVar1 = 0x40;
    uStack_30 = 0;
  }
  else {
    bVar1 = (**(code **)(iVar8 + 100))(iVar7);
    uStack_30 = (**(code **)(iVar8 + 0x68))(iVar7);
    if ((bVar6 == 2) && ((bVar1 & 0x10) != 0)) {
      uVar9 = 2;
    }
  }
  local_34 = uVar4 != 0;
  if (iVar3 == 0) {
    if (*(char *)(iVar7 + 0x4dd) == '\0') {
      cVar5 = '\x01';
    }
    else {
      cVar5 = *(char *)(iVar7 + 0xb36d);
    }
  }
  else {
    cVar5 = '\0';
  }
  local_33 = cVar5 << 4 | bVar6;
  local_31 = 0;
  local_32 = uVar9;
  local_2f = bVar1;
  iVar3 = (**(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x104))();
  if (iVar3 != 0) {
    (**(code **)(iVar8 + 0x60))(iVar7,&local_34,7);
  }
  rtl92ee_fill_h2c_cmd(param_1,0x20,7,&local_34);
  return;
}

