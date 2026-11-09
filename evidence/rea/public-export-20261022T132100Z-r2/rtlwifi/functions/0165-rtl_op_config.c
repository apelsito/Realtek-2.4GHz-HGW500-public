/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x181f8; aliases: rtl_op_config
 */

undefined4 rtl_op_config(uint *param_1,uint param_2)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = param_1[0x10];
  (*(code *)&printk)(&DAT_ram_0001a090,param_2,(byte)*param_1 >> 2 & 1,
                     *(undefined1 *)(uVar4 + 0x4ea));
  if (*(char *)(uVar4 + 0x4ec) != '\0') {
    return 1;
  }
  (*(code *)&mutex_lock)(uVar4 + 0x24);
  if ((param_2 & 0x100) == 0) {
    if (*(int *)(uVar4 + 0xb314) == 2) goto LAB_ram_0001832e;
  }
  else if ((*param_1 & 4) == 0) {
LAB_ram_0001832e:
    rtl_ips_nic_on(param_1);
  }
  else {
    rtl_ips_nic_off(param_1);
  }
  if ((((param_2 & 0x10) != 0) && (*(char *)(uVar4 + 0xb2f4) != '\0')) &&
     (*(char *)(uVar4 + 0xb2f6) == '\0')) {
    (*(code *)&cancel_delayed_work)(uVar4 + 0x16c);
    (*(code *)&cancel_delayed_work)(uVar4 + 0x198);
    if ((*param_1 & 2) == 0) {
      rtl_swlps_rf_awake(param_1);
      *(undefined1 *)(uVar4 + 0xb318) = 0;
    }
    else {
      *(undefined1 *)(uVar4 + 0xb318) = 1;
      if (*(char *)(uVar4 + 0xb31b) == '\0') {
        (*(code *)&queue_delayed_work_on)(1,*(undefined4 *)(uVar4 + 0xe4),uVar4 + 0x16c,1);
      }
    }
  }
  if ((param_2 & 0x80) == 0) {
LAB_ram_0001837a:
    if ((param_2 & 0x40) == 0) goto LAB_ram_000182f4;
  }
  else if (param_2 != 0xffffffff) {
    bVar1 = *(byte *)((int)param_1 + 0xf);
    *(byte *)(uVar4 + 0x599) = bVar1;
    *(byte *)(uVar4 + 0x598) = bVar1;
    (**(code **)(*(int *)(*(int *)(uVar4 + 0xb8fc) + 0xc) + 0x50))
              (param_1,0x35,(byte *)((int)param_1 + 0xf));
    goto LAB_ram_0001837a;
  }
  if (*(char *)(uVar4 + 0xb99c) != '\0') goto LAB_ram_000182f4;
  uVar10 = param_1[6];
  uVar7 = *(ushort *)(param_1[5] + 10);
  (*(code *)&printk)(&DAT_ram_0001a0d8,uVar7,*(undefined4 *)(param_1[5] + 4),uVar10,
                     *(undefined1 *)(uVar4 + 0x4ea));
  uVar6 = uVar7 & 0xff;
  if (uVar10 < 3) {
    uVar9 = param_1[6];
    if (uVar9 != 1) {
      if (uVar9 != 2) {
        if (uVar9 != 0) {
          (*(code *)&warn_slowpath_fmt)("include/net/cfg80211.h",0x30c,9,0);
        }
        goto LAB_ram_000183b4;
      }
      if (*(uint *)(param_1[5] + 4) < param_1[7]) {
        uVar9 = 3;
      }
    }
  }
  else {
LAB_ram_000183b4:
    uVar9 = 0;
  }
  if (*(char *)(uVar4 + 0x4ea) != '\0') {
    *(int *)(uVar4 + 0x4d4) = *(int *)(uVar4 + 0x4d4) + 1;
  }
  if (((*(char *)(uVar4 + 0xa0b9) != '\0') && (*(uint *)(uVar4 + 0x4d0) < 2)) &&
     ((*(char *)(uVar4 + 0x4ea) == '\0' &&
      (pcVar2 = *(code **)(*(int *)(*(int *)(uVar4 + 0xb8fc) + 0xc) + 200), pcVar2 != (code *)0x0)))
     ) {
    (*pcVar2)(param_1);
  }
  if (uVar10 < 3) {
    if (uVar9 == 2) {
      *(undefined1 *)(uVar4 + 0x58d) = 2;
      *(undefined1 *)(uVar4 + 0x88a) = 1;
      *(undefined1 *)(uVar4 + 0x587) = 1;
      *(undefined1 *)(uVar4 + 0x55f) = 0;
LAB_ram_000184b6:
      uVar7 = uVar7 - 2;
      goto LAB_ram_0001845c;
    }
    if (uVar9 == 3) {
      *(undefined1 *)(uVar4 + 0x58d) = 1;
      *(undefined1 *)(uVar4 + 0x88a) = 1;
      *(undefined1 *)(uVar4 + 0x587) = 1;
      *(undefined1 *)(uVar4 + 0x55f) = 0;
      uVar6 = uVar7 + 2 & 0xff;
    }
    else {
      *(undefined1 *)(uVar4 + 0x58d) = 0;
      *(undefined1 *)(uVar4 + 0x88a) = 0;
      *(undefined1 *)(uVar4 + 0x587) = 0;
      *(undefined1 *)(uVar4 + 0x55f) = 0;
    }
  }
  else if (uVar10 == 3) {
    uVar3 = param_1[7];
    uVar10 = *(uint *)(param_1[5] + 4);
    *(undefined1 *)(uVar4 + 0x88a) = 2;
    *(undefined1 *)(uVar4 + 0x55f) = 1;
    *(undefined1 *)(uVar4 + 0x587) = 1;
    if (uVar10 < uVar3) {
      *(undefined1 *)(uVar4 + 0x58f) = 1;
      if (uVar3 - uVar10 == 10) {
        *(undefined1 *)(uVar4 + 0x58d) = 2;
        uVar7 = uVar7 + 2;
      }
      else {
        if (uVar3 - uVar10 != 0x1e) goto LAB_ram_000184f4;
        *(undefined1 *)(uVar4 + 0x58d) = 1;
        uVar7 = uVar7 + 6;
      }
LAB_ram_0001845c:
      uVar6 = uVar7 & 0xff;
    }
    else {
      *(undefined1 *)(uVar4 + 0x58f) = 2;
      if (uVar10 - uVar3 == 10) {
        *(undefined1 *)(uVar4 + 0x58d) = 1;
        goto LAB_ram_000184b6;
      }
      if (uVar10 - uVar3 == 0x1e) {
        *(undefined1 *)(uVar4 + 0x58d) = 2;
        uVar7 = uVar7 - 6;
        goto LAB_ram_0001845c;
      }
    }
  }
LAB_ram_000184f4:
  uVar5 = (undefined1)uVar6;
  if (uVar6 == 0) {
    uVar5 = 1;
  }
  if (*(char *)(uVar4 + 0x4dc) != '\0') {
    *(undefined1 *)(uVar4 + 0x4dc) = 0;
    iVar8 = 0x31;
    do {
      iVar8 = iVar8 + -1;
      __udelay(1000);
    } while (iVar8 != -1);
  }
  *(undefined1 *)(uVar4 + 0x88f) = uVar5;
  (**(code **)(*(int *)(*(int *)(uVar4 + 0xb8fc) + 0xc) + 0x38))(param_1);
  (**(code **)(*(int *)(*(int *)(uVar4 + 0xb8fc) + 0xc) + 0x7c))(param_1);
  (**(code **)(*(int *)(*(int *)(uVar4 + 0xb8fc) + 0xc) + 0x34))(param_1,uVar9);
LAB_ram_000182f4:
  (*(code *)&mutex_unlock)(uVar4 + 0x24);
  return 0;
}

