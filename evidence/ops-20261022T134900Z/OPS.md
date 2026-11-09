# Inventario de operaciones del núcleo Realtek

Análisis offline de los módulos originales ET_REL ARC700. No se accedió al router.

| Módulo | Bytes | Funciones ELF | Rangos únicos | RELA | Callbacks poblados |
|---|---:|---:|---:|---:|---:|
| rtl8192ee | 102736 | 156 | 154 | 950 | 50 |
| rtlwifi | 77412 | 167 | 165 | 862 | 32 |
| rtl_pci | 45680 | 47 | 47 | 514 | 9 |

Los alias `init_module`/`cleanup_module` pueden aumentar el número de símbolos respecto a los rangos de código únicos.

Se resolvieron 91 slots de callback poblados en siete tablas, con 91 destinos únicos por identidad ELF de módulo/sección/offset.

Las coincidencias de definiciones fuente indican disponibilidad; no prueban equivalencia de compilación. Los slots NULL son datos reales del módulo.

| Módulo | Definición original | Definición overlay | Unión | Sin definición detectada |
|---|---:|---:|---:|---:|
| rtl8192ee | 140 | 60 | 145 | 11 |
| rtlwifi | 156 | 4 | 156 | 11 |
| rtl_pci | 30 | 35 | 41 | 6 |

La búsqueda léxica incluye helpers inline de cabeceras y elimina comentarios. Los alias y funciones generadas por macros pueden no dar coincidencia.

## rtl8192ee: rtl8192ee_hal_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | init_sw_vars | FUNCTION_POINTER | rtl92ee_init_sw_vars |
| 4 | deinit_sw_vars | FUNCTION_POINTER | rtl92ee_deinit_sw_vars |
| 8 | read_chip_version | NULL |  |
| 12 | read_eeprom_info | FUNCTION_POINTER | rtl92ee_read_eeprom_info |
| 16 | interrupt_recognized | FUNCTION_POINTER | rtl92ee_interrupt_recognized |
| 20 | hw_init | FUNCTION_POINTER | rtl92ee_hw_init |
| 24 | hw_disable | FUNCTION_POINTER | rtl92ee_card_disable |
| 28 | hw_suspend | FUNCTION_POINTER | rtl92ee_suspend |
| 32 | hw_resume | FUNCTION_POINTER | rtl92ee_resume |
| 36 | enable_interrupt | FUNCTION_POINTER | rtl92ee_enable_interrupt |
| 40 | disable_interrupt | FUNCTION_POINTER | rtl92ee_disable_interrupt |
| 44 | set_network_type | FUNCTION_POINTER | rtl92ee_set_network_type |
| 48 | set_chk_bssid | FUNCTION_POINTER | rtl92ee_set_check_bssid |
| 52 | set_bw_mode | FUNCTION_POINTER | rtl92ee_phy_set_bw_mode |
| 56 | switch_channel | FUNCTION_POINTER | rtl92ee_phy_sw_chnl |
| 60 | set_qos | FUNCTION_POINTER | rtl92ee_set_qos |
| 64 | set_bcn_reg | FUNCTION_POINTER | rtl92ee_set_beacon_related_registers |
| 68 | set_bcn_intv | FUNCTION_POINTER | rtl92ee_set_beacon_interval |
| 72 | update_interrupt_mask | FUNCTION_POINTER | rtl92ee_update_interrupt_mask |
| 76 | get_hw_reg | FUNCTION_POINTER | rtl92ee_get_hw_reg |
| 80 | set_hw_reg | FUNCTION_POINTER | rtl92ee_set_hw_reg |
| 84 | update_rate_tbl | FUNCTION_POINTER | rtl92ee_update_hal_rate_tbl |
| 88 | pre_fill_tx_bd_desc | FUNCTION_POINTER | rtl92ee_pre_fill_tx_bd_desc |
| 92 | update_rate_mask | NULL |  |
| 96 | rx_desc_buff_remained_cnt | FUNCTION_POINTER | rtl92ee_rx_desc_buff_remained_cnt |
| 100 | rx_check_dma_ok | FUNCTION_POINTER | rtl92ee_rx_check_dma_ok |
| 104 | fill_tx_desc | FUNCTION_POINTER | rtl92ee_tx_fill_desc |
| 108 | fill_fake_txdesc | NULL |  |
| 112 | fill_tx_cmddesc | FUNCTION_POINTER | rtl92ee_tx_fill_cmddesc |
| 116 | fill_tx_special_desc | NULL |  |
| 120 | query_rx_desc | FUNCTION_POINTER | rtl92ee_rx_query_desc |
| 124 | set_channel_access | FUNCTION_POINTER | rtl92ee_update_channel_access_setting |
| 128 | radio_onoff_checking | FUNCTION_POINTER | rtl92ee_gpio_radio_on_off_checking |
| 132 | dm_watchdog | FUNCTION_POINTER | rtl92ee_dm_watchdog |
| 136 | scan_operation_backup | FUNCTION_POINTER | rtl92ee_phy_scan_operation_backup |
| 140 | set_rf_power_state | FUNCTION_POINTER | rtl92ee_phy_set_rf_power_state |
| 144 | led_control | FUNCTION_POINTER | rtl92ee_led_control |
| 148 | set_desc | FUNCTION_POINTER | rtl92ee_set_desc |
| 152 | get_desc | FUNCTION_POINTER | rtl92ee_get_desc |
| 156 | is_tx_desc_closed | FUNCTION_POINTER | rtl92ee_is_tx_desc_closed |
| 160 | tx_polling | FUNCTION_POINTER | rtl92ee_tx_polling |
| 164 | enable_hw_sec | FUNCTION_POINTER | rtl92ee_enable_hw_security_config |
| 168 | set_key | FUNCTION_POINTER | rtl92ee_set_key |
| 172 | init_sw_leds | FUNCTION_POINTER | rtl92ee_init_sw_leds |
| 176 | deinit_sw_leds | NULL |  |
| 180 | get_bbreg | FUNCTION_POINTER | rtl92ee_phy_query_bb_reg |
| 184 | set_bbreg | FUNCTION_POINTER | rtl92ee_phy_set_bb_reg |
| 188 | get_rfreg | FUNCTION_POINTER | rtl92ee_phy_query_rf_reg |
| 192 | set_rfreg | FUNCTION_POINTER | rtl92ee_phy_set_rf_reg |
| 196 | linked_set_reg | NULL |  |
| 200 | chk_switch_dmdp | NULL |  |
| 204 | dualmac_switch_to_dmdp | NULL |  |
| 208 | phy_rf6052_config | NULL |  |
| 212 | phy_rf6052_set_cck_txpower | NULL |  |
| 216 | phy_rf6052_set_ofdm_txpower | NULL |  |
| 220 | config_bb_with_headerfile | NULL |  |
| 224 | config_bb_with_pgheaderfile | NULL |  |
| 228 | phy_lc_calibrate | NULL |  |
| 232 | phy_set_bw_mode_callback | NULL |  |
| 236 | dm_dynamic_txpower | NULL |  |
| 240 | c2h_command_handle | NULL |  |
| 244 | bt_wifi_media_status_notify | NULL |  |
| 248 | bt_coex_off_before_lps | NULL |  |
| 252 | fill_h2c_cmd | FUNCTION_POINTER | rtl92ee_fill_h2c_cmd |
| 256 | set_default_port_id_cmd | NULL |  |
| 260 | get_btc_status | FUNCTION_POINTER | rtl92ee_get_btc_status |
| 264 | is_fw_header | NULL |  |
| 268 | add_wowlan_pattern | NULL |  |
| 272 | get_available_desc | FUNCTION_POINTER | rtl92ee_get_available_desc |
| 276 | c2h_ra_report_handler | FUNCTION_POINTER | rtl92ee_c2h_ra_report_handler |

## rtl8192ee: rtlwifi_pm_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | (layout sin etiquetar) | NULL |  |
| 4 | (layout sin etiquetar) | NULL |  |
| 8 | (layout sin etiquetar) | NULL |  |
| 12 | (layout sin etiquetar) | NULL |  |
| 16 | (layout sin etiquetar) | NULL |  |
| 20 | (layout sin etiquetar) | NULL |  |
| 24 | (layout sin etiquetar) | NULL |  |
| 28 | (layout sin etiquetar) | NULL |  |
| 32 | (layout sin etiquetar) | NULL |  |
| 36 | (layout sin etiquetar) | NULL |  |
| 40 | (layout sin etiquetar) | NULL |  |
| 44 | (layout sin etiquetar) | NULL |  |
| 48 | (layout sin etiquetar) | NULL |  |
| 52 | (layout sin etiquetar) | NULL |  |
| 56 | (layout sin etiquetar) | NULL |  |
| 60 | (layout sin etiquetar) | NULL |  |
| 64 | (layout sin etiquetar) | NULL |  |
| 68 | (layout sin etiquetar) | NULL |  |
| 72 | (layout sin etiquetar) | NULL |  |
| 76 | (layout sin etiquetar) | NULL |  |
| 80 | (layout sin etiquetar) | NULL |  |
| 84 | (layout sin etiquetar) | NULL |  |
| 88 | (layout sin etiquetar) | NULL |  |

## rtl8192ee: rtl92ee_driver

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | (layout sin etiquetar) | NULL |  |
| 4 | (layout sin etiquetar) | NULL |  |
| 8 | (layout sin etiquetar) | DATA_POINTER | .rodata.str1.4+0x95c |
| 12 | (layout sin etiquetar) | DATA_POINTER | .rodata+0x1c0 |
| 16 | (layout sin etiquetar) | FUNCTION_POINTER | rtl_pci_probe |
| 20 | (layout sin etiquetar) | FUNCTION_POINTER | rtl_pci_disconnect |
| 24 | (layout sin etiquetar) | NULL |  |
| 28 | (layout sin etiquetar) | NULL |  |
| 32 | (layout sin etiquetar) | NULL |  |
| 36 | (layout sin etiquetar) | NULL |  |
| 40 | (layout sin etiquetar) | NULL |  |
| 44 | (layout sin etiquetar) | NULL |  |
| 48 | (layout sin etiquetar) | NULL |  |
| 52 | (layout sin etiquetar) | NULL |  |
| 56 | (layout sin etiquetar) | NULL |  |
| 60 | (layout sin etiquetar) | NULL |  |
| 64 | (layout sin etiquetar) | NULL |  |
| 68 | (layout sin etiquetar) | NULL |  |
| 72 | (layout sin etiquetar) | NULL |  |
| 76 | (layout sin etiquetar) | NULL |  |
| 80 | (layout sin etiquetar) | NULL |  |
| 84 | (layout sin etiquetar) | NULL |  |
| 88 | (layout sin etiquetar) | NULL |  |
| 92 | (layout sin etiquetar) | NULL |  |
| 96 | (layout sin etiquetar) | NULL |  |
| 100 | (layout sin etiquetar) | NULL |  |
| 104 | (layout sin etiquetar) | NULL |  |
| 108 | (layout sin etiquetar) | NULL |  |
| 112 | (layout sin etiquetar) | DATA_POINTER | .rodata+0x108 |
| 116 | (layout sin etiquetar) | NULL |  |
| 120 | (layout sin etiquetar) | NULL |  |
| 124 | (layout sin etiquetar) | NULL |  |
| 128 | (layout sin etiquetar) | NULL |  |

## rtlwifi: rtl_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | tx | FUNCTION_POINTER | rtl_op_tx |
| 4 | start | FUNCTION_POINTER | rtl_op_start |
| 8 | stop | FUNCTION_POINTER | rtl_op_stop |
| 12 | add_interface | FUNCTION_POINTER | rtl_op_add_interface |
| 16 | change_interface | FUNCTION_POINTER | rtl_op_change_interface |
| 20 | remove_interface | FUNCTION_POINTER | rtl_op_remove_interface |
| 24 | config | FUNCTION_POINTER | rtl_op_config |
| 28 | bss_info_changed | FUNCTION_POINTER | rtl_op_bss_info_changed |
| 32 | start_ap | NULL |  |
| 36 | stop_ap | NULL |  |
| 40 | prepare_multicast | NULL |  |
| 44 | configure_filter | FUNCTION_POINTER | rtl_op_configure_filter |
| 48 | config_iface_filter | NULL |  |
| 52 | set_tim | NULL |  |
| 56 | set_key | FUNCTION_POINTER | rtl_op_set_key |
| 60 | update_tkip_key | NULL |  |
| 64 | set_rekey_data | NULL |  |
| 68 | set_default_unicast_key | NULL |  |
| 72 | hw_scan | NULL |  |
| 76 | cancel_hw_scan | NULL |  |
| 80 | sched_scan_start | NULL |  |
| 84 | sched_scan_stop | NULL |  |
| 88 | sw_scan_start | FUNCTION_POINTER | rtl_op_sw_scan_start |
| 92 | sw_scan_complete | FUNCTION_POINTER | rtl_op_sw_scan_complete |
| 96 | get_stats | NULL |  |
| 100 | get_key_seq | NULL |  |
| 104 | set_frag_threshold | NULL |  |
| 108 | set_rts_threshold | NULL |  |
| 112 | sta_add | FUNCTION_POINTER | rtl_op_sta_add |
| 116 | sta_remove | FUNCTION_POINTER | rtl_op_sta_remove |
| 120 | sta_notify | FUNCTION_POINTER | rtl_op_sta_notify |
| 124 | sta_set_txpwr | NULL |  |
| 128 | sta_state | NULL |  |
| 132 | sta_pre_rcu_remove | NULL |  |
| 136 | sta_rc_update | NULL |  |
| 140 | sta_rate_tbl_update | NULL |  |
| 144 | sta_statistics | NULL |  |
| 148 | conf_tx | FUNCTION_POINTER | rtl_op_conf_tx |
| 152 | get_tsf | FUNCTION_POINTER | rtl_op_get_tsf |
| 156 | set_tsf | FUNCTION_POINTER | rtl_op_set_tsf |
| 160 | offset_tsf | NULL |  |
| 164 | reset_tsf | FUNCTION_POINTER | rtl_op_reset_tsf |
| 168 | tx_last_beacon | NULL |  |
| 172 | ampdu_action | FUNCTION_POINTER | rtl_op_ampdu_action |
| 176 | get_survey | NULL |  |
| 180 | rfkill_poll | FUNCTION_POINTER | rtl_op_rfkill_poll |
| 184 | set_coverage_class | NULL |  |
| 188 | flush | FUNCTION_POINTER | rtl_op_flush |
| 192 | channel_switch | NULL |  |
| 196 | set_antenna | NULL |  |
| 200 | get_antenna | NULL |  |
| 204 | remain_on_channel | NULL |  |
| 208 | cancel_remain_on_channel | NULL |  |
| 212 | set_ringparam | NULL |  |
| 216 | get_ringparam | NULL |  |
| 220 | tx_frames_pending | NULL |  |
| 224 | set_bitrate_mask | NULL |  |
| 228 | event_callback | NULL |  |
| 232 | allow_buffered_frames | NULL |  |
| 236 | release_buffered_frames | NULL |  |
| 240 | get_et_sset_count | NULL |  |
| 244 | get_et_stats | NULL |  |
| 248 | get_et_strings | NULL |  |
| 252 | mgd_prepare_tx | NULL |  |
| 256 | mgd_protect_tdls_discover | NULL |  |
| 260 | add_chanctx | NULL |  |
| 264 | remove_chanctx | NULL |  |
| 268 | change_chanctx | NULL |  |
| 272 | assign_vif_chanctx | NULL |  |
| 276 | unassign_vif_chanctx | NULL |  |
| 280 | switch_vif_chanctx | NULL |  |
| 284 | reconfig_complete | NULL |  |
| 288 | ipv6_addr_change | NULL |  |
| 292 | channel_switch_beacon | NULL |  |
| 296 | pre_channel_switch | NULL |  |
| 300 | post_channel_switch | NULL |  |
| 304 | abort_channel_switch | NULL |  |
| 308 | channel_switch_rx_beacon | NULL |  |
| 312 | join_ibss | NULL |  |
| 316 | leave_ibss | NULL |  |
| 320 | get_expected_throughput | NULL |  |
| 324 | get_txpower | NULL |  |
| 328 | tdls_channel_switch | NULL |  |
| 332 | tdls_cancel_channel_switch | NULL |  |
| 336 | tdls_recv_channel_switch | NULL |  |
| 340 | wake_tx_queue | NULL |  |
| 344 | sync_rx_queues | NULL |  |
| 348 | start_nan | NULL |  |
| 352 | stop_nan | NULL |  |
| 356 | nan_change_conf | NULL |  |
| 360 | add_nan_func | NULL |  |
| 364 | del_nan_func | NULL |  |
| 368 | can_aggregate_in_amsdu | NULL |  |
| 372 | get_ftm_responder_stats | NULL |  |
| 376 | start_pmsr | NULL |  |
| 380 | abort_pmsr | NULL |  |
| 384 | set_tid_config | NULL |  |
| 388 | reset_tid_config | NULL |  |
| 392 | update_vif_offload | NULL |  |
| 396 | sta_set_4addr | NULL |  |

## rtlwifi: rtl_rate_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | capa | NULL |  |
| 4 | name | DATA_POINTER | .rodata.str1.4+0x994 |
| 8 | alloc | FUNCTION_POINTER | rtl_rate_alloc |
| 12 | add_debugfs | NULL |  |
| 16 | free | FUNCTION_POINTER | rtl_rate_free |
| 20 | alloc_sta | FUNCTION_POINTER | rtl_rate_alloc_sta |
| 24 | rate_init | FUNCTION_POINTER | rtl_rate_init |
| 28 | rate_update | FUNCTION_POINTER | rtl_rate_update |
| 32 | free_sta | FUNCTION_POINTER | rtl_rate_free_sta |
| 36 | tx_status_ext | NULL |  |
| 40 | tx_status | FUNCTION_POINTER | rtl_tx_status |
| 44 | get_rate | FUNCTION_POINTER | rtl_get_rate |
| 48 | add_sta_debugfs | NULL |  |
| 52 | get_expected_throughput | NULL |  |

## rtlwifi: efuse_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | efuse_onebyte_read | FUNCTION_POINTER | efuse_one_byte_read |
| 4 | efuse_logical_map_read | FUNCTION_POINTER | efuse_shadow_read |

## rtl_pci: rtl_pci_ops

| Offset | Campo | Clase | Destino de relocación |
|---:|---|---|---|
| 0 | read_efuse_byte | FUNCTION_POINTER | read_efuse_byte |
| 4 | adapter_start | FUNCTION_POINTER | rtl_pci_start |
| 8 | adapter_stop | FUNCTION_POINTER | rtl_pci_stop |
| 12 | adapter_tx | FUNCTION_POINTER | rtl_pci_tx |
| 16 | flush | FUNCTION_POINTER | rtl_pci_flush |
| 20 | reset_trx_ring | FUNCTION_POINTER | rtl_pci_reset_trx_ring |
| 24 | waitq_insert | FUNCTION_POINTER | rtl_pci_tx_chk_waitq_insert |
| 28 | disable_aspm | FUNCTION_POINTER | rtl_pci_disable_aspm |
| 32 | enable_aspm | FUNCTION_POINTER | rtl_pci_enable_aspm |

## Límites

- Symbol/relocation inventory is not source recovery or behavioral equivalence.
- Definition matches are lexical availability evidence only.
- NULL callback slots are real compiled absence, not missing functions.
- ET_REL offsets are section-relative, not physical or runtime addresses.
- Three core modules only; mac80211/cfg80211/crypto/btcoexist and firmware are separate dependencies.
- Physical client, traffic, boot, recovery, soak and release gates unrun.
