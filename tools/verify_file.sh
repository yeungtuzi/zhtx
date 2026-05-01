#!/bin/bash
# Verify a single LPC file compiles without self-warnings
# Usage: tools/verify_file.sh /adm/daemons/moneyd
#        tools/verify_file.sh /Users/lf/vscode/zhtx/6688/adm/daemons/moneyd.c

SYMBOL="/Users/lf/vscode/mudos-ng/build/bin/symbol"
CONFIG="/Users/lf/vscode/zhtx/config.cfg"
MUDLIB="/Users/lf/vscode/zhtx/6688"

arg="$1"
if [ -z "$arg" ]; then
    echo "Usage: $0 <lpc-path | filesystem-path>"
    exit 1
fi

# Convert filesystem path to LPC path if needed
if [[ "$arg" == /* && "$arg" == *.c ]]; then
    lpc_path="${arg#$MUDLIB}"
    lpc_path="${lpc_path%.c}"
else
    lpc_path="$arg"
fi

echo "=== Checking: $lpc_path ==="
output=$("$SYMBOL" "$CONFIG" "$lpc_path" 2>&1)
rc=$?

# Extract all warnings
warnings=$(echo "$output" | grep "Warning:")

# Filter self-warnings (where the warned file matches the target)
target_file=$(basename "$lpc_path").c
self_warnings=$(echo "$warnings" | grep "^$target_file\|^/$target_file\|$target_file line")

echo "$output" | grep -E "Warning:|Error:|Fail to load"
echo "Exit code: $rc"

if [ -n "$self_warnings" ]; then
    echo ""
    echo "*** SELF-WARNINGS (needs fix): ***"
    echo "$self_warnings"
fi

if [ -z "$warnings" ] && [ $rc -eq 0 ]; then
    echo "CLEAN - no warnings, exit 0"
fi
