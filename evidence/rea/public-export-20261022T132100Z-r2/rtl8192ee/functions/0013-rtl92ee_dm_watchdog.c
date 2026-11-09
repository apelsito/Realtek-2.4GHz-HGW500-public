/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x105ac; aliases: rtl92ee_dm_watchdog
 */

void rtl92ee_dm_watchdog(int param_1)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined1 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined1 uVar17;
  int iVar18;
  int iVar19;
  char cVar20;
  undefined1 auStack_30 [2];
  char local_2e;
  char local_2d;
  undefined4 local_2c;
  
  iVar15 = *(int *)(param_1 + 0x40);
  local_2d = '\x01';
  local_2e = '\0';
  (**(code **)(*(int *)(*(int *)(iVar15 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x41,&local_2e);
  (**(code **)(*(int *)(*(int *)(iVar15 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x56,&local_2d);
  if (*(int *)(iVar15 + 0xb344) != 0) {
    local_2d = '\0';
  }
  if (*(int *)(iVar15 + 0xb314) != 0) {
    return;
  }
  if (local_2e != '\0') {
    return;
  }
  if (local_2d == '\0') {
    return;
  }
  if (*(char *)(iVar15 + 0xb2ea) != '\0') {
    return;
  }
  iVar15 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar15 + 0xa055) = 0;
  uVar6 = *(uint *)(iVar15 + 0x3f4);
  if (uVar6 == 2) {
    if (1 < *(uint *)(iVar15 + 0x4d0)) {
      *(undefined1 *)(iVar15 + 0xa055) = 1;
    }
  }
  else if ((uVar6 < 8) && ((0x8aU >> ((byte)uVar6 & 0x1f) & 1) != 0)) {
    *(int *)(((uint)auStack_30 & 0xffffe000) + 4) =
         *(int *)(((uint)auStack_30 & 0xffffe000) + 4) + 0x200;
    cVar20 = '\0';
    for (puVar16 = *(undefined4 **)(iVar15 + 0xb8cc); puVar16 != (undefined4 *)(iVar15 + 0xb8cc);
        puVar16 = (undefined4 *)*puVar16) {
      cVar20 = cVar20 + '\x01';
    }
    (*(code *)&__local_bh_enable_ip)(0x10b66,0x200);
    if (cVar20 == '\x01') {
      *(undefined1 *)(iVar15 + 0xa055) = 1;
    }
  }
  iVar15 = *(int *)(param_1 + 0x40);
  rtl_set_bbreg(param_1,0xc00,0x80000000,1);
  rtl_set_bbreg(param_1,0xd00,0x80000000,1);
  uVar6 = rtl_get_bbreg(param_1,0xcf0,0xffffffff);
  *(uint *)(iVar15 + 0xb8a0) = uVar6 & 0xffff;
  *(uint *)(iVar15 + 0xb8a4) = uVar6 >> 0x10;
  uVar6 = rtl_get_bbreg(param_1,0xda0,0xffffffff);
  *(uint *)(iVar15 + 0xb8b4) = uVar6 & 0xffff;
  *(uint *)(iVar15 + 0xb890) = uVar6 >> 0x10;
  uVar6 = rtl_get_bbreg(param_1,0xda4,0xffffffff);
  *(uint *)(iVar15 + 0xb894) = uVar6 & 0xffff;
  *(uint *)(iVar15 + 0xb898) = uVar6 >> 0x10;
  uVar6 = rtl_get_bbreg(param_1,0xda8,0xffffffff);
  *(uint *)(iVar15 + 0xb89c) = uVar6 & 0xffff;
  *(uint *)(iVar15 + 0xb8a8) =
       *(int *)(iVar15 + 0xb890) + *(int *)(iVar15 + 0xb894) + *(int *)(iVar15 + 0xb898) +
       *(int *)(iVar15 + 0xb8a0) + *(int *)(iVar15 + 0xb8a4) + (uVar6 & 0xffff);
  uVar6 = rtl_get_bbreg(param_1,0x8c4,0xffffffff);
  *(uint *)(iVar15 + 0xb8c4) = uVar6 & 0xffff;
  *(uint *)(iVar15 + 0xb8c0) = uVar6 >> 0x10;
  rtl_set_bbreg(param_1,0xa2c,0x1000,1);
  rtl_set_bbreg(param_1,0xa2c,0x4000,1);
  uVar7 = rtl_get_bbreg(param_1,0xa5c,0xff);
  *(undefined4 *)(iVar15 + 0xb8ac) = uVar7;
  uVar6 = rtl_get_bbreg(param_1,0xa58,0xff000000);
  *(uint *)(iVar15 + 0xb8ac) = (uVar6 & 0xff) * 0x100 + *(int *)(iVar15 + 0xb8ac);
  uVar6 = rtl_get_bbreg(param_1,0xa60,0xffffffff);
  uVar6 = (uVar6 & 0xff) << 8 | uVar6 >> 8 & 0xff;
  *(uint *)(iVar15 + 0xb8b8) = uVar6;
  *(int *)(iVar15 + 0xb8b0) =
       *(int *)(iVar15 + 0xb8a0) + *(int *)(iVar15 + 0xb8a4) + *(int *)(iVar15 + 0xb890) +
       *(int *)(iVar15 + 0xb894) + *(int *)(iVar15 + 0xb898) + *(int *)(iVar15 + 0xb89c) +
       *(int *)(iVar15 + 0xb8ac);
  *(uint *)(iVar15 + 0xb8bc) = *(int *)(iVar15 + 0xb8b4) + uVar6;
  rtl_set_bbreg(param_1,0xc0c,0x80000000,1);
  rtl_set_bbreg(param_1,0xc0c,0x80000000,0);
  rtl_set_bbreg(param_1,0xd00,0x8000000,1);
  rtl_set_bbreg(param_1,0xd00,0x8000000,0);
  rtl_set_bbreg(param_1,0xc00,0x80000000,0);
  rtl_set_bbreg(param_1,0xd00,0x80000000,0);
  rtl_set_bbreg(param_1,0xa2c,0x3000,0);
  rtl_set_bbreg(param_1,0xa2c,0x3000,2);
  rtl_set_bbreg(param_1,0xa2c,0xc000,0);
  rtl_set_bbreg(param_1,0xa2c,0xc000,2);
  iVar15 = *(int *)(param_1 + 0x40);
  local_2c = 0;
  if ((*(uint *)(iVar15 + 0x3f4) < 8) &&
     ((0x8aU >> ((byte)*(uint *)(iVar15 + 0x3f4) & 0x1f) & 1) != 0)) {
    *(int *)(((uint)auStack_30 & 0xffffe000) + 4) =
         *(int *)(((uint)auStack_30 & 0xffffe000) + 4) + 0x200;
    cVar20 = '\0';
    iVar18 = 0xff;
    iVar19 = 0;
    for (puVar16 = *(undefined4 **)(iVar15 + 0xb8cc); puVar16 != (undefined4 *)(iVar15 + 0xb8cc);
        puVar16 = (undefined4 *)*puVar16) {
      iVar9 = puVar16[0x38];
      cVar20 = cVar20 + '\x01';
      iVar18 = iVar18 * (uint)(iVar9 > iVar18) + iVar9 * (uint)(iVar9 <= iVar18);
      iVar19 = iVar19 * (uint)(iVar19 > iVar9) + iVar9 * (uint)(iVar19 <= iVar9);
      local_2c._0_2_ = CONCAT11(0x20,cVar20);
      local_2c = (uint)CONCAT12((char)*(undefined4 *)(iVar15 + 0x9ffc),(undefined2)local_2c);
      rtl92ee_fill_h2c_cmd(param_1,0x42,4,&local_2c);
    }
    (*(code *)&__local_bh_enable_ip)(0x10918,0x200);
    *(int *)(iVar15 + 0xa000) = iVar19;
    if (iVar18 == 0xff) {
      *(undefined4 *)(iVar15 + 0x9ff4) = 0;
    }
    else {
      *(int *)(iVar15 + 0x9ff4) = iVar18;
    }
  }
  if (*(char *)(iVar15 + 0xa011) == '\0') {
    rtl_write_byte(iVar15,0x4fe,*(uint *)(iVar15 + 0x9ffc) & 0xff);
  }
  else {
    local_2c = CONCAT22((ushort)(byte)*(uint *)(iVar15 + 0x9ffc),0x2000);
    rtl92ee_fill_h2c_cmd(param_1,0x42,4,&local_2c);
  }
  iVar18 = *(int *)(param_1 + 0x40);
  rtl_write_byte(iVar18,0xcb0,*(undefined1 *)(iVar18 + 0xb444));
  rtl_write_byte(iVar18,0xcb1,*(undefined1 *)(iVar18 + 0xb445));
  rtl_write_byte(iVar18,0xcb2,*(undefined1 *)(iVar18 + 0xb448));
  rtl_write_byte(iVar18,0xcb3,*(undefined1 *)(iVar18 + 0xb449));
  rtl_write_byte(iVar18,0xcb4,*(undefined1 *)(iVar18 + 0xb41c));
  rtl_write_byte(iVar18,0xcb5,*(undefined1 *)(iVar18 + 0xb420));
  rtl_write_word(iVar18,0xcb6,*(undefined2 *)(iVar18 + 0xb44e));
  rtl_write_word(iVar18,0xcb8,*(undefined2 *)(iVar18 + 0xb450));
  rtl_write_word(iVar18,0xcba,*(undefined2 *)(iVar18 + 0xb456));
  rtl_write_word(iVar18,0xcbc,*(undefined2 *)(iVar18 + 0xb458));
  iVar18 = *(int *)(param_1 + 0x40);
  if ((*(uint *)(iVar18 + 0x4d0) < 2) || ((*(uint *)(iVar18 + 0x3f4) & 0xfffffffd) == 1)) {
    uVar10 = (undefined1)*(undefined4 *)(iVar18 + 0x9ff4);
  }
  else {
    uVar10 = (undefined1)*(undefined4 *)(iVar18 + 0x9ffc);
  }
  *(undefined1 *)(iVar18 + 0xb943) = uVar10;
  *(undefined1 *)(iVar15 + 0xb944) = *(undefined1 *)(iVar15 + 0xb943);
  iVar15 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar15 + 0x4ea) == '\0') {
    uVar8 = *(uint *)(iVar15 + 0xb92c);
    bVar4 = *(byte *)(iVar15 + 0xb95f);
    uVar6 = uVar8 & 0xff;
    if (*(uint *)(iVar15 + 0x4d0) < 2) {
      *(undefined1 *)(iVar15 + 0xb941) = 0x5a;
      bVar5 = 0;
LAB_ram_00010c20:
      uVar11 = 0x1e;
    }
    else {
      uVar12 = (uint)*(byte *)(iVar15 + 0xb944);
      bVar5 = bVar4 ^ 1;
      uVar11 = uVar12 + 10;
      if (uVar11 < 0x5b) {
        if (uVar11 < 0x1e) {
          uVar11 = 0x1e;
        }
      }
      else {
        uVar11 = 0x5a;
      }
      *(char *)(iVar15 + 0xb941) = (char)uVar11;
      if (*(char *)(iVar15 + 0xa055) == '\0') {
LAB_ram_00010b22:
        bVar4 = 0;
        goto LAB_ram_00010c20;
      }
      uVar11 = uVar12;
      if (0x32 < uVar12) {
        uVar11 = 0x32;
      }
      bVar4 = 0;
      if (uVar12 < 0x1e) goto LAB_ram_00010b22;
    }
    uVar12 = *(uint *)(iVar15 + 0xb8b0);
    uVar10 = (undefined1)uVar11;
    if (uVar12 < 0x2711) {
      if (*(int *)(iVar15 + 0xb924) == 0) {
        uVar17 = 0;
        if (2 < *(byte *)(iVar15 + 0xb94d)) goto LAB_ram_00010c52;
        bVar14 = *(byte *)(iVar15 + 0xb94e);
        iVar18 = bVar14 - 1;
        if (iVar18 < (int)uVar11) {
          *(undefined1 *)(iVar15 + 0xb94e) = uVar10;
          *(undefined1 *)(iVar15 + 0xb942) = uVar10;
        }
        else {
          *(char *)(iVar15 + 0xb94e) = (char)iVar18;
          *(byte *)(iVar15 + 0xb942) = bVar14;
        }
      }
      else {
        *(int *)(iVar15 + 0xb924) = *(int *)(iVar15 + 0xb924) + -1;
      }
    }
    else {
      if (*(char *)(iVar15 + 0xb94d) != '\x03') {
        *(char *)(iVar15 + 0xb94d) = *(char *)(iVar15 + 0xb94d) + '\x01';
      }
      if (*(byte *)(iVar15 + 0xb94e) < uVar6) {
        *(char *)(iVar15 + 0xb94e) = (char)uVar8;
        uVar17 = 1;
LAB_ram_00010c52:
        *(undefined1 *)(iVar15 + 0xb94d) = uVar17;
      }
      else {
        bVar14 = *(byte *)(iVar15 + 0xb941);
        if (2 < *(byte *)(iVar15 + 0xb94d)) {
          uVar11 = *(byte *)(iVar15 + 0xb94e) + 1;
          if (uVar11 <= bVar14) {
            bVar14 = (byte)uVar11;
          }
          *(byte *)(iVar15 + 0xb942) = bVar14;
          *(undefined4 *)(iVar15 + 0xb924) = 0xe10;
        }
      }
    }
    uVar2 = *(ushort *)(iVar15 + 0xa074);
    if (uVar2 < 5) {
      *(undefined1 *)(iVar15 + 0xb942) = 0x1e;
    }
    uVar11 = (uint)*(byte *)(iVar15 + 0xb941);
    uVar13 = (uint)*(byte *)(iVar15 + 0xb942);
    if (uVar11 < *(byte *)(iVar15 + 0xb942)) {
      *(byte *)(iVar15 + 0xb942) = *(byte *)(iVar15 + 0xb941);
      uVar13 = uVar11;
    }
    if (*(uint *)(iVar15 + 0x4d0) < 2) {
      if (bVar4 != 0) goto LAB_ram_0001102e;
      if (10000 < uVar12) goto LAB_ram_00010ffc;
      if (8000 < uVar12) goto LAB_ram_00011006;
      if (uVar12 < 500) {
LAB_ram_00011018:
        uVar8 = uVar8 - 2;
        goto LAB_ram_00011008;
      }
    }
    else if (bVar5 == 0) {
      if (uVar12 < 0x401) {
        if (uVar12 < 0x301) {
          if (uVar12 < 0x200) {
            if (4 < uVar2) goto LAB_ram_00011018;
          }
          else if ((4 < uVar2) || (uVar12 == 0x300)) goto LAB_ram_00010cc6;
LAB_ram_0001102e:
          uVar6 = uVar13;
          goto LAB_ram_00010cc6;
        }
LAB_ram_00011006:
        uVar8 = uVar8 + 2;
      }
      else {
LAB_ram_00010ffc:
        uVar8 = uVar8 + 4;
      }
LAB_ram_00011008:
      uVar6 = uVar8 & 0xff;
    }
    else {
      uVar6 = (uint)*(byte *)(iVar15 + 0xb944);
      if (0x32 < uVar6) {
        uVar6 = 0x32;
      }
      *(undefined1 *)(iVar15 + 0xb94d) = 0;
    }
LAB_ram_00010cc6:
    if (uVar6 < uVar11) {
      uVar11 = uVar6;
    }
    if (uVar11 < uVar13) {
      uVar11 = uVar13;
    }
    rtl92ee_dm_write_dig(param_1,uVar11);
    *(undefined1 *)(iVar15 + 0xb95c) = uVar10;
    *(bool *)(iVar15 + 0xb95f) = 1 < *(uint *)(iVar15 + 0x4d0);
  }
  iVar15 = *(int *)(param_1 + 0x40);
  local_2c = local_2c & 0xffffff00;
  (**(code **)(*(int *)(*(int *)(iVar15 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x41,&local_2c);
  if ((char)local_2c == '\0') {
    bVar4 = rtl_get_bbreg(param_1,0xc50,0xff);
    bVar5 = rtl_get_bbreg(param_1,0xc58,0xff);
    if (bVar4 < 0x29) {
      if (((bVar4 < 0x25) && (bVar5 < 0x25)) && (*(char *)(iVar15 + 0x632) != '\0')) {
        rtl_write_byte(iVar15,0xc4c,0x7f);
        rtl_write_byte(iVar15,0xc4e,0x7f);
        *(undefined1 *)(iVar15 + 0x632) = 0;
      }
    }
    else if ((0x28 < bVar5) && (*(char *)(iVar15 + 0x632) == '\0')) {
      rtl_write_byte(iVar15,0xc4c,3);
      rtl_write_byte(iVar15,0xc4e,0);
      *(undefined1 *)(iVar15 + 0x632) = 1;
    }
  }
  iVar15 = *(int *)(param_1 + 0x40);
  if (*(uint *)(iVar15 + 0x4d0) < 2) {
LAB_ram_00010d3a:
    if (*(uint *)(iVar15 + 0xb8ac) < 0x3e9) {
      uVar7 = 0x40;
    }
    else {
LAB_ram_00011124:
      uVar7 = 0x83;
    }
  }
  else {
    if (*(byte *)(iVar15 + 0xb944) < 0x1a) {
      if (0xe < *(byte *)(iVar15 + 0xb944) - 0xb) goto LAB_ram_00010d3a;
      goto LAB_ram_00011124;
    }
    uVar7 = 0xcd;
  }
  rtl92ee_dm_write_cck_cca_thres(param_1,uVar7);
  iVar15 = *(int *)(param_1 + 0x40);
  if (((*(char *)(iVar15 + 0x698) != '\0') && (*(char *)(iVar15 + 0xa011) != '\0')) &&
     ((*(int *)(iVar15 + 0x4d0) == 2 && (*(int *)(iVar15 + 0x3f4) == 2)))) {
    uVar11 = *(uint *)(iVar15 + 0x9ffc);
    bVar1 = (int)uVar11 < (int)(uint)*(byte *)(iVar15 + 0xb3c5);
    *(bool *)(iVar15 + 0xb3c6) = bVar1;
    *(bool *)(iVar15 + 0xb3c7) = bVar1;
    uVar6 = *(uint *)(*(int *)(param_1 + 0x40) + 0xb37c);
    uVar8 = *(uint *)(*(int *)(param_1 + 0x40) + 0xb388);
    cVar20 = *(char *)(iVar15 + 0xb379);
    if (cVar20 == '\x02') {
      uVar6 = uVar6 + 5;
    }
    else if (cVar20 == '\x03') {
      uVar6 = uVar6 + 5;
      uVar8 = uVar8 + 5;
    }
    if (uVar6 < uVar11) {
      cVar3 = '\x01';
    }
    else if (uVar8 < uVar11) {
      cVar3 = '\x02';
    }
    else {
      cVar3 = '\x03';
    }
    if (cVar20 != cVar3) {
      *(char *)(iVar15 + 0xb379) = cVar3;
      iVar18 = (*(code *)&ieee80211_find_sta)
                         (*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3f0),iVar15 + 0x566);
      if (iVar18 != 0) {
        (**(code **)(*(int *)(*(int *)(iVar15 + 0xb8fc) + 0xc) + 0x54))
                  (param_1,iVar18,*(undefined1 *)(iVar15 + 0xb379),1);
      }
      *(undefined1 *)(iVar15 + 0xb3c4) = *(undefined1 *)(iVar15 + 0xb379);
    }
  }
  iVar15 = *(int *)(param_1 + 0x40);
  if (0x100 < *(ushort *)(iVar15 + 0xa076)) {
    *(undefined1 *)(iVar15 + 0xa00b) = 1;
  }
  *(undefined2 *)(iVar15 + 0xa076) = 0;
  if (*(char *)(iVar15 + 0xa00b) == '\0') {
    bVar4 = *(byte *)(iVar15 + 0xa00e) ^ 1;
  }
  else {
    bVar4 = 0;
  }
  if (*(short *)(*(int *)(param_1 + 0x40) + 0x588) != 2) {
    if (bVar4 == 0) {
      if (*(char *)(iVar15 + 0xa00a) != '\0') {
        local_2c = local_2c & 0xffffff00;
        (**(code **)(*(int *)(*(int *)(iVar15 + 0xb8fc) + 0xc) + 0x50))(param_1,0x20,&local_2c);
      }
      uVar10 = 0;
    }
    else {
      uVar11 = (*(int *)(iVar15 + 0xb3f0) - DAT_ram_00021c04) -
               (uint)(*(uint *)(iVar15 + 0xb3ec) < last_rxok_cnt_1);
      uVar17 = 1;
      uVar6 = *(uint *)(iVar15 + 0xb3d4) - last_txok_cnt_2;
      uVar8 = (uVar6 >> 0x1e) +
              ((*(int *)(iVar15 + 0xb3d8) - DAT_ram_00021c0c) -
              (uint)(*(uint *)(iVar15 + 0xb3d4) < last_txok_cnt_2)) * 4;
      if ((uVar11 <= uVar8) &&
         ((uVar11 != uVar8 || (*(uint *)(iVar15 + 0xb3ec) - last_rxok_cnt_1 <= uVar6 * 4)))) {
        uVar17 = 0;
      }
      rtl_write_dword(iVar15,0x508,0x5ea42b);
      uVar10 = 1;
      *(undefined1 *)(iVar15 + 0xa00c) = uVar17;
    }
    *(undefined1 *)(iVar15 + 0xa00a) = uVar10;
  }
  *(undefined1 *)(iVar15 + 0xa00b) = 0;
  last_txok_cnt_2 = *(undefined4 *)(iVar15 + 0xb3d4);
  DAT_ram_00021c0c = *(undefined4 *)(iVar15 + 0xb3d8);
  iVar18 = *(int *)(param_1 + 0x40);
  last_rxok_cnt_1 = *(undefined4 *)(iVar15 + 0xb3ec);
  DAT_ram_00021c04 = *(undefined4 *)(iVar15 + 0xb3f0);
  if (*(uint *)(iVar18 + 0x4d0) < 2) {
    if (*(char *)(iVar18 + 0xa088) == '\0') {
      rtl_set_bbreg(param_1,0xd2c,0x800,1);
      *(undefined1 *)(iVar18 + 0xa088) = 1;
    }
    iVar15 = (**(code **)(*(int *)(*(int *)(iVar18 + 0xb8fc) + 0xc) + 0x104))();
    if (((iVar15 == 0) ||
        (iVar15 = (**(code **)(*(int *)(iVar18 + 0xb9ac) + 0x4c))(iVar18), iVar15 != 0)) &&
       (uVar6 = (uint)*(byte *)(iVar18 + 0xb29a), *(uint *)(iVar18 + 0xa098) != uVar6)) {
      *(uint *)(iVar18 + 0xa098) = uVar6;
      rtl_set_bbreg(param_1,0x2c,0xfff000,(uVar6 & 0x3f) * 0x41);
    }
  }
  else {
    iVar15 = *(int *)(iVar18 + 0xa0a0);
    if (iVar15 != *(int *)(iVar18 + 0xa0a4)) {
      iVar19 = (*(code *)&__divsi3)(*(int *)(iVar18 + 0xa08c) * 0xc35,0x500);
      *(int *)(iVar18 + 0xa0a4) = iVar15;
      if (*(char *)(iVar18 + 0x889) != '\0') {
        iVar15 = (*(code *)&__divsi3)(*(int *)(iVar18 + 0xa090) * 0xc35,0x500);
        iVar19 = iVar15 + iVar19 >> 1;
      }
      iVar15 = *(int *)(iVar18 + 0xa094);
      if (iVar15 < iVar19) {
        iVar15 = iVar19 - iVar15;
      }
      else {
        iVar15 = iVar15 - iVar19;
      }
      if ((iVar15 < 0x15) || (*(char *)(iVar18 + 0xa089) != '\0')) {
        *(undefined1 *)(iVar18 + 0xa089) = 0;
        uVar6 = (uint)*(byte *)(iVar18 + 0xa09c);
        *(int *)(iVar18 + 0xa094) = iVar19;
        if (iVar19 < (int)-uVar6) {
LAB_ram_00011282:
          if (*(int *)(iVar18 + 0xa098) < 1) goto LAB_ram_0001122a;
          iVar15 = (iVar19 + 10 >> 2) + -1;
LAB_ram_000112a6:
          if (iVar15 != 0) {
            iVar15 = *(int *)(iVar18 + 0xa098) + iVar15;
            iVar15 = iVar15 * (uint)(0 < iVar15);
            *(undefined1 *)(iVar18 + 0xa08a) = 0;
            uVar6 = iVar15 * (uint)(0x3e >= iVar15) + (uint)(0x3e < iVar15) * 0x3f;
            *(uint *)(iVar18 + 0xa098) = uVar6;
            rtl_set_bbreg(param_1,0x2c,0xfff000,(uVar6 & 0x3f) * 0x41);
          }
        }
        else if ((int)uVar6 < iVar19) {
LAB_ram_00011222:
          if (*(int *)(iVar18 + 0xa098) < 0x3f) {
            iVar15 = (iVar19 + -10 >> 2) + 1;
            goto LAB_ram_000112a6;
          }
        }
        else if (*(char *)(iVar18 + 0xa08a) == '\0') {
          if (uVar6 == 10) {
            *(undefined1 *)(iVar18 + 0xa09c) = 0x14;
            *(undefined1 *)(iVar18 + 0xa08a) = 1;
          }
          else {
            *(undefined1 *)(iVar18 + 0xa09c) = 10;
          }
          if ((int)(uint)*(byte *)(iVar18 + 0xa09c) < iVar19) goto LAB_ram_00011222;
          if (iVar19 < (int)-(uint)*(byte *)(iVar18 + 0xa09c)) goto LAB_ram_00011282;
        }
LAB_ram_0001122a:
        if (iVar19 + 0x4fU < 0x9f) {
          if (*(char *)(iVar18 + 0xa088) != '\0') {
            rtl_set_bbreg(param_1,0xd2c,0x800,0);
            uVar10 = 0;
LAB_ram_00011252:
            *(undefined1 *)(iVar18 + 0xa088) = uVar10;
          }
        }
        else if (*(char *)(iVar18 + 0xa088) == '\0') {
          rtl_set_bbreg(param_1,0xd2c,0x800,1);
          uVar10 = 1;
          goto LAB_ram_00011252;
        }
      }
      else {
        *(undefined1 *)(iVar18 + 0xa089) = 1;
      }
    }
  }
  iVar15 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar15 + 0x3f4) == 3) {
    rtl92ee_dm_write_dynamic_cca(param_1,0);
    return;
  }
  if (*(uint *)(iVar15 + 0x4d0) < 2) {
    return;
  }
  if (*(char *)(iVar15 + 0x587) != '\0') {
    return;
  }
  if (*(char *)(iVar15 + 0xb3cc) != '\0') {
    if ((char)(count_down_0 + -1) != '\0') {
      count_down_0 = count_down_0 + -1;
      return;
    }
    count_down_0 = 0x1e;
    *(undefined1 *)(iVar15 + 0xb3cc) = 0;
    rtl92ee_dm_write_dynamic_cca(param_1,0);
    *(undefined1 *)(iVar15 + 0x6ec) = 0;
    *(undefined1 *)(iVar15 + 0xb3cf) = 0;
    *(undefined1 *)(iVar15 + 0xb3ce) = 0;
    *(undefined1 *)(iVar15 + 0xb3cd) = 0;
    return;
  }
  uVar6 = *(uint *)(iVar15 + 0xb8b4);
  uVar11 = *(uint *)(iVar15 + 0xb8a8);
  uVar12 = *(uint *)(iVar15 + 0xb8c0);
  uVar8 = *(uint *)(iVar15 + 0xb8c4);
  if (*(char *)(iVar15 + 0x58d) == '\x02') {
    if (((500 < uVar6) && (uVar12 < 0xfffffe0c)) && (uVar12 + 500 < uVar8)) {
      if (uVar6 >> 1 < uVar11) {
        *(undefined1 *)(iVar15 + 0xb3ce) = 1;
        *(undefined1 *)(iVar15 + 0xb3cd) = 1;
        uVar7 = 2;
LAB_ram_00011388:
        rtl92ee_dm_write_dynamic_cca(param_1,uVar7);
        *(undefined1 *)(iVar15 + 0xb3cc) = 1;
        return;
      }
      if (uVar11 < uVar6 >> 1) {
        *(undefined1 *)(iVar15 + 0xb3ce) = 2;
        *(undefined1 *)(iVar15 + 0xb3cd) = 1;
        uVar7 = 2;
LAB_ram_000113ac:
        rtl92ee_dm_write_dynamic_cca(param_1,uVar7);
        *(undefined1 *)(iVar15 + 0xb3cc) = 1;
        *(undefined1 *)(iVar15 + 0xb3cf) = 1;
        *(undefined1 *)(iVar15 + 0x6ec) = 1;
        return;
      }
    }
  }
  else {
    if (*(char *)(iVar15 + 0x58d) != '\x01') {
      return;
    }
    if (((500 < uVar6) && (uVar8 < 0xfffffe0c)) && (uVar8 + 500 < uVar12)) {
      if (uVar6 >> 1 < uVar11) {
        *(undefined1 *)(iVar15 + 0xb3ce) = 1;
        *(undefined1 *)(iVar15 + 0xb3cd) = 1;
        uVar7 = 1;
        goto LAB_ram_00011388;
      }
      if (uVar11 < uVar6 >> 1) {
        *(undefined1 *)(iVar15 + 0xb3ce) = 2;
        *(undefined1 *)(iVar15 + 0xb3cd) = 1;
        uVar7 = 1;
        goto LAB_ram_000113ac;
      }
    }
  }
  *(undefined1 *)(iVar15 + 0xb3ce) = 0;
  *(undefined1 *)(iVar15 + 0xb3cd) = 0;
  rtl92ee_dm_write_dynamic_cca(param_1,0);
  *(undefined1 *)(iVar15 + 0x6ec) = 0;
  *(undefined1 *)(iVar15 + 0xb3cf) = 0;
  return;
}

