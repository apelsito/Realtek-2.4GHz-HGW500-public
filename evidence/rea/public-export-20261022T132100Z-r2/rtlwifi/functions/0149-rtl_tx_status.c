/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x17634; aliases: rtl_tx_status
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_tx_status(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  
  if (param_4 == 0) {
    return;
  }
  puVar4 = *(ushort **)(param_5 + 0xbc);
  uVar1 = *puVar4;
  if (((uVar1 & 0xc) == 8) &&
     (iVar3 = rtl_is_special_data(*(undefined4 *)(param_1 + 0x3ec),param_5,1,1), iVar3 == 0)) {
    if ((*puVar4 & 0x100) == 0) {
      uVar2 = puVar4[2];
      puVar4 = puVar4 + 2;
    }
    else {
      uVar2 = puVar4[8];
      puVar4 = puVar4 + 8;
    }
    if ((((((uVar2 & 1) == 0) && ((*puVar4 & puVar4[1] & puVar4[2]) != 0xffff)) && (param_3 != 0))
        && ((*(char *)(param_3 + 0x1e) != '\0' && (*(short *)(param_5 + 0xa8) != -0x7178)))) &&
       ((uVar1 & 0x8c) == 0x88)) {
      puVar4 = *(ushort **)(param_5 + 0xbc);
      if ((~*puVar4 & 0x300) == 0) {
        puVar4 = puVar4 + 0xf;
      }
      else {
        puVar4 = puVar4 + 0xc;
      }
      if (((*(char *)(param_1 + 0x4ea) == '\0') &&
          ((*(int *)(param_1 + 0x3f4) != 2 || (2 < *(byte *)(param_1 + 0x4eb))))) &&
         (iVar3 = param_3 + 0x200 + ((byte)*puVar4 & 0xf) * 0x18, *(char *)(iVar3 + -0xdc) == '\0'))
      {
        *(undefined1 *)(iVar3 + -0xdc) = 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
  return;
}

