/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13204; aliases: rtl_fw_do_work
 */

void rtl_fw_do_work(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *local_1c;
  
  iVar2 = *(int *)(param_2 + 0x40);
  local_1c = param_1;
  if (param_1 == (uint *)0x0) {
    iVar1 = *(int *)(*(int *)(iVar2 + 0xb8fc) + 8);
    if (iVar1 != 0) {
      iVar1 = (*(code *)&request_firmware)(&local_1c,iVar1,*(undefined4 *)(iVar2 + 0x724));
      (*(code *)&printk)(&DAT_ram_00019c14,*(undefined4 *)(*(int *)(iVar2 + 0xb8fc) + 8));
      if (iVar1 == 0) goto LAB_ram_00013294;
    }
    (*(code *)&printk)(&DAT_ram_00019be4);
    *(undefined4 *)(iVar2 + 0xb8f8) = 0;
  }
  else {
LAB_ram_00013294:
    if (*(uint *)(iVar2 + 0xb8f8) < *local_1c) {
      (*(code *)&printk)(&DAT_ram_00019c40);
    }
    else if (param_3 == 0) {
      (*(code *)&memcpy)(*(undefined4 *)(iVar2 + 0x6b0));
      *(uint *)(iVar2 + 0x6ac) = *local_1c;
    }
    else {
      (*(code *)&memcpy)(*(undefined4 *)(iVar2 + 0x700),local_1c[1]);
      *(uint *)(iVar2 + 0x6fc) = *local_1c;
    }
    (*(code *)&release_firmware)(local_1c);
  }
  (*(code *)&complete)(iVar2 + 4);
  return;
}

