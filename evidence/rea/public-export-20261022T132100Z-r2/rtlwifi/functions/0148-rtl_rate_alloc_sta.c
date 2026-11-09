/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x175f8; aliases: rtl_rate_alloc_sta
 */

void rtl_rate_alloc_sta(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = (*(code *)&kmem_cache_alloc)
                    (*(undefined4 *)(&DAT_ram_0f00026c + ((param_3 & 0x10) >> 4) * 0x3c));
  if (iVar1 != 0) {
    *(int *)(param_1 + 0xb8c8) = iVar1;
  }
  return;
}

