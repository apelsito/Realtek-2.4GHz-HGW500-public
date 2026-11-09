#!/usr/bin/env python3
"""Build a finite source comparison and a pristine Linux 7.3 driver work tree."""
from pathlib import Path
import argparse
import difflib
import hashlib
import json
import shutil

ROOT = Path(__file__).resolve().parents[1]
DRIVER = Path("drivers/net/wireless/realtek/rtlwifi")
BASE = ROOT / "src/baseline-exact"
ORIGINAL = ROOT / "original/linux-5.10.260"
TARGET = ROOT / "src/linux-7.3-upstream-verified"
WORK = ROOT / "src/linux-7.3"
OUT = ROOT / "evidence/port-linux-7.3"
PATTERNS = {
    "pci.c": ["dma_set_mask", "dma_set_coherent_mask", "dma_wmb", "dma_rmb",
              "om_intx", "om_ap_rx", "om_irq", "txbd", "ieee80211_beacon_get"],
    "pci.h": ["om_intx", "om_ap_rx", "om_irq", "txbd", "rx_work"],
    "rtl8192ee/trx.c": ["get_unaligned", "put_unaligned", "upper_32_bits", "dma_wmb", "dma_rmb", "TXBD"],
    "rtl8192ee/hw.c": ["TXBD", "PBP", "dma", "WARN_ONCE"],
}
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def lines(path):
    return path.read_text(encoding="utf-8").splitlines(keepends=True)

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--verify-only",action="store_true")
    a=p.parse_args()
    manifest=json.loads((TARGET/"SOURCE_MANIFEST.json").read_text(encoding="utf-8"))
    for row in manifest["files"]:
        source=TARGET/row["path"]
        if sha(source)!=row["sha256"]:
            raise SystemExit("Target identity changed: "+row["path"])
    if a.verify_only:
        report=json.loads((OUT/"source-comparison.json").read_text(encoding="utf-8"))
        for row in report["work_tree_files"]:
            if sha(WORK/row["path"])!=row["sha256"]:
                raise SystemExit("Working tree differs from initial verified reference.")
        print(json.dumps({"target_files_verified":len(manifest["files"]),
                         "initial_work_files_verified":len(report["work_tree_files"]),
                         "status":"PASS_SOURCE_IDENTITY","build_status":"NOT_BUILT"}))
        return
    OUT.mkdir(parents=True,exist_ok=False)
    WORK.mkdir(parents=True,exist_ok=False)
    shutil.copytree(TARGET/DRIVER,WORK/DRIVER)
    for name in ["COPYING","LICENSES/preferred/GPL-2.0"]:
        source=TARGET/name
        dest=WORK/name
        dest.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(source,dest)
    report={"schema":"realtek.kernel-port-comparison/v1","upstream_commit":manifest["commit"],
            "working_source":"src/linux-7.3","role":"PRISTINE_WORK_TREE_REQUIRES_HGW_PATCH_PORT",
            "build_status":"NOT_BUILT","hardware_accessed":False,"flashable":False,
            "comparisons":[],"contract_anchors":[],
            "platform_gates":["ARC750D profile and no LL/SC atomics",
                              "MMUv2 PTE/TLB/cache semantics,8KiB pages",
                              "Non-SWAPE byte-swap path",
                              "Topaz DT/reserved memory/IRQ/PCIe host",
                              "DMA32/TXBD/IRQ/RX fixes transported and checked"]}
    patches={"hgw-5.10-versus-upstream.patch":[],"upstream-5.10-versus-7.3.patch":[]}
    for current in sorted((BASE/DRIVER).rglob("*")):
        if not current.is_file():
            continue
        rel=current.relative_to(BASE)
        old=ORIGINAL/rel
        new=TARGET/rel
        row={"path":rel.as_posix(),"baseline_sha256":sha(current)}
        if old.exists():
            row["upstream_5_10_sha256"]=sha(old)
            row["hgw_changed_from_upstream_5_10"]=old.read_bytes()!=current.read_bytes()
            patches["hgw-5.10-versus-upstream.patch"].extend(
                difflib.unified_diff(lines(old),lines(current),
                    fromfile="upstream-5.10/"+rel.as_posix(),tofile="hgw-5.10/"+rel.as_posix()))
        if new.exists():
            row["upstream_7_3_sha256"]=sha(new)
            row["upstream_changed_5_10_to_7_3"]=not old.exists() or old.read_bytes()!=new.read_bytes()
            if old.exists():
                patches["upstream-5.10-versus-7.3.patch"].extend(
                    difflib.unified_diff(lines(old),lines(new),
                        fromfile="upstream-5.10/"+rel.as_posix(),tofile="upstream-7.3/"+rel.as_posix()))
        report["comparisons"].append(row)
    for name,parts in patches.items():
        (OUT/name).write_text("".join(parts),encoding="utf-8")
    for filename,terms in PATTERNS.items():
        pth=BASE/DRIVER/filename
        for number,text in enumerate(lines(pth),1):
            if any(term.lower() in text.lower() for term in terms):
                report["contract_anchors"].append({"path":pth.relative_to(ROOT).as_posix(),
                                                   "line":number,"text":text.rstrip()})
    report["work_tree_files"]=[{"path":p.relative_to(WORK).as_posix(),"sha256":sha(p),"bytes":p.stat().st_size}
                              for p in sorted(WORK.rglob("*")) if p.is_file()]
    report["counts"]={"baseline_driver_files":len(report["comparisons"]),
         "hgw_modified_files":sum(x.get("hgw_changed_from_upstream_5_10",False) for x in report["comparisons"]),
         "upstream_changed_files":sum(x.get("upstream_changed_5_10_to_7_3",False) for x in report["comparisons"]),
         "contract_anchor_lines":len(report["contract_anchors"])}
    (OUT/"source-comparison.json").write_text(json.dumps(report,indent=2)+"\n",encoding="utf-8")
    print(json.dumps(report["counts"]))
if __name__=="__main__":
    main()
