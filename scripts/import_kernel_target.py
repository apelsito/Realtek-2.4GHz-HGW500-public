#!/usr/bin/env python3
"""Import a finite pristine Linux 7.3 subset, pinned to an upstream Git commit.
No target execution. Original and Linux 5.10 sources remain unchanged.
"""
import argparse
import base64
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path, PurePosixPath
import subprocess

COMMIT = "c03c1a14507dfaf8b856c2608f9ac216021fc222"
TAG_OBJECT = "091b06388b117fefdcb63336ac09956a4914b961"
REPO = "torvalds/linux"
DRIVER = "drivers/net/wireless/realtek/rtlwifi/"
ROOT = Path(__file__).resolve().parents[1]
PLATFORM = {
    "arch/arc/Kconfig", "arch/arc/Makefile",
    "arch/arc/include/asm/mmu.h", "arch/arc/include/asm/pgtable.h",
    "arch/arc/include/asm/pgtable-bits-arcv2.h", "arch/arc/include/asm/pgtable-bits-arcv3.h",
    "arch/arc/include/asm/swab.h", "arch/arc/include/asm/atomic.h",
    "arch/arc/include/asm/cacheflush.h", "arch/arc/include/asm/tlb.h",
    "arch/arc/kernel/head.S", "arch/arc/kernel/setup.c",
    "arch/arc/mm/mmu.c", "arch/arc/mm/tlb.c", "arch/arc/mm/cache.c",
    "arch/arc/mm/fault.c",
    "include/net/mac80211.h", "include/net/cfg80211.h",
    "include/linux/netdevice.h", "include/linux/skbuff.h",
    "include/linux/pci.h", "include/linux/dma-mapping.h",
    "COPYING", "LICENSES/preferred/GPL-2.0",
}

def api(path):
    return json.loads(subprocess.check_output(["gh", "api", "repos/" + REPO + "/" + path], text=True))

def selected_driver(path):
    if not path.startswith(DRIVER):
        return False
    tail = PurePosixPath(path[len(DRIVER):])
    return (len(tail.parts) == 1 or tail.parts[0] in {"rtl8192ee", "btcoexist"}) and (
        tail.suffix in {".c", ".h"} or tail.name in {"Makefile", "Kconfig"})

def resolve_tree(path):
    tree = COMMIT
    for component in path.split("/"):
        entries = api("git/trees/" + tree)["tree"]
        match = next(x for x in entries if x["path"] == component and x["type"] == "tree")
        tree = match["sha"]
    return tree

def git_blob_digest(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--output", type=Path, default=ROOT / "src/linux-7.3-upstream-verified")
    a = p.parse_args()
    if a.output.exists():
        raise SystemExit("Refusing existing output; select an absent directory.")
    tag = api("git/tags/" + TAG_OBJECT)
    if tag["tag"] != "v7.3" or tag["object"]["sha"] != COMMIT:
        raise SystemExit("Upstream tag identity mismatch.")
    entries = []
    for prefix in ["drivers/net/wireless/realtek/rtlwifi", "arch/arc", "include/net", "include/linux"]:
        tree = api("git/trees/" + resolve_tree(prefix) + "?recursive=1")
        if tree.get("truncated"):
            raise SystemExit("Tree truncated: " + prefix)
        entries.extend(dict(x, path=prefix + "/" + x["path"]) for x in tree["tree"] if x["type"] == "blob")
    top = api("git/trees/" + COMMIT)["tree"]
    entries.extend(x for x in top if x["type"] == "blob")
    licenses = api("git/trees/" + resolve_tree("LICENSES/preferred"))["tree"]
    entries.extend(dict(x, path="LICENSES/preferred/" + x["path"]) for x in licenses if x["type"] == "blob")
    chosen = sorted({x["path"]: x for x in entries if selected_driver(x["path"]) or x["path"] in PLATFORM}.values(), key=lambda x:x["path"])
    a.output.mkdir(parents=True, exist_ok=False)
    def fetch(row):
        relative = PurePosixPath(row["path"])
        if relative.is_absolute() or ".." in relative.parts:
            raise ValueError("Unsafe upstream member.")
        blob = api("git/blobs/" + row["sha"])
        if blob.get("encoding") != "base64" or blob.get("sha") != row["sha"]:
            raise ValueError("Unexpected upstream blob: " + row["path"])
        data = base64.b64decode(blob["content"], validate=False)
        if git_blob_digest(data) != row["sha"]:
            raise ValueError("Git blob mismatch: " + row["path"])
        target = a.output.joinpath(*relative.parts)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
        return {"path": row["path"], "bytes":len(data), "sha256":hashlib.sha256(data).hexdigest(), "git_blob_sha1":row["sha"]}
    with ThreadPoolExecutor(max_workers=2) as pool:
        files = list(pool.map(fetch, chosen))
    manifest = {"schema":"realtek.upstream-target/v1", "kernel":"7.3", "upstream_repository":REPO,
                "commit":COMMIT, "tag_object":TAG_OBJECT, "role":"PRISTINE_UPSTREAM_SOURCE_REFERENCE",
                "hardware_accessed":False, "build_status":"NOT_BUILT", "flashable":False,
                "scope":"rtlwifi common, RTL8192EE, btcoexist and selected platform/API dependencies; not a complete kernel",
                "files":files, "absent_platform_paths":sorted(PLATFORM - {x["path"] for x in files})}
    (a.output/"SOURCE_MANIFEST.json").write_text(json.dumps(manifest,indent=2)+"\n",encoding="utf-8")
    print(json.dumps({"files":len(files),"bytes":sum(x["bytes"] for x in files),"commit":COMMIT,"build_status":"NOT_BUILT"}))

if __name__ == "__main__":
    main()
