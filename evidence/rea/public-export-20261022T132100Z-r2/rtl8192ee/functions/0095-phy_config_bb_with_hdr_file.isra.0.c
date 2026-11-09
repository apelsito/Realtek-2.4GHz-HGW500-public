/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15864; aliases: phy_config_bb_with_hdr_file.isra.0
 */

void phy_config_bb_with_hdr_file_isra_0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = 0;
  if (param_2 != 0) {
LAB_ram_00015966:
    if ((uint)(&RTL8192EE_AGC_TAB_ARRAY)[iVar4] < 0xcdcdcdcd) {
      rtl_set_bbreg(param_1,(&RTL8192EE_AGC_TAB_ARRAY)[iVar4],0xffffffff,(&DAT_ram_0001fe30)[iVar4])
      ;
      __udelay(1);
    }
    else {
      if (0x211 < iVar4) {
        return;
      }
      piVar6 = &DAT_ram_0001fe38 + iVar4;
      iVar4 = iVar4 + 2;
      iVar5 = _check_condition_isra_0(*(undefined4 *)(param_1 + 0x40));
      iVar1 = *piVar6;
      if (iVar5 == 0) {
        for (; ((iVar1 != 0xdead && (iVar1 != 0xcdef)) && ((iVar1 != 0xcdcd && (iVar4 < 0x212))));
            iVar4 = iVar4 + 2) {
          iVar1 = (&DAT_ram_0001fe38)[iVar4];
        }
        iVar4 = iVar4 + -2;
      }
      else {
        while (iVar1 != 0xdead) {
          if (((iVar1 == 0xcdef) || (iVar1 == 0xcdcd)) || (0x211 < iVar4)) goto LAB_ram_00015a48;
          piVar6 = &DAT_ram_0001fe38 + iVar4;
          rtl_set_bbreg(param_1,(&RTL8192EE_AGC_TAB_ARRAY)[iVar4],0xffffffff,
                        (&DAT_ram_0001fe30)[iVar4]);
          __udelay(1);
          iVar4 = iVar4 + 2;
          iVar1 = *piVar6;
        }
      }
    }
    goto LAB_ram_00015998;
  }
LAB_ram_00015878:
  if ((uint)(&RTL8192EE_PHY_REG_ARRAY)[iVar4] < 0xcdcdcdcd) {
    _rtl92ee_config_bb_reg(param_1,(&RTL8192EE_PHY_REG_ARRAY)[iVar4],(&DAT_ram_00021318)[iVar4]);
    iVar5 = iVar4;
  }
  else {
    if (0x1bd < iVar4) {
      return;
    }
    iVar5 = iVar4 + 2;
    iVar1 = _check_condition_isra_0(*(undefined4 *)(param_1 + 0x40));
    iVar3 = (&DAT_ram_00021320)[iVar4];
    if (iVar1 == 0) {
      for (; ((iVar3 != 0xdead && (iVar3 != 0xcdef)) && ((iVar3 != 0xcdcd && (iVar5 < 0x1be))));
          iVar5 = iVar5 + 2) {
        iVar3 = (&DAT_ram_00021320)[iVar5];
      }
      iVar5 = iVar5 + -2;
    }
    else {
      uVar2 = (&DAT_ram_0002131c)[iVar4];
      while (iVar3 != 0xdead) {
        if (((iVar3 == 0xcdef) || (iVar3 == 0xcdcd)) || (0x1bd < iVar5)) goto LAB_ram_00015928;
        _rtl92ee_config_bb_reg(param_1,uVar2);
        iVar5 = iVar5 + 2;
        uVar2 = (&RTL8192EE_PHY_REG_ARRAY)[iVar5];
        iVar3 = (&DAT_ram_00021318)[iVar5];
      }
    }
  }
  goto LAB_ram_0001589c;
LAB_ram_00015a48:
  for (; (iVar1 != 0xdead && (iVar4 < 0x212)); iVar4 = iVar4 + 2) {
    iVar1 = (&DAT_ram_0001fe38)[iVar4];
  }
LAB_ram_00015998:
  iVar4 = iVar4 + 2;
  if (0x213 < iVar4) {
    return;
  }
  goto LAB_ram_00015966;
LAB_ram_00015928:
  for (; (iVar3 != 0xdead && (iVar5 < 0x1be)); iVar5 = iVar5 + 2) {
    iVar3 = (&DAT_ram_00021320)[iVar5];
  }
LAB_ram_0001589c:
  iVar4 = iVar5 + 2;
  if (0x1bf < iVar4) {
    return;
  }
  goto LAB_ram_00015878;
}

