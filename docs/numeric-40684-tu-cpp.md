# Numeric helpers at 0x08040684

This inferred complete utility TU contains four functions in
`0x08040684..0x08040758`: Q14 sine/cosine lookup, unsigned linear-congruential
random generation, and decimal-digit formatting. All 212 text/literal/alignment
bytes and 514 metadata bytes at `0x081731D6..0x081733D8` match after independent
typed relocation without masks. It owns no data or BSS section.

## Language, provenance, and ABI

Original language is unknown; C++ is the reconstruction fallback, not a
conclusion from matching. Address-based `extern "C"` labels are synthetic
reconstruction linkage, not recovered retail names/linkage. Names and views
describe observed GBA behavior; no other-platform source or metadata was used.

The 256 signed lookup samples were independently regenerated from
`round(16384 * sin(2*pi*i/256))`, not extracted as an opaque asset. Every sample
matches. The nearest rounding tie is more than 0.005 away, so the regeneration
does not depend on a half-tie convention. Both lookup functions truncate phase
to eight bits; cosine offsets phase by 64 and masks it to 255.

The observed final zero halfword at `0x081733D6` is included separately. It
could be trailing alignment or an unused closed-cycle endpoint; the consumers
only establish 256 addressable samples. Neither a 257th addressable sample nor
a recovered retail declaration is asserted. The emitted halfword-aligned
metadata includes this zero and ends at the next scene's register table.

The decimal routine calls BIOS `Div` through the existing veneer at
`0x0804A59C`. Numerator and denominator enter r0/r1; quotient and remainder
return in r0/r1. GNU C++ integer-complex is used solely as a typed ABI carrier:
`__real__` reads quotient and `__imag__` reads remainder. The pinned compiler's
ARM `FUNCTION_VALUE` selects r0 for complex-integer mode, and
`arm_return_in_memory` returns false for this non-aggregate type. The emitted
call and both consumers were independently checked against the ROM. This is
not evidence that retail source used complex numbers. It replaces the prior
coverage source's uninitialized r1 output shim with a defined paired return.

All left shifts used to represent signed-byte counters now operate on unsigned
32-bit values. Target signed-byte conversions and arithmetic right shifts
retain their agbcc/GBA behavior without signed-left-shift undefined behavior.
The division denominator is always ten, and the call is reached only for a
current value greater than nine. Negative input, signed-eight-bit width
truncation, zero-width return, backward digit writes, FF padding, and the
remaining-width return are preserved rather than normalized or clamped.
As in retail, callers must supply storage for the resulting cursor span.

The random generator retains unsigned 32-bit wrapping with multiplier
`0x41C64E6D`, increment `0x3039`, and returned bits 16 through 30. Seed storage
at `0x03005430` is also written by the separate reward initializer and remains
external; no private seed allocation or invented BSS is claimed.

## Boundary and ownership evidence

These adjacent general numeric services have many callers across engine,
animation, frontend, and dialog code; they do not install scene callbacks or
own rendering resources. Their only call is the BIOS division veneer. The
preceding function at `0x08040624` instead initializes the scanline/DMA buffer
subsystem. The next function at `0x08040758` independently initializes another
scene, consuming register metadata at `0x081733D8` through its literal at
`0x08040928`. The numeric lookup immediately follows the separate reward
selection metadata, which ends at `0x081731D6`. These behavioral and layout
facts support the bounded utility grouping; they are not recovered compiler
object boundaries.

An all-alignment ROM survey of text, metadata, and the shared seed classified
81 numeric occurrences: four code references, five validated LZ77 payloads,
58 validated MP2K WaveData payloads, two embedded LZ77 streams, ten graphics
payloads with observed DMA/CpuFastSet consumers, and two u16 text streams.
No occurrence remains unclassified. The mapped BL survey independently
identifies the widespread helper callers; arbitrary computed references
cannot be excluded by these surveys.

Graphics classifications use the observed transfer counts and destinations,
not just broad data-gap labels: intro DMA spans `083FD098..08400E18` and
`08401418..08404CD8`, scene DMA `08465AF8..08466E78`, startup DMA
`08328C74..0832ADB4`, ending OBJ DMA `08365C74..0836BC74`, and the actor bank
beginning `085F3E58` consumed as 1,152-byte frames by queued transfer type 3.
The apparent seed-interior value lies in frame 101 of that bank.

The two apparent interior-code values at `081D7337` and `081D985D` straddle
u16 glyphs within strings beginning `081D72D4` and `081D9804`, selected by the
language-zero text table through pointers `08EDFBC0` and `08EDFD44`.
The already matched dialog family selects its language table through
`08EEB228` and consumes u16 commands/glyphs in callback `08046BC4`, with
FFFE terminators at `081D73D2` and `081D9A2C`. These occurrences are not
function-pointer fields. Opaque graphics and text remain external.

## Whole-object allocation ablation

Standard flags remain `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`.
No opcode assembly is injected. Whole-object ablation removed 16 of 22 trial
constraints. The six retained constraints were individually removed again:

| Removed constraint | Text bytes | Differing bytes |
| --- | ---: | ---: |
| Cursor r4 | 212 | 19 |
| Cursor read/write operand | 208 | 123 |
| Digit decrement r1 | 208 | 75 |
| Original shifted width r2 | 212 | 9 |
| Signed remaining width r0 | 212 | 2 |
| Padding decrement r5 | 212 | 15 |

They document compiler-allocation requirements, not original source syntax.
The retained complete object has zero differing bytes in both ROM sections.

## Verification and report accounting

`python tools/check_unit_bytes.py main/unknown_08040684` is a required CI and
contributor gate. BSBE78 is the only supported target. Compilation and byte
equality do not establish runtime or physical-hardware validation, and the
bootstrap SHA-1 is not proof of a fully source-linked ROM.

Two unresolved code buckets around this TU and the split metadata gap increase
unit inventory from 1,962 to 1,965. Function inventory remains 1,300. Complete
function extents reclassify 24 previously unresolved pool/table bytes:
code/data counts become 270,432/16,506,784, still exactly 16 MiB.
All four functions were already counted exact by the old coverage report;
global exact functions stay 1,020 with no losses. This change establishes a
complete independently linked TU, correct literal ownership, safe paired-return
source semantics, and fully owned metadata rather than claiming four newly
matched functions. Branch matched code changes from 52.8335% to 52.8377%, and
complete code from 44.6185% to 44.6922%.
