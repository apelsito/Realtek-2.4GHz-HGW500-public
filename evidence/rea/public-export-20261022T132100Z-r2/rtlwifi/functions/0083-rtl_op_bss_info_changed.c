/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13ee8; aliases: rtl_op_bss_info_changed
 */

/* WARNING: Control flow encountered bad instruction data */

void rtl_op_bss_info_changed(int param_1,uint *param_2,undefined4 *param_3,uint param_4)

{
  undefined1 uVar1;
  uint *puVar2;
  int iVar3;
  undefined2 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  char local_69;
  uint local_68 [14];
  
  iVar6 = *(int *)(param_1 + 0x40);
  (*(code *)&mutex_lock)(iVar6 + 0x24);
  if ((7 < *param_2) || ((0x8aU >> ((byte)*param_2 & 0x1f) & 1) == 0)) goto LAB_ram_00014042;
  if ((param_4 & 0x100) == 0) {
    if ((param_4 & 0x200) != 0) {
      if (*(char *)((int)param_3 + 0x19) != '\0') goto LAB_ram_00013f80;
      goto LAB_ram_00013f50;
    }
  }
  else {
LAB_ram_00013f80:
    if (*(char *)(iVar6 + 0x217) == '\0') {
      *(undefined1 *)(iVar6 + 0x217) = 1;
      (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x48))
                (param_1,*(undefined4 *)(*(int *)(iVar6 + 0xb8fc) + 0x130),0);
      pcVar5 = *(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0xc4);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1);
      }
      iVar3 = *(int *)(param_1 + 0x40);
      iVar7 = (*(code *)&ieee80211_beacon_get_tim)(param_1,param_2,0,0);
      (*(code *)&memset)(local_68,0,0x38);
      if (iVar7 != 0) {
        (*(code *)&memset)(local_68,0,0x38);
        (**(code **)(*(int *)(iVar3 + 0xb900) + 0xc))(param_1,0,iVar7,local_68);
      }
    }
    if (((param_4 & 0x200) != 0) && (*(char *)((int)param_3 + 0x19) == '\0')) {
LAB_ram_00013f50:
      if (*(char *)(iVar6 + 0x217) == '\x01') {
        *(undefined1 *)(iVar6 + 0x217) = 0;
        (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x48))
                  (param_1,0,*(undefined4 *)(*(int *)(iVar6 + 0xb8fc) + 0x130));
      }
    }
  }
  if ((param_4 & 0x40) != 0) {
    *(uint *)(iVar6 + 0x5a0) = (uint)*(ushort *)(param_3 + 7);
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x44))(param_1);
  }
LAB_ram_00014042:
  if ((param_4 & 1) != 0) {
    local_69 = *(char *)(param_3 + 4);
    iVar7 = iVar6 + 0x566;
    if (local_69 == '\0') {
      if (*(int *)(iVar6 + 0x4d0) == 2) {
        rtl_lps_leave(param_1,1);
      }
      if (*(int *)(iVar6 + 0xb344) != 0) {
        rtl_p2p_ps_cmd(param_1,0);
      }
      *(undefined4 *)(iVar6 + 0x4d0) = 0;
      iVar3 = (*(code *)&cfg80211_get_bss)(*(undefined4 *)(param_1 + 0x38),0,iVar7,0,0,0,1);
      if (iVar3 != 0) {
        (*(code *)&cfg80211_unlink_bss)(*(undefined4 *)(param_1 + 0x38),iVar3);
        (*(code *)&cfg80211_put_bss)(*(undefined4 *)(param_1 + 0x38),iVar3);
      }
      eth_zero_addr(iVar7);
      *(undefined4 *)(iVar6 + 0x56c) = 0;
      *(undefined2 *)(iVar6 + 0x588) = 0;
      if ((*(char *)(iVar6 + 0xa0b9) != '\0') &&
         (pcVar5 = *(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 200), pcVar5 != (code *)0x0
         )) {
        (*pcVar5)(param_1);
      }
    }
    else {
      local_68[0] = CONCAT31(local_68[0]._1_3_,10);
      local_69 = '\x01';
      rtl_cam_reset_sec_info(param_1);
      rtl_cam_reset_all_entry(param_1);
      *(undefined4 *)(iVar6 + 0x4d0) = 2;
      *(undefined1 *)(iVar6 + 0x4eb) = 0;
      *(undefined2 *)(iVar6 + 0x59a) = *(undefined2 *)(param_3 + 5);
      (*(code *)&memcpy)(iVar7,*param_3,6);
      pcVar5 = *(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0xc4);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1);
      }
      puVar2 = (uint *)(*(code *)&ieee80211_find_sta)(param_2,*param_3);
      if (puVar2 == (uint *)0x0) {
        halt_baddata();
      }
      if ((*(char *)(iVar6 + 0xa0b9) != '\0') && (*(char *)((int)puVar2 + 0x1e) != '\0')) {
        rtl_send_smps_action(param_1);
      }
      iVar7 = *(int *)(iVar6 + 0x6d0);
      if (iVar7 == 1) {
        uVar4 = 1;
      }
      else if (*puVar2 < 0x10) {
        uVar4 = 2;
      }
      else {
        uVar4 = 4;
      }
      *(undefined2 *)(iVar6 + 0x588) = uVar4;
      if (*(char *)((int)puVar2 + 0x1e) != '\0') {
        if (iVar7 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = 0x20;
        }
        *(undefined2 *)(iVar6 + 0x588) = uVar4;
      }
      if ((char)puVar2[0xd] != '\0') {
        if (iVar7 == 1) {
          uVar4 = 0x40;
        }
        else {
          uVar4 = 0x80;
        }
        *(undefined2 *)(iVar6 + 0x588) = uVar4;
      }
      if (*param_2 == 2) {
        (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x54))(param_1,puVar2,0,1);
      }
      (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x5e,local_68);
    }
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x2c))(param_1,*param_2);
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x3e,&local_69);
    *(bool *)(iVar6 + 0xb2fb) = local_69 == '\x01';
    iVar7 = (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x104))();
    if (iVar7 != 0) {
      (**(code **)(*(int *)(iVar6 + 0xb9ac) + 0x30))(iVar6,local_69);
    }
  }
  if ((param_4 & 2) != 0) {
    *(undefined1 *)(iVar6 + 0x58c) = *(undefined1 *)((int)param_3 + 0x16);
  }
  if ((param_4 & 4) != 0) {
    *(undefined1 *)(iVar6 + 0x58b) = *(undefined1 *)((int)param_3 + 0x17);
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x13,iVar6 + 0x58b);
  }
  if ((param_4 & 8) != 0) {
    if (*(char *)(param_3 + 6) == '\0') {
      uVar1 = 0x14;
    }
    else {
      uVar1 = 9;
    }
    *(undefined1 *)(iVar6 + 0x58a) = uVar1;
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x12,iVar6 + 0x58a);
  }
  if ((param_4 & 0x10) != 0) {
    iVar7 = (*(code *)&ieee80211_find_sta)(param_2,*param_3);
    if (iVar7 != 0) {
      if (*(byte *)(iVar6 + 0x5a7) < *(byte *)(iVar7 + 0x20)) {
        *(byte *)(iVar6 + 0x5a7) = *(byte *)(iVar7 + 0x20);
      }
      if (*(byte *)(iVar7 + 0x1f) < *(byte *)(iVar6 + 0x5a6)) {
        *(byte *)(iVar6 + 0x5a6) = *(byte *)(iVar7 + 0x1f);
      }
    }
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x1d,iVar6 + 0x5a5);
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x1e,iVar6 + 0x5a6);
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,0x1c,iVar6 + 0x5a7);
  }
  if ((param_4 & 0x80) != 0) {
    local_68[0] = 0;
    (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,3,*param_3);
    *(undefined4 *)(iVar6 + 0x56c) = 0;
    (*(code *)&memcpy)(iVar6 + 0x566,*param_3,6);
    puVar2 = (uint *)(*(code *)&ieee80211_find_sta)(param_2,*param_3);
    if (puVar2 != (uint *)0x0) {
      iVar7 = *(int *)(iVar6 + 0x6d0);
      if (iVar7 == 1) {
        uVar4 = 1;
      }
      else if (*puVar2 < 0x10) {
        uVar4 = 2;
      }
      else {
        uVar4 = 4;
      }
      *(undefined2 *)(iVar6 + 0x588) = uVar4;
      if (*(char *)((int)puVar2 + 0x1e) != '\0') {
        if (iVar7 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = 0x20;
        }
        *(undefined2 *)(iVar6 + 0x588) = uVar4;
      }
      if ((char)puVar2[0xd] != '\0') {
        if (iVar7 == 1) {
          uVar4 = 0x40;
        }
        else {
          uVar4 = 0x80;
        }
        *(undefined2 *)(iVar6 + 0x588) = uVar4;
      }
      if (*param_2 == 2) {
        uVar4 = *(undefined2 *)(iVar6 + 0x588);
        *(char *)((int)puVar2 + 0x1f1) = (char)uVar4;
        *(char *)((int)puVar2 + 0x1f2) = (char)((ushort)uVar4 >> 8);
      }
      if (*(char *)((int)puVar2 + 0x1e) != '\0') {
        *(undefined1 *)(iVar6 + 0x584) = 1;
      }
      if ((char)puVar2[0xd] != '\0') {
        *(undefined1 *)(iVar6 + 0x55e) = 1;
      }
      if ((param_4 & 0x20) != 0) {
        if (*(int *)(iVar6 + 0x6d0) == 1) {
          local_68[0] = puVar2[1] << 4;
        }
        else {
          local_68[0] = *puVar2;
        }
        *(uint *)(iVar6 + 0x580) = local_68[0];
        (**(code **)(*(int *)(*(int *)(iVar6 + 0xb8fc) + 0xc) + 0x50))(param_1,2,local_68);
      }
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

