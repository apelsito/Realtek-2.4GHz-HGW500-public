/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x189a8; aliases: rtl92ee_init_sw_vars
 */

undefined4 rtl92ee_init_sw_vars(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x40);
  rtl92ee_bt_reg_init();
  *(undefined1 *)(iVar4 + 0xccb8) =
       *(undefined1 *)(*(int *)(*(int *)(iVar4 + 0xb8fc) + 0x10) + 0x13);
  uVar2 = (*(code *)&rtl_btc_get_ops_pointer)();
  *(undefined4 *)(iVar4 + 0xb9ac) = uVar2;
  *(undefined1 *)(iVar4 + 0xa008) = 1;
  *(undefined1 *)(iVar4 + 0xa030) = 0;
  *(undefined1 *)(iVar4 + 0xa00e) = 0;
  *(undefined4 *)(iVar4 + 0xbc54) = 0x8200;
  *(undefined4 *)(iVar4 + 0x6d0) = 0;
  *(undefined4 *)(iVar4 + 0x6d8) = 0;
  *(undefined4 *)(iVar4 + 0x6cc) = 0;
  *(undefined4 *)(iVar4 + 0xcc94) = 0x100;
  *(undefined4 *)(iVar4 + 0xcc88) = 0xf000710e;
  *(undefined4 *)(iVar4 + 0xcc90) = 0x200004ff;
  iVar3 = *(int *)(iVar4 + 0xb8fc);
  *(undefined1 *)(iVar4 + 0xb2fd) = *(undefined1 *)(*(int *)(iVar3 + 0x10) + 0x10);
  *(undefined1 *)(iVar4 + 0xb2f4) = *(undefined1 *)(*(int *)(iVar3 + 0x10) + 0x11);
  *(undefined1 *)(iVar4 + 0xb2f6) = *(undefined1 *)(*(int *)(iVar3 + 0x10) + 0x12);
  *(undefined1 *)(iVar4 + 0xccb8) = *(undefined1 *)(*(int *)(iVar3 + 0x10) + 0x13);
  if (*(char *)(*(int *)(iVar3 + 0x10) + 0x1c) != '\0') {
    (*(code *)&printk)(&DAT_ram_0001d38c);
  }
  *(undefined1 *)(iVar4 + 0xb2f8) = 3;
  *(undefined1 *)(iVar4 + 0xb2fa) = 5;
  iVar3 = *(int *)(param_1 + 0x40);
  *(undefined2 *)(iVar3 + 0xccac) = 0x302;
  *(undefined2 *)(iVar3 + 0xcca8) = 3;
  *(undefined1 *)(iVar3 + 0xccaa) = 0;
  *(char *)(iVar3 + 0xccab) =
       (char)*(undefined4 *)(*(int *)(*(int *)(iVar3 + 0xb8fc) + 0x10) + 0x18);
  cVar1 = *(char *)(iVar4 + 0xb2f8);
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    *(char *)(iVar4 + 0xb2f7) = cVar1;
  }
  else if (cVar1 == '\x03') {
    *(undefined1 *)(iVar4 + 0xb2f7) = 3;
  }
  *(undefined1 *)(iVar4 + 0x6e1) = 0;
  *(undefined1 *)(iVar4 + 0xb2fc) = 0;
  iVar3 = (*(code *)&vzalloc)(0x8000);
  *(int *)(iVar4 + 0x6b0) = iVar3;
  if (iVar3 == 0) {
    (*(code *)&printk)(&DAT_ram_0001d3ac);
  }
  else {
    *(undefined4 *)(iVar4 + 0xb8f8) = 0x8000;
    (*(code *)&printk)(&DAT_ram_0001d3ec,"rtlwifi/rtl8192eefw.bin");
    iVar3 = (*(code *)&request_firmware_nowait)
                      (__this_module,1,"rtlwifi/rtl8192eefw.bin",*(undefined4 *)(iVar4 + 0x724),
                       0xcc0,param_1,&rtl_fw_cb);
    if (iVar3 == 0) {
      return 0;
    }
    (*(code *)&printk)(&DAT_ram_0001d40c);
    (*(code *)&vfree)(*(undefined4 *)(iVar4 + 0x6b0));
    *(undefined4 *)(iVar4 + 0x6b0) = 0;
  }
  return 1;
}

