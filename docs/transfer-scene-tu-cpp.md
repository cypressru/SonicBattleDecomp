# Transfer-scene translation unit

The inferred complete TU at `0x0803281C..0x080336DC` contains 29 routines,
3,776 text bytes including literals and alignment, 412 metadata bytes at
`0x08EDC4AC..0x08EDC648`, and 64 register-setting bytes at
`0x08137FDC..0x0813801C`. All 4,252 owned ROM bytes match independently,
without masks. Four four-byte NOBITS variables occupy `0x03005304..0x03005314`.

No independent evidence identifies the original source language. C++ is the
required reconstruction fallback. Address-based `extern "C"` labels are
synthetic linkage, not recovered names or original linkage. Types and member
names are observed layout views, not original declarations. No cross-platform
proprietary material or assets are included.

## Boundaries and behavior

The preceding extra-menu family ends at this initializer. Its own language
graphics, register settings, transfer-state controller and linked sprite
callbacks form a coherent family. The next initializer at `0x080336DC` uses
different register settings (`0x0814BE24`) and a different menu/node family.
These are evidence-based TU boundaries, not recovered object-file boundaries.

The initializer clears display memory, selects one of six language tables,
builds tile maps and creates a palette-transition node. Link-status callbacks
coordinate transfer startup, completion, timeout and transition. The seven-state
controller preserves fall-through from states zero to one and two to three.
Sprite callbacks animate linked positions, spawn moving sprites, and remove
off-screen nodes. BIOS transfer/reset behavior is reconstructed but was not run.

The final callback `FUN_080336ac` has its own prologue, return and alignment;
its body matches the preceding callback. All-alignment stored-pointer scans
and direct-call scans of accepted function extents found no caller. Similarly,
the last position record at `0x08EDC638` has no stored reference. Its complete
16-byte layout uses the same sprite parts and attributes as the preceding
record, with a different y coordinate. It ends exactly at the next family's
position table at `0x08EDC648`, referenced at `0x08033B58`. Both unused-looking
members are retained as family/layout evidence; neither is claimed reachable.

## Owned data and state

The metadata contains six five-pointer language arrays (120 bytes), eight
EWRAM transfer destinations (32), six background register values (12), four
position records (64), eight animation tile values (16), twenty y coordinates
(40), sixteen x coordinates (32), and six more position records (96).
The second ROM section contains sixteen register-offset/value pairs consumed
by the display-register initializer. Graphics, palettes and sprite-part
pointees remain external; only interpreted metadata and symbolic pointers are
defined. Contiguous slots do not establish original capacities or reachability.

All-alignment whole-ROM scans found 22 live metadata references inside this
family and one numeric coincidence: `0x08E2B8AA` lies inside validated M4A
sample 317 (`0x08E2A290..0x08E2C4E0`). The register table has one reference,
at `0x08032884`. All 18 live references into the four private words lie in
this family. Their word loads/stores establish four-byte minimum extents.
Shared state at `0x03005258`, `0x0300525C`, `0x03005300`, the node pool,
save data and engine transfer state remain external.

Nine other values numerically resemble references into the private words:

| Source | Independently identified containing data |
| --- | --- |
| `0x081335C9` | LZ77 asset 111, `0x081334D8..0x081338C6` |
| `0x0815C88E` | LZ77 asset 222, `0x0815C4B4..0x0815E67B` |
| `0x081601EF` | LZ77 asset 225, `0x0815FAFC..0x08160243` |
| `0x0819AD2D` | LZ77 asset 381, `0x0819ABD4..0x0819D78F` |
| `0x081B1045` | LZ77 asset 408, `0x081B0E50..0x081B1442` |
| `0x081B1639` | LZ77 asset 409, `0x081B1444..0x081B1A3A` |
| `0x08697155` | Raw sprite frame, `0x08697098..0x08697518` |
| `0x08EFEEF1` | Embedded stream, `0x08EEF9C0..0x08F16058` |
| `0x08F7513D` | Embedded stream, `0x08F5F04C..0x08F81D10` |

All eight compressed streams were parsed with valid back-references and exact
declared output sizes. For the raw frame, code at `0x08015CA0` selects graphics
base `0x08681A98`; the call at `0x08015D9C` queues it through `FUN_08020440`.
The independently matched transfer dispatcher copies 1,152-byte frames from
`base + frame * 1152` to OBJ VRAM. The numeric value is 189 bytes into frame
76. The region up to the next character palette at `0x086F6A98` consists of
416 such frame slots; this arithmetic is layout evidence, not a claim that
every frame is used. Scans cannot exclude all computed references; the
ownership inference also relies on consumers, formats and adjacent boundaries.

## Compiler and verification

The pinned EGCS C++ frontend and agbcc backend use TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. Five register bindings
remain: two initializer column counters, the palette-result temporary,
the transfer callback address, and the reset destination. Greedy cleanup
removed eleven bindings and all ten empty constraints while checking every
owned byte after each accepted removal. No instruction assembly, empty
assembly, byte patches, compiler changes or masks remain. These bindings are
reconstruction constraints, not original-source evidence or a minimality claim.

`python tools/check_unit_bytes.py main/unknown_0803281C` independently links
all three ROM sections with typed address symbols and verifies four NOBITS
address/type/size spans. Objdiff borrows relocation metadata and does not
replace this independent byte check. Owned standalone metadata entries are
excluded from report accounting. Eleven legacy function definitions are
removed; unrelated definitions are preserved.

The clean BSBE78 build passed all 2,028 steps. All 24 documented byte gates,
61 tool tests, 28 Python syntax checks, 39 source/header formatting checks,
proprietary-file check, payload/debug/function-map checks and ROM SHA-1 passed.
All 29 routines and all reported sections are 100% matching. The global exact
count rises from 901 to 919, with no losses. Inventory remains 1,298 functions,
268,608 code bytes and 16,508,608 data bytes (exactly 16 MiB), now across 1,942
units. The report inventory guard was updated only for the reviewed unit split.
Code accounting includes literal islands in accepted extents, not just opcodes.

BSBE78 is the only supported target. The bootstrap ROM is a verified copy,
not a ROM fully linked from reconstructed sources; its SHA-1 cannot establish
project-level source matching. Compilation does not establish runtime or
physical-hardware validation.
