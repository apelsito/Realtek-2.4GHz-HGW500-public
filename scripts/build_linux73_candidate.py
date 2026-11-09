#!/usr/bin/env python3
"""Build the HGW500 Realtek stack twice using a copy of its kernel context."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess


GCC_SHA256 = "3918a0da3c9f2cfde359f6fed1d0df19e737438dfd2cc60edae63f2dcbf14263"
STACK_PATH = Path("drivers/net/wireless/realtek/rtlwifi")
MODULE_NAMES = {"rtlwifi", "rtl_pci", "rtl8192ee", "btcoexist"}
CONTEXT_FILES = (".config", "Module.symvers", "vmlinux")


def sha256(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def file_hashes(directory):
    return {
        path.relative_to(directory).as_posix(): sha256(path)
        for path in sorted(directory.rglob("*"))
        if path.is_file()
    }


def command_output(command):
    return subprocess.check_output(command, text=True)


def inspect_modules(directory, cross_prefix, kernel_exports):
    modules = sorted(directory.rglob("*.ko"))
    if {path.stem for path in modules} != MODULE_NAMES:
        raise ValueError("Expected exactly the four selected Realtek modules")
    results = []
    for module in modules:
        header = module.read_bytes()[:64]
        if header[:6] != b"\x7fELF\x01\x01" or struct.unpack_from("<H", header, 18)[0] != 93:
            raise ValueError("Expected an ELF32 little-endian ARCompact module")
        assembly = command_output([cross_prefix + "objdump", "-d", str(module)])
        if re.search(r"\t(?:swape|llock|scond)(?:[.\s]|$)", assembly):
            raise ValueError("Instruction unsupported by the selected ARC CPU")
        module.with_suffix(".disassembly.txt").write_text(assembly)
        undefined = command_output([cross_prefix + "nm", "-u", str(module)])
        imports = sorted({line.split()[-1] for line in undefined.splitlines() if line.split()})
        missing = set(imports) - kernel_exports
        if missing:
            raise ValueError("Unresolved kernel imports: " + repr(sorted(missing)))
        modinfo = command_output([cross_prefix + "readelf", "-p", ".modinfo", str(module)])
        vermagic = re.search(r"vermagic=([^\n]+)", modinfo)
        if not vermagic or not vermagic.group(1).startswith("7.3.0-openmitrastar-radio73-v1 "):
            raise ValueError("Module targets a different kernel release")
        size_output = command_output([cross_prefix + "size", str(module)])
        results.append({
            "path": module.relative_to(directory).as_posix(),
            "bytes": module.stat().st_size,
            "sha256": sha256(module),
            "imports": imports,
            "vermagic": vermagic.group(1).strip(),
            "sections": size_output.splitlines()[-1].split()[:5],
        })
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("kernel", "context", "output"):
        parser.add_argument("--" + name, type=Path, required=True)
    parser.add_argument("--overlay", type=Path,
                        help="Candidate rtlwifi directory; omit to rebuild the reference")
    parser.add_argument("--cross-prefix", required=True)
    parser.add_argument("--jobs", type=int, default=2)
    args = parser.parse_args()
    if os.name != "posix":
        parser.error("Use the native Linux filesystem and ARC toolchain in Engineering")
    kernel = args.kernel.resolve()
    context = args.context.resolve()
    destination = args.output.resolve()
    if destination.exists() or str(destination).startswith("/mnt/"):
        parser.error("Choose an absent destination on native Linux storage")
    if not 1 <= args.jobs <= 8:
        parser.error("Use 1 through 8 jobs")
    if destination.is_relative_to(kernel) or destination.is_relative_to(context):
        parser.error("Output must be outside the reference kernel and context")
    compiler = Path(args.cross_prefix + "gcc")
    if sha256(compiler) != GCC_SHA256:
        raise ValueError("ARC compiler differs from the verified toolchain")
    reference_stack = kernel / STACK_PATH
    context_hashes = {name: sha256(context / name) for name in CONTEXT_FILES}
    reference_hashes = file_hashes(reference_stack)
    overlay = args.overlay.resolve() if args.overlay else None
    overlay_hashes = file_hashes(overlay) if overlay else {}
    destination.mkdir(parents=True)
    candidate_context = destination / "context"
    subprocess.run(["cp", "-a", "--reflink=auto", str(context), str(candidate_context)], check=True)
    environment = os.environ.copy()
    environment.update(SOURCE_DATE_EPOCH="1792365298", KBUILD_BUILD_TIMESTAMP="@1792365298",
                       KBUILD_BUILD_USER="openmitrastar", KBUILD_BUILD_HOST="radio73",
                       KBUILD_BUILD_VERSION="1", LC_ALL="C")
    # A later vmlinux target can leave Module.symvers containing kernel exports
    # only. Rebuild the enabled modules in the copy to recover their real exports.
    prepare = ["make", "-C", str(kernel), "O=" + str(candidate_context), "ARCH=arc",
               "CROSS_COMPILE=" + args.cross_prefix, "-j" + str(args.jobs), "modules"]
    with (destination / "prepare-context.log").open("w") as log:
        subprocess.run(prepare, env=environment, stdout=log, stderr=subprocess.STDOUT, check=True)
    exports = {line.split()[1] for line in (candidate_context / "Module.symvers").read_text().splitlines()
               if line.split()}
    lanes = []
    for lane in ("a", "b"):
        source = destination / lane
        shutil.copytree(reference_stack, source, symlinks=True)
        if overlay:
            for relative in overlay_hashes:
                target = source / relative
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(overlay / relative, target)
        flags = " ".join((
            "-mcpu=arc700 -mno-lock -mno-atomic -mno-swape",
            "-ffile-prefix-map=" + str(source) + "=/openmitrastar/realtek/source",
            "-ffile-prefix-map=" + str(kernel) + "=/openmitrastar/kernel",
            "-ffile-prefix-map=" + str(candidate_context) + "=/openmitrastar/kernel-context",
        ))
        command = ["make", "-C", str(kernel), "O=" + str(candidate_context), "ARCH=arc",
                   "CROSS_COMPILE=" + args.cross_prefix, "M=" + str(source),
                   "KCFLAGS=" + flags, "-j" + str(args.jobs), "modules"]
        with (destination / ("build-" + lane + ".log")).open("w") as log:
            subprocess.run(command, env=environment, stdout=log, stderr=subprocess.STDOUT,
                           check=True)
        lanes.append({"lane": lane, "modules": inspect_modules(source, args.cross_prefix, exports)})
    if lanes[0]["modules"] != lanes[1]["modules"]:
        raise ValueError("Independent module builds differ")
    if context_hashes != {name: sha256(context / name) for name in CONTEXT_FILES}:
        raise ValueError("Reference kernel context changed during the build")
    if reference_hashes != file_hashes(reference_stack):
        raise ValueError("Reference Realtek sources changed during the build")
    if overlay and overlay_hashes != file_hashes(overlay):
        raise ValueError("Candidate sources changed during the build")
    report = {
        "schema": "openmitrastar.realtek-linux73-candidate/v1",
        "status": "PASS_PAIRED_ARC_REALTEK_BUILD",
        "compiler_sha256": sha256(compiler),
        "context": {"path": str(context), "hashes": context_hashes},
        "reference_sources": reference_hashes,
        "candidate_overlay": overlay_hashes,
        "lanes": lanes,
        "hardware_accessed": False,
        "physical_acceptance": False,
    }
    (destination / "result.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({"status": report["status"], "modules_per_lane": len(MODULE_NAMES),
                      "result": str(destination / "result.json")}))


if __name__ == "__main__":
    main()
