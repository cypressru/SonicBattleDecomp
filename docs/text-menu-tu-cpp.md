# Text/options-menu translation unit

The complete inferred TU at `0x0802DF68..0x08030F38` contains 40 functions,
12,240 bytes of code, literals and alignment, and 1,172 bytes of interpreted
metadata. All 13,412 owned ROM bytes match independently without masks.
The private four-byte pointer at `0x030052F0` also matches its NOBITS address
and size. No independent evidence establishes the original source language;
C++ is the reconstruction fallback. Address-based `extern "C"` labels are
synthetic reconstruction linkage, not recovered retail names or linkage.
Types describe observed layouts, not original declarations or capacities.

## Boundaries and behavior

The preceding progress-menu TU ends at the first text-rendering switch.
This family shares the language-dependent text table at `0x030052F0`, text
descriptors, option packing and refresh rules, screen initialization, input,
multiplayer handshakes, fade exits and sprite callbacks. The next initializer
at `0x08030F38` starts a different screen family with subsequent pointer tables
at `0x08EDC23C`. These are evidence-bounded behavioral TU boundaries, not
recovered object-file boundaries.

Both text renderers handle seven rows and nine label/value paths. The upper
renderer deliberately falls through after rows zero and two to refresh the
dependent row. Coordinates narrow to bytes after text-width adjustment and
glyph advance. The lower renderer draws a two-tile-high strip. Packed options
use widths 2/3/3/2/1/1/2/1/3, followed by four two-bit player fields. Input
priority, disabled-row skipping, remote command values and repeated refreshes
follow the observed operations. The register setup, IRQ transitions, fades,
scrolling and callback updates belong to the same family.

## Owned data and exclusions

`0x0812E608..0x0812E6F4` contains sixteen register-offset/value pairs (64 bytes)
and 43 four-byte text descriptors (172 bytes). The register consumer writes
successive halfwords to `0x04000000 + offset`. Descriptors contain x, y, text
index and alignment. The title descriptor retains a byte-array view because
the initializer accesses its fields by index. Contiguous descriptor spans are
preserved, including the sixth record before `0x0812E6A4`; this is not a claim
that every possible index is reachable. The palette at `0x0812E6F4` is external.

`0x08EDBE94..0x08EDC23C` contains four 16-byte position records, six 35-entry
glyph-pointer tables, six pointers selecting those language tables, seven
scroll offsets (20, 16, 13, 10, 6, 3, 0), and one alignment byte. Position and
glyph pointees remain external opaque assets. The following pointer tables
are referenced by the next screen, not owned here.

Stored-pointer scans at all byte alignments found only family references into
these owned spans, apart from three numeric coincidences:

- `0x08C70A34` is inside validated M4A sample 058, header `0x08C6FB80`,
  payload end `0x08C74A83`.
- `0x08E119C8` is inside validated M4A sample 310, header `0x08E11954`,
  payload end `0x08E15164`.
- `0x08337A82` is pixel data in `0x08336FB4..0x083386B4`: the DMA3 sequence
  at `0x0803EA4A` copies 2,944 halfwords to `0x06008000`.

The private text-table pointer is defined as four bytes of BSS. Menu state at
`0x030052E0`, `0x030052E4`, `0x030052E8`, `0x030052F4` and `0x030052F8`
has later-screen consumers and remains external. Save, node-pool, sprite and
player state also remain external. Stored-pointer scans cannot exclude all
computed references; ownership additionally follows the observed consumers.

## Function-map corrections

Five old entries are not separate functions. `0x0802F1EA` and `0x0802F2DE`
are upper halfwords of literals in the lower renderer. Their apparent pointers
occur inside validated M4A samples 067 (`0x08C92E90..0x08C94CAF`) and 029
(`0x08C2A788..0x08C2C79F`), respectively. `0x0802F31A` is the renderer's
shared epilogue, reached by a long Thumb BL while using the entry's frame.
The upper renderer likewise reaches its own epilogue at `0x0802EA4A`.

`0x0803013A` is a literal halfword in the initializer's trailing pool. Its
apparent pointer at `0x083A8144` is inside raw graphics copied from
`0x083A3074..0x083A9074`: code at `0x0803EC3C` selects the source and branches
to the DMA3 transfer at `0x0803EE8A`, copying 12,288 halfwords to `0x06010000`.
`0x08030C6E` is another literal halfword; its apparent pointer at `0x08F848E8`
lies inside the independently checked embedded LZ77 stream
`0x08F81D10..0x08F9EE17`. These numeric coincidences are explicitly rejected.

The actual callback starts at `0x08030C78`, with a reviewed push-LR prologue,
a stored callback pointer at `0x08030C70`, 40 code bytes, and eight pool bytes.
The lower renderer's extent now reaches its final return at `0x0802F322`.
All internal literals, switch tables and alignment remain in the byte gate.

## Compiler and verification

The pinned EGCS C++ pipeline uses TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. The reconstruction has
150 register bindings and 16 empty assembly constraints, preserving observed
register allocation, narrowing, load order and stack placement. Greedy cleanup
removed redundant constraints with whole-range comparisons; no global
minimality is claimed. These are reconstruction constraints, not original
source or portability evidence. There are no instruction assembly bodies,
opaque instruction arrays, compiler changes, byte patches or comparison masks.
Symbol-size overrides change ELF metadata only.

`python tools/check_unit_bytes.py main/unknown_0802DF68` independently links
the base object with typed address symbols, compares all three ROM sections,
and checks the private NOBITS span. Objdiff's source-composed target borrows
relocation metadata, so its 100% result is not independent byte evidence.

Ten duplicated legacy definitions are removed; unrelated functions remain.
Nine functions were already exact; all 40 now match, raising the global exact
count from 858 to 889 without losses. The corrected inventory is 1,297
functions, 1,938 report units, 268,468 code bytes and 16,508,748 data bytes,
covering exactly 16 MiB. Internal literal islands remain within enclosing
function extents; these accounting categories are not an instruction census.

BSBE78 is the only supported build target. Its bootstrap ROM is a verified
copy of the reference ROM, not a fully source-linked ROM. The matching SHA-1
does not establish project-level source matching. Compilation and byte checks
do not establish runtime or physical-hardware validation.
