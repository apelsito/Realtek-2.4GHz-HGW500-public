/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12b8c; aliases: rtl_cam_add_one_entry
 */

undefined4
rtl_cam_add_one_entry
          (int param_1,byte *param_2,uint param_3,int param_4,int param_5,int param_6,int param_7)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if (param_3 != 0x20) {
    param_3 = param_3 | param_5 << 2;
    if (param_6 == 1) {
      param_3 = param_5 << 2 & 0x3fffc;
    }
    iVar5 = *(int *)(param_1 + 0x40);
    iVar6 = 7;
    while( true ) {
      uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0xb8fc) + 0x80);
      uVar7 = iVar6 + param_4 * 8 | 0x80010000;
      if (iVar6 == 0) break;
      if (iVar6 == 1) {
        uVar1 = (uint)*(uint3 *)(param_2 + 2);
        uVar3 = (uint)param_2[5] << 0x18;
      }
      else {
        iVar4 = param_7 + iVar6 * 4;
        uVar1 = (uint)*(byte *)(iVar4 + -5) << 0x18 | (uint)*(byte *)(iVar4 + -6) << 0x10 |
                (uint)*(byte *)(iVar4 + -8);
        uVar3 = (uint)*(byte *)(iVar4 + -7) << 8;
      }
      rtl_write_dword(iVar5,uVar2,uVar3 | uVar1);
      iVar6 = iVar6 + -1;
      rtl_write_dword(iVar5,*(undefined4 *)(*(int *)(iVar5 + 0xb8fc) + 0x7c),uVar7);
    }
    rtl_write_dword(iVar5,uVar2,
                    param_3 & 0xffff | 0x8000 | (uint)*param_2 << 0x10 | (uint)param_2[1] << 0x18);
    rtl_write_dword(iVar5,*(undefined4 *)(*(int *)(iVar5 + 0xb8fc) + 0x7c),uVar7);
    return 1;
  }
  return 0;
}

