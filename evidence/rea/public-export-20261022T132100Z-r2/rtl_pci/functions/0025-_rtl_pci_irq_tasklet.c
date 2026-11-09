/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10b80; aliases: _rtl_pci_irq_tasklet
 */

void _rtl_pci_irq_tasklet(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 auStack_60 [9];
  byte local_57;
  int aiStack_54 [11];
  
  iVar12 = *(int *)(param_1 + -0x88);
  iVar10 = *(int *)(iVar12 + 0x40);
  if (*(char *)(iVar10 + 0x6e1) != '\0') {
    iVar11 = 7;
    do {
      iVar1 = iVar11 * 0xc;
      iVar3 = (*(code *)&rtl_tid_to_ac)(iVar11);
      bVar2 = *(byte *)((int)&ac_to_hwq + iVar3);
      iVar3 = iVar10 + iVar1 + 0x4f0;
      while ((*(char *)(iVar10 + 0x4ea) == '\0' && (*(int *)(iVar10 + 0xb314) == 0))) {
        (*(code *)&memset)(auStack_60,0,0x38);
        (*(code *)&memset)(auStack_60,0,0x38);
        if ((iVar3 == *(int *)(iVar10 + iVar1 + 0x4f0)) ||
           (iVar4 = iVar10 + 0xb800 + (uint)bVar2 * 0x2c,
           (uint)(*(int *)(iVar4 + 0x2ac) - *(int *)(iVar4 + 0x2b8)) <=
           (uint)*(byte *)(iVar10 + 0x6e2))) break;
        iVar4 = (*(code *)&skb_dequeue)(iVar3);
        if ((*(uint *)(iVar4 + 0x18) & 0x40) != 0) {
          iVar7 = *(int *)(iVar12 + 0x40);
          if (*(int *)(iVar4 + 0x34) == 0) {
            uVar8 = 4;
          }
          else {
            uVar8 = *(byte *)(*(int *)(iVar4 + 0x34) + 0xc) + 4 & 0xff;
          }
          local_57 = 0;
          *(int *)(((uint)auStack_60 & 0xffffe000) + 4) =
               *(int *)(((uint)auStack_60 & 0xffffe000) + 4) + 0x200;
          piVar6 = *(int **)(iVar7 + iVar1 + 0x4f0);
          piVar9 = (int *)(iVar7 + iVar1 + 0x4f0);
          while ((piVar6 != piVar9 && ((piVar6[6] & 0x40U) != 0))) {
            uVar5 = local_57 + 1;
            aiStack_54[local_57] = piVar6[0x14] + uVar8;
            local_57 = (byte)uVar5;
            piVar6 = (int *)*piVar6;
            if ((piVar6 == piVar9) || ((uint)*(byte *)(iVar7 + 0x6e2) <= (uVar5 & 0xff))) break;
          }
          (*(code *)&__local_bh_enable_ip)(0x10cd4,0x200);
        }
        (**(code **)(*(int *)(iVar10 + 0xb900) + 0xc))(iVar12,0,iVar4);
      }
      iVar11 = iVar11 + -1;
    } while (iVar11 != -1);
  }
  return;
}

