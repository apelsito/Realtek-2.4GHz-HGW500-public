/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14e9c; aliases: _phy_convert_txpower_dbm_to_relative_value
 */

void _phy_convert_txpower_dbm_to_relative_value(uint *param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar4 = 3;
  do {
    bVar1 = (byte)(iVar4 << 3);
    uVar2 = *param_1 >> (bVar1 & 0x1f);
    uVar3 = uVar2 & 0xff;
    if ((param_2 <= iVar4) && (iVar4 <= param_3)) {
      uVar3 = (*param_1 >> (bVar1 + 4 & 0x1f) & 0xf) * 10 + (uVar2 & 0xf) & 0xff;
      if (param_4 < uVar3) {
        uVar3 = uVar3 - param_4;
      }
      else {
        uVar3 = param_4 - uVar3;
      }
      uVar3 = uVar3 & 0xff;
    }
    iVar4 = (int)(char)((char)iVar4 + -1);
    uVar5 = uVar5 << 8 | uVar3;
  } while (iVar4 != -1);
  *param_1 = uVar5;
  return;
}

