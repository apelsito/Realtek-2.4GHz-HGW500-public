/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11a0c; aliases: _rtl92ee_download_fw_once.isra.0
 */

undefined4
_rtl92ee_download_fw_once_isra_0(int param_1,int param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint local_24;
  
  _rtl92ee_enable_fw_download_isra_0(*(undefined4 *)(param_1 + 0x40),1);
  local_24 = param_3;
  (*(code *)&rtl_fill_dummy)(param_2,&local_24);
  uVar4 = 0;
  uVar5 = local_24 >> 0xc;
  uVar2 = local_24 & 0xfff;
  if (8 < uVar5) {
    (*(code *)&printk)(&DAT_ram_0001ccb0);
  }
  for (; uVar4 < uVar5; uVar4 = uVar4 + 1) {
    (*(code *)&rtl_fw_page_write)(param_1,uVar4,uVar4 * 0x1000 + param_2,0x1000);
    __udelay(2);
  }
  if (uVar2 != 0) {
    (*(code *)&rtl_fw_page_write)(param_1,uVar5,uVar5 * 0x1000 + param_2,uVar2);
  }
  uVar2 = 0;
  _rtl92ee_enable_fw_download_isra_0(*(undefined4 *)(param_1 + 0x40),0);
  uVar3 = *(undefined4 *)(param_1 + 0x40);
  *param_4 = 0;
  do {
    uVar4 = rtl_read_dword(uVar3,0x80);
    if (uVar2 == 3000) goto LAB_ram_00011ac2;
    uVar2 = uVar2 + 1;
  } while ((uVar4 & 4) == 0);
  if (uVar2 < 3000) {
    uVar2 = rtl_read_dword(uVar3,0x80);
    rtl_write_dword(uVar3,0x80,uVar2 & 0xffffffbf | 2);
    iVar1 = 0;
    rtl92ee_firmware_selfreset(param_1);
    while (uVar2 = rtl_read_dword(uVar3,0x80), (uVar2 & 0x40) == 0) {
      __udelay(0x32);
      if (iVar1 == 3000) {
        (*(code *)&printk)(&DAT_ram_0001cd20,uVar2,0xbb9);
        goto LAB_ram_00011ada;
      }
      iVar1 = iVar1 + 1;
    }
    uVar3 = 0;
  }
  else {
LAB_ram_00011ac2:
    (*(code *)&printk)(&DAT_ram_0001cce8,uVar4);
    *param_4 = 1;
LAB_ram_00011ada:
    uVar3 = 0xfffffffb;
  }
  return uVar3;
}

