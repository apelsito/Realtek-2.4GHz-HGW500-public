/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12f3c; aliases: _rtl92ee_set_fw_clock_on.constprop.0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtl92ee_set_fw_clock_on_constprop_0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_2c [2];
  byte local_2a [2];
  
  iVar3 = *(int *)(param_1 + 0x40);
  local_2a[0] = 0x40;
  local_2a[1] = 0;
  (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x5c,local_2a + 1);
  if ((*(char *)(iVar3 + 0x6ba) != '\0') && (*(char *)(iVar3 + 0xb2f9) != '\0')) {
    uVar4 = 0;
    while( true ) {
      uVar2 = (uint)auStack_2c & 0xffffe000;
      *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
      if (*(char *)(iVar3 + 0x6c7) == '\0') break;
      while (*(char *)(iVar3 + 0x6c7) != '\0') {
        (*(code *)&__local_bh_enable_ip)(0x1307e,0x200);
        uVar4 = uVar4 + 1;
        __udelay(100);
        if (1000 < uVar4) {
          return;
        }
        *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
      }
      (*(code *)&__local_bh_enable_ip)(0x130b6);
    }
    (*(code *)&__local_bh_enable_ip)(0x12fd6,0x200);
    if ((*(byte *)(iVar3 + 0x6c9) & 0xf) == 1) {
      (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x3c,local_2a);
      if ((local_2a[0] & 0x40) != 0) {
        while (uVar1 = rtl_read_dword(iVar3,0xb4), (uVar1 & 0x100) == 0) {
          if (499 < uVar4) goto LAB_ram_00013022;
          uVar4 = uVar4 + 1;
          __udelay(0x32);
        }
        rtl_write_word(iVar3,0xb4,0x100);
        *(undefined1 *)(iVar3 + 0x6c9) = 0;
      }
LAB_ram_00013022:
      *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
      *(undefined1 *)(iVar3 + 0x6c7) = 0;
      (*(code *)&__local_bh_enable_ip)(0x13022,0x200);
      if (param_2 != 0) {
        (*(code *)&mod_timer)(iVar3 + 0x60,_jiffies + 1);
      }
    }
    else {
      *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
      *(undefined1 *)(iVar3 + 0x6c7) = 0;
      (*(code *)&__local_bh_enable_ip)(0x130ec,0x200);
    }
  }
  return;
}

