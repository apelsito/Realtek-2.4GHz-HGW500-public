/** Export immutable offline REA dossiers using one Ghidra Program per module.
 * Runs in the pre-existing isolated REA-Linux ARC700 lane. Never loads firmware.
 */
import { readFile, writeFile, mkdir } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { gzipSync } from 'node:zlib';
import { pathToFileURL } from 'node:url';
import path from 'node:path';

const [labPath, targetPath, outputPath, symbolPath] = process.argv.slice(2);
if (!labPath || !targetPath || !outputPath || !symbolPath) {
  throw new Error('Usage: node rea_batch_arc700.mjs LAB TARGET NEW_OUTPUT SYMBOLS_JSON');
}
const sha = data => createHash('sha256').update(data).digest('hex');
const labBytes = await readFile(path.join(labPath, 'manifest.json'));
const lab = JSON.parse(labBytes);
const load = file => import(pathToFileURL(path.join(lab.runtime, 'dist', file)).href);
const [{ GhidraClient }, { GhidraHeadlessLauncher }, { inspectGhidraInstallation },
       { parseGhidraFunctionResult }, { silentLogger }, { ArtifactResourceScope },
       { AnalysisCleanupLease }] = await Promise.all([
  load('ghidra/GhidraClient.js'), load('ghidra/GhidraLauncher.js'),
  load('ghidra/GhidraInstallation.js'), load('ghidra/GhidraFunctionValues.js'),
  load('logger.js'), load('artifacts/ArtifactResourceScope.js'),
  load('artifacts/AnalysisCleanupLease.js'),
]);
await mkdir(outputPath, { recursive: false });
await mkdir(path.join(outputPath, 'functions'));
const inputBytes = await readFile(targetPath);
const inputSha = sha(inputBytes);
const symbols = JSON.parse(await readFile(symbolPath, 'utf8'));
const resources = new ArtifactResourceScope();
const resourceOwner = {
  retain: (owner, resource) => resources.retain({ kind: 'lease', resource,
    lease: AnalysisCleanupLease.forCloseOwner(owner, resource) }),
  run: operation => resources.run(operation),
};
const installation = await inspectGhidraInstallation({
  installDir: lab.ghidra, javaHome: '/usr/lib/jvm/java-21-openjdk-amd64',
  environment: process.env, resourceOwner,
});
if (installation.status !== 'available') {
  await writeFile(path.join(outputPath, 'installation-failure.json'), JSON.stringify(installation, null, 2));
  throw new Error('Pinned Ghidra installation unavailable');
}
const parameters = {
  operation: 'project-local-rea-batch-function-dossiers',
  language_id: lab.language_id, compiler_spec_id: lab.compiler_spec_id,
  upstream_rea_version: lab.upstream_version, lab_manifest_sha256: sha(labBytes),
  target_sha256: inputSha, function_selection: 'all-defined-elf-code-symbol-entries',
};
const client = new GhidraClient({
  startupTimeoutMs: 600000, platform: 'linux', transport: 'unix-socket',
  launcher: new GhidraHeadlessLauncher({
    environment: process.env, analyzeHeadlessPath: installation.analyzeHeadlessPath,
    configurationDirectoryName: installation.configurationDirectoryName,
    javaHome: installation.javaHome, javaVmName: installation.javaVmName,
    bridgeScriptPath: path.join(lab.runtime, 'bridge/ghidra/ReaGhidraBridge.java'),
    languageOverride: { languageId: lab.language_id, compilerSpecId: lab.compiler_spec_id },
    platform: 'linux',
  }),
  targetPath, targetSha256: inputSha, providerVersion: installation.providerVersion,
  profileDigest: sha(JSON.stringify(parameters)),
  expectedLanguageId: lab.language_id, expectedCompilerSpecId: lab.compiler_spec_id,
  logger: silentLogger,
});
const startedUtc = new Date().toISOString();
const entries = [];
let closed;
try {
  console.log(JSON.stringify({ phase: 'startup', target: path.basename(targetPath), symbols: symbols.length }));
  const started = await client.start();
  if (!started.ok) throw started.error;
  await writeFile(path.join(outputPath, 'session.json'), JSON.stringify(started.value, null, 2));
  const inventory = await client.callTool('list_procedures', { document: null });
  if (!inventory.ok) throw inventory.error;
  await writeFile(path.join(outputPath, 'ghidra-procedures.json'), JSON.stringify(inventory.value, null, 2));
  const groups = new Map();
  for (const symbol of symbols) {
    const rows = groups.get(symbol.address) ?? [];
    rows.push(symbol);
    groups.set(symbol.address, rows);
  }
  let ordinal = 0;
  for (const [address, aliases] of groups) {
    const primary = aliases[0];
    const key = String(++ordinal).padStart(4, '0') + '-' + primary.name.replace(/[^A-Za-z0-9_.-]/g, '_');
    const row = { address, aliases: aliases.map(s => s.name), elf_size_bytes: primary.size,
                  dossier: 'functions/' + key + '.json.gz', pseudocode: 'functions/' + key + '.c',
                  assembly: 'functions/' + key + '.assembly.txt' };
    try {
      const result = await client.callTool('analyze_function', { procedure: address });
      if (!result.ok) throw result.error;
      const normalized = parseGhidraFunctionResult('analyze_function', result.value);
      if (!normalized.ok) throw normalized.error;
      const value = normalized.value.value;
      await writeFile(path.join(outputPath, row.dossier), gzipSync(Buffer.from(JSON.stringify({
        provenance: 'project-local-REA-internal-Ghidra-bridge-batch', parameters,
        selected_elf_symbols: aliases, raw_bridge_result: result.value,
        normalized_result: normalized.value,
      })), { level: 9 }));
      const disclaimer = '/* ANALYSIS ONLY. Decompiled pseudocode, not original source or compilable driver.\n' +
        ' * ARC700 ABI, types, indirect calls and boundary recovery require validation.\n' +
        ' * ELF address: ' + address + '; aliases: ' + row.aliases.join(', ') + '\n */\n';
      await writeFile(path.join(outputPath, row.pseudocode), disclaimer + (value.pseudocode ?? ''));
      await writeFile(path.join(outputPath, row.assembly), (value.assembly ?? []).join('\n') + '\n');
      row.status = value.facet_availability?.pseudocode?.available && value.pseudocode?.trim()
        ? 'PSEUDOCODE_EXPORTED_UNVALIDATED' : 'NO_PSEUDOCODE';
      row.ghidra_name = value.procedure.name;
      row.ghidra_body = value.procedure.body;
      row.assembly_instructions = value.assembly?.length ?? 0;
      row.warning_lines = (value.pseudocode ?? '').split('\n').filter(x => /WARNING|BAD_|halt_baddata|unaff_|extraout_|in_stack_/i.test(x));
      row.unresolved_calls = value.unresolved_calls ?? [];
      row.native_value_flow_truncated = value.native_value_flow?.truncated ?? null;
      row.native_signature_source = value.native_api?.signature_source ?? null;
      row.relationship_coverage = normalized.value.relationshipCoverage ?? null;
      row.boundary_limitations = normalized.value.limitations;
      row.dossier_sha256 = sha(await readFile(path.join(outputPath, row.dossier)));
      row.pseudocode_sha256 = sha(await readFile(path.join(outputPath, row.pseudocode)));
      row.assembly_sha256 = sha(await readFile(path.join(outputPath, row.assembly)));
    } catch (error) {
      row.status = 'FAILED';
      row.failure = { name: error.name, message: error.message,
                      diagnostics: error.diagnostics ?? null };
    }
    entries.push(row);
    await writeFile(path.join(outputPath, 'progress.json'), JSON.stringify({ completed: ordinal,
      total_unique_entries: groups.size, latest: row.aliases[0], latest_status: row.status }, null, 2));
    console.log(JSON.stringify({ phase: 'function', ordinal, total: groups.size,
      name: row.aliases[0], status: row.status, warnings: row.warning_lines?.length ?? 0 }));
  }
} finally {
  closed = await client.close();
  await resources.retryCleanup();
  const sourceUnchanged = inputSha === sha(await readFile(targetPath));
  const result = {
    schema: 'realtek.rea-static-batch/v1', classification: 'ANALYSIS_ONLY_NEVER_LOAD_OR_FLASH',
    started_utc: startedUtc, finished_utc: new Date().toISOString(), parameters,
    target_unchanged: sourceUnchanged, hardware_accessed: false,
    defined_code_symbols: symbols.length, unique_entries_attempted: entries.length,
    symbols_covered: entries.filter(x => x.status === 'PSEUDOCODE_EXPORTED_UNVALIDATED').reduce((n, x) => n + x.aliases.length, 0),
    pseudocode_entries: entries.filter(x => x.status === 'PSEUDOCODE_EXPORTED_UNVALIDATED').length,
    failed_entries: entries.filter(x => x.status === 'FAILED').length,
    no_pseudocode_entries: entries.filter(x => x.status === 'NO_PSEUDOCODE').length,
    entries_with_warning_lines: entries.filter(x => x.warning_lines?.length).length,
    cleanup_ok: closed.ok, entries,
    limitations: [
      'REA adaptation and Ghidra ARCompact lane are project-local, not upstream certified ARC700 support.',
      'Coverage counts known ELF code-symbol entries; unidentified code and unresolved indirect targets may remain.',
      'Pseudocode retains decompiler warnings and does not establish source equivalence or compilation.',
      'Synthetic external symbols in the analysis ELF have no measured runtime addresses.',
      'No driver load, hardware, RF, client, traffic, cold boot, rollback or release acceptance is performed.',
    ],
  };
  await writeFile(path.join(outputPath, 'result.json'), JSON.stringify(result, null, 2));
  console.log(JSON.stringify({ phase: 'complete', symbols_covered: result.symbols_covered,
    failed_entries: result.failed_entries, cleanup_ok: result.cleanup_ok, target_unchanged: sourceUnchanged }));
}
