/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10d7c; aliases: rtl_skb_ether_type_ptr.isra.0
 */

int rtl_skb_ether_type_ptr_isra_0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)&ieee80211_get_hdrlen_from_skb)(param_2);
  switch(*(undefined4 *)(param_1 + 0xa3d0)) {
  case 1:
  case 5:
    iVar2 = 4;
    break;
  case 2:
  case 4:
    iVar2 = 8;
    break;
  default:
    iVar2 = 0;
  }
  return *(int *)(param_2 + 0xbc) + (iVar1 + 6 + param_3 * iVar2 & 0xffU);
}

