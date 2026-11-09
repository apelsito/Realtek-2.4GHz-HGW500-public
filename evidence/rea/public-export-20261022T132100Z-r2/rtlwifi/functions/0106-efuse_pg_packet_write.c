/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x150c8; aliases: efuse_pg_packet_write
 */

undefined4 efuse_pg_packet_write(int param_1,undefined4 param_2,byte param_3,undefined1 *param_4)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  byte bVar16;
  uint uVar17;
  undefined4 uVar18;
  int iStack_68;
  byte local_58;
  byte local_57;
  byte local_56;
  char local_55;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  byte local_42;
  byte local_41;
  undefined1 uStack_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 uStack_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  
  iVar14 = *(int *)(param_1 + 0x40);
  (*(code *)&memset)(&local_42,0,10);
  uVar4 = efuse_get_current_size(param_1);
  if (0x200U - *(int *)(*(int *)(iVar14 + 0xb8fc) + 0x74) <= uVar4) {
    return 0;
  }
  bVar13 = (byte)param_2;
  local_42 = bVar13;
  local_41 = param_3;
  (*(code *)&memset)(&uStack_40,0xff,8);
  if ((param_3 & 1) == 0) {
    uStack_40 = *param_4;
    local_3f = param_4[1];
  }
  if ((param_3 & 2) == 0) {
    local_3e = param_4[2];
    local_3d = param_4[3];
  }
  if ((param_3 & 4) == 0) {
    uStack_3c = param_4[4];
    local_3b = param_4[5];
  }
  if ((param_3 & 8) == 0) {
    local_3a = param_4[6];
    local_39 = param_4[7];
  }
  uVar4 = 0;
  iStack_68 = efuse_calculate_word_cnts(local_41);
  do {
    iVar15 = 1;
LAB_ram_00015222:
    if (0x200U - *(int *)(*(int *)(iVar14 + 0xb8fc) + 0x74) <= uVar4) {
      return 1;
    }
    if (iVar15 == 1) {
      uVar5 = efuse_one_byte_read(param_1,uVar4,&local_58);
      bVar16 = local_58;
      if ((uVar5 != 0) && (local_58 != 0xff)) {
        uVar17 = local_58 & 0xf;
        local_4c = 0;
        local_48 = 0;
        iVar6 = efuse_calculate_word_cnts(uVar17);
        uVar12 = uVar4 + 1;
        iVar6 = iVar6 * 2;
        if (local_42 == bVar16 >> 4) {
          for (uVar11 = 0; (int)uVar11 < iVar6; uVar11 = uVar11 + 1 & 0xff) {
            iVar7 = efuse_one_byte_read(param_1,uVar11 + uVar4 + 1 & 0xffff,&local_54);
            if (iVar7 != 0) {
              uVar5 = uVar5 & (byte)local_54 == -1;
            }
          }
          if (uVar5 != 0) {
            uVar8 = local_41 | uVar17;
            uVar11 = (uVar8 & 1) + 0xe;
            if ((uVar8 & 2) == 0) {
              uVar11 = uVar11 & 0x1d;
            }
            if ((uVar8 & 4) == 0) {
              uVar11 = uVar11 & 0xfb;
            }
            if ((uVar8 & 8) == 0) {
              uVar11 = uVar11 & 0xf7;
            }
            else if (uVar11 == 0xf) {
              uVar4 = uVar12 + iVar6 & 0xffff;
              local_42 = bVar13;
              local_41 = param_3;
              goto LAB_ram_00015222;
            }
            iVar6 = enable_efuse_data_write(param_1,uVar12 & 0xffff,uVar17);
            if (iVar6 != 0xf) {
              efuse_pg_packet_write(param_1,param_2,iVar6);
            }
            uVar11 = uVar11 ^ local_41;
            uVar12 = 0xf - (uVar11 & 1);
            uVar17 = uVar12 & 0xff;
            if ((uVar11 & 2) != 0) {
              uVar17 = uVar12 & 0xfd;
            }
            if ((uVar11 & 4) != 0) {
              uVar17 = uVar17 & 0xfb;
            }
            bVar16 = (byte)uVar17;
            if ((uVar11 & 8) == 0) {
              if (uVar17 != 0xf) goto LAB_ram_000152ea;
              uVar5 = 0;
            }
            else {
              bVar16 = bVar16 & 0xf7;
LAB_ram_000152ea:
              uVar4 = efuse_get_current_size(param_1);
              local_42 = bVar13;
              local_41 = bVar16;
            }
            repeat_times_0 = repeat_times_0 + 1;
            uVar5 = repeat_times_0 < 4 & uVar5;
            goto LAB_ram_00015320;
          }
        }
        uVar4 = iVar6 + uVar12 & 0xffff;
        goto LAB_ram_00015222;
      }
      uVar18 = 0;
      bVar16 = local_41 | local_42 << 4;
      local_54 = 0;
      local_50 = 0;
      efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),uVar4,bVar16);
      efuse_one_byte_read(param_1,uVar4,&local_57);
      if (bVar16 == local_57) {
        iVar15 = 0x20;
      }
      else {
        if (local_57 != 0xff) {
          bVar16 = local_57 >> 4;
          bVar3 = local_57 & 0xf;
          iVar6 = efuse_calculate_word_cnts();
          (*(code *)&memset)(&local_54,0xff,8);
          local_4c = uVar18;
          local_48 = uVar18;
          (*(code *)&memset)(&local_54,0xff,8);
          iVar7 = 1;
          uVar5 = 0;
          (*(code *)&memset)(&local_4c,0xff,8);
          do {
            if (iVar7 == 1) {
              iVar9 = efuse_one_byte_read(param_1,uVar5,&local_56);
              bVar2 = local_56;
              if ((iVar9 == 0) || (local_56 == 0xff)) break;
              iVar9 = efuse_calculate_word_cnts(local_56 & 0xf);
              if (bVar16 == bVar2 >> 4) {
                bVar1 = true;
                for (uVar12 = 0; (int)uVar12 < iVar9 * 2; uVar12 = uVar12 + 1 & 0xff) {
                  iVar10 = efuse_one_byte_read(param_1,(int)(short)((short)uVar12 + (short)uVar5 + 1
                                                                   ),&local_55);
                  if (iVar10 != 0) {
                    *(char *)((int)&local_4c + uVar12) = local_55;
                    bVar1 = (bool)(bVar1 & local_55 == -1);
                  }
                }
                if (!bVar1) {
                  iVar7 = 0x20;
                  goto LAB_ram_000154be;
                }
              }
              uVar5 = uVar5 + 1 + iVar9 * 2 & 0xffff;
            }
            else {
              local_54 = local_4c;
              uVar5 = uVar5 + 1 & 0xffff;
              local_50 = local_48;
              iVar7 = 1;
            }
LAB_ram_000154be:
          } while (uVar5 < 0x200);
          uVar4 = uVar4 + 1;
          if (((byte)local_54 & local_54._1_1_ & local_54._2_1_ & local_54._3_1_ & (byte)local_50 &
               local_50._1_1_ & local_50._2_1_ & local_50._3_1_) == 0xff) {
            uVar4 = uVar4 + iVar6 * 2 & 0xffff;
          }
          else {
            iVar7 = enable_efuse_data_write(param_1,uVar4 & 0xffff,bVar3);
            uVar4 = uVar4 + iVar6 * 2 & 0xffff;
            if (iVar7 != 0xf) {
              efuse_pg_packet_write(param_1,bVar16,iVar7);
              uVar4 = efuse_get_current_size(param_1);
            }
          }
        }
        repeat_times_0 = repeat_times_0 + 1;
        uVar5 = (uint)(repeat_times_0 < 4);
LAB_ram_00015320:
        if (uVar5 == 0) {
          return 1;
        }
      }
      goto LAB_ram_00015222;
    }
    iVar15 = enable_efuse_data_write(param_1,uVar4 + 1 & 0xffff,local_41);
    if (iVar15 == 0xf) {
      return 1;
    }
    repeat_times_0 = repeat_times_0 + 1;
    local_41 = (byte)iVar15;
    if (3 < repeat_times_0) {
      return 1;
    }
    uVar4 = uVar4 + 1 + iStack_68 * 2 & 0xffff;
    local_42 = bVar13;
    iStack_68 = efuse_calculate_word_cnts();
  } while( true );
}

