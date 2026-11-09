/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x145a4; aliases: rtl92ee_set_key
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl92ee_set_key(int param_1,uint param_2,undefined6 *param_3,char param_4,int param_5,
                    char param_6,char param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined6 *puVar5;
  undefined1 uVar6;
  
  iVar4 = *(int *)(param_1 + 0x40);
  if (param_7 != '\0') {
    uVar3 = 0;
    do {
      (*(code *)&rtl_cam_mark_invalid)(param_1,uVar3);
      (*(code *)&rtl_cam_empty_entry)(param_1,uVar3);
      (*(code *)&memset)(iVar4 + uVar3 * 0x3d + 0xa49c,0,0x3d);
      iVar2 = iVar4 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      *(undefined1 *)(iVar2 + 0xa5cd) = 0;
    } while (uVar3 != 5);
    return;
  }
  uVar3 = param_5 - 1U & 0xff;
  if (uVar3 < 5) {
    uVar6 = *(undefined1 *)((int)&CSWTCH_147 + uVar3);
  }
  else {
    uVar6 = 2;
  }
  uVar3 = param_2;
  if ((param_6 == '\0') && (*(char *)(iVar4 + 0xa3ce) == '\0')) {
    if (param_4 == '\0') {
      if ((*(uint *)(iVar4 + 0x3f4) & 0xfffffffb) == 3) {
        uVar3 = (*(code *)&rtl_cam_get_free_entry)(param_1,param_3);
        if (0x1f < uVar3) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      else {
        uVar3 = 4;
      }
      bVar1 = true;
      param_2 = 0;
      puVar5 = param_3;
    }
    else {
      puVar5 = &cam_const_broad_0;
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
    puVar5 = (undefined6 *)(cam_const_addr_1 + param_2 * 6);
  }
  if (*(char *)(iVar4 + param_2 + 0xa5cd) == '\0') {
    if ((*(uint *)(iVar4 + 0x3f4) & 0xfffffffb) == 3) {
      (*(code *)&rtl_cam_del_entry)(param_1,param_3);
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (bVar1) {
    iVar2 = param_2 * 0x3d + 0xa49c + iVar4;
  }
  else {
    iVar2 = uVar3 * 0x3d + 0xa49c + iVar4;
    if (*(int *)(iVar4 + 0x3f4) == 1) {
      (*(code *)&rtl_cam_add_one_entry)(param_1,iVar4 + 0xa9f8,0,4,uVar6,0,iVar2);
    }
  }
  (*(code *)&rtl_cam_add_one_entry)(param_1,puVar5,param_2,uVar3,uVar6,0,iVar2);
  return;
}

