/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x14e44; aliases: enable_efuse_data_write
 */

uint enable_efuse_data_write(int param_1,uint param_2,uint param_3,char *param_4)

{
  uint uVar1;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = 0;
  uStack_28 = 0;
  (*(code *)&memset)(&local_2c,0xff,8);
  if ((param_3 & 1) == 0) {
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2,*param_4);
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2 + 1 & 0xffff,param_4[1]);
    efuse_one_byte_read(param_1,param_2,&local_2c);
    efuse_one_byte_read(param_1,param_2 + 1 & 0xffff,(int)&local_2c + 1);
    param_2 = param_2 + 2 & 0xffff;
    if ((*param_4 != (char)local_2c) || (param_4[1] != local_2c._1_1_)) {
      uVar1 = 0xe;
      goto LAB_ram_00014ede;
    }
  }
  uVar1 = 0xf;
LAB_ram_00014ede:
  if ((param_3 & 2) == 0) {
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2,param_4[2]);
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2 + 1 & 0xffff,param_4[3]);
    efuse_one_byte_read(param_1,param_2,(int)&local_2c + 2);
    efuse_one_byte_read(param_1,param_2 + 1 & 0xffff,(int)&local_2c + 3);
    param_2 = param_2 + 2 & 0xffff;
    if ((param_4[2] != local_2c._2_1_) || (param_4[3] != local_2c._3_1_)) {
      uVar1 = uVar1 & 0xfd;
    }
  }
  if ((param_3 & 4) == 0) {
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2,param_4[4]);
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2 + 1 & 0xffff,param_4[5]);
    efuse_one_byte_read(param_1,param_2,&uStack_28);
    efuse_one_byte_read(param_1,param_2 + 1 & 0xffff,(int)&uStack_28 + 1);
    param_2 = param_2 + 2 & 0xffff;
    if ((param_4[4] != (char)uStack_28) || (param_4[5] != uStack_28._1_1_)) {
      uVar1 = uVar1 & 0xfb;
    }
  }
  if ((param_3 & 8) == 0) {
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2,param_4[6]);
    efuse_one_byte_write_isra_0(*(undefined4 *)(param_1 + 0x40),param_2 + 1 & 0xffff,param_4[7]);
    efuse_one_byte_read(param_1,param_2,(int)&uStack_28 + 2);
    efuse_one_byte_read(param_1,param_2 + 1 & 0xffff,(int)&uStack_28 + 3);
    if ((param_4[6] != uStack_28._2_1_) || (param_4[7] != uStack_28._3_1_)) {
      uVar1 = uVar1 & 0xf7;
    }
  }
  return uVar1;
}

