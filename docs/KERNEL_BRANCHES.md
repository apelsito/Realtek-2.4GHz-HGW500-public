# Ramas del driver Realtek HGW500

Objetivo acordado el 22 de octubre de 2026: conservar las fuentes originales,
mantener la reconstrucción Linux 5.10 y trabajar directamente hacia Linux 7.3.

| Rama | Referencia | Estado |
| --- | --- | --- |
| `main` | Repo de reconstrucción existente | Conservada; no se reescribe ni se mueve |
| `reference/original-linux-5.10` | `c544c9f`, primer import con fuentes originales | Referencia histórica; `original/` conserva bytes upstream y del overlay |
| `linux/5.10.260` | `149bf5abd887a33264b9dc6f431c4820d2f3d052` | Base exacta F363 de los cuatro módulos; evidencia portable de doble compilación |
| `port/linux-7.3` | Derivada de la base exacta | BASIC y EthernetRAM físicos aceptados; ping y12/12UDPeth0; segundo conector, radios y persistencia pendientes |

`reference/original-linux-5.10` no es el módulo OEM `rtl8192cd` de Linux
2.6.35.12. Es el import original disponible de rtlwifi/RTL8192EE upstream 5.10
y el overlay conservado. Los originales de todas las ramas permanecen en
`original/`. Los futuros cambios se realizan en `src/linux-7.3/`.

## Kernel objetivo fijado

- Repositorio upstream: `torvalds/linux`.
- Release: `v7.3`, publicada el 18 de octubre de 2026.
- Objeto tag: `091b06388b117fefdcb63336ac09956a4914b961`.
- Commit: `c03c1a14507dfaf8b856c2608f9ac216021fc222`.
- `src/linux-7.3-upstream-verified/`: 87 archivos de referencia, verificados
  por identidad del blob Git y SHA-256; subconjunto del driver y APIs/plataforma.
- `src/linux-7.3/`: 68 archivos del driver y licencias, inicialmente idénticos
  al upstream fijado. Requieren transportar las correcciones HGW.

El repositorio conserva el driver Realtek y añade en `kernel/basic-linux-7.3/`
la fase inicial de plataforma UART. El kernel básico se ha construido de forma
reproducible y arrancó físicamente por RAM; no se incluyen binarios. El contexto
F363 solo pertenece al driver 5.10, no a la compilación del kernel nuevo.

El objetivo inmediato acordado es llegar a una consola UART con Linux 7.3:
CPU750D, MMUv2, caché, RAM, IRQ, timers e initramfs. Los drivers se retoman
después de aceptar ese arranque. La imagen RAM seleccionada sin compresión mide
1966400 bytes y tiene SHA256
`24a085a69296c7f8c31dc587a231231750f66928b3480ff777f0d741aa48fbfb`.
Véase `kernel/basic-linux-7.3/OFFLINE_RESULT.json` para los hashes de kernel,
DT y configuración. `kernel/basic-linux-7.3/PHYSICAL_BOOT_RESULT.json` acredita
boot e input UART, tick y memtest de 1 MiB. Retorno manual, persistencia y
drivers permanecen pendientes.

## Evidencia de conservación

Comprobaciones de esta rama:

- 625 archivos de los manifiestos originales, baseline y contexto verificados.
- 79 archivos y 3630 comentarios originales comprobados por rangos de byte.
- 16 pruebas existentes de las herramientas: PASS.
- Los 54 objetos y ocho módulos de las dos compilaciones portables retenidas
  coinciden ahora con sus hashes de referencia. Esta comprobación vuelve a
  leer los resultados existentes; no presenta una compilación nueva.
- 66 archivos del driver comparados: 11 difieren entre upstream 5.10 y HGW
  5.10; 34 difieren entre upstream 5.10 y upstream 7.3.
- 224 líneas de anclajes DMA/IRQ/TXBD/mac80211 registradas para el port.

Los patches en `evidence/port-linux-7.3/` son diferencias para revisión.
No constituyen una serie aplicable a 7.3 ni un cambio validado de runtime.

## Requisitos antes de una compilación candidata HGW

El perfil retenido del kernel F358 usa ARC750D, MMUv2, páginas de 8 KiB,
sin LL/SC y sin SWAPE. Linux upstream retiró ARC750 y MMUv1/v2 en la serie
integrada en 5.15. El Kconfig 7.3 ofrece MMUv3 para ARCompact y el Makefile
incluye `-mswape`; seleccionar `ARCH=arc` no restaura el hardware anterior.

1. Recuperar y adaptar ARC750D/MMUv2, bits PTE/TLB, invalidación uTLB y caché.
2. Recuperar alternativas sin SWAPE y el contrato de atomics sin LL/SC.
3. Construir una plataforma Topaz con DT, reservas RAM, IRQ y host PCIe correctos.
4. Portar las 11 diferencias HGW a las APIs y estructuras 7.3. Por ejemplo,
   upstream añade el argumento link-id a `ieee80211_beacon_get`.
5. Generar el nuevo contexto/configuración/headers y construir el driver desde
   cero. Los módulos 5.10 no se pueden reutilizar como módulos 7.3.
6. Comprobar DMA32/TXBD, publicación/readback, INTx, RX diferido y ciclo de vida.
7. Pasar las puertas físicas independientes de cliente, tráfico, persistencia
   y recuperación mediante una campaña específica autorizada fuera de este repo.

La reconstrucción exacta del driver 5.10 está conseguida. El árbol completo
parcheado F358 permanece sin recuperar; es un problema distinto del driver.

## Comandos offline

```powershell
python scripts/verify_original_sources.py
python scripts/extract_original_comments.py --check
python -m unittest discover -s tests -v
python scripts/prepare_kernel_port.py --verify-only
```

`import_kernel_target.py` requiere gh autenticado para leer GitHub y escribe
solo en un directorio de destino ausente. Las descargas son blobs fijados al
commit, sin ejecutar código. `prepare_kernel_port.py` crea un árbol de trabajo
nuevo y las diferencias iniciales. `--verify-only` comprueba que el árbol de
trabajo conserva esa referencia inicial; tras cambiarlo deberá producirse
evidencia nueva de los parches, no actualizar este resultado retrospectivamente.

## Fuentes upstream

- https://www.kernel.org/
- https://github.com/torvalds/linux/tree/v7.3
- https://github.com/torvalds/linux/commit/288ff7de62af0936353c9394de9d0b2c6dd22c80
- https://github.com/torvalds/linux/commit/767a697e75769fdae092a15d92bf562d5631a490
- https://github.com/torvalds/linux/blob/v7.3/arch/arc/Kconfig
- https://github.com/torvalds/linux/blob/v7.3/arch/arc/Makefile
