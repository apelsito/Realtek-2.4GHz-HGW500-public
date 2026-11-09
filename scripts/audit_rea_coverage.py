"""Cross-check retained REA dossiers against ELF extents and GNU ARC disassembly.

This compares observation inventories, not semantic equivalence. Inputs unchanged.
"""
import argparse
import csv
from datetime import datetime, timezone
import gzip
import hashlib
import json
from pathlib import Path
import re


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    summary = json.loads((args.input / 'result.json').read_text())
    rows = []
    failures = []
    totals = {'defined_code_symbols': 0, 'unique_entries': 0, 'dossier_hashes_verified': 0,
              'pseudocode_hashes_verified': 0, 'assembly_hashes_verified': 0,
              'entries_with_warning_lines': 0, 'entries_with_missing_gnu_instruction_starts': 0,
              'entries_with_extra_ghidra_instruction_starts': 0, 'entries_with_body_size_difference': 0,
              'entries_with_unresolved_calls': 0, 'entries_with_truncated_high_pcode': 0}
    for module in summary['modules']:
        module_dir = args.input / module['module']
        rea_dir = module_dir / 'rea'
        result = json.loads((rea_dir / 'result.json').read_text())
        totals['defined_code_symbols'] += module['defined_code_symbols']
        gnu = {}
        for line in (module_dir / 'gnu-arc-disassembly.txt').read_text().splitlines():
            match = re.match(r'^\s*([0-9a-f]+):\s+([0-9a-f ]+)\s*\t([^\t]+)(?:\t(.*))?$', line)
            if match:
                gnu[int(match[1], 16)] = {'mnemonic': match[3].strip(), 'operands': (match[4] or '').strip()}
        for entry in result['entries']:
            totals['unique_entries'] += 1
            if entry['status'] != 'PSEUDOCODE_EXPORTED_UNVALIDATED':
                failures.append({'module': module['module'], 'entry': entry['aliases'], 'status': entry['status']})
                continue
            for field in ('dossier', 'pseudocode', 'assembly'):
                observed = hashlib.sha256((rea_dir / entry[field]).read_bytes()).hexdigest()
                if observed != entry[field + '_sha256']:
                    failures.append({'module': module['module'], 'entry': entry['aliases'], 'hash_failure': field})
                else:
                    totals[field + '_hashes_verified'] += 1
            dossier = json.load(gzip.open(rea_dir / entry['dossier']))['normalized_result']['value']
            address = int(entry['address'], 16)
            length = entry['elf_size_bytes']
            gnu_starts = {a for a in gnu if address <= a < address + length}
            ghidra_starts = {int(line.split(':')[0], 16) for line in dossier['assembly']}
            missing = sorted(gnu_starts - ghidra_starts)
            extra = sorted(ghidra_starts - gnu_starts)
            warnings = entry['warning_lines']
            unresolved = dossier['unresolved_calls']
            truncated = dossier['native_value_flow'].get('truncated', False)
            body_difference = entry['ghidra_body']['total_bytes'] != length
            totals['entries_with_warning_lines'] += bool(warnings)
            totals['entries_with_missing_gnu_instruction_starts'] += bool(missing)
            totals['entries_with_extra_ghidra_instruction_starts'] += bool(extra)
            totals['entries_with_body_size_difference'] += body_difference
            totals['entries_with_unresolved_calls'] += bool(unresolved)
            totals['entries_with_truncated_high_pcode'] += bool(truncated)
            rows.append({'module': module['module'], 'name': entry['aliases'][0], 'aliases': '|'.join(entry['aliases']),
                         'address': entry['address'], 'elf_size_bytes': length,
                         'ghidra_body_bytes': entry['ghidra_body']['total_bytes'],
                         'gnu_instruction_starts': len(gnu_starts), 'ghidra_instruction_starts': len(ghidra_starts),
                         'missing_gnu_instruction_starts': '|'.join(hex(a) for a in missing),
                         'extra_ghidra_instruction_starts': '|'.join(hex(a) for a in extra),
                         'warning_lines': len(warnings), 'unresolved_calls': len(unresolved),
                         'high_pcode_truncated': truncated,
                         'native_signature_source': dossier['native_api'].get('signature_source'),
                         'pseudocode': str((rea_dir / entry['pseudocode']).relative_to(args.input))})
    with (args.output / 'functions.csv').open('w', newline='', encoding='utf-8') as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    report = {'schema': 'realtek.rea-coverage-audit/v1',
              'created_utc': datetime.now(timezone.utc).isoformat(),
              'input_manifest_sha256': hashlib.sha256((args.input / 'result.json').read_bytes()).hexdigest(),
              'status': 'INVENTORY_AND_HASH_AUDIT_PASS' if not failures else 'FAILED',
              'totals': totals, 'failures': failures, 'hardware_accessed': False,
              'source_equivalence': 'UNPROVEN', 'compilation': 'NOT_PERFORMED',
              'limitations': ['Matching instruction starts does not validate ISA semantics, ABI, types or indirect call recovery.',
                              'GNU compares ELF symbol extents; Ghidra uses recovered bodies and may omit terminal alignment NOPs.',
                              'High p-code inventory may include decompiler artifacts or omit aliasing/call side effects.',
                              'Directory labels are not capture timestamps; result.json clocks identify actual execution.']}
    (args.output / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))
    return int(bool(failures))


if __name__ == '__main__':
    raise SystemExit(main())
