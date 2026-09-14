# Results-screen translation unit

This inferred complete TU contains 23 functions at `0x0802B6E8..0x0802CC78`,
including 5,520 bytes of text, literals and alignment, plus 148 bytes of
interpreted metadata and 30 bytes of observed private RAM. All 5,668 owned ROM
bytes match independently, without masks. No independent original-language
evidence establishes C; C++ is the reconstruction fallback. Address-based
`extern "C"` labels supply synthetic linkage, not original names or linkage.

## Boundaries and ownership

The two leading text helpers are called by the initializer at `0x0802B980`
and its selection callbacks. Ranking, score/team adjustment, rendering,
confirmation, communication and sprite callbacks share the same state and
metadata. The preceding selection screen ends at the first helper. The next
initializer at `0x0802CC78` uses a different state family beginning at
`0x030052B0` and metadata beginning at `0x08EDBC7C`. These are inferred
behavioral boundaries, not recovered object-file boundaries.

The contiguous metadata at `0x08EDBBE8..0x08EDBC7C` consists of six symbolic
text-pointer arrays (13 pointers), five four-player coordinate-pair arrays
(80 bytes), and four symbolic graphics pointers (16 bytes). Indexed loads,
strides and consumers establish these interpretations. Text glyph streams,
graphics, fonts and palettes remain external assets. Whole-ROM stored-pointer
scans, including unaligned positions, found only this family's consumers of
the owned metadata. Such scans cannot exclude computed references.

Only these observed RAM spans are defined; intervening gaps are not owned:

| Address | Bytes | Observed use |
| --- | ---: | --- |
| `0x03005270` | 8 | Four horizontal animation offsets |
| `0x03005278` | 4 | Player ordering |
| `0x0300527C` | 1 | Active player count |
| `0x03005280` | 4 | Selected text-pointer table |
| `0x03005290` | 8 | Three decimal glyphs and terminator |
| `0x030052A0` | 1 | Winning team or tie |
| `0x030052A4` | 4 | Player ranks |

Initialization and same-family callback loads/stores support these minimum
spans, not a claim about original allocation capacity. All stored code-address
references into these spans are in this family. Five non-code numeric
coincidences occur inside compressed streams: `0x0813CC9C`, `0x0818B296`,
`0x0819FF8D`, `0x0812A8CE`, and `0x08EF71AA`. The first four are inside parsed
LZ77 assets starting at `0x0813CAF8`, `0x08188CE8`, `0x0819EEDC`, and
`0x0812A0BC`; the last is inside the independently validated embedded-test
stream `0x08EEF9C0..0x08F16058`. These compressed bytes are not runtime pointers.
Shared scene, save, network, node-pool and player-name state remains external.

The byte checker validates each RAM section as ELF NOBITS with its exact
address and size. Explicit zero initializers make the pinned compiler honor
custom BSS sections; no RAM contents are copied from the ROM. Node and position
views describe observed prefixes, not original types or allocation sizes.

## Compiler and reconstruction constraints

The pinned EGCS C++ pipeline uses TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. No compiler changes,
per-function options, instruction assembly bodies, opaque instruction bytes,
byte patches or comparison masks are used. Symbol-size overrides affect ELF
metadata only; comparison includes all literal and alignment bytes.

There are 133 register-bound declarations and 29 empty assembly constraints.
These are explicit reconstruction constraints, not original-source evidence
or portability claims. All actual operations remain C++. Initializer cleanup
removed 58 bindings and 59 empty constraints while rechecking the entire code
range. One memory operand reserves the observed stack-slot placement; one
clobber-only constraint prevents constant-address hoisting into r8/r9/r10/r12.
Removing any one of those four clobbers changed the complete code bytes.
Sorting induction counters remain unbound: binding them caused destructive
register reuse in rejected experiments. Signed packet sentinels, key priority,
tie propagation, saturating adjustments and repeated observed stores are
preserved rather than simplified away.

## Verification scope

`python tools/check_unit_bytes.py main/unknown_0802B6E8` independently links
the base object with typed address symbols and compares both owned ROM
sections byte-for-byte, then checks all seven NOBITS spans. Objdiff's target
is source-composed with retail bytes and borrowed relocation metadata; its
100% result is not a substitute for this independent gate.

Splitting the remaining coverage bucket and metadata gap adds two report
units (1,936 total), without changing the 1,301-function inventory or the
266,470 code / 16,510,746 data byte totals. Seven duplicated legacy function
definitions are removed; unrelated legacy code remains intact.

The supported build target is BSBE78. The bootstrap ROM is a verified copy
of the reference ROM, not a ROM linked entirely from reconstructed sources.
Its SHA-1 alone therefore does not prove project-level source matching.
Compilation and byte comparison do not establish runtime or hardware validation.
