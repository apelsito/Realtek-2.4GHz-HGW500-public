/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x108c8; aliases: tasklet_schedule
 */

/* WARNING: Control flow encountered bad instruction data */

void tasklet_schedule(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = arch_local_irq_save();
  uVar2 = *(uint *)(param_1 + 4);
  *(uint *)(param_1 + 4) = uVar2 | 1;
  Auxregs0028 = uVar1;
  if ((uVar2 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

