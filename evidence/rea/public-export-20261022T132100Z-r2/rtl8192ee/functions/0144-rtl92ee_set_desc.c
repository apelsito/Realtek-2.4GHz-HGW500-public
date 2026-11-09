/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1ac68; aliases: rtl92ee_set_desc
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl92ee_set_desc(int param_1,uint *param_2,char param_3,char param_4,uint *param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint unaff_r16;
  ushort *puVar20;
  undefined2 *puVar21;
  int iVar22;
  uint uVar23;
  code *pcVar24;
  bool bVar25;
  
  if (param_3 == '\0') {
    if (param_4 == '\x06') {
      *param_2 = *param_2 | 0x40000000;
      return;
    }
    if (param_4 != '\a') {
      if (__warned_14 == '\0') {
        __warned_14 = 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      return;
    }
    *param_2 = *param_2 & 0x80004000 | 0x2018;
    uVar19 = *param_5;
    param_2[2] = 0;
    param_2[1] = uVar19;
    return;
  }
  if (param_4 == '\0') {
    iVar17 = *(int *)(param_1 + 0x40);
    uVar19 = (uint)(byte)*param_5;
    uVar4 = *(undefined1 *)(*(int *)(*(int *)(iVar17 + 0xb8fc) + 0x10) + 0x14);
    if ((hgw500_tx_dma_wmb == '\0') ||
       (iVar16 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar16 == 0)) {
      bVar25 = false;
    }
    else {
      bVar25 = *(short *)(iVar17 + 0x690) == 0xc;
    }
    iVar16 = uVar19 * 0x2c;
    iVar22 = iVar17 + 0xbc00;
    if (7 < uVar19) {
      unaff_r16 = 0x3a8;
    }
    uVar1 = *(undefined2 *)(iVar22 + iVar16 + -0x13a);
    uVar23 = *(uint *)(iVar17 + iVar16 + 0xbaac);
    if (uVar19 < 8) {
      unaff_r16 = (uint)*(ushort *)(CSWTCH_176 + uVar19 * 2);
    }
    uVar18 = doorbell_trace_count_5 + 1;
    doorbell_trace_count_5 = uVar18;
    if (uVar18 < 0x21) {
      uVar2 = *(undefined2 *)(iVar22 + iVar16 + -0x138);
      pcVar24 = rtl_read_dword;
      uVar6 = rtl_read_dword(iVar17,unaff_r16);
      uVar7 = (*pcVar24)(iVar17,0x300);
      uVar8 = (*pcVar24)(iVar17,0xb0);
      uVar9 = (*pcVar24)(iVar17,0xb4);
      uVar10 = (*pcVar24)(iVar17,0xb8);
      uVar11 = (*pcVar24)(iVar17,0xbc);
      uVar12 = (*pcVar24)(iVar17,0x210);
      uVar13 = (*pcVar24)(iVar17,0x288);
      uVar14 = rtl_read_word(iVar17,0x41a);
      uVar15 = rtl_read_word(iVar17,0x10c);
      (*(code *)&printk)(&DAT_ram_0001dd04,uVar18,uVar19,uVar1,uVar2,uVar6,uVar7,uVar8,uVar9,uVar10,
                         uVar11,uVar12,uVar13,uVar14,uVar15);
    }
    if (uVar19 == 4) {
      *(undefined2 *)(iVar17 + 0xbb76) = 0;
      *(undefined2 *)(iVar17 + 0xbb78) = 0;
      *param_2 = *param_2 | 0x80000000;
      if (uVar18 < 0x21) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    else {
      puVar20 = (ushort *)(iVar22 + iVar16 + -0x13a);
      uVar5 = (*(code *)&__modsi3)(*puVar20 + 1,uVar23 & 0xffff);
      *puVar20 = uVar5;
      if (bVar25) {
        if (__print_once_15 == '\0') {
          __print_once_15 = '\x01';
          (*(code *)&printk)(&DAT_ram_0001ddfc,uVar4);
        }
        sync(0);
      }
      puVar21 = (undefined2 *)(iVar22 + iVar16 + -0x13a);
      rtl_write_word(iVar17,unaff_r16,*puVar21);
      if (uVar18 < 0x21) {
        uVar2 = *puVar21;
        uVar3 = *(undefined2 *)(iVar22 + iVar16 + -0x138);
        uVar6 = rtl_read_dword(iVar17,unaff_r16);
        uVar7 = rtl_read_dword(iVar17,0x300);
        uVar8 = rtl_read_dword(iVar17,0xb0);
        uVar9 = rtl_read_dword(iVar17,0xb4);
        uVar10 = rtl_read_dword(iVar17,0xb8);
        uVar11 = rtl_read_dword(iVar17,0xbc);
        uVar12 = rtl_read_dword(iVar17,0x210);
        uVar13 = rtl_read_dword(iVar17,0x288);
        uVar14 = rtl_read_word(iVar17,0x41a);
        uVar15 = rtl_read_word(iVar17,0x10c);
        (*(code *)&printk)(&DAT_ram_0001de54,uVar18,uVar19,uVar1,uVar2,uVar3,uVar6,uVar7,uVar8,uVar9
                           ,uVar10,uVar11,uVar12,uVar13,uVar14,uVar15);
      }
    }
    return;
  }
  if (param_4 == '\x02') {
    param_2[0xc] = *param_5;
    return;
  }
  return;
}

