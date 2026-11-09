/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15d98; aliases: rtl_efuse_shadow_map_update
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_efuse_shadow_map_update(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar1 + 0xa9e3) == '\0') {
    efuse_read_all_map(param_1,iVar1 + 0xa5e0);
  }
  else {
    (*(code *)&memset)(iVar1 + 0xa5e0,0xff,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x68));
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

