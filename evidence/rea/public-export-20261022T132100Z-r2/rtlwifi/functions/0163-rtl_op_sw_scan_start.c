/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17fe4; aliases: rtl_op_sw_scan_start
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_op_sw_scan_start(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  (*(code *)&printk)(&DAT_ram_00019cd4,*(undefined4 *)(iVar4 + 0x4d0),
                     *(undefined1 *)(iVar4 + 0xb7cb),*(undefined4 *)(iVar4 + 0xb314));
  *(undefined1 *)(iVar4 + 0x4ea) = 1;
  if (*(char *)(iVar4 + 0xb7cb) != '\0') {
    *(undefined1 *)(iVar4 + 0x4ec) = 1;
    return;
  }
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x104))();
  iVar2 = *(int *)(iVar4 + 0xb9ac);
  if (iVar1 == 0) {
    if (iVar2 == 0) goto LAB_ram_0001807e;
    pcVar3 = *(code **)(iVar2 + 0x28);
  }
  else {
    pcVar3 = *(code **)(iVar2 + 0x24);
  }
  (*pcVar3)(iVar4,1);
LAB_ram_0001807e:
  if ((*(char *)(iVar4 + 0xa0b9) != '\0') &&
     (pcVar3 = *(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 200), pcVar3 != (code *)0x0)) {
    (*pcVar3)(param_1);
  }
  if (*(int *)(iVar4 + 0x4d0) == 2) {
    rtl_lps_leave(param_1,1);
    *(undefined4 *)(iVar4 + 0x4d0) = 3;
  }
  else {
    rtl_ips_nic_on(param_1);
  }
  *(undefined1 *)(iVar4 + 0x6e6) = 0;
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x90))(param_1,6);
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x88))(param_1,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

