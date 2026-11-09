/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x116a8; aliases: rtl92ee_fill_h2c_cmd
 */

/* WARNING: Type propagation algorithm not settling */

void rtl92ee_fill_h2c_cmd(int param_1,undefined1 param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  
  uStack_40 = 0;
  uStack_3c = 0;
  if (*(char *)(*(int *)(param_1 + 0x40) + 0x6ba) == '\0') {
    if (__warned_1 == '\0') {
      __warned_1 = '\x01';
      (*(code *)&warn_slowpath_fmt)
                ("drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c",0x1cd,9,
                 "rtl8192ee: error H2C cmd because of Fw download fail!!!\n");
    }
  }
  else {
    pcVar11 = (code *)&memset;
    (*(code *)&memset)(&stack0xffffffc0,0,8);
    (*(code *)&memcpy)(&stack0xffffffc0,param_4,param_3);
    iVar8 = *(int *)(param_1 + 0x40);
    local_48 = 0;
    local_44 = 0;
    if ((*(int *)(iVar8 + 0xb2f0) == 0) && (uVar7 = 0, *(int *)(iVar8 + 0xb310) != 2)) {
      while (uVar2 = arch_local_irq_save(), *(char *)(iVar8 + 0x6b8) != '\0') {
        while (*(char *)(iVar8 + 0x6b8) != '\0') {
          Auxregs0028 = uVar2;
          uVar7 = uVar7 + 1;
          __udelay(100);
          if (1000 < uVar7) {
            return;
          }
          uVar2 = arch_local_irq_save();
        }
        Auxregs0028 = uVar2;
      }
      *(undefined1 *)(iVar8 + 0x6b8) = 1;
      Auxregs0028 = uVar2;
      bVar1 = *(byte *)(iVar8 + 0x6b9);
      uVar7 = (uint)bVar1;
      iVar10 = uVar7 * 4 + 0x1d0;
      iVar9 = uVar7 * 4 + 0x1f0;
      if (3 < uVar7) {
        iVar9 = 0;
        iVar10 = 0;
      }
      iVar3 = rtl_read_byte(iVar8,0x100);
      if (iVar3 == 0xea) {
        iVar9 = rtl_read_byte(iVar8,0x210);
        if ((iVar9 == 0xea) || (iVar9 = rtl_read_byte(iVar8,0x41a), iVar9 == 0xea)) {
          rtl_write_byte(iVar8,0xf3,0xff);
        }
      }
      else {
        cVar5 = 'd';
        iVar3 = rtl_read_byte(*(undefined4 *)(param_1 + 0x40),0x1cc);
        uVar6 = iVar3 >> (bVar1 & 0x1f);
        while ((~uVar6 & 1) == 0) {
          cVar5 = cVar5 + -1;
          if (cVar5 == '\0') goto LAB_ram_00011898;
          __udelay(10);
          iVar3 = rtl_read_byte(*(undefined4 *)(param_1 + 0x40),0x1cc);
          rtl_read_byte(iVar8,0x130);
          uVar6 = iVar3 >> (bVar1 & 0x1f);
        }
        (*pcVar11)(&local_48,0,4);
        (*pcVar11)(&local_44,0,4);
        local_48 = CONCAT31(local_48._1_3_,param_2);
        if (param_3 < 4) {
          if (param_3 != 0) {
            uVar6 = 0;
            (*(code *)&memcpy)((int)&local_48 + 1,&stack0xffffffc0,param_3);
            do {
              puVar4 = (undefined1 *)((int)&local_48 + uVar6);
              iVar9 = iVar10 + uVar6;
              uVar6 = uVar6 + 1 & 0xff;
              rtl_write_byte(iVar8,iVar9,*puVar4);
            } while (uVar6 != 4);
          }
        }
        else if (param_3 - 4 < 4) {
          (*(code *)&memcpy)(&local_44,&uStack_3d,param_3 - 3);
          uVar6 = 0;
          (*(code *)&memcpy)((int)&local_48 + 1,&stack0xffffffc0,3);
          do {
            puVar4 = (undefined1 *)((int)&local_44 + uVar6);
            iVar3 = iVar9 + uVar6;
            uVar6 = uVar6 + 1 & 0xff;
            rtl_write_byte(iVar8,iVar3,*puVar4);
          } while (uVar6 != 4);
          uVar6 = 0;
          do {
            puVar4 = (undefined1 *)((int)&local_48 + uVar6);
            iVar9 = iVar10 + uVar6;
            uVar6 = uVar6 + 1 & 0xff;
            rtl_write_byte(iVar8,iVar9,*puVar4);
          } while (uVar6 != 4);
        }
        if ((uVar7 + 1 & 0xff) == 4) {
          *(undefined1 *)(iVar8 + 0x6b9) = 0;
        }
        else {
          *(char *)(iVar8 + 0x6b9) = (char)(uVar7 + 1);
        }
      }
LAB_ram_00011898:
      uVar2 = arch_local_irq_save();
      *(undefined1 *)(iVar8 + 0x6b8) = 0;
      Auxregs0028 = uVar2;
    }
  }
  return;
}

