/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11a30; aliases: _rtl_pci_topaz_tx_complete
 */

void _rtl_pci_topaz_tx_complete(int param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  
  iVar8 = *(int *)(param_1 + 0x40);
  iVar7 = 0;
  do {
    iVar5 = iVar8 + 0xb800;
    if ((*(uint *)(*(int *)(iVar8 + 0xb8fc) + (uint)(byte)(&map_ids_11)[iVar7] * 4 + 0x1c) &
        *param_2) != 0) {
      uVar6 = (uint)(byte)(&queues_10)[iVar7];
      iVar1 = uVar6 * 0x2c;
      iVar10 = *(int *)(iVar5 + iVar1 + 0x2b8);
      uVar9 = *(undefined4 *)(iVar5 + iVar1 + 0x2a8);
      if (uVar6 < 4) {
        *(int *)(iVar8 + 0xb7c0) = *(int *)(iVar8 + 0xb7c0) + 1;
      }
      _rtl_pci_tx_isr(param_1,uVar6);
      iVar11 = *(int *)(iVar5 + iVar1 + 0x2b8);
      uVar4 = trace_count_9 + 1;
      trace_count_9 = uVar4;
      if ((iVar10 == 0) || (iVar11 != iVar10)) {
        if (uVar4 < 0x11) goto LAB_ram_00011aec;
      }
      else {
        uVar2 = *(uint *)(no_progress_count_8 + uVar6 * 4) + 1;
        *(uint *)(no_progress_count_8 + uVar6 * 4) = uVar2;
        if (((uVar4 < 0x11) || (uVar2 < 5)) || (iVar3 = is_power_of_2(), iVar3 != 0)) {
LAB_ram_00011aec:
          (*(code *)&printk)(&DAT_ram_00015108,uVar4,param_3,uVar6,iVar10,iVar11,uVar9,
                             *(undefined4 *)(iVar1 + iVar5 + 0x2a8),iVar11 != iVar10);
        }
      }
    }
    iVar7 = iVar7 + 1;
    if (iVar7 == 6) {
      return;
    }
  } while( true );
}

