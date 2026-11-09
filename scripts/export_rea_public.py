"""Create an allowlisted sanitized REA export without logs or analysis ELF bytes.

Absolute private paths are replaced in nested dossier strings. Preserve raw
evidence locally; this derived export must use a new directory.
"""
import argparse
import csv
from datetime import datetime, timezone
import gzip
import hashlib
import io
import json
from pathlib import Path
import re


MAC = re.compile(r'(?i)(?<![0-9a-f])(?:[0-9a-f]{2}:){5}[0-9a-f]{2}(?![0-9a-f])')
SECRET = re.compile(r'(?i)(?:wpa_passphrase|wpa_psk|wifi_password|private[_ -]?key|api[_ -]?token|password)\s*[:=]\s*[\"\'][^\"\']{4,}')
WINDOWS_PATH = re.compile(r'[A-Za-z]:[/\\](?:Users|Program Files|Windows|Astra|Nau|Temp)[/\\][^\s\"\'<>]+', re.I)
LINUX_PATH = re.compile(r'/(?:mnt/[a-z]/Users/[^\s\"\'<>]+|home/[^\s\"\'<>]+|tmp/[^\s\"\'<>]+|run/[^\s\"\'<>]+)')


def sanitize(value):
    if isinstance(value, dict):
        return {key: sanitize(item) for key, item in value.items()}
    if isinstance(value, list):
        return [sanitize(item) for item in value]
    if isinstance(value, str):
        return WINDOWS_PATH.sub('[PRIVATE_PATH]', LINUX_PATH.sub('[PRIVATE_PATH]', value))
    return value


def check_text(text):
    findings = []
    if MAC.search(text):
        findings.append('mac_literal')
    if SECRET.search(text):
        findings.append('credential_literal')
    if WINDOWS_PATH.search(text) or LINUX_PATH.search(text):
        findings.append('private_absolute_path')
    return findings


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--audit', type=Path, required=True)
    parser.add_argument('--ops', type=Path, required=True)
    parser.add_argument('--repo', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    source_manifest = json.loads((args.input / 'result.json').read_text())
    audit = json.loads((args.audit / 'result.json').read_text())
    exports = []
    rejected = []
    reconciliation = []

    def output_file(relative, data, provenance):
        target = args.output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
        exports.append({'path': str(relative).replace('\\', '/'), 'bytes': len(data),
                        'sha256': hashlib.sha256(data).hexdigest(), 'source': provenance})

    for module in source_manifest['modules']:
        name = module['module']
        rea = args.input / name / 'rea'
        result = json.loads((rea / 'result.json').read_text())
        ops = json.loads((args.ops / (name + '-inventory.json')).read_text())
        symbol_definitions = {row['name']: row for row in ops['functions']}
        sanitized_entries = []
        for entry in result['entries']:
            exported_entry = {key: sanitize(item) for key, item in entry.items()
                              if key not in {'dossier_sha256', 'pseudocode_sha256', 'assembly_sha256', 'known_indirect_calls'}}
            for field in ('pseudocode', 'assembly', 'dossier'):
                source = rea / entry[field]
                if field == 'dossier':
                    raw = json.load(gzip.open(source))
                    sanitized = sanitize(raw)
                    text = json.dumps(sanitized, separators=(',', ':'))
                    if check_text(text):
                        # Keep safe analysis facts, omit literal program strings/names
                        # if the full dossier contains a sensitive literal.
                        rejected.append({'module': name, 'entry': entry['aliases'], 'field': field,
                                         'reason': check_text(text)})
                        for scope in ('raw_bridge_result', 'normalized_result'):
                            container = sanitized.get(scope, {})
                            facts = container.get('value', container)
                            for literal_field in ('referenced_strings', 'referenced_names', 'comments'):
                                if isinstance(facts, dict):
                                    facts[literal_field] = []
                        text = json.dumps(sanitized, separators=(',', ':'))
                    findings = check_text(text)
                    if findings:
                        raise ValueError('Sensitive literal remains in dossier ' + entry['aliases'][0] + ': ' + ','.join(findings))
                    data = gzip.compress(text.encode('utf-8'), compresslevel=9, mtime=0)
                    facts = raw['normalized_result']['value']
                    exported_entry['unresolved_calls'] = facts['unresolved_calls']
                    exported_entry['native_value_flow_truncated'] = facts['native_value_flow'].get('truncated')
                    exported_entry['native_signature_source'] = facts['native_api'].get('signature_source')
                else:
                    text = sanitize(source.read_text())
                    findings = check_text(text)
                    if findings:
                        raise ValueError('Sensitive literal in textual export ' + source.name + ': ' + ','.join(findings))
                    data = text.encode('utf-8')
                output_file(Path(name) / entry[field], data,
                            {'module': name, 'raw_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                             'kind': field, 'sanitized': True})
                exported_entry[field + '_sha256'] = hashlib.sha256(data).hexdigest()
            sanitized_entries.append(exported_entry)
        output_file(Path(name) / 'result.json', (json.dumps({
            'schema': 'realtek.rea-sanitized-module/v1', 'module': name,
            'original_sha256': module['original_sha256'], 'original_bytes': module['original_bytes'],
            'defined_code_symbols': module['defined_code_symbols'],
            'pseudocode_entries': module['pseudocode_entries'],
            'source_equivalence': 'UNPROVEN', 'entries': sanitized_entries,
        }, indent=2) + '\n').encode(), {'kind': 'module_summary'})
    audit_rows = list(csv.DictReader((args.audit / 'functions.csv').open()))
    for row in audit_rows:
        if not (row['missing_gnu_instruction_starts'] or row['extra_ghidra_instruction_starts']
                or row['high_pcode_truncated'] == 'True'):
            continue
        module = row['module']
        inventory = json.loads((args.ops / (module + '-inventory.json')).read_text())
        symbols = {symbol['name']: symbol for symbol in inventory['functions']}
        symbol = symbols[row['name']]
        sources = []
        for label, prefix, field in (
            ('original-linux-5.10.260', args.repo / 'original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi', 'original_definition_matches'),
            ('port-overlay', args.repo / 'src/overlay/files/drivers/net/wireless/realtek/rtlwifi', 'source_definition_matches')):
            for relative in symbol[field]:
                source = prefix / relative
                if not source.exists():
                    continue
                code = source.read_text()
                base_name = re.split(r'\.(?:constprop|isra|part)\.', row['name'])[0]
                match = re.search(r'\b' + re.escape(base_name) + r'\s*\(', code)
                sources.append({'kind': label, 'path': str(source.relative_to(args.repo)).replace('\\', '/'),
                                'sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
                                'first_identifier_line': code.count('\n', 0, match.start()) + 1 if match else None})
        reconciliation.append({'module': module, 'name': row['name'],
                               'elf_size_bytes': int(row['elf_size_bytes']),
                               'ghidra_body_bytes': int(row['ghidra_body_bytes']),
                               'source_definition_matches': sources,
                               'source_available': bool(sources),
                               'exact_binary_equivalence': 'UNPROVEN',
                               'issue': 'HIGH_PCODE_TRUNCATION' if row['high_pcode_truncated'] == 'True' else 'DECODER_OR_BOUNDARY_DIFFERENCE'})
    output_file(Path('coverage-audit.json'), (json.dumps(sanitize(audit), indent=2) + '\n').encode(), {'kind': 'audit_summary'})
    output_file(Path('functions.csv'), (args.audit / 'functions.csv').read_bytes(), {'kind': 'coverage_csv'})
    output_file(Path('source-reconciliation.json'), (json.dumps(reconciliation, indent=2) + '\n').encode(), {'kind': 'source_reconciliation'})
    export_manifest = {'schema': 'realtek.rea-public-export/v1',
                       'created_utc': datetime.now(timezone.utc).isoformat(),
                       'status': 'ALLOWLIST_AND_LITERAL_SCAN_PASS', 'hardware_accessed': False,
                       'source_manifest_sha256': hashlib.sha256((args.input / 'result.json').read_bytes()).hexdigest(),
                       'defined_code_symbols': 370, 'unique_entries': 366, 'modules': source_manifest['modules'],
                       'actual_started_utc': source_manifest['started_utc'], 'actual_finished_utc': source_manifest['updated_utc'],
                       'raw_logs_included': False, 'analysis_elf_included': False,
                       'absolute_private_paths_replaced': True, 'literal_filters': ['mac_literal', 'credential_literal', 'private_absolute_path'],
                       'literal_fields_omitted': rejected, 'files': exports,
                       'limitations': ['Sanitized derived evidence; original dossiers retained locally.',
                                       'Semantic and exact binary equivalence remain unproven.',
                                       'Source definition availability does not prove same patch lineage or binary equivalence.']}
    (args.output / 'manifest.json').write_text(json.dumps(export_manifest, indent=2) + '\n')
    print(json.dumps({'files': len(exports), 'entries': 366, 'source_reconciliation_entries': len(reconciliation),
                      'source_reconciliation_with_source': sum(row['source_available'] for row in reconciliation),
                      'literal_fields_omitted': len(rejected), 'output': str(args.output)}))


if __name__ == '__main__':
    main()
