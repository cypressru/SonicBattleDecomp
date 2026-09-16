# Intro callbacks at 0x0803D748

This inferred complete TU owns six callbacks and their pools, switch tables,
and alignment in `0x0803D748..0x0803E7A8` (4,192 bytes), plus coordinate and
scroll metadata in `0x08172A3C..0x08172A78` (60 bytes). All 4,252 bytes match
the source-built object after independent typed relocation, without masks.
No private BSS is claimed; all referenced engine state and assets stay external.

## Language, boundaries, and provenance

Original language is unknown: C++ is the requested reconstruction fallback,
not an inference from matching bytes. Address labels and `extern "C"` are
synthetic reconstruction linkage, not recovered names or original linkage.
Local types and names describe observed GBA widths and behavior. No other
platform's source, executable, or metadata was used.

The initializer resets rendering and state, installs the first image sequence,
and progresses through a second animated sequence to the final title display.
Two terminal fades dispatch to different external scenes. The preceding menu
ends at `0x0803D748`; the next ending initializer starts at `0x0803E7A8`.
Neither is a member of this callback graph. These are behavioral and layout
inferences, not recovered compiler object boundaries.

An all-alignment ROM survey found 49 numeric references into the claimed
code/metadata ranges: 34 code/pool references, 14 values within validated MP2K
WaveData sample payloads, and one within a validated embedded LZ77 payload.
No occurrence remained unclassified. The initializer has external stored
pointers at `0x08000770`, `0x0801C5C8`, `0x08023034`, and `0x08038444`;
the remaining genuine callback pointers and switch tables are internal.
A mapped Thumb BL survey found no direct calls into the family. Such surveys
cannot exclude arbitrary computed references.

The six metadata references are pools `0x0803D844`, `0x0803DB5C`,
`0x0803DCE4`, `0x0803D850`, `0x0803DB68`, and `0x0803DCE8`.
The first array contains twenty signed halfwords (initial and target x/y),
the second ten (initial and target scroll). Target views originate inside
the complete arrays: the transition's scene index -1 accesses the preceding
valid row, not memory before an independently declared target array.
The following metadata at `0x08172A78` belongs to a different scene.

## ABI and compiler details

Flags remain `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` on the pinned
EGCS/agbcc C++ pipeline. The matrix argument in `FUN_0803e1b0` uses a synthetic
64-bit ABI carrier. ROM `0x08017F34` stores incoming r0/r1 as two successive
words at `0x03003190 + count * 8`; `0x08017F80` splits those words into four
halfwords and forwards them to `0x080200D8`. The existing consumer TU uses
two pointer-shaped word arguments, likewise a synthetic ABI view. A single
64-bit argument starts in r0/r1 with the pinned calling convention, with no
preceding parameter or stack argument alignment mismatch. No portable shared
prototype or original 64-bit source type is claimed.

`MatrixWords` has four consecutive signed 16-bit fields, all assigned before
reading its 64-bit member. The read explicitly relies on the pinned GNU
union representation extension, not portable ISO C++ type punning. There are
no padding bits in the eight-byte carrier and no source-level indeterminate
read. Passing an eight-byte aggregate or two scalar words has the same data
meaning but different allocation; the packed carrier matches without falsely
annotating `DivArm` as pure/const.

Whole-object ablation removed the final callback's trig r6 binding with no
byte change. Removing its scale r0 binding instead produces 4,196 text bytes
and 478 differences. Removing both scale bindings produces 4,204 bytes and
1,672 differences. Earlier complete-object cleanup also removed D860's delta
and scroll bindings and replaced all GNU statement expressions with ordinary
initialized locals, preserving byte identity.

Remaining fixed-register/empty-operand hints constrain allocation, not emitted
opcodes. In particular the terminal timer pointer's output is tied to the
initialized `&gUnknown_030016bc` input in the same register. This defines its
value while limiting its lifetime; an ordinary earlier-bound pointer changes
whole-function address commoning. Reset constants and affine intermediates
are initialized before their operands. There is no invented frame padding.
Final whole-object individual empty-operand ablations give:

| Removed operand | Text bytes | Differing bytes |
| --- | ---: | ---: |
| D860 reset constant | 4,188 | 2,473 |
| DD14 first coefficient | 4,192 | 267 |
| DD14 first pre-truncation use | 4,196 | 1,580 |
| DD14 first post-truncation use | 4,196 | 1,577 |
| DD14 second coefficient | 4,192 | 242 |
| DD14 second pre-truncation use | 4,196 | 1,574 |
| DD14 second post-truncation use | 4,192 | 6 |
| DD14 reset constant | 4,192 | 109 |

DMA ordering, transfer counts, readbacks, signed shifts and halfword truncation
are retained. Coordinate paths keep the affine-origin left shifts nonnegative.

## Verification

The independent `main/unknown_0803D748` byte check is a required contributor
and CI gate. BSBE78 is the only supported target. Full clean build, tests,
existing complete-TU gates, report validation, and ROM SHA-1 are required
before completion. The bootstrap SHA check alone does not prove a fully
source-linked ROM. No emulator or physical-hardware validation is claimed.

On base main `f779d43`, the final clean BSBE78 build completed all 2,091
steps, the ROM SHA-1 matched, and all 61 automated tests passed. Objdiff
reports six of six callbacks and both complete sections at 100%.
All 38 required byte gates, payload/debug/function-map checks, formatting,
proprietary-file policy, Python syntax, and normalized report validation pass.

## Reviewed inventory

Full function extents reclassify 292 previously unresolved literal/pool/table
bytes as part of the six functions: code/data totals change from
270,432/16,506,784 to 270,724/16,506,492. This is classification, not 292 new
instruction bytes. Metadata splitting adds one reported remainder unit;
units change from 1,965 to 1,966. The function count stays 1,300 and total
coverage remains exactly 16 MiB. Branch matched/complete code is
54.3003%/46.1924%, up from 52.8377%/44.6922%. Exact-function identity
comparison gains five callbacks (1,020 to 1,025); `FUN_0803e74c` was already
exact in the incomplete bucket. No previously exact function is lost.
This does not claim unmerged main progress changed.
