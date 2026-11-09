/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14be0; aliases: rtl92ee_led_control
 */

void rtl92ee_led_control(int param_1,uint param_2)

{
  if (0x20000000 < *(uint *)(*(int *)(param_1 + 0x40) + 0xb300)) {
    if (param_2 - 1 < 6) {
      return;
    }
    if (param_2 == 8) {
      return;
    }
  }
  if (3 < param_2) {
    if (param_2 != 7) {
      return;
    }
    rtl92ee_sw_led_off(param_1,*(int *)(param_1 + 0x40) + 0xb2a8);
    return;
  }
  if (param_2 == 0) {
    return;
  }
  rtl92ee_sw_led_on();
  return;
}

