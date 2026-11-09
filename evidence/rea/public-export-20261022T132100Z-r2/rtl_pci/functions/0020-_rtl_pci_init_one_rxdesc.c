/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x106ec; aliases: _rtl_pci_init_one_rxdesc
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_rtl_pci_init_one_rxdesc(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 local_39;
  int iStack_38;
  
  iVar7 = *(int *)(param_1 + 0x40);
  iStack_38 = 0;
  local_39 = 1;
  iVar2 = param_2;
  if ((param_2 != 0) ||
     (iVar2 = (*(code *)&__netdev_alloc_skb)(0,*(undefined2 *)(iVar7 + 0xcc84),0xa20), iVar2 != 0))
  {
    uVar9 = *(uint *)(iVar2 + 0xb0);
    iVar8 = *(int *)(iVar7 + 0xba94);
    uVar1 = *(undefined2 *)(iVar7 + 0xcc84);
    iVar3 = (*(code *)&is_vmalloc_addr)(uVar9);
    if (iVar3 == 0) {
      iStack_38 = (*(code *)&dma_map_page_attrs)
                            (iVar8 + 0x74,_mem_map + ((uVar9 >> 0xd) - 0x4249d) * 0x24,
                             uVar9 & 0x1fff,uVar1,2,0);
    }
    else {
      if (__warned_26 == '\0') {
        __warned_26 = '\x01';
        uVar4 = (*(code *)&dev_driver_string)(iVar8 + 0x74);
        iVar3 = *(int *)(iVar8 + 0xa0);
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar8 + 0x74);
        }
        (*(code *)&warn_slowpath_fmt)
                  ("include/linux/dma-mapping.h",0x113,9,
                   "%s %s: rejecting DMA map of vmalloc memory\n",uVar4,iVar3);
      }
      iStack_38 = -1;
    }
    *(int *)(iVar2 + 0x18) = iStack_38;
    if (iStack_38 != -1) {
      puVar5 = (undefined1 *)(iVar2 + 0x18);
      uVar4 = 7;
      *(int *)(iVar7 + (param_4 * 0x205 + param_5 + 0x74) * 4 + 0xba94) = iVar2;
      pcVar6 = *(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x94);
      if (*(char *)(iVar7 + 0xba10) == '\0') {
        (*pcVar6)(param_1,param_3,0,4,&iStack_38);
        (**(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x94))
                  (param_1,param_3,0,5,iVar7 + 0xcc84);
        puVar5 = &local_39;
        uVar4 = 1;
        pcVar6 = *(code **)(*(int *)(*(int *)(iVar7 + 0xb8fc) + 0xc) + 0x94);
      }
      (*pcVar6)(param_1,param_3,0,uVar4,puVar5);
      return 1;
    }
    if (param_2 == 0) {
      (*(code *)&kfree_skb)(iVar2);
    }
  }
  return 0;
}

