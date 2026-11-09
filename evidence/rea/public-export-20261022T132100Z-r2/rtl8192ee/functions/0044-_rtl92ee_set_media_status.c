/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x131ec; aliases: _rtl92ee_set_media_status
 */

undefined4 _rtl92ee_set_media_status(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x40);
  uVar1 = rtl_read_byte(iVar5,0x102);
  switch(param_2) {
  case 0:
    uVar4 = 0;
    break;
  case 1:
  case 7:
    uVar4 = 1;
    break;
  case 2:
    uVar4 = 2;
    goto LAB_ram_00013260;
  case 3:
    uVar4 = 3;
    param_2 = 2;
    goto LAB_ram_000132f2;
  default:
    (*(code *)&printk)(&DAT_ram_0001ce98,param_2);
    return 1;
  }
  param_2 = 3;
LAB_ram_00013260:
  if (*(uint *)(iVar5 + 0x4d0) < 2) {
    uVar4 = 0;
    param_2 = 3;
  }
  else if ((uVar4 != 0) && (uVar4 != 2)) {
    uVar4 = 1;
LAB_ram_000132f2:
    _rtl92ee_resume_tx_beacon_isra_0(*(undefined4 *)(param_1 + 0x40));
    uVar3 = 0;
    uVar2 = 2;
    goto LAB_ram_00013292;
  }
  _rtl92ee_stop_tx_beacon_isra_0(*(undefined4 *)(param_1 + 0x40));
  uVar3 = 2;
  uVar2 = 0;
LAB_ram_00013292:
  _rtl92ee_set_bcn_ctrl_reg_isra_0(*(undefined4 *)(param_1 + 0x40),uVar2,uVar3);
  rtl_write_byte(iVar5,0x102,uVar1 & 0xfc | uVar4);
  (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0x90))(param_1,param_2);
  rtl_write_byte(iVar5,0x511);
  return 0;
}

