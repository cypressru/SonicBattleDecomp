# Text-entry scene family at 0x08036350

This inferred complete TU covers `0x08036350..0x08037148`: seventeen
functions, 3,576 text bytes including literals and alignment, 372 interpreted
ROM-data bytes, and eight minimum-observed BSS bytes in five placed spans.

## Language, linkage and boundaries

Original source language is unknown. C++ is the repository-required fallback,
not an inference from matching output. Address-based `extern "C"` labels are
synthetic reconstruction linkage, not recovered retail symbols. Names and
minimum structure views are inferred from this GBA executable's access widths,
offsets, call contracts and behavior; no original declarations or another
platform's metadata are asserted.

The three leading routines draw a scrolling ten-column text grid, allocate
glyph tiles, and redraw the entered text. The initializer at `0x08036560`
owns their display setup and creates the grid/button callbacks. The frame,
input, fade and child callbacks through `0x08037110` operate on the same
state and position/text tables. The last routine installs `0x080370B8` as
its button callback. The preceding family ends at these helpers; its own
tile-cycle table ends exactly where this family's position records begin.

The following routine at `0x08037148` begins a different multi-mode renderer
and state family, using the succeeding metadata and state at `0x03005390`
onward. These are reference, behavior and layout boundaries, not recovered
compiler-object boundaries. The whole-ROM, all-alignment function-pointer
survey found twelve pointers within this family and just two outside it:
`0x0803E744` and `0x08047F14`, both selecting the initializer. Scanning mapped
code extents found no external Thumb BL candidates into the owned text.
Such scans do not by themselves exclude arbitrary computed references.

## Interpreted ROM data and storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDCBEC..0x08EDCC3C` | Five sixteen-byte position records |
| `0x08EDCC3C..0x08EDCCC8` | Thirty-five symbolic grid-row pointers |
| `0x08EDCCC8..0x08EDCCE8` | Eight additional symbolic text pointers |
| `0x08EDCCE8..0x08EDCD0C` | Nine symbolic code-string pointers |
| `0x08156C70..0x08156CB0` | Sixteen display-register offset/value pairs |
| `0x08158660..0x08158674` | Nine halfword selection IDs, byte count, alignment |

The selection IDs follow `238 + 8 * index` for indices zero through eight;
the count is nine and the structure has one zero alignment byte. The eight
additional text pointers have no observed direct consumer; their inclusion
uses the contiguous pointer-array layout and adjacent family data. No claim
that all entries are reachable, or that the renderer has forty-three rows,
is made. Sprite, palette, graphics and text pointees remain external assets;
no extracted payloads or assembly are included.

The slot bitmap at `0x0300537C` is one byte. Scroll offset, grid selection,
and entered length at `0x03005384`, `0x03005388`, and `0x0300538C` are
halfwords. Only these minimum access sizes are defined; alignment gaps are
not invented storage. The intervening byte at `0x03005380` is an exported
scene-entry/return mode, not private state: `0x0803E6E8` sets it to zero
after selecting the initializer, `0x08047EC4` sets it to one on the other
entry path, and `0x080402B0` inspects it during return. Its placement with
the other four fields is an inferred TU storage assignment, not proof of
an original static declaration. Shared save/input/node storage, the text
buffer at `0x03005200`, and scene header at `0x03005330` remain external.

All-alignment stored-reference scans found only family consumers for the
four private fields and interpreted tables. Three non-code numeric matches
were independently contained in valid LZ streams: `0x081AEABB` in
`0x081AE4EC..0x081AEBF7` (4,608 output bytes), `0x08139308` in
`0x08139140..0x08139C8E` (8,832), and `0x0819AD6E` in
`0x0819ABD4..0x0819D78F` (28,448). Back-reference distances and declared
output lengths were checked, rather than treating those bytes as pointers.

## Preserved behavior and compiler constraints

The bitmap is byte-wide even though allocation scans sixteen bit masks.
This mismatch is preserved, not repaired. Backspace stores zero; confirmation
padding stores `0xFFFE`. The grid scroll wraps over 350 entries. Name and
code-entry modes have different exit callbacks and save effects. Code entry
uses the observed flag word at save + `0x4DC` and counters at save + `0x120`
plus the selected ID: `255` becomes zero, counters above eight reject the
entry, and already-set flags continue the comparison/search behavior.

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`, using the pinned
C++ frontend. Source emission order follows the complete ROM text span.
There is no opcode assembly. Forty-eight fixed-register bindings and eight
empty constraints remain. Full-owned-object removal tests eliminated 61 of
117 constraints; a second pass tested all remaining 56 individually and
none could be removed while preserving all owned sections and BSS checks.
This is an individual-removal fixed point, not proof of global minimality.

## Verification

The integrated unit-byte verifier passes all 3,948 linked ROM bytes across
four sections without masks, and validates all five BSS sections as ELF32
NOBITS at their documented addresses and minimum sizes. Full build, report,
and regression checks passed: clean BSBE78 compilation (2,052 steps), all
61 tool tests, all 28 documented unit-byte gates, proprietary-content,
payload-map, debug-metadata, function-map, Python-syntax, formatting and
whitespace checks. The expected ROM SHA-1 matches:
`8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.

The normalized report contains 1,952 units, 1,299 functions, 268,636 code
bytes and 16,508,580 data bytes: exactly 16 MiB with no duplicate ownership.
The three additional units arise from the new remaining-code bucket and
the external remainders around the separately owned register/code metadata.
All seventeen functions and the complete ROM sections in this TU report
100% matching. Compared with parent `6f5b99e` (PR #78), fifteen of the
seventeen were already individually exact in the broad bucket; the new
exact functions are `FUN_080368dc` and `FUN_08036e64`. Across the entire
report, exact functions increase from 947 to 949 with none lost. Code
matching rises from 42.1247% to 42.7255%, and complete-TU code from 32.5675%
to 33.8264%. These are branch results, not a claim that main has merged them.

BSBE78 is the only supported target. Compilation does not establish runtime
or physical-hardware validation. The bootstrap ROM build copies the verified
base ROM; its SHA-1 is not proof of a fully source-linked ROM.
