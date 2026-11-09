# Checkout de trabajo en la raíz OpenMitraStar

La carpeta `/workspace/OpenMitraStar/Realtek-2.4GHz-HGW500` materializa la rama
`port/linux-7.3` del repositorio privado existente el 3 de noviembre de 2026.
La base upstream de esta organización es el commit
`a924ed874ba925c1b9fb2e42cbb2ef2e59d74e5d`. Se copiaron los cambios vigentes
de `HGW500/drivers/realtek` sin modificar su índice, checkout o puntero Git.

Los cambios actuales corrigen límites de firmware y mensajes H2C/C2H,
propiedad RX/DMA, reserva y liberación de rings parciales, y parsing PHY/RX.
El candidato público 35.7 permanece separado del firmware 19.0 instalado.
La entrega fija fuentes, scripts y evidencias en `WORKSPACE_MANIFEST.json`.

Los scripts de las cuatro fixtures ya usan `scripts/c_source.py` local.
Funcionan desde este checkout sin depender de `HGW500/tools` ni de su posición
anterior dentro del árbol de integración. Las fixtures se ejecutaron otra vez
desde esta carpeta con GCC nativo en WSL Engineering.

| Fixture | Resultado observado |
| --- | --- |
| PCI RX y C2H | PASS, fallos de mapping, propiedad y framing |
| PCI rings | PASS, 150 fallos de reserva/mapping, retry y liberación idempotente |
| RX/PHY query | PASS, 16.612 casos, ASan/UBSan |
| Entrada firmware y H2C/C2H | PASS, 65.564 casos, ASan/UBSan, candidato 35.7 |

`evidence/root-workspace-20261103/` conserva los cuatro recibos nuevos.
Las comparaciones pareadas de cuatro módulos del candidato se conservan
como evidencia previa en `docs/LINUX73_DRIVER_CANDIDATE_20261103.md`.
Esta organización no repitió una compilación completa del kernel.

La aceptación física de Core Boot R1 corresponde al artefacto instalado
de HGW500. La fuente candidata y el microfirmware 35.7 mantienen pendientes
su propia instalación, cliente, tráfico y estabilidad prolongada.

Para reproducir cada fixture, usar su `--help` y un destino ext4 nuevo.

```powershell
wsl -d Engineering -u apelsito --exec python3 /workspace/OpenMitraStar/Realtek-2.4GHz-HGW500/scripts/test_linux73_pci_rx.py --output /workspace/build/evidence/rtl-pci-rx-new
wsl -d Engineering -u apelsito --exec python3 /workspace/OpenMitraStar/Realtek-2.4GHz-HGW500/scripts/test_linux73_pci_rings.py --output /workspace/build/evidence/rtl-pci-rings-new
wsl -d Engineering -u apelsito --exec python3 /workspace/OpenMitraStar/Realtek-2.4GHz-HGW500/scripts/test_linux73_rx_query.py --output /workspace/build/evidence/rtl-rx-query-new
wsl -d Engineering -u apelsito --exec python3 /workspace/OpenMitraStar/Realtek-2.4GHz-HGW500/scripts/test_linux73_firmware.py --output /workspace/build/evidence/rtl-fw-new
```

El último comando admite `--firmware` para cualquiera de los dos binarios
fijados en el repositorio hermano `hgw500-2ghz-driver-microfirmware`.
