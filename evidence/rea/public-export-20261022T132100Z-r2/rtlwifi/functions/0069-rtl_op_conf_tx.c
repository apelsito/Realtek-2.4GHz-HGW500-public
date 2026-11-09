/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13170; aliases: rtl_op_conf_tx
 */

undefined4 rtl_op_conf_tx(int param_1,undefined4 param_2,uint param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_3 & 0xffff) < 4) {
    iVar3 = *(int *)(param_1 + 0x40);
    iVar4 = (int)*(char *)((int)&CSWTCH_84 + (param_3 & 0xffff));
    iVar1 = iVar3 + iVar4 * 8;
    *(undefined1 *)(iVar1 + 0x5f2) = *(undefined1 *)(param_4 + 3);
    iVar2 = iVar3 + 0x400 + iVar4 * 8;
    *(undefined2 *)(iVar2 + 0x1ee) = param_4[1];
    *(undefined2 *)(iVar2 + 0x1f0) = param_4[2];
    *(undefined2 *)(iVar1 + 0x5f4) = *param_4;
    (*(code *)&memcpy)(iVar3 + iVar4 * 0xe + 0x5a8,param_4,0xe);
    (**(code **)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0xc) + 0x3c))(param_1,iVar4);
    return 0;
  }
  return 0xffffffea;
}

