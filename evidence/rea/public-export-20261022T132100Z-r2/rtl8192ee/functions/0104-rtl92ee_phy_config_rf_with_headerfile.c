/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x173b0; aliases: rtl92ee_phy_config_rf_with_headerfile
 */

undefined4 rtl92ee_phy_config_rf_with_headerfile(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0) {
    iVar5 = 0;
LAB_ram_000173d0:
    uVar2 = (&RTL8192EE_RADIOA_ARRAY)[iVar5];
    if (uVar2 < 0xcdcdcdcd) {
      _rtl92ee_config_rf_reg(param_1,uVar2,(&DAT_ram_00020cc0)[iVar5],0,uVar2);
      iVar6 = iVar5;
    }
    else {
      if (0xeb < iVar5) {
        return 1;
      }
      iVar6 = iVar5 + 2;
      iVar1 = _check_condition_isra_0(*(undefined4 *)(param_1 + 0x40));
      iVar3 = (&DAT_ram_00020cc8)[iVar5];
      if (iVar1 == 0) {
        for (; ((iVar3 != 0xdead && (iVar3 != 0xcdef)) && ((iVar3 != 0xcdcd && (iVar6 < 0xec))));
            iVar6 = iVar6 + 2) {
          iVar3 = (&DAT_ram_00020cc8)[iVar6];
        }
        iVar6 = iVar6 + -2;
      }
      else {
        uVar4 = (&DAT_ram_00020cc4)[iVar5];
        while (iVar3 != 0xdead) {
          if (((iVar3 == 0xcdef) || (iVar3 == 0xcdcd)) || (0xeb < iVar6)) goto LAB_ram_0001747c;
          _rtl92ee_config_rf_reg(param_1,uVar4,iVar3,0);
          iVar6 = iVar6 + 2;
          uVar4 = (&RTL8192EE_RADIOA_ARRAY)[iVar6];
          iVar3 = (&DAT_ram_00020cc0)[iVar6];
        }
      }
    }
    goto LAB_ram_000173f8;
  }
  if (param_2 != 1) {
    return 1;
  }
  iVar5 = 0;
LAB_ram_000174c0:
  uVar2 = (&RTL8192EE_RADIOB_ARRAY)[iVar5];
  if (uVar2 < 0xcdcdcdcd) {
    _rtl92ee_config_rf_reg(param_1,uVar2,(&DAT_ram_000209a8)[iVar5],1,uVar2);
    iVar6 = iVar5;
  }
  else {
    if (0xc3 < iVar5) {
      return 1;
    }
    iVar6 = iVar5 + 2;
    iVar1 = _check_condition_isra_0(*(undefined4 *)(param_1 + 0x40));
    iVar3 = (&DAT_ram_000209b0)[iVar5];
    if (iVar1 == 0) {
      for (; ((iVar3 != 0xdead && (iVar3 != 0xcdef)) && ((iVar3 != 0xcdcd && (iVar6 < 0xc4))));
          iVar6 = iVar6 + 2) {
        iVar3 = (&DAT_ram_000209b0)[iVar6];
      }
      iVar6 = iVar6 + -2;
    }
    else {
      uVar4 = (&DAT_ram_000209ac)[iVar5];
      while (iVar3 != 0xdead) {
        if (((iVar3 == 0xcdef) || (iVar3 == 0xcdcd)) || (0xc3 < iVar6)) goto LAB_ram_0001756c;
        _rtl92ee_config_rf_reg(param_1,uVar4,iVar3,1);
        iVar6 = iVar6 + 2;
        uVar4 = (&RTL8192EE_RADIOB_ARRAY)[iVar6];
        iVar3 = (&DAT_ram_000209a8)[iVar6];
      }
    }
  }
  goto LAB_ram_000174e8;
LAB_ram_0001747c:
  for (; (iVar3 != 0xdead && (iVar6 < 0xec)); iVar6 = iVar6 + 2) {
    iVar3 = (&DAT_ram_00020cc8)[iVar6];
  }
LAB_ram_000173f8:
  iVar5 = iVar6 + 2;
  if (0xed < iVar5) {
    return 1;
  }
  goto LAB_ram_000173d0;
LAB_ram_0001756c:
  for (; (iVar3 != 0xdead && (iVar6 < 0xc4)); iVar6 = iVar6 + 2) {
    iVar3 = (&DAT_ram_000209b0)[iVar6];
  }
LAB_ram_000174e8:
  iVar5 = iVar6 + 2;
  if (0xc5 < iVar5) {
    return 1;
  }
  goto LAB_ram_000174c0;
}

