/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13064; aliases: rtl_dm_diginit
 */

void rtl_dm_diginit(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *(undefined2 *)(iVar1 + 0xb934) = 0x401;
  *(undefined4 *)(iVar1 + 0xb92c) = param_2;
  *(undefined4 *)(iVar1 + 0xb928) = 0;
  *(undefined1 *)(iVar1 + 0xb93c) = 3;
  *(undefined1 *)(iVar1 + 0xb951) = 0;
  *(undefined1 *)(iVar1 + 0xb93b) = 0;
  *(undefined4 *)(iVar1 + 0xb908) = 0x23;
  *(undefined4 *)(iVar1 + 0xb90c) = 0x28;
  *(undefined4 *)(iVar1 + 0xb910) = 400;
  *(undefined4 *)(iVar1 + 0xb914) = 1000;
  *(undefined2 *)(iVar1 + 0xb93e) = 0xc0a;
  *(undefined2 *)(iVar1 + 0xb940) = 0x3efc;
  *(undefined1 *)(iVar1 + 0xb942) = 0x1e;
  *(undefined1 *)(iVar1 + 0xb94e) = 0x1e;
  *(undefined1 *)(iVar1 + 0xb94d) = 0;
  *(undefined4 *)(iVar1 + 0xb924) = 0;
  *(undefined1 *)(iVar1 + 0xa008) = 1;
  *(undefined4 *)(iVar1 + 0xb95c) = 0x322525;
  *(undefined1 *)(iVar1 + 0xb945) = 0xff;
  *(undefined1 *)(iVar1 + 0xb960) = 0;
  *(undefined2 *)(iVar1 + 0xb946) = 0x483;
  *(undefined2 *)(iVar1 + 0xb948) = 0;
  *(undefined1 *)(iVar1 + 0xb94a) = 0;
  return;
}

