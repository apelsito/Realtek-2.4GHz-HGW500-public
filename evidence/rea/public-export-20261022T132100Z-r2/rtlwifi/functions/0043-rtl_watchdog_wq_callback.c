/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x12108; aliases: rtl_watchdog_wq_callback
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rtl_watchdog_wq_callback(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  uint local_48 [9];
  
  iVar9 = *(int *)(param_1 + -0xa0);
  iVar8 = *(int *)(iVar9 + 0x40);
  (*(code *)&memset)(local_48,0,0x24);
  if (*(char *)(iVar8 + 0x698) == '\0') {
    return;
  }
  if (*(int *)(iVar8 + 0x4d0) == 0) {
    *(undefined1 *)(iVar8 + 0x4eb) = 0;
  }
  else {
    if (*(byte *)(iVar8 + 0x4eb) < 0x14) {
      *(byte *)(iVar8 + 0x4eb) = *(byte *)(iVar8 + 0x4eb) + 1;
    }
    if (*(int *)(iVar8 + 0x4d0) != 1) {
      uVar2 = 0;
      uVar3 = 0;
      *(undefined4 *)(iVar8 + 0xb7b0) = *(undefined4 *)(iVar8 + 0xb7b4);
      *(undefined4 *)(iVar8 + 0xb7a0) = *(undefined4 *)(iVar8 + 0xb7a4);
      *(undefined4 *)(iVar8 + 0xb7b4) = *(undefined4 *)(iVar8 + 0xb7b8);
      *(undefined4 *)(iVar8 + 0xb7a4) = *(undefined4 *)(iVar8 + 0xb7a8);
      *(undefined4 *)(iVar8 + 0xb7b8) = *(undefined4 *)(iVar8 + 0xb7bc);
      *(undefined4 *)(iVar8 + 0xb7a8) = *(undefined4 *)(iVar8 + 0xb7ac);
      *(undefined4 *)(iVar8 + 0xb7bc) = *(undefined4 *)(iVar8 + 0xb7c4);
      *(undefined4 *)(iVar8 + 0xb7ac) = *(undefined4 *)(iVar8 + 0xb7c0);
      uVar1 = 0;
      do {
        iVar4 = iVar8 + uVar3 * 4;
        uVar3 = uVar3 + 1 & 0xff;
        uVar1 = uVar1 + *(int *)(iVar4 + 0xb7b0);
        uVar2 = uVar2 + *(int *)(iVar4 + 0xb7a0);
      } while (uVar3 != 4);
      uVar2 = uVar2 >> 2;
      uVar1 = uVar1 >> 2;
      bVar10 = 100 < uVar2;
      bVar11 = false;
      if (uVar1 < 0x65) {
LAB_ram_0001222e:
        bVar13 = 4000 < uVar2;
        bVar12 = false;
      }
      else {
        bVar11 = uVar2 < uVar1;
        if (uVar1 < 0xfa1) {
          bVar10 = true;
          goto LAB_ram_0001222e;
        }
        bVar12 = 5000 < uVar1;
        bVar10 = true;
        bVar13 = true;
      }
      uVar1 = 0;
      do {
        iVar4 = iVar8 + uVar1 * 0x10;
        *(undefined4 *)(iVar8 + (uVar1 + 0xb7d) * 0x10) = *(undefined4 *)(iVar4 + 0xb7d4);
        *(undefined4 *)(iVar4 + 0xb7d4) = *(undefined4 *)(iVar4 + 0xb7d8);
        *(undefined4 *)(iVar4 + 0xb7d8) = *(undefined4 *)(iVar4 + 0xb7dc);
        *(undefined4 *)(iVar4 + 0xb7dc) = *(undefined4 *)(iVar8 + (uVar1 + 0x2e18) * 4);
        uVar3 = local_48[uVar1];
        uVar2 = 0;
        do {
          iVar4 = uVar1 * 4 + uVar2;
          uVar2 = uVar2 + 1 & 0xff;
          uVar3 = uVar3 + *(int *)(iVar8 + (iVar4 + 0x2df4) * 4);
        } while (uVar2 != 4);
        uVar2 = uVar1 + 1 & 0xff;
        local_48[uVar1] = uVar3;
        *(bool *)(iVar8 + uVar1 + 0xb884) = 0x4e23 < uVar3;
        uVar1 = uVar2;
      } while (uVar2 != 8);
      iVar4 = (**(code **)(*(int *)(*(int *)(iVar8 + 0xb8fc) + 0xc) + 0x104))();
      if ((iVar4 == 0) ||
         (iVar4 = (**(code **)(*(int *)(iVar8 + 0xb9ac) + 0x6c))(iVar8), iVar4 == 0)) {
        if ((*(uint *)(iVar8 + 0xb7c4) + *(int *)(iVar8 + 0xb7c0) < 9) &&
           (*(uint *)(iVar8 + 0xb7c4) < 3)) {
          rtl_lps_enter(iVar9,1);
        }
        else {
          rtl_lps_leave(iVar9,1);
        }
      }
      goto LAB_ram_0001231e;
    }
  }
  bVar12 = false;
  bVar13 = false;
  bVar11 = false;
  bVar10 = false;
LAB_ram_0001231e:
  uVar1 = 0;
  do {
    iVar4 = uVar1 + 0x2e18;
    uVar1 = uVar1 + 1 & 0xff;
    *(undefined4 *)(iVar8 + iVar4 * 4) = 0;
  } while (uVar1 != 8);
  *(bool *)(iVar8 + 0xb7c8) = bVar10;
  *(bool *)(iVar8 + 0xb7cb) = bVar13;
  *(bool *)(iVar8 + 0xb7ca) = bVar11;
  *(undefined1 *)(iVar8 + 0xb7c9) = 0;
  *(bool *)(iVar8 + 0xb7cc) = bVar12;
  uVar2 = *(uint *)(iVar8 + 0xb40c);
  uVar7 = *(uint *)(iVar8 + 0xb3d4);
  uVar1 = uVar7 - uVar2;
  *(uint *)(iVar8 + 0xb3f4) = uVar1;
  iVar5 = (*(int *)(iVar8 + 0xb3d8) - *(int *)(iVar8 + 0xb410)) - (uint)(uVar7 < uVar2);
  *(int *)(iVar8 + 0xb3f8) = iVar5;
  uVar6 = *(uint *)(iVar8 + 0xb3ec);
  uVar3 = *(uint *)(iVar8 + 0xb414);
  uVar2 = uVar6 - uVar3;
  *(uint *)(iVar8 + 0xb3fc) = uVar2;
  iVar4 = (*(int *)(iVar8 + 0xb3f0) - *(int *)(iVar8 + 0xb418)) - (uint)(uVar6 < uVar3);
  *(int *)(iVar8 + 0xb400) = iVar4;
  *(uint *)(iVar8 + 0xb40c) = uVar7;
  *(int *)(iVar8 + 0xb410) = *(int *)(iVar8 + 0xb3d8);
  *(uint *)(iVar8 + 0xb414) = uVar6;
  *(int *)(iVar8 + 0xb418) = *(int *)(iVar8 + 0xb3f0);
  *(uint *)(iVar8 + 0xb404) = ((uVar1 >> 0x1d) + iVar5 * 8) * 0x800 + ((uVar1 & 0x1fffffff) >> 0x12)
  ;
  *(uint *)(iVar8 + 0xb408) = ((uVar2 >> 0x1d) + iVar4 * 8) * 0x800 + ((uVar2 & 0x1fffffff) >> 0x12)
  ;
  if (*(char *)(*(int *)(*(int *)(iVar8 + 0xb8fc) + 0x10) + 0x1c) == '\0') {
    (**(code **)(*(int *)(*(int *)(iVar8 + 0xb8fc) + 0xc) + 0x84))(iVar9);
  }
  if ((*(int *)(iVar8 + 0x4d0) == 2) && (*(int *)(iVar8 + 0x3f4) == 2)) {
    if (*(int *)(iVar8 + 47000) + *(int *)(iVar8 + 0xb7c4) == 0) {
      uVar1 = *(int *)(iVar8 + 0xb79c) + 1;
      *(uint *)(iVar8 + 0xb79c) = uVar1;
      if (4 < uVar1) {
        (*(code *)&printk)(&DAT_ram_00019a88);
        *(undefined4 *)(iVar8 + 0xb79c) = 0;
        (*(code *)&ieee80211_connection_loss)(*(undefined4 *)(iVar8 + 0x3f0));
      }
    }
    else {
      *(undefined4 *)(iVar8 + 0xb79c) = 0;
    }
  }
  iVar4 = (**(code **)(*(int *)(*(int *)(iVar8 + 0xb8fc) + 0xc) + 0x104))();
  if (iVar4 != 0) {
    (**(code **)(*(int *)(iVar8 + 0xb9ac) + 0x34))(iVar8);
  }
  if ((*(char *)(iVar8 + 0xb9b5) != '\0') && ((3000 - _jiffies) + *(int *)(iVar8 + 0xb9b8) < 0)) {
    *(undefined1 *)(iVar8 + 0xb9b5) = 0;
  }
  *(undefined4 *)(iVar8 + 0xb7c4) = 0;
  *(undefined4 *)(iVar8 + 0xb7c0) = 0;
  *(undefined4 *)(iVar8 + 47000) = 0;
  rtl_scan_list_expire(iVar9);
  rtl_free_entries_from_ack_queue(iVar9,1);
  return;
}

