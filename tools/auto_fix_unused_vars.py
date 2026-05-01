#!/usr/bin/env python3
"""
Batch auto-fix unused local variable warnings in LPC files.
Processes each file once, applying all fixes from bottom to top.

Usage:
  python3 tools/auto_fix_unused_vars.py --dry-run
  python3 tools/auto_fix_unused_vars.py
"""

import json
import os
import re
import sys
import subprocess
from collections import defaultdict

SCAN_RESULTS = "/Users/lf/vscode/zhtx/tools/scan_results.json"
MUDLIB = "/Users/lf/vscode/zhtx/6688"
SYMBOL = "/Users/lf/vscode/mudos-ng/build/bin/symbol"
CONFIG = "/Users/lf/vscode/zhtx/config.cfg"


def load_results():
    with open(SCAN_RESULTS) as f:
        return json.load(f)


def group_fixes_by_file(results):
    """Group (varname, func_close_line) by lpc_path."""
    groups = defaultdict(list)
    for r in results:
        for w in r["self_warnings"]:
            m = re.match(r".*line (\d+): Warning: Unused local variable '(\w+)'", w)
            if m:
                groups[r["lpc_path"]].append((m.group(2), int(m.group(1))))
    return groups


def find_func_bounds(lines, close_line):
    """Find the start and end of the function containing close_line."""
    depth = 0
    func_start = None
    for i in range(close_line - 1, -1, -1):
        stripped = lines[i].strip()
        if "}" in stripped:
            depth += stripped.count("}")
        if "{" in stripped:
            depth -= stripped.count("{")
        if depth < 0:
            func_start = i
            break
    return func_start if func_start is not None else 0


def remove_var_from_line(line, varname):
    """Remove varname from a declaration line. Returns new line or None to delete."""
    stripped = line.rstrip("\n").rstrip("\r")

    # Case 1: Single variable: "int varname;"
    if re.match(r'^\s*(int|string|object|mapping|mixed|float|nosave)\s+' + re.escape(varname) + r'\s*;\s*$', stripped):
        return None

    # Case 2: Variable at end: "int a, varname;"
    m = re.match(r'^(.*),\s*' + re.escape(varname) + r'\s*;(.*)$', stripped)
    if m:
        return m.group(1) + ";" + m.group(2) + "\n"

    # Case 3: Variable at start: "int varname, b;"
    m = re.match(r'^(\s*(?:int|string|object|mapping|mixed|float|nosave)\s+)' + re.escape(varname) + r'\s*,\s*(.*)', stripped)
    if m:
        return m.group(1) + m.group(2) + "\n"

    # Case 4: Variable in middle: "int a, varname, b;"
    m = re.match(r'^(.*),\s*' + re.escape(varname) + r'\s*,(.*)', stripped)
    if m:
        return m.group(1) + "," + m.group(2) + "\n"

    # Case 5: Assignment: "int varname = expr;"
    if re.match(r'^\s*(int|string|object|mapping|mixed|float|nosave)\s+' + re.escape(varname) + r'\s*=.*;', stripped):
        return None

    return None  # can't fix


def find_decl_in_func(lines, func_start, func_close, varname):
    """Find the line index (0-based) where varname is declared in the function."""
    for i in range(func_start, func_close):
        line = lines[i]
        if re.search(r'\b(int|string|object|mapping|mixed|float|nosave)\b', line):
            if re.search(r'\b' + re.escape(varname) + r'\b', line):
                return i
    return None


def fix_file(fs_path, fixes):
    """Apply all fixes to a single file. fixes = [(varname, func_close_line), ...]."""
    with open(fs_path, "r") as f:
        lines = f.readlines()

    modifications = []
    for varname, close_line in fixes:
        func_start = find_func_bounds(lines, close_line)
        decl_line = find_decl_in_func(lines, func_start, close_line, varname)
        if decl_line is not None:
            new_line = remove_var_from_line(lines[decl_line], varname)
            modifications.append((decl_line, new_line, varname))

    if not modifications:
        return False, []

    # Remove duplicates (same decl_line modifying the same variable)
    seen = set()
    unique_mods = []
    for decl, new, var in modifications:
        key = (decl, var)
        if key not in seen:
            seen.add(key)
            unique_mods.append((decl, new, var))
    modifications = unique_mods

    # Sort by descending line number to apply from bottom up
    modifications.sort(key=lambda x: -x[0])

    changes = []
    for decl_line, new_line, varname in modifications:
        if new_line is None:
            changes.append(f"  DEL line {decl_line+1}: removing '{varname}'")
            del lines[decl_line]
        else:
            changes.append(f"  MOD line {decl_line+1}: removing '{varname}'")
            lines[decl_line] = new_line

    with open(fs_path, "w") as f:
        f.writelines(lines)

    return True, changes


def verify_file(lpc_path):
    """Check if a file has 0 self-warnings."""
    result = subprocess.run(
        [SYMBOL, CONFIG, lpc_path],
        capture_output=True, text=True, timeout=30
    )
    combined = result.stdout + "\n" + result.stderr
    warnings = [l.strip() for l in combined.split("\n") if "Warning:" in l]
    target = lpc_path.lstrip("/") + ".c"
    self_warnings = [w for w in warnings if target.split("/")[-1] in w.split(" line ")[0].split("/")[-1]]
    return len(self_warnings) == 0, self_warnings, result.returncode


def main():
    dry_run = "--dry-run" in sys.argv
    results = load_results()
    groups = group_fixes_by_file(results)

    total_files = len(groups)
    total_warnings = sum(len(v) for v in groups.values())
    print(f"Processing {total_warnings} warnings across {total_files} files")

    fixed_files = 0
    failed_files = 0
    skipped_files = 0

    for lpc_path, fixes in sorted(groups.items()):
        fs_path = os.path.join(MUDLIB, lpc_path.lstrip("/") + ".c")
        if not os.path.exists(fs_path):
            skipped_files += 1
            continue

        ok, changes = fix_file(fs_path, fixes)
        if not ok:
            skipped_files += 1
            continue

        if dry_run:
            print(f"{lpc_path}:")
            for c in changes:
                print(c)
            fixed_files += 1
            continue

        # Verify after fix
        clean, remaining, rc = verify_file(lpc_path)
        if clean:
            if len(changes) <= 3:
                print(f"OK {lpc_path}: {len(changes)} fix(es)")
            fixed_files += 1
        else:
            print(f"FAIL {lpc_path}: {len(remaining)} remaining warnings: {remaining[:3]}")
            failed_files += 1

    if dry_run:
        print(f"\nDRY-RUN: would fix {fixed_files} files, skip {skipped_files}")
    else:
        print(f"\nFixed: {fixed_files} files, Failed: {failed_files}, Skipped: {skipped_files}")


if __name__ == "__main__":
    main()
