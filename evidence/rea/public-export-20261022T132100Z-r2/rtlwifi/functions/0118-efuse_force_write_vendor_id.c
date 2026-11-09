/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16190; aliases: efuse_force_write_vendor_id
 */

/* WARNING: Removing unreachable block (ram,0x000156e4) */
/* WARNING: Removing unreachable block (ram,0x00015862) */
/* WARNING: Removing unreachable block (ram,0x00015866) */
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

void efuse_force_write_vendor_id(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uStack_10 = 0xffffffff;
  local_14 = 0x10ecffff;
  efuse_power_switch(param_1,1,1);
  efuse_pg_packet_write(param_1,1,0xd,&local_14);
  iVar2 = *(int *)(param_1 + 0x40);
  if ((*(ushort *)(iVar2 + 0x690) & 0xfffd) != 4) {
    rtl_write_byte(iVar2,*(undefined4 *)(*(int *)(iVar2 + 0xb8fc) + 0x78),0);
  }
  uVar1 = rtl_read_byte(iVar2,*(int *)(*(int *)(iVar2 + 0xb8fc) + 0x48) + 3);
  rtl_write_byte(iVar2,*(int *)(*(int *)(iVar2 + 0xb8fc) + 0x48) + 3,uVar1 & 0x7f);
  if (*(short *)(iVar2 + 0x690) != 2) {
    return;
  }
  rtl_write_byte(iVar2,*(undefined4 *)(*(int *)(iVar2 + 0xb8fc) + 0x50),2);
  return;
}

