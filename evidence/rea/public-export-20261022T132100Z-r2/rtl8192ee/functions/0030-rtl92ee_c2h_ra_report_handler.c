/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12414; aliases: rtl92ee_c2h_ra_report_handler
 */

void rtl92ee_c2h_ra_report_handler(undefined4 param_1,byte *param_2,byte param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar1 = *param_2;
  if (param_3 < 4) {
    bVar8 = 0;
  }
  else {
    bVar8 = param_2[3] & 1;
  }
  if ((rtl92ee_hgw500_tx_rate_trace == '\0') ||
     (iVar4 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar4 == 0))
  goto LAB_ram_000124b0;
  uVar5 = report_count_0 + 1;
  if (param_3 < 2) {
    bVar6 = 0;
    bVar7 = 0;
LAB_ram_000124d6:
    bVar3 = 0;
  }
  else {
    bVar7 = param_2[1];
    if (param_3 == 2) {
      bVar6 = 0;
      goto LAB_ram_000124d6;
    }
    bVar6 = param_2[2];
    if (param_3 == 3) goto LAB_ram_000124d6;
    bVar3 = param_2[3];
  }
  if ((uVar5 < 0x21) || (uVar2 = report_count_0 & uVar5, report_count_0 = uVar5, uVar2 == 0)) {
    report_count_0 = uVar5;
    (*(code *)&printk)(&DAT_ram_0001ce24,uVar5,param_3,bVar1 & 0x3f,*param_2 >> 7,bVar7,bVar8,
                       *param_2,bVar7,bVar6,bVar3);
  }
LAB_ram_000124b0:
  rtl92ee_dm_dynamic_arfb_select(param_1,bVar1 & 0x3f,bVar8);
  return;
}

