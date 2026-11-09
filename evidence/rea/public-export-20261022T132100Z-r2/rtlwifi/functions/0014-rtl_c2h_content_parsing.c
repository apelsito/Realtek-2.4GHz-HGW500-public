/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1046c; aliases: rtl_c2h_content_parsing
 */

void rtl_c2h_content_parsing(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  char cVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0x40);
  iVar6 = *(int *)(iVar5 + 0xb9ac);
  iVar2 = *(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc);
  pbVar4 = *(byte **)(param_2 + 0xbc) + 2;
  bVar1 = **(byte **)(param_2 + 0xbc);
  if (bVar1 - 3 < 10) {
    cVar3 = *(char *)(param_2 + 0x50) + -2;
    switch(bVar1) {
    case 3:
      rtl_tx_report_handler(param_1,pbVar4,cVar3);
      return;
    case 9:
      iVar2 = (**(code **)(iVar2 + 0x104))();
      if (iVar2 != 0) {
        UNRECOVERED_JUMPTABLE = *(code **)(iVar6 + 0x3c);
LAB_ram_0001050c:
                    /* WARNING: Could not recover jumptable at 0x00010518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(iVar5,pbVar4,cVar3);
        return;
      }
      break;
    case 0xb:
      iVar2 = (**(code **)(iVar2 + 0x104))();
      if (iVar2 != 0) {
        UNRECOVERED_JUMPTABLE = *(code **)(iVar6 + 0x40);
        goto LAB_ram_0001050c;
      }
      break;
    case 0xc:
      UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x114);
      iVar5 = param_1;
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) goto LAB_ram_0001050c;
    }
  }
  return;
}

