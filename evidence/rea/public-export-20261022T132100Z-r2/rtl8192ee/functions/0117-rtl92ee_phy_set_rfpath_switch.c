/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x182bc; aliases: rtl92ee_phy_set_rfpath_switch
 */

void rtl92ee_phy_set_rfpath_switch(int param_1,char param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar3 + 0x698) == '\0') {
    bVar2 = rtl_read_byte(iVar3,0x4c);
    rtl_write_byte(iVar3,0x4c,bVar2 | 0x80);
    rtl_set_bbreg(param_1,0x878,0x2000,1);
  }
  rtl_set_bbreg(param_1,0x870,0x300,0);
  rtl_set_bbreg(param_1,0x914,0xffff,0x201);
  if (param_2 == '\0') {
    rtl_set_bbreg(param_1,0x860,0x7000,1);
    rtl_set_bbreg(param_1,0x864,0x38,1);
    cVar1 = *(char *)(iVar3 + 0xaa00);
  }
  else {
    rtl_set_bbreg(param_1,0x860,0x7000,0);
    rtl_set_bbreg(param_1,0x864,0x38,0);
    cVar1 = *(char *)(iVar3 + 0xaa00);
  }
  if (cVar1 != '\x02') {
    return;
  }
  rtl_set_bbreg(param_1,0xb2c,0x80000000);
  return;
}

