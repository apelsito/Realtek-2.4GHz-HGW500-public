/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x1875c; aliases: rtl92ee_phy_rf6052_set_bandwidth
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl92ee_phy_rf6052_set_bandwidth(int param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  if (param_2 == '\0') {
    uVar1 = *(uint *)(iVar2 + 0x9f78) | 0xc00;
  }
  else {
    if (param_2 != '\x01') {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = *(uint *)(iVar2 + 0x9f78) & 0xfffff3ff | 0x400;
  }
  *(uint *)(iVar2 + 0x9f78) = uVar1;
  rtl_set_rfreg_constprop_0(param_1,0);
                    /* WARNING: Could not recover jumptable at 0x00018738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xb8fc) + 0xc) + 0xc0))
            (param_1,1,0x18,0xfffff,*(undefined4 *)(iVar2 + 0x9f78));
  return;
}

