/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13cac; aliases: rtl92ee_enable_hw_security_config
 */

void rtl92ee_enable_hw_security_config(int param_1)

{
  byte bVar1;
  int iVar2;
  byte local_11;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if ((*(char *)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0x10) + 8) == '\0') &&
     (*(char *)(iVar2 + 0xa3cc) == '\0')) {
    local_11 = 0xc;
    if (*(char *)(iVar2 + 0xa3ce) != '\0') {
      local_11 = 0xf;
    }
    local_11 = local_11 | 0xc0;
    bVar1 = rtl_read_byte(iVar2,0x101);
    rtl_write_byte(iVar2,0x101,bVar1 | 2);
    (**(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 0x50))(param_1,0x1b,&local_11);
  }
  return;
}

