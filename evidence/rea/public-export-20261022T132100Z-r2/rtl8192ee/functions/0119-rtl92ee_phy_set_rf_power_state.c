/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x184ac; aliases: rtl92ee_phy_set_rf_power_state
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 rtl92ee_phy_set_rf_power_state(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
  iVar5 = *(int *)(param_1 + 0x40);
  iVar3 = *(int *)(iVar5 + 0xb314);
  if (iVar3 == param_2) {
    return 0;
  }
  if (param_2 == 1) {
    if (iVar3 != 2) {
      bVar7 = 0;
      uVar6 = 0;
      do {
        if (*(int *)(iVar5 + uVar6 * 0x2c + 0xbab8) == 0) {
          uVar6 = uVar6 + 1 & 0xff;
        }
        else {
          bVar7 = bVar7 + 1;
          __udelay(10);
          if (0x3f < bVar7) break;
        }
      } while (uVar6 != 9);
      (*(code *)&jiffies_to_msecs)(_jiffies - *(int *)(iVar5 + 0xb32c));
      *(int *)(iVar5 + 0xb328) = _jiffies;
      uVar2 = *(undefined4 *)(param_1 + 0x40);
      rtl_write_byte(uVar2,0x522,0xff);
      rtl_set_rfreg(param_1,0,0,0xfffff,0);
      rtl_write_byte(uVar2,2,0xe2);
      rtl_write_byte(uVar2,0x11,0x22);
    }
    goto LAB_ram_0001860c;
  }
  if (param_2 == 2) {
    bVar7 = 0;
    uVar6 = 0;
    do {
      if ((uVar6 == 4) || (*(int *)(iVar5 + uVar6 * 0x2c + 0xbab8) == 0)) {
        uVar6 = uVar6 + 1 & 0xff;
      }
      else {
        bVar7 = bVar7 + 1;
        __udelay(10);
        if (0x3f < bVar7) break;
      }
    } while (uVar6 != 9);
    if ((*(uint *)(iVar5 + 0xb308) & 8) != 0) {
      (*(code *)&rtl_ps_disable_nic)(param_1);
      *(uint *)(iVar5 + 0xb304) = *(uint *)(iVar5 + 0xb304) | 8;
      goto LAB_ram_0001860c;
    }
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x90);
    if (*(int *)(iVar5 + 0xb300) == 0x10000000) goto LAB_ram_0001853c;
    uVar2 = 7;
  }
  else {
    if (param_2 != 0) {
      return 0;
    }
    if ((iVar3 == 2) && ((*(uint *)(iVar5 + 0xb304) & 8) != 0)) {
      iVar3 = 0;
      do {
        iVar1 = (*(code *)&rtl_ps_enable_nic)(param_1);
        if (iVar1 != 0) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 10);
      *(uint *)(iVar5 + 0xb304) = *(uint *)(iVar5 + 0xb304) & 0xfffffff7;
    }
    else {
      (*(code *)&jiffies_to_msecs)(_jiffies - *(int *)(iVar5 + 0xb328));
      *(int *)(iVar5 + 0xb32c) = _jiffies;
      uVar2 = *(undefined4 *)(param_1 + 0x40);
      rtl_write_byte(uVar2,0x11,0x2b);
      rtl_write_byte(uVar2,2,0xe3);
      rtl_write_byte(uVar2,2,0xe2);
      rtl_write_byte(uVar2,2,0xe3);
      rtl_write_byte(uVar2,0x522,0);
    }
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x90);
    if (*(int *)(iVar5 + 0x4d0) == 2) {
      uVar2 = 2;
    }
    else {
LAB_ram_0001853c:
      uVar2 = 3;
    }
  }
  (*pcVar4)(param_1,uVar2);
LAB_ram_0001860c:
  *(int *)(iVar5 + 0xb314) = param_2;
  return 1;
}

