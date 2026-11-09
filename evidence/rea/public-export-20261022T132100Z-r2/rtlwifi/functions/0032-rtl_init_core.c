/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x111f8; aliases: rtl_init_core
 */

undefined4 rtl_init_core(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined2 local_20;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if ((*(int *)(iVar3 + 0x6cc) == 0) && (*(int *)(iVar3 + 0x6d8) == 2)) {
    (*(code *)&memcpy)(iVar3 + 0x220,rtl_band_2ghz,0x5c);
    _rtl_init_hw_ht_capab_isra_0(*(undefined4 *)(param_1 + 0x40),iVar3 + 0x234);
    *(int *)(*(int *)(param_1 + 0x38) + 0xcc) = iVar3 + 0x220;
    (*(code *)&memcpy)(iVar3 + 0x27c,rtl_band_5ghz,0x5c);
    _rtl_init_hw_ht_capab_isra_0(*(undefined4 *)(param_1 + 0x40),iVar3 + 0x290);
  }
  else {
    if (*(int *)(iVar3 + 0x6d0) == 0) {
      (*(code *)&memcpy)(iVar3 + 0x220,rtl_band_2ghz,0x5c);
      _rtl_init_hw_ht_capab_isra_0(*(undefined4 *)(param_1 + 0x40),iVar3 + 0x234);
      *(int *)(*(int *)(param_1 + 0x38) + 0xcc) = iVar3 + 0x220;
      goto code_r0x000112d6;
    }
    if (*(int *)(iVar3 + 0x6d0) != 1) {
      (*(code *)&printk)(&DAT_ram_00019964);
      goto code_r0x000112d6;
    }
    (*(code *)&memcpy)(iVar3 + 0x27c,rtl_band_5ghz,0x5c);
    _rtl_init_hw_ht_capab_isra_0(*(undefined4 *)(param_1 + 0x40),iVar3 + 0x290);
  }
  _rtl_init_hw_vht_capab_isra_0(*(undefined4 *)(param_1 + 0x40),iVar3 + 0x2a8);
  *(int *)(*(int *)(param_1 + 0x38) + 0xd0) = iVar3 + 0x27c;
code_r0x000112d6:
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x10;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 2;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x80;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x800;
  if (((rtl_hgw500_honest_tx_ack == '\0') ||
      (iVar1 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2"), iVar1 == 0)) ||
     (*(short *)(iVar3 + 0x690) != 0xc)) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x10000;
  }
  else if (__print_once_0 == '\0') {
    __print_once_0 = '\x01';
    (*(code *)&printk)(&DAT_ram_00019998);
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x40000000;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x8000;
  if (*(char *)(iVar3 + 0xb2f4) != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x100;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x200;
  }
  if (*(char *)(iVar3 + 0xb2f6) != '\0') {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x100;
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x400;
  }
  *(undefined2 *)(*(int *)(param_1 + 0x38) + 0x20) = 0x38e;
  *(uint *)(*(int *)(param_1 + 0x38) + 0x24) = *(uint *)(*(int *)(param_1 + 0x38) + 0x24) | 0x100;
  *(uint *)(*(int *)(param_1 + 0x38) + 0x24) = *(uint *)(*(int *)(param_1 + 0x38) + 0x24) | 0x200000
  ;
  *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x78) = 0x92b;
  *(undefined4 *)(param_1 + 0x4c) = 0x20;
  *(undefined1 *)(param_1 + 0x6b) = 4;
  *(undefined4 *)(param_1 + 100) = 0xa0004;
  *(undefined4 *)(param_1 + 0x58) = 0xf3;
  if (((*(ushort *)(iVar3 + 0xa9f8) & 1) != 0) ||
     (puVar2 = (undefined4 *)(iVar3 + 0xa9f8),
     (*(ushort *)(iVar3 + 0xa9f8) == 0 && *(short *)(iVar3 + 0xa9fa) == 0) &&
     *(short *)(iVar3 + 0xa9fc) == 0)) {
    local_20 = 0x92;
    local_24 = 0x814ce000;
    (*(code *)&get_random_bytes)((int)&local_20 + 1,1);
    puVar2 = &local_24;
  }
  (*(code *)&memcpy)(*(undefined4 *)(param_1 + 0x38),puVar2,6);
  *(int *)(iVar3 + 0x3ec) = param_1;
  *(char **)(param_1 + 0x3c) = "rtl_rc";
  iVar1 = rtl_regd_init(param_1,rtl_reg_notifier);
  if (iVar1 == 0) {
    (*(code *)&__mutex_init)(iVar3 + 0x24,"&rtlpriv->locks.conf_mutex",&hgw500_tx_ampdu_disable);
    (*(code *)&__mutex_init)(iVar3 + 0x30,"&rtlpriv->locks.ips_mutex",&hgw500_tx_ampdu_disable);
    (*(code *)&__mutex_init)(iVar3 + 0x3c,"&rtlpriv->locks.lps_mutex",&hgw500_tx_ampdu_disable);
    *(int *)(iVar3 + 0xb8cc) = iVar3 + 0xb8cc;
    *(int *)(iVar3 + 0xb8d0) = iVar3 + 0xb8cc;
    *(int *)(iVar3 + 0xb2e0) = iVar3 + 0xb2e0;
    *(int *)(iVar3 + 0xb2e4) = iVar3 + 0xb2e0;
    *(int *)(iVar3 + 0xb2d0) = iVar3 + 0xb2d0;
    *(int *)(iVar3 + 0xb2d4) = iVar3 + 0xb2d0;
    *(undefined4 *)(iVar3 + 0xb2d8) = 0;
    *(undefined4 *)(iVar3 + 0xb8dc) = 0;
    *(int *)(iVar3 + 0xb8d4) = iVar3 + 0xb8d4;
    *(int *)(iVar3 + 0xb8d8) = iVar3 + 0xb8d4;
    *(undefined4 *)(iVar3 + 0x4d0) = 0;
    iVar1 = *(int *)(param_1 + 0x40);
    iVar3 = (*(code *)&alloc_workqueue)
                      (&DAT_ram_00019a6c,0,0,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 4));
    if (iVar3 == 0) {
      uVar4 = 0xfffffff4;
    }
    else {
      (*(code *)&init_timer_key)(iVar1 + 0x4c,rtl_watch_dog_timer_callback,0,0,0);
      *(int *)(iVar1 + 0x48) = param_1;
      *(int *)(iVar1 + 0xec) = iVar1 + 0xec;
      *(int *)(iVar1 + 0xf0) = iVar1 + 0xec;
      *(int *)(iVar1 + 0xe4) = iVar3;
      *(undefined4 *)(iVar1 + 0xe8) = 0xffffffe0;
      *(code **)(iVar1 + 0xf4) = rtl_watchdog_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0xf8,&delayed_work_timer_fn,0x200000,0,0);
      *(int *)(iVar1 + 0x118) = iVar1 + 0x118;
      *(int *)(iVar1 + 0x11c) = iVar1 + 0x118;
      *(undefined4 *)(iVar1 + 0x114) = 0xffffffe0;
      *(code **)(iVar1 + 0x120) = rtl_ips_nic_off_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0x124,&delayed_work_timer_fn,0x200000,0,0);
      *(int *)(iVar1 + 0x170) = iVar1 + 0x170;
      *(int *)(iVar1 + 0x174) = iVar1 + 0x170;
      *(undefined4 *)(iVar1 + 0x16c) = 0xffffffe0;
      *(code **)(iVar1 + 0x178) = rtl_swlps_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0x17c,&delayed_work_timer_fn,0x200000,0,0);
      *(int *)(iVar1 + 0x19c) = iVar1 + 0x19c;
      *(int *)(iVar1 + 0x1a0) = iVar1 + 0x19c;
      *(undefined4 *)(iVar1 + 0x198) = 0xffffffe0;
      *(code **)(iVar1 + 0x1a4) = rtl_swlps_rfon_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0x1a8,&delayed_work_timer_fn,0x200000,0,0);
      *(int *)(iVar1 + 0x1c8) = iVar1 + 0x1c8;
      *(int *)(iVar1 + 0x1cc) = iVar1 + 0x1c8;
      *(undefined4 *)(iVar1 + 0x1c4) = 0xffffffe0;
      *(code **)(iVar1 + 0x1d0) = rtl_fwevt_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0x1d4,&delayed_work_timer_fn,0x200000,0,0);
      *(int *)(iVar1 + 0x144) = iVar1 + 0x144;
      *(int *)(iVar1 + 0x148) = iVar1 + 0x144;
      *(undefined4 *)(iVar1 + 0x140) = 0xffffffe0;
      *(code **)(iVar1 + 0x14c) = rtl_c2hcmd_wq_callback;
      (*(code *)&init_timer_key)(iVar1 + 0x150,&delayed_work_timer_fn,0x200000,0,0);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
    (*(code *)&printk)(&DAT_ram_000199f8);
  }
  return uVar4;
}

