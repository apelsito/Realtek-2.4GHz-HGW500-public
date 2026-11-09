/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17eb0; aliases: rtl_op_sw_scan_complete
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_op_sw_scan_complete(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  (*(code *)&printk)(&DAT_ram_00019b68,*(undefined4 *)(iVar4 + 0x4d4),
                     *(undefined4 *)(iVar4 + 0xb2dc));
  *(undefined1 *)(iVar4 + 0x4ea) = 0;
  *(undefined1 *)(iVar4 + 0x4ec) = 0;
  *(char *)(iVar4 + 0xb9b4) = (char)*(undefined4 *)(iVar4 + 0xb2dc);
  if (*(char *)(iVar4 + 0xb7cb) != '\0') {
    return;
  }
  *(bool *)(iVar4 + 0x4de) = *(int *)(iVar4 + 0x4d4) == 3;
  *(undefined4 *)(iVar4 + 0x4d4) = 0;
  *(undefined1 *)(iVar4 + 0x6e6) = 0;
  if (*(int *)(iVar4 + 0x4d0) == 3) {
    *(undefined4 *)(iVar4 + 0x4d0) = 2;
    if (*(int *)(iVar4 + 0x3f4) == 2) {
      (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x2c))(param_1);
    }
  }
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x88))(param_1,2);
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x104))();
  iVar2 = *(int *)(iVar4 + 0xb9ac);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      halt_baddata();
    }
    pcVar3 = *(code **)(iVar2 + 0x28);
  }
  else {
    pcVar3 = *(code **)(iVar2 + 0x24);
  }
  (*pcVar3)(iVar4,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

