/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x18d44; aliases: dma_map_single_attrs.constprop.0
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 dma_map_single_attrs_constprop_0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&is_vmalloc_addr)(param_2);
  if (iVar1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (__warned_23 == '\0') {
    __warned_23 = '\x01';
    uVar2 = (*(code *)&dev_driver_string)(param_1);
    iVar1 = param_1[0xb];
    if (iVar1 == 0) {
      iVar1 = *param_1;
    }
    (*(code *)&warn_slowpath_fmt)
              ("include/linux/dma-mapping.h",0x113,9,"%s %s: rejecting DMA map of vmalloc memory\n",
               uVar2,iVar1);
  }
  return 0xffffffff;
}

