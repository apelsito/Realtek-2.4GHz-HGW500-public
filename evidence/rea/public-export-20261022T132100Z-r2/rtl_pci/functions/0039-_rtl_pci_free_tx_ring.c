/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12628; aliases: _rtl_pci_free_tx_ring
 */

void _rtl_pci_free_tx_ring(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = param_2 * 0x2c;
  iVar8 = *(int *)(param_1 + 0x40);
  while( true ) {
    iVar7 = iVar8 + 0xb800;
    iVar5 = iVar7 + iVar1;
    if (*(int *)(iVar5 + 0x2b8) == 0) break;
    iVar2 = __skb_dequeue(iVar8 + 0xba94 + iVar1 + 0x1c);
    if (*(char *)(iVar8 + 0xba10) == '\0') {
      iVar4 = *(int *)(iVar5 + 0x2a0);
      iVar5 = *(int *)(iVar5 + 0x2a8) << 6;
    }
    else {
      iVar4 = *(int *)(iVar5 + 700);
      iVar5 = *(int *)(iVar5 + 0x2a8) * (uint)*(ushort *)(iVar8 + iVar1 + 0xbac4);
    }
    iVar6 = *(int *)(iVar8 + 0xba94);
    uVar3 = _rtl_pci_tx_buffer_addr(param_1,iVar1 + 0xc + iVar8 + 0xba94,iVar4 + iVar5);
    (*(code *)&dma_unmap_page_attrs)(iVar6 + 0x74,uVar3,*(undefined4 *)(iVar2 + 0x50),1,0);
    (*(code *)&kfree_skb)(iVar2);
    iVar7 = iVar7 + iVar1;
    uVar3 = (*(code *)&__umodsi3)(*(int *)(iVar7 + 0x2a8) + 1,*(undefined4 *)(iVar7 + 0x2ac));
    *(undefined4 *)(iVar7 + 0x2a8) = uVar3;
  }
  (*(code *)&dma_free_attrs)
            (*(int *)(iVar8 + 0xba94) + 0x74,*(int *)(iVar5 + 0x2ac) << 6,
             *(undefined4 *)(iVar5 + 0x2a0),*(undefined4 *)(iVar5 + 0x2a4),0);
  *(undefined4 *)(iVar5 + 0x2a0) = 0;
  if (*(char *)(iVar8 + 0xba10) != '\0') {
    (*(code *)&dma_free_attrs)
              (*(int *)(iVar8 + 0xba94) + 0x74,
               *(int *)(iVar5 + 0x2ac) * (uint)*(ushort *)(iVar8 + iVar1 + 0xbac4),
               *(undefined4 *)(iVar5 + 700),*(undefined4 *)((param_2 + 1) * 0x2c + iVar7 + 0x294),0)
    ;
    *(undefined4 *)(iVar5 + 700) = 0;
  }
  return;
}

