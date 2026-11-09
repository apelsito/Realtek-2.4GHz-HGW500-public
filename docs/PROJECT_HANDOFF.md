# HGW500 Realtek host driver for Linux 7.3 handoff

## Purpose and evidence boundary

This is the maintained Linux-side port for the 2.4 GHz RTL8192EE radio. The work covers PCIe/DMA, receive and transmit handling, firmware messaging and integration with the Linux wireless stack. The original 5.10 reconstruction and the 8051 payload analysis are maintained separately.

Continue candidate-specific receive/transmit, error-path and DMA qualification against the exact kernel ABI. Long-duration radio/load behavior remains a separate gate. Do not attribute results of one candidate or toolchain to another.

## Source and evidence entry points

- `src/combined-memory-rx-20261105/`
- `docs/ROOT_WORKSPACE_20261103.md`
- `docs/LINUX73_BASIC_CONTRACTS_20261103.md`
- `docs/LINUX73_R5_R8_20261104.md`
- `docs/KERNEL_BRANCHES.md`
- `scripts/`
- `tests/`

These paths are relative to this checkout. Some are preserved local additions
ahead of a remote branch; use the source/preservation manifests and the notes
below to establish which files a given clone actually contains. Do not guess
missing private inputs or replace an original with a similar-looking download.

## Continue from another machine

1. Clone the correct repository and branch from the [repository map](REPOSITORY_MAP.md).
   Initialize submodules only where the component actually declares them.
2. Read `docs/PUBLIC_SNAPSHOT.md`, the preservation/source manifest and the detailed
   [reference notes](REFERENCE_NOTES.md). Resolve baseline and target kernel first.
3. Verify the input hashes, analysis subject and compiler/processor definition.
   Keep preserved exports separate from any new analysis project.
4. Run the README's offline integrity checks. Missing context, original inputs
   or submodules are unmet dependencies, not permission to fabricate a passing result.
5. Put new build/analysis outputs in a fresh ignored `out/` or an external build
   directory. Record source hash, tool version, target ABI and the exact checks run.
6. Report source recovery, native compilation, byte comparison and any physical
   result separately. Installation/reboot/traffic tests need their own authority
   and exact-image recovery plan in the integration project.

## Handoff deliverables

- The selected source and immutable input hashes, with licences/provenance.
- A reproducible command or an explicit list of unresolved external inputs.
- New output locations and result receipts, leaving older evidence unchanged.
- A short explanation of what changed, which checks passed and what remains untested.
- A reviewed export containing no workstation paths, credentials, identity,
  client MACs, calibration or personalized image bodies.

The [firmware map](FIRMWARE_MAP.md) separates the OEM recovery, Core Boot R1 and
newer API v2 R3 integration. A historical acceptance does not transfer between them.
