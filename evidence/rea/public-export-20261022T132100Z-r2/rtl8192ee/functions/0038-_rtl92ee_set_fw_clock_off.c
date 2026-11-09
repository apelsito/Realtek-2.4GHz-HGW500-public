/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12d78; aliases: _rtl92ee_set_fw_clock_off
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rtl92ee_set_fw_clock_off(int param_1,byte param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  byte local_28 [4];
  int iStack_24;
  
  iVar3 = *(int *)(param_1 + 0x40);
  iStack_24 = 0;
  if ((((*(char *)(iVar3 + 0x6ba) != '\0') && (*(char *)(iVar3 + 0xb2f9) != '\0')) &&
      (cVar1 = *(char *)(iVar3 + 0x6c8), cVar1 != '\0')) &&
     ((local_28[0] = param_2,
      (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x28,&iStack_24),
      iStack_24 != 2 && (*(int *)(iVar3 + 0xb310) != 2)))) {
    uVar2 = 0;
    do {
      if (*(int *)(uVar2 * 0x2c + iVar3 + 0xbab8) != 0) {
        if (cVar1 != '\0') goto LAB_ram_00012ec6;
        break;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 != 9);
    if ((*(byte *)(iVar3 + 0x6c9) & 0xf) != 1) {
      uVar2 = (uint)local_28 & 0xffffe000;
      *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
      if (*(char *)(iVar3 + 0x6c7) == '\0') {
        *(undefined1 *)(iVar3 + 0x6c7) = 1;
        (*(code *)&__local_bh_enable_ip)(0x12e44,0x200);
        *(byte *)(iVar3 + 0x6c9) = local_28[0] & 0xf;
        rtl_write_word(iVar3,0xb4,0x100);
        (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3c,local_28);
        *(int *)(uVar2 + 4) = *(int *)(uVar2 + 4) + 0x200;
        *(undefined1 *)(iVar3 + 0x6c7) = 0;
        (*(code *)&__local_bh_enable_ip)(0x12e44,0x200);
      }
      else {
        (*(code *)&__local_bh_enable_ip)(0x12ede,0x200);
LAB_ram_00012ec6:
        (*(code *)&mod_timer)(iVar3 + 0x60,_jiffies + 1);
      }
    }
  }
  return;
}

