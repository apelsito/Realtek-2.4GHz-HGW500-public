/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1028c; aliases: rtl92ee_dm_init
 */

void rtl92ee_dm_init(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  uVar1 = rtl_get_bbreg(param_1,0xc50,0x7f);
  *(undefined1 *)(iVar4 + 0xa032) = 1;
  (*(code *)&rtl_dm_diginit)(param_1,uVar1);
  rtl92ee_dm_init_rate_adaptive_mask(param_1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar4 + 0x6ec) = 0;
  *(undefined1 *)(iVar4 + 0xb3cf) = 0;
  *(undefined1 *)(iVar4 + 0xb3cd) = 0;
  *(undefined1 *)(iVar4 + 0xb3ce) = 0;
  *(undefined1 *)(iVar4 + 0xb3d0) = 0;
  *(undefined1 *)(iVar4 + 0xb3d1) = 0;
  *(undefined1 *)(iVar4 + 0xb3d2) = 0;
  rtl92ee_dm_init_edca_turbo(param_1);
  iVar4 = *(int *)(param_1 + 0x40);
  *(undefined1 *)(iVar4 + 0xa0b5) = 0x14;
  *(undefined1 *)(iVar4 + 0xa03b) = 0x1e;
  *(undefined1 *)(iVar4 + 0xa010) = 1;
  *(undefined2 *)(iVar4 + 0xa03c) = 0x1414;
  uVar2 = 0;
  do {
    iVar3 = iVar4 + 0xa000 + uVar2;
    *(undefined1 *)(iVar3 + 0xae) = 0x1e;
    *(undefined1 *)(iVar3 + 0x37) = 0x1e;
    uVar2 = uVar2 + 1 & 0xff;
    *(undefined1 *)(iVar3 + 0x3e) = 0;
    *(undefined1 *)(iVar3 + 0x42) = 0;
    *(undefined1 *)(iVar3 + 0x46) = 0;
  } while (uVar2 != 4);
  iVar4 = *(int *)(param_1 + 0x40);
  *(uint *)(iVar4 + 0xa098) = (uint)*(byte *)(iVar4 + 0xb29a);
  iVar3 = rtl_get_bbreg(param_1,0xd2c,0x800);
  *(bool *)(iVar4 + 0xa088) = iVar3 != 0;
  *(undefined1 *)(iVar4 + 0xa09c) = 10;
  return;
}

