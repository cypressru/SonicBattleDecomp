# Progress-menu translation unit

This inferred complete TU contains 27 functions at `0x0802CC78..0x0802DF68`:
4,848 bytes of code, literals and alignment, 536 bytes of contiguous metadata,
and 16 bytes of animation coordinates. All 5,400 owned ROM bytes match
independently without masks. Three observed private RAM bytes are also owned.
No independent original-language evidence establishes C; C++ is the fallback.
Address-based `extern "C"` labels provide synthetic reconstruction linkage,
not original names or linkage. Types describe observed prefixes, not original
declarations or allocation capacities.

## Boundaries and ownership

The initializer, input/variant selection, score and three-item displays,
sprite setup, slide transitions and rendering callbacks share the state at
`0x030052B0`, `0x030052B4` and `0x030052B8`. The preceding results screen
ends at this initializer. The following routine at `0x0802DF68` begins a
different text-rendering switch family using `0x030052F0` and `0x0812E648`.
These are inferred behavioral boundaries, not recovered object-file boundaries.

Metadata at `0x08EDBC7C..0x08EDBE94` contains ten 16-byte position records,
two 11-slot graphics-pointer tables, a 66-slot pointer table, and twelve
signed coordinate halfwords. Each graphics table has ten populated entries
and a final null. The larger table has two such populated groups and 44
trailing null slots. Code observes the first two groups; the reserve extent
is inferred from the next referenced coordinate table, not proof of original
array capacity. The four coordinate triples are `(0,0,0)`, `(-7,7,7)`,
`(-14,0,14)` and `(-14,0,14)`; only variant indices 0 through 2 are observed.
The next position record begins at `0x08EDBE94` and is consumed outside this TU.
Pointees remain external opaque assets; only interpreted records and symbolic
pointers are reconstructed here.

Eight signed animation coordinates at `0x0812E5F8..0x0812E608` form a
separate owned ROM section. Whole-ROM stored-pointer scans, including all
byte alignments, found only this family's code references into the owned
metadata and coordinates, plus one numeric coincidence at `0x08DCBACE`.
That coincidence is inside validated M4A PCM sample 277, whose header is
`0x08DCB09C` and payload ends at `0x08DCC948`; it is not a runtime pointer.
Stored-pointer scans cannot exclude computed references.

Only one byte each at `0x030052B0` (count), `0x030052B4` (selection) and
`0x030052B8` (variant) is defined. All stored references into those minimum
spans are in this family. Intervening gaps are not owned. The character list
at `0x030052D0` has consumers outside the family and stays external, as do
shared save, scene, node-pool and mode state. The independent checker validates
each private section as ELF NOBITS with its exact address and size.

## Compiler and reconstruction constraints

The pinned EGCS C++ pipeline uses TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. All operations remain C++:
there are no instruction assembly bodies, opaque instruction bytes, compiler
changes, byte patches or comparison masks. Symbol-size overrides affect ELF
metadata only; literal and alignment bytes remain included in comparison.

There are 78 register bindings and 37 empty assembly constraints. These are
reconstruction constraints, not original-source or portability claims. A
reverse greedy cleanup removed 96 bindings and 49 empty constraints, checking
all owned ROM and RAM sections after every accepted removal. This is not a
claim of global minimality. Constraints preserve observed register allocation,
address-calculation order, byte truncation, repeated loads and stack placement.
Score saturation, blank leading digits, 14/29-pixel glyph spacing, signed
slide positions and input priority follow the observed operations.

## Verification scope

`python tools/check_unit_bytes.py main/unknown_0802CC78` independently links
the base object using typed address symbols and checks all three ROM sections
and three private NOBITS spans. Objdiff's target is source-composed using
retail bytes and borrowed relocation metadata; its 100% result is not a
substitute for this independent byte gate.

Ten duplicated legacy definitions are removed; unrelated interleaved functions
remain intact. Splitting the legacy bucket adds one report unit (1,937 total);
the 1,301 functions and 266,470 code / 16,510,746 data bytes remain unchanged.
Objdiff merges the three RAM sections into a padded 12-byte view; the independent
check owns only the three actual bytes, not that padding.
The supported build target is BSBE78. The bootstrap ROM is a
verified copy of the reference ROM, not a ROM linked entirely from reconstructed
sources. Its SHA-1 alone does not establish project-level source matching.
Compilation and byte comparison do not establish runtime or hardware validation.
