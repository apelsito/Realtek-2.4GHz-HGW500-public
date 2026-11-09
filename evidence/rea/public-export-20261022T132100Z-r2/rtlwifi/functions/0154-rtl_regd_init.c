/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1784c; aliases: rtl_regd_init
 */

undefined4 rtl_regd_init(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined1 uVar5;
  short sVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 0x38);
  if (iVar9 == 0) {
    return 0xffffffea;
  }
  iVar2 = *(int *)(param_1 + 0x40);
  bVar1 = *(byte *)(iVar2 + 0xb2a1);
  if (bVar1 == 0x32) {
    sVar6 = 0xc;
    goto LAB_ram_000178a0;
  }
  if (bVar1 < 0x33) {
    if (bVar1 == 0x22) {
      sVar6 = 1;
      goto LAB_ram_000178a0;
    }
    if (bVar1 == 0x25) {
      sVar6 = 2;
      goto LAB_ram_000178a0;
    }
  }
  else {
    if (bVar1 == 0x41) {
      sVar6 = 10;
      goto LAB_ram_000178a0;
    }
    if (bVar1 == 0x7f) {
      sVar6 = 0xd;
      goto LAB_ram_000178a0;
    }
  }
  sVar6 = 0xb;
LAB_ram_000178a0:
  *(short *)(iVar2 + 0x70a) = sVar6;
  iVar8 = 0;
  do {
    if ((&all_countries)[iVar8 * 4] == sVar6) {
      puVar7 = (&PTR_DAT_ram_0001a214_ram_0001af0c)[iVar8 * 2];
      *(undefined1 *)(iVar2 + 0x708) = *puVar7;
      uVar5 = puVar7[1];
      goto LAB_ram_000178c8;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0xe);
  *(undefined1 *)(iVar2 + 0x708) = 0x30;
  uVar5 = 0x30;
LAB_ram_000178c8:
  *(undefined1 *)(iVar2 + 0x709) = uVar5;
  *(undefined4 *)(iVar9 + 0xe0) = param_2;
  *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) & 0xfffffff9 | 1;
  puVar7 = rtl_regdom_no_midband;
  uVar3 = *(ushort *)(iVar2 + 0x70a) - 1 & 0xffff;
  if (uVar3 < 0xd) {
    puVar7 = *(undefined1 **)(CSWTCH_6 + uVar3 * 4);
  }
  (*(code *)&wiphy_apply_custom_regulatory)(iVar9,puVar7);
  _rtl_reg_apply_radar_flags(iVar9);
  _rtl_reg_apply_beaconing_flags(iVar9,2);
  piVar4 = *(int **)(iVar9 + 0xcc);
  if (piVar4 != (int *)0x0) {
    uVar3 = *(uint *)(*piVar4 + 0x274);
    if ((uVar3 & 2) != 0) {
      *(uint *)(*piVar4 + 0x274) = uVar3 & 0xfffffffd;
    }
    uVar3 = *(uint *)(*piVar4 + 0x2ac);
    if ((uVar3 & 2) != 0) {
      *(uint *)(*piVar4 + 0x2ac) = uVar3 & 0xfffffffd;
    }
  }
  return 0;
}

