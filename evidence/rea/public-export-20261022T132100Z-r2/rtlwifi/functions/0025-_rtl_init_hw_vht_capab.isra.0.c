/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10edc; aliases: _rtl_init_hw_vht_capab.isra.0
 */

void _rtl_init_hw_vht_capab_isra_0(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(*(int *)(param_1 + 0xb8fc) + 0x18) & 2) == 0) {
    return;
  }
  if (*(ushort *)(param_1 + 0x690) - 0xe < 2) {
    *param_2 = 1;
    *(undefined4 *)(param_2 + 4) = 0x33c019a2;
    uVar1 = 0x363fffa;
  }
  else {
    if (*(ushort *)(param_1 + 0x690) != 0xd) {
      return;
    }
    *param_2 = 1;
    *(undefined4 *)(param_2 + 4) = 0x33c019a2;
    uVar1 = 0x1b2fffe;
  }
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(undefined4 *)(param_2 + 0xc) = uVar1;
  return;
}

