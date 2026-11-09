/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15d3c; aliases: efuse_read_all_map
 */

/* WARNING: Removing unreachable block (ram,0x0001581a) */
/* WARNING: Removing unreachable block (ram,0x000156e4) */
/* WARNING: Removing unreachable block (ram,0x00015862) */
/* WARNING: Removing unreachable block (ram,0x000156f0) */
/* WARNING: Removing unreachable block (ram,0x000157d6) */
/* WARNING: Removing unreachable block (ram,0x000157ea) */
/* WARNING: Removing unreachable block (ram,0x00015700) */
/* WARNING: Removing unreachable block (ram,0x0001570e) */
/* WARNING: Removing unreachable block (ram,0x00015726) */
/* WARNING: Removing unreachable block (ram,0x00015736) */
/* WARNING: Removing unreachable block (ram,0x00015750) */
/* WARNING: Removing unreachable block (ram,0x00015754) */
/* WARNING: Removing unreachable block (ram,0x00015766) */
/* WARNING: Removing unreachable block (ram,0x00015866) */
/* WARNING: Removing unreachable block (ram,0x0001576a) */
/* WARNING: Removing unreachable block (ram,0x00015782) */
/* WARNING: Removing unreachable block (ram,0x0001578a) */
/* WARNING: Removing unreachable block (ram,0x0001578e) */
/* WARNING: Removing unreachable block (ram,0x00015790) */
/* WARNING: Removing unreachable block (ram,0x00015792) */
/* WARNING: Removing unreachable block (ram,0x00015796) */
/* WARNING: Removing unreachable block (ram,0x0001579a) */
/* WARNING: Removing unreachable block (ram,0x000157b0) */
/* WARNING: Removing unreachable block (ram,0x000157b8) */

void efuse_read_all_map(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  efuse_power_switch(param_1,0,1);
  read_efuse(param_1,0,*(undefined2 *)(*(int *)(iVar1 + 0xb8fc) + 0x68),param_2);
  iVar1 = *(int *)(param_1 + 0x40);
  if (((*(ushort *)(iVar1 + 0x690) & 0xfffd) != 4) &&
     (rtl_write_byte(iVar1,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x78),0),
     *(short *)(iVar1 + 0x690) == 2)) {
    rtl_write_byte(iVar1,*(undefined4 *)(*(int *)(iVar1 + 0xb8fc) + 0x50),2);
    return;
  }
  return;
}

