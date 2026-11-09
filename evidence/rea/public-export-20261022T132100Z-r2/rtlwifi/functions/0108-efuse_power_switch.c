/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1569c; aliases: efuse_power_switch
 */

void efuse_power_switch(int param_1,char param_2,char param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x40);
  uVar1 = *(ushort *)(iVar7 + 0x690);
  if (param_3 != '\0') {
    if (uVar1 == 2) {
      if (param_2 != '\0') goto LAB_ram_0001576a;
    }
    else {
      if ((uVar1 & 0xfffd) == 4) {
        uVar3 = (**(code **)(iVar7 + 0x754))(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x1c))
        ;
        uVar5 = *(uint *)(*(int *)(iVar7 + 0xb8fc) + 0x58);
        if ((uVar3 & uVar5) == 0) {
          rtl_write_word(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x1c),
                         (uVar5 | uVar3) & 0xffff);
        }
      }
      else {
        rtl_write_byte(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x78),0x69);
      }
      uVar3 = (**(code **)(iVar7 + 0x754))(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x20));
      uVar5 = *(uint *)(*(int *)(iVar7 + 0xb8fc) + 0x5c);
      if ((uVar3 & uVar5) == 0) {
        rtl_write_word(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x20),
                       (uVar5 | uVar3) & 0xffff);
      }
      uVar3 = (**(code **)(iVar7 + 0x754))(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x24));
      iVar4 = *(int *)(iVar7 + 0xb8fc);
      if (((uVar3 & *(uint *)(iVar4 + 0x60)) == 0) || ((uVar3 & *(uint *)(iVar4 + 100)) == 0)) {
        rtl_write_word(iVar7,*(undefined4 *)(iVar4 + 0x24),
                       (uVar3 | *(uint *)(iVar4 + 0x60) | *(uint *)(iVar4 + 100)) & 0xffff);
      }
      if (param_2 != '\0') {
LAB_ram_0001576a:
        bVar2 = rtl_read_byte(iVar7,*(int *)(*(int *)(iVar7 + 0xb8fc) + 0x48) + 3);
        if (*(short *)(iVar7 + 0x690) == 0xe) {
          bVar2 = bVar2 & 0x87 | 0x18;
        }
        else if (*(short *)(iVar7 + 0x690) != 2) {
          bVar2 = bVar2 & 0xf | 0x30;
        }
        rtl_write_byte(iVar7,*(int *)(*(int *)(iVar7 + 0xb8fc) + 0x48) + 3,bVar2 | 0x80);
      }
      if (*(short *)(iVar7 + 0x690) != 2) {
        return;
      }
    }
    iVar4 = *(int *)(iVar7 + 0xb8fc);
    uVar6 = 3;
    goto LAB_ram_000157be;
  }
  if ((uVar1 & 0xfffd) == 4) {
    if (param_2 == '\0') {
      return;
    }
LAB_ram_0001581a:
    uVar3 = rtl_read_byte(iVar7,*(int *)(*(int *)(iVar7 + 0xb8fc) + 0x48) + 3);
    rtl_write_byte(iVar7,*(int *)(*(int *)(iVar7 + 0xb8fc) + 0x48) + 3,uVar3 & 0x7f);
  }
  else {
    rtl_write_byte(iVar7,*(undefined4 *)(*(int *)(iVar7 + 0xb8fc) + 0x78),0);
    if (param_2 != '\0') goto LAB_ram_0001581a;
  }
  if (*(short *)(iVar7 + 0x690) != 2) {
    return;
  }
  iVar4 = *(int *)(iVar7 + 0xb8fc);
  uVar6 = 2;
LAB_ram_000157be:
  rtl_write_byte(iVar7,*(undefined4 *)(iVar4 + 0x50),uVar6);
  return;
}

