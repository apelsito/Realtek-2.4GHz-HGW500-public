"""Offline ELF32 ARC driver and callback inventory.

Reads original ET_REL modules without linking, disassembly or device access.
Source definition matches establish availability only, not compile equivalence.
The ELF parser follows the project qualify_f370_qdrv_module.py section/symbol
and RELA approach; this portable copy has no dependency on the parent workspace.
"""
import argparse
from collections import Counter, defaultdict
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import struct


def sha(data):
    return hashlib.sha256(data).hexdigest()


class Elf:
    def __init__(self, path):
        self.path = Path(path)
        self.raw = self.path.read_bytes()
        if self.raw[:6] != b'\x7fELF\x01\x01':
            raise ValueError('Expected ELF32 little endian: ' + str(path))
        if struct.unpack_from('<HH', self.raw, 16) != (1, 93):
            raise ValueError('Expected ET_REL / EM_ARC_COMPACT=93: ' + str(path))
        off = struct.unpack_from('<I', self.raw, 32)[0]
        size, count, strings = struct.unpack_from('<HHH', self.raw, 46)
        raw_sections = [struct.unpack_from('<10I', self.raw, off + i * size)
                        for i in range(count)]
        names = self.raw[raw_sections[strings][4]:
                         raw_sections[strings][4] + raw_sections[strings][5]]
        self.sections = []
        for index, s in enumerate(raw_sections):
            name = names[s[0]:names.index(0, s[0])].decode('utf-8')
            self.sections.append(dict(index=index, name=name, type=s[1],
                flags=s[2], offset=s[4], size=s[5], link=s[6], info=s[7],
                align=s[8], entsize=s[9],
                data=b'' if s[1] == 8 else self.raw[s[4]:s[4] + s[5]]))
        self.byname = {s['name']: s for s in self.sections}
        symbols = self.byname['.symtab']
        names = self.sections[symbols['link']]['data']
        self.syms = []
        for p in range(0, len(symbols['data']), symbols['entsize']):
            name, value, length, info, other, section = struct.unpack_from(
                '<IIIBBH', symbols['data'], p)
            self.syms.append(dict(index=len(self.syms),
                name=names[name:names.index(0, name)].decode('utf-8'),
                value=value, size=length, type=info & 15, bind=info >> 4,
                other=other, section=section))
        self.relas = []
        for section in self.sections:
            if section['type'] != 4:
                continue
            for p in range(0, len(section['data']), section['entsize']):
                offset, info, addend = struct.unpack_from('<IIi', section['data'], p)
                self.relas.append(dict(section=self.sections[section['info']]['name'],
                    offset=offset, type=info & 255, symbol=info >> 8, addend=addend))

    def section_name(self, symbol):
        index = symbol['section']
        if index == 0:
            return 'UND'
        return self.sections[index]['name'] if index < len(self.sections) else str(index)

    def target(self, relocation):
        symbol = self.syms[relocation['symbol']]
        section = self.section_name(symbol)
        offset = symbol['value'] + relocation['addend']
        matches = [s['name'] for s in self.syms if s['type'] == 2
                   and self.section_name(s) == section and s['value'] == offset]
        result = dict(symbol=symbol['name'], section=section, offset=offset,
                      addend=relocation['addend'], relocation_type=relocation['type'],
                      functions=matches, imported=section == 'UND')
        # ELF ET_REL undefined symbols often have STT_NOTYPE. kernel_param
        # references param_ops_* objects, never imported callback functions.
        imported_object = symbol['name'].startswith('param_ops_')
        if section == 'UND' and symbol['name'] and not imported_object:
            result['functions'] = [symbol['name']]
        result['import_kind'] = 'DATA_OBJECT' if imported_object else 'FUNCTION_OR_UNKNOWN' if section == 'UND' else None
        return result


def remove_comments(text):
    return re.sub(r'/\*.*?\*/|//[^\n]*', ' ', text, flags=re.S)


def struct_body(text, name):
    found = re.search(r'\bstruct\s+' + re.escape(name) + r'\s*\{', remove_comments(text))
    if not found:
        raise ValueError('Missing struct ' + name)
    text = remove_comments(text)
    start = found.end()
    depth = 1
    for end in range(start, len(text)):
        depth += (text[end] == '{') - (text[end] == '}')
        if depth == 0:
            return text[start:end]
    raise ValueError('Unclosed struct ' + name)


def configured_body(text, name, config):
    """Evaluate only the simple conditionals used by the selected ABI structs."""
    body = struct_body(text, name)
    active = [True]
    output = []
    for line in body.splitlines():
        condition = re.match(r'\s*#\s*(ifdef|ifndef|if)\s+(.+)', line)
        if condition:
            kind, expr = condition.groups()
            if kind in ('ifdef', 'ifndef'):
                value = bool(config.get(expr.strip(), False))
                if kind == 'ifndef':
                    value = not value
            else:
                found = re.fullmatch(r'IS_ENABLED\((CONFIG_\w+)\)', expr.strip())
                if not found:
                    raise ValueError('Unsupported layout conditional ' + expr)
                value = bool(config.get(found.group(1), False))
            active.append(active[-1] and value)
        elif re.match(r'\s*#\s*endif\b', line):
            active.pop()
        elif re.match(r'\s*#\s*else\b', line):
            active[-1] = active[-2] and not active[-1]
        elif re.match(r'\s*#', line):
            raise ValueError('Unsupported layout preprocessor line ' + line)
        elif active[-1]:
            output.append(line)
    if len(active) != 1:
        raise ValueError('Unclosed layout conditional ' + name)
    return '\n'.join(output)


def pointer_fields(text, name, config=None):
    """Return pointer-only layout; deliberately refuse scalar/mixed layouts."""
    body = configured_body(text, name, config or {})
    fields = re.findall(r'\(\s*\*\s*(\w+)\s*\)', body)
    if not fields:
        raise ValueError('No function pointers in ' + name)
    return fields


def rate_fields(text, config):
    body = configured_body(text, 'rate_control_ops', config)
    fields = []
    for declaration in body.split(';'):
        declaration = declaration.strip()
        if not declaration:
            continue
        pointer = re.search(r'\(\s*\*\s*(\w+)\s*\)', declaration)
        if pointer:
            fields.append(pointer.group(1))
        elif re.fullmatch(r'unsigned\s+long\s+capa', declaration):
            fields.append('capa')
        elif re.fullmatch(r'const\s+char\s*\*\s*name', declaration):
            fields.append('name')
        else:
            raise ValueError('Unrecognized rate_control_ops field ' + declaration)
    return fields


def source_matches(symbol_name, paths):
    name = re.sub(r'\.(?:isra|constprop|part)\.\d+$', '', symbol_name)
    expr = re.compile(r'\b' + re.escape(name) +
                      r'\s*\([^;{}]*\)\s*(?:__\w+\s*)?\{', re.S)
    return [str(path.relative_to(root)).replace('\\', '/')
            for root, path, text in paths if expr.search(text)]


def sources(root):
    if not root or not root.exists():
        return []
    return [(root, p, remove_comments(p.read_text(encoding='utf-8', errors='replace')))
            for p in sorted(root.rglob('*')) if p.is_file() and p.suffix in ('.c', '.h')]


def module_sources(name, rows):
    """Avoid attributing same-named static helpers to other chipset sources."""
    result = []
    for root, path, text in rows:
        relative = path.relative_to(root)
        if name == 'rtl8192ee':
            include = relative.parts[0] == 'rtl8192ee' or (len(relative.parts) == 1 and path.suffix == '.h')
        elif name == 'rtl_pci':
            include = len(relative.parts) == 1 and (path.name == 'pci.c' or path.suffix == '.h')
        else:
            include = len(relative.parts) == 1 and path.name != 'pci.c'
        if include:
            result.append((root, path, text))
    return result


def table(elf, symbol, fields=None):
    section = elf.byname[elf.section_name(symbol)]
    start = symbol['value']
    if symbol['size'] % 4:
        raise ValueError('Non pointer-width table ' + symbol['name'])
    slots = symbol['size'] // 4
    if fields is not None and len(fields) != slots:
        raise ValueError(f"{symbol['name']} layout mismatch: {len(fields)} fields / {slots} slots")
    relocs = defaultdict(list)
    for r in elf.relas:
        if r['section'] == section['name'] and start <= r['offset'] < start + symbol['size']:
            relocs[r['offset'] - start].append(r)
    result = []
    for slot in range(slots):
        offset = slot * 4
        raw = section['data'][start + offset:start + offset + 4]
        targets = [elf.target(r) for r in relocs[offset]]
        row = dict(slot=slot, byte_offset=offset,
                   field=fields[slot] if fields is not None else None,
                   raw_u32=struct.unpack('<I', raw)[0], relocations=targets)
        row['classification'] = ('FUNCTION_POINTER' if targets and all(t['functions'] for t in targets)
            else 'DATA_POINTER' if targets else 'NULL' if row['raw_u32'] == 0 else 'SCALAR_OR_RAW_POINTER')
        result.append(row)
    return dict(name=symbol['name'], section=section['name'], offset=start,
        bytes=symbol['size'], layout_fields_proven=fields is not None,
        slots=result, populated_callback_slots=sum(s['classification'] == 'FUNCTION_POINTER' for s in result),
        null_slots=sum(s['classification'] == 'NULL' for s in result))


TABLES = {'rtl8192ee': ['rtl8192ee_hal_ops', 'rtlwifi_pm_ops', 'rtl92ee_driver'],
          'rtlwifi': ['rtl_ops', 'rtl_rate_ops', 'efuse_ops'],
          'rtl_pci': ['rtl_pci_ops']}


def audit(args):
    args.output.mkdir(parents=True, exist_ok=False)
    current_source = sources(args.source)
    original_source = sources(args.original)
    config = json.loads(args.config.read_text(encoding='utf-8')) if args.config else {}
    wifi_header = (args.source / 'wifi.h').read_text(encoding='utf-8')
    layouts = dict(rtl8192ee_hal_ops=pointer_fields(wifi_header, 'rtl_hal_ops'),
                   rtl_pci_ops=pointer_fields(wifi_header, 'rtl_intf_ops'),
                   efuse_ops=pointer_fields(wifi_header, 'rtl_efuse_ops'))
    if args.mac80211 and args.mac80211.is_file():
        header = args.mac80211.read_text(encoding='utf-8')
        layouts['rtl_ops'] = pointer_fields(header, 'ieee80211_ops', config)
        layouts['rtl_rate_ops'] = rate_fields(header, config)
    if args.layouts:
        layouts.update(json.loads(args.layouts.read_text(encoding='utf-8')))
    modules = []
    hashes = {}
    for name in TABLES:
        path = args.modules / (name + '.ko')
        elf = Elf(path)
        before = sha(elf.raw)
        hashes[str(path)] = before
        funcs = [s for s in elf.syms if s['type'] == 2 and s['size'] > 0]
        ranges = defaultdict(list)
        function_rows = []
        current_module_source = module_sources(name, current_source)
        original_module_source = module_sources(name, original_source)
        for s in funcs:
            section_name = elf.section_name(s)
            data = elf.byname[section_name]['data'][s['value']:s['value'] + s['size']]
            ranges[(section_name, s['value'], s['size'])].append(s['name'])
            function_rows.append(dict(symbol_index=s['index'], name=s['name'],
                section=section_name, offset=s['value'], bytes=s['size'], sha256=sha(data),
                bind=s['bind'], source_definition_matches=source_matches(s['name'], current_module_source),
                original_definition_matches=source_matches(s['name'], original_module_source)))
        tables = [table(elf, next(s for s in elf.syms if s['type'] == 1 and s['name'] == t), layouts.get(t))
                  for t in TABLES[name]]
        reloc_coverage = []
        code_relocations = [r for r in elf.relas if elf.byname[r['section']]['flags'] & 4]
        for r in code_relocations:
            owners = [s['name'] for s in funcs if elf.section_name(s) == r['section']
                      and s['value'] <= r['offset'] < s['value'] + s['size']]
            reloc_coverage.append(dict(**r, owner_functions=owners, target=elf.target(r)))
        result = dict(name=name, path=str(path), sha256=before, bytes=len(elf.raw),
            symbols=len(elf.syms), function_symbols=len(funcs), unique_function_ranges=len(ranges),
            code_allocated_bytes=sum(s['size'] for s in elf.sections if s['flags'] & 4),
            relocations=len(elf.relas), code_relocations=len(code_relocations),
            code_relocations_without_function_owner=sum(not r['owner_functions'] for r in reloc_coverage),
            object_symbols=sum(s['type'] == 1 for s in elf.syms),
            compilation_units=[s['name'] for s in elf.syms if s['type'] == 4],
            imports=sorted({s['name'] for s in elf.syms if s['section'] == 0 and s['name']}),
            functions=function_rows, callback_tables=tables, code_relocation_ownership=reloc_coverage,
            current_source_definition_matches=sum(bool(r['source_definition_matches']) for r in function_rows),
            original_source_definition_matches=sum(bool(r['original_definition_matches']) for r in function_rows),
            source_definition_union_matches=sum(bool(r['source_definition_matches'] or r['original_definition_matches']) for r in function_rows),
            symbols_without_available_definition=[r['name'] for r in function_rows
                if not (r['source_definition_matches'] or r['original_definition_matches'])])
        (args.output / (name + '-inventory.json')).write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
        modules.append({k: v for k, v in result.items() if k not in ('functions', 'code_relocation_ownership')})
    for path, before in hashes.items():
        if sha(Path(path).read_bytes()) != before:
            raise ValueError('Original input drift: ' + path)
    summary = dict(schema='openmitrastar.realtek-ops-inventory/v1',
        created_utc=datetime.now(timezone.utc).isoformat(),
        status='PASS_OFFLINE_SYMBOL_RELOCATION_INVENTORY',
        hardware_accessed=False, original_modules_unchanged=True,
        function_symbols=sum(m['function_symbols'] for m in modules),
        unique_function_ranges=sum(m['unique_function_ranges'] for m in modules),
        core_module_bytes=sum(m['bytes'] for m in modules),
        total_relocations=sum(m['relocations'] for m in modules),
        populated_callback_slots=sum(t['populated_callback_slots'] for m in modules for t in m['callback_tables']),
        unique_callback_targets=len({(r['section'], r['offset'], r['symbol'], m['name'])
            for m in modules for t in m['callback_tables'] for s in t['slots']
            if s['classification'] == 'FUNCTION_POINTER' for r in s['relocations']}),
        source_definition_union_matches=sum(m['source_definition_union_matches'] for m in modules),
        abi_config=config,
        modules=modules, source_inputs=[dict(path=str(p), sha256=sha(p.read_bytes()))
                                      for _, p, _ in current_source + original_source],
        limits=['Symbol/relocation inventory is not source recovery or behavioral equivalence.',
                'Definition matches are lexical availability evidence only.',
                'NULL callback slots are real compiled absence, not missing functions.',
                'ET_REL offsets are section-relative, not physical or runtime addresses.',
                'Three core modules only; mac80211/cfg80211/crypto/btcoexist and firmware are separate dependencies.',
                'Physical client, traffic, boot, recovery, soak and release gates unrun.'])
    (args.output / 'result.json').write_text(json.dumps(summary, indent=2) + '\n', encoding='utf-8')
    lines = ['# Inventario de operaciones del núcleo Realtek', '',
             'Análisis offline de los módulos originales ET_REL ARC700. No se accedió al router.', '',
             '| Módulo | Bytes | Funciones ELF | Rangos únicos | RELA | Callbacks poblados |',
             '|---|---:|---:|---:|---:|---:|']
    for m in modules:
        lines.append(f"| {m['name']} | {m['bytes']} | {m['function_symbols']} | {m['unique_function_ranges']} | {m['relocations']} | {sum(t['populated_callback_slots'] for t in m['callback_tables'])} |")
    lines += ['', 'Los alias `init_module`/`cleanup_module` pueden aumentar el número de símbolos respecto a los rangos de código únicos.', '',
              f"Se resolvieron {summary['populated_callback_slots']} slots de callback poblados en siete tablas, con {summary['unique_callback_targets']} destinos únicos por identidad ELF de módulo/sección/offset.", '',
              'Las coincidencias de definiciones fuente indican disponibilidad; no prueban equivalencia de compilación. Los slots NULL son datos reales del módulo.', '',
              '| Módulo | Definición original | Definición overlay | Unión | Sin definición detectada |',
              '|---|---:|---:|---:|---:|']
    for m in modules:
        lines.append(f"| {m['name']} | {m['original_source_definition_matches']} | {m['current_source_definition_matches']} | {m['source_definition_union_matches']} | {len(m['symbols_without_available_definition'])} |")
    lines += ['', 'La búsqueda léxica incluye helpers inline de cabeceras y elimina comentarios. Los alias y funciones generadas por macros pueden no dar coincidencia.', '']
    for m in modules:
        for t in m['callback_tables']:
            lines += [f"## {m['name']}: {t['name']}", '',
                      '| Offset | Campo | Clase | Destino de relocación |', '|---:|---|---|---|']
            for s in t['slots']:
                target = '; '.join(', '.join(r['functions']) or r['symbol'] or f"{r['section']}+0x{r['offset']:x}" for r in s['relocations'])
                lines.append(f"| {s['byte_offset']} | {s['field'] or '(layout sin etiquetar)'} | {s['classification']} | {target} |")
            lines.append('')
    lines += ['## Límites', ''] + ['- ' + x for x in summary['limits']]
    (args.output / 'OPS.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in summary.items() if k not in ('modules', 'source_inputs')}))


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--modules', type=Path, required=True)
    p.add_argument('--source', type=Path, required=True)
    p.add_argument('--original', type=Path)
    p.add_argument('--mac80211', type=Path)
    p.add_argument('--layouts', type=Path)
    p.add_argument('--config', type=Path, help='JSON booleans for ABI layout conditional symbols')
    p.add_argument('--output', type=Path, required=True)
    audit(p.parse_args())


if __name__ == '__main__':
    main()
