/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x147d8; aliases: rtl_hal_pwrseqcmdparsing
 */

undefined4 rtl_hal_pwrseqcmdparsing(int param_1,byte param_2,byte param_3,byte param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  uVar7 = 0;
  iVar6 = 0;
  do {
    puVar4 = (ushort *)(param_5 + iVar6 * 8);
    uVar5 = (uint)*puVar4;
    bVar1 = *(byte *)((int)puVar4 + 5);
    bVar2 = (byte)puVar4[3];
    if ((((*(byte *)((int)puVar4 + 3) & 0xf & param_3) != 0) && (((byte)puVar4[1] & param_2) != 0))
       && ((*(byte *)((int)puVar4 + 3) >> 4 & param_4) != 0)) {
      switch((byte)puVar4[2] >> 4) {
      case 0:
        break;
      case 1:
        bVar3 = (**(code **)(param_1 + 0x750))(param_1,uVar5);
        (**(code **)(param_1 + 0x740))(param_1,uVar5,bVar3 & ~bVar1 | bVar2 & bVar1);
        if (*(char *)(*(int *)(param_1 + 0xb8fc) + 1) != '\0') {
          (**(code **)(param_1 + 0x750))(param_1,uVar5);
        }
        break;
      case 2:
        do {
          bVar3 = (**(code **)(param_1 + 0x750))(param_1,uVar5);
          bVar8 = (bVar1 & (bVar3 ^ bVar2)) != 0;
          if (bVar8) {
            __udelay(10);
          }
          if (5000 < uVar7) {
            return 0;
          }
          uVar7 = uVar7 + 1;
        } while (bVar8);
        break;
      case 3:
        if (bVar2 == 0) {
          __udelay(uVar5);
        }
        else {
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            __udelay(1000);
          }
        }
        break;
      case 4:
        return 1;
      default:
        if (__warned_4 == '\0') {
          __warned_4 = '\x01';
          (*(code *)&warn_slowpath_fmt)
                    ("drivers/net/wireless/realtek/rtlwifi/core.c",0x788,9,
                     "rtlwifi: rtl_hal_pwrseqcmdparsing(): Unknown CMD!!\n");
        }
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

