/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x128a4; aliases: rtl_cam_del_entry
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_cam_del_entry(int param_1,short *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x40);
  if ((param_2 != (short *)0x0) && ((*param_2 != 0 || param_2[1] != 0) || param_2[2] != 0)) {
    uVar3 = 4;
    do {
      bVar1 = (byte)uVar3;
      if ((*(uint *)(iVar5 + 0xa3d8) & 1 << (bVar1 & 0x1f)) != 0) {
        iVar4 = uVar3 * 6 + 0xa3dc;
        iVar2 = (*(code *)&memcmp)(iVar4 + iVar5,param_2,6);
        if (iVar2 == 0) {
          (*(code *)&memset)(iVar4 + iVar5,0,6);
          *(uint *)(iVar5 + 0xa3d8) =
               (0xfffffffeU >> (-bVar1 & 0x1f) | -2 << (bVar1 + 0x20 & 0x1f)) &
               *(uint *)(iVar5 + 0xa3d8);
        }
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 != 0x20);
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

