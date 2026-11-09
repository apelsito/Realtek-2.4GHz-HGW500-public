"""Verify the allowlist, hashes and literal scan of a sanitized REA export."""
import argparse
import gzip
import hashlib
import json
from pathlib import Path

from export_rea_public import check_text


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    manifest = json.loads((args.input / 'manifest.json').read_text())
    failures = []
    findings = []
    forbidden = []
    byte_count = 0
    allowed = {row['path'] for row in manifest['files']} | {'manifest.json'}
    extra = [str(path.relative_to(args.input)).replace('\\', '/')
             for path in args.input.rglob('*') if path.is_file()
             and str(path.relative_to(args.input)).replace('\\', '/') not in allowed]
    for row in manifest['files']:
        path = args.input / row['path']
        data = path.read_bytes()
        byte_count += len(data)
        if len(data) != row['bytes'] or hashlib.sha256(data).hexdigest() != row['sha256']:
            failures.append(row['path'])
        text = gzip.decompress(data).decode() if path.suffix == '.gz' else data.decode()
        observed = check_text(text)
        if observed:
            findings.append({'path': row['path'], 'findings': observed})
        if path.suffix in {'.elf', '.ko', '.bin', '.stdout', '.stderr'}:
            forbidden.append(row['path'])
    manifest_findings = check_text((args.input / 'manifest.json').read_text())
    if manifest_findings:
        findings.append({'path': 'manifest.json', 'findings': manifest_findings})
    result = {'schema': 'realtek.rea-public-export-verification/v1',
              'status': 'PASS' if not failures + extra + findings + forbidden else 'FAILED',
              'payload_files': len(manifest['files']), 'payload_bytes': byte_count,
              'hash_failures': failures, 'unexpected_files': extra,
              'literal_findings': findings, 'forbidden_artifacts': forbidden}
    if args.output:
        with args.output.open('x', encoding='utf-8') as handle:
            handle.write(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))
    return int(result['status'] != 'PASS')


if __name__ == '__main__':
    raise SystemExit(main())
