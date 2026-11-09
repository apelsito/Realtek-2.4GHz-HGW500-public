/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x100f8; aliases: rtl_tx_mgmt_proc
 */

undefined4 rtl_tx_mgmt_proc(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  ushort uVar3;
  
  iVar2 = *(int *)(param_1 + 0x40);
  uVar3 = **(ushort **)(param_2 + 0xbc) & 0xfc;
  if ((*(char *)(iVar2 + 0xa0b9) != '\0') && (*(uint *)(iVar2 + 0x4d0) < 2)) {
    if ((uVar3 != 0xb0) && (uVar3 != 0x40)) {
      return 1;
    }
    pcVar1 = *(code **)(*(int *)(*(int *)(iVar2 + 0xb8fc) + 0xc) + 200);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
    }
  }
  if (uVar3 == 0xb0) {
    *(undefined4 *)(iVar2 + 0x4d0) = 1;
    *(undefined1 *)(iVar2 + 0x942) = 1;
  }
  return 1;
}

