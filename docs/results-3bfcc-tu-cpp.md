# Results scene at 0x0803BFCC

This inferred complete TU owns ten functions in `0x0803BFCC..0x0803CB64`,
including 2,968 text, literal-pool, and alignment bytes; five 16-byte position
records at `0x08EDD560..0x08EDD5B0`; and sixteen register offset/value pairs at
`0x081703D8..0x08170418`. Seven four-byte BSS words occupy
`0x03005404..0x03005420`. Independent typed relocation compares all 3,112 ROM
bytes without masks and checks every BSS section's NOBITS type/address/size.

## Language, types, and reconstruction

Original source language is unknown: C++ is the required reconstruction
fallback, not an inference from a byte match. Address-based `extern "C"`
labels are synthetic linkage, not recovered retail names or linkage. Names
and partial structure views describe observed GBA behavior and access widths;
no source or metadata from another platform was used. Graphics, text, palettes,
and sprite-part payloads remain external opaque assets. The position metadata
contains symbolic pointers and interpreted coordinates/attributes, not copied
opaque assets. The register metadata describes observed hardware writes.

`StateScore` is only a typed view of observed halfword field 98 and word field
120. Its intervening bytes are not claimed as recovered fields or owned BSS.
The reconstruction's volatile result word preserves the observed repeated
loads; it is not evidence for a retail qualifier. Sound arguments follow the
already recovered halfword-width interfaces. Unsigned arithmetic retains
wrapping score behavior and palette-return values retain byte truncation.

The two variable-denominator ratios explicitly call retail `__udivsi3` at
`0x0804B4E4` with numerator in r0 and denominator in r1. This is not the BIOS
division interface. Its zero path calls the no-op `__div0` at `0x0804B038`
and returns zero. Explicit calls preserve this behavior without inventing a
nonzero gameplay invariant or introducing C++ division-by-zero undefined
behavior. Other divisions/remainders have constant nonzero divisors.

Standard flags remain `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`.
No opcode assembly or fake stack allocation is used. Typed field accesses
keep the shared state base live through the bonus loop; the language switch
preserves the retail signed default checks. Separate induction and termination
variables express the observed loops. Explicit next-iteration values remain
ordinary calculations used by those loops.

## Ownership evidence

Initialization computes time, defeat, miss, ratio, and flag bonuses, accumulates
the total into shared game state, resets rendering, installs backgrounds and
localized sprite graphics, and creates the result UI nodes. The renderer
displays a scrolling window through result labels and values. Input changes
the selection or starts fade-out. Exit updates rank/high-score save fields
when the iteration finishes, then chooses the next dispatcher. Other callbacks
format total-score digits, perform palette fade-in, or conditionally submit
arrow/digit sprites. Existing quirks, ordering, and bounds remain unchanged.

The initializer at `0x0803C378` has one surveyed external stored entry pointer,
at `0x0802C274`. All remaining genuine callback references are internal. The
three mapped Thumb BL calls entering the family target its renderer and are
also internal. The preceding family ends at `0x0803BFCC` with its own metadata
and state through `0x03005400`; the next scene starts independently at
`0x0803CB64`, with its own metadata beginning `0x08EDD5B0` and state at
`0x03005420`. Together with reset/dispatch behavior and contiguous layout,
this supports the complete family boundary, not a fragment chosen for ease of
matching. These remain inferred, not recovered compiler-object boundaries.

An all-alignment ROM survey across text, both metadata spans, and all seven
BSS words classified 70 numeric occurrences: 56 code references, nine inside
validated LZ77 assets, four inside validated embedded LZ77 streams, and one
inside validated MP2K WaveData payload. None remains unclassified. The surveys
do not exclude arbitrary computed references. Shared selection, input, save,
node-pool, text-table, and game-state storage remains external.

## Allocation ablation

Earlier whole-object ablation removed 24 of 31 trial constraints. After the
initializer matched, another whole-object pass removed the time-pointer input,
ratio-scale read/write operand, and next-column r5 binding. Nine constraints
remain; each was removed separately from the complete matching object:

| Removed constraint | Text bytes | Differing bytes |
| --- | ---: | ---: |
| Ratio scale r1 | 2,968 | 271 |
| Bonus termination counter r1 | 2,968 | 20 |
| Tile-copy row counter r1 | 2,968 | 4 |
| Rank r2 | Compiler internal error | No result accepted |
| Difficulty pointer read/write high operand | 2,968 | 38 |
| Difficulty-address r2 | 2,968 | 11 |
| Difficulty-address read/write operand | 2,968 | 11 |
| Difficulty value r2 | 2,968 | 4 |
| Fade result r0 | 2,960 | 144 |

These are reconstruction/compiler-allocation requirements, not evidence for
original syntax. The retained full object has zero differing bytes.

## Verification and report accounting

`python tools/check_unit_bytes.py main/unknown_0803BFCC` is a required CI and
contributor gate. BSBE78 is the only supported target. Compilation and byte
equality do not establish runtime or physical-hardware validation, and the
bootstrap ROM SHA-1 is not proof of a fully source-linked ROM.

The unit inventory changes from 1,963 to 1,962: the independently covered
80-byte metadata range is absorbed into its owner, while the new register
boundary splits a data gap but its owned portion is excluded from duplicate
coverage. Function inventory stays 1,300. Full function extents reclassify
176 previously unresolved pool/table bytes: code/data counts change from
270,232/16,506,984 to 270,408/16,506,808, still exactly 16 MiB.

This TU goes from four to ten exact functions, and global exact functions from
1,014 to 1,020, with no losses. Branch matched code increases from 51.7992% to
52.8335%; complete code from 43.5507% to 44.6185%. These figures describe the
reviewed branch report, not a claim that unmerged main progress has changed.
