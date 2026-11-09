/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11148; aliases: _rtl_pci_prepare_bcn_tasklet
 */

void _rtl_pci_prepare_bcn_tasklet(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined1 local_65;
  undefined1 auStack_64 [56];
  
  iVar9 = *(int *)(param_1 + -0xa0);
  iVar8 = *(int *)(iVar9 + 0x40);
  (*(code *)&memset)(auStack_64,0,0x38);
  local_65 = 1;
  (*(code *)&memset)(auStack_64,0,0x38);
  iVar1 = __skb_dequeue(iVar8 + 0xbb60);
  if (*(char *)(param_1 + 0xb970) == '\0') {
    iVar6 = *(int *)(iVar8 + 0xbb50);
    iVar5 = *(int *)(iVar8 + 0xbb58) << 6;
  }
  else {
    iVar6 = *(int *)(iVar8 + 0xbb6c);
    iVar5 = *(int *)(iVar8 + 0xbb58) * (uint)*(ushort *)(iVar8 + 0xbb74);
  }
  if (iVar1 != 0) {
    iVar10 = *(int *)(iVar8 + 0xba94);
    uVar2 = _rtl_pci_tx_buffer_addr(iVar9,iVar8 + 0xbb50,iVar6 + iVar5);
    (*(code *)&dma_unmap_page_attrs)(iVar10 + 0x74,uVar2,*(undefined4 *)(iVar1 + 0x50),1,0);
    (*(code *)&kfree_skb)(iVar1);
  }
  piVar3 = (int *)(*(code *)&ieee80211_beacon_get_tim)(iVar9,*(undefined4 *)(iVar8 + 0x3f0),0,0);
  if (piVar3 != (int *)0x0) {
    uVar2 = *(undefined4 *)(iVar8 + 0xbb50);
    if (*(char *)(param_1 + 0xb970) == '\0') {
      uVar11 = 0;
    }
    else {
      uVar11 = *(undefined4 *)(iVar8 + 0xbb6c);
    }
    (**(code **)(*(int *)(*(int *)(param_1 + 0xb85c) + 0xc) + 0x68))
              (iVar9,piVar3[0x2f],uVar2,uVar11,piVar3 + 6,0,piVar3,4,auStack_64);
    piVar4 = *(int **)(iVar8 + 0xbb64);
    *piVar3 = iVar8 + 0xbb60;
    piVar3[1] = (int)piVar4;
    *(int **)(iVar8 + 0xbb64) = piVar3;
    *piVar4 = (int)piVar3;
    *(int *)(iVar8 + 0xbb68) = *(int *)(iVar8 + 0xbb68) + 1;
    if (*(char *)(param_1 + 0xb970) != '\0') {
      local_65 = 4;
      uVar2 = uVar11;
    }
    (**(code **)(*(int *)(*(int *)(param_1 + 0xb85c) + 0xc) + 0x94))(iVar9,uVar2,1,0,&local_65);
    if ((*(char *)(param_1 + 0xb970) != '\0') && (*(char *)(iVar8 + 0xba99) != '\0')) {
      uVar7 = hgw500_bcn_poll_count_5 + 1;
      sync(0);
      hgw500_bcn_poll_count_5 = uVar7;
      (**(code **)(*(int *)(*(int *)(param_1 + 0xb85c) + 0xc) + 0xa0))(iVar9,4);
      if (uVar7 < 9) {
        (*(code *)&printk)(&DAT_ram_00014e1c,uVar7);
      }
    }
  }
  return;
}

