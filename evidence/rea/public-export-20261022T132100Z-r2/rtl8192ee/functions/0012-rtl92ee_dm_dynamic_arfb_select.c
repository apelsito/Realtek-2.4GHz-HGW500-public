/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x103a0; aliases: rtl92ee_dm_dynamic_arfb_select
 */

void rtl92ee_dm_dynamic_arfb_select(int param_1,uint param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  param_2 = param_2 & 0xff;
  iVar2 = *(int *)(param_1 + 0x40);
  if (param_2 - 0x14 < 5) {
    if (param_3 != '\0') {
      switch(param_2) {
      case 0x15:
        rtl_write_dword(iVar2,0x430);
        uVar1 = 0x8080707;
        break;
      case 0x16:
        rtl_write_dword(iVar2,0x430);
        uVar1 = 0x8080706;
        break;
      case 0x17:
        rtl_write_dword(iVar2,0x430);
        uVar1 = 0x7070605;
        break;
      case 0x18:
        rtl_write_dword(iVar2,0x430,0);
        uVar1 = 0x7060501;
        break;
      default:
        rtl_write_dword(iVar2,0x430,0);
        uVar1 = 0x9090808;
      }
      goto LAB_ram_000103f4;
    }
    switch(param_2) {
    case 0x15:
      rtl_write_dword(iVar2,0x430,0x7070000);
      uVar1 = 0xa090808;
      break;
    case 0x16:
      rtl_write_dword(iVar2,0x430,0x7060000);
      uVar1 = 0xa090908;
      break;
    case 0x17:
      rtl_write_dword(iVar2,0x430,0x6050000);
      uVar1 = 0x9080807;
      break;
    case 0x18:
      uVar1 = 0x5010000;
LAB_ram_00010478:
      rtl_write_dword(iVar2,0x430,uVar1);
      uVar1 = 0x9080706;
      break;
    default:
      rtl_write_dword(iVar2,0x430,0x8080000);
      uVar1 = 0xb0a0909;
    }
  }
  else {
    if (param_3 != '\0') {
      if (param_2 == 0x1b) {
        rtl_write_dword(iVar2,0x430);
        uVar1 = 0x5040302;
      }
      else if (param_2 == 0x1a) {
        rtl_write_dword(iVar2,0x430);
        uVar1 = 0x6050302;
      }
      else if (param_2 == 0x19) {
        rtl_write_dword();
        uVar1 = 0x7060502;
      }
      else {
        rtl_write_dword(iVar2,0x430,0);
        uVar1 = 0x6050402;
      }
      goto LAB_ram_000103f4;
    }
    if (param_2 == 0x1b) {
      rtl_write_dword(iVar2,0x430,0x3020000);
      uVar1 = 0x7060504;
      goto LAB_ram_000103f4;
    }
    if (param_2 == 0x1a) {
      uVar1 = 0x3020000;
    }
    else {
      if (param_2 == 0x19) {
        uVar1 = 0x5020000;
        goto LAB_ram_00010478;
      }
      uVar1 = 0x4020000;
    }
    rtl_write_dword(iVar2,0x430,uVar1);
    uVar1 = 0x8070605;
  }
LAB_ram_000103f4:
  (**(code **)(iVar2 + 0x748))(iVar2,0x434,uVar1);
  if (*(char *)(*(int *)(iVar2 + 0xb8fc) + 1) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001014c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar2 + 0x758))(iVar2,0x434);
    return;
  }
  return;
}

