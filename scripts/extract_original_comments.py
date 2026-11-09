#!/usr/bin/env python3
"""Export original C and build-file comments verbatim, with source locations."""
import argparse
import hashlib
import json
import re
from pathlib import Path


def c_comments(text):
    """Lex comments while preserving quoted literals and escaped newlines."""
    i = 0
    size = len(text)
    while i < size:
        if text[i] in {'"', "'"}:
            quote = text[i]
            i += 1
            while i < size:
                if text[i] == "\\":
                    i += 2
                elif text[i] == quote:
                    i += 1
                    break
                else:
                    i += 1
            continue
        if text.startswith("/*", i):
            start = i
            end = text.find("*/", i + 2)
            if end < 0:
                raise ValueError("unterminated block comment")
            i = end + 2
            yield start, i, "block", text[start:i]
            continue
        if text.startswith("//", i):
            start = i
            i += 2
            while i < size:
                if text[i] == "\\" and text[i + 1:i + 3] == "\r\n":
                    i += 3
                elif text[i] == "\\" and text[i + 1:i + 2] == "\n":
                    i += 2
                elif text[i] in "\r\n":
                    break
                else:
                    i += 1
            yield start, i, "line", text[start:i]
            continue
        i += 1


def hash_comments(text):
    offset = 0
    for line in text.splitlines(keepends=True):
        quote = None
        escaped = False
        for index, char in enumerate(line):
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif quote:
                if char == quote:
                    quote = None
            elif char in {'"', "'"}:
                quote = char
            elif char == "#":
                end = len(line.rstrip("\r\n"))
                yield offset + index, offset + end, "hash", line[index:end]
                break
        offset += len(line)


def extract(repository):
    files, records = [], []
    for path in sorted((repository / "original").rglob("*"), key=lambda p: p.relative_to(repository).as_posix()):
        if not path.is_file():
            continue
        if path.suffix in {".c", ".h"}:
            parser = c_comments
        elif path.name in {"Makefile", "Kconfig"}:
            parser = hash_comments
        else:
            continue
        content = path.read_bytes()
        text = content.decode("utf-8")
        relative = path.relative_to(repository).as_posix()
        count = 0
        for start, end, kind, comment in parser(text):
            count += 1
            records.append({"id": len(records) + 1, "file": relative,
                            "line_start": text.count("\n", 0, start) + 1,
                            "line_end": text.count("\n", 0, end) + 1,
                            "character_start": start, "character_end": end,
                            "byte_start": len(text[:start].encode()), "byte_end": len(text[:end].encode()),
                            "kind": kind, "text": comment,
                            "sha256": hashlib.sha256(comment.encode()).hexdigest()})
        files.append({"path": relative, "sha256": hashlib.sha256(content).hexdigest(),
                      "bytes": len(content), "comments": count})
    return {"schema": "realtek.original-comments/v1", "comments": records, "files": files,
            "scope": "All .c/.h/Makefile/Kconfig in original/; verbatim comments, not decompiled code",
            "limitations": ["Compiled binaries do not retain source comments.",
                            "Coverage applies to the imported sources, not unavailable historical sources."]}


def render(result):
    lines = ["# Todos los comentarios de las fuentes originales", "",
             "Este documento conserva los comentarios literales de todos los archivos C, cabeceras, Makefile y Kconfig de `original/`, con archivo y líneas de procedencia. Incluye las fuentes upstream y las fuentes del port disponibles. No resume ni reescribe los comentarios.", "",
             "Los binarios compilados no conservan los comentarios originales. La cobertura corresponde a los archivos importados; no atribuye comentarios a fuentes históricas ausentes ni al pseudocódigo recuperado con REA.", "",
             f"Archivos examinados: {len(result['files'])}. Comentarios: {len(result['comments'])}.", "",
             "El índice JSON conserva offsets de byte, contenido literal y SHA-256; `original/` conserva los bytes completos.", ""]
    for comment in result["comments"]:
        maximum = max((len(x) for x in re.findall(r"`+", comment["text"])), default=0)
        fence = "`" * max(3, maximum + 1)
        lines.extend([f"## {comment['id']}. {comment['file']}:{comment['line_start']}", "",
                      f"Líneas {comment['line_start']}–{comment['line_end']}; tipo `{comment['kind']}`.", "",
                      fence + "text", comment["text"], fence, ""])
    lines.extend(["## Índice de archivos", "", "| Archivo | Comentarios |", "|---|---:|"])
    lines.extend(f"| `{row['path']}` | {row['comments']} |" for row in result["files"])
    return "\n".join(lines) + "\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repository", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--check", action="store_true", help="Verify committed exports without writing")
    args = parser.parse_args()
    repository = args.repository.resolve()
    result = extract(repository)
    expected = {repository / "docs" / "ORIGINAL_COMMENTS.md": render(result).encode(),
                repository / "evidence" / "original-comments.json": (json.dumps(result, ensure_ascii=False, indent=2) + "\n").encode()}
    for path, content in expected.items():
        if args.check:
            if not path.exists() or path.read_bytes() != content:
                raise SystemExit("comment export differs: " + str(path))
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(content)
    for row in result["comments"]:
        original = (repository / row["file"]).read_bytes()
        if original[row["byte_start"]:row["byte_end"]].decode() != row["text"]:
            raise SystemExit("comment byte range mismatch")
    print(json.dumps({"files": len(result["files"]), "comments": len(result["comments"]),
                      "verbatim_byte_ranges_verified": True, "check": args.check}))


if __name__ == "__main__":
    main()
