# Node-animation translation unit

The inferred complete TU covers 21 functions at `0x08027DB8..0x080283F8`.
Its complete 1,600-byte text section includes all literals and alignment.
There is no independently established original source language: C++ is the
repository's reconstruction fallback. Address-based `extern "C"` labels are
synthetic linkage, not recovered names or evidence of original C linkage.

## Boundary and ownership evidence

Six entry animations are followed by three coordinate-convergence helpers,
six setup callbacks and six settled callbacks. They consistently operate on
caller-supplied list nodes, positions and allocation records, and use the
existing affine/list helpers. The callback pairs implement horizontal or
vertical offsets around 32- or 64-pixel centers and return to their associated
settled callbacks. The two single-axis convergence helpers are retained even
though the pointer and direct-call scans found no users for them.

The preceding card/deck family accesses its selected-list and UI state through
`0x08027D54`, whose full extent ends at `0x08027DB8`. Its control callbacks
return to other card/deck handlers. In contrast, stored pointers to these
animation callbacks occur in multiple distant screen families, including
`0802A298/0802A480`, `0802CFE0/0802D1EC/0802D4DC`,
`0803187C/08031E68`, `08034514/0803465C/080349AC`, and
`08039FE0/0803A0F8`. The two-axis convergence helper is directly called from
`0802A480`, `0802A9A4`, `0802AC48`, and `0802AD4C`.

The last settled callback ends, including alignment, at `0x080283F8`. The
next function accesses save-dependent text tables and VRAM, followed by a
separate screen initializer at `0x080284B4`. Coherent behavior, complete
callback pairing, callers and the adjacent transitions support this inferred
TU boundary. No original object-boundary metadata is claimed.

The compiled object has only three undefined symbols: `__divsi3`,
`FUN_0801fd18`, and `FUN_0801fed8`. Every other relocation is an internal
callback reference. All target pools are included in the byte comparison;
there are no external ROM-data references or owned initialized-data/BSS
sections. The emitted `.data` and `.bss` sections both have size zero. Whole-ROM
stored-pointer scans found no external data tables containing these callback
addresses. Numeric scans alone cannot exclude computed or indirect references.
Caller-owned node and allocation storage is not claimed as this TU's BSS.

## Types and emission

The node and position layouts follow the repository's reviewed list interface.
Allocation fields at offsets 16, 18, 20 and 22 are inferred from halfword
accesses; the first 16 bytes are unclassified. This is a view of the accessed
prefix, not a claim that every caller allocates exactly 24 bytes. Coordinates
are narrowed to signed halfwords where the target performs signed loads or
extensions. Other names and types are reconstruction descriptions.

The signed division call uses the reviewed SDK `__divsi3(s32, s32)` ABI,
replacing the legacy fragment's synthetic unsigned-halfword return declaration.
The final narrowing preserves the matching emitted instructions. Typed callback
addresses carry the Thumb bit through ELF function metadata; no manual `+1`
is applied to an already typed function pointer.

Literal zero stores in the setup callbacks preserve the compiler's constant
ordering. Separate current and computed coordinate locals in the two-axis
helper preserve the target register lifetimes without forced registers. The
pinned EGCS pipeline uses `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`.
No inline assembly, backend changes, artificial operations, byte patches or
comparison masks are used. Symbol-size overrides affect ELF metadata only;
whole-section verification still covers every byte between functions.

## Verification

`python tools/check_unit_bytes.py main/unknown_08027DB8` independently links
the compiled object using reviewed typed symbol definitions and compares its
entire text section against retail without masking. The same command is in
CI and the contribution checklist. Splitting one unresolved code bucket into
three adds two report units without changing ROM coverage or the function
inventory. Unresolved save and card/deck functions remain unresolved; their
coverage is not attributed to this TU.

The integrated report records all 21 functions and the complete section at
100%. Seven functions are newly matching; the global exact-function set grows
from 792 to 799 with none lost. Objdiff partitions the text into 1,548 function
bytes and 52 data/alignment bytes; the independent check covers all 1,600.

Before submission, all supported targets (BSBE78 only), automated tests,
independent TU checks, formatting, maps, proprietary-content checks, objdiff
nonregression and the ROM SHA-1 gate must pass. The bootstrap builder copies
the verified base ROM: its SHA-1 is not proof of a fully source-linked ROM.
No runtime or physical-hardware validation is claimed.
