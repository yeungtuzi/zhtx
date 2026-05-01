#!/usr/bin/env python3
r"""
Fix unknown backslash escape sequences in LPC files.
Removes backslash when followed by a Chinese/UTF-8 character (byte >= 0x80).
Preserves valid escape sequences: \n \t \r \\ \" \' \a \b \f \v \0 \xNN

Usage:
  python3 tools/fix_escapes.py --dry-run    # preview changes
  python3 tools/fix_escapes.py              # apply fixes
"""

import json
import os
import re
import sys
import subprocess

SCAN_RESULTS = "/Users/lf/vscode/zhtx/tools/scan_results.json"
MUDLIB = "/Users/lf/vscode/zhtx/6688"
SYMBOL = "/Users/lf/vscode/mudos-ng/build/bin/symbol"
CONFIG = "/Users/lf/vscode/zhtx/config.cfg"

# Valid LPC escape sequences (don't touch these)
VALID_ESCAPES = set('ntr\\"\'abfv0x')


def get_files_with_warnings():
    with open(SCAN_RESULTS) as f:
        results = json.load(f)

    files = {}
    for r in results:
        for w in r["self_warnings"]:
            if "Unknown \\ escape" in w:
                m = re.search(r"line (\d+):", w)
                if m:
                    files.setdefault(r["lpc_path"], set()).add(int(m.group(1)))
    return files


def fix_line(line):
    """Remove invalid backslashes from a line. Returns (new_line, count_fixed)."""
    chars = list(line)
    fixed = 0
    i = 0
    while i < len(chars):
        if chars[i] == '\\' and i + 1 < len(chars):
            next_char = chars[i + 1]
            # Check if next byte is start of UTF-8 multi-byte sequence (>= 0x80)
            if ord(next_char) >= 0x80:
                # Remove the backslash before Chinese/UTF-8 character
                chars.pop(i)
                fixed += 1
                continue
            # Check if it's a valid escape sequence
            if next_char not in VALID_ESCAPES and not next_char.isdigit():
                # Also invalid but not UTF-8... could be other cases
                # Let's be conservative and only fix UTF-8 cases
                pass
        i += 1

    if fixed > 0:
        return ''.join(chars), fixed
    return line, 0


def fix_line_direct(line):
    """More aggressive: remove backslash before ANY non-ASCII byte.
    Only keeps valid C escape sequences. Returns (new_line, count)."""
    result = []
    chars = list(line)
    fixed = 0
    skip = False
    for i, ch in enumerate(chars):
        if skip:
            skip = False
            continue
        if ch == '\\' and i + 1 < len(chars):
            nxt = chars[i + 1]
            if ord(nxt) >= 0x80:
                # Non-ASCII byte after backslash → remove backslash
                result.append(nxt)
                skip = True
                fixed += 1
                continue
        result.append(ch)
    return ''.join(result), fixed


def verify_file(lpc_path):
    """Check if unknown escape warnings were resolved."""
    result = subprocess.run(
        [SYMBOL, CONFIG, lpc_path],
        capture_output=True, text=True, timeout=30
    )
    combined = result.stdout + "\n" + result.stderr
    escape_warnings = [l for l in combined.split("\n") if "Unknown \\ escape" in l]
    target = lpc_path.lstrip("/") + ".c"
    self_escapes = [w for w in escape_warnings if target.split("/")[-1] in w]
    return len(self_escapes)


def main():
    dry_run = "--dry-run" in sys.argv
    files = get_files_with_warnings()

    print(f"Found {len(files)} files with unknown escape warnings")
    total_fixed = 0
    failed = []

    for lpc_path, warned_lines in sorted(files.items()):
        fs_path = os.path.join(MUDLIB, lpc_path.lstrip("/") + ".c")
        if not os.path.exists(fs_path):
            continue

        with open(fs_path, "r") as f:
            lines = f.readlines()

        file_fixes = 0
        for lineno in warned_lines:
            if lineno > len(lines):
                continue
            idx = lineno - 1
            new_line, count = fix_line_direct(lines[idx])
            if count > 0:
                lines[idx] = new_line
                file_fixes += count

        if file_fixes == 0:
            continue

        if dry_run:
            print(f"  {lpc_path}: {file_fixes} fix(es)")
            total_fixed += file_fixes
            continue

        with open(fs_path, "w") as f:
            f.writelines(lines)

        remaining = verify_file(lpc_path)
        if remaining == 0:
            print(f"  OK {lpc_path}: {file_fixes} fix(es)")
            total_fixed += file_fixes
        else:
            print(f"  FAIL {lpc_path}: {remaining} remaining (was {file_fixes} fixes)")
            failed.append(lpc_path)

    if dry_run:
        print(f"\nDRY-RUN: would fix {total_fixed} escape(s) in {len(files)} files")
    else:
        print(f"\nFixed: {total_fixed} escape(s), Failed: {len(failed)}")


if __name__ == "__main__":
    main()
