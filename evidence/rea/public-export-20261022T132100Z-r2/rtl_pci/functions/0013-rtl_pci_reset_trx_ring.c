/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10170; aliases: rtl_pci_reset_trx_ring
 */

undefined4 rtl_pci_reset_trx_ring(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 local_35;
  undefined4 uStack_34;
  
  iVar9 = *(int *)(param_1 + 0x40);
  local_35 = 1;
  uStack_34 = 0;
  iVar11 = 0;
  do {
    iVar2 = iVar11 * 0x814;
    iVar7 = iVar9 + 0xb800;
    if ((*(char *)(iVar9 + 0xba10) == '\0') && (*(int *)(iVar7 + iVar2 + 0x458) != 0)) {
      *(undefined4 *)(iVar7 + iVar2 + 0x460) = 0;
      iVar8 = 0;
      for (iVar10 = 0; iVar5 = *(int *)(*(int *)(iVar9 + 0xb8fc) + 0xc),
          iVar10 < *(int *)(iVar9 + 0xcc80); iVar10 = iVar10 + 1) {
        iVar8 = *(int *)(iVar7 + iVar2 + 0x458) + iVar10 * 0x20;
        uStack_34 = (**(code **)(iVar5 + 0x98))(param_1,iVar8,0,4);
        (*(code *)&memset)(iVar8,0,0x20);
        pcVar6 = *(code **)(*(int *)(*(int *)(iVar9 + 0xb8fc) + 0xc) + 0x94);
        if (*(char *)(iVar9 + 0xba10) == '\0') {
          (*pcVar6)(param_1,iVar8,0,4,&uStack_34);
          (**(code **)(*(int *)(*(int *)(iVar9 + 0xb8fc) + 0xc) + 0x94))
                    (param_1,iVar8,0,5,iVar9 + 0xcc84);
          pcVar6 = *(code **)(*(int *)(*(int *)(iVar9 + 0xb8fc) + 0xc) + 0x94);
        }
        (*pcVar6)(param_1,iVar8,0);
      }
      (**(code **)(iVar5 + 0x94))(param_1,iVar8,0,6,&local_35);
    }
    *(undefined4 *)(iVar2 + iVar7 + 0x460) = 0;
    bVar1 = iVar11 != 1;
    iVar11 = 1;
  } while (bVar1);
  uVar3 = arch_local_irq_save();
  iVar11 = 0;
  do {
    iVar2 = iVar11 * 0x2c;
    if ((*(int *)(iVar7 + iVar2 + 0x2a0) != 0) || (*(int *)(iVar7 + iVar2 + 700) != 0)) {
      while (iVar8 = iVar7 + iVar2, *(int *)(iVar8 + 0x2b8) != 0) {
        iVar10 = __skb_dequeue(iVar9 + 0xba94 + iVar2 + 0x1c);
        if (*(char *)(iVar9 + 0xba10) == '\0') {
          iVar5 = *(int *)(iVar8 + 0x2a0);
          iVar8 = *(int *)(iVar8 + 0x2a8) << 6;
        }
        else {
          iVar5 = *(int *)(iVar8 + 700);
          iVar8 = *(int *)(iVar8 + 0x2a8) * (uint)*(ushort *)(iVar9 + iVar2 + 0xbac4);
        }
        iVar12 = *(int *)(iVar9 + 0xba94);
        uVar4 = _rtl_pci_tx_buffer_addr(param_1,iVar2 + 0xc + iVar9 + 0xba94,iVar5 + iVar8);
        (*(code *)&dma_unmap_page_attrs)(iVar12 + 0x74,uVar4,*(undefined4 *)(iVar10 + 0x50),1,0);
        (*(code *)&__dev_kfree_skb_irq)(iVar10,1);
        iVar8 = iVar7 + iVar2;
        uVar4 = (*(code *)&__umodsi3)(*(int *)(iVar8 + 0x2a8) + 1,*(undefined4 *)(iVar8 + 0x2ac));
        *(undefined4 *)(iVar8 + 0x2a8) = uVar4;
      }
      if (*(char *)(iVar9 + 0xba10) != '\0') {
        iVar8 = iVar9 + 0xbc00 + iVar2;
        *(undefined2 *)(iVar8 + -0x138) = 0;
        *(undefined2 *)(iVar8 + -0x13a) = 0;
      }
      *(undefined4 *)(iVar7 + iVar2 + 0x2a8) = 0;
      *(undefined4 *)(iVar7 + iVar2 + 0x2ac) = *(undefined4 *)(iVar7 + (iVar11 + 0x66) * 4 + 0x294);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 != 9);
  Auxregs0028 = uVar3;
  return 0;
}

