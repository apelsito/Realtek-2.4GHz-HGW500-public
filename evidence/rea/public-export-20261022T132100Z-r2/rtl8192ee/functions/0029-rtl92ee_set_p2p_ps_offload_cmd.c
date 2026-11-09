/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12204; aliases: rtl92ee_set_p2p_ps_offload_cmd
 */

void rtl92ee_set_p2p_ps_offload_cmd(int param_1,undefined1 param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char local_24 [4];
  
  iVar5 = *(int *)(param_1 + 0x40);
  switch(param_2) {
  case 0:
    (*(code *)&memset)(iVar5 + 0x6c6,0,1);
    break;
  case 1:
    iVar7 = iVar5 + 0xb400;
    if (*(char *)(iVar5 + 0xb34d) != '\0') {
      *(byte *)(iVar5 + 0x6c6) = *(byte *)(iVar5 + 0x6c6) | 4;
      local_24[0] = *(char *)(iVar5 + 0xb34d);
      rtl92ee_fill_h2c_cmd(param_1,0x46,1,local_24);
    }
    for (uVar6 = 0; uVar6 < *(byte *)(iVar5 + 0xb34f); uVar6 = uVar6 + 1 & 0xff) {
      rtl_write_byte(iVar5,0x5cf,(uVar6 & 0xf) << 4);
      iVar8 = iVar5 + uVar6 * 4;
      if (uVar6 == 0) {
        bVar2 = *(byte *)(iVar5 + 0x6c6) | 8;
      }
      else {
        bVar2 = *(byte *)(iVar5 + 0x6c6) | 0x10;
      }
      *(byte *)(iVar5 + 0x6c6) = bVar2;
      rtl_write_dword(iVar5,0x5e0,*(undefined4 *)(iVar8 + 0xb354));
      rtl_write_dword(iVar5,0x5e4,*(undefined4 *)(iVar8 + 0xb35c));
      iVar3 = rtl_read_dword(iVar5,0x560);
      uVar4 = *(uint *)(iVar8 + 0xb364);
      if (*(char *)(iVar7 + uVar6 + -0xb0) != '\x01') {
        while (uVar4 <= iVar3 + 0xc800U) {
          uVar4 = uVar4 + *(int *)(iVar8 + 0xb35c);
          cVar1 = *(char *)(iVar7 + uVar6 + -0xb0);
          if (cVar1 != -1) {
            *(char *)(iVar7 + uVar6 + -0xb0) = cVar1 + -1;
          }
        }
      }
      rtl_write_dword(iVar5,0x5e8);
      rtl_write_dword(iVar5,0x5ec,*(undefined1 *)(iVar7 + uVar6 + -0xb0));
    }
    if ((*(char *)(iVar5 + 0xb34e) == '\x01') || (*(byte *)(iVar5 + 0xb34f) != 0)) {
      rtl_write_byte(iVar5,0x553,0x10);
      bVar2 = *(byte *)(iVar5 + 0x6c6);
      *(byte *)(iVar5 + 0x6c6) = bVar2 | 1;
      if (*(char *)(iVar5 + 0x4dd) == '\x03') {
        bVar2 = bVar2 & 0xdd | 3;
      }
      else {
        bVar2 = bVar2 & 0xfd | 1;
      }
      *(byte *)(iVar5 + 0x6c6) = bVar2;
      *(byte *)(iVar5 + 0x6c6) = *(byte *)(iVar5 + 0x6c6) & 0xbf;
    }
    break;
  case 2:
    *(byte *)(iVar5 + 0x6c6) = *(byte *)(iVar5 + 0x6c6) | 0x40;
    break;
  case 3:
    *(byte *)(iVar5 + 0x6c6) = *(byte *)(iVar5 + 0x6c6) & 0xbf;
    *(undefined4 *)(iVar5 + 0xb348) = 1;
  }
  rtl92ee_fill_h2c_cmd(param_1,0x14,1,iVar5 + 0x6c6);
  return;
}

