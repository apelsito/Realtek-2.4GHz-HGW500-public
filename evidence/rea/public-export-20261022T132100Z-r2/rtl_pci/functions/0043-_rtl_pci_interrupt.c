/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1335c; aliases: _rtl_pci_interrupt
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _rtl_pci_interrupt(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  iVar4 = *(int *)(param_2 + 0x40);
  (*(code *)&memset)(&local_38,0,0x10);
  uVar5 = trace_count_4 + 1;
  trace_count_4 = uVar5;
  if (uVar5 < 0x11) {
    (*(code *)&printk)(&DAT_ram_000161d4,uVar5,param_1,*(undefined1 *)(iVar4 + 0xba98));
  }
  if (*(char *)(iVar4 + 0xba98) == '\0') {
    if (*(char *)(iVar4 + 0xba99) == '\0') {
      if (uVar5 < 0x11) {
        (*(code *)&printk)(&DAT_ram_0001625c,uVar5);
      }
      return 0;
    }
    uVar1 = arch_local_irq_save();
    (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x10))(param_2,&local_38);
    topaz_deferred_inta = local_38 | topaz_deferred_inta;
    topaz_deferred_intb = local_34 | topaz_deferred_intb;
    Auxregs0028 = uVar1;
    if (0x10 < uVar5) {
      return 1;
    }
    (*(code *)&printk)(&DAT_ram_00016210,uVar5,param_1,local_38,local_34);
    return 1;
  }
  uVar1 = arch_local_irq_save();
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x28))(param_2);
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x10))(param_2,&local_38);
  if (*(char *)(iVar4 + 0xba99) != '\0') {
    local_38 = local_38 | topaz_deferred_inta;
    local_34 = local_34 | topaz_deferred_intb;
    topaz_deferred_inta = 0;
    topaz_deferred_intb = 0;
  }
  if (uVar5 < 0x11) {
    (*(code *)&printk)(&DAT_ram_000162ac,uVar5,local_38,local_34,local_30,local_2c);
  }
  if (local_38 == 0) {
    if ((local_34 != 0 || local_30 != 0) || local_2c != 0) {
LAB_ram_00013530:
      _rtl_pci_topaz_tx_complete(param_2,&local_38,&DAT_ram_000162fc);
      if (*(short *)(iVar4 + 0x690) == 0xf) {
        if ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0xfc) & local_2c) != 0) {
          *(int *)(iVar4 + 0xb7c0) = *(int *)(iVar4 + 0xb7c0) + 1;
          _rtl_pci_tx_isr(param_2,5);
          goto code_r0x0001357a;
        }
      }
      else {
code_r0x0001357a:
        if ((*(short *)(iVar4 + 0x690) == 2) &&
           ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0x108) & local_38) != 0)) {
          *(int *)(iVar4 + 0xb7c0) = *(int *)(iVar4 + 0xb7c0) + 1;
          _rtl_pci_tx_isr(param_2,5);
        }
      }
      cVar6 = *(char *)(iVar4 + 0xba99);
      iVar2 = *(int *)(iVar4 + 0xb8fc);
      if ((cVar6 == '\0') ||
         ((((*(uint *)(iVar2 + 0xf4) | *(uint *)(iVar2 + 0x128)) & local_38) == 0 &&
          ((local_34 & *(uint *)(iVar2 + 0xf0)) == 0)))) {
        if ((local_38 & *(uint *)(iVar2 + 0x128)) != 0) {
          _rtl_pci_rx_interrupt(param_2,*(undefined4 *)(iVar4 + 0xcc80));
        }
        if ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0xf4) & local_38) != 0) {
          _rtl_pci_rx_interrupt(param_2,*(undefined4 *)(iVar4 + 0xcc80));
        }
        if ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0xf0) & local_34) != 0) {
          _rtl_pci_rx_interrupt(param_2,*(undefined4 *)(iVar4 + 0xcc80));
        }
        cVar6 = '\0';
      }
      else {
        uVar3 = (*(code *)&queue_delayed_work_on)(1,_system_wq,iVar4 + 0xb8,0);
        if (uVar5 < 0x11) {
          (*(code *)&printk)(&DAT_ram_00016300,uVar5,uVar3,local_38,local_34,0x20,4);
        }
      }
      if (*(short *)(iVar4 + 0x690) == 8) {
        if ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 0x134) & local_38) != 0) {
          (*(code *)&queue_delayed_work_on)(1,*(undefined4 *)(iVar4 + 0xe4),iVar4 + 0x1c4,0);
          goto LAB_ram_0001363c;
        }
      }
      else {
LAB_ram_0001363c:
        if (((ushort)(*(short *)(iVar4 + 0x690) - 10U) < 2) &&
           ((*(uint *)(*(int *)(iVar4 + 0xb8fc) + 300) & local_38) != 0)) {
          iVar2 = *(int *)(param_2 + 0x40);
          uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0xb8fc) + 0x44);
          uVar5 = (**(code **)(iVar2 + 0x750))(iVar2,uVar3);
          (**(code **)(iVar2 + 0x740))(iVar2,uVar3,(uVar5 | *(uint *)(iVar2 + 0xcca0)) & 0xff);
          if (*(char *)(*(int *)(iVar2 + 0xb8fc) + 1) != '\0') {
            (**(code **)(iVar2 + 0x750))(iVar2,uVar3);
          }
        }
      }
      if (*(char *)(iVar4 + 0x6e1) != '\0') {
        tasklet_schedule(iVar4 + 0x88);
      }
      if (cVar6 != '\0') goto LAB_ram_0001350a;
    }
  }
  else if (local_38 != 0xffff) {
    if ((local_38 & *(uint *)(*(int *)(iVar4 + 0xb8fc) + 0xec)) != 0) {
      tasklet_schedule(iVar4 + 0xa0);
    }
    goto LAB_ram_00013530;
  }
  (**(code **)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0xc) + 0x24))(param_2);
LAB_ram_0001350a:
  Auxregs0028 = uVar1;
  return 1;
}

