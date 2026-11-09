/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14310; aliases: rtl92ee_update_hal_rate_tbl
 */

void rtl92ee_update_hal_rate_tbl(int param_1,uint *param_2,char param_3,byte param_4)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char local_18;
  byte local_17;
  byte local_16;
  undefined1 local_15;
  undefined1 uStack_14;
  undefined1 local_13;
  undefined1 local_12;
  
  iVar8 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar8 + 0xa011) == '\0') {
    return;
  }
  uVar1 = (ushort)param_2[7];
  sVar2 = *(short *)((int)param_2 + 0x1f1);
  uVar6 = *param_2;
  uVar7 = (int)(uint)uVar1 >> 1 & 1;
  switch(*(int *)(iVar8 + 0x3f4)) {
  case 1:
  case 3:
    local_18 = (char)*(undefined2 *)((int)param_2 + 0x1a) + '\x01';
    if (*(int *)(iVar8 + 0x3f4) == 1) {
      uVar6 = 0xfff;
    }
    break;
  case 2:
  case 7:
    uVar7 = (uint)*(byte *)(iVar8 + 0x587);
  default:
    local_18 = '\0';
  }
  uVar3 = (uint)*(byte *)((int)param_2 + 0x21) << 0xc | (uint)*(byte *)((int)param_2 + 0x22) << 0x14
  ;
  uVar4 = uVar3 | uVar6;
  if (sVar2 == 4) {
    if (param_3 == '\x01') {
      uVar4 = uVar6 & 0xf00;
    }
    else if (param_3 == '\x02') {
      uVar4 = uVar6 & 0xff0;
    }
    else {
      uVar4 = uVar6 & 0xff5;
    }
    iVar8 = 3;
LAB_ram_000143c6:
    cVar5 = '\0';
  }
  else {
    if (sVar2 != 0x10) {
      if (sVar2 == 2) {
        iVar8 = 5;
        if ((uVar6 & 0xc) == 0) {
          uVar4 = uVar6 & 0xf;
        }
        else {
          uVar4 = uVar6 & 0xd;
        }
        goto LAB_ram_000143c6;
      }
      if (*(char *)(iVar8 + 0x889) == '\0') {
        uVar4 = uVar4 & 0xff0ff;
        cVar5 = '\0';
        local_17 = 0;
        goto LAB_ram_000144be;
      }
      uVar4 = uVar4 & 0xf8ff0ff;
      cVar5 = '\0';
LAB_ram_0001442e:
      local_17 = 0;
      goto LAB_ram_000144be;
    }
    if (*(char *)(iVar8 + 0x889) == '\0') {
      if (uVar7 == 0) {
        if (param_3 == '\x01') {
          uVar4 = uVar4 & 0xf0000;
        }
        else if (param_3 == '\x02') {
          uVar4 = uVar4 & 0xff000;
        }
        else {
          uVar4 = uVar4 & 0xff005;
        }
        goto LAB_ram_00014450;
      }
      if (param_3 == '\x01') {
        uVar4 = uVar4 & 0xf0000;
      }
      else if (param_3 == '\x02') {
        uVar4 = uVar4 & 0xff000;
      }
      else {
        uVar4 = uVar4 & 0xff015;
      }
LAB_ram_0001441e:
      cVar5 = '\0';
      if ((uVar1 & 0x40) != 0) goto LAB_ram_00014424;
LAB_ram_0001442c:
      if (uVar7 != 0) goto LAB_ram_0001442e;
    }
    else {
      if (uVar7 != 0) {
        if (param_3 == '\x01') {
          uVar4 = uVar4 & 0xf8f0000;
        }
        else {
          if (param_3 == '\x02') {
            uVar6 = uVar6 & 0xffff000;
          }
          else {
            uVar6 = uVar6 & 0xffff015;
          }
          uVar4 = uVar3 | uVar6;
        }
        goto LAB_ram_0001441e;
      }
      if (param_3 == '\x01') {
        uVar4 = uVar4 & 0xf8f0000;
      }
      else {
        if (param_3 == '\x02') {
          uVar6 = uVar6 & 0xffff000;
        }
        else {
          uVar6 = uVar6 & 0xffff005;
        }
        uVar4 = uVar3 | uVar6;
      }
LAB_ram_00014450:
      if ((uVar1 & 0x20) != 0) {
LAB_ram_00014424:
        cVar5 = '\x01';
        if (local_18 != '\0') {
          cVar5 = '\0';
        }
        goto LAB_ram_0001442c;
      }
      cVar5 = '\0';
    }
    iVar8 = 1;
  }
  local_17 = *(byte *)((int)&CSWTCH_104 + iVar8);
LAB_ram_000144be:
  local_15 = (undefined1)uVar4;
  uStack_14 = (undefined1)(uVar4 >> 8);
  *(byte *)((int)param_2 + 499) = local_17;
  local_16 = (byte)uVar7 | (param_4 ^ 1) << 3;
  local_17 = local_17 | cVar5 << 7;
  local_13 = (undefined1)(uVar4 >> 0x10);
  local_12 = (undefined1)(uVar4 >> 0x18);
  rtl92ee_fill_h2c_cmd(param_1,0x40,7,&local_18);
  _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),8,0);
  return;
}

