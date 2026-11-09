/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12ca0; aliases: rtl_cam_get_free_entry
 */

uint rtl_cam_get_free_entry(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  uVar3 = *(uint *)(iVar4 + 0xa3d8);
  if (param_2 == 0) {
    (*(code *)&printk)(&DAT_ram_00019af4);
  }
  else {
    uVar2 = 4;
    do {
      iVar1 = (*(code *)&memcmp)(uVar2 * 6 + 0xa3dc + iVar4,param_2,6);
      if (iVar1 == 0) {
        return uVar2;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 != 0x20);
    uVar3 = uVar3 >> 4;
    uVar2 = 4;
    do {
      if ((uVar3 & 1) == 0) {
        (*(code *)&printk)(&DAT_ram_00019b30,*(undefined4 *)(iVar4 + 0xa3d8),uVar2);
        *(uint *)(iVar4 + 0xa3d8) = *(uint *)(iVar4 + 0xa3d8) | 1 << ((byte)uVar2 & 0x1f);
        (*(code *)&memcpy)(uVar2 * 6 + 0xa3dc + iVar4,param_2,6);
        return uVar2;
      }
      uVar2 = uVar2 + 1 & 0xff;
      uVar3 = uVar3 >> 1;
    } while (uVar2 != 0x20);
  }
  return 0x20;
}

