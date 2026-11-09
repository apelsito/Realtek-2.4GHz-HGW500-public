/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b634; aliases: rtl92ee_hw_init
 */

undefined4 rtl92ee_hw_init(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  bool bVar10;
  byte local_39;
  
  iVar7 = *(int *)(param_1 + 0x40);
  local_39 = 0;
  (*(code *)&printk)(&DAT_ram_0001cfb0);
  *(undefined1 *)(iVar7 + 0x62f) = 1;
  (**(code **)(*(int *)(iVar7 + 0xb900) + 0x1c))(param_1);
  local_39 = rtl_read_byte(iVar7,9);
  iVar2 = rtl_read_byte(iVar7,0x100);
  if ((((local_39 & 8) == 0) || (iVar2 == 0)) || (iVar2 == 0xea)) {
    *(undefined1 *)(iVar7 + 0x631) = 0;
    *(undefined1 *)(iVar7 + 0x6c9) = 0;
  }
  else {
    *(undefined1 *)(iVar7 + 0x631) = 1;
  }
  bVar1 = rtl_read_byte(iVar7,0x3f3);
  if ((bVar1 & 4) == 0) {
    iVar2 = 99;
    rtl_write_byte(iVar7,0x3f3,bVar1 | 4);
    do {
      iVar2 = iVar2 + -1;
      __udelay(1000);
    } while (iVar2 != -1);
  }
  uVar3 = rtl_read_byte(iVar7,0x3f3);
  if ((uVar3 & 3) != 0) {
    cVar6 = *(char *)(iVar7 + 0x631);
    uVar3 = rtl_read_byte(iVar7,0x1c);
    rtl_write_byte(iVar7,0x1c,uVar3 & 0xfc);
    bVar1 = rtl_read_byte(iVar7,0xcc);
    rtl_write_byte(iVar7,0xcc,bVar1 | 4);
    bVar1 = rtl_read_byte(iVar7,0x286);
    bVar10 = (bVar1 & 4) == 0;
    if (bVar10) {
      rtl_write_byte(iVar7,0x286,bVar1 | 4);
    }
    iVar2 = rtl_read_byte(iVar7,0x301);
    if (iVar2 != 0xff) {
      rtl_write_byte(iVar7,0x301);
    }
    if (cVar6 != '\0') {
      rtl_write_byte(iVar7,0x100);
    }
    uVar3 = rtl_read_byte(iVar7,3);
    rtl_write_byte(iVar7,3,uVar3 & 0xfe);
    bVar1 = rtl_read_byte(iVar7,3);
    rtl_write_byte(iVar7,3,bVar1 | 1);
    if (cVar6 != '\0') {
      rtl_write_byte(iVar7,0x100);
    }
    bVar1 = rtl_read_byte(iVar7,0xfa);
    rtl_write_byte(iVar7,0xfa,bVar1 | 2);
    if (cVar6 == '\0') {
      if (bVar10) {
        uVar3 = rtl_read_byte(iVar7,0x286);
        rtl_write_byte(iVar7,0x286,uVar3 & 0xfb);
      }
      rtl_write_byte(iVar7,0x301,iVar2);
    }
    uVar3 = rtl_read_byte(iVar7,0xcc);
    rtl_write_byte(iVar7,0xcc,uVar3 & 0xfb);
    *(undefined1 *)(iVar7 + 0x631) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x40);
  rtl_write_byte(iVar2,0x1c,0);
  uVar3 = rtl_read_dword(iVar2,0xf0);
  if ((uVar3 & 0x1000000) == 0) {
    bVar1 = rtl_read_byte(iVar2,0x16);
    rtl_write_byte(iVar2,0x16,bVar1 | 0x50);
  }
  rtl_write_byte(iVar2,0x7c);
  uVar3 = rtl_read_byte(iVar2,0x28);
  rtl_write_byte(iVar2,0x28,uVar3 & 0xfb);
  uVar3 = rtl_read_dword(iVar2,0x78);
  rtl_write_dword(iVar2,0x78,uVar3 & 0xfffffc7f);
  uVar3 = rtl_read_byte(iVar2,0x28);
  rtl_write_byte(iVar2,0x28,uVar3 & 0xbf);
  uVar3 = rtl_read_dword(iVar2,0x78);
  rtl_write_dword(iVar2,0x78,uVar3 & 0xffdfffff);
  iVar4 = (*(code *)&rtl_hal_pwrseqcmdparsing)(iVar2,0xff,0xf,4,rtl8192E_card_enable_flow);
  if (iVar4 != 0) {
    rtl_read_byte(iVar2,0x100);
    rtl_write_byte(iVar2,0x100,0xff);
    __udelay(2000);
    rtl_write_byte(iVar2,0x423,0x7f);
    __udelay(2000);
    bVar1 = rtl_read_byte(iVar2,8);
    rtl_write_byte(iVar2,8,bVar1 | 8);
    uVar3 = rtl_read_byte(iVar2,0x41);
    rtl_write_byte(iVar2,0x41,uVar3 & 0xef);
    rtl_write_word(iVar2,0x100,0x2ff);
    if (*(char *)(iVar2 + 0x631) == '\0') {
      uVar5 = *(undefined4 *)(param_1 + 0x40);
      rtl_write_dword(uVar5,0x200,0x80e60808);
      rtl_write_byte(uVar5,0x114,0xf7);
      rtl_write_word(uVar5,0x116,0x3cff);
      rtl_write_byte(uVar5,0x209,0xf7);
      rtl_write_byte(uVar5,0x229,0xf7);
      rtl_write_byte(uVar5,0x424,0xf7);
      rtl_write_byte(uVar5,0x457,0xf7);
      rtl_write_byte(uVar5,0x425,0xf7);
      rtl_write_byte(uVar5,0x45d,0xf7);
      iVar8 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
      if ((iVar8 == 0) || (hgw500_tx_pbp_256 == '\0')) {
        rtl_write_byte(uVar5,0x104,0x31);
      }
      else {
        rtl_write_byte(uVar5,0x104,0x21);
        (*(code *)&printk)(&DAT_ram_0001cfdc);
      }
      rtl_write_byte(uVar5,0x60f,4);
      uVar3 = rtl_read_byte(uVar5,0x226);
      rtl_write_byte(uVar5,0x226,uVar3 & 0xff | 1);
      cVar6 = '\0';
      do {
        if ((uVar3 & 1) == 0) break;
        uVar3 = rtl_read_byte(uVar5,0x226);
        __udelay(10);
        cVar6 = cVar6 + '\x01';
      } while (cVar6 != '\v');
    }
    rtl_write_dword(iVar2,0xb4,0xffffffff);
    rtl_write_dword(iVar2,0xbc,0xffffffff);
    uVar3 = (**(code **)(iVar2 + 0x754))(iVar2,0x10c);
    rtl_write_word(iVar2,0x10c,uVar3 & 0xf | 0xf5b1);
    rtl_write_byte(iVar2,0x421,0x1f);
    rtl_write_dword(iVar2,0x608,*(undefined4 *)(iVar2 + 0xcc88));
    rtl_write_word(iVar2,0x6a4,0xffff);
    rtl_write_dword(iVar2,0x604,*(undefined4 *)(iVar2 + 0xbc54));
    if (*(char *)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0x10) + 0x14) != '\0') {
      rtl_write_dword(iVar2,0x30c,0);
      rtl_write_dword(iVar2,0x314,0);
      rtl_write_dword(iVar2,0x31c,0);
      rtl_write_dword(iVar2,0x324,0);
      rtl_write_dword(iVar2,0x32c,0);
      rtl_write_dword(iVar2,0x334,0);
      rtl_write_dword(iVar2,0x344,0);
      rtl_write_dword(iVar2,0x33c,0);
    }
    rtl_write_dword(iVar2,0x308,*(undefined4 *)(iVar2 + 0xbb70));
    rtl_write_dword(iVar2,0x310,*(undefined4 *)(iVar2 + 0xbbc8));
    rtl_write_dword(iVar2,0x318,*(undefined4 *)(iVar2 + 0xbb44));
    rtl_write_dword(iVar2,800,*(undefined4 *)(iVar2 + 0xbb18));
    rtl_write_dword(iVar2,0x328,*(undefined4 *)(iVar2 + 0xbaec));
    rtl_read_dword(iVar2,0x328);
    rtl_write_dword(iVar2,0x330,*(undefined4 *)(iVar2 + 0xbac0));
    rtl_write_dword(iVar2,0x340,*(undefined4 *)(iVar2 + 0xbbf4));
    rtl_write_dword(iVar2,0x338,*(undefined4 *)(iVar2 + 0xbc5c));
    rtl_write_dword(iVar2,0x39c,0x3fffffff);
    bVar1 = rtl_read_byte(iVar2,0x303);
    rtl_write_byte(iVar2,0x303,bVar1 | 0xf7);
    rtl_write_dword(iVar2,0x304,0);
    rtl_write_dword(iVar2,0x1c0,0);
    rtl_write_word(iVar2,0x380,0x1200);
    rtl_write_word(iVar2,900,0x1200);
    rtl_write_word(iVar2,0x386,0x1200);
    rtl_write_word(iVar2,0x388,0x1200);
    rtl_write_word(iVar2,900,0x1200);
    rtl_write_word(iVar2,0x38a,0x1200);
    rtl_write_word(iVar2,0x38c,0x1200);
    rtl_write_word(iVar2,0x38e,0x1200);
    rtl_write_word(iVar2,0x390,0x1200);
    rtl_write_word(iVar2,0x392,0x1200);
    rtl_write_word(iVar2,0x394,0x1200);
    rtl_write_word(iVar2,0x396,0x1200);
    rtl_write_word(iVar2,0x398,0x1200);
    rtl_write_word(iVar2,0x39a,0x1200);
    if ((*(char *)(iVar2 + 0xbc50) == '\0') ||
       ((iVar8 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar8 != 0 &&
        (hgw500_force_txbd64_width != '\0')))) {
      uVar3 = 0xa200;
    }
    else {
      uVar3 = 0x2200;
    }
    rtl_write_word(iVar2,0x382,uVar3);
    (*(code *)&printk)(&DAT_ram_0001d020,*(undefined1 *)(iVar2 + 0xbc50),hgw500_force_txbd64_width,
                       uVar3 >> 0xf,uVar3);
    rtl_write_dword(iVar2,0x39c,0xffffffff);
    iVar2 = *(int *)(param_1 + 0x40);
    if (*(char *)(iVar2 + 0x62d) == '\0') {
      if ((*(int *)(iVar2 + 0xb300) == 0x10000000) || (*(int *)(iVar2 + 0xb300) == 0)) {
        rtl92ee_sw_led_on();
      }
      else {
        rtl92ee_sw_led_off(param_1,iVar2 + 0xb2a8);
      }
    }
  }
  (*(code *)&printk)(&DAT_ram_0001d07c,iVar4);
  rtl_write_byte(iVar7,0x577,3);
  rtl_write_byte(iVar7,0x78,0x2a);
  rtl_write_byte(iVar7,0x79,0);
  rtl_write_byte(iVar7,0x28,0x83);
  if (*(char *)(iVar7 + 0xb9b1) == '\x01') {
    rtl_write_byte(iVar7,100,0);
    rtl_write_byte(iVar7,0x65,1);
  }
  if (iVar4 == 0) {
    (*(code *)&printk)(&DAT_ram_0001d0b0);
  }
  else {
    *(undefined2 *)(iVar7 + 0x6ea) = 0;
    rtl_write_word(iVar7,0x300,0x8000);
    iVar2 = rtl92ee_download_fw(param_1,0);
    if (iVar2 == 0) {
      *(undefined1 *)(iVar7 + 0x6ba) = 1;
      pcVar9 = rtl_get_rfreg_constprop_0;
      (*(code *)&printk)(&DAT_ram_0001d0d0,*(undefined4 *)(iVar7 + 0x6ac));
      *(undefined1 *)(iVar7 + 0xb2f9) = 0;
      *(undefined1 *)(iVar7 + 0x6c7) = 0;
      *(undefined2 *)(iVar7 + 0x6c8) = 0;
      *(undefined1 *)(iVar7 + 0x6b9) = 0;
      rtl92ee_phy_mac_config(param_1);
      rtl92ee_phy_bb_config(param_1);
      rtl92ee_phy_rf_config(param_1);
      (*(code *)&printk)(&DAT_ram_0001d10c);
      uVar5 = (*pcVar9)(param_1,0,0x18);
      *(undefined4 *)(iVar7 + 0x9f78) = uVar5;
      uVar5 = (*pcVar9)(param_1,1,0x18);
      *(undefined4 *)(iVar7 + 0x9f7c) = uVar5;
      uVar5 = (*pcVar9)(param_1,0,0x1a);
      pcVar9 = rtl_set_rfreg;
      *(undefined4 *)(iVar7 + 0x9f8c) = uVar5;
      *(uint *)(iVar7 + 0x9f78) = *(uint *)(iVar7 + 0x9f78) | 0xc00;
      rtl_set_rfreg(param_1,0,0x18,0xfffff);
      (*pcVar9)(param_1,1,0x18,0xfffff,*(undefined4 *)(iVar7 + 0x9f78));
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xb8))
                (param_1,0x800,0x1000000,1);
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xb8))
                (param_1,0x800,0x2000000,1);
      (*pcVar9)(param_1,0,0xb1,0xfffff,0x54418);
      iVar2 = *(int *)(param_1 + 0x40);
      rtl_write_dword(iVar2,0x440,0xfff);
      rtl_write_dword(iVar2,0x444,0x10);
      rtl_write_dword(iVar2,0x448,0x3e0ff000);
      rtl_write_dword(iVar2,0x44c,0x10);
      rtl_write_dword(iVar2,0x450,0xff000);
      rtl_write_byte(iVar2,0x51b,9);
      rtl_write_word(iVar2,0x420,0x1f80);
      rtl_write_word(iVar2,0x42a,0x707);
      rtl_write_dword(iVar2,0x4cc,0x201ffff);
      rtl_write_dword(iVar2,0x430,0x1000000);
      rtl_write_dword(iVar2,0x434,0x7060504);
      rtl_write_dword(iVar2,0x438,0x1000000);
      rtl_write_dword(iVar2,0x43c,0x7060504);
      rtl_write_byte(iVar2,0x55a,2);
      rtl_write_byte(iVar2,0x55d,0xff);
      *(undefined4 *)(iVar2 + 0xcca4) = 0x1d;
      rtl_write_byte(iVar2,0x550,0x1d);
      rtl_write_byte(iVar2,0x551,0);
      rtl_write_byte(iVar2,0x541,0xff);
      rtl_write_byte(iVar2,0x512,0);
      rtl_write_byte(iVar2,0x51a,0x16);
      rtl_write_word(iVar2,0x546,0x40);
      rtl_write_word(iVar2,0x4c8,0x8ff);
      rtl_write_dword(iVar2,0x460,0x3086666);
      rtl_write_byte(iVar2,0x640,0x40);
      rtl_write_word(iVar2,0x428,0x100a);
      rtl_write_word(iVar2,0x63a,0x100a);
      rtl_write_word(iVar2,0x514,0x100a);
      rtl_write_word(iVar2,0x516,0x100a);
      rtl_write_byte(iVar2,0x4c7,0x80);
      rtl_write_byte(iVar2,0x60c,0x20);
      rtl_write_word(iVar2,0x4ca,0x1717);
      rtl_write_dword(iVar2,0x620,0xffffffff);
      rtl_write_dword(iVar2,0x624,0xffffffff);
      *(undefined1 *)(iVar7 + 0x631) = 1;
      (*(code *)&rtl_cam_reset_all_entry)(param_1);
      rtl92ee_enable_hw_security_config(param_1);
      *(undefined4 *)(iVar7 + 0xb314) = 0;
      (**(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x50))(param_1,0,iVar7 + 0x210);
      iVar8 = *(int *)(param_1 + 0x40);
      rtl_write_word(iVar8,0x3f0,0x78);
      rtl_write_byte(iVar8,0x3f2,2);
      iVar2 = rtl_read_byte(iVar8,0x3f2);
      iVar4 = 0;
      while (iVar2 != 0) {
        if (iVar4 == 0x14) goto LAB_ram_0001c21a;
        __udelay(10);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
        iVar4 = iVar4 + 1;
      }
      uVar3 = rtl_read_dword(iVar8,0x3ec);
      if ((uVar3 & 0xff00) != 0x2000) {
        rtl_write_dword(iVar8,1000,uVar3 & 0xffff00ff | 0x2000);
        rtl_write_word(iVar8,0x3f0,0xf078);
        rtl_write_byte(iVar8,0x3f2,1);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
        for (iVar4 = 0; (iVar2 != 0 && (iVar4 != 0x14)); iVar4 = iVar4 + 1) {
          __udelay(10);
          iVar2 = rtl_read_byte(iVar8,0x3f2);
        }
      }
LAB_ram_0001c21a:
      rtl_write_word(iVar8,0x3f0,0x70c);
      rtl_write_byte(iVar8,0x3f2,2);
      iVar2 = rtl_read_byte(iVar8,0x3f2);
      iVar4 = 0;
      while (iVar2 != 0) {
        if (iVar4 == 0x14) goto LAB_ram_0001c24a;
        __udelay(10);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
        iVar4 = iVar4 + 1;
      }
      uVar3 = rtl_read_dword(iVar8,0x3ec);
      rtl_write_dword(iVar8,1000,uVar3 | 0x80000000);
      rtl_write_word(iVar8,0x3f0,0xf70c);
      rtl_write_byte(iVar8,0x3f2,1);
LAB_ram_0001c24a:
      iVar2 = rtl_read_byte(iVar8,0x3f2);
      for (iVar4 = 0; (iVar2 != 0 && (iVar4 != 0x14)); iVar4 = iVar4 + 1) {
        __udelay(10);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
      }
      rtl_write_word(iVar8,0x3f0,0x718);
      rtl_write_byte(iVar8,0x3f2,2);
      iVar2 = rtl_read_byte(iVar8,0x3f2);
      for (iVar4 = 0; (iVar2 != 0 && (iVar4 != 0x14)); iVar4 = iVar4 + 1) {
        __udelay(10);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
      }
      if ((*(char *)(iVar8 + 0xb2ee) != '\0') || (iVar2 == 0)) {
        uVar3 = rtl_read_dword(iVar8,0x3ec);
        rtl_write_dword(iVar8,1000,uVar3 | 0x1800);
        rtl_write_word(iVar8,0x3f0,0xf718);
        rtl_write_byte(iVar8,0x3f2,1);
      }
      iVar2 = rtl_read_byte(iVar8,0x3f2);
      for (iVar4 = 0; (iVar2 != 0 && (iVar4 != 0x14)); iVar4 = iVar4 + 1) {
        __udelay(10);
        iVar2 = rtl_read_byte(iVar8,0x3f2);
      }
      (**(code **)(*(int *)(iVar7 + 0xb900) + 0x20))(param_1);
      rtl92ee_bt_hw_init(param_1);
      *(undefined1 *)(iVar7 + 0x62f) = 0;
      if (*(int *)(iVar7 + 0xb314) == 0) {
        (*(code *)&printk)(&DAT_ram_0001d13c,*(undefined1 *)(iVar7 + 0x93c));
        if (*(char *)(iVar7 + 0x93c) == '\0') {
          rtl92ee_phy_iq_calibrate(param_1,0);
          *(undefined1 *)(iVar7 + 0x93c) = 1;
        }
        else {
          rtl92ee_phy_iq_calibrate(param_1,1);
        }
        (*(code *)&printk)(&DAT_ram_0001d17c);
      }
      *(undefined1 *)(iVar7 + 0x93d) = 1;
      if (*(char *)(iVar7 + 0x889) == '\x02') {
        *(undefined1 *)(iVar7 + 0x93e) = 1;
      }
      (*(code *)&efuse_one_byte_read)(param_1,0x1fa,&local_39);
      if ((local_39 & 1) == 0) {
        (*pcVar9)(param_1,0,0x15,0xf,5);
      }
      if (((local_39 & 2) == 0) && (*(char *)(iVar7 + 0x889) == '\x02')) {
        (*pcVar9)(param_1,1,0x15,0xf,5);
      }
      rtl_write_byte(iVar7,0x652,0xeb);
      uVar3 = rtl_read_dword(iVar7,0x10);
      rtl_write_byte(iVar7,0x14,0x75);
      rtl_write_dword(iVar7,0x10,uVar3 & 0xfff00fff | 0x7e000);
      rtl92ee_dm_init(param_1);
      rtl_write_dword(iVar7,0x4fc,0);
      (*(code *)&printk)(&DAT_ram_0001d1ac);
      return 0;
    }
    *(undefined1 *)(iVar7 + 0x6ba) = 0;
  }
  return 1;
}

