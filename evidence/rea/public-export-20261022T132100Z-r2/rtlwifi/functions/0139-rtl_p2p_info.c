/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x16ecc; aliases: rtl_p2p_info
 */

void rtl_p2p_info(int param_1,ushort *param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  byte bVar7;
  ushort *puVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  
  iVar11 = *(int *)(param_1 + 0x40);
  if (*(char *)(iVar11 + 0x4dd) == '\0') {
    return;
  }
  if (*(int *)(iVar11 + 0x4d0) != 2) {
    return;
  }
  if (param_3 < 0x2d) {
    return;
  }
  if ((param_2[8] != *(ushort *)(iVar11 + 0x566) || param_2[9] != *(ushort *)(iVar11 + 0x568)) ||
      *(ushort *)(iVar11 + 0x56a) != param_2[10]) {
    return;
  }
  uVar4 = *param_2 & 0xfc;
  if ((uVar4 == 0x80) || (uVar4 == 0x50)) {
    puVar8 = param_2 + 0x12;
    pcVar10 = (char *)((int)param_2 + (param_3 - 4));
    while( true ) {
      if (pcVar10 <= (char *)((int)puVar8 + 1)) {
        return;
      }
      if (pcVar10 < (char *)((int)puVar8 + *(byte *)((int)puVar8 + 1) + 2)) {
        return;
      }
      if ((((char)*puVar8 == -0x23) && (4 < *(byte *)((int)puVar8 + 1))) &&
         (iVar5 = (*(code *)&memcmp)(puVar8 + 1,&p2p_oui_ie_type_0,4), iVar5 == 0)) break;
      puVar8 = (ushort *)((int)puVar8 + *(byte *)((int)puVar8 + 1) + 2);
    }
    puVar8 = puVar8 + 3;
    if (puVar8 == (ushort *)0x0) {
      return;
    }
    for (; (char *)((int)puVar8 + 1) < pcVar10;
        puVar8 = (ushort *)((int)puVar8 + *(ushort *)((int)puVar8 + 1) + 3)) {
      if (pcVar10 < (char *)((int)puVar8 + *(byte *)((int)puVar8 + 1) + 3)) {
        return;
      }
      if ((char)*puVar8 == '\f') {
        iVar5 = *(ushort *)((int)puVar8 + 1) - 2;
        if (0x13b13b12 < iVar5 * -0x3b13b13b + 0x9d89d89U) {
          return;
        }
        iVar12 = *(int *)(iVar11 + 0xb344);
        cVar1 = *(char *)((int)puVar8 + 3);
        if ((iVar12 == 0) || (*(char *)(iVar11 + 0xb34c) != cVar1)) {
          bVar3 = (*(code *)&__divsi3)(iVar5,0xd);
          *(char *)(iVar11 + 0xb34c) = cVar1;
          cVar1 = -((char)puVar8[2] >> 7);
          *(char *)(iVar11 + 0xb34e) = cVar1;
          *(byte *)(iVar11 + 0xb34d) = (byte)puVar8[2] & 0x7f;
          bVar7 = bVar3;
          if (2 < bVar3) {
            bVar7 = 2;
          }
          *(byte *)(iVar11 + 0xb34f) = bVar7;
          if (bVar3 == 0) {
            if (cVar1 == '\x01') goto LAB_ram_00017240;
            if (iVar12 == 0) goto LAB_ram_00017262;
            uVar6 = 0;
          }
          else {
            *(char *)(iVar11 + 0xb350) = *(char *)((int)puVar8 + 5);
            *(undefined4 *)(iVar11 + 0xb354) = *(undefined4 *)(puVar8 + 3);
            *(undefined4 *)(iVar11 + 0xb35c) = *(undefined4 *)(puVar8 + 5);
            *(undefined4 *)(iVar11 + 0xb364) = *(undefined4 *)(puVar8 + 7);
            if (bVar3 != 1) {
              *(char *)(iVar11 + 0xb351) = (char)puVar8[9];
              *(undefined4 *)(iVar11 + 0xb358) = *(undefined4 *)((int)puVar8 + 0x13);
              *(undefined4 *)(iVar11 + 0xb360) = *(undefined4 *)((int)puVar8 + 0x17);
              *(undefined4 *)(iVar11 + 0xb368) = *(undefined4 *)((int)puVar8 + 0x1b);
            }
            if (cVar1 == '\x01') {
LAB_ram_00017240:
              *(undefined4 *)(iVar11 + 0xb344) = 1;
              if (*(char *)(iVar11 + 0xb2f9) == '\0') goto LAB_ram_00017262;
            }
            else {
              *(undefined4 *)(iVar11 + 0xb344) = 2;
            }
            uVar6 = 1;
          }
          rtl_p2p_ps_cmd(param_1,uVar6);
        }
LAB_ram_00017262:
        bVar2 = true;
        goto LAB_ram_00017264;
      }
    }
    bVar2 = false;
LAB_ram_00017264:
    if ((*(int *)(iVar11 + 0xb344) == 0) || (bVar2)) {
      return;
    }
LAB_ram_00016fa2:
    uVar6 = 0;
    goto LAB_ram_0001721a;
  }
  if (uVar4 != 0xd0) {
    return;
  }
  if ((char)param_2[0xc] != '\x7f') {
    return;
  }
  iVar5 = (*(code *)&memcmp)((int)param_2 + 0x19,&p2p_oui_ie_type_1,4);
  if (iVar5 != 0) {
    return;
  }
  pcVar10 = (char *)((int)param_2 + 0x1f);
  if (pcVar10 == (char *)0x0) {
    return;
  }
  pcVar9 = (char *)((int)param_2 + (param_3 - 4));
  while( true ) {
    if (pcVar9 <= pcVar10 + 1) {
      return;
    }
    if (pcVar9 < pcVar10 + (byte)pcVar10[1] + 3) {
      return;
    }
    if (*pcVar10 == '\f') break;
    pcVar10 = pcVar10 + *(ushort *)(pcVar10 + 1) + 3;
  }
  iVar5 = *(ushort *)(pcVar10 + 1) - 2;
  if (0x13b13b12 < iVar5 * -0x3b13b13b + 0x9d89d89U) {
    return;
  }
  iVar12 = *(int *)(iVar11 + 0xb344);
  cVar1 = pcVar10[3];
  if ((iVar12 != 0) && (*(char *)(iVar11 + 0xb34c) == cVar1)) {
    return;
  }
  bVar3 = (*(code *)&__divsi3)(iVar5,0xd);
  *(char *)(iVar11 + 0xb34c) = cVar1;
  cVar1 = -(pcVar10[4] >> 7);
  *(char *)(iVar11 + 0xb34e) = cVar1;
  *(byte *)(iVar11 + 0xb34d) = pcVar10[4] & 0x7f;
  bVar7 = bVar3;
  if (2 < bVar3) {
    bVar7 = 2;
  }
  *(byte *)(iVar11 + 0xb34f) = bVar7;
  if (bVar3 == 0) {
    if (cVar1 != '\x01') {
      if (iVar12 == 0) {
        return;
      }
      goto LAB_ram_00016fa2;
    }
LAB_ram_000171fe:
    *(undefined4 *)(iVar11 + 0xb344) = 1;
    if (*(char *)(iVar11 + 0xb2f9) == '\0') {
      return;
    }
  }
  else {
    *(char *)(iVar11 + 0xb350) = pcVar10[5];
    *(undefined4 *)(iVar11 + 0xb354) = *(undefined4 *)(pcVar10 + 6);
    *(undefined4 *)(iVar11 + 0xb35c) = *(undefined4 *)(pcVar10 + 10);
    *(undefined4 *)(iVar11 + 0xb364) = *(undefined4 *)(pcVar10 + 0xe);
    if (bVar3 != 1) {
      *(char *)(iVar11 + 0xb351) = pcVar10[0x12];
      *(undefined4 *)(iVar11 + 0xb358) = *(undefined4 *)(pcVar10 + 0x13);
      *(undefined4 *)(iVar11 + 0xb360) = *(undefined4 *)(pcVar10 + 0x17);
      *(undefined4 *)(iVar11 + 0xb368) = *(undefined4 *)(pcVar10 + 0x1b);
    }
    if (cVar1 == '\x01') goto LAB_ram_000171fe;
    *(undefined4 *)(iVar11 + 0xb344) = 2;
  }
  uVar6 = 1;
LAB_ram_0001721a:
  rtl_p2p_ps_cmd(param_1,uVar6);
  return;
}

