/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x169c4; aliases: rtl_swlps_wq_callback
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_swlps_wq_callback(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint **)(param_1 + -0x124))[0x10];
  if (*(char *)(uVar2 + 0xb31a) == '\0') {
    return;
  }
  uVar3 = **(uint **)(param_1 + -0x124);
  rtl_swlps_rf_sleep();
  uVar3 = uVar3 & 2;
  if (*(char *)(uVar2 + 0xb319) == '\0') {
    if (uVar3 == 0) goto code_r0x00016a28;
  }
  else if (uVar3 == 0) {
    uVar1 = (*(code *)&jiffies_to_msecs)(_jiffies - *(int *)(uVar2 + 0xb33c));
    *(undefined4 *)(uVar2 + 0xb324) = uVar1;
    goto code_r0x00016a28;
  }
  *(int *)(uVar2 + 0xb340) = _jiffies;
code_r0x00016a28:
  *(int *)(uVar2 + 0xb33c) = _jiffies;
  *(char *)(uVar2 + 0xb319) = (char)(uVar3 >> 1);
  return;
}

