# Registro de callbacks Realtek: fuente y ELF

21 sitios de setup fuente; 20 destinos dinámicos distintos; 20 sitios con materialización de dirección compilada.

| Módulo | Tipo | API/campo | Callback | Fuente | Evidencia ELF |
|---|---|---|---|---|---|
| rtlwifi | TIMER | timer_setup | rtl_watch_dog_timer_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:453 | .text+0x15b6 (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_watchdog_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:460 | .text+0x15f2 (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_ips_nic_off_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:462 | .text+0x1628 (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_swlps_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:464 | .text+0x165e (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_swlps_rfon_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:465 | .text+0x1694 (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_fwevt_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:467 | .text+0x16ca (rtl_init_core) |
| rtlwifi | DELAYED_WORK | INIT_DELAYED_WORK | rtl_c2hcmd_wq_callback | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:468 | .text+0x1700 (rtl_init_core) |
| rtlwifi | REGULATORY_NOTIFIER | rtl_regd_init | rtl_reg_notifier | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:540 | .text+0x1432 (rtl_init_core) |
| rtl_pci | WORK | INIT_WORK | rtl_lps_change_work_callback | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:1810 | .text.unlikely+0xcca (rtl_pci_probe) |
| rtl_pci | DELAYED_WORK | INIT_DELAYED_WORK | _rtl_pci_rx_work | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:1809 | .text.unlikely+0xca6 (rtl_pci_probe) |
| rtl_pci | TASKLET | tasklet_setup | _rtl_pci_irq_tasklet | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:1806 | .text.unlikely+0xc58 (rtl_pci_probe) |
| rtl_pci | TASKLET | tasklet_setup | _rtl_pci_prepare_bcn_tasklet | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:1807 | .text.unlikely+0xc6c (rtl_pci_probe) |
| rtl_pci | IRQ | request_irq | _rtl_pci_interrupt | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:2908 | .text.unlikely+0x112 (rtl_pci_intr_mode_legacy) |
| rtl_pci | IRQ | request_irq | _rtl_pci_interrupt | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:2934 | .text.unlikely+0x112 (rtl_pci_intr_mode_legacy) |
| rtl_pci | IO_FUNCTION_POINTER | io.write8_async | pci_write8_async | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:641 | .text.unlikely+0x788 (rtl_pci_probe) |
| rtl_pci | IO_FUNCTION_POINTER | io.write16_async | pci_write16_async | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:642 | .text.unlikely+0x790 (rtl_pci_probe) |
| rtl_pci | IO_FUNCTION_POINTER | io.write32_async | pci_write32_async | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:643 | .text.unlikely+0x798 (rtl_pci_probe) |
| rtl_pci | IO_FUNCTION_POINTER | io.read8_sync | pci_read8_sync | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:645 | .text.unlikely+0x7a0 (rtl_pci_probe) |
| rtl_pci | IO_FUNCTION_POINTER | io.read16_sync | pci_read16_sync | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:646 | .text.unlikely+0x7a8 (rtl_pci_probe) |
| rtl_pci | IO_FUNCTION_POINTER | io.read32_sync | pci_read32_sync | src/overlay/files/drivers/net/wireless/realtek/rtlwifi/pci.c:647 | .text.unlikely+0x7b0 (rtl_pci_probe) |
| rtl8192ee | ASYNC_FIRMWARE | request_firmware_nowait | rtl_fw_cb | original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:153 | .text+0x8b72 (rtl92ee_init_sw_vars) |

## Clasificación de todas las referencias estáticas

| Módulo | Tablas callback | Lifecycle módulo | Exports | Objetos param_ops importados |
|---|---:|---:|---:|---:|
| rtl8192ee | 50 | 2 | 0 | 25 |
| rtlwifi | 32 | 2 | 63 | 2 |
| rtl_pci | 9 | 0 | 2 | 12 |

## Cobertura léxica de valores de función

Se clasificaron 180 usos como valor de nombres de funciones ELF en los archivos fuente seleccionados: {'EXPORTED_SYMBOL': 65, 'DYNAMIC_REGISTRATION': 21, 'MODULE_LIFECYCLE': 2, 'STATIC_TABLE_INITIALIZER': 92}. Sin clasificar: 0.

La unión contiene 111 nombres distintos de callback: 91 de tablas estáticas y 20 registrados dinámicamente. Se añaden cuatro entradas lifecycle de módulo con alias.

El setup IRQ de MSI permanece en la fuente, pero no tiene función propietaria compilada ni su relocación: se marca eliminado en este build. El setup legacy sí está compilado.

## Layouts PCI y PM etiquetados

| Tabla | Offset | Campo | Clase | Destino |
|---|---:|---|---|---|
| rtlwifi_pm_ops | 0 | prepare | NULL |  |
| rtlwifi_pm_ops | 4 | complete | NULL |  |
| rtlwifi_pm_ops | 8 | suspend | NULL |  |
| rtlwifi_pm_ops | 12 | resume | NULL |  |
| rtlwifi_pm_ops | 16 | freeze | NULL |  |
| rtlwifi_pm_ops | 20 | thaw | NULL |  |
| rtlwifi_pm_ops | 24 | poweroff | NULL |  |
| rtlwifi_pm_ops | 28 | restore | NULL |  |
| rtlwifi_pm_ops | 32 | suspend_late | NULL |  |
| rtlwifi_pm_ops | 36 | resume_early | NULL |  |
| rtlwifi_pm_ops | 40 | freeze_late | NULL |  |
| rtlwifi_pm_ops | 44 | thaw_early | NULL |  |
| rtlwifi_pm_ops | 48 | poweroff_late | NULL |  |
| rtlwifi_pm_ops | 52 | restore_early | NULL |  |
| rtlwifi_pm_ops | 56 | suspend_noirq | NULL |  |
| rtlwifi_pm_ops | 60 | resume_noirq | NULL |  |
| rtlwifi_pm_ops | 64 | freeze_noirq | NULL |  |
| rtlwifi_pm_ops | 68 | thaw_noirq | NULL |  |
| rtlwifi_pm_ops | 72 | poweroff_noirq | NULL |  |
| rtlwifi_pm_ops | 76 | restore_noirq | NULL |  |
| rtlwifi_pm_ops | 80 | runtime_suspend | NULL |  |
| rtlwifi_pm_ops | 84 | runtime_resume | NULL |  |
| rtlwifi_pm_ops | 88 | runtime_idle | NULL |  |
| rtl92ee_driver | 0 | node.next | NULL |  |
| rtl92ee_driver | 4 | node.prev | NULL |  |
| rtl92ee_driver | 8 | name | DATA_POINTER | .rodata.str1.4+0x95c |
| rtl92ee_driver | 12 | id_table | DATA_POINTER | .rodata+0x1c0 |
| rtl92ee_driver | 16 | probe | FUNCTION_POINTER | rtl_pci_probe |
| rtl92ee_driver | 20 | remove | FUNCTION_POINTER | rtl_pci_disconnect |
| rtl92ee_driver | 24 | suspend | NULL |  |
| rtl92ee_driver | 28 | resume | NULL |  |
| rtl92ee_driver | 32 | shutdown | NULL |  |
| rtl92ee_driver | 36 | sriov_configure | NULL |  |
| rtl92ee_driver | 40 | err_handler | NULL |  |
| rtl92ee_driver | 44 | groups | NULL |  |
| rtl92ee_driver | 48 | driver.name | NULL |  |
| rtl92ee_driver | 52 | driver.bus | NULL |  |
| rtl92ee_driver | 56 | driver.owner | NULL |  |
| rtl92ee_driver | 60 | driver.mod_name | NULL |  |
| rtl92ee_driver | 64 | driver.suppress_bind_attrs_and_padding | NULL |  |
| rtl92ee_driver | 68 | driver.probe_type | NULL |  |
| rtl92ee_driver | 72 | driver.of_match_table | NULL |  |
| rtl92ee_driver | 76 | driver.acpi_match_table | NULL |  |
| rtl92ee_driver | 80 | driver.probe | NULL |  |
| rtl92ee_driver | 84 | driver.sync_state | NULL |  |
| rtl92ee_driver | 88 | driver.remove | NULL |  |
| rtl92ee_driver | 92 | driver.shutdown | NULL |  |
| rtl92ee_driver | 96 | driver.suspend | NULL |  |
| rtl92ee_driver | 100 | driver.resume | NULL |  |
| rtl92ee_driver | 104 | driver.groups | NULL |  |
| rtl92ee_driver | 108 | driver.dev_groups | NULL |  |
| rtl92ee_driver | 112 | driver.pm | DATA_POINTER | .rodata+0x108 |
| rtl92ee_driver | 116 | driver.coredump | NULL |  |
| rtl92ee_driver | 120 | driver.p | NULL |  |
| rtl92ee_driver | 124 | dynids.list.next | NULL |  |
| rtl92ee_driver | 128 | dynids.list.prev | NULL |  |

## Funciones cuyo nombre no demuestra registro

- `rtl92ee_fw_clk_off_timer_callback`: Present function and mod_timer users, but no timer setup/assigned reference found in selected compiled modules or available sources.
- `rtl_wowlan_fw_cb`: Exported firmware callback present; no request_firmware_nowait caller in these three selected modules.
- `rtl92ee_phy_set_bw_mode_callback`: Direct synchronous helper call from rtl92ee_phy_set_bw_mode, not registered callback.
- `rtl92ee_phy_sw_chnl_callback`: Direct synchronous helper call from rtl92ee_phy_sw_chnl, not registered callback.

## Límites

- Every noncode ELF relocation to a local function/import has been classified; imported STT_NOTYPE requires semantic classification.
- Dynamic setup search covers the selected PCI/common/rtl8192ee compilation source files and explicit APIs/IO assignments; not a general pointer dataflow proof.
- Address loads for direct calls are not automatically registrations.
- Original upstream+overlay availability does not prove exact compiled source reconstruction.
- No physical execution, traffic, radio, coldboot, recovery or release acceptance.
