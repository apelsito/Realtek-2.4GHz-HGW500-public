/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10f34; aliases: _rtl_init_hw_ht_capab.isra.0
 */

void _rtl_init_hw_ht_capab_isra_0(int param_1,undefined2 *param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  
  *(undefined1 *)(param_2 + 1) = 1;
  *param_2 = 0x1862;
  cVar1 = *(char *)(param_1 + 0x6e7);
  *(undefined1 *)((int)param_2 + 0x11) = 1;
  if (cVar1 == '\0') {
    uVar3 = 0x1862;
  }
  else {
    uVar3 = 0x1062;
  }
  *param_2 = uVar3;
  *(undefined1 *)((int)param_2 + 3) = 3;
  *(undefined1 *)(param_2 + 2) = 7;
  if (*(char *)(param_1 + 0xa0b9) == '\0') {
    bVar2 = *(byte *)(param_1 + 0x889);
    if (bVar2 - 1 < 2) {
      *(undefined1 *)((int)param_2 + 5) = 0xff;
      *(undefined1 *)(param_2 + 3) = 0xff;
      *(undefined1 *)((int)param_2 + 0xf) = 0x2c;
      *(undefined1 *)((int)param_2 + 9) = 1;
      bVar2 = 1;
    }
    else {
      if (bVar2 != 0) {
        return;
      }
      *(undefined1 *)((int)param_2 + 5) = 0xff;
      *(byte *)(param_2 + 3) = bVar2;
      *(undefined1 *)((int)param_2 + 9) = 1;
      *(undefined1 *)((int)param_2 + 0xf) = 0x96;
    }
    *(byte *)(param_2 + 8) = bVar2;
  }
  else {
    (*(code *)&printk)(&DAT_ram_00019940);
    *(undefined1 *)((int)param_2 + 5) = 0xff;
    *(undefined1 *)(param_2 + 3) = 0xff;
    *(undefined1 *)((int)param_2 + 0xf) = 0x2c;
    *(undefined1 *)((int)param_2 + 9) = 1;
    *(undefined1 *)(param_2 + 8) = 1;
  }
  return;
}

