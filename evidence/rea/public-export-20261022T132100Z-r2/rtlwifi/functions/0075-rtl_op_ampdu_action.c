/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13470; aliases: rtl_op_ampdu_action
 */

undefined4 rtl_op_ampdu_action(int param_1,int *param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = param_3[1];
  uVar1 = *(undefined2 *)(param_3 + 2);
  switch(*param_3) {
  case 0:
    uVar3 = rtl_rx_agg_start(param_1,uVar3,uVar1);
    return uVar3;
  case 1:
    uVar3 = rtl_rx_agg_stop(param_1,uVar3,uVar1);
    return uVar3;
  case 2:
    break;
  case 3:
  case 4:
  case 5:
    uVar3 = rtl_tx_agg_stop(param_1,param_2,uVar3,uVar1);
    return uVar3;
  case 6:
    rtl_tx_agg_oper(param_1,uVar3,uVar1);
    return 0;
  default:
    (*(code *)&printk)(&DAT_ram_00019cac);
    return 0xffffffa1;
  }
  if (hgw500_tx_ampdu_disable != '\0') {
    iVar4 = *(int *)(param_1 + 0x40);
    iVar2 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
    if (((iVar2 != 0) && (*(short *)(iVar4 + 0x690) == 0xc)) && (*param_2 == 3)) {
      iVar2 = (*(code *)&___ratelimit)(_rs_2,"rtl_op_ampdu_action");
      if (iVar2 == 0) {
        return 0xffffffa1;
      }
      (*(code *)&printk)(&DAT_ram_00019c64,uVar1);
      return 0xffffffa1;
    }
  }
  uVar3 = rtl_tx_agg_start(param_1,param_2,uVar3,uVar1,(int)param_3 + 10);
  return uVar3;
}

