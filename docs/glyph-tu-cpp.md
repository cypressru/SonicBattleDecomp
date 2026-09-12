# Buffer and glyph translation unit

This reconstruction owns code at `0x08020978..0x08021050`, the span table at
`0x080716BC..0x0807173C`, the two pixel tables at `0x0807A37C..0x0807AB7C`, and
28 bytes of private state at `0x03004B10`. The four bytes before the following
allocator state are not claimed. This is an inferred complete TU, not recovered
original object-file metadata.

## Evidence and boundaries

The thirteen consecutive routines render glyphs, interpret text commands,
measure widths, initialize/scroll a buffer, and copy tile rectangles. Six
literal references to the state base occur at `0x080209BC`, `0x08020B0C`,
`0x08020CD8`, `0x08020F14`, `0x08020F44`, and `0x08020F74`, all inside this span.
The preceding palette TU and following allocator TU have independently bounded
state and complete matching code. The state accesses establish a minimum
28-byte layout; no unreferenced trailing padding is included.

The span table has one base reference, at `0x08020CDC`. The clearing-mask table
has references at `0x08020AC4` and `0x08020E1C`; the pixel expansion table at
`0x08020AC8` and `0x08020E20`. Their complete sizes follow from the arithmetic
definitions: 32 words and two sets of 256 words. Every word agrees with the
retail bytes. The span table enumerates partial nibble runs; each pixel table
entry expands input bit i to bit 4*i, or clears the corresponding full nibbles.
The source generates these constants arithmetically, without copied asset data.

The width and glyph assets at `0x0807173C` and `0x08071B7C` are externally shared:
their base values occur 44 and 42 times, respectively, including many other
modules. They remain outside this TU. Three numeric lookalikes for interior
state addresses occur in opaque data at `0x081A8C32`, `0x0818A628`, and
`0x081257A2`; these are not established pointers. Base-value scans cannot rule
out computed or indirect references, so the ownership inference is not a claim
of original private linkage.

The former map entry `0x08020C22` lies in the upper halfword of the preceding
routine's `0x0000FFF8` literal. The fill prologue starts at `0x08020C24`, and its
entire 252-byte extent matches a compiled function beginning there. The only
raw value `0x08020C23` occurs in opaque data at `0x08C4E790`; no direct branch
establishes either address as a referenced entry. The map now uses the matching
prologue and explicitly records that rejected numeric pointer. It does not
assert an original alias at the old address.

## Language, types, and compiler

No independent source-language evidence exists here. C++ is the repository's
fallback. Address-derived `extern "C"` labels provide reconstruction linkage,
not original names or original C linkage. `BufferState` and field names describe
observed offsets and uses, not recovered declarations. The two named read-only
sections are reconstruction placement controls, not original section names.

The pinned EGCS C++ frontend and complete agbcc backend compile this unit with
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. No compiler backend changes,
fixed registers, inline assembly, opaque instruction blobs, or byte patching
are used. Function-size overrides describe reviewed code extents only.

Caller evidence requires the bounded renderer to return a 32-bit width: an
8-bit declaration adds narrowing instructions absent from retail callers,
although its own byte-load return can match either declaration. Both width
readers return the last line's width, despite tracking a maximum at newlines;
this observed behavior is preserved. Clipping narrows the remaining row count
to a byte before limiting it to sixteen, preserving wrap behavior.

Matching depends on integer intermediates before pixel-group narrowing,
separate command branches, and separate pointer/value lifetimes. Earlier
equivalent-looking OR conditions and narrowed intermediate assignments changed
register allocation. All thirteen functions match together with owned tables.

## Verification scope

The independent checker links the compiled object at all three retail ROM
spans and compares all 3,928 bytes without masking relocations. It separately
asserts ELF NOBITS state address and size. The data range map excludes the owned
tables from standalone progress accounting, preventing duplicate ROM coverage.
The function-map correction reclassifies two literal bytes previously counted
as code; it does not add or remove ROM bytes or invent another function.

The source-composed objdiff target uses base-object relocation metadata, so its
100% result alone is insufficient: the independent linked comparison is the
binding and full-byte gate. The full-ROM SHA-1 check validates the bootstrap
builder's copied input, not a source-linked ROM. Compilation and matching do not
establish runtime or physical-hardware validation.
