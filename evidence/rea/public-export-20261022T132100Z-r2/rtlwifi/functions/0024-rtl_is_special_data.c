/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10de0; aliases: rtl_is_special_data
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 rtl_is_special_data(int param_1,int param_2,char param_3,undefined1 param_4)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = *(int *)(param_1 + 0x40);
  if ((**(ushort **)(param_2 + 0xbc) & 0xc) != 8) goto LAB_ram_00010eca;
  psVar4 = (short *)rtl_skb_ether_type_ptr_isra_0(iVar6,param_2,param_4);
  uVar3 = _jiffies;
  sVar2 = *psVar4;
  if (sVar2 == 8) {
    if (*(char *)((int)psVar4 + 0xb) != '\x11') {
LAB_ram_00010eca:
      *(undefined1 *)(iVar6 + 0xb3c8) = 0;
      return 0;
    }
    uVar5 = *(byte *)(psVar4 + 1) & 0xf;
    cVar1 = *(char *)((int)psVar4 + uVar5 * 4 + 3);
    if (cVar1 == 'D') {
      bVar7 = *(char *)((int)psVar4 + uVar5 * 4 + 5) == 'C';
    }
    else {
      if (cVar1 != 'C') goto LAB_ram_00010eca;
      bVar7 = *(char *)((int)psVar4 + uVar5 * 4 + 5) == 'D';
    }
    if (!bVar7) goto LAB_ram_00010eca;
  }
  else if (sVar2 != 0x608) {
    if (sVar2 != -0x7178) goto LAB_ram_00010eca;
    *(undefined1 *)(iVar6 + 0xb9b5) = 1;
    *(undefined4 *)(iVar6 + 0xb9b8) = uVar3;
    if (param_3 == '\0') {
      return 1;
    }
    *(undefined1 *)(iVar6 + 0xb3c8) = 1;
    rtl_lps_leave(param_1,0);
    *(undefined4 *)(iVar6 + 0xb330) = _jiffies;
    goto LAB_ram_00010e5e;
  }
  if (param_3 == '\0') {
    return 1;
  }
LAB_ram_00010e5e:
  setup_special_tx(iVar6,iVar6 + 0xb2e8);
  return 1;
}

