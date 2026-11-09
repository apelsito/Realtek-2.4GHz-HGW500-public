/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x15e08; aliases: rtl_get_hwinfo
 */

undefined4
rtl_get_hwinfo(int param_1,undefined4 param_2,undefined4 param_3,ushort *param_4,uint *param_5)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (*(short *)(iVar3 + 0xa9e6) == 0) {
    (*(code *)&printk)(&DAT_ram_0001a170);
  }
  else if (*(short *)(iVar3 + 0xa9e6) == 2) {
    rtl_efuse_shadow_map_update();
    (*(code *)&memcpy)(param_4,iVar3 + 0xa5e0,param_3);
    uVar1 = *param_4;
    uVar2 = *param_5;
    *(bool *)(iVar3 + 0xa9e3) = uVar1 != uVar2;
    if (uVar1 == uVar2) {
      *(undefined2 *)(iVar3 + 0xa9e8) = *(undefined2 *)((int)param_4 + param_5[1]);
      *(undefined2 *)(iVar3 + 0xa9ea) = *(undefined2 *)((int)param_4 + param_5[2]);
      *(undefined2 *)(iVar3 + 0xa9ec) = *(undefined2 *)((int)param_4 + param_5[3]);
      *(undefined2 *)(iVar3 + 0xa9ee) = *(undefined2 *)((int)param_4 + param_5[4]);
      (*(code *)&memcpy)(iVar3 + 0xa9f8,(int)param_4 + param_5[5],6);
      *(ushort *)(iVar3 + 0xa9f2) = (ushort)*(byte *)((int)param_4 + param_5[6]);
      *(undefined1 *)(iVar3 + 0xa9f4) = *(undefined1 *)((int)param_4 + param_5[7]);
      *(undefined1 *)(iVar3 + 0xaa01) = 1;
      *(undefined1 *)(iVar3 + 0xa9f0) = *(undefined1 *)((int)param_4 + param_5[8]);
      *(char *)(iVar3 + 0xb2a1) = (char)param_5[9];
      return 0;
    }
  }
  else {
    (*(code *)&_dev_warn)(*(int *)(iVar3 + 0xba94) + 0x74,"no efuse data\n");
  }
  return 1;
}

