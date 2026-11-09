#!/usr/bin/env python3
"""Verify preserved source bytes and verbatim comment exports offline."""
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]


def main():
    manifests = [(ROOT / "original" / "MANIFEST.json", ROOT, "files"),
                 (ROOT / "original" / "port-overlay" / "SOURCE_MANIFEST.json", ROOT / "original" / "port-overlay", "files")]
    api = ROOT / "original" / "kernel-api" / "MANIFEST.json"
    if api.exists():
        manifests.append((api, ROOT, "headers"))
    api_v2 = api.with_name("MANIFEST-v2.json")
    if api_v2.exists():
        manifests.append((api_v2, ROOT, "headers"))
    support = ROOT / "original" / "port-support" / "SOURCE_MANIFEST.json"
    if support.exists():
        manifests.append((support, ROOT / "original" / "port-support", "files"))
    context = ROOT / "build-context" / "f363" / "REFERENCE_MANIFEST.json"
    if context.exists():
        manifests.append((context, context.parent, "files"))
    baseline = ROOT / "src" / "baseline-exact" / "SOURCE_MANIFEST.json"
    if baseline.exists():
        manifests.append((baseline, baseline.parent, "files"))
    verified = 0
    for manifest, base, collection in manifests:
        rows = json.loads(manifest.read_text(encoding="utf-8"))[collection]
        for row in rows:
            path = (base / row["path"]).resolve()
            if not path.is_relative_to(base.resolve()):
                raise ValueError("unsafe manifest source path")
            content = path.read_bytes()
            if hashlib.sha256(content).hexdigest() != row["sha256"] or ("bytes" in row and len(content) != row["bytes"]):
                raise ValueError("original source identity changed: " + row["path"])
            verified += 1
    print(json.dumps({"original_files_verified": verified, "source_bytes_preserved": True}))
    return 0


if __name__ == "__main__":
    sys.exit(main())
