# Scene services at 0x0803FB2C

This inferred complete services TU contains 24 functions and their literals
and alignment in `0x0803FB2C..0x08040684` (2,904 bytes), eight stage-start rows
in `0x0831EAE4..0x0831EB14` (48 bytes), and eight initial-script pointers in
`0x08EEB240..0x08EEB260` (32 bytes). All 2,984 owned ROM bytes match after
independent typed relocation, without masks. Twelve private BSS objects total
36 bytes; intervening gaps are not claimed.

## Language, behavior, and boundaries

Original source language is unknown. C++ is the reconstruction fallback;
matching does not establish original language or compiler identity.
Address-based names and `extern "C"` are synthetic reconstruction linkage.
Types and descriptive names are inferred from GBA access widths and consumers,
not recovered names. No other platform's source or metadata was used.

The family initializes scene/save state, blends palettes toward white or
black, queues and drains DMA/tile transfers, manages a 127-slot recycled node
pool, stably sorts render nodes, and emits up to 128 OAM entries. Its callbacks
also bridge into the separate reward and scene families. The preceding reward
selection ends at `0x0803FB2C`; the following numeric helpers start at
`0x08040684`. Shared node, queue, sorting, and rendering state connects these
services. These are inferred behavioral/layout boundaries, not recovered
compiler object boundaries.

The eight stage rows are six-byte `(room, x, y)` records, expressed as a u16
matrix because the pinned compiler rounds a three-halfword struct to eight
bytes. Initial scripts use symbolic pointer relocations. The next script
metadata at `0x08EEB260` and preceding stage records belong to the separate
scene family and remain outside this TU.

An all-alignment ROM survey classified references into the surveyed services
and neighboring utility ownership ranges using code consumers, validated LZ77
and WaveData payloads, bounded graphics transfers, text/script parsers, and
scene metadata. No surveyed occurrence remained unclassified. Graphics bounds
were derived from actual transfer/frame consumers, not broad data-gap labels.
Script traversal stops at unknown opcodes or scene changes; opaque assets and
script bodies remain external. Numeric surveys cannot exclude arbitrary
computed references or prove historical object boundaries.

## Storage and source semantics

The BSS map is verified by independent named sections:

| Address | Bytes | Reconstructed role |
| --- | ---: | --- |
| 030001A0 | 4 | DMA queue pointer |
| 030001A4 | 4 | Rectangle queue pointer |
| 030001A8 | 4 | Recycle ring pointer |
| 030001AC | 1 | Recycle write cursor |
| 030001AD | 1 | Recycle read cursor |
| 030001B0 | 4 | Priority-head pointer |
| 030001B4 | 4 | Render-link pointer |
| 030001B8 | 1 | Render count |
| 030001BC | 4 | Key-count pointer |
| 030001C0 | 4 | Sort-pair pointer |
| 030001C4 | 4 | Sorted-node pointer |
| 030001C8 | 1 | Sort count |

Explicit zero definitions prevent COMMON merging; they do not introduce ROM
initializers. Shared scene state, node pool, palette pointer, active-node
count, callbacks, and flags remain external. Buffer addresses initialized by
these routines are not new private allocations.

`ServiceNode` is a 44-byte operational view with byte links, halfword
coordinates, callback/script/sprite fields, and an observed parent index at
byte 25. Heterogeneous pointer views do not establish an original class.
`SceneState` and `SaveView` are synthetic views; the latter is only a prefix,
not a claim of full save-data ownership. Save coordinates are at offsets
0x498/0x49A, independently corroborated by the save writer; packed flags start
at 0x49C. Restoring and initializing scenes preserve their distinct field
updates, script selection, and RNG snapshot behavior.

Palette count and amount enter through register-width reconstruction
parameters and are explicitly narrowed to u16 locally. This preserves the
observed narrowing order, not an original prototype. Signed loop indices and
buffer extents retain caller preconditions. Channel products fit signed
32-bit intermediates; black blending preserves the observed low-halfword
result rather than adding clamps. A local arithmetic model checked 6,291,456
channel/amount cases and 655,360 composed-color cases. This is source-model
checking, not emulator or hardware validation.

Queue capacities, node indices, scene flag indices, and OAM limits retain
retail preconditions and truncation. DMA registers are volatile and transfer
ordering/readbacks are preserved. Signed-coordinate shifts that represent
bit placement use unsigned operands. No invented padding variables, opaque
instruction arrays, opcode assembly, or indeterminate register reads are used.

## Compiler constraints and verification

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` on the pinned
EGCS/agbcc reconstruction pipeline. Four whole-owned-object ablation passes
tested 45, 38, 36, and 34 candidates respectively, removing 13 byte-neutral
constraints. The final pass found no individually removable constraint:
27 fixed-register bindings, five input-only empty-assembly statements, and
two tied address handoffs remain. This is local ablation evidence, not a
claim of globally minimal source.

Both tied handoffs initialize their output from the actual palette-pointer
global address through a same-register matching input. Empty statements emit
no opcode. Bindings constrain real initialized values and are accepted only
with complete section equality, not merely plausible source-level intent.
No palette-loop empty assembly remains. Formatting and comment cleanup were
followed by another complete byte/BSS verification.

`python tools/check_unit_bytes.py main/unknown_0803FB2C` is required in CI and
the contributor checklist. BSBE78 is the only documented supported target.
The full build, existing byte gates, tests, policy checks, and normalized
objdiff report must pass before submission. A bootstrap ROM SHA-1 match does
not establish a fully source-linked ROM or runtime/physical-hardware validation.

The clean BSBE78 build completed all 2,097 steps and the bootstrap ROM SHA-1
matched. All 61 tests and all 39 complete-TU byte gates passed, as did payload,
debug-metadata, function-map, formatting, Python syntax, proprietary-file
policy, and normalized objdiff report checks. Objdiff reports 24/24 functions
and all composed sections at 100%; the independent gate verifies all three
ROM sections and each BSS object separately.

## Reviewed report inventory

Against main `ab35f28`, full function extents reclassify 294 bytes previously
counted as unresolved pool/alignment data. Code/data totals become
271,018/16,506,198, still exactly 16 MiB. This is classification, not 294 new
instruction bytes. The new code unit and two metadata remainder units increase
inventory from 1,966 to 1,969; function inventory stays 1,300. Exact-function
identity comparison gains ten functions, from 1,025 to 1,035, with no losses.
Fourteen services already appeared exact in the incomplete coverage bucket;
all 24 now belong to a complete independently verified TU. Branch matched code
changes from 54.3003% to 55.1100%, and complete code from 46.1924% to 47.2138%.
The independent BSS gate checks the 36 actual object bytes; objdiff's composed
BSS size includes alignment and is not a private-storage ownership claim.
