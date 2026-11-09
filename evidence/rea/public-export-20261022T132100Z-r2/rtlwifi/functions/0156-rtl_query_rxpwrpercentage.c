/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17a0c; aliases: rtl_query_rxpwrpercentage
 */

uint rtl_query_rxpwrpercentage(char param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (0x76 < (iVar1 + 99U & 0xff)) {
    return 0;
  }
  if (iVar1 < 0) {
    return iVar1 + 100U & 0xff;
  }
  return 100;
}

