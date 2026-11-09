/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17a20; aliases: rtl92ee_phy_set_bw_mode_callback
 */

void rtl92ee_phy_set_bw_mode_callback(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar5 + 0x698) == '\0') goto LAB_ram_00017b34;
  bVar1 = rtl_read_byte(iVar5,0x603);
  uVar2 = rtl_read_byte(iVar5,0x442);
  if (*(char *)(iVar5 + 0x88a) == '\0') {
    rtl_write_byte(iVar5,0x603,bVar1 | 4);
  }
  else if (*(char *)(iVar5 + 0x88a) == '\x01') {
    rtl_write_byte(iVar5,0x603,bVar1 & 0xfb);
    rtl_write_byte(iVar5,0x442,uVar2 & 0x90 | (*(byte *)(iVar5 + 0x58d) & 7) << 5);
  }
  else {
    (*(code *)&printk)(&DAT_ram_0001d2fc);
  }
  if (*(char *)(iVar5 + 0x88a) == '\0') {
    rtl_set_bbreg(param_1,0x800,1,0);
    rtl_set_bbreg(param_1,0x900,1,0);
    uVar4 = 0xc0000000;
    uVar3 = 0xce4;
LAB_ram_00017b22:
    rtl_set_bbreg(param_1,uVar3,uVar4);
  }
  else {
    if (*(char *)(iVar5 + 0x88a) == '\x01') {
      rtl_set_bbreg(param_1,0x800,1,1);
      rtl_set_bbreg(param_1,0x900,1,1);
      rtl_set_bbreg(param_1,0xa00,0x10,*(byte *)(iVar5 + 0x58d) >> 1);
      rtl_set_bbreg(param_1,0xd00,0xc00,*(undefined1 *)(iVar5 + 0x58d));
      uVar4 = 0xc000000;
      uVar3 = 0x818;
      goto LAB_ram_00017b22;
    }
    (*(code *)&printk)(&DAT_ram_0001d2fc);
  }
  rtl92ee_phy_rf6052_set_bandwidth(param_1,*(undefined1 *)(iVar5 + 0x88a));
LAB_ram_00017b34:
  *(undefined1 *)(iVar5 + 0x88b) = 0;
  return;
}

