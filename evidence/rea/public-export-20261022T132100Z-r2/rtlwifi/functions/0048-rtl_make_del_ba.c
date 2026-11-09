/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x126cc; aliases: rtl_make_del_ba
 */

int rtl_make_del_ba(int param_1,undefined4 param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  iVar1 = (*(code *)&__netdev_alloc_skb)(0,*(int *)(param_1 + 0x4c) + 0x22,0xa20);
  if (iVar1 != 0) {
    iVar3 = *(int *)(param_1 + 0x4c);
    *(int *)(iVar1 + 0xbc) = *(int *)(iVar1 + 0xbc) + iVar3;
    *(int *)(iVar1 + 0xb0) = *(int *)(iVar1 + 0xb0) + iVar3;
    puVar2 = (undefined2 *)(*(code *)&skb_put)(iVar1,0x22);
    (*(code *)&memset)(puVar2,0,0x22);
    (*(code *)&memcpy)(puVar2 + 5,param_2,6);
    (*(code *)&memcpy)(puVar2 + 2,iVar4 + 0xa9f8,6);
    (*(code *)&memcpy)(puVar2 + 8,param_3,6);
    *puVar2 = 0xd0;
    puVar2[0xc] = 0x203;
    puVar2[0xd] = param_4 << 0xc | 0x800;
    puVar2[0xe] = 0x27;
  }
  return iVar1;
}

