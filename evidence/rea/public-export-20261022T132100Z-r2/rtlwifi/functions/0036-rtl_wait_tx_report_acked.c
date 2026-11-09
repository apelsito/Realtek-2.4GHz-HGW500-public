/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11ed8; aliases: rtl_wait_tx_report_acked
 */

void rtl_wait_tx_report_acked(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((uVar2 < param_2 && (iVar1 = rtl_check_tx_report_acked(param_1), iVar1 == 0))) {
    uVar2 = uVar2 + 1;
    (*(code *)&usleep_range)(1000,2000);
  }
  return;
}

