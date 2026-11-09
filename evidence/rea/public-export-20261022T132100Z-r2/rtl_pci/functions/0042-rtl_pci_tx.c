/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12978; aliases: rtl_pci_tx
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int rtl_pci_tx(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  code *pcVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  uint *puVar22;
  undefined4 uVar23;
  int iVar24;
  ushort *puVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  bool bVar30;
  bool bVar31;
  int iStack_70;
  byte local_52 [2];
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined1 uStack_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  
  iVar29 = *(int *)(param_1 + 0x40);
  local_52[0] = _rtl_mac_to_hwqueue(param_1,param_3);
  puVar25 = (ushort *)param_3[0x2f];
  uVar21 = trace_count_3 + 1;
  local_52[1] = 1;
  uVar1 = *puVar25;
  iVar24 = *(int *)(param_1 + 0x40);
  iStack_50 = 0;
  iStack_4c = 0;
  trace_count_3 = uVar21;
  (*(code *)&memset)(&local_44,0,0xc);
  uStack_48 = 0;
  if ((hgw500_eapol_trace == '\0') ||
     (iVar4 = rtl_pci_hgw500_match_eapol(param_1,param_3,uVar1,&local_44), iVar4 == 0)) {
    if (uVar21 < 0x21) {
      iStack_70 = 0;
      goto LAB_ram_00012a40;
    }
LAB_ram_00012a62:
    iStack_70 = 0;
  }
  else {
    iStack_70 = rtl_pci_hgw500_eapol_should_log_constprop_0(1,&uStack_48);
    if (uVar21 < 0x21) {
LAB_ram_00012a40:
      (*(code *)&printk)(&DAT_ram_00015a28,uVar21,local_52[0],param_3[0x14],
                         *(undefined1 *)(iVar29 + 0xba10));
    }
    if (iStack_70 == 0) goto LAB_ram_00012a62;
    (*(code *)&printk)(&DAT_ram_00015a70,uStack_48,uVar21,param_3,uVar1,param_3[0x14],local_44,
                       local_52[0],(short)param_3[0x17],param_3[0x22],puVar25[0xb] >> 4,
                       puVar25[0xb] & 0xf,uVar1 >> 0xe & 1,uVar1 >> 0xb & 1,param_2 != 0,puVar25 + 2
                       ,puVar25 + 5,puVar25 + 8,uStack_40,local_3f,local_42,local_3e,local_3c,
                       local_3a);
  }
  if ((uVar1 & 0xc) == 0) {
    (*(code *)&rtl_tx_mgmt_proc)(param_1,param_3);
  }
  if (((*(char *)(iVar29 + 0xb318) != '\0') && ((uVar1 & 0x100c) == 8)) && ((uVar1 & 0xfc) != 0x48))
  {
    *puVar25 = *puVar25 | 0x1000;
  }
  (*(code *)&rtl_action_proc)(param_1,param_3,1);
  uVar13 = param_3[0x14];
  if ((puVar25[2] & 1) == 0) {
    uVar11 = *(uint *)(iVar29 + 0xb3d4);
    *(uint *)(iVar29 + 0xb3d4) = uVar11 + uVar13;
    *(uint *)(iVar29 + 0xb3d8) = *(int *)(iVar29 + 0xb3d8) + (uint)CARRY4(uVar11,uVar13);
  }
  else {
    uVar11 = *(uint *)(iVar29 + 0xb3dc);
    *(uint *)(iVar29 + 0xb3dc) = uVar11 + uVar13;
    *(uint *)(iVar29 + 0xb3e0) = *(int *)(iVar29 + 0xb3e0) + (uint)CARRY4(uVar11,uVar13);
  }
  uVar5 = arch_local_irq_save();
  uVar13 = (uint)local_52[0];
  iVar28 = iVar24 + 0xb800;
  iVar4 = uVar13 * 0x2c;
  if (uVar13 == 4) {
    uVar11 = 0;
  }
  else if (*(char *)(iVar29 + 0xba10) == '\0') {
    iVar6 = iVar28 + iVar4;
    uVar11 = (*(code *)&__umodsi3)
                       (*(int *)(iVar6 + 0x2a8) + *(int *)(iVar6 + 0x2b8),
                        *(undefined4 *)(iVar6 + 0x2ac));
    uVar11 = uVar11 & 0xffff;
  }
  else {
    uVar11 = (uint)*(ushort *)(iVar24 + iVar4 + 0xbac6);
  }
  iVar6 = iVar28 + iVar4;
  puVar22 = (uint *)(*(int *)(iVar6 + 0x2a0) + uVar11 * 0x40);
  iStack_50 = *(int *)(iVar6 + 0x2a4) + uVar11 * 0x40;
  if (uVar21 < 0x21) {
    (*(code *)&printk)(&DAT_ram_00015b6c,uVar21,uVar11,*(undefined4 *)(iVar6 + 0x2ac),
                       *(undefined4 *)(iVar6 + 0x2b8),puVar22,&iStack_50,iVar4 + iVar24 + 0xbaa4);
  }
  if (*(char *)(iVar29 + 0xba10) == '\0') {
    cVar3 = (**(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0x98))(param_1,puVar22,1,0);
    if ((cVar3 != '\x01') || (local_52[0] == 4)) {
      puVar20 = (uint *)0x0;
      goto code_r0x00012bb8;
    }
    if (0x20 < uVar21) goto LAB_ram_00012d1c;
    puVar7 = &DAT_ram_00015bdc;
  }
  else {
    iStack_4c = *(ushort *)(iVar24 + iVar4 + 0xbac4) * uVar11;
    puVar20 = (uint *)(*(int *)(iVar28 + iVar4 + 700) + iStack_4c);
    iStack_4c = *(int *)((uVar13 + 1) * 0x2c + iVar28 + 0x294) + iStack_4c;
code_r0x00012bb8:
    pcVar14 = *(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0x110);
    if ((pcVar14 == (code *)0x0) || (iVar6 = (*pcVar14)(param_1,local_52[0]), iVar6 != 0)) {
      iVar6 = iVar24 + iVar4 + 0xbaa0;
      if ((uVar1 & 0xc) == 8) {
        (**(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0x90))(param_1,4);
      }
      (**(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0x68))
                (param_1,puVar25,puVar22,puVar20,param_3 + 6,param_2,param_3,local_52[0],param_4);
      bVar2 = local_52[0];
      if ((((hgw500_txbd_final_readback != '\0') && (puVar20 != (uint *)0x0)) && (local_52[0] == 1))
         && (((iVar26 = *(int *)(param_1 + 0x40), *(char *)(iVar26 + 0xba10) != '\0' &&
              (iVar8 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar8 != 0
              )) && (*(short *)(iVar26 + 0x690) == 0xc)))) {
        sync(0);
        uVar27 = *puVar20;
        if ((uVar27 & 0x7fff0000) == 0) {
          iVar26 = (*(code *)&___ratelimit)(_rs_2,"rtl_pci_hgw500_txbd_final_readback");
          if (iVar26 != 0) {
            (*(code *)&printk)(&DAT_ram_00015c50,1,uVar27);
          }
        }
        else if (__print_once_25 == 0) {
          __print_once_25 = bVar2;
          (*(code *)&printk)(&DAT_ram_00015c90,1);
        }
      }
      if ((uVar21 < 0x21) &&
         ((*(code *)&printk)(&DAT_ram_00015cd8,uVar21,local_52[0],uVar11,&iStack_50,&iStack_4c,
                             *puVar22 >> 0x1f,*puVar22,puVar22[1],puVar22[2],puVar22[3],puVar22[7],
                             puVar22[8]), puVar20 != (uint *)0x0)) {
        if (*(short *)(iVar24 + uVar13 * 0x2c + 0xbac4) == 0x20) {
          (*(code *)&printk)(&DAT_ram_00015d6c,uVar21,local_52[0],uVar11,puVar20);
        }
        else {
          (*(code *)&printk)(&DAT_ram_00015de8,uVar21,local_52[0],uVar11,puVar20);
        }
      }
      if (iStack_70 != 0) {
        if (puVar20 == (uint *)0x0) {
          uVar27 = 0;
        }
        else {
          uVar27 = *puVar20 >> 0x1f;
        }
        if (puVar20 == (uint *)0x0) {
          uVar17 = 0;
          uVar19 = 0;
          uVar15 = 0;
          uVar18 = 0;
        }
        else {
          uVar15 = *puVar20;
          uVar19 = puVar20[1];
          uVar17 = puVar20[2];
          uVar18 = puVar20[3];
        }
        (*(code *)&printk)(&DAT_ram_00015e84,uStack_48,uVar21,param_3,local_52[0],uVar11,
                           *(undefined4 *)(uVar13 * 0x2c + iVar28 + 0x2b8),&iStack_50,&iStack_4c,
                           *puVar22 >> 0x1f,uVar27,*puVar22,puVar22[1],puVar22[2],puVar22[3],
                           puVar22[7],puVar22[8],uVar15,uVar19,uVar17,uVar18);
      }
      iVar26 = iVar24 + iVar4 + 0xbab0;
      puVar12 = *(undefined4 **)(iVar26 + 4);
      iVar4 = uVar13 * 0x2c;
      iVar8 = iVar24 + 0xb800;
      *param_3 = iVar26;
      param_3[1] = (int)puVar12;
      *(int **)(iVar26 + 4) = param_3;
      *puVar12 = param_3;
      *(int *)(iVar26 + 8) = *(int *)(iVar8 + iVar4 + 0x2b8) + 1;
      if ((local_52[0] == 1) && (iVar26 = rtl_pci_hgw500_be_summary_active(iVar29), iVar26 != 0)) {
        uVar13 = *(uint *)(iVar8 + iVar4 + 0x2b8);
        hgw500_be_tx_enter_bytes = param_3[0x14] + hgw500_be_tx_enter_bytes;
        iVar26 = hgw500_be_tx_enter_count + 1;
        if (hgw500_be_tx_max_queued < uVar13) {
          hgw500_be_tx_max_queued = uVar13;
        }
        hgw500_be_tx_enter_count = iVar26;
        iVar9 = rtl_pci_hgw500_be_summary_should_log(iVar26);
        if (iVar9 != 0) {
          rtl_pci_hgw500_be_summary_log(iVar6,"enter",iVar26);
        }
      }
      if (uVar21 < 0x21) {
        (*(code *)&printk)(&DAT_ram_00015f60,uVar21,local_52[0],
                           *(undefined4 *)(iVar8 + iVar4 + 0x2b8));
      }
      pbVar16 = local_52;
      if (*(char *)(iVar29 + 0xba10) == '\0') {
        pbVar16 = local_52 + 1;
      }
      (**(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0x94))(param_1,puVar22,1,0,pbVar16);
      if (uVar21 < 0x21) {
        iVar26 = iVar24 + 0xbc00 + iVar4;
        (*(code *)&printk)(&DAT_ram_00015fa0,uVar21,local_52[0],uVar11,
                           *(undefined2 *)(iVar26 + -0x13a),*(undefined2 *)(iVar26 + -0x138),
                           *puVar22 >> 0x1f);
      }
      if (iStack_70 != 0) {
        iVar26 = iVar24 + 0xbc00 + iVar4;
        if (puVar20 == (uint *)0x0) {
          uVar27 = 0;
          uVar13 = 0;
        }
        else {
          uVar13 = *puVar20;
          uVar27 = uVar13 >> 0x1f;
        }
        (*(code *)&printk)(&DAT_ram_00016014,uStack_48,uVar21,param_3,local_52[0],uVar11,
                           *(undefined2 *)(iVar26 + -0x13a),*(undefined2 *)(iVar26 + -0x138),
                           *(undefined4 *)(iVar8 + iVar4 + 0x2b8),*puVar22 >> 0x1f,uVar27,*puVar22,
                           uVar13);
      }
      iVar26 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
      cVar3 = hgw500_tx_queue_guard;
      if (iVar26 == 0) {
        if ((hgw500_tx_queue_guard != '\0') && (local_52[0] == 1)) goto LAB_ram_00013256;
LAB_ram_00013310:
        iVar26 = *(int *)(iVar8 + iVar4 + 0x2ac);
        iVar9 = *(int *)(iVar8 + iVar4 + 0x2b8);
        bVar30 = iVar26 - iVar9 == 1;
        bVar31 = iVar26 == iVar9;
      }
      else {
        if ((hgw500_tx_queue_guard == '\0') || (local_52[0] != 1)) goto LAB_ram_00013310;
        if (hgw500_be_queue_guard_stopped != 0) goto LAB_ram_00013256;
        uVar11 = *(uint *)(iVar8 + iVar4 + 0x2b8);
        uVar13 = rtl_pci_hgw500_guard_high_isra_0(*(undefined4 *)(iVar6 + 0xc));
        bVar30 = uVar13 == uVar11;
        bVar31 = uVar13 < uVar11;
      }
      if ((bVar31 || bVar30) && (local_52[0] != 4)) {
        if ((cVar3 != '\0') && (local_52[0] == 1)) {
          hgw500_be_queue_guard_stopped = local_52[0];
          uVar13 = hgw500_be_queue_guard_stop_count + 1;
          hgw500_be_queue_guard_stop_count = uVar13;
          if ((uVar13 < 9) || (iVar26 = is_power_of_2(uVar13), iVar26 != 0)) {
            uVar23 = *(undefined4 *)(iVar28 + iVar4 + 0x2b8);
            uVar10 = rtl_pci_hgw500_guard_high_isra_0(*(undefined4 *)(iVar6 + 0xc));
            iVar28 = iVar24 + 0xbc00 + iVar4;
            (*(code *)&printk)(&DAT_ram_000160a0,uVar13,1,uVar23,uVar10,
                               *(undefined2 *)(iVar28 + -0x138),*(undefined2 *)(iVar28 + -0x13a));
          }
        }
        (*(code *)&ieee80211_stop_queue)(param_1,(short)param_3[0x17]);
        if ((((hgw500_tx_reclaim_poll != '\0') && (hgw500_tx_queue_guard != '\0')) &&
            (local_52[0] == 1)) && (hgw500_be_queue_guard_stopped != 0)) {
          iVar28 = (*(code *)&queue_delayed_work_on)(1,_system_wq,iVar29 + 0xb8,1);
          (*(code *)&printk)(&DAT_ram_000160f0,local_52[0],*(undefined4 *)(iVar8 + iVar4 + 0x2b8),
                             iVar28);
          if (iVar28 == 0) {
            rtl_pci_hgw500_be_reclaim_rearm_isra_0(*(undefined4 *)(param_1 + 0x40),"tx-arm-busy");
          }
        }
      }
LAB_ram_00013256:
      Auxregs0028 = uVar5;
      if (uVar21 < 0x21) {
        iVar28 = iVar24 + 0xbc00 + iVar4;
        (*(code *)&printk)(&DAT_ram_00016144,uVar21,local_52[0],*(undefined2 *)(iVar28 + -0x13a),
                           *(undefined2 *)(iVar28 + -0x138));
      }
      (**(code **)(*(int *)(*(int *)(iVar29 + 0xb8fc) + 0xc) + 0xa0))(param_1,local_52[0]);
      if (uVar21 < 0x21) {
        iVar4 = iVar24 + 0xbc00 + iVar4;
        (*(code *)&printk)(&DAT_ram_0001618c,uVar21,local_52[0],*(undefined2 *)(iVar4 + -0x13a),
                           *(undefined2 *)(iVar4 + -0x138));
      }
      return 0;
    }
    if (0x20 < uVar21) goto LAB_ram_00012d1c;
    puVar7 = &DAT_ram_00015c14;
  }
  (*(code *)&printk)(puVar7,uVar21);
LAB_ram_00012d1c:
  Auxregs0028 = uVar5;
  return param_3[0x14];
}

