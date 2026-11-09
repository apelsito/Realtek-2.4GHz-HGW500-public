/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x108fc; aliases: rtl_pci_irq_line_release.isra.0
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_pci_irq_line_release_isra_0(int param_1)

{
  if (((*(char *)(param_1 + 0xba99) != '\0') && (*(char *)(param_1 + 0xcc8c) != '\0')) &&
     (*(char *)(param_1 + 0xba9a) != '\0')) {
    (*(code *)&enable_irq)(*(undefined4 *)(*(int *)(param_1 + 0xba94) + 0x170));
    *(undefined1 *)(param_1 + 0xba9a) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

