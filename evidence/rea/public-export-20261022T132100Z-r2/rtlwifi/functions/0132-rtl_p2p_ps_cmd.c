/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16a5c; aliases: rtl_p2p_ps_cmd
 */

void rtl_p2p_ps_cmd(int param_1,byte param_2)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  code *pcVar4;
  int iVar5;
  byte local_1c [4];
  
  pbVar3 = local_1c;
  uVar1 = (uint)param_2;
  iVar5 = *(int *)(param_1 + 0x40);
  local_1c[0] = param_2;
  if (uVar1 == 1) {
    if (*(int *)(iVar5 + 0xb344) == 0) {
      return;
    }
    *(undefined4 *)(iVar5 + 0xb348) = 1;
    if ((*(char *)(iVar5 + 0xb34d) != '\0') && (*(char *)(iVar5 + 0xb36d) != '\0')) {
      *(undefined1 *)(iVar5 + 0xb36d) = 0;
      (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3d,iVar5 + 0xb36c);
    }
    uVar2 = 0x40;
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x50);
  }
  else if (uVar1 < 2) {
    *(undefined4 *)(iVar5 + 0xb348) = 0;
    (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x50))(param_1,0x40,local_1c);
    *(undefined4 *)(iVar5 + 0xb34c) = 0;
    *(undefined4 *)(iVar5 + 0xb344) = 0;
    if (*(char *)(iVar5 + 0xb2f9) == '\0') {
      return;
    }
    if (*(char *)(iVar5 + 0xb36d) != '\0') {
      return;
    }
    *(undefined1 *)(iVar5 + 0xb36d) = 2;
    pbVar3 = (byte *)(iVar5 + 0xb36c);
    uVar2 = 0x3d;
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x50);
  }
  else {
    if (2 < uVar1 - 2) {
      return;
    }
    if (*(int *)(iVar5 + 0xb344) == 0) {
      return;
    }
    *(uint *)(iVar5 + 0xb348) = uVar1;
    pcVar4 = *(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x50);
    uVar2 = 0x40;
    pbVar3 = local_1c;
  }
  (*pcVar4)(param_1,uVar2,pbVar3);
  return;
}

