/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.
 * ARC700 ABI, types, indirect calls and boundary recovery require validation.
 * ELF address: 0x11f04; aliases: rtl92ee_set_fw_rsvdpagepkt
 */

void rtl92ee_set_fw_rsvdpagepkt(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x40);
  reserved_page_packet[0x10] = *(undefined1 *)(iVar2 + 0x566);
  reserved_page_packet[0x11] = *(undefined1 *)(iVar2 + 0x567);
  reserved_page_packet[0x13] = *(undefined1 *)(iVar2 + 0x569);
  reserved_page_packet[0x14] = *(undefined1 *)(iVar2 + 0x56a);
  reserved_page_packet[0x15] = *(undefined1 *)(iVar2 + 0x56b);
  reserved_page_packet[0x12] = *(undefined1 *)(iVar2 + 0x568);
  reserved_page_packet[0x103] = (byte)((ushort)*(undefined2 *)(iVar2 + 0x59a) >> 8) | 0xc0;
  reserved_page_packet[0x102] = (undefined1)*(undefined2 *)(iVar2 + 0x59a);
  reserved_page_packet[0x104] = (undefined1)*(undefined2 *)(iVar2 + 0x566);
  reserved_page_packet[0xb] = *(undefined1 *)(iVar2 + 0x211);
  reserved_page_packet[0xc] = *(undefined1 *)(iVar2 + 0x212);
  reserved_page_packet[0xd] = *(undefined1 *)(iVar2 + 0x213);
  reserved_page_packet[0xe] = *(undefined1 *)(iVar2 + 0x214);
  reserved_page_packet[0xf] = *(undefined1 *)(iVar2 + 0x215);
  reserved_page_packet[10] = *(undefined1 *)(iVar2 + 0x210);
  reserved_page_packet[0x105] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x566) >> 8);
  reserved_page_packet[0x106] = (undefined1)*(undefined2 *)(iVar2 + 0x568);
  reserved_page_packet[0x107] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x568) >> 8);
  reserved_page_packet[0x108] = (undefined1)*(undefined2 *)(iVar2 + 0x56a);
  reserved_page_packet[0x109] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x56a) >> 8);
  reserved_page_packet[0x10a] = (undefined1)*(undefined2 *)(iVar2 + 0x210);
  reserved_page_packet[0x10b] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x210) >> 8);
  reserved_page_packet[0x10c] = (undefined1)*(undefined2 *)(iVar2 + 0x212);
  reserved_page_packet[0x10e] = (undefined1)*(undefined2 *)(iVar2 + 0x214);
  reserved_page_packet[0x10d] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x212) >> 8);
  reserved_page_packet[0x10f] = (undefined1)((ushort)*(undefined2 *)(iVar2 + 0x214) >> 8);
  reserved_page_packet[0x30a] = *(undefined1 *)(iVar2 + 0x210);
  reserved_page_packet[0x30b] = *(undefined1 *)(iVar2 + 0x211);
  reserved_page_packet[0x30c] = *(undefined1 *)(iVar2 + 0x212);
  reserved_page_packet[0x30d] = *(undefined1 *)(iVar2 + 0x213);
  reserved_page_packet[0x30e] = *(undefined1 *)(iVar2 + 0x214);
  reserved_page_packet[0x30f] = *(undefined1 *)(iVar2 + 0x215);
  reserved_page_packet[0x38a] = *(undefined1 *)(iVar2 + 0x210);
  reserved_page_packet[0x38b] = *(undefined1 *)(iVar2 + 0x211);
  reserved_page_packet[0x38c] = *(undefined1 *)(iVar2 + 0x212);
  reserved_page_packet[0x38d] = *(undefined1 *)(iVar2 + 0x213);
  reserved_page_packet[0x38e] = *(undefined1 *)(iVar2 + 0x214);
  reserved_page_packet[0x38f] = *(undefined1 *)(iVar2 + 0x215);
  reserved_page_packet[0x184] = reserved_page_packet[0x10];
  reserved_page_packet[0x185] = reserved_page_packet[0x11];
  reserved_page_packet[0x186] = reserved_page_packet[0x12];
  reserved_page_packet[0x187] = reserved_page_packet[0x13];
  reserved_page_packet[0x188] = reserved_page_packet[0x14];
  reserved_page_packet[0x189] = reserved_page_packet[0x15];
  reserved_page_packet[0x18a] = reserved_page_packet[10];
  reserved_page_packet[0x18b] = reserved_page_packet[0xb];
  reserved_page_packet[0x18c] = reserved_page_packet[0xc];
  reserved_page_packet[0x18d] = reserved_page_packet[0xd];
  reserved_page_packet[0x18e] = reserved_page_packet[0xe];
  reserved_page_packet[399] = reserved_page_packet[0xf];
  reserved_page_packet[400] = reserved_page_packet[0x10];
  reserved_page_packet[0x191] = reserved_page_packet[0x11];
  reserved_page_packet[0x192] = reserved_page_packet[0x12];
  reserved_page_packet[0x193] = reserved_page_packet[0x13];
  reserved_page_packet[0x194] = reserved_page_packet[0x14];
  reserved_page_packet[0x195] = reserved_page_packet[0x15];
  reserved_page_packet[0x204] = reserved_page_packet[0x10];
  reserved_page_packet[0x205] = reserved_page_packet[0x11];
  reserved_page_packet[0x206] = reserved_page_packet[0x12];
  reserved_page_packet[0x207] = reserved_page_packet[0x13];
  reserved_page_packet[0x208] = reserved_page_packet[0x14];
  reserved_page_packet[0x209] = reserved_page_packet[0x15];
  reserved_page_packet[0x20a] = reserved_page_packet[10];
  reserved_page_packet[0x20b] = reserved_page_packet[0xb];
  reserved_page_packet[0x20c] = reserved_page_packet[0xc];
  reserved_page_packet[0x20d] = reserved_page_packet[0xd];
  reserved_page_packet[0x20e] = reserved_page_packet[0xe];
  reserved_page_packet[0x20f] = reserved_page_packet[0xf];
  reserved_page_packet[0x210] = reserved_page_packet[0x10];
  reserved_page_packet[0x211] = reserved_page_packet[0x11];
  reserved_page_packet[0x212] = reserved_page_packet[0x12];
  reserved_page_packet[0x213] = reserved_page_packet[0x13];
  reserved_page_packet[0x214] = reserved_page_packet[0x14];
  reserved_page_packet[0x215] = reserved_page_packet[0x15];
  reserved_page_packet[0x304] = reserved_page_packet[0x10];
  reserved_page_packet[0x305] = reserved_page_packet[0x11];
  reserved_page_packet[0x306] = reserved_page_packet[0x12];
  reserved_page_packet[0x307] = reserved_page_packet[0x13];
  reserved_page_packet[0x308] = reserved_page_packet[0x14];
  reserved_page_packet[0x309] = reserved_page_packet[0x15];
  reserved_page_packet[0x310] = reserved_page_packet[0x10];
  reserved_page_packet[0x311] = reserved_page_packet[0x11];
  reserved_page_packet[0x312] = reserved_page_packet[0x12];
  reserved_page_packet[0x313] = reserved_page_packet[0x13];
  reserved_page_packet[0x314] = reserved_page_packet[0x14];
  reserved_page_packet[0x315] = reserved_page_packet[0x15];
  reserved_page_packet[900] = reserved_page_packet[0x10];
  reserved_page_packet[0x385] = reserved_page_packet[0x11];
  reserved_page_packet[0x386] = reserved_page_packet[0x12];
  reserved_page_packet[0x387] = reserved_page_packet[0x13];
  reserved_page_packet[0x388] = reserved_page_packet[0x14];
  reserved_page_packet[0x389] = reserved_page_packet[0x15];
  reserved_page_packet[0x390] = reserved_page_packet[0x10];
  reserved_page_packet[0x391] = reserved_page_packet[0x11];
  reserved_page_packet[0x392] = reserved_page_packet[0x12];
  reserved_page_packet[0x393] = reserved_page_packet[0x13];
  reserved_page_packet[0x394] = reserved_page_packet[0x14];
  reserved_page_packet[0x395] = reserved_page_packet[0x15];
  iVar2 = (*(code *)&__netdev_alloc_skb)(0,0x400,0xa20);
  if (iVar2 != 0) {
    uVar1 = (*(code *)&skb_put)(iVar2,0x400);
    (*(code *)&memcpy)(uVar1,reserved_page_packet,0x400);
    iVar2 = (*(code *)&rtl_cmd_send_packet)(param_1,iVar2);
    if (iVar2 != 0) {
      rtl92ee_fill_h2c_cmd(param_1,0);
    }
  }
  return;
}

