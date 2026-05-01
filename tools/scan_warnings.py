#!/usr/bin/env python3
"""
Batch LPC warning scanner using MudOS-NG symbol tool.
Scans all .c files and captures compiler warnings.

Usage:
  python3 tools/scan_warnings.py                    # full scan
  python3 tools/scan_warnings.py --self-only         # self-warnings only
  python3 tools/scan_warnings.py --file /adm/daemons/moneyd  # single file
  python3 tools/scan_warnings.py --dir /feature      # directory only
  python3 tools/scan_warnings.py --summary            # print summary from saved scan
"""

import subprocess
import os
import sys
import json
import re
import time
from concurrent.futures import ProcessPoolExecutor, as_completed
from collections import defaultdict

CONFIG = "/Users/lf/vscode/zhtx/config.cfg"
SYMBOL = "/Users/lf/vscode/mudos-ng/build/bin/symbol"
MUDLIB = "/Users/lf/vscode/zhtx/6688"
OUTPUT_FILE = "/Users/lf/vscode/zhtx/tools/scan_results.json"

SKIP_PATTERNS = [
    "RCS/", "binaries/", "log/", "data/", "doc/",
    ".bak", ".git", "__pycache__"
]


def find_all_files(base_dir, restrict_dir=None):
    """Find all .c files in mudlib, returning (fs_path, lpc_path) tuples."""
    results = []
    for root, dirs, files in os.walk(base_dir):
        dirs[:] = [d for d in dirs if not any(p in os.path.join(root, d) for p in SKIP_PATTERNS)]
        for f in files:
            if f.endswith(".c"):
                fs_path = os.path.join(root, f)
                lpc_path = "/" + os.path.relpath(fs_path, base_dir)[:-2]
                if restrict_dir and not lpc_path.startswith(restrict_dir):
                    continue
                results.append((fs_path, lpc_path))
    return results


def check_file(lpc_path):
    """Run symbol on a single LPC file, return (lpc_path, warnings, errors, exit_code)."""
    try:
        result = subprocess.run(
            [SYMBOL, CONFIG, lpc_path],
            capture_output=True, text=True, timeout=30
        )
        combined = result.stdout + "\n" + result.stderr
        warnings = [l.strip() for l in combined.split("\n") if "Warning:" in l]
        errors = [l.strip() for l in combined.split("\n") if "Error:" in l or "Fail to load" in l]
        return (lpc_path, warnings, errors, result.returncode)
    except subprocess.TimeoutExpired:
        return (lpc_path, [], ["TIMEOUT after 30s"], -1)
    except Exception as e:
        return (lpc_path, [], [str(e)], -2)


def is_self_warning(lpc_path, warn_line):
    """Check if a warning is from the file itself (not inherited from base class)."""
    m = re.match(r"([^\s]+\.c)\s+line\s+(\d+):", warn_line)
    if m:
        warned_file = m.group(1)
        target_file = lpc_path.lstrip("/") + ".c" if not lpc_path.endswith(".c") else lpc_path.lstrip("/")
        # Remove leading / for comparison
        if warned_file.lstrip("/") == target_file:
            return True
        # Also try with leading path components
        if warned_file == target_file or warned_file.endswith("/" + target_file) or target_file.endswith("/" + warned_file):
            return True
        # The warned file path might be relative
        return warned_file == os.path.basename(target_file)
    return False


def scan_all(restrict_dir=None, jobs=8):
    """Scan all .c files and collect warnings."""
    files = find_all_files(MUDLIB, restrict_dir)
    total = len(files)
    print(f"Scanning {total} files with {jobs} parallel workers...")

    all_results = []
    done = 0
    t0 = time.time()

    with ProcessPoolExecutor(max_workers=jobs) as executor:
        futures = {executor.submit(check_file, lpc): lpc for _, lpc in files}
        for future in as_completed(futures):
            lpc_path, warnings, errors, rc = future.result()
            all_results.append({
                "lpc_path": lpc_path,
                "warnings": warnings,
                "errors": errors,
                "exit_code": rc,
                "self_warnings": [w for w in warnings if is_self_warning(lpc_path, w)],
                "inherited_warnings": [w for w in warnings if not is_self_warning(lpc_path, w)]
            })
            done += 1
            if done % 500 == 0:
                elapsed = time.time() - t0
                rate = done / elapsed
                eta = (total - done) / rate
                print(f"  {done}/{total} ({done*100//total}%) - {rate:.0f} files/s - ETA {eta:.0f}s")

    elapsed = time.time() - t0
    print(f"Done in {elapsed:.1f}s ({total/elapsed:.0f} files/s)")

    # Save results
    with open(OUTPUT_FILE, "w") as f:
        json.dump(all_results, f, indent=2, ensure_ascii=False)

    return all_results


def print_summary(results=None):
    """Print summary statistics from scan results."""
    if results is None:
        if os.path.exists(OUTPUT_FILE):
            with open(OUTPUT_FILE) as f:
                results = json.load(f)
        else:
            print("No scan results found. Run scan first.")
            return

    total_files = len(results)
    files_with_warnings = [r for r in results if r["warnings"]]
    files_with_self = [r for r in results if r["self_warnings"]]
    files_with_errors = [r for r in results if r["errors"]]
    files_exit_fail = [r for r in results if r["exit_code"] != 0]

    total_warnings = sum(len(r["warnings"]) for r in results)
    total_self = sum(len(r["self_warnings"]) for r in results)
    total_inherited = sum(len(r["inherited_warnings"]) for r in results)

    print(f"\n{'='*60}")
    print(f"  SCAN SUMMARY")
    print(f"{'='*60}")
    print(f"  Total files scanned:      {total_files}")
    print(f"  Files with warnings:      {len(files_with_warnings)}")
    print(f"  Files with self-warnings: {len(files_with_self)}")
    print(f"  Files with errors:        {len(files_with_errors)}")
    print(f"  Files exit != 0:          {len(files_exit_fail)}")
    print(f"  Total warning lines:      {total_warnings}")
    print(f"  Self-warnings only:       {total_self}")
    print(f"  Inherited warnings:       {total_inherited}")
    print(f"{'='*60}")

    # Category breakdown (self-warnings only)
    cats = defaultdict(int)
    for r in results:
        for w in r["self_warnings"]:
            m = re.search(r"Warning:\s*(.+)$", w)
            if m:
                cats[m.group(1)] += 1

    if cats:
        print(f"\n  SELF-WARNING CATEGORIES:")
        for cat, count in sorted(cats.items(), key=lambda x: -x[1]):
            print(f"    {count:5d}  {cat}")

    # Top files by self-warnings
    if files_with_self:
        print(f"\n  TOP FILES BY SELF-WARNINGS:")
        top = sorted(files_with_self, key=lambda r: -len(r["self_warnings"]))[:15]
        for r in top:
            print(f"    {len(r['self_warnings']):3d}  {r['lpc_path']}")

    # Top base classes by propagation
    base_propagation = defaultdict(int)
    for r in results:
        for w in r["inherited_warnings"]:
            m = re.match(r"([^\s]+\.c)\s+line", w)
            if m:
                base_propagation[m.group(1)] += 1

    if base_propagation:
        print(f"\n  TOP BASE CLASSES BY PROPAGATION:")
        top = sorted(base_propagation.items(), key=lambda x: -x[1])[:15]
        for path, count in top:
            print(f"    {count:6d}  {path}")


if __name__ == "__main__":
    if "--summary" in sys.argv:
        print_summary()
    elif "--self-only" in sys.argv:
        # Print only self-warnings
        if os.path.exists(OUTPUT_FILE):
            with open(OUTPUT_FILE) as f:
                results = json.load(f)
            for r in results:
                for w in r["self_warnings"]:
                    print(f"{r['lpc_path']}|{w}")
        else:
            print("No scan results found. Run scan first.")
    elif "--file" in sys.argv:
        idx = sys.argv.index("--file")
        lpc = sys.argv[idx + 1]
        _, warnings, errors, rc = check_file(lpc)
        for w in warnings:
            print(w)
        for e in errors:
            print(f"ERROR: {e}")
        print(f"Exit: {rc}")
    elif "--dir" in sys.argv:
        idx = sys.argv.index("--dir")
        d = sys.argv[idx + 1]
        results = scan_all(restrict_dir=d)
        print_summary(results)
    else:
        results = scan_all()
        print_summary(results)
