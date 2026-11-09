/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x138b0; aliases: rtl_pci_probe
 */

int rtl_pci_probe(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  uint uVar20;
  code *pcVar21;
  int iVar22;
  bool bVar23;
  char local_45;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_0001539c,iVar10,*(undefined4 *)(param_1 + 0x170));
  iVar10 = (*(code *)&pci_enable_device)(param_1);
  if (iVar10 != 0) {
    if (__warned_22 != '\0') {
      return iVar10;
    }
    iVar17 = *(int *)(param_1 + 0xa0);
    __warned_22 = 1;
    if (iVar17 == 0) {
      iVar17 = *(int *)(param_1 + 0x74);
    }
    (*(code *)&warn_slowpath_fmt)
              ("drivers/net/wireless/realtek/rtlwifi/pci.c",0xbbe,9,
               "%s : Cannot enable new PCI device\n",iVar17);
    return iVar10;
  }
  iVar10 = param_1 + 0x74;
  if ((*(char *)(*(int *)(*(int *)(param_2 + 0x18) + 0x10) + 0x14) == '\0') ||
     (iVar17 = (*(code *)&dma_set_mask)(iVar10,0xffffffff,0xffffffff), iVar17 != 0)) {
    iVar17 = (*(code *)&dma_set_mask)(iVar10,0xffffffff,0);
    if (iVar17 != 0) goto LAB_ram_00013a16;
    iVar17 = (*(code *)&dma_set_coherent_mask)(iVar10,0xffffffff,0);
    if (iVar17 == 0) {
      uVar11 = 0;
      goto LAB_ram_00013a0c;
    }
    if (__warned_20 == '\0') {
      __warned_20 = '\x01';
      pcVar14 = "rtlwifi: Unable to obtain 32bit DMA for consistent allocations\n";
      uVar11 = 0xbcf;
      goto LAB_ram_000139ea;
    }
LAB_ram_000139fa:
    iVar18 = -0xc;
    goto LAB_ram_000139fe;
  }
  iVar17 = (*(code *)&dma_set_coherent_mask)(iVar10,0xffffffff,0xffffffff);
  if (iVar17 != 0) {
    if (__warned_21 == '\0') {
      __warned_21 = '\x01';
      pcVar14 = "Unable to obtain 64bit DMA for consistent allocations\n";
      uVar11 = 0xbc6;
LAB_ram_000139ea:
      (*(code *)&warn_slowpath_fmt)("drivers/net/wireless/realtek/rtlwifi/pci.c",uVar11,9,pcVar14);
    }
    goto LAB_ram_000139fa;
  }
  uVar11 = 1;
LAB_ram_00013a0c:
  platform_enable_dma64(param_1,uVar11);
LAB_ram_00013a16:
  (*(code *)&pci_set_master)(param_1);
  iVar17 = (*(code *)&ieee80211_alloc_hw_nm)(0xcccc,&rtl_ops,0);
  if (iVar17 == 0) {
    if (__warned_19 == '\0') {
      iVar10 = *(int *)(param_1 + 0xa0);
      __warned_19 = '\x01';
      if (iVar10 == 0) {
        iVar10 = *(int *)(param_1 + 0x74);
      }
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/pci.c",0xbdd,9,
                 "%s : ieee80211 alloc failed\n",iVar10);
    }
    goto LAB_ram_000139fa;
  }
  *(int *)(*(int *)(iVar17 + 0x38) + 0x10c) = iVar10;
  *(int *)(param_1 + 0xb4) = iVar17;
  piVar19 = *(int **)(iVar17 + 0x40);
  *piVar19 = iVar17;
  piVar19[0x2ea5] = param_1;
  piVar19[1] = 0;
  (*(code *)&__init_swait_queue_head)(piVar19 + 2,"&x->wait",&hgw500_txbd_compact32);
  *(undefined1 *)(piVar19 + 0x2e67) = 0;
  piVar19[0x2ea5] = param_1;
  piVar19[0x1a3] = 0;
  piVar19[0x2e3f] = *(int *)(param_2 + 0x18);
  piVar19[0x2e40] = (int)rtl_pci_ops;
  (*(code *)&rtl_efuse_ops_init)(iVar17);
  iVar18 = (*(code *)&pci_request_regions)(param_1,"rtl_pci");
  if (iVar18 != 0) {
    if (__warned_18 == '\0') {
      __warned_18 = '\x01';
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/pci.c",0xbfa,9,
                 "rtlwifi: Can\'t obtain PCI resources\n");
    }
    goto LAB_ram_00013b9c;
  }
  iVar18 = param_1 + (uint)*(byte *)piVar19[0x2e3f] * 0x20;
  iVar15 = *(int *)(iVar18 + 0x174);
  iVar6 = *(int *)(iVar18 + 0x178);
  iVar18 = 0;
  if (iVar15 != 0 || iVar6 != 0) {
    iVar18 = (iVar6 + 1) - iVar15;
  }
  iVar18 = (*(code *)&pci_iomap)(param_1,(uint)*(byte *)piVar19[0x2e3f],iVar18);
  piVar19[0x1ce] = iVar18;
  if (iVar18 == 0) {
    if (__warned_17 == '\0') {
      __warned_17 = '\x01';
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/pci.c",0xc07,9,
                 "rtlwifi: Can\'t map PCI mem\n");
    }
    iVar18 = -0xc;
    goto LAB_ram_00013be8;
  }
  pcVar21 = (code *)&pci_write_config_byte;
  (*(code *)&pci_write_config_byte)(param_1,0x81,0);
  (*pcVar21)(param_1,0x44,0);
  (*pcVar21)(param_1,4,6);
  (*pcVar21)(param_1,4,7);
  iVar18 = *(int *)(iVar17 + 0x40);
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x1c);
  local_40 = (uint)local_40._2_2_ << 0x10;
  local_45 = '\0';
  *(undefined1 *)(iVar18 + 0xccc3) = 4;
  uVar3 = *(ushort *)(param_1 + 0x22);
  (*(code *)&pci_read_config_byte)(param_1,8,&local_45);
  (*(code *)&pci_read_config_word)(param_1,0x3c,&local_40);
  if (uVar3 == 0x8723) {
    uVar9 = 8;
    goto LAB_ram_00013d38;
  }
  if (uVar3 < 0x8724) {
    if (uVar3 == 0x818b) {
      uVar9 = 0xc;
      goto LAB_ram_00013d38;
    }
    if (uVar3 < 0x818c) {
      if (uVar3 < 0x8175) {
        if (((0x8170 < uVar3) || (uVar3 == 0x44)) || (uVar3 == 0x47)) goto LAB_ram_00013f66;
        bVar23 = uVar3 == 0x2b;
        goto LAB_ram_00013cce;
      }
      uVar9 = 10;
      if (uVar3 != 0x8179) goto LAB_ram_00013cee;
      goto LAB_ram_00013d38;
    }
    if (uVar3 != 0x8192) {
      bVar23 = uVar3 == 0x8193;
LAB_ram_00013cce:
      if (!bVar23) goto LAB_ram_00013cee;
      uVar9 = 6;
      goto LAB_ram_00013d38;
    }
    if (local_45 != '\x01') {
LAB_ram_00013f66:
      if (local_45 != '\x01') {
        uVar9 = 2;
        goto LAB_ram_00013d38;
      }
      *(undefined2 *)(iVar18 + 0x690) = 0;
    }
LAB_ram_00013f82:
    iVar18 = -0x13;
    goto LAB_ram_00013be8;
  }
  if (uVar3 == 0xb723) {
    uVar9 = 0xb;
LAB_ram_00013d38:
    *(undefined2 *)(iVar18 + 0x690) = uVar9;
  }
  else {
    if (uVar3 < 0xb724) {
      if (uVar3 == 0x8812) {
        uVar9 = 0xe;
      }
      else {
        if (uVar3 != 0x8821) goto LAB_ram_00013cee;
        uVar9 = 0xd;
      }
      goto LAB_ram_00013d38;
    }
    if (uVar3 != 0xb822) {
LAB_ram_00013cee:
      uVar9 = 4;
      goto LAB_ram_00013d38;
    }
    *(undefined2 *)(iVar18 + 0x690) = 0xf;
    *(undefined4 *)(iVar18 + 0x6d8) = 2;
  }
  sVar2 = *(short *)(iVar18 + 0x690);
  if (sVar2 == 6) {
    *(uint *)(iVar18 + 0x6dc) = (uint)(local_45 == '\x01');
LAB_ram_00013d74:
    uVar4 = 0;
  }
  else {
    if ((sVar2 != 0xc) && (sVar2 != 0xf)) goto LAB_ram_00013d74;
    uVar4 = 1;
  }
  *(undefined1 *)(iVar18 + 0xba10) = uVar4;
  *(undefined1 *)(iVar18 + 0xccbd) = *(undefined1 *)(*(int *)(param_1 + 8) + 0x70);
  *(byte *)(iVar18 + 0xccbe) = (byte)(*(uint *)(param_1 + 0x1c) >> 3) & 0x1f;
  *(byte *)(iVar18 + 0xccbf) = *(byte *)(param_1 + 0x1c) & 7;
  *(undefined1 *)(iVar18 + 0xccc3) = 4;
  if (iVar6 != 0) {
    sVar2 = *(short *)(iVar6 + 0x20);
    *(short *)(iVar18 + 0xccc4) = sVar2;
    if (sVar2 == -0x7f7a) {
      uVar4 = 0;
    }
    else if (sVar2 == 0x1002) {
      uVar4 = 1;
    }
    else if (sVar2 == 0x1022) {
      uVar4 = 2;
    }
    else if (sVar2 == 0x1039) {
      uVar4 = 3;
    }
    else {
      if (sVar2 != 0) goto LAB_ram_00013de6;
      uVar4 = 4;
    }
    *(undefined1 *)(iVar18 + 0xccc3) = uVar4;
  }
LAB_ram_00013de6:
  if (*(char *)(iVar18 + 0xccc3) != '\x04') {
    *(undefined1 *)(iVar18 + 0xccc0) = *(undefined1 *)(*(int *)(iVar6 + 8) + 0x70);
    *(byte *)(iVar18 + 0xccc1) = (byte)(*(uint *)(iVar6 + 0x1c) >> 3) & 0x1f;
    *(byte *)(iVar18 + 0xccc2) = *(byte *)(iVar6 + 0x1c) & 7;
    if (*(char *)(iVar18 + 0xccc3) == '\x02') {
      iVar6 = *(int *)(iVar17 + 0x40);
      local_44 = local_44 & 0xffffff00;
      local_3c = 0;
      (*pcVar21)(*(undefined4 *)(iVar6 + 0xba94),0xe0,0xa0);
      (*(code *)&pci_read_config_byte)(*(undefined4 *)(iVar6 + 0xba94),0xe0,&local_44);
      if ((byte)local_44 == -0x60) {
        (*(code *)&pci_read_config_dword)(*(undefined4 *)(iVar6 + 0xba94),0xe4,&local_3c);
        bVar5 = local_3c._2_1_ >> 7;
      }
      else {
        bVar5 = 0;
      }
      *(byte *)(iVar18 + 0xccc8) = bVar5;
    }
  }
  iVar18 = *(int *)(iVar17 + 0x40);
  local_44 = local_44 & 0xffffff00;
  local_3c = local_3c & 0xffff0000;
  (*(code *)&pcie_capability_read_word)(param_1,0x10,&local_3c);
  *(char *)(iVar18 + 0xccbc) = (char)local_3c;
  (*(code *)&pci_read_config_byte)(param_1,0x98,&local_44);
  local_44._0_1_ = (byte)local_44 | 0x10;
  (*pcVar21)(param_1,0x98);
  local_44 = CONCAT31(local_44._1_3_,0x17);
  (*pcVar21)(param_1,0x70f,0x17);
  iVar18 = *(int *)(iVar17 + 0x40);
  *(int *)(iVar18 + 0x724) = iVar10;
  *(code **)(iVar18 + 0x740) = pci_write8_async;
  *(code **)(iVar18 + 0x744) = pci_write16_async;
  *(code **)(iVar18 + 0x748) = pci_write32_async;
  *(code **)(iVar18 + 0x750) = pci_read8_sync;
  *(code **)(iVar18 + 0x754) = pci_read16_sync;
  *(code **)(iVar18 + 0x758) = pci_read32_sync;
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_00015508,iVar10);
  (**(code **)(*(int *)(piVar19[0x2e3f] + 0xc) + 0xc))(iVar17);
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_00015534,iVar10);
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_00015560,iVar10);
  iVar10 = (*(code *)**(undefined4 **)(piVar19[0x2e3f] + 0xc))(iVar17);
  if (iVar10 != 0) {
    (*(code *)&printk)(&DAT_ram_00015590);
    goto LAB_ram_00013f82;
  }
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_000155b0,iVar10);
  (**(code **)(*(int *)(piVar19[0x2e3f] + 0xc) + 0xac))(iVar17);
  iVar10 = *(int *)(iVar17 + 0x40);
  local_3c = local_3c & 0xffffff00;
  *(undefined4 *)(iVar10 + 0xb308) = 0;
  *(undefined1 *)(iVar10 + 0xb2ed) = 0;
  *(undefined1 *)(iVar10 + 0xb30c) = *(undefined1 *)(iVar10 + 0xcca9);
  switch(*(undefined1 *)(iVar10 + 0xcca8)) {
  case 1:
    *(undefined4 *)(iVar10 + 0xb308) = 0x80000000;
    break;
  case 2:
    *(undefined4 *)(iVar10 + 0xb308) = 0x80000002;
    break;
  case 3:
    uVar11 = 0x42;
    goto LAB_ram_000140b2;
  case 4:
    uVar11 = 0x40;
LAB_ram_000140b2:
    *(undefined4 *)(iVar10 + 0xb308) = uVar11;
  }
  uVar7 = *(uint *)(iVar10 + 0xb308);
  uVar12 = uVar7 | 8;
  *(uint *)(iVar10 + 0xb308) = uVar12;
  cVar1 = *(char *)(iVar10 + 0xccaa);
  if (cVar1 == '\x02') {
    if ((int)uVar12 < 0) {
      uVar12 = uVar7 | 9;
    }
    *(uint *)(iVar10 + 0xb308) = uVar12;
  }
  else {
    if (cVar1 == '\x03') {
      uVar7 = uVar7 | 0xc;
    }
    else {
      if ((cVar1 != '\x01') || (-1 < (int)uVar12)) goto LAB_ram_0001408a;
      uVar7 = uVar7 | 9;
    }
    *(uint *)(iVar10 + 0xb308) = uVar7;
  }
LAB_ram_0001408a:
  cVar1 = *(char *)(iVar10 + 0xccab);
  if (cVar1 == '\x01') {
    *(undefined1 *)(iVar10 + 0xb2ed) = 1;
    *(undefined1 *)(iVar10 + 0xb2ee) = 1;
  }
  else if (cVar1 == '\x02') {
    if (*(char *)(iVar10 + 0xccc3) == '\0') {
      *(undefined1 *)(iVar10 + 0xb2ed) = 1;
    }
  }
  else if (cVar1 != '\0') {
    (*(code *)&printk)(&DAT_ram_000155dc);
  }
  (*(code *)&pci_read_config_byte)(*(undefined4 *)(iVar10 + 0xba94),0x80,&local_3c);
  if (*(short *)(iVar10 + 0x690) == 2) {
    bVar23 = (char)local_3c == 'C';
LAB_ram_00014102:
    if (bVar23) {
      *(undefined1 *)(iVar10 + 0xb2ed) = 0;
    }
  }
  else if ((*(short *)(iVar10 + 0x690) == 0xb) &&
          (*(short *)(*(int *)(iVar10 + 0xba94) + 0x24) == 0x11ad)) {
    bVar23 = *(short *)(*(int *)(iVar10 + 0xba94) + 0x26) == 0x1723;
    goto LAB_ram_00014102;
  }
  if ((*(uint *)(iVar10 + 0xb308) & 0x40) != 0) {
    rtl_pci_enable_aspm(iVar17);
    *(uint *)(iVar10 + 0xb304) = *(uint *)(iVar10 + 0xb304) | 0x40;
  }
  iVar10 = *(int *)(param_1 + 0xa0);
  if (iVar10 == 0) {
    iVar10 = *(int *)(param_1 + 0x74);
  }
  (*(code *)&printk)(&DAT_ram_00015608,iVar10);
  iVar18 = (*(code *)&rtl_init_core)(iVar17);
  if (iVar18 == 0) {
    iVar10 = *(int *)(param_1 + 0xa0);
    if (iVar10 == 0) {
      iVar10 = *(int *)(param_1 + 0x74);
    }
    (*(code *)&printk)(&DAT_ram_00015664,iVar10);
    iVar10 = *(int *)(param_1 + 0xa0);
    if (iVar10 == 0) {
      iVar10 = *(int *)(param_1 + 0x74);
    }
    (*(code *)&printk)(&DAT_ram_00015694,iVar10);
    iVar18 = *(int *)(iVar17 + 0x40);
    *(undefined1 *)(iVar18 + 0xba9c) = 1;
    *(undefined1 *)(iVar18 + 0xba9e) = 0;
    *(undefined1 *)(iVar18 + 0xcc8c) = 0;
    iVar10 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
    uVar4 = 0;
    if (iVar10 != 0) {
      if ((*(int *)(param_1 + 0x170) == 0x1c) && (*(short *)(param_1 + 0x20) == 0x10ec)) {
        uVar4 = 1;
        if (*(short *)(param_1 + 0x22) != -0x7e75) {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
    }
    *(undefined1 *)(iVar18 + 0xba99) = uVar4;
    *(undefined1 *)(iVar18 + 0xba9a) = 0;
    if (((hgw500_txbd_compact32 == '\0') ||
        (iVar10 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar10 == 0))
       || (*(short *)(iVar18 + 0x690) != 0xc)) {
      bVar5 = 0;
    }
    else {
      bVar5 = *(byte *)(*(int *)(*(int *)(iVar18 + 0xb8fc) + 0x10) + 0x14) ^ 1;
    }
    iVar10 = iVar18 + 0xbc00;
    *(byte *)(iVar18 + 0xbc50) = bVar5 & 1;
    if (*(char *)(iVar18 + 0xba99) != '\0') {
      topaz_deferred_inta = 0;
      topaz_deferred_intb = 0;
    }
    (*(code *)&printk)(&DAT_ram_000156c4,*(char *)(iVar18 + 0xba99),*(undefined4 *)(param_1 + 0x170)
                       ,*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22));
    (*(code *)&printk)(&DAT_ram_0001571c,*(undefined1 *)(iVar10 + 0x50),hgw500_txbd_compact32,
                       *(undefined1 *)(*(int *)(*(int *)(iVar18 + 0xb8fc) + 0x10) + 0x14));
    *(int *)(iVar18 + 0x628) = iVar17;
    *(int *)(iVar18 + 0xba94) = param_1;
    iVar10 = *(int *)(iVar17 + 0x40);
    sVar2 = *(short *)(iVar10 + 0x690);
    if ((sVar2 == 0xc) || (sVar2 == 0xf)) {
      uVar11 = 0x200;
    }
    else {
      uVar11 = 0x80;
    }
    uVar7 = 0;
    do {
      iVar6 = uVar7 * 4;
      uVar7 = uVar7 + 1 & 0xff;
      *(undefined4 *)(iVar10 + iVar6 + 0xbc2c) = uVar11;
    } while (uVar7 != 9);
    if (((*(char *)(iVar10 + 0xbc50) == '\0') || (*(char *)(iVar10 + 0xba99) == '\0')) ||
       (sVar2 != 0xc)) {
      uVar11 = 2;
    }
    else {
      uVar11 = 4;
    }
    *(undefined4 *)(iVar10 + 0xbc3c) = uVar11;
    if (*(char *)(*(int *)(iVar17 + 0x40) + 0xba10) == '\0') {
      *(undefined4 *)(iVar10 + 0xbc30) = 0x100;
    }
    *(undefined2 *)(iVar10 + 0xcc84) = 0x238c;
    *(undefined4 *)(iVar10 + 0xcc80) = 0x200;
    *(undefined4 *)(iVar18 + 0x5a0) = 100;
    *(undefined4 *)(iVar18 + 0x5a4) = 0x7030000;
    *(undefined2 *)(iVar18 + 0x598) = 0x707;
    *(undefined4 *)(iVar18 + 0xccb0) = 2;
    (*(code *)&tasklet_setup)(iVar18 + 0x88,_rtl_pci_irq_tasklet);
    (*(code *)&tasklet_setup)(iVar18 + 0xa0,_rtl_pci_prepare_bcn_tasklet);
    *(int *)(iVar18 + 0xbc) = iVar18 + 0xbc;
    *(int *)(iVar18 + 0xc0) = iVar18 + 0xbc;
    *(undefined4 *)(iVar18 + 0xb8) = 0xffffffe0;
    *(code **)(iVar18 + 0xc4) = _rtl_pci_rx_work;
    (*(code *)&init_timer_key)(iVar18 + 200,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined4 *)(iVar18 + 0x1f0) = 0xffffffe0;
    *(int *)(iVar18 + 500) = iVar18 + 500;
    *(int *)(iVar18 + 0x1f8) = iVar18 + 500;
    *(undefined1 **)(iVar18 + 0x1fc) = &rtl_lps_change_work_callback;
    iVar18 = *(int *)(iVar17 + 0x40);
    iVar10 = 0;
    do {
      iVar16 = *(int *)(iVar17 + 0x40);
      iVar22 = iVar16 + 0xb800;
      iVar13 = iVar16 + (-iVar10 & 0x814U) + 0xbc5c;
      iVar6 = iVar10 * 0x814;
      iVar15 = *(int *)(iVar16 + 0xba94) + 0x74;
      if (*(char *)(iVar16 + 0xba10) == '\0') {
        local_3c = CONCAT31(local_3c._1_3_,1);
        uVar7 = (*(code *)&dma_alloc_attrs)(iVar15,*(int *)(iVar16 + 0xcc80) << 5,iVar13,0xcc0,0);
        *(uint *)(iVar22 + iVar6 + 0x458) = uVar7;
        if ((uVar7 == 0) || ((uVar7 & 0xff) != 0)) goto LAB_ram_0001448e;
        *(undefined4 *)(iVar22 + iVar6 + 0x460) = 0;
        iVar13 = 0;
        for (iVar15 = 0; iVar15 < *(int *)(iVar16 + 0xcc80); iVar15 = iVar15 + 1) {
          iVar13 = *(int *)(iVar22 + iVar6 + 0x458) + iVar15 * 0x20;
          iVar8 = _rtl_pci_init_one_rxdesc(iVar17,0,iVar13,iVar10);
          if (iVar8 == 0) goto LAB_ram_0001449e;
        }
        (**(code **)(*(int *)(*(int *)(iVar16 + 0xb8fc) + 0xc) + 0x94))(iVar17,iVar13,0,6,&local_3c)
        ;
      }
      else {
        uVar7 = (*(code *)&dma_alloc_attrs)(iVar15,*(int *)(iVar16 + 0xcc80) << 4,iVar13,0xcc0,0);
        *(uint *)(iVar22 + iVar6 + 0xc64) = uVar7;
        if ((uVar7 == 0) || ((uVar7 & 0xff) != 0)) {
LAB_ram_0001448e:
          (*(code *)&printk)(&DAT_ram_00015770);
LAB_ram_0001449e:
          iVar18 = -0xc;
          goto LAB_ram_00014650;
        }
        *(undefined4 *)(iVar22 + iVar6 + 0x460) = 0;
        for (iVar15 = 0; iVar15 < *(int *)(iVar16 + 0xcc80); iVar15 = iVar15 + 1) {
          iVar13 = _rtl_pci_init_one_rxdesc
                             (iVar17,0,*(int *)(iVar22 + iVar6 + 0xc64) + iVar15 * 0x10,iVar10,
                              iVar15);
          if (iVar13 == 0) goto LAB_ram_0001449e;
        }
      }
      bVar23 = iVar10 != 1;
      iVar10 = 1;
    } while (bVar23);
    iVar10 = 0;
    do {
      iVar13 = *(int *)(iVar17 + 0x40);
      iVar6 = iVar18 + 0xb800;
      iVar15 = iVar13 + 0xb800;
      uVar7 = *(uint *)(iVar6 + (iVar10 + 0x66) * 4 + 0x294);
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      if (*(char *)(iVar13 + 0xba10) != '\0') {
        if ((*(char *)(iVar13 + 0xbc50) == '\0') ||
           (((iVar16 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"),
             iVar16 != 0 && (hgw500_txbd_tx5_layout != '\0')) &&
            ((3 < iVar10 || ((iVar10 == 1 && (hgw500_txbd_be_legacy64 != '\0')))))))) {
          iVar16 = 0x40;
        }
        else {
          iVar16 = 0x20;
        }
        iVar22 = iVar10 * 0x2c;
        *(short *)(iVar13 + iVar22 + 0xbac4) = (short)iVar16;
        if (((iVar10 == 4) && (iVar16 == 0x20)) && (*(char *)(iVar13 + 0xba99) != '\0')) {
          (*(code *)&printk)(&DAT_ram_00015794,0x20,uVar7,iVar16 * uVar7,0x80);
        }
        uVar12 = (*(code *)&dma_alloc_attrs)
                           (*(int *)(iVar13 + 0xba94) + 0x74,iVar16 * uVar7,&local_44,0xcc0,0);
        if ((uVar12 != 0) && ((uVar12 & 0xff) == 0)) {
          *(uint *)(iVar15 + iVar22 + 700) = uVar12;
          *(uint *)((iVar10 + 1) * 0x2c + iVar15 + 0x294) = local_44;
          iVar22 = iVar22 + iVar13 + 0xbc00;
          *(undefined2 *)(iVar22 + -0x138) = 0;
          *(undefined2 *)(iVar22 + -0x13a) = 0;
          if (*(char *)(iVar13 + 0xbc50) != '\0') {
            (*(code *)&printk)(&DAT_ram_00015820,iVar10,*(short *)(iVar22 + -0x13c),
                               *(short *)(iVar22 + -0x13c) == 0x20);
          }
          goto LAB_ram_00014798;
        }
LAB_ram_000145fe:
        (*(code *)&printk)(&DAT_ram_000157f0,iVar10);
        _rtl_pci_free_rx_ring_isra_0(*(undefined4 *)(iVar17 + 0x40),0);
        _rtl_pci_free_rx_ring_isra_0(*(undefined4 *)(iVar17 + 0x40),1);
        iVar10 = 0;
        do {
          iVar18 = iVar6 + iVar10 * 0x2c;
          if ((*(int *)(iVar18 + 0x2a0) != 0) || (*(int *)(iVar18 + 700) != 0)) {
            _rtl_pci_free_tx_ring(iVar17,iVar10);
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 9);
        iVar18 = 1;
LAB_ram_00014650:
        (*(code *)&printk)(&DAT_ram_00015860);
        (*(code *)&printk)(&DAT_ram_0001588c);
        goto LAB_ram_00014670;
      }
LAB_ram_00014798:
      uVar12 = (*(code *)&dma_alloc_attrs)
                         (*(int *)(iVar13 + 0xba94) + 0x74,uVar7 << 6,&local_40,0xcc0,0);
      if ((uVar12 == 0) || ((uVar12 & 0xff) != 0)) goto LAB_ram_000145fe;
      iVar15 = iVar15 + iVar10 * 0x2c;
      *(uint *)(iVar15 + 0x2a0) = uVar12;
      iVar6 = iVar10 * 0x2c + 0xbab0 + iVar13;
      *(undefined4 *)(iVar15 + 0x2a8) = 0;
      *(int *)(iVar15 + 0x2a4) = local_40;
      *(uint *)(iVar15 + 0x2ac) = uVar7;
      *(int *)(iVar15 + 0x2b0) = iVar6;
      *(int *)(iVar15 + 0x2b4) = iVar6;
      *(undefined4 *)(iVar15 + 0x2b8) = 0;
      if (*(char *)(iVar13 + 0xba10) == '\0') {
        uVar20 = 0;
        while (uVar20 < uVar7) {
          iVar6 = (*(code *)&__umodsi3)(uVar20 + 1,uVar7);
          local_3c = iVar6 * 0x40 + local_40;
          (**(code **)(*(int *)(*(int *)(iVar13 + 0xb8fc) + 0xc) + 0x94))
                    (iVar17,uVar20 * 0x40 + uVar12,1,2,&local_3c);
          uVar20 = uVar20 + 1;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != 9);
    iVar10 = *(int *)(param_1 + 0xa0);
    if (iVar10 == 0) {
      iVar10 = *(int *)(param_1 + 0x74);
    }
    (*(code *)&printk)(&DAT_ram_000158ac,iVar10);
    iVar10 = *(int *)(param_1 + 0xa0);
    if (iVar10 == 0) {
      iVar10 = *(int *)(param_1 + 0x74);
    }
    (*(code *)&printk)(&DAT_ram_000158dc,iVar10);
    iVar10 = (*(code *)&ieee80211_register_hw)(iVar17);
    if (iVar10 == 0) {
      iVar10 = *(int *)(param_1 + 0xa0);
      if (iVar10 == 0) {
        iVar10 = *(int *)(param_1 + 0x74);
      }
      (*(code *)&printk)(&DAT_ram_00015938,iVar10);
      *(undefined1 *)((int)piVar19 + 0x216) = 1;
      (*(code *)&rtl_init_rfkill)(iVar17);
      iVar10 = *(int *)(param_1 + 0xa0);
      if (iVar10 == 0) {
        iVar10 = *(int *)(param_1 + 0x74);
      }
      (*(code *)&printk)(&DAT_ram_00015968,iVar10,*(undefined4 *)(param_1 + 0x170));
      if (*(char *)(*(int *)(iVar17 + 0x40) + 0xba99) != '\0') {
        (*(code *)&printk)(&DAT_ram_000159a0,
                           *(undefined4 *)(*(int *)(*(int *)(iVar17 + 0x40) + 0xba94) + 0x170));
      }
      iVar18 = rtl_pci_intr_mode_legacy(iVar17);
      if (iVar18 == 0) {
        iVar10 = *(int *)(param_1 + 0xa0);
        if (iVar10 == 0) {
          iVar10 = *(int *)(param_1 + 0x74);
        }
        (*(code *)&printk)(&DAT_ram_000159e0,iVar10,*(undefined4 *)(param_1 + 0x170));
        uVar11 = arch_local_irq_save();
        piVar19[0x2e41] = piVar19[0x2e41] | 1;
        Auxregs0028 = uVar11;
        return 0;
      }
      (*(code *)&rtl_deinit_rfkill)(iVar17);
      if (*(char *)((int)piVar19 + 0x216) != '\0') {
        (*(code *)&ieee80211_unregister_hw)(iVar17);
        *(undefined1 *)((int)piVar19 + 0x216) = 0;
      }
    }
    else {
      iVar18 = -0x13;
      (*(code *)&printk)(&DAT_ram_00015910);
    }
    rtl_pci_deinit(iVar17);
LAB_ram_00014670:
    (*(code *)&rtl_deinit_core)(iVar17);
  }
  else {
    (*(code *)&printk)(&DAT_ram_00015638);
  }
  (*(code *)&wait_for_completion)(piVar19 + 1);
  (**(code **)(*(int *)(piVar19[0x2e3f] + 0xc) + 4))(iVar17);
LAB_ram_00013be8:
  (*(code *)&pci_release_regions)(param_1);
LAB_ram_00013b9c:
  (*(code *)&ieee80211_free_hw)(iVar17);
LAB_ram_000139fe:
  (*(code *)&pci_disable_device)(param_1);
  return iVar18;
}

