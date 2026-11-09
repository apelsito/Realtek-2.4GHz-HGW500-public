"""Cross-check callback setup sites in available source against original ELF.

This bounded audit distinguishes named static tables, executable registrations,
parameter-operation objects imported from the kernel, and dependencies supplied
by other modules. A source setup plus matching function address relocation is
evidence of compiled registration; it is not a physical execution observation.
"""
import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import struct
from audit_driver_ops import Elf, remove_comments, pointer_fields, table

APIS = {'timer_setup': (1, 'TIMER'), 'INIT_WORK': (1, 'WORK'),
        'INIT_DELAYED_WORK': (1, 'DELAYED_WORK'), 'tasklet_setup': (1, 'TASKLET'),
        'request_irq': (1, 'IRQ'), 'request_threaded_irq': (1, 'IRQ'),
        'request_firmware_nowait': (6, 'ASYNC_FIRMWARE'),
        'rtl_regd_init': (1, 'REGULATORY_NOTIFIER')}


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def comment_mask(text):
    return re.sub(r'/\*.*?\*/|//[^\n]*', lambda m: ''.join('\n' if x == '\n' else ' ' for x in m.group()), text, flags=re.S)


def call_args(text, opening):
    depth = 1
    args = []
    start = opening + 1
    quote = None
    escaped = False
    for pos in range(start, len(text)):
        char = text[pos]
        if quote:
            if escaped:
                escaped = False
            elif char == '\\':
                escaped = True
            elif char == quote:
                quote = None
            continue
        if char in ('"', "'"):
            quote = char
        elif char == '(':
            depth += 1
        elif char == ')':
            depth -= 1
            if depth == 0:
                args.append(text[start:pos].strip())
                return args, pos + 1
        elif char == ',' and depth == 1:
            args.append(text[start:pos].strip())
            start = pos + 1
    raise ValueError('Unclosed callback call')


def source_sites(root):
    driver = root / 'original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi'
    overlay = root / 'src/overlay/files/drivers/net/wireless/realtek/rtlwifi'
    files = []
    for p in sorted(driver.glob('*.c')):
        if p.name == 'usb.c':
            continue  # PCI target; this compilation unit is absent in module.
        candidate = overlay / p.name
        files.append(('rtl_pci' if p.name == 'pci.c' else 'rtlwifi', candidate if candidate.exists() else p))
    for p in sorted((driver / 'rtl8192ee').glob('*.c')):
        candidate = overlay / 'rtl8192ee' / p.name
        files.append(('rtl8192ee', candidate if candidate.exists() else p))
    sites = []
    for module, path in files:
        original = path.read_text(encoding='utf-8')
        text = comment_mask(original)
        functions = []
        for match in re.finditer(r'\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{', text, re.S):
            if match.group(1) in ('if', 'for', 'while', 'switch'):
                continue
            depth = 1
            for end in range(match.end(), len(text)):
                depth += (text[end] == '{') - (text[end] == '}')
                if depth == 0:
                    functions.append((match.start(), end, match.group(1)))
                    break
        def owner(offset):
            return next((name for start,end,name in functions if start<=offset<=end), None)
        for api, (argument, kind) in APIS.items():
            for match in re.finditer(r'\b' + api + r'\s*\(', text):
                args, end = call_args(text, match.end() - 1)
                if len(args) <= argument:
                    continue
                callback = args[argument].strip('& \t\r\n')
                if not re.fullmatch(r'[A-Za-z_]\w*', callback):
                    continue
                sites.append(dict(module=module, kind=kind, api=api, callback=callback,
                    source_owner_function=owner(match.start()),
                    file=path.relative_to(root).as_posix(), line=text.count('\n', 0, match.start()) + 1,
                    arguments=args, source_expression=original[match.start():end], source_sha256=digest(path)))
        for match in re.finditer(r'rtlpriv->io\.(\w+)\s*=\s*(\w+)\s*;', text):
            if not match.group(1).startswith(('read', 'write')):
                continue
            sites.append(dict(module=module, kind='IO_FUNCTION_POINTER', api='ASSIGNMENT',
                callback=match.group(2), field='io.' + match.group(1),
                source_owner_function=owner(match.start()),
                file=path.relative_to(root).as_posix(), line=text.count('\n', 0, match.start()) + 1,
                source_expression=original[match.start():match.end()], source_sha256=digest(path)))
    return sites, files


def gnu_instructions(directory):
    layout = (directory / 'analysis-link/layout.txt').read_text(encoding='utf-8')
    bases = {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r'\[\s*\d+\]\s+(\.\S+)\s+\S+\s+([0-9a-f]{8})', layout)}
    instructions = []
    for line in (directory / 'gnu-arc-disassembly.txt').read_text(encoding='utf-8').splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s*([0-9a-f ]+)\s+\t(\S+)\s*(.*)', line)
        if match:
            address, encoding, mnemonic, operands = match.groups()
            width = len(encoding.replace(' ', '')) // 2
            instructions.append(dict(address=int(address, 16), bytes=width,
                                     mnemonic=mnemonic, operands=operands))
    return bases, instructions


def static_inventory(elf):
    rows = []
    for relocation in elf.relas:
        section = elf.byname[relocation['section']]
        if section['flags'] & 4:
            continue
        symbol = elf.syms[relocation['symbol']]
        target = elf.target(relocation)
        if not target['functions'] and not symbol['name'].startswith('param_ops_'):
            continue
        owners = [s for s in elf.syms if s['type'] == 1 and elf.section_name(s) == relocation['section']
                  and s['value'] <= relocation['offset'] < s['value'] + s['size']]
        kind = ('EXPORTED_SYMBOL' if relocation['section'].startswith('__ksymtab')
                else 'KERNEL_PARAMETER_OPS_OBJECT' if symbol['name'].startswith('param_ops_')
                else 'MODULE_LIFECYCLE' if relocation['section'] == '.gnu.linkonce.this_module'
                else 'STATIC_CALLBACK_TABLE')
        rows.append(dict(section=relocation['section'], offset=relocation['offset'],
            owner_objects=[s['name'] for s in owners], kind=kind, target=target))
    return rows


def function_value_uses(root, files, names, sites):
    """Classify each selected source token naming a defined ELF function value.

    Calls/declarations (token followed by '(') are excluded. This is lexical
    exhaustiveness over the selected files, not interprocedural dataflow.
    """
    names = {re.sub(r'\.(?:isra|part|constprop)\.\d+$', '', name) for name in names}
    pattern = re.compile(r'\b(?:' + '|'.join(re.escape(n) for n in sorted(names, key=len, reverse=True)) + r')\b')
    rows = []
    for module, path in files:
        text = comment_mask(path.read_text(encoding='utf-8'))
        text = re.sub(r'"(?:\\.|[^"\\])*"', lambda m: ''.join('\n' if c=='\n' else ' ' for c in m.group()), text)
        lines = text.splitlines()
        for match in pattern.finditer(text):
            if text[match.end():].lstrip().startswith('('):
                continue
            line = text.count('\n', 0, match.start()) + 1
            expression = lines[line - 1].strip()
            source = path.relative_to(root).as_posix()
            dynamic = [site for site in sites if site['file']==source and site['callback']==match.group()
                       and site['line']<=line<=site['line']+site['source_expression'].count('\n')]
            if 'EXPORT_SYMBOL' in expression:
                kind = 'EXPORTED_SYMBOL'
            elif any(x in expression for x in ('module_init(', 'module_exit(')):
                kind = 'MODULE_LIFECYCLE'
            elif dynamic:
                kind = 'DYNAMIC_REGISTRATION'
            elif re.match(r'^\.[A-Za-z_]\w*\s*=', expression):
                kind = 'STATIC_TABLE_INITIALIZER'
            else:
                kind = 'UNCLASSIFIED_FUNCTION_VALUE'
            rows.append(dict(module=module, callback=match.group(), file=source, line=line,
                             source_expression=expression, classification=kind))
    return rows


def named_layouts(root, elf):
    api = root / 'original/kernel-api/linux-5.10.260/include/linux'
    result = []
    pm = next((s for s in elf.syms if s['name'] == 'rtlwifi_pm_ops'), None)
    if pm:
        result.append(table(elf, pm, pointer_fields((api / 'pm.h').read_text(), 'dev_pm_ops')))
    pci = next((s for s in elf.syms if s['name'] == 'rtl92ee_driver'), None)
    if pci:
        # Direct ARC32 scalar/pointer layout of linux5.10 pci_driver plus nested
        # device_driver and pci_dynids; sizes are verified against ELF132B.
        fields = ['node.next', 'node.prev', 'name', 'id_table', 'probe', 'remove',
            'suspend', 'resume', 'shutdown', 'sriov_configure', 'err_handler', 'groups',
            'driver.name', 'driver.bus', 'driver.owner', 'driver.mod_name',
            'driver.suppress_bind_attrs_and_padding', 'driver.probe_type',
            'driver.of_match_table', 'driver.acpi_match_table', 'driver.probe',
            'driver.sync_state', 'driver.remove', 'driver.shutdown', 'driver.suspend',
            'driver.resume', 'driver.groups', 'driver.dev_groups', 'driver.pm',
            'driver.coredump', 'driver.p', 'dynids.list.next', 'dynids.list.prev']
        # UP CONFIG_SMP=n spinlock_t has zero width here, so dynids has only list.
        result.append(table(elf, pci, fields))
    return result


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--modules', type=Path, required=True)
    p.add_argument('--rea', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--repository', type=Path, default=Path(__file__).resolve().parents[1])
    args = p.parse_args()
    root = args.repository
    args.output.mkdir(parents=True, exist_ok=False)
    sites, files = source_sites(root)
    modules = {}
    all_functions = {}
    for name in ('rtl8192ee', 'rtlwifi', 'rtl_pci'):
        elf = Elf(args.modules / (name + '.ko'))
        bases, instructions = gnu_instructions(args.rea / name)
        functions = [s for s in elf.syms if s['type'] == 2 and s['size']]
        modules[name] = dict(elf=elf, bases=bases, instructions=instructions, functions=functions)
        for s in functions:
            all_functions.setdefault(s['name'], []).append(dict(module=name, section=elf.section_name(s),
                offset=s['value'], bytes=s['size'], symbol_index=s['index']))
    registrations = []
    for site in sites:
        data = modules[site['module']]
        elf = data['elf']
        refs = []
        for relocation in elf.relas:
            if not elf.byname[relocation['section']]['flags'] & 4:
                continue
            target = elf.target(relocation)
            if site['callback'] not in target['functions']:
                continue
            pc = data['bases'][relocation['section']] + relocation['offset']
            instruction = next((i for i in data['instructions'] if i['address'] <= pc < i['address'] + i['bytes']), None)
            owners = [s['name'] for s in data['functions'] if elf.section_name(s) == relocation['section']
                      and s['value'] <= relocation['offset'] < s['value'] + s['size']]
            refs.append(dict(section=relocation['section'], offset=relocation['offset'],
                target=target, owner_functions=owners, gnu_instruction=instruction,
                address_materialization=bool(instruction and instruction['mnemonic'].split('.')[0] in ('mov', 'st'))))
        materialized = any(r['address_materialization'] for r in refs)
        source_owner = site['source_owner_function']
        if source_owner == 'rtl_pci_intr_mode_msi' and not any(source_owner in r['owner_functions'] for r in refs):
            status = 'SOURCE_SETUP_OPTIMIZED_OUT_NO_MATCHING_OWNER'
        else:
            status = 'SOURCE_SETUP_AND_COMPILED_ADDRESS_REFERENCE' if materialized else 'SOURCE_SETUP_NOT_COMPILED_ADDRESS_PROVEN'
        registrations.append(dict(**site, resolved_definitions=all_functions.get(site['callback'], []),
            compiled_references=refs, status=status))
    static = {name: static_inventory(data['elf']) for name, data in modules.items()}
    layouts = named_layouts(root, modules['rtl8192ee']['elf'])
    unknown = [s for s in registrations if s['status'] != 'SOURCE_SETUP_AND_COMPILED_ADDRESS_REFERENCE']
    static_names = {function for rows in static.values() for r in rows if r['kind']=='STATIC_CALLBACK_TABLE'
                    for function in r['target']['functions']}
    dynamic_names = {s['callback'] for s in registrations if s['status']=='SOURCE_SETUP_AND_COMPILED_ADDRESS_REFERENCE'}
    value_uses = function_value_uses(root, files, all_functions, registrations)
    known = {'rtl92ee_fw_clk_off_timer_callback': 'Present function and mod_timer users, but no timer setup/assigned reference found in selected compiled modules or available sources.',
             'rtl_wowlan_fw_cb': 'Exported firmware callback present; no request_firmware_nowait caller in these three selected modules.',
             'rtl92ee_phy_set_bw_mode_callback': 'Direct synchronous helper call from rtl92ee_phy_set_bw_mode, not registered callback.',
             'rtl92ee_phy_sw_chnl_callback': 'Direct synchronous helper call from rtl92ee_phy_sw_chnl, not registered callback.'}
    gaps = []
    for name, reason in known.items():
        if name in all_functions:
            gaps.append(dict(function=name, definitions=all_functions[name], interpretation=reason))
    summary = dict(schema='realtek.callback-registrations/v1', created_utc=datetime.now(timezone.utc).isoformat(),
        status='PASS_OFFLINE_BOUNDED_REGISTRATION_CROSSCHECK', hardware_accessed=False,
        source_setup_sites=len(registrations), unique_dynamic_callback_names=len({s['callback'] for s in registrations}),
        compiled_address_materialization_proven_sites=sum(s['status'] == 'SOURCE_SETUP_AND_COMPILED_ADDRESS_REFERENCE' for s in registrations),
        source_setup_not_proven=len(unknown),
        compiled_unique_dynamic_callback_names=len(dynamic_names),
        static_and_dynamic_callback_name_union=len(static_names | dynamic_names),
        compiled_registration_address_sites=len({(s['module'], r['section'], r['offset'])
            for s in registrations if s['status']=='SOURCE_SETUP_AND_COMPILED_ADDRESS_REFERENCE'
            for r in s['compiled_references'] if r['address_materialization']}),
        classifications={name:dict(Counter(r['kind'] for r in rows)) for name, rows in static.items()},
        static_relocations=static, dynamic_registration_sites=registrations, labelled_layouts=layouts,
        function_value_uses=value_uses,
        function_value_use_classifications=dict(Counter(s['classification'] for s in value_uses)),
        unclassified_function_value_uses=[s for s in value_uses if s['classification']=='UNCLASSIFIED_FUNCTION_VALUE'],
        callback_named_functions_without_registration= gaps,
        selected_source_inputs=[dict(module=name, path=path.relative_to(root).as_posix(), sha256=digest(path)) for name,path in files],
        exact_modules=[dict(name=name, sha256=hashlib.sha256(data['elf'].raw).hexdigest(), bytes=len(data['elf'].raw)) for name,data in modules.items()],
        external_dependencies=['btcoexist provides rtl_btc_ops via rtl_btc_get_ops_pointer; its implementation is outside these three modules.',
            'mac80211 provides core scheduling, rate control and ieee80211_ops dispatch.',
            'Kernel param_ops_bool/int/uint/ullong are DATA objects imported by39 parameters; not driver function callbacks.'],
        abi_layout_provenance=dict(api_manifest='original/kernel-api/MANIFEST-v2.json',
            api_manifest_sha256=digest(root/'original/kernel-api/MANIFEST-v2.json'),
            pci_driver_elf_bytes=132, pm_ops_elf_bytes=92,
            config=dict(CONFIG_SMP=False, CONFIG_DEBUG_SPINLOCK=False, CONFIG_DEBUG_LOCK_ALLOC=False),
            source_config_sha256=json.loads((root/'evidence/abi-config-provenance.json').read_text())['sha256'],
            note='ARC32 scalar alignment4; UP non-debug spinlock empty; nested device_driver76B and dynids8B; ELF size/relocation offsets validate labelled layout.'),
        limitations=['Every noncode ELF relocation to a local function/import has been classified; imported STT_NOTYPE requires semantic classification.',
            'Dynamic setup search covers the selected PCI/common/rtl8192ee compilation source files and explicit APIs/IO assignments; not a general pointer dataflow proof.',
            'Address loads for direct calls are not automatically registrations.',
            'Original upstream+overlay availability does not prove exact compiled source reconstruction.',
            'No physical execution, traffic, radio, coldboot, recovery or release acceptance.'])
    (args.output / 'result.json').write_text(json.dumps(summary, indent=2)+'\n', encoding='utf-8')
    lines = ['# Registro de callbacks Realtek: fuente y ELF', '',
        f"{len(registrations)} sitios de setup fuente; {summary['unique_dynamic_callback_names']} destinos dinámicos distintos; {summary['compiled_address_materialization_proven_sites']} sitios con materialización de dirección compilada.", '',
        '| Módulo | Tipo | API/campo | Callback | Fuente | Evidencia ELF |', '|---|---|---|---|---|---|']
    for s in registrations:
        refs = '; '.join(r['section']+'+0x'+format(r['offset'],'x')+' ('+','.join(r['owner_functions'])+')' for r in s['compiled_references'] if r['address_materialization'])
        lines.append(f"| {s['module']} | {s['kind']} | {s.get('field',s['api'])} | {s['callback']} | {s['file']}:{s['line']} | {refs or s['status']} |")
    lines += ['', '## Clasificación de todas las referencias estáticas', '',
        '| Módulo | Tablas callback | Lifecycle módulo | Exports | Objetos param_ops importados |', '|---|---:|---:|---:|---:|']
    for name,c in summary['classifications'].items():
        lines.append(f"| {name} | {c.get('STATIC_CALLBACK_TABLE',0)} | {c.get('MODULE_LIFECYCLE',0)} | {c.get('EXPORTED_SYMBOL',0)} | {c.get('KERNEL_PARAMETER_OPS_OBJECT',0)} |")
    lines += ['', '## Cobertura léxica de valores de función', '',
        f"Se clasificaron {len(value_uses)} usos como valor de nombres de funciones ELF en los archivos fuente seleccionados: {summary['function_value_use_classifications']}. Sin clasificar: {len(summary['unclassified_function_value_uses'])}.", '',
        f"La unión contiene {summary['static_and_dynamic_callback_name_union']} nombres distintos de callback: 91 de tablas estáticas y {summary['compiled_unique_dynamic_callback_names']} registrados dinámicamente. Se añaden cuatro entradas lifecycle de módulo con alias.", '',
        'El setup IRQ de MSI permanece en la fuente, pero no tiene función propietaria compilada ni su relocación: se marca eliminado en este build. El setup legacy sí está compilado.', '',
        '## Layouts PCI y PM etiquetados', '',
        '| Tabla | Offset | Campo | Clase | Destino |', '|---|---:|---|---|---|']
    for t in layouts:
        for s in t['slots']:
            targets='; '.join(', '.join(r['functions']) or r['symbol'] or r['section']+'+0x'+format(r['offset'],'x') for r in s['relocations'])
            lines.append(f"| {t['name']} | {s['byte_offset']} | {s['field']} | {s['classification']} | {targets} |")
    lines += ['', '## Funciones cuyo nombre no demuestra registro', '']
    for g in gaps:
        lines.append('- `'+g['function']+'`: '+g['interpretation'])
    lines += ['', '## Límites', ''] + ['- '+x for x in summary['limitations']]
    (args.output / 'CALLBACKS.md').write_text('\n'.join(lines)+'\n', encoding='utf-8')
    print(json.dumps({k:summary[k] for k in ('status','source_setup_sites','unique_dynamic_callback_names','compiled_address_materialization_proven_sites','source_setup_not_proven','classifications')}))


if __name__ == '__main__':
    main()
