/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1ab5c; aliases: rtl92ee_tx_fill_cmddesc
 */

void rtl92ee_tx_fill_cmddesc(int param_1,uint *param_2,char param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = dma_map_single_attrs_constprop_0
                    (*(int *)(*(int *)(param_1 + 0x40) + 0xba94) + 0x74,
                     *(undefined4 *)(param_5 + 0xbc),*(undefined4 *)(param_5 + 0x50));
  if (uVar1 != 0xffffffff) {
    (*(code *)&memset)(param_2,0,0x28);
    if (param_3 != '\0') {
      *param_2 = *param_2 & 0xff00ffff | 0x280000;
    }
    uVar3 = param_2[1];
    uVar2 = *param_2;
    param_2[4] = param_2[4] & 0xffffffc0;
    param_2[9] = param_2[9] & 0xff000fff;
    param_2[1] = uVar3 & 0xffffe0ff | 0x1000;
    *param_2 = uVar2 & 0xefffffff | 0xc000000;
    set_tx_desc_tx_buffer_size(param_2,*(undefined2 *)(param_5 + 0x50));
    param_2[10] = uVar1;
    param_2[1] = uVar3 & 0xffe0e080 | 0x71000;
    *param_2 = uVar2 & 0xefffffff | 0x8c000000;
    set_tx_desc_pkt_size(param_2,*(undefined2 *)(param_5 + 0x50));
    *param_2 = *param_2 & 0xff00ffff | 0xc280000;
    param_2[3] = param_2[3] | 0x100;
  }
  return;
}

