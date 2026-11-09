# Reconstrucción de las fuentes del driver 2,4 GHz

El núcleo específico es RTL8192EE PCI (`10ec:818b`), acompañado por rtlwifi,
rtl_pci y btcoexist. El módulo OEM histórico rtl8192cd no es el módulo de
referencia instalado para Linux 5.10.260.

La referencia de comparación es el output F363 conservado, contrastado
anteriormente con la extracción F367r9. Esta reconstrucción no accede al equipo
físico y no convierte aquel contraste histórico en una observación nueva.

## Insumos

- Linux upstream 5.10.260, archivo SHA-256
  `47a8297131505b7d38338d39ad8a9d592507d33c695b27b1bbe55f25869a6b84`.
- Cinco archivos completos del overlay, conservados en `original/port-overlay`.
- Parches del port reconstruidos en `src/overlay/patches`.
- Cabecera GPL del ABI Quantenna que altera `sk_buff` y `net_device` en el kernel
  compartido. Es necesaria incluso para compilar el driver Realtek con el ABI
  de referencia. No contiene firmware ni calibración.
- Cabeceras generadas, configuración y archivos `.cmd` del output F363.
- Compilador ARC700 GCC 15.2.0 del toolchain ARC 2026.03.
- Para el enlace final, fuentes `.mod.c` y `scripts/module.lds` conservadas del
  contexto F363. Se recompila `.mod.c`; no se reutiliza el binario `.mod.o`.

El kernel F358 histórico completo sigue ausente. El driver puede reconstruirse
contra los headers upstream más la extensión ABI y el contexto generado sin
reconstruir ni arrancar un kernel completo.

## Reparaciones de la receta

La receta antigua asumía un árbol Linux ya parcheado. Aplicarla directamente
sobre upstream producía fallos reproducibles. La receta aislada corrige:

1. El parche de ancho global TXBD debe preceder al override TXBD64/PBP256.
2. Los marcadores presentes en `pci.c` no acreditan que `pci.h` haya recibido
   los campos adicionales del ciclo de IRQ.
3. Los parches que afectan varios archivos se limitan a los archivos ausentes
   del overlay. Evita volver a insertar cambios PCI que ya están en la fuente.
4. Los tamaños de los hunks se recalculan y se elimina contexto de comentarios
   antiguos que no afecta al cambio aplicado.
5. Un salto de línea omitido por ese contexto movía `WARN_ONCE` de la línea
   histórica 1621 a la 1620. La única diferencia de `hw.o` era el inmediato de
   esa línea de diagnóstico. La receta recupera el salto con una comprobación
   explícita de la línea, sin alterar la lógica.

La primera reconstrucción compiló las 27 unidades en dos lanes idénticas:
26 objetos fueron idénticos por SHA-256 y `hw.o` tuvo únicamente el byte de
línea descrito. Véase `evidence/reconstruction-initial.json`. La receta posterior
recupera ese byte y añade la compilación y el enlace de los cuatro módulos.

## Ejecución

`python scripts/reconstruct_baseline.py --help` documenta los parámetros.
Todos los insumos locales se indican explícitamente. El root de trabajo Linux
debe ser una carpeta local existente o creable dentro de la distribución WSL
de análisis. Cada ejecución crea una carpeta distinta y conserva sus resultados.

El script recompila 27 unidades y cuatro archivos `.mod.c`, enlaza los cuatro
módulos en cada lane y compara hashes con la referencia. Los binarios,
cabeceras generadas y logs quedan en `.work`, excluidos de Git. La exportación
de fuentes conserva sólo core rtlwifi, RTL8192EE y btcoexist.

La reconstrucción ha producido los cuatro módulos idénticos a la referencia
por SHA-256 en dos compilaciones: 27/27 objetos, 4/4 módulos por compilación.
Los hashes están en
[`reconstruction-exact-paired.json`](../evidence/reconstruction-exact-paired.json).
La evidencia fija el árbol `src/baseline-exact`, sus fuentes y sus hashes.
Asociación WPA2, tráfico bidireccional, persistencia, temperatura y recuperación
siguen siendo gates físicos distintos. Ninguno se ejecuta aquí.

La compilación después de clonar utiliza el contexto `build-context/f363` por
 defecto. `REFERENCE_MANIFEST.json` fija los hashes de objetos y módulos que
 no se incluyen en Git. Las rutas locales del compilador y kernel se sustituyen
 por marcadores; se conserva el SHA-256 original de cada comando. El archivo
 upstream y el toolchain se proporcionan externamente como argumentos.

La comprobación final desde el contexto portable incluido recompiló las dos
lanes desde cero: 27/27 unidades y 4/4 módulos idénticos por SHA-256 a la
referencia, con identidad entre las lanes. Véase
`evidence/reconstruction-portable-paired.json`. No necesitó `.o` ni `.ko`
históricos como insumos de compilación.
