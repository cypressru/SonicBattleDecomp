# Main menu at 0x08039DD8

This inferred complete TU contains nine functions in `0x08039DD8..0x0803A4BC`,
1,764 text bytes including pools/alignment, and 128 interpreted ROM-data bytes.
All 1,892 owned ROM bytes are compared without masks after typed relocation.
There is no independently identified private BSS allocation in this family.

## Language, names and boundaries

Original source language is unknown; C++ is the repository-required fallback,
not a deduction from matching bytes. Address-based `extern "C"` labels are
synthetic reconstruction linkage, not recovered retail names or linkage.
Types and field names describe observed GBA widths, offsets and behavior;
no declarations from another platform or build are asserted.

The preceding statistics scene ends at `0x08039DD8`. The animated-tile
callback at that address is installed by this initializer at `0x08039E20`
and by the earlier initializer at `0x080284B4` (pointer at `0x08028718`).
The initializer, frame wrapper, palette/setup callback, input/dispatch and
three preview/blend callbacks form one coherent menu family. The next entry,
`0x0803A4BC`, renders character-menu pages using a different state cluster
and is called by `0x0803AE04` and `0x0803B82C`. Its following metadata starts
at `0x08EDD344`. These are behavioral/reference/layout boundary inferences,
not recovered compiler-object boundaries.

All-alignment stored-pointer scans found eleven external references to this
menu initializer at `0x08039E20`, in return/transition paths, and the one
external animated-tile callback reference above. All remaining stored entry
pointers are internal. Mapped Thumb BL scans found only the internal call
from `0x0803A428` to `0x0803A0F8` into this interval. Such scans cannot rule
out arbitrary computed references. Exported callbacks do not extend TU
ownership to their callers.

## Interpreted data and storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDD304..0x08EDD314` | Sixteen-byte position record: parts pointer, x=64, y=32, tile=128 and six zero state/attribute bytes |
| `0x08EDD314..0x08EDD32C` | Six symbolic compressed-graphics pointers selected by the language byte |
| `0x08EDD32C..0x08EDD344` | Six symbolic preview-graphics pointers selected by the language byte |
| `0x0815F02C..0x0815F06C` | Sixteen display-register offset/value pairs |

The two language tables each select one asset for language zero and a second
asset for all five other entries. Each preview asset contains seven 4,096-byte
selection blocks; source bases `0x081609E4` and `0x081679E4` are 28,672 bytes
apart, and the second block ends at the separately addressed palette base
`0x0816E9E4`. The pointers are metadata, not embedded asset bytes. Graphics,
palettes, tile maps and sprite-part records remain external. The register
table ends at the separately referenced compressed asset at `0x0815F06C`.
All-alignment scans into both owned metadata intervals found only their four
local base references, with no interior or non-code numeric coincidences.

The observed node layout is sixteen bytes. Animation storage is eight bytes.
The controller view describes the accessed eighteen-byte prefix of a
twenty-byte allocation; the child view describes twenty-four accessed bytes
of a twenty-eight-byte allocation. Unobserved suffixes are not invented
fields or asserted original declarations. These are allocator-owned objects,
not new static variables.

`0x03005264` is shared persistent word-sized selection state, referenced by
earlier families beginning at `0x080283F8`, `0x0802B6E8` and `0x0802CC78`.
`0x030052E0` is shared byte-sized active selection state used by earlier
text/settings/statistics menus and later character/results menus. Neither
is newly claimed as owned storage. Save, input, node-pool, transition-callback
and player storage remain external. The dispatcher's four cleared bytes at
`0x030053E0`, `0x030053E8`, `0x030053F0` and `0x030053F8` belong to the next
character-menu state cluster, not a private allocation in this TU.

## Preserved behavior

The tile animation increments a wrapping halfword timer, resets it above 23
and selects `(timer >> 2) & 7`; its normal cycle therefore uses six frames.
Each frame copies a 12-by-17 tile rectangle with the observed tile offset.
The initializer clears display storage, installs assets and nodes and starts
the palette/setup callback. Four palette transitions must all finish before
the two arrow children are installed and persistent selection is restored.

Input priority is confirm, left, then right. Selection wraps through 0..6.
Confirm records a separate constant in each switch arm, installs the exit
callback, begins a transition and plays its sound. Preview changes copy
4,096 graphics bytes and 32 palette bytes, then change blend coefficients.
The fade-in callback calls the input handler on every frame, including its
completion frame. Alias-sensitive rereads after byte stores and the prefix
increment inside its condition are preserved.

The exit callback retains the low-byte truncation of the actual word-returning
`FUN_0802067C`. Selection zero tests save byte offset `145 << 3` (1,160,
`0x488`), choosing `0x0802CC78` when zero and `0x0803CB64` otherwise.
Selections one and two clear four players; one additionally clears 152 bytes
at `0x03001620`. Selection three clears the next menu's four state bytes and
four players. Other cases select the observed callbacks without extra work.
The actual `FUN_08029CFC` parameter is a word, not a byte.

No new range checks or repairs are introduced. Language indices are used
without validation, and persistent word selection is truncated to a byte
without first clamping it. The reconstructed array sizes describe observed
metadata boundaries, not a proof that arbitrary corrupt state is safe.

## Compiler constraints and inventory

The pinned C++ frontend uses `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`.
Sequential whole-owned-object ablation tested all 32 initial register/empty
constraints, removing 21 on pass one and one on pass two. A third pass could
remove none of the ten survivors: six fixed-register bindings and four empty
operand constraints. Each trial compiled the complete TU and compared all
three relocated ROM sections; no fragment-only acceptance was used.

The palette accumulator remains bound to r0 and the input halfword to r1.
Each of the two blend callbacks retains r3 for 0x1000 and r0 for its remainder,
with empty read/write constraints preserving their handoff. They emit no
opcode assembly. Removing any survivor changes the final owned object.
The other allocation/pointer/dispatch constraints were removed.

No function-map entry was added or removed. Exact global functions increase
from 980 to 988, with no previously exact function lost; the frame wrapper was
already exact. The new TU is 9/9 exact. Its function-symbol sizes include 234
additional literal/alignment bytes previously counted as data: increases of
6, 126, 30, 22, 10, 32, 4 and 4 bytes at the eight changed symbols in address
order. This is classification, not new instructions or extra ROM coverage.
The wrapper's two alignment bytes remain outside its fourteen-byte symbol
but are included in the independent 1,764-byte text comparison.

Reviewed report inventory is 1,954 units, 1,300 functions, 269,322 code bytes
and 16,507,894 data bytes, still exactly 16 MiB. On this stacked branch,
matched code moves from 46.4747590318% to 47.0834166616%, and complete code
from 37.8136520395% to 38.4350331573%. These are branch figures, not main.

Build/objdiff verification is not runtime or physical-hardware validation.
The bootstrap ROM retains unmatched base-ROM ranges, so its matching SHA-1
does not imply that the entire game is already linked from source.

## Local verification

BSBE78 is the only documented supported target. Its clean 2,063-step build,
all 61 automated tests and all 31 documented independent byte gates pass.
Policy, payload/debug/function maps, Python syntax, C/C++ formatting and
whitespace checks pass. Clean and incremental reports have identical units
and measures and pass the reviewed inventory validator. No toolchain is
missing. The full-ROM SHA-1 is
`8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.
