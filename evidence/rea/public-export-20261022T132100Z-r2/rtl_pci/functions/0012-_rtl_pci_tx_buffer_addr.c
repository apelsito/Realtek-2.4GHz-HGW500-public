/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10138; aliases: _rtl_pci_tx_buffer_addr
 */

undefined4 _rtl_pci_tx_buffer_addr(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(char *)(*(int *)(param_1 + 0x40) + 0xba10) != '\0') && (*(short *)(param_2 + 0x24) == 0x20)
     ) {
    return *(undefined4 *)(param_3 + 0xc);
  }
  uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0x98))
                    (param_1,param_3,1,3);
  return uVar1;
}

