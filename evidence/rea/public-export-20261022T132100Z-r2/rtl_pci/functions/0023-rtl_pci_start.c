/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10978; aliases: rtl_pci_start
 */

int rtl_pci_start(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(param_1 + 0x40);
  puVar4 = *(undefined4 **)(iVar3 + 0xb9ac);
  rtl_pci_reset_trx_ring();
  *(undefined1 *)(iVar3 + 0xba9b) = 0;
  pcVar1 = *(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x104);
  if ((pcVar1 == (code *)0x0) || (iVar2 = (*pcVar1)(), iVar2 == 0)) {
    if (puVar4 == (undefined4 *)0x0) goto LAB_ram_000109de;
    pcVar1 = (code *)puVar4[1];
  }
  else {
    *(undefined1 *)(iVar3 + 0xb9b4) = 0x24;
    (*(code *)*puVar4)(iVar3);
    pcVar1 = (code *)puVar4[3];
  }
  (*pcVar1)(iVar3);
LAB_ram_000109de:
  iVar2 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x14))(param_1);
  if (iVar2 == 0) {
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x50))(param_1,0x35,iVar3 + 0x599);
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x24))(param_1);
    (*(code *)&rtl_init_rx_config)(param_1);
    *(undefined1 *)(iVar3 + 0x698) = 1;
    rtl_pci_irq_line_release_isra_0(*(undefined4 *)(param_1 + 0x40),"start-ready");
    *(uint *)(iVar3 + 0xb304) = *(uint *)(iVar3 + 0xb304) & 0xfffffff7;
    *(undefined1 *)(iVar3 + 0xba9c) = 0;
  }
  else {
    (*(code *)&kfree)(*(undefined4 *)(iVar3 + 0xb9bc));
    (*(code *)&kfree)(*(undefined4 *)(iVar3 + 0xb9c0));
  }
  return iVar2;
}

