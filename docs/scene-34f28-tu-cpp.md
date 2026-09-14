# Scene family at 0x08034F28

This inferred complete TU ends at `0x08036350`: 48 functions, 5,160 text
bytes including literals and alignment, 260 interpreted ROM-data bytes,
and 37 minimum-observed BSS bytes in fourteen separately placed spans.

## Language, names and boundaries

The original source language is unknown. C++ is the repository-required
reconstruction fallback, not a conclusion from the compiler match.
Address-based `extern "C"` labels are synthetic linkage, not retail symbols.
Names, structures and field types are inferred from this GBA executable's
access widths, offsets, call contracts and behavior. No other platform's
proprietary metadata or original source declarations are asserted.

The preceding list editor ends at this initializer. It resets four players,
selects language-dependent graphics/name tables, updates selected-entry save
counters, sets up the display, and creates a callback-driven scene. Fade,
text, movement, sprite and exit callbacks share its state and tables.
The final callback setup at `0x0803631C` installs the four-tile animation
controller at `0x080362DC`.

The next three helpers at `0x08036350`, `0x08036428`, and `0x080364D8`
belong to the following scene, rather than this TU: their observed callers
are exclusively at `0x080366F8`, `0x080367A0`, `0x08036B74`,
`0x08036BB8`, `0x08036C04`, and `0x08036FC4`. That next initializer
at `0x08036560` initializes their state at `0x0300537C` and
`0x03005384`; their label table is `0x08EDCC3C`. Its position metadata
starts at `0x08EDCBEC`, immediately after this family's tile cycle.
These are behavioral, reference and layout boundaries, not recovered
compiler object boundaries.

## Interpreted data and storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDC9B8..0x08EDCA4C` | 37 symbolic text pointers |
| `0x08EDCA4C..0x08EDCA64` | Six language slices into that pointer array |
| `0x08EDCA64..0x08EDCA6C` | Four horizontal coordinates |
| `0x08EDCA6C..0x08EDCA74` | Four sprite tile offsets |
| `0x08EDCBE4..0x08EDCBEC` | Four-step tile cycle, indexed by `(state >> 3) & 3` |
| `0x08155348..0x08155388` | Sixteen display-register offset/value pairs |

Language slices begin at indices 0, 6, 13, 19, 31 and 25. All 37 pointer
entries are preserved; this does not assert that all are reachable.
Sprite-part, palette, graphics and text pointees remain opaque external
assets. No extracted payload or assembly is included.

Private-state definitions use only observed sizes: bytes at `533C`, `5350`
and `5374`; pointers at `5340`, `5354` and `5358`; halfwords at `5348`,
`534C`, `535C`, `5368`, `536C`, `5370` and `5378`; four halfwords at
`5360` (addresses prefixed `0x0300`). Alignment gaps and the unused `5344`
slot are not invented storage. The shared scene header at `0x03005330`,
save data, node pool, input, main callback and language resources remain
external. Scene records and callback allocations are minimum access views,
not assertions about original allocation capacity or declarations.

Whole-ROM all-alignment stored-reference scans found no outside code
references to these private spans or interpreted tables. Twenty-five
non-code numeric occurrences were checked independently: seventeen graphics
LZ streams, four embedded-program LZ streams, two M4A samples, one DMA
graphics span and one raw sprite frame. Compressed streams were parsed with
valid back-reference distances and exact declared output sizes.
The M4A samples are `0x08C591B4..0x08C5ECB5` and
`0x08DCC94C..0x08DD005C`. The DMA span is
`0x08350834..0x08352574`, from its actual DMA3 source and count.
The raw occurrence at `0x085D1B09` is 465 bytes into frame 242 of base
`0x0858D838`, selected at `0x08015C28` and queued at `0x08015D9C`.
The independently matched transfer dispatcher uses 1,152-byte frames;
this frame occupies `0x085D1938..0x085D1DB8`.
Stored-reference scans alone cannot exclude arbitrary computed references;
the inference also uses the consumers and state/layout boundaries above.

## Newly identified leaf and preserved behavior

`FUN_08035a5c` is a previously unmapped, unreferenced leaf. Its fourteen
Thumb instructions occupy `0x08035A5C..0x08035A78`, ending in `BX LR`;
five state-pointer literals follow through `0x08035A8C`. Natural C++ exactly
reproduces all 48 bytes. It resets the same text state as the timed scene
callback. No direct-call, short-branch or stored-pointer caller was found;
no reachability is claimed. The map gains one function and 28 code bytes,
losing exactly 28 data bytes while retaining 16 MiB total ROM accounting.

The text command `0xFFFD` clears the cursor without advancing the stream.
The parent and child record-selection clamps differ (9 versus 10). Both
behaviors are preserved. Save counters are accessed at save-base + `0x120`
plus the selected index; inferred access views do not invent array bounds.
The five-word initializer local models observed stack clear slots, not an
original source-level array declaration.

## Compiler and verification

Flags: `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`, using agbcc's C++
frontend. Source emission order follows the complete ROM text span.
Ten fixed-register bindings and five empty constraints remain; there is no
opcode assembly. Full-object ablation removed 29 of 44 initial constraints.
Removing any one of the remaining fifteen breaks the complete owned-span
match, with owned data and all BSS definitions included in the tests.

Local full-object verification passes all four ROM sections byte-for-byte,
without masks, and validates the fourteen BSS sections as ELF32 NOBITS with
their exact minimal addresses and sizes. The clean BSBE78 build passed all
2,045 steps, all 61 tool tests passed, and all 27 documented unit-byte gates
passed. Proprietary-content, function-map, embedded-payload and debug-metadata
checks passed, as did formatting and whitespace checks. The ROM SHA-1 is
`8cf4fbbe73f6b1907ab9997caab4c4e7d9708937` and matches the expected hash.

The normalized objdiff report has 1,949 units, 1,299 functions, 268,636 code
bytes and 16,508,580 data bytes: exactly 16 MiB, with no duplicate ownership.
All 48 functions and all four ROM sections in this TU are 100% matching.
Compared with main `065c6f5`, exact functions increase from 936 to 947,
with no previously exact function lost. Code matching increases from
41.1246% to 42.1247%; complete-TU code increases from 30.9082% to 32.5675%.
The former broad bucket already had 37 of this family's 47 mapped routines
matching individually; this change completes those routines' TU and adds
the previously unmapped leaf, rather than claiming 48 newly exact functions.
BSBE78 is the only supported target. Compilation does not establish runtime
or hardware validation. The bootstrap ROM build copies the verified base
ROM, so its SHA-1 is not proof of a fully source-linked ROM.
