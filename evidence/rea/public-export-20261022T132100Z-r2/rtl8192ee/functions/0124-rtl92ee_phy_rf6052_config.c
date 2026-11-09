/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x187dc; aliases: rtl92ee_phy_rf6052_config
 */

undefined4 rtl92ee_phy_rf6052_config(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = 0;
  uVar7 = 0;
  if (*(char *)(*(int *)(param_1 + 0x40) + 0x889) == '\0') {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x40) + 0x9f98) = uVar2;
  iVar9 = *(int *)(param_1 + 0x40);
  do {
    if (*(byte *)(iVar9 + 0x9f98) <= uVar5) {
      return 1;
    }
    iVar1 = uVar5 * 0x48;
    iVar8 = iVar9 + 0x800;
    if (uVar5 < 4) {
      switch(uVar5) {
      default:
        uVar7 = 0x10;
        break;
      case 1:
      case 3:
        uVar7 = 0x100000;
      }
      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xb4))
                        (param_1,*(undefined4 *)(iVar8 + iVar1 + -0xa4),uVar7);
    }
    iVar6 = iVar8 + iVar1;
    rtl_set_bbreg(param_1,*(undefined4 *)(iVar6 + -0x98),0x100000,1);
    __udelay_constprop_0();
    rtl_set_bbreg(param_1,*(undefined4 *)(iVar6 + -0x9c),0x10,1);
    __udelay_constprop_0();
    rtl_set_bbreg(param_1,*(undefined4 *)(iVar6 + -0x84),0x400,0);
    __udelay_constprop_0();
    rtl_set_bbreg(param_1,*(undefined4 *)(iVar6 + -0x84),0x800,0);
    __udelay_constprop_0();
    if (uVar5 == 0) {
      iVar6 = rtl92ee_phy_config_rf_with_headerfile(param_1,0);
LAB_ram_00018938:
      uVar3 = *(undefined4 *)(iVar1 + iVar8 + -0xa4);
      uVar4 = 0x10;
LAB_ram_00018944:
      rtl_set_bbreg(param_1,uVar3,uVar4,uVar7);
      if (iVar6 == 0) {
        return 0;
      }
    }
    else {
      if (uVar5 == 1) {
        iVar6 = rtl92ee_phy_config_rf_with_headerfile(param_1,1);
LAB_ram_00018962:
        uVar3 = *(undefined4 *)(iVar8 + iVar1 + -0xa4);
        uVar4 = 0x100000;
        goto LAB_ram_00018944;
      }
      if (uVar5 == 2) {
        iVar6 = 1;
        goto LAB_ram_00018938;
      }
      if (uVar5 == 3) {
        iVar6 = 1;
        goto LAB_ram_00018962;
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while( true );
}

