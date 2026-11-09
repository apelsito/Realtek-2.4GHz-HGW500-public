/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x126a4; aliases: rtl_find_ie
 */

char * rtl_find_ie(int param_1,int param_2,char param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)(param_1 + 0x24);
  while ((pcVar2 = pcVar1, pcVar2 < (char *)(param_1 + param_2) &&
         (pcVar2 + (byte)pcVar2[1] + 2 <= (char *)(param_1 + param_2)))) {
    pcVar1 = pcVar2 + (byte)pcVar2[1] + 2;
    if (*pcVar2 == param_3) {
      return pcVar2;
    }
  }
  return (char *)0x0;
}

