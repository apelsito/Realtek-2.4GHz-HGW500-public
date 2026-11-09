# Preserved component notes

Editorial copy of the previous README. Workstation paths are normalized; original source and immutable evidence are not modified. Earlier status claims belong to their named checkpoints, not the live device. Start with the current [README](../README.md).

# Realtek 2.4 GHz HGW500

**Estado de referencia comprobado el 8 de noviembre de 2026.** La fuente de
los cuatro módulos Realtek de Foundation R3 es
`src/combined-memory-rx-20261105/`, composición de R9/R11 con el contrato de
finalización DMA. Sus 93 archivos conservan los hashes del manifiesto; los
66 archivos del overlay coinciden con el recibo del par ARC R51 y los cuatro
módulos coinciden con el manifiesto de la imagen R3. La receta y los recibos
están en [la guía del checkout](../docs/ROOT_WORKSPACE_20261103.md).

Foundation R3 es la última instalación acreditada por los recibos HGW500 del
6 de noviembre; Core Boot R1 + Quantenna R39 queda como rollback. Esos gates
pertenecen a sus imágenes exactas. R3 tiene prueba RAM de gestión, arranque
desde flash y doble readback completo; faltan coldboot específico, tráfico
por ambos puertos y carga prolongada. El 7 de noviembre se perdió el acceso
al router tras una lectura que coincidía con kernel/PID1 de R3: el estado
físico actual necesita una consulta nueva. Los resultados R2–R8 y 5.10 que
siguen son antecedentes de sus propias revisiones.

Checkout actual en la raíz OpenMitraStar. Las fuentes vigentes, la procedencia del traslado y las cuatro fixtures verificadas desde esta carpeta están en [organización del 3 de noviembre](../docs/ROOT_WORKSPACE_20261103.md).

R6 y R7 tienen ensayos en RAM con selección automática de tasa y tráfico del
móvil al PC por Ethernet. R7 reúne además 61.440 casos diferenciales de la
preparación del descriptor TX. R8 corrige la inicialización del BSSID en modo
AP y tiene dos builds ARC coincidentes. La comparación física continúa con
repeticiones de carga. El alcance de cada revisión y los primeros resultados
están en R5–R8 y mediciones (`docs/LINUX73_R5_R8_20261104.md`; maintainer-workspace reference).

El candidato R4 corrige la publicación de descriptores TX cuando falla DMA,
reduce las consultas del árbol de dispositivos en RX/TX y permite ensayar la
tasa del móvil en RAM. Se han reproducido los cuatro módulos y la imagen en
dos builds ARC. Fuentes y pruebas de R4 (`docs/LINUX73_R4_20261104.md`; maintainer-workspace reference).

El 4 de noviembre la integración HGW500 arrancó en RAM la revisión
`rtl8192ee-basic-contracts-r2-20261103` sobre Linux 7.3 con microfirmware 35.7.
Los cuatro módulos cargaron, el móvil se asoció al AP de 2,4 GHz y los
contadores de la estación avanzaron en ambos sentidos. El recibo está en
`HGW500/out/rtl357-driver-20261104/physical-summary.json` en el workspace.
En aquel corte, la flash contenía la 35.7 con el driver original de Core Boot R1.
Las mediciones posteriores de R6 y R7 figuran en el hito enlazado al inicio.

La revisión posterior `rtl8192ee-rx-telemetry-r3-20261104` modifica sólo
`rtl_pci.ko`. El worker de recepción evita leer el registro de la cola PCIe
cuando la traza no consume su valor. La fixture `scripts/test_linux73_rx_work.py`
contrastó 2.340 pares de ejecuciones de los cuerpos C de R2 y R3. La integración
arrancó R3 en RAM con la 35.7 y verificó el AP en canal 1. El mismo móvil
respondió a 400/400 pings con R3 y a 374/400 con R2. El tráfico de fondo
varió entre tandas. Mediciones en
`HGW500/out/rtl357-rx-telemetry-20261104/physical-summary.json`.

La revisión posterior corrige la validación de claves y limita el ancho TX/SGI
al canal y al cliente. Ver contratos básicos y comprobaciones (`docs/LINUX73_BASIC_CONTRACTS_20261103.md`; maintainer-workspace reference),
con pruebas negativas sobre las fuentes anteriores y límites CAM pendientes.

El 3 de noviembre se preparó un candidato sobre las fuentes de Core Boot R1
con correcciones de descarga, RX/DMA, reservas parciales y mensajes de firmware.
Cuatro módulos construidos por duplicado y pruebas de los cuerpos C con
sanitizers correctos. El análisis 8051 identifica también un microfirmware
público 35.7. Ver [candidato y reproducción](../docs/LINUX73_DRIVER_CANDIDATE_20261103.md)
para cambios, evidencias y alcance de aceptación.

Esta rama prepara el port directo a **Linux 7.3**. La reconstrucción exacta
Linux 5.10 se conserva en `linux/5.10.260`; el import inicial en
`reference/original-linux-5.10`; `main` conserva el repositorio anterior.
Véase [ramas y estado del port](../docs/KERNEL_BRANCHES.md).

`src/linux-7.3-upstream-verified/` fija la referencia upstream por commit y
hashes. `src/linux-7.3/` conserva el primer arbol de referencia. El port HGW compilado
esta en `kernel/radio2g-linux-7.3-v1/`: kernel y 18 modulos construidos en dos
salidas independientes identicas, imports resueltos y checks ARC aprobados.
El kernel BASIC y Ethernet ya tienen aceptacion fisica en RAM. La primera
revisión de Realtek 7.3 alcanzó la aceptación offline descrita en ese hito.
Vease [estado de radio2g y Ethernet v3](../docs/LINUX73_RADIO2G_OFFLINE_V1.md).

El primer hito se ha limitado al **arranque básico por UART**. En
[`kernel/basic-linux-7.3/`](../kernel/basic-linux-7.3/README.md) están los parches,
las fuentes y la receta del kernel mínimo: dos compilaciones completas
idénticas, MMU v2, caché, temporizadores, IRQ y consola. El 22 de octubre
se aceptó el arranque físico, nonce UART, avance del tick y memtest de 1 MiB.
El kernel queda en RAM; esta imagen no integra Realtek, Quantenna o Ethernet.

La siguiente fase tiene ya [kernel y módulo Ethernet compilados dos veces](../docs/LINUX73_ETHERNET_OFFLINE_V1.md),
con bytes idénticos y pruebas de lifecycle/RX ante timeout. Las fuentes y
recetas están en `kernel/ethernet-linux-7.3-v1/`. DT desactivado, módulo
separado en esa primera variante offline. Una imagen RAM posterior ya tiene
[aceptación física de boot, driver y tráfico eth0](../docs/LINUX73_ETHERNET_PHYSICAL_BOOT.md):
ping y12/12ecosUDP, apertura/cierre deeth0/eth1 y reaperturaeth0. Sin flash
ni bootenv; kernelRAM. Segundo conector, soak, radios y persistencia pendientes.

Reconstrucción documentada del driver de **2,4 GHz Realtek RTL8192EE** para el MitraStar HGW-500BNA-QCv2 A2, ARC700 y Linux `5.10.260-openmitrastar-radiohw`.

Repositorio privado: `apelsito/Realtek-2.4GHz-HGW500`. Equipo: HGW-500BNA-QCv2 A2.

El repositorio conserva las fuentes originales, los cambios del port, las operaciones recuperadas desde los módulos y las herramientas de comprobación offline. **Reconstrucción exacta offline conseguida:** 27 unidades y cuatro módulos se han compilado dos veces, con SHA-256 idéntico a la referencia. Una compilación o un análisis estático no certifican asociación, tráfico ni aceptación del firmware en el equipo físico.

## Estructura

| Carpeta | Contenido |
|---|---|
| `original/linux-5.10.260/` | Subconjunto upstream original: rtlwifi, RTL8192EE, btcoexist y API mac80211 |
| `original/port-overlay/` | Fuentes disponibles del port antes de esta reconstrucción, conservadas byte a byte |
| `original/kernel-api/` | Cabeceras originales necesarias para identificar las tablas y sus offsets |
| `src/overlay/` | Receta y cambios necesarios para reconstruir el árbol del driver |
| `src/baseline-exact/` | Fuentes que reconstruyen exactamente los cuatro módulos de referencia |
| `build-context/f363/` | Cabeceras y contexto mínimo de compilación; no contiene objetos ni módulos heredados |
| `scripts/` | Importación, conservación de comentarios, inventario de ops, reconstrucción y REA |
| `tests/` | Pruebas offline de las herramientas |
| `docs/` | Documentación, comentarios originales y límites de verificación |
| `evidence/` | Manifiestos, hashes y resultados; fuentes y binarios de referencia se distinguen |
| `.work/` | Compilaciones y ELF de análisis locales; excluidos de Git |

## Comentarios originales

[`docs/ORIGINAL_COMMENTS.md`](../docs/ORIGINAL_COMMENTS.md) contiene **todos los comentarios literales** de los archivos C, cabeceras, Makefile y Kconfig importados en `original/`, con sus archivos y líneas. El índice [`evidence/original-comments.json`](../evidence/original-comments.json) conserva también offsets de byte y hashes.

Los comentarios originales proceden de fuentes disponibles. Los binarios compilados no retienen comentarios; el pseudocódigo generado por REA se conserva separado y no se presenta como código original.

```powershell
python scripts/extract_original_comments.py --check
python scripts/verify_original_sources.py
python -m unittest discover -s tests -v
```

## Referencia del driver

Referencia extraída previamente de la imagen F367r9 y contrastada con el contexto F363 retenido:

| Módulo | Bytes | SHA-256 |
|---|---:|---|
| `rtl8192ee.ko` | 102736 | `f014ad53084e1eb3cf7a9083913388ac907f0d254478dd63b0bc9ca054394e85` |
| `rtl_pci.ko` | 45680 | `6f85efa424c6aa5b693982ae074d268d2312a3f9262238e8c6f5eda16199df63` |
| `rtlwifi.ko` | 77412 | `9b7988816abb5065cd5a2a39defba608d073646aac15c75e244ac5cd95e096ee` |

Estos tres módulos suman 225828 bytes, 370 símbolos de función definidos y 2326 relocaciones RELA. Los binarios originales se mantienen fuera de Git. La pila completa incluye mac80211, cfg80211, btcoexist y módulos criptográficos: este inventario no atribuye todo ese código al módulo RTL8192EE.

## Reconstrucción

El archivo upstream Linux 5.10.260 está fijado por SHA-256 `47a8297131505b7d38338d39ad8a9d592507d33c695b27b1bbe55f25869a6b84`. `scripts/import_original_sources.py` extrae únicamente el subconjunto declarado y comprueba su identidad.

`scripts/reconstruct_baseline.py --help` describe los insumos explícitos: archivo upstream, contexto de compilación histórico retenido y prefijo del compilador ARC. Trabaja en directorios nuevos, realiza dos compilaciones y compara unidades con los objetos de referencia. El árbol completo del kernel F358 con sus parches no está recuperado; los resultados informan por separado si las unidades del driver son idénticas y si quedan diferencias.

El contexto mínimo está en `build-context/f363/`. La evidencia [`evidence/reconstruction-exact-paired.json`](../evidence/reconstruction-exact-paired.json) conserva los hashes de ambas compilaciones y la comparación exacta. Véase [`docs/RECONSTRUCTION.md`](../docs/RECONSTRUCTION.md) para reproducirlo con el archivo upstream y el toolchain ARC fijados.

REA recorrió 370 símbolos de función, equivalentes a 366 entradas únicas, con pseudocódigo y ensamblador conservados. Las tablas de ops contienen 91 callbacks poblados; el registro de timers, trabajo diferido, tasklets, IRQ e IO añade 20 destinos distintos. Esos inventarios documentan operaciones concretas. La recuperación exacta del binario se acredita por compilación y hashes, de forma independiente de las limitaciones del pseudocódigo REA.

## Alcance y conservación

Los scripts del repositorio trabajan offline. No acceden al router, UART, radio, TFTP ni flash. Los ELF derivados para REA son exclusivamente de análisis y no pueden cargarse ni empaquetarse como firmware.

Este repositorio no contiene firmware OEM, imágenes personalizadas del equipo, dumps de particiones, calibración, contraseñas, PSK o claves privadas. La autorización para reconstrucción y publicación privada no sustituye a los requisitos de instalación y aceptación física.

## Licencias y procedencia

Las fuentes Linux conservan sus avisos SPDX y copyright. Véase [`NOTICE.md`](../NOTICE.md), el `COPYING` original y `LICENSES/preferred/GPL-2.0`. Los hashes y la procedencia están en los manifiestos de `original/`. Los componentes de procedencia distinta mantienen sus avisos propios.

## Arquitectura de procesamiento del HGW500

El [esquema y sus evidencias](../docs/HARDWARE_ARCHITECTURE.md), conservados el
3 de noviembre de 2026, identifican una CPU LHost ARC750 a 500 MHz y cuatro
coprocesadores: MuC, AuC, DSP y la MCU 8051 del RTL8192EE. Incluyen el inventario
SPI NOR de 16 MiB y el perfil DDR3 OEM de 128 MiB, con fuentes y límites.

![Arquitectura de procesamiento del HGW500](../docs/hardware/hgw500-processing-architecture.png)

El diagrama es una vista conceptual. La etiqueta qdrv describe el papel del
host; los gates de 5 GHz corresponden a la revisión de firmware indicada en
el estado HGW500, no al diagrama.
