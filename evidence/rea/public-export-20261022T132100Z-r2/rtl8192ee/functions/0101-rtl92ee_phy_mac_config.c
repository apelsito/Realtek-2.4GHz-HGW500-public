/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16e08; aliases: rtl92ee_phy_mac_config
 */

undefined4 rtl92ee_phy_mac_config(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x40);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 2;
    rtl_write_byte(uVar3,(&RTL8192EE_MAC_ARRAY)[iVar1],(&DAT_ram_00020680)[iVar1 * 4]);
    iVar1 = iVar2;
  } while (iVar2 != 0xca);
  return 1;
}

