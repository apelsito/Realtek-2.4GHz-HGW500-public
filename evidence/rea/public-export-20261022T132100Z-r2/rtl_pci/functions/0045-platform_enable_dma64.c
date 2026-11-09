/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x137ac; aliases: platform_enable_dma64
 */

void platform_enable_dma64(undefined4 param_1,int param_2)

{
  byte local_d;
  
  local_d = 0;
  (*(code *)&pci_read_config_byte)(param_1,0x719,&local_d);
  if (param_2 == 0) {
    local_d = local_d & 0xdf;
  }
  else {
    local_d = local_d | 0x20;
  }
  (*(code *)&pci_write_config_byte)(param_1,0x719);
  return;
}

