/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1254c; aliases: _rtl_pci_free_rx_ring.isra.0
 */

void _rtl_pci_free_rx_ring_isra_0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = *(int *)(param_1 + 0xcc80);
    if (iVar1 <= iVar3) break;
    iVar1 = *(int *)(param_1 + 0xb800 + (param_2 * 0x205 + iVar3 + 0x74) * 4 + 0x294);
    if (iVar1 != 0) {
      (*(code *)&dma_unmap_page_attrs)
                (*(int *)(param_1 + 0xba94) + 0x74,*(undefined4 *)(iVar1 + 0x18),
                 *(undefined2 *)(param_1 + 0xcc84),2,0);
      (*(code *)&kfree_skb)(iVar1);
    }
    iVar3 = iVar3 + 1;
  }
  iVar2 = param_1 + 0xb800 + param_2 * 0x814;
  iVar3 = *(int *)(param_1 + 0xba94) + 0x74;
  if (*(char *)(param_1 + 0xba10) == '\0') {
    (*(code *)&dma_free_attrs)
              (iVar3,iVar1 << 5,*(undefined4 *)(iVar2 + 0x458),*(undefined4 *)(iVar2 + 0x45c),0);
    *(undefined4 *)(iVar2 + 0x458) = 0;
  }
  else {
    (*(code *)&dma_free_attrs)(iVar3,iVar1 << 4,*(undefined4 *)(iVar2 + 0xc64));
    *(undefined4 *)(iVar2 + 0xc64) = 0;
  }
  return;
}

