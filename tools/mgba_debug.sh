#!/usr/bin/env bash
set -euo pipefail

repo_root=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
rom_path=${1:-"$repo_root/rom/baserom.gba"}
symbol_path="$repo_root/build/debug/sonic_battle_symbols.elf"
log_path="$repo_root/build/debug/mgba.log"

if [[ ! -f "$rom_path" ]]; then
    echo "ROM not found: $rom_path" >&2
    exit 1
fi
if ! command -v mgba-qt >/dev/null; then
    echo "mgba-qt is required" >&2
    exit 1
fi
if ! command -v gdb >/dev/null; then
    echo "GDB with ARM support is required" >&2
    exit 1
fi
if ss -ltn | rg -q ':2345[[:space:]]'; then
    echo "TCP port 2345 is already in use; close the existing mGBA GDB session." >&2
    exit 1
fi

python "$repo_root/tools/make_gdb_symbols.py" --output "$symbol_path"
mgba-qt -g "$rom_path" >"$log_path" 2>&1 &
mgba_pid=$!
cleanup() {
    kill "$mgba_pid" 2>/dev/null || true
    wait "$mgba_pid" 2>/dev/null || true
}
trap cleanup EXIT INT TERM

for _attempt in {1..100}; do
    if ss -ltn | rg -q ':2345[[:space:]]'; then
        break
    fi
    if ! kill -0 "$mgba_pid" 2>/dev/null; then
        echo "mGBA exited before opening its GDB server; see $log_path" >&2
        exit 1
    fi
    sleep 0.05
done
if ! ss -ltn | rg -q ':2345[[:space:]]'; then
    echo "mGBA did not open TCP port 2345; see $log_path" >&2
    exit 1
fi

gdb -q -nx -ex "symbol-file $symbol_path" -x "$repo_root/tools/mgba.gdb"
