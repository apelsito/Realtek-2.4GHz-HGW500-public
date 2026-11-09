# RTL8192EE y APIs del kernel — candidato del 3 de noviembre

El candidato corrige la descarga del microfirmware, la recepción PCIe y la
gestión de mensajes de firmware en el port Linux 7.3 del HGW500. Las fuentes
de partida coincidían con el árbol de Core Boot R1. La configuración conserva
ARC750, MMU v2, páginas de 8 KiB, UP y las APIs de mac80211/cfg80211 existentes.

## Cambios comprobados

- La descarga rechaza imágenes vacías, mayores de 32 KiB y cabeceras Realtek
  incompletas antes de acceder al hardware. Mantiene el formato raw admitido.
- El polling acepta el checksum si aparece en la última lectura permitida.
  H2C valida sus uno a siete bytes antes de copiar y los informes RA vacíos
  se descartan antes de leer su contenido.
- RX comprueba offset, longitud, cabecera y datos PHY antes de interpretarlos.
  La lectura de frame control admite direcciones no alineadas. ACK y CTS se
  procesan sin intentar obtener una dirección transmisora ausente.
- El anillo RX prepara y mapea el buffer de reemplazo antes de retirar el
  anterior. Ante falta de memoria o error de mapeo conserva el mapping válido.
  Publica el descriptor y la barrera DMA antes de avanzar el puntero MMIO.
- La inicialización libera las reservas parciales RX/TX con sus tamaños
  correctos. El probe aborta si no consigue una máscara DMA utilizable.
- La entrada C2H valida la cabecera y el tamaño representable en u8.
  Los informes TX comprueban el mínimo de cada uno de sus dos formatos.

## Comprobaciones y alcance

Los cuerpos C reales se ejecutaron con registros y notificaciones simulados,
AddressSanitizer y UndefinedBehaviorSanitizer. La suite de firmware pasó
65.564 casos con cada imagen y la consulta RX pasó 16.612 casos. Las mismas
pruebas contra el código anterior reprodujeron firmware vacío aceptado y una
lectura RX fuera del buffer. Las pruebas PCIe cubren errores de reserva y DMA,
rearme, capacidad exacta, alineamiento, frames cortos y mensajes C2H. La suite
de anillos añade 150 fallos de reserva y mapeo en los formatos legacy, nuevo
de 64 bits y compacto de 32 bits, con liberación, reintento y deinit repetido.

Se reconstruyeron la referencia y el candidato en dos destinos independientes
contra una copia del contexto real de Core Boot R1. Los cuatro módulos de cada
pareja coinciden byte a byte, con imports resueltos y sin SWAPE, LLOCK o SCOND.
La configuración, Module.symvers, vmlinux y las fuentes del contexto original
conservaron sus hashes. El candidato añade 1.116 bytes a la pareja de módulos
frente a la referencia recompilada con las mismas opciones.

Los recibos y módulos permanecen en
`/workspace/OpenMitraStar/HGW500/out/rtl8192ee-20261103/`. Las pruebas físicas de carga,
AP, asociación, tráfico, reconexión y reinicio pertenecen a una fase posterior.
El resultado actual acredita correcciones y compatibilidad de compilación.

## Reproducción local

Desde PowerShell, usando un destino nuevo en ext4.

```powershell
wsl -d Engineering -u root --exec python3 /workspace/OpenMitraStar/HGW500/drivers/realtek/scripts/build_linux73_candidate.py --kernel /workspace/build/core-r1/kernel --context /workspace/build/core-r1/context --overlay /workspace/OpenMitraStar/HGW500/drivers/realtek/kernel/radio2g-linux-7.3-v1/overlay/drivers/net/wireless/realtek/rtlwifi --output /workspace/build/rtl-candidate-NUEVO --cross-prefix /workspace/build/arc-toolchain/bin/arc-snps-linux-uclibc- --jobs 2
```

Los scripts `test_linux73_firmware.py`, `test_linux73_rx_query.py` y
`test_linux73_pci_rx.py` y `test_linux73_pci_rings.py` aceptan un directorio de salida nuevo. El primero
admite `--firmware` para contrastar el archivo real mediante sus entry points.
El manifiesto de fuentes se actualiza para esta revisión. `OFFLINE_RESULT.json`
conserva el resultado histórico del kernel mínimo previo a estas correcciones.

## Microfirmware 8051

Core Boot R1 utiliza versión 19.0, con 31.818 bytes y SHA-256
`c6e5beeeb2a716ce417a9ede5974d0876b18ebf0368c195da8a181f6ba6d9b4b`.
El snapshot linux-firmware `02665d2016e1360cd2135998f36cfa303b5be6e1`
declara el alias RTL8192EE hacia `rtl8192eu_nic.bin`, versión 35.7,
32.286 bytes y SHA-256
`b15bc955fba2fc3abc093affe62c9f7284a0b84d4f13f8ce55366488dc9aad8b`.

REA 6.8.0 realizó inspecciones de entropía y regiones. Su selector RAW carece
de 8051. Ghidra 12.1.3 analizó ambas imágenes con lenguaje 8051 y verificó
5.217 instrucciones del instalado y 6.061 del candidato contra sus bytes.
La base CODE 0x4000 se infiere de vectores e interrupciones. La reconstrucción
es parcial y quedan referencias a regiones ROM ausentes.

Ambos binarios contienen el esquema básico de cuatro buzones H2C. La igualdad
completa del protocolo H2C/C2H y el funcionamiento de 35.7 en esta unidad quedan
pendientes. El informe detallado está en
`out/rtl8192ee-20261103/firmware-rea/README.md` del proyecto HGW500.
