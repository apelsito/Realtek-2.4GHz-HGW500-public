#!/usr/bin/env python3
"""Offline source reconstruction and exact historical compile-unit comparison.

Never contacts hardware. Inputs remain unchanged. Every build has a new directory.
The historical full kernel is not recovered by this driver-only operation.
"""
from __future__ import annotations
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
OLD_SRC = "/home/user/openmitrastar-build/f358-flash-arbitration-20260921T173956Z/linux"
PREFIX = "drivers/net/wireless/realtek/rtlwifi"
EXPECTED_ARCHIVE = "47a8297131505b7d38338d39ad8a9d592507d33c695b27b1bbe55f25869a6b84"

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def linux(path):
    p = Path(path).resolve()
    return "/mnt/" + p.drive[0].lower() + p.as_posix()[2:]

def run_wsl(distro, script, output):
    result = subprocess.run(["wsl.exe", "-d", distro, "-u", "rea", "-e", "sh", linux(script)],
                            stdin=subprocess.DEVNULL, capture_output=True)
    (output / "launcher.stdout").write_bytes(result.stdout)
    (output / "launcher.stderr").write_bytes(result.stderr)
    return result.returncode

def export_driver(source, destination):
    """Keep only shared core, RTL8192EE and its coexistence dependency."""
    destination.mkdir(parents=True, exist_ok=False)
    for p in source.iterdir():
        if p.is_file() and (p.suffix in {".c", ".h"} or p.name in {"Makefile", "Kconfig"}):
            shutil.copyfile(p, destination / p.name)
    for name in ["rtl8192ee", "btcoexist"]:
        shutil.copytree(source / name, destination / name,
                        ignore=shutil.ignore_patterns("*.orig", "*.rej"))

def reference_digest(reference, relative, manifest):
    p = reference / relative
    if p.is_file():
        return sha(p)
    return manifest["reference_artifacts"][relative]["sha256"]

def relocate_command(command, toolchain_prefix, source_linux):
    new_root = linux(toolchain_prefix.parent.parent)
    if "@TOOLCHAIN_ROOT@" in command:
        return command.replace("@TOOLCHAIN_ROOT@",new_root).replace("@KERNEL_SOURCE@",source_linux).replace("@HISTORICAL_OUTPUT@","/f358-output")
    old_executable = shlex.split(command)[0]
    old_root = old_executable.rsplit("/bin/",1)[0]
    return command.replace(old_root,new_root).replace(OLD_SRC,source_linux)

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--archive", required=True, type=Path)
    ap.add_argument("--reference", default=ROOT/"build-context/f363", type=Path, help="retained or normalized F363 build context directory")
    ap.add_argument("--toolchain-prefix", required=True, type=Path)
    ap.add_argument("--distro", default="REA-Linux")
    ap.add_argument("--linux-work-root", required=True, help="absolute Linux directory for fast isolated source extraction")
    ap.add_argument("--output", type=Path)
    args = ap.parse_args()
    assert sha(args.archive) == EXPECTED_ARCHIVE, "upstream archive digest mismatch"
    assert (args.reference / ".config").is_file()
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")
    out = args.output or ROOT / ".work" / ("reconstruction-" + stamp)
    out = out.resolve()
    out.mkdir(parents=True, exist_ok=False)
    assert args.linux_work_root.startswith("/") and ".." not in Path(args.linux_work_root).parts
    source_linux = args.linux_work_root.rstrip("/") + "/reconstruction-" + stamp + "/linux-5.10.260"
    source = Path("//wsl.localhost/" + args.distro + source_linux)
    overlay = ROOT / "src" / "overlay"
    reference = args.reference.resolve()
    reference_manifest_path = reference / "REFERENCE_MANIFEST.json"
    reference_manifest = json.loads(reference_manifest_path.read_text()) if reference_manifest_path.exists() else {}
    units = []
    modules = ["rtlwifi", "rtl_pci", "rtl8192ee/rtl8192ee", "btcoexist/btcoexist"]
    for module in modules:
        mod = reference / PREFIX / (module + ".mod")
        for relative in mod.read_text().split():
            if relative in [u["relative"] for u in units]:
                continue
            obj = reference / relative
            cmdfile = obj.with_name("." + obj.name + ".cmd")
            line = cmdfile.read_text().splitlines()[0].split(":=", 1)[1].strip()
            units.append({"relative":relative,"command":line,"reference_sha256":reference_digest(reference,relative,reference_manifest),
                          "command_sha256":sha(cmdfile)})
    for lane in ["a", "b"]:
        dst = out / lane
        dst.mkdir()
        for rel in ["include/config", "include/generated", "arch/arc/include/generated"]:
            shutil.copytree(reference / rel, dst / rel)
        (dst / "scripts").mkdir()
        shutil.copyfile(reference / "scripts/module.lds", dst / "scripts/module.lds")
        for unit in units:
            (dst / unit["relative"]).parent.mkdir(parents=True, exist_ok=True)
        for module in modules:
            rel = PREFIX + "/" + module + ".mod.c"
            shutil.copyfile(reference / rel, dst / rel)
    q = shlex.quote
    script = "#!/bin/sh\nset -eu\n"
    script += f"mkdir -p {q(source_linux.rsplit('/',1)[0])}\n"
    script += f"tar -xJf {q(linux(args.archive))} -C {q(source_linux.rsplit('/',1)[0])}\n"
    script += f"src={q(source_linux)}\noverlay={q(linux(overlay))}\n"
    script += 'cp -a "$overlay/files/." "$src/"\n'
    script += 'patch -d "$src" -p1 --forward < "$overlay/patches/qdrv-core-compat.patch"\n'
    script += 'sh "$overlay/apply-driver-only.sh" "$src" "$overlay"\n'
    for lane in ["a", "b"]:
        script += f"cd {q(linux(out / lane))}\n"
        for i, unit in enumerate(units):
            # Retain exact ABI/compiler flags; only relocate compiler and source.
            command = relocate_command(unit["command"],args.toolchain_prefix,source_linux)
            script += f"printf '%s\\n' {q(lane + ':' + unit['relative'])}\n"
            script += command + f" > {q(linux(out / ('compile-' + lane + '-' + str(i) + '.log')))} 2>&1\n"
        for i, module in enumerate(modules):
            relative = PREFIX + "/" + module
            commands = [relative + ".o"]
            commands += [relative + ".mod.o", relative + ".ko"]
            for objrelative in commands:
                obj = reference / objrelative
                cmdfile = obj.with_name("." + obj.name + ".cmd")
                command = cmdfile.read_text().splitlines()[0].split(":=", 1)[1].strip()
                command = relocate_command(command,args.toolchain_prefix,source_linux)
                script += command + f" > {q(linux(out / ('module-' + lane + '-' + str(i) + '-' + obj.suffix + '.log')))} 2>&1\n"
    script_path = out / "build.sh"
    script_path.write_text(script, encoding="utf-8", newline="\n")
    print(json.dumps({"build_started":str(out),"compile_units":len(units),"hardware_actions":False}), flush=True)
    code = run_wsl(args.distro, script_path, out)
    report = {"schema":"realtek.reconstruction/v1","created_utc":stamp,
              "status":"BUILD_FAILED" if code else "BUILT_EQUIVALENCE_PENDING",
              "exit_code":code,"hardware_actions":False,"flashable":False,
              "upstream_archive_sha256":EXPECTED_ARCHIVE,"compile_units":[],
              "source_tree":str(source),"paired_build":False,"exact_object_matches":0,
              "limits":["Driver compile units only; complete historical kernel is not reconstructed.",
                        "Object identity does not prove physical radio, association, or traffic acceptance."]}
    for unit in units:
        row = {k:v for k,v in unit.items() if k != "command"}
        a,b = out/"a"/unit["relative"],out/"b"/unit["relative"]
        if a.exists(): row["a_sha256"] = sha(a)
        if b.exists(): row["b_sha256"] = sha(b)
        row["paired_identical"] = a.exists() and b.exists() and sha(a)==sha(b)
        row["exact_reference_identical"] = a.exists() and sha(a)==row["reference_sha256"]
        report["compile_units"].append(row)
    report["paired_build"] = bool(units) and all(r["paired_identical"] for r in report["compile_units"])
    report["exact_object_matches"] = sum(r["exact_reference_identical"] for r in report["compile_units"])
    report["modules"] = []
    for module in modules:
        relative = PREFIX + "/" + module + ".ko"
        a,b = out/"a"/relative,out/"b"/relative
        row = {"relative":relative,"reference_sha256":reference_digest(reference,relative,reference_manifest)}
        if a.exists():row["a_sha256"] = sha(a)
        if b.exists():row["b_sha256"] = sha(b)
        row["paired_identical"] = a.exists() and b.exists() and sha(a)==sha(b)
        row["exact_reference_identical"] = a.exists() and sha(a)==row["reference_sha256"]
        report["modules"].append(row)
    if not code:
        exact_modules = all(r["exact_reference_identical"] and r["paired_identical"] for r in report["modules"])
        report["status"] = "PASS_EXACT_DRIVER_MODULES" if report["exact_object_matches"]==len(units) and exact_modules else "PASS_BUILD_SOURCE_DELTA_REMAINS"
        baseline = ROOT / "src" / ("baseline-exact" if all(r["exact_reference_identical"] for r in report["modules"]) else "baseline")
        if baseline.exists():
            baseline = ROOT / "src" / (baseline.name + "-" + stamp)
        export_driver(source / PREFIX, baseline / PREFIX)
        for rel in ["include/linux/skbuff.h", "include/linux/netdevice.h", "include/linux/openmitrastar_qtn_skb.h"]:
            dest = baseline / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(source / rel, dest)
        manifest_files = [{"path":p.relative_to(baseline).as_posix(),"bytes":p.stat().st_size,"sha256":sha(p)}
                          for p in sorted(baseline.rglob("*")) if p.is_file()]
        (baseline / "SOURCE_MANIFEST.json").write_text(json.dumps({"schema":"realtek.source-baseline/v1",
            "role":"EXACT_F363_DRIVER_RECONSTRUCTED_SOURCE" if exact_modules else "RECONSTRUCTED_DRIVER_SOURCE",
            "hardware_actions":False,"upstream_archive_sha256":EXPECTED_ARCHIVE,
            "reference_context":"F363 retained kernel output","compiler":"ARCompact ARC700 GCC 15.2.0 build10504",
            "files":manifest_files,"verification":report["status"]},indent=2)+"\n",encoding="utf-8")
        report["baseline_export"] = str(baseline)
    (out/"result.json").write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({"result":str(out/"result.json"),"status":report["status"],
                      "exact_object_matches":report["exact_object_matches"],"units":len(units)}),flush=True)
    return code

if __name__ == "__main__":
    sys.exit(main())
