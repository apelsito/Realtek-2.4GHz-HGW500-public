/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13310; aliases: rtl92ee_get_hw_reg
 */

void rtl92ee_get_hw_reg(int param_1,byte param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_18;
  
  iVar5 = *(int *)(param_1 + 0x40);
  if (param_2 == 0x41) {
    *(undefined1 *)param_3 = *(undefined1 *)(iVar5 + 0xb2f9);
  }
  else if (param_2 < 0x42) {
    if (param_2 == 0x28) {
      uVar2 = *(undefined4 *)(iVar5 + 0xb314);
    }
    else {
      if (param_2 != 0x2c) {
        return;
      }
      uVar2 = *(undefined4 *)(iVar5 + 0xcc88);
    }
    *param_3 = uVar2;
  }
  else if (param_2 == 0x54) {
    uVar2 = rtl_read_dword(iVar5,0x564);
    uVar4 = rtl_read_dword(iVar5,0x560);
    param_3[1] = uVar2;
    *param_3 = uVar4;
  }
  else if (param_2 == 0x56) {
    local_18 = 0;
    (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x4c))(param_1,0x28,&local_18);
    if ((local_18 == 2) || (uVar3 = rtl_read_dword(iVar5,0x608), (uVar3 & 0x70000) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    *(undefined1 *)param_3 = uVar1;
  }
  return;
}

