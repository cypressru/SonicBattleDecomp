# Menu scene at 0x0803D1A0

This inferred complete TU contains four callbacks in
`0x0803D1A0..0x0803D748`: initialization, input/update, palette fade-in,
and fade-out/exit. Its 1,448 text, literal-pool, switch-table, and alignment
bytes match after independent typed relocation without masks. It defines
no separate data, rodata, or BSS.

## Language and provenance

Original source language is unknown; C++ is the reconstruction fallback,
not a conclusion from matching bytes. Address-based `extern "C"` labels
are synthetic reconstruction linkage, not recovered retail names or linkage.
Types and local names describe observed GBA access widths and behavior.
No other platform's source, executable, or metadata was used. Referenced
graphics, tilemaps, and palettes remain external opaque assets.

The existing agbcc C++ flags are `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`. Whole-object ablation removed three trial bindings: DMA block
size in r3 and two fade-result temporaries in r1/r0. The final source retains
one r1 binding for the input halfword and three empty operand constraints
in the fade-in callback. None injects opcodes. Individually removing them
from the cleaned, complete object gives:

| Removed constraint | Text bytes | Differing bytes |
| --- | ---: | ---: |
| Input halfword r1 | 1,452 | 594 |
| Pending result read/write operand | 1,444 | 493 |
| Zero-second-fade branch result input operand | 1,444 | 491 |
| Other branch result read/write operand | 1,448 | 196 |

The retained object is 1,448 bytes with zero differences. These constraints
describe reconstruction/compiler allocation needs, not original source syntax.

## Boundary and ownership evidence

The initializer independently resets rendering, clears the palette, loads
three backgrounds and localized sprite graphics, and installs fade-in.
Fade-in installs input/update; input installs fade-out; fade-out returns to
startup. An all-alignment ROM survey found nine external stored initializer
pointers at `0x0801AB5C`, `0x0801BEA8`, `0x08028F58`, `0x08029BF0`,
`0x0802C224`, `0x08030268`, `0x08032C30`, `0x0803305C`, and `0x08034480`.
The remaining genuine callback pointers and six-way initialization switch
table are internal. A mapped Thumb BL survey found no calls into this
family or the next initializer. Arbitrary computed references cannot be
excluded by these surveys.

The preceding scene family ends at `0x0803D1A0` and owns its own state at
`0x03005420` and metadata at `0x08EDD5B0`. The next initializer at
`0x0803D748` is independently entered by startup and other dispatchers and
begins a different intro sequence with coordinate/scroll metadata at
`0x08172A3C..0x08172A78`. Neither neighboring family is installed or called
by this menu's callback graph. These are behavioral/layout inferences,
not recovered compiler-object boundaries.

The apparent interior-code value at `0x08BFAEE6` lies in validated MP2K
WaveData sample payload. The apparent shared-state value at `0x08EF1731`
lies in a validated embedded LZ77 stream. The unaligned apparent code value
at `0x08314255` instead spans two big-endian 16-bit script offsets in the
record at `0x08314251`. The stream pointer at `0x08EEB598` is consumed via
`0x08040A94` and initializer `0x08043FC0`; interpreter `0x080440E4` selects
the record's handler at `0x080443EC`, which reads a count and indexes 16-bit
stream-relative offsets. A conservative command/control-flow walk from
the stream entry establishes this record boundary. It is not a stored
menu pointer. No surveyed numeric occurrence remains unclassified.

State at `0x03005254` has 28 code references across engine/frontend code,
including startup, and remains external. The frame counter, queues, input,
save-language state, and current callback are also shared engine storage.
No private BSS or invented alignment allocation is claimed.

## Behavior and verification

DMA order, transfer counts, destinations, and control-register readbacks
are preserved. Language zero selects one secondary sprite image; other
values select the other. The six-case primary image switch retains its
default path that skips the transfer. Each update advances the signed
halfword frame counter by two, subtracts 256 only when above 255, submits
six sprite pieces, and updates background scroll. The input test retains
its separate masks. Palette results retain their byte truncation and
the fade-in callback's two-result handling. Exit clears blending and
installs startup.

`python tools/check_unit_bytes.py main/unknown_0803D1A0` is a required CI
and contributor gate. BSBE78 is the only supported target. Compilation
and byte equality do not establish runtime or physical-hardware validation.
The bootstrap ROM SHA check is not proof of a fully source-linked ROM.

## Reviewed report inventory

Splitting the remaining intro coverage into its own unresolved bucket adds
one unit: 1,962 becomes 1,963, with the function inventory unchanged at
1,300. Full function sizes include 84 bytes formerly classified as unresolved
pool/table data: code/data accounting changes from 270,148/16,507,068 to
270,232/16,506,984 bytes. Total coverage remains 16 MiB. This is a
classification change, not 84 additional recovered instruction bytes.

All four callbacks become newly exact; global exact functions increase from
1,010 to 1,014, with no losses. On this branch, matched code rises from
51.2793% to 51.7992%, and complete code from 43.0283% to 43.5507%.
These branch results do not claim that unmerged main-branch progress changed.
