/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10000; aliases: arch_local_irq_save
 */

void arch_local_irq_save(void)

{
  uint uVar1;
  
  uVar1 = Auxregs0028;
  if ((uVar1 & 6) != 0) {
    Auxregs0028 = uVar1 & 0xfffffff9;
  }
  return;
}

