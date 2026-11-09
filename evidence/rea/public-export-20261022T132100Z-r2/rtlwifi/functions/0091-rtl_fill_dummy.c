/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1499c; aliases: rtl_fill_dummy
 */

void rtl_fill_dummy(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((uVar2 & 3) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 4 - (uVar2 & 3);
  }
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    *param_2 = uVar2;
    return;
  }
  do {
    uVar1 = uVar1 - 1 & 0xff;
    *(undefined1 *)(param_1 + uVar2) = 0;
    uVar2 = uVar2 + 1;
  } while (uVar1 != 0);
  *param_2 = uVar2;
  return;
}

