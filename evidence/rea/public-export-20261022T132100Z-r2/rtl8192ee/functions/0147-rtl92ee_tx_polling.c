/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1b350; aliases: rtl92ee_tx_polling
 */

void rtl92ee_tx_polling(int param_1,uint param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar14;
  
  param_2 = param_2 & 0xff;
  iVar10 = *(int *)(param_1 + 0x40);
  if (param_2 < 8) {
    uVar14 = *(undefined2 *)(CSWTCH_176 + param_2 * 2);
  }
  else {
    uVar14 = 0x3a8;
  }
  uVar12 = poll_trace_count_1 + 1;
  poll_trace_count_1 = uVar12;
  if ((param_2 == 4) && (*(char *)(iVar10 + 0xba99) != '\0')) {
    uVar11 = beacon_trigger_count_0 + 1;
    beacon_trigger_count_0 = uVar11;
    rtl_write_word(iVar10,0x300,0x10);
    if (uVar11 < 9) {
      uVar3 = rtl_read_dword(iVar10,0x300);
      (*(code *)&printk)(&DAT_ram_0001e038,uVar11,uVar3);
    }
  }
  if (uVar12 < 0x21) {
    iVar13 = iVar10 + 0xbc00 + param_2 * 0x2c;
    uVar2 = *(undefined2 *)(iVar13 + -0x13a);
    uVar1 = *(undefined2 *)(iVar13 + -0x138);
    uVar3 = rtl_read_dword(iVar10,uVar14);
    uVar4 = rtl_read_dword(iVar10,0x300);
    uVar5 = rtl_read_dword(iVar10,0xb4);
    uVar6 = rtl_read_dword(iVar10,0xbc);
    uVar7 = rtl_read_dword(iVar10,0x210);
    uVar8 = rtl_read_dword(iVar10,0x288);
    uVar9 = rtl_read_word(iVar10,0x41a);
    (*(code *)&printk)(&DAT_ram_0001e07c,uVar12,param_2,uVar2,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                       uVar8,uVar9);
    uVar1 = *(undefined2 *)(iVar13 + -0x13a);
    uVar2 = *(undefined2 *)(iVar13 + -0x138);
    uVar3 = rtl_read_dword(iVar10,uVar14);
    uVar4 = rtl_read_dword(iVar10,0x300);
    uVar5 = rtl_read_dword(iVar10,0xb4);
    uVar6 = rtl_read_dword(iVar10,0xbc);
    uVar7 = rtl_read_dword(iVar10,0x210);
    uVar8 = rtl_read_dword(iVar10,0x288);
    uVar9 = rtl_read_word(iVar10,0x41a);
    (*(code *)&printk)(&DAT_ram_0001e10c,uVar12,param_2,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,
                       uVar8,uVar9);
  }
  return;
}

