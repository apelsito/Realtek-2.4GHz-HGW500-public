/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11344; aliases: _rtl_pci_tx_isr
 */

/* WARNING: Control flow encountered bad instruction data */

void _rtl_pci_tx_isr(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ushort *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  code *pcVar17;
  bool bVar18;
  bool bVar19;
  undefined4 uStack_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined1 uStack_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  
  iVar3 = param_2 * 0x2c;
  iVar10 = *(int *)(param_1 + 0x40);
  iVar15 = iVar3 + 0xc + iVar10 + 0xba94;
LAB_ram_00011398:
  do {
    do {
      while( true ) {
        iVar11 = iVar10 + 0xb800;
        iVar8 = iVar11 + iVar3;
        if (*(int *)(iVar8 + 0x2b8) == 0) {
          if ((*(uint *)(iVar10 + 0xb7c4) + *(int *)(iVar10 + 0xb7c0) < 9) &&
             (*(uint *)(iVar10 + 0xb7c4) < 3)) {
            return;
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        (*(code *)&memset)(&local_44,0,0xc);
        uStack_48 = 0;
        uVar16 = (uint)*(ushort *)(iVar8 + 0x2a8);
        if (*(char *)(iVar10 + 0xba10) == '\0') {
          iVar9 = *(int *)(iVar8 + 0x2a0);
          iVar8 = uVar16 << 6;
        }
        else {
          iVar9 = *(int *)(iVar8 + 700);
          iVar8 = *(ushort *)(iVar10 + iVar3 + 0xbac4) * uVar16;
        }
        iVar4 = (**(code **)(*(int *)(*(int *)(iVar10 + 0xb8fc) + 0xc) + 0x9c))
                          (param_1,param_2,uVar16);
        if (iVar4 == 0) {
          return;
        }
        iVar4 = iVar11 + iVar3;
        uVar5 = (*(code *)&__umodsi3)(*(int *)(iVar4 + 0x2a8) + 1,*(undefined4 *)(iVar4 + 0x2ac));
        *(undefined4 *)(iVar4 + 0x2a8) = uVar5;
        iVar4 = __skb_dequeue(iVar10 + 0xba94 + iVar3 + 0x1c);
        iVar13 = *(int *)(iVar10 + 0xba94);
        uVar5 = _rtl_pci_tx_buffer_addr(param_1,iVar15,iVar9 + iVar8);
        (*(code *)&dma_unmap_page_attrs)(iVar13 + 0x74,uVar5,*(undefined4 *)(iVar4 + 0x50),1,0);
        if (*(char *)(iVar10 + 0x6e1) != '\0') {
          (*(code *)&skb_pull)(iVar4,8);
        }
        if (param_2 != 5) break;
LAB_ram_000114d6:
        (*(code *)&kfree_skb)(iVar4);
      }
      uVar1 = **(ushort **)(iVar4 + 0xbc);
      if ((hgw500_eapol_trace == '\0') ||
         (iVar8 = rtl_pci_hgw500_match_eapol(param_1,iVar4,uVar1,&local_44), iVar8 == 0)) {
        iVar8 = 0;
      }
      else {
        iVar8 = rtl_pci_hgw500_eapol_should_log_constprop_0(1,&uStack_48);
      }
      uVar12 = uVar1 & 0xfc;
      if (uVar12 == 0x48) {
        if ((uVar1 & 0x1000) == 0) {
          *(undefined1 *)(iVar10 + 0xb31a) = 0;
        }
        else {
          *(undefined1 *)(iVar10 + 0x4dc) = 1;
          *(undefined1 *)(iVar10 + 0xb31a) = 1;
        }
      }
      else if ((uVar12 == 0xd0) && (*(char *)(*(int *)(iVar4 + 0xbc) + 0x19) == '\x01'))
      goto LAB_ram_000114d6;
      puVar6 = *(ushort **)(iVar4 + 0xbc);
      if ((~*puVar6 & 0x300) == 0) {
        puVar6 = puVar6 + 0xf;
      }
      else {
        puVar6 = puVar6 + 0xc;
      }
      if (((byte)*puVar6 & 8) == 0) {
        iVar9 = iVar10 + ((byte)*puVar6 & 0xf) * 4;
        *(int *)(iVar9 + 0xb860) = *(int *)(iVar9 + 0xb860) + 1;
      }
      uVar2 = *(undefined2 *)(iVar4 + 0x5c);
      if ((param_2 == 1) && (iVar9 = rtl_pci_hgw500_be_summary_active(iVar10), iVar9 != 0)) {
        hgw500_be_tx_complete_count = hgw500_be_tx_complete_count + 1;
        hgw500_be_tx_complete_bytes = *(int *)(iVar4 + 0x50) + hgw500_be_tx_complete_bytes;
        iVar9 = rtl_pci_hgw500_be_summary_should_log(hgw500_be_tx_complete_count);
        if (iVar9 != 0) {
          rtl_pci_hgw500_be_summary_log(iVar15,"complete");
        }
      }
      pcVar17 = (code *)&of_machine_is_compatible;
      if (uVar12 == 0x48) {
        (*(code *)&rtl_tx_ackqueue)(param_1,iVar4);
      }
      else {
        if ((rtl_hgw500_honest_tx_ack == '\0') ||
           (iVar9 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar9 == 0))
        {
          bVar18 = false;
        }
        else {
          bVar18 = *(short *)(iVar10 + 0x690) == 0xc;
        }
        if ((hgw500_mgmt_tx_complete_trace == '\0') || (param_2 != 6)) {
LAB_ram_000115fa:
          bVar19 = false;
        }
        else {
          iVar13 = *(int *)(param_1 + 0x40);
          iVar9 = (*pcVar17)("mitrastar,hgw-500bna-qcv2");
          if ((iVar9 == 0) || (*(short *)(iVar13 + 0x690) != 0xc)) goto LAB_ram_000115fa;
          if (((uVar12 == 0x50) || ((uVar1 & 0xec) == 0xa0)) || ((uVar1 & 0xdc) == 0x10)) {
            bVar19 = true;
          }
          else {
            bVar19 = uVar12 == 0xc0;
          }
        }
        *(byte *)(iVar4 + 0x21) = *(byte *)(iVar4 + 0x21) & 0xe0;
        *(byte *)(iVar4 + 0x24) = *(byte *)(iVar4 + 0x24) & 0xe0;
        *(byte *)(iVar4 + 0x27) = *(byte *)(iVar4 + 0x27) & 0xe0;
        *(byte *)(iVar4 + 0x2a) = *(byte *)(iVar4 + 0x2a) & 0xe0;
        (*(code *)&memset)(iVar4 + 0x30,0,0x18);
        if ((bVar18 ^ 1U) == 0) {
          uVar14 = honest_ack_trace_count_7 + 1;
          honest_ack_trace_count_7 = uVar14;
          if ((uVar14 < 9) || (iVar9 = is_power_of_2(uVar14), iVar9 != 0)) {
            (*(code *)&printk)(&DAT_ram_00014eb4,uVar14,param_2,*(byte *)(iVar4 + 0x18) >> 6 & 1);
          }
        }
        else {
          *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 0x200;
        }
        if (iVar8 != 0) {
          iVar8 = *(int *)(iVar4 + 0xbc);
          iVar9 = iVar10 + 0xbc00 + iVar3;
          (*(code *)&printk)(&DAT_ram_00014f04,uStack_48,iVar4,uVar1,*(undefined4 *)(iVar4 + 0x50),
                             local_44,param_2,uVar16,*(undefined4 *)(iVar11 + iVar3 + 0x2a8),
                             *(undefined4 *)(iVar11 + iVar3 + 0x2b8),*(undefined2 *)(iVar9 + -0x138)
                             ,*(undefined2 *)(iVar9 + -0x13a),*(byte *)(iVar4 + 0x19) >> 1 & 1,uVar2
                             ,*(ushort *)(iVar8 + 0x16) >> 4,*(ushort *)(iVar8 + 0x16) & 0xf,
                             iVar8 + 4,iVar8 + 10,iVar8 + 0x10,uStack_40,local_3f,local_42,local_3e,
                             local_3c,local_3a);
        }
        if (bVar19) {
          iVar8 = *(int *)(iVar4 + 0xbc);
          if (iVar8 + 10 == 0) {
            pcVar7 = "probe_resp";
          }
          else if (uVar12 == 0xb0) {
            pcVar7 = "auth";
          }
          else if (uVar12 == 0x10) {
            pcVar7 = "assoc_resp";
          }
          else if (uVar12 == 0x30) {
            pcVar7 = "reassoc_resp";
          }
          else if (uVar12 == 0xc0) {
            pcVar7 = "deauth";
          }
          else if (uVar12 == 0xa0) {
            pcVar7 = "disassoc";
          }
          else {
            pcVar7 = "mgmt_other";
          }
          (*(code *)&printk)(&DAT_ram_00015014,pcVar7,uVar1,*(undefined4 *)(iVar4 + 0x50),param_2,
                             uVar16,*(undefined4 *)(iVar11 + iVar3 + 0x2a8),
                             *(undefined4 *)(iVar11 + iVar3 + 0x2b8),bVar18 ^ 1U,
                             *(byte *)(iVar4 + 0x19) >> 1 & 1,uVar2,iVar8 + 4,iVar8 + 10,
                             iVar8 + 0x10);
        }
        (*(code *)&ieee80211_tx_status_irqsafe)(param_1,iVar4);
      }
      iVar8 = (*pcVar17)("mitrastar,hgw-500bna-qcv2");
      if (iVar8 == 0) goto LAB_ram_000119c4;
      if ((hgw500_tx_queue_guard == '\0') || (param_2 != 1)) goto LAB_ram_000119ce;
    } while (hgw500_be_queue_guard_stopped == '\0');
    uVar14 = *(uint *)(iVar10 + 0xbae4);
    iVar8 = rtl_pci_hgw500_guard_high_isra_0(*(undefined4 *)(iVar15 + 0xc));
    uVar16 = iVar8 - 1U;
    if (hgw500_tx_queue_guard_low <= iVar8 - 1U) {
      uVar16 = hgw500_tx_queue_guard_low;
    }
  } while (uVar16 < uVar14);
  goto LAB_ram_00011836;
LAB_ram_000119c4:
  if ((hgw500_tx_queue_guard == '\0') || (param_2 != 1)) {
LAB_ram_000119ce:
    if ((uint)(*(int *)(iVar11 + iVar3 + 0x2ac) - *(int *)(iVar11 + iVar3 + 0x2b8)) < 5) {
      if ((hgw500_tx_queue_guard != '\0') && (param_2 == 1)) {
LAB_ram_00011836:
        uVar16 = hgw500_be_queue_guard_wake_count + 1;
        hgw500_be_queue_guard_stopped = '\0';
        hgw500_be_queue_guard_wake_count = uVar16;
        if ((uVar16 < 9) || (iVar8 = is_power_of_2(uVar16), iVar8 != 0)) {
          uVar5 = *(undefined4 *)(iVar10 + 0xbae4);
          iVar8 = rtl_pci_hgw500_guard_high_isra_0(*(undefined4 *)(iVar15 + 0xc));
          uVar14 = iVar8 - 1U;
          if (hgw500_tx_queue_guard_low <= iVar8 - 1U) {
            uVar14 = hgw500_tx_queue_guard_low;
          }
          (*(code *)&printk)(&DAT_ram_000150b8,uVar16,1,uVar5,uVar14,
                             *(undefined2 *)(iVar10 + 0xbaf4),*(undefined2 *)(iVar10 + 0xbaf2));
        }
      }
      (*(code *)&ieee80211_wake_queue)(param_1,uVar2);
    }
  }
  goto LAB_ram_00011398;
}

