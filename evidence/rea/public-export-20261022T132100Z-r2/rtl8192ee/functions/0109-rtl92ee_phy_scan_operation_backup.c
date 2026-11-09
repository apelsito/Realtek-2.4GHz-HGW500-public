/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x179cc; aliases: rtl92ee_phy_scan_operation_backup
 */

void rtl92ee_phy_scan_operation_backup(int param_1,char param_2)

{
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  if (*(char *)(*(int *)(param_1 + 0x40) + 0x698) != '\0') {
    if (param_2 != '\0') {
      if (param_2 != '\x02') {
        (*(code *)&printk)(&DAT_ram_0001d2cc);
        return;
      }
      local_8[0] = 2;
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0x50))
              (param_1,0x48,local_8);
  }
  return;
}

