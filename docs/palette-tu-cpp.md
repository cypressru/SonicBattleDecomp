# Palette/blend TU C++ fallback

The complete inferred TU at `0x08020500-0x08020978` contains ten palette and
hardware-blend helpers, 1,144 ROM bytes and a ten-byte reconstructed private
RAM span. All ten functions previously existed as C fragments; this is full-TU
recovery and C++ migration, not ten newly matching functions. Original language
is unknown. C++ is the requested fallback, and address labels with `extern "C"`
provide synthetic linkage rather than recovered original names or C linkage.
The remaining coverage source retains the palette-convergence function's `u8`
prototype after its definition moves; omitting it made the legacy C compiler
assume an `int` result and regressed five callers. The restored declaration
preserves their existing exact emission.

## Boundary and behavior evidence

The preceding transfer-command TU ends with its last enqueue helper's complete
pool. This TU starts with per-channel palette convergence, followed by blend
progress, convergence toward black/white, palette scaling, four blend setup
helpers and a reset. The final reset at `0x08020944` clears both queued blend
registers and all three state fields; its complete pool ends at `0x08020978`.
The next function begins the separate buffer/glyph family using `0x03004B10`.
Function order, complete pools, related operations and shared state support an
inferred TU boundary, not surviving retail object metadata.

The three state fields use halfword, byte and halfword accesses at
`0x03004B00`, `0x03004B04` and `0x03004B08`. They represent blend progress,
direction and step, but the source retains generic names. Color arithmetic
preserves the five-bit RGB masks, unsigned scaling, halfword wrapping and the
observed return behavior. The four setup helpers queue blend-control values,
clamp a zero duration to one, calculate a step and clamp a zero step to one.

The division call uses the reviewed `s32 __divsi3(s32, s32)` ABI at `0x0804AFA4`,
instead of the earlier synthetic unsigned-argument/halfword-return declaration.
Both declarations produced matching bytes here, but the reviewed library ABI
is the appropriate source declaration. The arguments in these helpers are
positive and fit signed 32 bits. No other game's source or private cross-platform
metadata was used for this TU.

## Storage ownership and limits

Whole-ROM halfword-aligned scans find exact base references only in this family:

| State base | Literal addresses (ROM prefix `080` omitted) |
| --- | --- |
| `03004B00` | `2061C`, `20644`, `20834`, `2088C`, `208E0`, `20938`, `20970` |
| `03004B04` | `205E4`, `20830`, `20888`, `208DC`, `20934`, `2096C` |
| `03004B08` | `20620`, `20660`, `20838`, `20890`, `208E4`, `2093C`, `20974` |

The source owns the minimal span through the last halfword, ending at
`0x03004B0A`. Two bytes at offsets 2-3 and three bytes at offsets 5-7 are
explicitly unclassified storage. They preserve the observed distances without
claiming original fields or alignment declarations. The six bytes before the
next buffer-state address are not claimed. Two words numerically inside the
internal gaps occur at `0x0818E9C6` in opaque ROM data and `0x08F1D8FE` in a
compressed payload; these are not established pointers or known accesses.
Scans alone cannot exclude indirect/computed references or prove original
declarations. Ownership is inferred from the coherent API and direct references.

Scalar state and separate unclassified storage emit `.bss` size `0xA`, with
the observed fields at offsets zero, four and eight. Struct-wrapper, array and
exported-wrapper controls placed storage correctly but changed setup/reset
emission and were rejected. The unclassified declarations are storage views,
not invented gameplay behavior. No initialized or remote ROM data is identified.

## Emission and verification

The pinned EGCS C++ pipeline uses `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`, plus diagnostic-only `-quiet -Werror`. No backend or optimization
flags were changed. No assembly, fixed registers, instruction patches or
relocation masks are used. Symbol-size overrides affect ELF metadata only.

`python tools/check_unit_bytes.py main/unknown_08020500` independently links the
actual compiled object, compares all 1,144 ROM bytes including resolved calls,
literals and alignment, and checks the linked BSS NOBITS address and size.
For configured BSS ownership the checker now supplies explicit output sections:
the default linker script rounds a ten-byte BSS section up to twelve bytes.
That linker-added tail is not input storage and is not claimed by this TU.
Objdiff must also verify all ten functions and both complete sections at 100%.
BSS is not included in ROM coverage. The inventory adds one unit without adding
functions or ROM bytes; function-extent accounting includes internal pools.

Every supported target (BSBE78 only), repository tests, formatting, proprietary
checks, maps, normalized reports and the SHA-1 gate are required before submission.
The bootstrap builder copies its verified base ROM: its passing SHA-1 is not
source-built ROM proof. No runtime or hardware validation is claimed.
