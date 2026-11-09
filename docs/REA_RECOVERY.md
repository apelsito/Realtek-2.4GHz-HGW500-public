# Recuperación estática REA del driver Realtek RTL8192EE

El 22 de octubre de 2026 se han exportado las **370 funciones con símbolo de
código** de los tres módulos registrados: 156 de `rtl8192ee`, 47 de `rtl_pci` y
167 de `rtlwifi`. Hay 366 entradas únicas porque cuatro símbolos son alias. Cada
entrada tiene un dossier REA comprimido, pseudocódigo y ensamblador. Todos los
SHA-256 de estos 1.098 archivos se han comprobado y no hay fallos de exportación.

Esto completa el inventario conocido y la extracción estática. Posteriormente
la reconstrucción desde fuentes ha producido **los cuatro módulos idénticos
byte a byte en dos compilaciones**, según
[`reconstruction-exact-paired.json`](../evidence/reconstruction-exact-paired.json).
Ese resultado es independiente de la calidad del pseudocódigo: la semántica
inferida por REA conserva las limitaciones descritas abajo. El pseudocódigo está
en `evidence/rea/`, separado del código fuente compilable.

## Entradas y procedencia

Se han usado exclusivamente los archivos locales registrados en
`outputs/rea/arc700-20261021-r2/current-radio2g/manifest.json` del proyecto padre:

| Módulo | Bytes | SHA-256 | Símbolos | Entradas únicas | Con avisos |
|---|---:|---|---:|---:|---:|
| rtl8192ee.ko | 102736 | f014ad53084e1eb3cf7a9083913388ac907f0d254478dd63b0bc9ca054394e85 | 156 | 154 | 60 |
| rtl_pci.ko | 45680 | 6f85efa424c6aa5b693982ae074d268d2312a3f9262238e8c6f5eda16199df63 | 47 | 47 | 15 |
| rtlwifi.ko | 77412 | 9b7988816abb5065cd5a2a39defba608d073646aac15c75e244ac5cd95e096ee | 167 | 165 | 55 |

Los módulos originales no han cambiado. El enlace crea únicamente derivados
`ANALYSIS_ONLY-NOT_FIRMWARE.elf`: aplica relocaciones internas y asigna direcciones
sintéticas a símbolos externos para que se conserven sus nombres. Estos ELF no
son módulos instalables ni firmware y nunca deben cargarse o grabarse.

Se reutilizó el laboratorio aislado REA 6.7.0/Ghidra 12.1.4 con lenguaje
`ARCompact:LE:32:default`. Es una adaptación local ARC700, con sus hashes en el
manifiesto del laboratorio, y no soporte ARC700 certificado por upstream. Cada
módulo se importó una sola vez y las funciones se solicitaron secuencialmente al
bridge autenticado de REA. No se cambió la instalación de REA ni Codex.

La ejecución real registrada duró aproximadamente **80 segundos**, de
13:12:31 a 13:13:51 UTC, 15:12:31 a 15:13:51 en Madrid. Los nombres de directorio
fueron etiquetas escogidas antes del proceso; la hora efectiva es la de
`result.json`, no el texto del nombre del directorio.

## Evidencia exportable

- [Manifiesto de exportación saneada](../evidence/rea/public-export-20261022T132100Z-r2/manifest.json).
- [Auditoría de inventario y hashes](../evidence/rea/public-export-20261022T132100Z-r2/coverage-audit.json).
- [CSV por función](../evidence/rea/public-export-20261022T132100Z-r2/functions.csv).
- [Reconciliación con fuentes de los 25 casos](../evidence/rea/public-export-20261022T132100Z-r2/source-reconciliation.json).
- [Inventario de callbacks desde símbolos y relocaciones](../evidence/ops-20261022T131600Z/OPS.md).

El export permitido contiene 1.104 archivos y 7.366.373 bytes: 366 dossiers,
366 pseudocódigos, 366 ensambladores, tres resultados de módulos y tres informes.
Su manifiesto fija SHA-256/bytes por archivo y la procedencia de cada copia.
Las rutas privadas se sustituyen recursivamente y se buscan literales MAC,
credenciales y rutas privadas. No se detectó ningún literal que exigiera omitir
campos. Los dossiers `.json.gz` contienen la respuesta del bridge y la respuesta
normalizada con referencias, CFG, declaraciones inferidas, ensamblador y
high-pcode; los `.c` incluyen un aviso explícito de pseudocódigo.

Los manifiestos de enlace, ELF derivados, direcciones sintéticas, GNU `objdump`,
listas Ghidra, logs y sesiones quedan únicamente en la evidencia raw local.
No están en el allowlist exportable. No deben subirse por incluirlos en un
`git add` indiscriminado del directorio de evidencia.

La primera ejecución fallida se ha conservado en
`current-radio2g-20261022T143500Z`: documenta la necesidad de proporcionar el owner
de recursos al API interno y de seleccionar `rtl_pci_probe` como entrada del
enlace `rtl_pci`, que no define `init_module`. No es el resultado válido.

## Límites medidos y trabajo restante

La auditoría compara los inicios de instrucciones GNU ARC con Ghidra sobre las
extensiones exactas de los símbolos ELF. Ha encontrado:

- 130 entradas con avisos o artefactos visibles de decompilación.
- 25 funciones con inicios GNU ausentes en el cuerpo Ghidra; también son las 25
  con tamaño de cuerpo distinto del símbolo ELF.
- 14 funciones con inicios de instrucción Ghidra que no coinciden con GNU.
- 182 entradas con llamadas indirectas que Ghidra no resuelve completamente.
- `rtl_pci_probe` con high-pcode truncado; su pseudocódigo y ensamblador completos
  sí se conservaron como representaciones observadas.

Algunas diferencias pueden corresponder a alineación, terminaciones o límites de
función inferidos, pero otras son grandes. `rtl92ee_set_hw_reg` omite 124 bytes de
extensión de símbolo y `phy_set_txpower_index_by_rate_array` omite 192 bytes. No
se han clasificado esos huecos como inocuos. El CSV permite priorizar los casos.

Un ejemplo visible de limitación de ABI es `rtl92ee_interrupt_recognized`: GNU y
Ghidra muestran llamadas a `rtl_write_dword` con el valor preparado en `r2`, pero
el pseudocódigo infiere una firma de dos argumentos y pierde ese parámetro. La
cola salta a `rtl_write_dword`; Ghidra la expande y añade avisos de salto indirecto.
Copiar ese pseudocódigo como C funcional reproduciría una firma incorrecta.

Las **25 funciones con diferencias tienen definición completa en las fuentes
conservadas**. El informe de reconciliación fija la ruta relativa, SHA-256 y
primera línea del identificador. Por ejemplo, `rtl92ee_set_hw_reg` está en
`original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:407` y
`phy_set_txpower_index_by_rate_array` en `rtl8192ee/phy.c:1514` del mismo árbol.
`rtl_pci_probe` tiene fuente original `pci.c:2072` y overlay `pci.c:2991`.
Por tanto, la reconstrucción de esos casos dispone de C fuente y no necesita
inventar lógica a partir del pseudocódigo defectuoso. Encontrar la definición
no demuestra que el binario actual provenga de esa revisión exacta.

La reconstrucción desde las fuentes y los parches conservados ha cerrado la
identidad del artefacto del driver con el compilador ARC fijado. Las tablas y los
registros de callbacks se documentan por separado; el kernel histórico completo
sigue fuera de ese resultado. Los tests de comportamiento y la aceptación
física son gates distintos. Esta extracción no carga el driver,
accede al router, modifica radio, abre UART, flashea ni prueba clientes/tráfico.

## Reproducción

La extracción se ejecuta desde la distribución WSL existente `REA-Linux` con
`python3 scripts/recover_current_radio2g.py --workspace RUTA_PROYECTO_PADRE
--lab RUTA_LAB_AISLADO --output NUEVO_DIRECTORIO`. El workspace padre necesita
sus tres módulos exactos, `tools/link_arc700_analysis_image.py` y el toolchain
ARC fijado. No se instala nada ni se buscan fuentes o paquetes por internet.

La auditoría se reproduce con `python3 scripts/audit_rea_coverage.py --input
DIRECTORIO_EXPORTACION --output NUEVO_DIRECTORIO_AUDITORIA`. Ambos comandos
exigen salida nueva y no sustituyen resultados anteriores. Los scripts no
certifican que la semántica ARC700 del decompilador sea correcta.

`scripts/export_rea_public.py` crea el export derivado mediante allowlist,
con rutas privadas sustituidas y un manifiesto de hashes. Su salida se comprueba
de nuevo con `python3 scripts/verify_rea_public_export.py --input
DIRECTORIO_EXPORT_SANEADO --output NUEVO_RESULTADO.json`. Esta segunda lectura
ha dado PASS para los 1.104 archivos, sin archivos inesperados, literales
sensibles ni formatos binarios excluidos.
