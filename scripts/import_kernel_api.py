"""Import a bounded ABI-header subset from the same SHA-pinned kernel archive."""
import argparse
import hashlib
import json
from pathlib import Path
import tarfile
from import_original_sources import ARCHIVE_SHA256

HEADERS = ('pm.h', 'pci.h', 'device.h', 'moduleparam.h', 'module.h', 'device/driver.h')


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('archive', type=Path)
    p.add_argument('--repository', type=Path, default=Path(__file__).resolve().parents[1])
    a = p.parse_args()
    with a.archive.open('rb') as stream:
        digest = hashlib.file_digest(stream, 'sha256').hexdigest()
    if digest != ARCHIVE_SHA256:
        raise SystemExit('Kernel archive digest mismatch')
    out = a.repository / 'original/kernel-api/linux-5.10.260/include/linux'
    entries = []
    with tarfile.open(a.archive, 'r:xz') as archive:
        for name in HEADERS:
            member = archive.getmember('linux-5.10.260/include/linux/' + name)
            if not member.isfile():
                raise SystemExit('Nonregular header ' + name)
            data = archive.extractfile(member).read()
            dest = out / name
            dest.parent.mkdir(parents=True, exist_ok=True)
            if dest.exists() and dest.read_bytes() != data:
                raise SystemExit('Refusing to replace original ' + name)
            dest.write_bytes(data)
            entries.append(dict(path=dest.relative_to(a.repository).as_posix(), bytes=len(data),
                                sha256=hashlib.sha256(data).hexdigest()))
    manifest = dict(schema='realtek.kernel-api-original/v1', archive_sha256=digest,
                    source_bytes_preserved=True, headers=entries)
    dest = a.repository / 'original/kernel-api/MANIFEST-v2.json'
    encoded = (json.dumps(manifest, indent=2) + '\n').encode()
    if dest.exists() and dest.read_bytes() != encoded:
        raise SystemExit('Refusing to replace different API manifest')
    dest.write_bytes(encoded)
    print(json.dumps(dict(headers=len(entries), bytes=sum(x['bytes'] for x in entries))))


if __name__ == '__main__':
    main()
