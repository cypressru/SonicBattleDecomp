# Extra-menu translation unit

This inferred complete TU contains fourteen functions at
`0x080315BC..0x0803281C`: 4,704 bytes of code, literals and alignment,
472 bytes of menu metadata, and 64 bytes of register settings. All 5,240
owned ROM bytes match independently without masks. The private pointer at
`0x030052FC` owns four NOBITS bytes. No independent original-language evidence
establishes C; C++ is the reconstruction fallback. Address-based `extern "C"`
labels provide synthetic reconstruction linkage, not original names or linkage.
Types are observed layout views, not recovered declarations or capacities.

## Boundaries and behavior

The preceding briefing-screen family ends at this initializer. These fourteen
routines share the menu's language-pointer state, sprite positions, graphics
tables, scrolling controller and transition helpers. The next initializer at
`0x0803281C` uses a different register table at `0x08137FDC` and language data
beginning at `0x08EDC4AC`. These are inferred behavioral TU boundaries, not
recovered object-file boundaries.

The initializer clears display memory, selects language resources, prepares a
tile map and creates service/display nodes. The setup routine builds four rows,
two animated markers and the current selection's graphics and label. Enabled
and locked text paths retain their separately expanded drawing operations.
The controller handles confirmation, cancellation, bounded selection changes,
row insertion/removal and marker animation. It preserves the six-entry switch
even though ordinary downward navigation clamps the selection to four; this is
not a claim that every switch case is normally reachable.

One transition reconstructs decompression of the external embedded payload into
EWRAM, writes its observed parameter words, and calls `SoftResetExram`.
The payload remains external. Neither this transition nor any reconstructed
game routine was executed as part of verification.

`FUN_0803268c` is a newly recorded, apparently unused label-drawing helper.
It has its own saved-register prologue, stack frame and return, followed by its
own literal pool. The preceding helper returns before this entry. Its complete
152-byte span matches source, and expanded copies of its behavior appear in
both larger menu routines. Stored-pointer scans at every byte alignment and
direct-call scans found no caller. The entry and family evidence do not imply
that it is called or that its original name or linkage is known. Its 140-byte
function extent excludes the final literal pool.

## Owned data and shared state

`0x08EDC2D4..0x08EDC4AC` contains eleven 16-byte position views (176 bytes),
seven graphics pointers (28 bytes), seven palette pointers (28 bytes), six
nine-slot language-pointer arrays (216 bytes), four animation-part pointers
(16 bytes), and four signed coordinates (8 bytes). The coordinates are
29, 55, 81 and 107. Opaque graphics, palettes, glyph strings and sprite-part
pointees remain external; only interpreted layout and symbolic pointers are
defined here. Contiguous slot extents do not establish original array types
or that all slots are reachable.

`0x08132394..0x081323D4` contains sixteen register-offset/value pairs. The
consumer writes each value to `0x04000000 + offset`. The following compressed
asset and other display resources remain external.

Whole-ROM stored-pointer scans at all byte alignments found 29 references into
the owned menu metadata and one into the register table, all in this TU. All
22 stored references into `0x030052FC..0x03005300` also lie in this family.
Its consumers load/store a pointer, supporting the four-byte private extent.
These scans cannot rule out all computed references; ownership also relies on
the observed consumers and adjacent metadata boundaries.

Selection byte `0x03005300` is shared: the lobby and following screen also use
it, so it remains external. Save data, input state, the service-node pool,
generation state, font resources and the main callback remain shared. Per-node
allocations use minimum observed views; no additional global RAM or alignment
gaps are claimed.

## Compiler and verification

The pinned EGCS C++ pipeline uses TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. All operations are C++.
There are 75 register bindings and 43 empty assembly constraints. Greedy
cleanup removed 87 bindings and 62 empty constraints, comparing all 5,240 ROM
bytes and the private NOBITS span after each accepted removal. This is not a
global-minimality claim. The initializer and service routine match without
constraints. Remaining constraints preserve register allocation, stack
placement, narrow-value lifetimes and load order; they are reconstruction
constraints, not original-source or portability evidence. There are no
instruction assembly bodies, opaque instruction arrays, compiler changes,
byte patches or masks. Function-size overrides affect ELF metadata only.

`python tools/check_unit_bytes.py main/unknown_080315BC` independently links
the base object with typed address symbols and compares every byte of all
three ROM sections. The BSS check verifies address, size and NOBITS type.
Objdiff's source-composed target borrows relocation metadata and combines the
read-only sections in its presentation; its 100% result is not a substitute
for the independent section checks. Standalone entries for the two owned
tables are excluded from report accounting, preventing duplicate coverage.

Nine duplicated legacy definitions are removed; unrelated definitions remain.
All fourteen routines match, including eight previously exact routines. The
global exact-function count increases from 895 to 901 without losses. The
newly recorded helper adds 140 code bytes to the reviewed inventory: 1,298
functions, 268,608 code bytes and 16,508,608 data bytes across 1,941 units.
Coverage is exactly 16 MiB. Code accounting includes internal literal islands
within accepted function extents, not an instruction census.

BSBE78 is the only supported target. Its clean build, all 23 documented TU
byte gates, 61 tool tests, payload/debug/function-map checks and ROM SHA-1
check pass. An optional broader independent-link sweep reaches an existing
SDK limitation: `engine/multi_sio_sync` lacks a reviewed address for
`gMultiSioSendState`. That extra check is not claimed as passing and its
unrelated symbol mapping is unchanged.

The bootstrap ROM is a verified copy of the reference ROM, not a ROM fully
linked from reconstructed sources. Its matching SHA-1 does not establish
project-level source matching. Compilation and byte comparison do not
establish runtime or physical-hardware validation.
