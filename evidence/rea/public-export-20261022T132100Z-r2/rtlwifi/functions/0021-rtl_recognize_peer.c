/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x10a34; aliases: rtl_recognize_peer
 */

void rtl_recognize_peer(int param_1,ushort *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar4 + 0x3f4) == 2) {
    if (*(int *)(iVar4 + 0x4d0) == 0) {
      *(undefined4 *)(iVar4 + 0x56c) = 0;
    }
    else if (((*(byte *)(iVar4 + 0x4eb) < 3) && ((*param_2 & 0xfc) == 0x80)) && (0x2c < param_3)) {
      iVar5 = iVar4 + 0x566;
      puVar3 = param_2 + 0x12;
      if ((param_2[8] == *(ushort *)(iVar4 + 0x566) && param_2[9] == *(ushort *)(iVar4 + 0x568)) &&
          *(ushort *)(iVar4 + 0x56a) == param_2[10]) {
        do {
          if ((ushort *)((int)param_2 + param_3) <= puVar3) break;
          if ((char)*puVar3 == -0x23) {
            puVar6 = puVar3 + 1;
            iVar7 = *(int *)(param_1 + 0x40);
            iVar1 = (*(code *)&memcmp)(puVar6,&athcap_1_65,3);
            if ((iVar1 == 0) || (iVar1 = (*(code *)&memcmp)(puVar6,&athcap_2_66,3), iVar1 == 0)) {
              uVar2 = 5;
            }
            else {
              iVar1 = (*(code *)&memcmp)(puVar6,&broadcap_1_67,3);
              if (((iVar1 == 0) || (iVar1 = (*(code *)&memcmp)(puVar6,&broadcap_2_68,3), iVar1 == 0)
                  ) || (iVar1 = (*(code *)&memcmp)(puVar6,&broadcap_3_69,3), iVar1 == 0)) {
                uVar2 = 3;
              }
              else {
                iVar1 = (*(code *)&memcmp)(puVar6,&racap_70,3);
                if (iVar1 == 0) {
                  uVar2 = 4;
                }
                else {
                  iVar1 = (*(code *)&memcmp)(puVar6,&ciscocap_71,3);
                  if (iVar1 == 0) {
                    uVar2 = 6;
                  }
                  else {
                    iVar1 = (*(code *)&memcmp)(puVar6,&marvcap_72,3);
                    if (iVar1 != 0) goto LAB_ram_00010ba0;
                    uVar2 = 7;
                  }
                }
              }
            }
            *(undefined4 *)(iVar7 + 0x56c) = uVar2;
            iVar1 = *(int *)(iVar4 + 0x56c);
            goto LAB_ram_00010bb0;
          }
LAB_ram_00010ba0:
          puVar3 = (ushort *)(*(byte *)((int)puVar3 + 1) + 2 + (int)puVar3);
        } while (puVar3 <= (ushort *)((int)param_2 + param_3));
        iVar1 = 0;
LAB_ram_00010bb0:
        iVar7 = (*(code *)&memcmp)(iVar5,&ap5_1_49,3);
        if (((((iVar7 == 0) || (iVar7 = (*(code *)&memcmp)(iVar5,&ap5_2_50,3), iVar7 == 0)) ||
             (iVar7 = (*(code *)&memcmp)(iVar5,&ap5_3_51,3), iVar7 == 0)) ||
            ((iVar7 = (*(code *)&memcmp)(iVar5,&ap5_4_52,3), iVar7 == 0 ||
             (iVar7 = (*(code *)&memcmp)(iVar5,&ap5_5_53,3), iVar7 == 0)))) ||
           ((iVar7 = (*(code *)&memcmp)(iVar5,&ap5_6_54,3), iVar7 == 0 || (iVar1 == 5)))) {
          iVar1 = 5;
        }
        else {
          iVar7 = (*(code *)&memcmp)(iVar5,&ap4_4_55,3);
          if (((iVar7 == 0) || (iVar7 = (*(code *)&memcmp)(iVar5,&ap4_5_56,3), iVar7 == 0)) ||
             ((iVar7 = (*(code *)&memcmp)(iVar5,&ap4_1_57,3), iVar7 == 0 ||
              (((iVar7 = (*(code *)&memcmp)(iVar5,&ap4_2_58,3), iVar7 == 0 ||
                (iVar7 = (*(code *)&memcmp)(iVar5,&ap4_3_59,3), iVar7 == 0)) || (iVar1 == 4)))))) {
            iVar1 = 4;
          }
          else {
            iVar7 = (*(code *)&memcmp)(iVar5,&ap6_1_60,3);
            if (iVar7 == 0) {
              iVar1 = 6;
            }
            else if (iVar1 != 6) {
              iVar7 = (*(code *)&memcmp)(iVar5,&ap3_1_61,3);
              if (((iVar7 == 0) || (iVar7 = (*(code *)&memcmp)(iVar5,&ap3_2_62,3), iVar7 == 0)) ||
                 ((iVar7 = (*(code *)&memcmp)(iVar5,&ap3_3_63,3), iVar7 == 0 || (iVar1 == 3)))) {
                iVar1 = 3;
              }
              else {
                iVar5 = (*(code *)&memcmp)(iVar5,&ap7_1_64,3);
                if (iVar5 == 0) {
                  iVar1 = 7;
                }
              }
            }
          }
        }
        *(int *)(iVar4 + 0x56c) = iVar1;
      }
    }
  }
  return;
}

