/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13314; aliases: rtl_cmd_send_packet
 */

undefined4 rtl_cmd_send_packet(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x40);
  uVar1 = Auxregs0028;
  if ((uVar1 & 6) != 0) {
    Auxregs0028 = uVar1 & 0xfffffff9;
  }
  piVar2 = *(int **)(iVar6 + 0xbb60);
  if (((int *)(iVar6 + 0xbb60) != piVar2) && (piVar2 != (int *)0x0)) {
    *(int *)(iVar6 + 0xbb68) = *(int *)(iVar6 + 0xbb68) + -1;
    piVar4 = (int *)piVar2[1];
    iVar5 = *piVar2;
    piVar2[1] = 0;
    *piVar2 = 0;
    *(int **)(iVar5 + 4) = piVar4;
    *piVar4 = iVar5;
    (*(code *)&__dev_kfree_skb_irq)(piVar2,1);
  }
  (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x70))
            (param_1,*(undefined4 *)(iVar6 + 0xbb50),1,1,param_2);
  puVar3 = *(undefined4 **)(iVar6 + 0xbb64);
  *param_2 = (int *)(iVar6 + 0xbb60);
  param_2[1] = puVar3;
  *(undefined4 **)(iVar6 + 0xbb64) = param_2;
  *puVar3 = param_2;
  *(int *)(iVar6 + 0xbb68) = *(int *)(iVar6 + 0xbb68) + 1;
  Auxregs0028 = uVar1;
  (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0xa0))(param_1,4);
  return 1;
}

