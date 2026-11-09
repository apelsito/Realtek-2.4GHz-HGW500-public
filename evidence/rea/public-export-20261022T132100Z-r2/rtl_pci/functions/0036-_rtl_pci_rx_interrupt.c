/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11b70; aliases: _rtl_pci_rx_interrupt
 */

int _rtl_pci_rx_interrupt(int param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined1 local_13d;
  undefined4 uStack_13c;
  undefined2 local_138;
  undefined2 local_136;
  undefined1 uStack_134;
  undefined1 local_133;
  undefined1 local_132;
  undefined2 local_130;
  undefined2 local_12e;
  undefined1 auStack_12c [38];
  char local_106;
  undefined1 auStack_fc [48];
  undefined1 auStack_cc [19];
  undefined1 local_b9;
  byte local_96;
  byte local_8b;
  byte local_8a;
  undefined1 local_55;
  undefined1 local_54;
  char local_4a;
  
  iVar13 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(auStack_12c,0,0x30);
  local_13d = 0;
  if (*(uint *)(iVar13 + 0xcc80) <= param_2) {
    param_2 = *(uint *)(iVar13 + 0xcc80);
  }
  (*(code *)&memset)(auStack_cc,0,0x94);
  iVar4 = 0;
  iVar16 = 0;
  bVar2 = false;
  do {
    if (param_2 == 0) {
      return iVar4;
    }
    (*(code *)&memset)(&local_138,0,0xc);
    uStack_13c = 0;
    iVar12 = *(int *)(iVar13 + (*(int *)(iVar13 + 0xbc60) + 0x74) * 4 + 0xba94);
    if (*(char *)(iVar13 + 0xba10) == '\0') {
      iVar15 = *(int *)(iVar13 + 0xbc58) + *(int *)(iVar13 + 0xbc60) * 0x20;
      cVar3 = (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x98))(param_1,iVar15,0,0);
      if (cVar3 != '\0') {
        return iVar4;
      }
      iVar17 = 0;
    }
    else {
      if ((iVar16 == 0) &&
         (iVar16 = (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x60))(param_1,0),
         iVar16 == 0)) {
        return iVar4;
      }
      iVar15 = *(int *)(iVar12 + 0xbc);
      iVar17 = *(int *)(iVar13 + 0xc464) + *(int *)(iVar13 + 0xbc60) * 0x10;
    }
    (*(code *)&dma_unmap_page_attrs)
              (*(int *)(iVar13 + 0xba94) + 0x74,*(undefined4 *)(iVar12 + 0x18),
               *(undefined2 *)(iVar13 + 0xcc84),2,0);
    iVar5 = (*(code *)&__netdev_alloc_skb)(0,*(undefined2 *)(iVar13 + 0xcc84),0xa20);
    param_2 = param_2 - 1;
    if (iVar5 != 0) {
      (*(code *)&memset)(auStack_12c,0,0x30);
      (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x78))
                (param_1,auStack_cc,auStack_12c,iVar15,iVar12);
      if (*(char *)(iVar13 + 0xba10) != '\0') {
        (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 100))(param_1,iVar17,0);
      }
      uVar6 = (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x98))(param_1,iVar15,0,5);
      if ((int)(uVar6 & 0xffff) < *(int *)(iVar12 + 0xb4) - *(int *)(iVar12 + 0xb0)) {
        (*(code *)&skb_put)(iVar12);
        iVar7 = (uint)local_8b + (uint)local_8a;
        if (*(char *)(iVar13 + 0xba10) != '\0') {
          iVar7 = iVar7 + 0x18;
        }
        *(int *)(iVar12 + 0xb0) = *(int *)(iVar12 + 0xb0) + iVar7;
        *(int *)(iVar12 + 0xbc) = *(int *)(iVar12 + 0xbc) + iVar7;
        iVar7 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
        if ((iVar7 != 0) && ((*(uint *)(iVar12 + 0xbc) & 1) != 0)) {
          if (*(uint *)(iVar12 + 0xbc) == *(uint *)(iVar12 + 0xb8)) goto LAB_ram_00011d9a;
          uVar8 = *(undefined4 *)(iVar12 + 0x50);
          (*(code *)&skb_push)(iVar12,1);
          (*(code *)&memmove)(*(int *)(iVar12 + 0xbc),*(int *)(iVar12 + 0xbc) + 1,uVar8);
          (*(code *)&skb_trim)(iVar12,uVar8);
          if (__print_once_23 == '\0') {
            __print_once_23 = '\x01';
            (*(code *)&printk)(&DAT_ram_0001516c);
          }
        }
        if (local_4a != '\x04') {
          puVar14 = *(ushort **)(iVar12 + 0xbc);
          uVar1 = *puVar14;
          if ((hgw500_eapol_trace == '\0') ||
             (iVar7 = rtl_pci_hgw500_match_eapol(param_1,iVar12,uVar1,&local_138), iVar7 == 0)) {
            iVar7 = 0;
          }
          else {
            iVar7 = rtl_pci_hgw500_eapol_should_log_constprop_0(0,&uStack_13c);
          }
          if (((local_96 & 3) == 0) && (4 < *(uint *)(iVar12 + 0x50))) {
            (*(code *)&memcpy)(iVar12 + 0x18,auStack_12c,0x30);
            if (((puVar14[3] & puVar14[2] & puVar14[4]) != 0xffff) && ((puVar14[2] & 1) == 0)) {
              uVar11 = *(uint *)(iVar12 + 0x50);
              uVar6 = *(uint *)(iVar13 + 0xb3ec);
              *(uint *)(iVar13 + 0xb3ec) = uVar6 + uVar11;
              *(uint *)(iVar13 + 0xb3f0) = *(int *)(iVar13 + 0xb3f0) + (uint)CARRY4(uVar6,uVar11);
              bVar2 = true;
            }
            (*(code *)&rtl_is_special_data)(param_1,iVar12,0,1);
            if (((uVar1 & 0xc) == 8) &&
               ((**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x90))(param_1,5), bVar2))
            {
              *(int *)(iVar13 + 0xb7c4) = *(int *)(iVar13 + 0xb7c4) + 1;
            }
            (*(code *)&rtl_collect_scan_list)(param_1,iVar12);
            (*(code *)&rtl_beacon_statistic)(param_1,iVar12);
            (*(code *)&rtl_p2p_info)
                      (param_1,*(undefined4 *)(iVar12 + 0xbc),*(undefined4 *)(iVar12 + 0x50));
            (*(code *)&rtl_swlps_beacon)
                      (param_1,*(undefined4 *)(iVar12 + 0xbc),*(undefined4 *)(iVar12 + 0x50));
            (*(code *)&rtl_recognize_peer)
                      (param_1,*(undefined4 *)(iVar12 + 0xbc),*(undefined4 *)(iVar12 + 0x50));
            if (iVar7 != 0) {
              (*(code *)&printk)(&DAT_ram_000151b8,uStack_13c,iVar12,uVar1,
                                 *(undefined4 *)(iVar12 + 0x50),local_138,puVar14[0xb] >> 4,
                                 puVar14[0xb] & 0xf,uVar1 >> 0xe & 1,uVar1 >> 0xb & 1,local_8b,
                                 local_8a,local_b9,local_54,local_55,local_96 >> 1 & 1,
                                 local_96 >> 2 & 1,(int)local_106,puVar14 + 2,puVar14 + 5,
                                 puVar14 + 8,uStack_134,local_133,local_136,local_132,local_130,
                                 local_12e);
            }
            if (((*(int *)(iVar13 + 0x3f4) != 3) || (*(int *)(iVar13 + 0x6d0) != 0)) ||
               (((uVar1 & 0xfc) != 0x80 && ((uVar1 & 0xfc) != 0x50)))) {
              (*(code *)&memcpy)(auStack_fc,auStack_12c,0x30);
              iVar7 = (*(code *)&rtl_action_proc)(param_1,iVar12,0);
              if (iVar7 != 0) {
                iVar7 = (*(code *)&__netdev_alloc_skb)(0,*(int *)(iVar12 + 0x50) + 0x80,0xa20);
                if (iVar7 != 0) {
                  (*(code *)&memcpy)(iVar7 + 0x18,auStack_fc,0x30);
                  uVar10 = *(undefined4 *)(iVar12 + 0x50);
                  uVar8 = *(undefined4 *)(iVar12 + 0xbc);
                  uVar9 = (*(code *)&skb_put)(iVar7,uVar10);
                  (*(code *)&memcpy)(uVar9,uVar8,uVar10);
                  dev_kfree_skb_any(iVar12);
                  iVar12 = iVar7;
                }
                (*(code *)&ieee80211_rx_irqsafe)(param_1,iVar12);
                goto LAB_ram_00011e34;
              }
            }
          }
          goto LAB_ram_00011d9a;
        }
        (*(code *)&rtl_c2hcmd_enqueue)(param_1,iVar12);
      }
      else {
LAB_ram_00011d9a:
        dev_kfree_skb_any(iVar12);
      }
LAB_ram_00011e34:
      if (*(char *)(iVar13 + 0xba10) != '\0') {
        *(ushort *)(iVar13 + 0xc468) = *(short *)(iVar13 + 0xc468) + 1U & 0x1ff;
        iVar16 = iVar16 + -1;
        (**(code **)(iVar13 + 0x744))(iVar13,0x3b4);
        if (*(char *)(*(int *)(iVar13 + 0xb8fc) + 1) != '\0') {
          (**(code **)(iVar13 + 0x754))(iVar13,0x3b4);
        }
      }
      iVar12 = iVar5;
      if ((8 < *(uint *)(iVar13 + 0xb7c4) + *(int *)(iVar13 + 0xb7c0)) ||
         (2 < *(uint *)(iVar13 + 0xb7c4))) {
        (*(code *)&rtl_lps_leave)(param_1,0);
      }
    }
    if (*(char *)(iVar13 + 0xba10) == '\0') {
      iVar17 = _rtl_pci_init_one_rxdesc(param_1,iVar12,iVar15,0,*(undefined4 *)(iVar13 + 0xbc60));
      if ((iVar17 == 0) && (iVar5 != 0)) {
        dev_kfree_skb_any(iVar12);
      }
      if (*(int *)(iVar13 + 0xbc60) == *(int *)(iVar13 + 0xcc80) + -1) {
        (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x94))
                  (param_1,iVar15,0,6,&local_13d);
      }
    }
    else {
      iVar15 = _rtl_pci_init_one_rxdesc(param_1,iVar12,iVar17);
      if ((iVar15 == 0) && (iVar5 != 0)) {
        dev_kfree_skb_any(iVar12);
      }
    }
    uVar8 = (*(code *)&__umodsi3)(*(int *)(iVar13 + 0xbc60) + 1,*(undefined4 *)(iVar13 + 0xcc80));
    *(undefined4 *)(iVar13 + 0xbc60) = uVar8;
    iVar4 = iVar4 + 1;
  } while( true );
}

