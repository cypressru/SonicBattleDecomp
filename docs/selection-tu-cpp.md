# Selection-screen translation unit

This inferred complete TU contains 44 functions at `0x08029250..0x0802B6E8`,
including 9,368 bytes of text, literals and alignment. It also owns 212 bytes
of interpreted metadata and a one-byte selection cache. All 9,580 owned ROM
bytes match independently. No independent original-language evidence establishes
C; C++ is the reconstruction fallback. Address-based `extern "C"` labels are
synthetic linkage, not original names or evidence of original linkage.

## Boundaries and ownership

The initializer, transition, name/settings updates, player selection, variant
selection, animation, communication and sprite callbacks form one connected
screen family. The preceding lobby ends at `0x08029250`. The helpers beginning
at `0x0802B6E8` and `0x0802B81C` are called by the following screen initializer
at `0x0802B980` and use that screen's metadata and state. These are inferred
behavioral boundaries, not recovered object-file boundaries.

The empty routine at `0x08029C28` consists of a standalone Thumb return followed
by alignment, between the preceding return and the next prologue. It was absent
from the function map; an empty C++ function reproduces its four-byte span.
The preceding analyzed extent already ended at this address. Stored-pointer
and direct-call scans found no references; current reachability is not claimed.

Owned metadata is split into two independently compared sections:

- `0x08EDBABC..0x08EDBB08`: two 16-byte position descriptors and eleven symbolic
  pointers to external graphics, corroborated by copies and indexed consumers.
- `0x08EDBB34..0x08EDBBBC`: two four-player coordinate-pair tables, a four-entry
  mode-position table, and four four-player coordinate tables. Loads, strides
  and signed movement operations corroborate the interpreted layouts.

Whole-ROM stored-pointer scans, including unaligned positions, found only this
family's consumers for the owned metadata. Such scans cannot exclude computed
references. The intervening eleven-pointer table at `0x08EDBB08` has a save
initializer consumer and remains external shared metadata. The following table
at `0x08EDBBBC` has consumers in other screen families and remains external.

The default record at `0x08EDBAAC` is an external name-glyph stream, not an
opaque settings initializer: it is copied into the player-name slots at
`0x03005200`, whose halfword glyphs and `0xFFFE` terminator are consumed by the
accepted name renderer at `0x080290E8`. This text and the preceding glyph streams
are not included. Graphics, fonts and palettes likewise remain external assets.

The one-byte cache at `0x03005250` has two stored-address references, both in
this family: initialization and the mode-dependent cache updater. Retail byte
loads/stores and that lifecycle support inferred ownership of exactly one byte.
The three-byte gap before `0x03005254` is not owned. Neighboring selection,
variant, connection, player-count and player-index state has definite consumers
outside this family and remains external. The byte check validates `.bss` as
NOBITS with exact address and size; it does not copy runtime RAM contents.

Node, position and allocation views describe observed offsets and accessed
prefixes. They do not establish original types or complete allocation sizes.
Previously misleading legacy call labels in the transition were corrected to
the actual reviewed targets `0x080184C8`, `0x08018C3C` and `memcpy`; interior
addresses were not added as fake function entries.

## Compiler and reconstruction constraints

The pinned EGCS C++ pipeline uses TU-wide flags
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. There are no compiler changes,
per-function options, instruction assembly bodies, opaque instruction bytes,
byte patches or comparison masks. Symbol-size overrides affect ELF metadata;
independent comparison still includes every literal and alignment byte.

The source contains 242 register-bound declarations and 86 empty assembly
constraints, including inherited initialization/address phases. These are
explicit reconstruction constraints, not original-source evidence or a claim
of portability to arbitrary compilers. All actual operations remain C++.

Four legacy stack-pointer instruction bodies in the initializer were replaced
by unsigned target-address calculations from a real stack array, an empty
constraint, and conversion back to the appropriate array-element pointer. The
intermediate integer is not dereferenced; no out-of-bounds C++ pointer arithmetic
is used. This preserves the observed two-instruction address materialization.

The synchronization routine was reduced from 17 register bindings and seven
empty constraints to ten and five, while rechecking all 424 bytes. Its peer
counter is unbound, shared between the two loops, and explicitly narrowed to a
byte on each increment. Remaining constraints preserve phase reloads, pointer
operand order and count-address setup. Its outgoing mask-table value is assigned,
not accumulated with OR. Other input paths preserve retail priority and signed
sentinel behavior, including zero-extension-sensitive packet decoding.

## Verification

`python tools/check_unit_bytes.py main/unknown_08029250` independently links
the object with reviewed typed external symbols and compares all three entire
ROM sections. It also verifies the one-byte NOBITS extent. This gate is required
by CI and the contribution checklist. Source-composed objdiff targets alone
are not independent evidence; the byte checker supplies that check.

The repository's bootstrap ROM builder copies the verified base ROM. Its SHA-1
gate is not proof of a fully source-linked ROM. Compilation and static matching
do not establish runtime or physical-hardware validation.

Local integration verification passed: clean BSBE78 build (1,999 steps before
the data-map split; BSBE78 is the only supported target), subsequent map and
format rebuilds, all 59 automated tests, all 18 complete C++ TU byte gates,
function/payload/debug/proprietary checks and the ROM SHA-1 gate. The normalized
report records 44/44 functions at 100%, up from 26/43 previously mapped functions.
The global exact set grows from 806 to 824 without losses. The new empty return
adds two analyzed code bytes; the reviewed inventory is 1,301 functions and
1,934 units, with 266,470 code bytes and 16,510,746 data bytes, totaling 16 MiB.
This TU's text contains 8,816 function bytes and 552 literal/alignment bytes;
all 9,368 text bytes are independently checked.
