/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x133d8; aliases: rtl92ee_set_hw_reg
 */

void rtl92ee_set_hw_reg(int param_1,byte param_2,ushort *param_3)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  byte bVar9;
  code *pcVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  char cVar15;
  char cVar16;
  bool bVar17;
  byte local_2e;
  byte local_2d;
  undefined4 local_2c;
  
  if (0x5e < param_2) {
    return;
  }
  iVar11 = *(int *)(param_1 + 0x40);
  if (param_2 < 0x35) {
    if (0x21 < param_2) {
      if (param_2 != 0x2c) {
        return;
      }
      rtl_write_dword(iVar11,0x608,*(undefined4 *)param_3);
      *(undefined4 *)(iVar11 + 0xcc88) = *(undefined4 *)param_3;
      return;
    }
    if (param_2 < 0xe) {
      if (param_2 == 2) {
        uVar2 = *param_3;
        rtl_write_byte(iVar11,0x440,uVar2 & 0x5d | 0xd);
        (**(code **)(iVar11 + 0x740))(iVar11,0x441,uVar2 >> 8 & 1);
        if (*(char *)(*(int *)(iVar11 + 0xb8fc) + 1) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00012d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(iVar11 + 0x750))(iVar11,0x441);
          return;
        }
        return;
      }
      if (param_2 != 3) {
        uVar13 = 0;
        if (param_2 != 0) {
          return;
        }
        do {
          pbVar5 = (byte *)((int)param_3 + uVar13);
          iVar7 = uVar13 + 0x610;
          uVar13 = uVar13 + 1 & 0xff;
          rtl_write_byte(iVar11,iVar7,*pbVar5);
        } while (uVar13 != 6);
        return;
      }
      uVar13 = 0;
      do {
        pbVar5 = (byte *)((int)param_3 + uVar13);
        iVar7 = uVar13 + 0x618;
        uVar13 = uVar13 + 1 & 0xff;
        rtl_write_byte(iVar11,iVar7,*pbVar5);
      } while (uVar13 != 6);
      return;
    }
    switch(param_2) {
    case 0xe:
      rtl_write_byte(iVar11,0x515,(byte)*param_3);
      rtl_write_byte(iVar11,0x517,*(byte *)((int)param_3 + 1));
      rtl_write_byte(iVar11,0x429,(byte)*param_3);
      rtl_write_byte(iVar11,0x63b,(byte)*param_3);
      uVar8 = 0x63e;
      goto LAB_ram_00013602;
    default:
      return;
    case 0x12:
      local_2c = (uint)local_2c._1_3_ << 8;
      rtl_write_byte(iVar11,0x51b,(byte)*param_3);
      bVar4 = 0;
      while( true ) {
        local_2c = CONCAT31(local_2c._1_3_,bVar4);
        if (3 < bVar4) break;
        (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))(param_1,0x20,&local_2c);
        bVar4 = (byte)local_2c + 1;
      }
      return;
    case 0x13:
      bVar17 = (byte)*param_3 != 0;
      uVar13 = (*(byte *)(iVar11 + 0x58d) & 7) << 5;
      if (bVar17) {
        uVar13 = uVar13 | 0x80;
      }
      rtl_write_byte(iVar11,0x442,uVar13);
      *(bool *)(iVar11 + 0x58b) = bVar17;
      return;
    case 0x1b:
      bVar9 = (byte)*param_3;
      uVar8 = 0x680;
      break;
    case 0x1e:
      local_2c = 0xb972a841;
      if (3 < (byte)*param_3) {
        return;
      }
      uVar6 = 1 << ((byte)*param_3 + 2 & 0x1f);
      uVar12 = 0;
      uVar14 = uVar6 & 0xff;
      uVar13 = uVar6;
      if (0xf < (int)uVar6) {
        uVar13 = 0xf;
      }
      if (0xf < (int)uVar6) {
        uVar14 = 0xf;
      }
      do {
        pbVar5 = (byte *)((int)&local_2c + uVar12);
        uVar6 = (uint)*pbVar5;
        if ((int)(uVar13 << 4) < (int)(uVar6 & 0xf0)) {
          uVar6 = (uVar14 & 0xf) << 4 | uVar6 & 0xf;
          *pbVar5 = (byte)uVar6;
        }
        if (uVar14 < (uVar6 & 0xf)) {
          *pbVar5 = (byte)uVar6 & 0xf0 | (byte)uVar14;
        }
        iVar7 = uVar12 + 0x458;
        uVar12 = uVar12 + 1 & 0xff;
        rtl_write_byte(iVar11,iVar7);
      } while (uVar12 != 4);
      return;
    case 0x20:
      local_2c = CONCAT31(local_2c._1_3_,(byte)*param_3);
      if (*(int *)(iVar11 + 0xccb0) == 2) {
        return;
      }
      pbVar5 = (byte *)&local_2c;
      uVar8 = 0x21;
      pcVar10 = *(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50);
      goto LAB_ram_00013772;
    case 0x21:
      bVar4 = *(byte *)(iVar11 + 0x5f2);
      bVar1 = (byte)*param_3;
      bVar3 = rtl_read_byte(iVar11,0x5c0);
      bVar17 = *(int *)(iVar11 + 0xccb0) != 2;
      bVar9 = bVar3 | bVar17;
      if ((bVar4 >> 4 & 1) == 0) {
        if (bVar1 == 2) {
          bVar9 = bVar3 & 0xfb | bVar17;
        }
        else if (bVar1 == 3) {
          bVar9 = bVar3 & 0xf7 | bVar17;
        }
        else if (bVar1 == 0) {
          bVar9 = bVar3 & 0xfd | bVar17;
        }
      }
      else if (bVar1 == 2) {
        bVar9 = bVar9 | 4;
      }
      else if (bVar1 == 3) {
        bVar9 = bVar9 | 8;
      }
      else if (bVar1 == 0) {
        bVar9 = bVar9 | 2;
      }
      uVar8 = 0x5c0;
    }
    goto LAB_ram_000136a8;
  }
  switch(param_2) {
  case 0x35:
    uVar8 = 0x42a;
    goto LAB_ram_00013602;
  case 0x38:
    *(byte *)(iVar11 + 0xa9e2) = (byte)*param_3;
    break;
  case 0x39:
    *(ushort *)(iVar11 + 0xa9e0) = *param_3;
    break;
  case 0x3c:
    uVar13 = rtl_read_byte(iVar11,0x3dc);
    __udelay(1);
    bVar9 = (byte)*param_3;
    uVar8 = 0x3dc;
    if ((uVar13 & 0x80) == 0) {
      bVar9 = bVar9 | 0x80;
    }
    goto LAB_ram_000136a8;
  case 0x3d:
    rtl92ee_set_fw_pwrmode_cmd(param_1,(byte)*param_3);
    return;
  case 0x3e:
    uVar2 = *param_3;
    if ((byte)uVar2 == 1) {
      (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))(param_1,0x52,0);
      uVar8 = *(undefined4 *)(param_1 + 0x40);
      cVar15 = '\0';
      bVar4 = rtl_read_byte(uVar8,0x101);
      rtl_write_byte(uVar8,0x101,bVar4 | 1);
      _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),0,8);
      _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),0x10,0);
      uVar13 = rtl_read_byte(uVar8,0x422);
      rtl_write_byte(uVar8,0x422,uVar13 & 0xbf);
      do {
        bVar4 = rtl_read_byte(uVar8,0x20a);
        rtl_write_byte(uVar8,0x20a,bVar4 | 1);
        rtl92ee_set_fw_rsvdpagepkt(param_1,0);
        bVar4 = rtl_read_byte(uVar8,899);
        for (cVar16 = '\0'; ((bVar4 & 0x10) != 0 && (cVar16 != '\x14')); cVar16 = cVar16 + '\x01') {
          __udelay(10);
          bVar4 = rtl_read_byte(uVar8,899);
        }
        rtl_write_byte(uVar8,899,bVar4 | 0x10);
        cVar16 = '\0';
        uVar6 = rtl_read_byte(uVar8,0x20a);
        while( true ) {
          if ((uVar6 & 1) != 0) {
            rtl_write_byte(uVar8,0x20a,1);
            goto LAB_ram_00013ae8;
          }
          if (cVar16 == '\x14') break;
          __udelay(0x32);
          cVar16 = cVar16 + '\x01';
          uVar6 = rtl_read_byte(uVar8,0x20a);
        }
        cVar15 = cVar15 + '\x01';
      } while (cVar15 != '\x05');
LAB_ram_00013ae8:
      _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),8,0);
      _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),0,0x10);
      if ((uVar13 & 0x40) != 0) {
        rtl_write_byte(uVar8,0x422);
      }
      uVar13 = rtl_read_byte(uVar8,0x101);
      rtl_write_byte(uVar8,0x101,uVar13 & 0xfe);
    }
    rtl92ee_set_fw_media_status_rpt_cmd(param_1,(byte)uVar2);
    return;
  case 0x40:
    rtl92ee_set_p2p_ps_offload_cmd(param_1,(byte)*param_3);
    return;
  case 0x41:
    *(byte *)(iVar11 + 0xb2f9) = (byte)*param_3;
    break;
  case 0x43:
    _rtl92ee_set_fw_clock_on_constprop_0(param_1,1);
    return;
  case 0x44:
    local_2d = (byte)*param_3;
    if (local_2d == 0) {
      local_2c = (uint)local_2c._1_3_ << 8;
      local_2e = local_2d;
      if (*(char *)(iVar11 + 0xb2fc) == '\0') {
        (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3c,&local_2d);
      }
      else {
        local_2d = 0x40;
        _rtl92ee_set_fw_clock_on_constprop_0(param_1,0);
        *(undefined1 *)(iVar11 + 0x6c8) = 0;
      }
      (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3d,&local_2c);
      pbVar5 = &local_2e;
      uVar8 = 0x41;
      pcVar10 = *(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50);
    }
    else {
      local_2d = 1;
      pcVar10 = *(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50);
      if (*(char *)(iVar11 + 0xb2fc) != '\0') {
        local_2c = CONCAT31(local_2c._1_3_,1);
        (*pcVar10)(param_1,0x41,&local_2d);
        (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))
                  (param_1,0x3d,iVar11 + 0xb2f7);
        *(undefined1 *)(iVar11 + 0x6c8) = 1;
        _rtl92ee_set_fw_clock_off(param_1,local_2c & 0xff);
        return;
      }
      local_2c = (uint)local_2c._1_3_ << 8;
      (*pcVar10)(param_1,0x41,&local_2d);
      (**(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3d,iVar11 + 0xb2f7);
      pbVar5 = (byte *)&local_2c;
      uVar8 = 0x3c;
      pcVar10 = *(code **)(*(int *)(*(int *)(iVar11 + 0xb8fc) + 0xc) + 0x50);
    }
LAB_ram_00013772:
    (*pcVar10)(param_1,uVar8,pbVar5);
    break;
  case 0x48:
    rtl92ee_phy_set_io_cmd(param_1,*(undefined4 *)param_3);
    return;
  case 0x52:
    (**(code **)(iVar11 + 0x754))(iVar11,0x6a8);
    uVar8 = 0x6a8;
LAB_ram_00013602:
    rtl_write_word(iVar11,uVar8);
    return;
  case 0x54:
    uVar2 = *param_3;
    if ((byte)uVar2 != 0) {
      _rtl92ee_stop_tx_beacon_isra_0(iVar11);
    }
    _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),0,8);
    rtl_write_dword(iVar11,0x560,*(undefined4 *)(iVar11 + 0x590));
    rtl_write_dword(iVar11,0x564,*(undefined4 *)(iVar11 + 0x594));
    _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),8,0);
    if ((byte)uVar2 != 0) {
      _rtl92ee_resume_tx_beacon_isra_0(*(undefined4 *)(param_1 + 0x40));
      return;
    }
    break;
  case 0x57:
    bVar9 = 3;
    uVar8 = 0x553;
LAB_ram_000136a8:
    rtl_write_byte(iVar11,uVar8,bVar9);
    return;
  case 0x5e:
    local_2c._0_2_ = CONCAT11((byte)*param_3,0xff);
    rtl92ee_fill_h2c_cmd(param_1,3,2,&local_2c);
  }
  return;
}

