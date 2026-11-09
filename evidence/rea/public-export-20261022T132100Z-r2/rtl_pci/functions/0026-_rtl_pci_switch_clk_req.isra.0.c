/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10d30; aliases: _rtl_pci_switch_clk_req.isra.0
 */

void _rtl_pci_switch_clk_req_isra_0(int param_1,undefined4 param_2)

{
  (*(code *)&pcie_capability_clear_and_set_word)
            (*(undefined4 *)(param_1 + 0xba94),0x10,0x100,param_2);
  if (*(short *)(param_1 + 0x690) == 2) {
    __udelay(100);
    return;
  }
  return;
}

