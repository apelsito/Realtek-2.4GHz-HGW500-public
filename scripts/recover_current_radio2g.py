"""Offline batch REA export of the exact three recorded Realtek modules.

Invoke with WSL REA-Linux python3. Output must be a new timestamped directory.
Never modifies a source module, runtime, REA installation or physical router.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
from datetime import datetime, timezone


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--workspace', type=Path, required=True)
    parser.add_argument('--lab', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--modules', nargs='+', default=['rtl8192ee', 'rtl_pci', 'rtlwifi'])
    args = parser.parse_args()
    if any(m not in {'rtl8192ee', 'rtl_pci', 'rtlwifi'} for m in args.modules):
        raise ValueError('Only the three exact recorded radio2g modules are admitted')
    args.output.mkdir(parents=True, exist_ok=False)
    lab = json.loads((args.lab / 'manifest.json').read_text())
    source_dir = args.workspace / 'outputs/rea/arc700-20261021-r2/current-radio2g'
    source_manifest = json.loads((source_dir / 'manifest.json').read_text())
    source_rows = {r['name']: r for r in source_manifest['artifacts']}
    tool_prefix = args.workspace / 'work/toolchains/arc-uclibc/arc-arc700-linux-uclibc/bin/arc-snps-linux-uclibc-'
    env = os.environ.copy()
    env.update(JAVA_HOME='/usr/lib/jvm/java-21-openjdk-amd64', GHIDRA_INSTALL_DIR=lab['ghidra'])
    started = datetime.now(timezone.utc).isoformat()
    results = []
    for module in args.modules:
        source = source_dir / (module + '.ko')
        pin = source_rows[module]
        if source.stat().st_size != pin['bytes'] or sha(source) != pin['sha256']:
            raise ValueError('Recorded source hash/size mismatch: ' + module)
        module_dir = args.output / module
        module_dir.mkdir()
        link_dir = module_dir / 'analysis-link'
        entries = {'rtl8192ee': 'init_module', 'rtl_pci': 'rtl_pci_probe', 'rtlwifi': 'init_module'}
        command = [sys.executable, str(args.workspace / 'tools/link_arc700_analysis_image.py'),
                   '--input', str(source), '--output', str(link_dir), '--entry', entries[module]]
        proc = subprocess.run(command, env=env, capture_output=True)
        (module_dir / 'link-run.stdout').write_bytes(proc.stdout)
        (module_dir / 'link-run.stderr').write_bytes(proc.stderr)
        if proc.returncode:
            raise RuntimeError('Analysis-only link failed for ' + module)
        link_manifest = json.loads((link_dir / 'manifest.json').read_text())
        target = Path(link_manifest['derived']['path'])
        symbols_text = subprocess.check_output([str(tool_prefix) + 'nm', '-S', '--defined-only', '-n', str(target)], text=True)
        (module_dir / 'symbols-sized.txt').write_text(symbols_text)
        symbols = []
        for line in symbols_text.splitlines():
            fields = line.split()
            if len(fields) == 4 and fields[2] in {'t', 'T', 'w', 'W'}:
                symbols.append({'address': hex(int(fields[0], 16)), 'size': int(fields[1], 16),
                                'type': fields[2], 'name': fields[3]})
        symbol_path = module_dir / 'symbols.json'
        symbol_path.write_text(json.dumps(symbols, indent=2) + '\n')
        # GNU ARC disassembly is an independent decoder to compare with Ghidra.
        disassembly = subprocess.check_output([str(tool_prefix) + 'objdump', '-d', str(target)])
        (module_dir / 'gnu-arc-disassembly.txt').write_bytes(disassembly)
        node_command = ['node', str(args.workspace / 'realtek/scripts/rea_batch_arc700.mjs'),
                        str(args.lab), str(target), str(module_dir / 'rea'), str(symbol_path)]
        print(json.dumps({'phase': 'module', 'module': module, 'symbols': len(symbols)}), flush=True)
        with (module_dir / 'batch.stdout').open('wb') as stdout, (module_dir / 'batch.stderr').open('wb') as stderr:
            completed = subprocess.run(node_command, env=env, stdout=stdout, stderr=stderr, timeout=7200)
        result_path = module_dir / 'rea/result.json'
        result = json.loads(result_path.read_text()) if result_path.exists() else {'failure': 'batch result missing'}
        results.append({'module': module, 'original_sha256': pin['sha256'], 'original_bytes': pin['bytes'],
                        'original_unchanged': sha(source) == pin['sha256'], 'batch_exit_code': completed.returncode,
                        'defined_code_symbols': len(symbols),
                        'symbols_covered': result.get('symbols_covered', 0),
                        'pseudocode_entries': result.get('pseudocode_entries', 0),
                        'failed_entries': result.get('failed_entries', 0),
                        'entries_with_warning_lines': result.get('entries_with_warning_lines', 0),
                        'result': str(result_path.relative_to(args.output))})
        (args.output / 'result.json').write_text(json.dumps({
            'schema': 'realtek.radio2g-static-recovery/v1',
            'started_utc': started, 'updated_utc': datetime.now(timezone.utc).isoformat(),
            'status': 'EXPORTED_UNVALIDATED' if len(results) == len(args.modules) else 'IN_PROGRESS',
            'hardware_accessed': False, 'rea_installation_modified': False,
            'lab_manifest_sha256': sha(args.lab / 'manifest.json'), 'modules': results,
        }, indent=2) + '\n')
        print(json.dumps(results[-1]), flush=True)
    return int(any(r['batch_exit_code'] != 0 or not r['original_unchanged'] for r in results))


if __name__ == '__main__':
    raise SystemExit(main())
