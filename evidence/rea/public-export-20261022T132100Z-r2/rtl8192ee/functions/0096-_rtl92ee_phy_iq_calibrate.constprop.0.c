/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15a68; aliases: _rtl92ee_phy_iq_calibrate.constprop.0
 */

void _rtl92ee_phy_iq_calibrate_constprop_0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 local_ac [4];
  undefined1 auStack_9c [36];
  undefined4 local_78 [16];
  
  iVar14 = *(int *)(param_1 + 0x40);
  uVar5 = rtl_get_bbreg(param_1,0xc50,0xff);
  uVar6 = rtl_get_bbreg(param_1,0xc58,0xff);
  (*(code *)&memcpy)(local_78,&DAT_ram_0001c6f0,0x40);
  (*(code *)&memcpy)(local_ac,&DAT_ram_0001c730,0x10);
  (*(code *)&memcpy)(auStack_9c,&DAT_ram_0001c740,0x24);
  if (param_3 == 0) {
    _rtl92ee_phy_save_adda_registers(param_1,local_78,iVar14 + 0x8c4,0x10);
    uVar15 = *(undefined4 *)(param_1 + 0x40);
    iVar12 = 0;
    do {
      iVar3 = iVar12 * 4;
      uVar7 = rtl_read_byte(uVar15,local_ac[iVar12]);
      iVar12 = iVar12 + 1;
      *(undefined4 *)(iVar14 + 0x904 + iVar3) = uVar7;
    } while (iVar12 != 3);
    uVar15 = rtl_read_dword(uVar15,0x40);
    *(undefined4 *)(iVar14 + 0x910) = uVar15;
    _rtl92ee_phy_save_adda_registers(param_1,auStack_9c,iVar14 + 0x914,9);
  }
  iVar12 = 0;
  do {
    puVar11 = local_78 + iVar12;
    iVar12 = iVar12 + 1;
    rtl_set_bbreg(param_1,*puVar11,0xffffffff,0xfc01616);
  } while (iVar12 != 0x10);
  rtl_set_bbreg(param_1,0x800,0x1000000,0);
  rtl_set_bbreg(param_1,0xc04,0xffffffff,0x3a05600);
  rtl_set_bbreg(param_1,0xc08,0xffffffff,0x800e4);
  rtl_set_bbreg(param_1,0x874,0xffffffff,0x22208200);
  rtl_set_bbreg(param_1,0x870,0x400,1);
  rtl_set_bbreg(param_1,0x870,0x4000000,1);
  rtl_set_bbreg(param_1,0x860,0x400,1);
  rtl_set_bbreg(param_1,0x864,0x400,1);
  rtl_set_bbreg(param_1,0x520,0xff0000,0xff);
  rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
  rtl_set_bbreg(param_1,0xe40,0xffffffff,0x1007c00);
  rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
  bVar2 = false;
  do {
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
    rtl_set_rfreg(param_1,0,0xdf,0xfffff,0x180);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
    rtl_set_bbreg(param_1,0xe30,0xffffffff,0x18008c1c);
    rtl_set_bbreg(param_1,0xe34,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe50,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe54,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe38,0xffffffff,0x82140303);
    rtl_set_bbreg(param_1,0xe3c,0xffffffff,0x68160000);
    rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x462911);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf9000000);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
    iVar12 = 9;
    do {
      __udelay(1000);
      bVar1 = iVar12 != 0;
      iVar12 = iVar12 + -1;
    } while (bVar1);
    uVar8 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
    uVar9 = rtl_get_bbreg(param_1,0xe94,0xffffffff);
    uVar10 = rtl_get_bbreg(param_1,0xe9c,0xffffffff);
    bVar1 = false;
    if ((((uVar8 & 0x10000000) == 0) && ((uVar9 & 0x3ff0000) != 0x1420000)) &&
       ((uVar10 & 0x3ff0000) != 0x420000)) {
      uVar8 = rtl_get_bbreg(param_1,0xe94,0xffffffff);
      puVar13 = (uint *)(param_3 * 0x20 + param_2);
      *puVar13 = uVar8 >> 0x10 & 0x3ff;
      uVar8 = rtl_get_bbreg(param_1,0xe9c,0xffffffff);
      puVar13[1] = uVar8 >> 0x10 & 0x3ff;
      break;
    }
    bVar4 = !bVar2;
    bVar2 = true;
  } while (bVar4);
  do {
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
    rtl_set_rfreg(param_1,0,0xef,0xfffff,0x800a0);
    rtl_set_rfreg(param_1,0,0x30,0xfffff,0x30000);
    rtl_set_rfreg(param_1,0,0x31,0xfffff,0xf);
    rtl_set_rfreg(param_1,0,0x32,0xfffff,0xf117b);
    rtl_set_rfreg(param_1,0,0xdf,0xfffff,0x980);
    rtl_set_rfreg(param_1,0,0x56,0xfffff,0x51000);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
    rtl_set_bbreg(param_1,0xe40,0xffffffff,0x1007c00);
    rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
    rtl_set_bbreg(param_1,0xe30,0xffffffff,0x18008c1c);
    rtl_set_bbreg(param_1,0xe34,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe50,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe54,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe38,0xffffffff,0x82160c1f);
    rtl_set_bbreg(param_1,0xe3c,0xffffffff,0x68160c1f);
    rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x46a911);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xfa000000);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
    iVar12 = 9;
    do {
      __udelay(1000);
      bVar2 = iVar12 != 0;
      iVar12 = iVar12 + -1;
    } while (bVar2);
    uVar8 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
    uVar9 = rtl_get_bbreg(param_1,0xe94,0xffffffff);
    uVar10 = rtl_get_bbreg(param_1,0xe9c,0xffffffff);
    if ((((uVar8 & 0x10000000) == 0) && ((uVar9 & 0x3ff0000) != 0x1420000)) &&
       ((uVar10 & 0x3ff0000) != 0x420000)) {
      rtl_set_bbreg(param_1,0xe40,0xffffffff,uVar10 >> 0x10 & 0x3ff | uVar9 & 0x3ff0000 | 0x80007c00
                   );
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,0,0xef,0xfffff,0x800a0);
      rtl_set_rfreg(param_1,0,0x30,0xfffff,0x30000);
      rtl_set_rfreg(param_1,0,0x31,0xfffff,0xf);
      rtl_set_rfreg(param_1,0,0x32,0xfffff,0xf7ffa);
      rtl_set_rfreg(param_1,0,0xdf,0xfffff,0x980);
      rtl_set_rfreg(param_1,0,0x56,0xfffff,0x51000);
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
      rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
      rtl_set_bbreg(param_1,0xe30,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe34,0xffffffff,0x18008c1c);
      rtl_set_bbreg(param_1,0xe50,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe54,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe38,0xffffffff,0x82160c1f);
      rtl_set_bbreg(param_1,0xe3c,0xffffffff,0x28160c1f);
      rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x46a891);
      rtl_set_bbreg(param_1,0xe48,0xffffffff,0xfa000000);
      iVar12 = 9;
      rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
      do {
        iVar12 = iVar12 + -1;
        __udelay(1000);
      } while (iVar12 != -1);
      uVar8 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
      uVar9 = rtl_get_bbreg(param_1,0xea4,0xffffffff);
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,0,0xdf,0xfffff,0x180);
      if ((((uVar8 & 0x8000000) == 0) && ((uVar9 & 0x3ff0000) != 0x1320000)) &&
         ((uVar8 & 0x3ff0000) != 0x360000)) {
        uVar8 = rtl_get_bbreg(param_1,0xea4,0xffffffff);
        iVar12 = param_3 * 0x20 + param_2;
        *(uint *)(iVar12 + 8) = uVar8 >> 0x10 & 0x3ff;
        uVar8 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
        *(uint *)(iVar12 + 0xc) = uVar8 >> 0x10 & 0x3ff;
        break;
      }
    }
    else {
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,0,0xdf,0xfffff,0x180);
    }
    bVar2 = !bVar1;
    bVar1 = true;
  } while (bVar2);
  rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
  rtl_set_rfreg(param_1,0,0,0xfffff,0x10000);
  iVar12 = 0;
  rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
  do {
    puVar11 = local_78 + iVar12;
    iVar12 = iVar12 + 1;
    rtl_set_bbreg(param_1,*puVar11,0xffffffff,0xfc01616);
  } while (iVar12 != 0x10);
  rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
  rtl_set_bbreg(param_1,0xe40,0xffffffff,0x1007c00);
  rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
  bVar2 = false;
  do {
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
    rtl_set_rfreg(param_1,1,0xdf,0xfffff,0x180);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
    rtl_set_bbreg(param_1,0xe30,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe34,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe50,0xffffffff,0x18008c1c);
    rtl_set_bbreg(param_1,0xe54,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe58,0xffffffff,0x821403e2);
    rtl_set_bbreg(param_1,0xe5c,0xffffffff,0x68160000);
    rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x462911);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xfa000000);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
    iVar12 = 9;
    do {
      __udelay(1000);
      bVar1 = iVar12 != 0;
      iVar12 = iVar12 + -1;
    } while (bVar1);
    iVar12 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
    uVar8 = rtl_get_bbreg(param_1,0xeb4,0xffffffff);
    uVar9 = rtl_get_bbreg(param_1,0xebc,0xffffffff);
    bVar1 = false;
    if (((-1 < iVar12) && ((uVar8 & 0x3ff0000) != 0x1420000)) && ((uVar9 & 0x3ff0000) != 0x420000))
    {
      uVar8 = rtl_get_bbreg(param_1,0xeb4,0xffffffff);
      iVar12 = param_3 * 0x20 + param_2;
      *(uint *)(iVar12 + 0x10) = uVar8 >> 0x10 & 0x3ff;
      uVar8 = rtl_get_bbreg(param_1,0xebc,0xffffffff);
      *(uint *)(iVar12 + 0x14) = uVar8 >> 0x10 & 0x3ff;
      break;
    }
    bVar4 = !bVar2;
    bVar2 = true;
  } while (bVar4);
  do {
    bVar2 = bVar1;
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
    rtl_set_rfreg(param_1,1,0xef,0xfffff,0x800a0);
    rtl_set_rfreg(param_1,1,0x30,0xfffff,0x30000);
    rtl_set_rfreg(param_1,1,0x31,0xfffff,0xf);
    rtl_set_rfreg(param_1,1,0x32,0xfffff,0xf117b);
    rtl_set_rfreg(param_1,1,0xdf,0xfffff,0x980);
    rtl_set_rfreg(param_1,1,0x56,0xfffff,0x51000);
    rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
    rtl_set_bbreg(param_1,0xe40,0xffffffff,0x1007c00);
    rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
    rtl_set_bbreg(param_1,0xe30,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe34,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe50,0xffffffff,0x18008c1c);
    rtl_set_bbreg(param_1,0xe54,0xffffffff,0x38008c1c);
    rtl_set_bbreg(param_1,0xe58,0xffffffff,0x82160c1f);
    rtl_set_bbreg(param_1,0xe5c,0xffffffff,0x68160c1f);
    rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x46a911);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xfa000000);
    rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
    iVar12 = 9;
    do {
      __udelay(1000);
      bVar1 = iVar12 != 0;
      iVar12 = iVar12 + -1;
    } while (bVar1);
    iVar12 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
    uVar8 = rtl_get_bbreg(param_1,0xeb4,0xffffffff);
    uVar9 = rtl_get_bbreg(param_1,0xebc,0xffffffff);
    if (((iVar12 < 0) || ((uVar8 & 0x3ff0000) == 0x1420000)) || ((uVar9 & 0x3ff0000) == 0x420000)) {
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,1,0xdf,0xfffff,0x180);
    }
    else {
      rtl_set_bbreg(param_1,0xe40,0xffffffff,uVar9 >> 0x10 & 0x3ff | uVar8 & 0x3ff0000 | 0x80007c00)
      ;
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,1,0xef,0xfffff,0x800a0);
      rtl_set_rfreg(param_1,1,0x30,0xfffff,0x30000);
      rtl_set_rfreg(param_1,1,0x31,0xfffff,0xf);
      rtl_set_rfreg(param_1,1,0x32,0xfffff,0xf7ffa);
      rtl_set_rfreg(param_1,1,0xdf,0xfffff,0x980);
      rtl_set_rfreg(param_1,1,0x56,0xfffff,0x51000);
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0x80800000);
      rtl_set_bbreg(param_1,0xe44,0xffffffff,0x1004800);
      rtl_set_bbreg(param_1,0xe30,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe34,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe50,0xffffffff,0x38008c1c);
      rtl_set_bbreg(param_1,0xe54,0xffffffff,0x18008c1c);
      rtl_set_bbreg(param_1,0xe58,0xffffffff,0x82160c1f);
      rtl_set_bbreg(param_1,0xe5c,0xffffffff,0x28160c1f);
      rtl_set_bbreg(param_1,0xe4c,0xffffffff,0x46a891);
      rtl_set_bbreg(param_1,0xe48,0xffffffff,0xfa000000);
      iVar12 = 9;
      rtl_set_bbreg(param_1,0xe48,0xffffffff,0xf8000000);
      do {
        iVar12 = iVar12 + -1;
        __udelay(1000);
      } while (iVar12 != -1);
      uVar8 = rtl_get_bbreg(param_1,0xeac,0xffffffff);
      uVar9 = rtl_get_bbreg(param_1,0xec4,0xffffffff);
      uVar10 = rtl_get_bbreg(param_1,0xecc,0xffffffff);
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      rtl_set_rfreg(param_1,1,0xdf,0xfffff,0x180);
      if ((((uVar8 & 0x40000000) == 0) && ((uVar9 & 0x3ff0000) != 0x1320000)) &&
         ((uVar10 & 0x3ff0000) != 0x360000)) {
        uVar8 = rtl_get_bbreg(param_1,0xec4,0xffffffff);
        param_2 = param_3 * 0x20 + param_2;
        *(uint *)(param_2 + 0x18) = uVar8 >> 0x10 & 0x3ff;
        uVar8 = rtl_get_bbreg(param_1,0xecc,0xffffffff);
        *(uint *)(param_2 + 0x1c) = uVar8 >> 0x10 & 0x3ff;
        goto code_r0x00016aa8;
      }
    }
    bVar1 = true;
    if (bVar2) {
code_r0x00016aa8:
      rtl_set_bbreg(param_1,0xe28,0xffffffff,0);
      if (param_3 == 0) {
        return;
      }
      _rtl92ee_phy_reload_adda_registers(param_1,local_78,iVar14 + 0x8c4,0x10);
      uVar15 = *(undefined4 *)(param_1 + 0x40);
      iVar12 = 0;
      do {
        iVar3 = iVar12 * 4;
        puVar11 = local_ac + iVar12;
        iVar12 = iVar12 + 1;
        rtl_write_byte(uVar15,*puVar11,*(undefined1 *)(iVar14 + 0x904 + iVar3));
      } while (iVar12 != 3);
      rtl_write_dword(uVar15,0x40,*(undefined4 *)(iVar14 + 0x910));
      _rtl92ee_phy_reload_adda_registers(param_1,auStack_9c,iVar14 + 0x914,9);
      rtl_set_bbreg(param_1,0xc50,0xff,0x50);
      rtl_set_bbreg(param_1,0xc50,0xff,uVar5);
      rtl_set_bbreg(param_1,0xc50,0xff,0x50);
      rtl_set_bbreg(param_1,0xc58,0xff,uVar6);
      rtl_set_bbreg(param_1,0xe30,0xffffffff,0x1008c00);
                    /* WARNING: Could not recover jumptable at 0x00016bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      rtl_set_bbreg(param_1,0xe34,0xffffffff,0x1008c00);
      return;
    }
  } while( true );
}

