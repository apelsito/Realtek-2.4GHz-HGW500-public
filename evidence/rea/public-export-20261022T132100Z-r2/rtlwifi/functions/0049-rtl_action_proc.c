/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12798; aliases: rtl_action_proc
 */

undefined4 rtl_action_proc(int param_1,int param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  undefined1 auStack_44 [24];
  uint uStack_2c;
  ushort local_28;
  undefined1 local_23;
  undefined1 uStack_20;
  undefined1 local_1e;
  
  puVar3 = *(ushort **)(param_2 + 0xbc);
  if ((((*puVar3 & 0xfc) == 0xd0) && ((char)puVar3[0xc] == '\x03')) &&
     (*(char *)((int)puVar3 + 0x19) == '\0')) {
    if (*(char *)(*(int *)(param_1 + 0x40) + 0x4ea) != '\0') {
      return 0;
    }
    if (((param_3 == '\0') &&
        (iVar1 = (*(code *)&ieee80211_find_sta)
                           (*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3f0),puVar3 + 8),
        iVar1 != 0)) &&
       ((iVar1 != -0x108 &&
        ((uVar2 = *(byte *)((int)puVar3 + 0x1b) >> 2 & 0xf, uVar2 < 9 &&
         (*(char *)(iVar1 + uVar2 * 0x18 + 0x125) == '\x01')))))) {
      (*(code *)&memset)(auStack_44,0,0x30);
      iVar1 = rtl_make_del_ba(param_1,puVar3 + 5,puVar3 + 8,uVar2);
      if (iVar1 != 0) {
        local_28 = local_28 & 0xe000 | (ushort)(*(undefined4 **)(param_1 + 0x14))[1] & 0x1fff;
        uStack_20 = (undefined1)**(undefined4 **)(param_1 + 0x14);
        uStack_2c = uStack_2c | 0x82;
        local_23 = 0;
        local_1e = 0x3c;
        (*(code *)&memcpy)(iVar1 + 0x18,auStack_44,0x30);
        (*(code *)&ieee80211_rx_irqsafe)(param_1,iVar1);
      }
    }
  }
  return 1;
}

