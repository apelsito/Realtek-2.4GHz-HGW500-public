/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x147e4; aliases: rtl92ee_read_eeprom_info
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl92ee_read_eeprom_info(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_4c [40];
  
  iVar7 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar7 + 0x889) = 2;
  uVar3 = rtl_read_dword(iVar7,0xf0);
  if ((uVar3 & 0x800000) == 0) {
    uVar4 = 0x102c;
  }
  else {
    uVar4 = 0x24;
  }
  *(undefined4 *)(iVar7 + 0x694) = uVar4;
  if (*(char *)(iVar7 + 0x889) == '\0') {
    *(undefined1 *)(iVar7 + 0xa012) = 1;
  }
  else {
    *(undefined2 *)(iVar7 + 0xa012) = 0x101;
  }
  uVar3 = rtl_read_byte(iVar7,10);
  *(short *)(iVar7 + 0xa9e6) = (short)((~(uVar3 >> 4) & 1) << 1);
  if ((uVar3 & 0x20) == 0) {
    (*(code *)&printk)(&DAT_ram_0001cf90);
  }
  else {
    *(undefined1 *)(iVar7 + 0xa9e3) = 0;
    iVar8 = *(int *)(param_1 + 0x40);
    (*(code *)&memcpy)(auStack_4c,&DAT_ram_0001c698,0x28);
    iVar5 = (*(code *)&kmem_cache_alloc)(_DAT_ram_0f000164,0xdc0);
    if (iVar5 != 0) {
      iVar6 = (*(code *)&rtl_get_hwinfo)(param_1,iVar8,0x200,iVar5,auStack_4c);
      if (iVar6 == 0) {
        if (*(char *)(iVar8 + 0xa9f0) == -1) {
          *(undefined1 *)(iVar8 + 0xa9f0) = 0;
        }
        *(char *)(iVar8 + 0xb2a1) = (char)*(undefined2 *)(iVar8 + 0xa9f2);
        _rtl92ee_read_txpower_info_from_hwpg(param_1,*(char *)(iVar8 + 0xa9e3) != '\0',iVar5);
        rtl92ee_read_bt_coexist_info_from_hwpg(param_1,*(char *)(iVar8 + 0xa9e3) != '\0',iVar5);
        bVar1 = *(byte *)(iVar5 + 0xc1) >> 5;
        *(byte *)(iVar8 + 0xa9f5) = bVar1;
        if (*(char *)(iVar5 + 0xc1) == -1) {
          bVar1 = 0;
        }
        *(byte *)(iVar8 + 0xa9f5) = bVar1;
        if (*(char *)(iVar8 + 0xb9b1) == '\x01') {
          bVar1 = bVar1 | 4;
          *(byte *)(iVar8 + 0xa9f5) = bVar1;
        }
        *(byte *)(iVar8 + 0x699) = bVar1;
        cVar2 = *(char *)(iVar5 + 0xb9);
        if (cVar2 == -1) {
          cVar2 = ' ';
        }
        *(char *)(iVar8 + 0xb29a) = cVar2;
        *(undefined1 *)(iVar8 + 0xaa00) = 0xff;
        *(undefined1 *)(iVar8 + 0xa9ff) = 0;
        if ((((*(char *)(iVar8 + 0x693) == '\0') && (*(char *)(iVar8 + 0xa9f0) == '\0')) &&
            (*(short *)(iVar8 + 0xa9ea) == -0x7e75)) &&
           ((*(short *)(iVar8 + 0xa9ec) == 0x10ec && (*(short *)(iVar8 + 0xa9ee) == 0x1b)))) {
          *(undefined1 *)(iVar8 + 0x693) = 0x12;
        }
      }
      (*(code *)&kfree)(iVar5);
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 0x40) + 0xb2a4) = 1;
  *(undefined1 *)(iVar7 + 0x93d) = 1;
  if (*(char *)(iVar7 + 0x889) == '\x02') {
    *(undefined1 *)(iVar7 + 0x93e) = 1;
  }
  return;
}

