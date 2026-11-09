/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1170c; aliases: rtl_is_tx_report_skb
 */

undefined4 rtl_is_tx_report_skb(int param_1,int param_2)

{
  ushort uVar1;
  short *psVar2;
  undefined4 uVar3;
  
  uVar1 = **(ushort **)(param_2 + 0xbc);
  psVar2 = (short *)rtl_skb_ether_type_ptr_isra_0(*(undefined4 *)(param_1 + 0x40),param_2,1);
  if (*psVar2 == -0x7178) {
    uVar3 = 1;
  }
  else {
    uVar3 = 1;
    if ((uVar1 & 0xfc) != 0x48) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

