/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1607c; aliases: efuse_shadow_update
 */

int efuse_shadow_update(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_24;
  undefined4 uStack_20;
  
  iVar6 = *(int *)(param_1 + 0x40);
  iVar2 = efuse_shadow_update_chk();
  if (iVar2 != 0) {
    uVar7 = 0;
    efuse_power_switch(param_1,1,1);
    do {
      uVar8 = 0xf;
      iVar3 = (uVar7 & 0x1fff) * 8;
      uVar4 = 0;
      do {
        iVar5 = iVar6 + 0xa600 + iVar3 + uVar4;
        if (*(char *)(iVar5 + -0x20) != *(char *)(iVar5 + 0x1e0)) {
          cVar1 = (char)(uVar4 >> 1);
          *(char *)(iVar5 + -0x20) = *(char *)(iVar5 + 0x1e0);
          uVar8 = uVar8 & (0xfffffffeU >> (-cVar1 & 0x1fU) | -2 << (cVar1 + 0x20U & 0x1f));
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 != 8);
      if (uVar8 != 0xf) {
        local_24 = 0;
        uStack_20 = 0;
        (*(code *)&memcpy)(&local_24,iVar6 + (iVar3 - 0x5820U & 0xffff));
        iVar3 = efuse_pg_packet_write(param_1,uVar7,uVar8,&local_24);
        if (iVar3 == 0) break;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 != 0x10);
    efuse_power_switch(param_1,1,0);
  }
  efuse_read_all_map(param_1,iVar6 + 0xa5e0);
  (*(code *)&memcpy)(iVar6 + 0xa7e0,iVar6 + 0xa5e0,*(undefined4 *)(*(int *)(iVar6 + 0xb8fc) + 0x68))
  ;
  return iVar2;
}

