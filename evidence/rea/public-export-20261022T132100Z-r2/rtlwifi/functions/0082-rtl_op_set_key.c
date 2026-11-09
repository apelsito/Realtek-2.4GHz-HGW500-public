/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x13aec; aliases: rtl_op_set_key
 */

undefined4 rtl_op_set_key(int param_1,int param_2,uint *param_3,int param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  byte bVar8;
  bool bVar9;
  undefined4 uStack_48;
  undefined2 local_44;
  undefined4 uStack_40;
  undefined2 local_3c;
  
  iVar5 = *(int *)(param_1 + 0x40);
  local_44 = 0;
  uStack_48 = 0;
  local_3c = 0xffff;
  uStack_40 = 0xffffffff;
  *(undefined1 *)(iVar5 + 0xb9b5) = 0;
  if ((*(char *)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0x10) + 8) != '\0') ||
     (*(char *)(iVar5 + 0xa3cc) != '\0')) {
    iVar2 = (*(code *)&of_machine_is_compatible)("mitrastar,hgw-500bna-qcv2");
    if ((iVar2 != 0) && ((*(short *)(iVar5 + 0x690) == 0xc && (*param_3 == 3)))) {
      if (__print_once_6 == '\0') {
        __print_once_6 = '\x01';
        (*(code *)&printk)(&DAT_ram_00019d68);
      }
      return 1;
    }
    return 0xffffffe4;
  }
  if (((*param_3 == 1) || (*param_3 == 7)) && ((*(ushort *)(param_5 + 0x10) & 8) == 0)) {
    return 0xffffffe4;
  }
  *(undefined1 *)(iVar5 + 0xa3cd) = 1;
  rtl_ips_nic_on(param_1);
  (*(code *)&mutex_lock)();
  switch(*(int *)(param_5 + 8)) {
  case 0xfac01:
    uVar7 = 1;
    break;
  case 0xfac02:
    uVar7 = 2;
    goto LAB_ram_00013c54;
  default:
    puVar3 = &DAT_ram_00019da0;
    param_2 = *(int *)(param_5 + 8);
    goto LAB_ram_00013c8e;
  case 0xfac04:
    uVar7 = 4;
LAB_ram_00013c54:
    if (*param_3 == 1) break;
    goto LAB_ram_00013c5c;
  case 0xfac05:
    uVar7 = 5;
    break;
  case 0xfac06:
    goto switchD_ram_00013c44_caseD_fac06;
  }
  *(undefined1 *)(iVar5 + 0xa3ce) = 1;
LAB_ram_00013c5c:
  bVar8 = *(byte *)(param_5 + 0xf);
  iVar2 = (int)(char)bVar8;
  if (bVar8 < 4) {
    uVar1 = *(ushort *)(param_5 + 0x10);
    if ((*param_3 & 0xfffffffb) == 3) {
      if ((uVar1 & 8) != 0) {
        bVar9 = false;
        goto LAB_ram_00013cce;
      }
      if ((uVar7 & 3) == 1) {
        bVar9 = true;
        goto LAB_ram_00013cce;
      }
LAB_ram_00013cc4:
      if (param_2 == 0) {
LAB_ram_00013db6:
        *(uint *)(iVar5 + 0xa3d4) = uVar7;
        (*(code *)&memcpy)(iVar5 + iVar2 * 0x3d + 0xa49c,param_5 + 0x13,
                           *(undefined1 *)(param_5 + 0x12));
        *(undefined1 *)(iVar5 + iVar2 + 0xa5cd) = *(undefined1 *)(param_5 + 0x12);
        puVar4 = &uStack_40;
        goto LAB_ram_00013dee;
      }
    }
    else {
      if (((uVar1 & 8) == 0) && (*param_3 != 1)) {
        if (*(int *)(iVar5 + 0xa3d0) != 0) goto LAB_ram_00013cc4;
LAB_ram_00013d08:
        bVar9 = (uVar7 & 3) == 1;
      }
      else {
        if (*(int *)(iVar5 + 0xa3d0) == 0) goto LAB_ram_00013d08;
        bVar9 = false;
      }
      *(uint *)(iVar5 + 0xa3d0) = uVar7;
LAB_ram_00013cce:
      (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0xa4))(param_1);
      if (param_2 == 0) {
        if (bVar9 == false) {
          if ((uVar1 & 8) == 0) goto LAB_ram_00013db6;
          if (param_4 == 0) {
            if (__warned_5 == '\0') {
              __warned_5 = '\x01';
              (*(code *)&warn_slowpath_fmt)
                        ("drivers/net/wireless/realtek/rtlwifi/core.c",0x6c7,9,
                         "rtlwifi: pairwise key without mac_addr\n");
            }
switchD_ram_00013c44_caseD_fac06:
            uVar6 = 0xffffffa1;
            goto LAB_ram_00013c6a;
          }
          *(uint *)(iVar5 + 0xa3d0) = uVar7;
          (*(code *)&memcpy)(iVar5 + 0xa49c,param_5 + 0x13,*(undefined1 *)(param_5 + 0x12));
          *(undefined1 *)(iVar5 + 0xa5cd) = *(undefined1 *)(param_5 + 0x12);
          *(int *)(iVar5 + 0xa5d4) = iVar5 + 0xa49c;
          puVar4 = (undefined4 *)(param_4 + 0x14);
LAB_ram_00013dee:
          bVar9 = false;
          (*(code *)&memcpy)(&uStack_48,puVar4,6);
        }
        else {
          *(uint *)(iVar5 + 0xa3d0) = uVar7;
          *(uint *)(iVar5 + 0xa3d4) = uVar7;
          (*(code *)&memcpy)(iVar5 + iVar2 * 0x3d + 0xa49c,param_5 + 0x13,
                             *(undefined1 *)(param_5 + 0x12));
          *(undefined1 *)(iVar5 + iVar2 + 0xa5cd) = *(undefined1 *)(param_5 + 0x12);
          eth_zero_addr(&uStack_48);
        }
        (**(code **)(*(int *)(*(int *)(iVar5 + 0xb8fc) + 0xc) + 0xa8))
                  (param_1,iVar2,&uStack_48,(uVar1 & 8) >> 3 ^ 1,uVar7,bVar9,0);
        uVar1 = *(ushort *)(param_5 + 0x10);
        *(ushort *)(param_5 + 0x10) = uVar1 | 2;
        *(byte *)(param_5 + 0xe) = bVar8;
        if (uVar7 == 2) {
          uVar1 = uVar1 | 6;
        }
        else {
          if (uVar7 != 4) goto LAB_ram_00013c68;
          uVar1 = uVar1 | 0x12;
        }
        *(ushort *)(param_5 + 0x10) = uVar1;
        goto LAB_ram_00013c68;
      }
    }
    if (param_2 == 1) {
      if (((*param_3 & 0xfffffffb) == 3) && (param_4 != 0)) {
        rtl_cam_del_entry(param_1,param_4 + 0x14);
      }
      (*(code *)&memset)(iVar5 + iVar2 * 0x3d + 0xa49c,0,*(undefined1 *)(param_5 + 0x12));
      *(undefined1 *)(iVar5 + iVar2 + 0xa5cd) = 0;
      eth_zero_addr(&uStack_48);
      rtl_wait_tx_report_acked(param_1,500);
      rtl_cam_delete_one_entry(param_1,&uStack_48,iVar2);
    }
    else {
      puVar3 = &DAT_ram_00019e10;
LAB_ram_00013c8e:
      (*(code *)&printk)(puVar3,param_2);
    }
  }
LAB_ram_00013c68:
  uVar6 = 0;
LAB_ram_00013c6a:
  (*(code *)&mutex_unlock)(iVar5 + 0x24);
  *(undefined1 *)(iVar5 + 0xa3cd) = 0;
  return uVar6;
}

