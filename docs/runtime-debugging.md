# Runtime debugging

mGBA's GDB remote stub can provide behavioral evidence for function starts, indirect calls,
callers, arguments, global types, and hardware-register effects. Runtime observations supplement
the static function and translation-unit audits; they do not prove that unexecuted code is data or
establish original translation-unit boundaries by themselves.

## Starting a session

Install mGBA Qt and a GDB build that accepts `set architecture arm`, then run:

```sh
tools/mgba_debug.sh
```

The launcher uses the locally supplied `rom/baserom.gba`, starts mGBA's GDB server on loopback port
2345, generates `build/debug/sonic_battle_symbols.o` from the reviewed function CSV, and opens a
persistent GDB session. The generated object contains names and absolute addresses only; it embeds
no ROM bytes. The launcher closes its mGBA child when GDB exits.

Useful commands:

```text
sb-boot                         run from reset to AgbMain
sb-frame                        advance one normal main-loop frame
sb-frames 60                    advance 60 main-loop frames
sb-state                        show call registers and nearby instructions
sb-break 0x08018318             break at a candidate function
sb-watch8 0x030016C4            watch an 8-bit global
sb-watch16 0x03001B04           watch a 16-bit global
break FUN_080183d0              names from functions.csv also work
```

The frame command stops at `0x080007CA`, the top of `AgbMain`'s persistent loop immediately before
the wait/update/callback sequence. It is a deterministic game-loop boundary during normal
execution. Interrupt-driven activity and unusual reset or communication loops still need to be
interpreted separately.

## Recording evidence

For a proposed name or boundary, record the tested scene and input, breakpoint address, caller and
return address, argument values, modified memory or registers, and whether the behavior reproduced
from a second state. Treat a descriptive runtime name as a behavioral correlation, not as a claim
that it was the developer's original symbol.

ROMs, BIOS files, savestates, screenshots, traces, memory dumps, and emulator logs must remain
local. The existing ignore rules cover the default ROM and `build/debug` paths; do not add runtime
artifacts to commits or pull requests.
