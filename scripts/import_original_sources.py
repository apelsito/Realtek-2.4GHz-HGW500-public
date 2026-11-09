#!/usr/bin/env python3
"""Import a finite, SHA-pinned Linux source subset without changing its bytes."""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import tarfile

ARCHIVE_SHA256 = "47a8297131505b7d38338d39ad8a9d592507d33c695b27b1bbe55f25869a6b84"
PREFIX = "linux-5.10.260/"
DRIVER = "drivers/net/wireless/realtek/rtlwifi/"


def sha(data):
    return hashlib.sha256(data).hexdigest()


def selected(relative):
    if relative in {"COPYING", "LICENSES/preferred/GPL-2.0", "include/net/mac80211.h"}:
        return True
    if not relative.startswith(DRIVER):
        return False
    tail = PurePosixPath(relative[len(DRIVER):])
    in_scope = len(tail.parts) == 1 or tail.parts[0] in {"rtl8192ee", "btcoexist"}
    return in_scope and (tail.suffix in {".c", ".h"} or tail.name in {"Makefile", "Kconfig"})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument("--repository", type=Path, default=Path(__file__).resolve().parents[1])
    args = parser.parse_args()
    digest = hashlib.file_digest(args.archive.open("rb"), "sha256").hexdigest()
    if digest != ARCHIVE_SHA256:
        raise SystemExit("archive SHA-256 mismatch")
    root = args.repository.resolve() / "original" / "linux-5.10.260"
    entries = []
    with tarfile.open(args.archive, "r:xz") as archive:
        for member in archive:
            if not member.isfile() or not member.name.startswith(PREFIX):
                continue
            relative = member.name[len(PREFIX):]
            if not selected(relative):
                continue
            target = root / relative
            if not target.resolve().is_relative_to(root.resolve()):
                raise SystemExit("unsafe archive member")
            content = archive.extractfile(member).read()
            target.parent.mkdir(parents=True, exist_ok=True)
            if target.exists():
                if target.read_bytes() != content:
                    raise SystemExit("refusing to replace an original: " + relative)
            else:
                target.write_bytes(content)
            entries.append({"path": target.relative_to(args.repository.resolve()).as_posix(),
                            "bytes": len(content), "sha256": sha(content)})
    if not entries:
        raise SystemExit("no selected sources in archive")
    manifest = {"schema": "realtek.original-sources/v1", "source": "Linux 5.10.260 upstream archive",
                "archive_sha256": digest, "scope": "rtlwifi common, RTL8192EE, btcoexist and mac80211 API header",
                "source_bytes_preserved": True, "files": sorted(entries, key=lambda e: e["path"])}
    path = args.repository / "original" / "MANIFEST.json"
    encoded = (json.dumps(manifest, ensure_ascii=False, indent=2) + "\n").encode()
    if path.exists() and path.read_bytes() != encoded:
        raise SystemExit("refusing to replace a different original manifest")
    path.write_bytes(encoded)
    print(json.dumps({"files": len(entries), "bytes": sum(e["bytes"] for e in entries), "archive_sha256": digest}))


if __name__ == "__main__":
    main()
