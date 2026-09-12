# Lobby translation unit

The inferred complete TU contains 20 functions at `0x080283F8..0x08029250`,
including 3,672 bytes of text, literals and alignment, plus 288 bytes of
interpreted metadata at `0x08EDB94C..0x08EDBA6C`. All 3,960 owned ROM bytes
match independently. No original-language evidence establishes C: C++ is the
repository's reconstruction fallback. Address-based `extern "C"` labels are
synthetic linkage, not recovered original names or linkage evidence.

## Boundaries and ownership

The family contains title drawing, screen initialization, frame/setup/palette
callbacks, lobby input and selection, connection handshakes, player-record
synchronization, transition and failure callbacks, player markers, name drawing
and settings save/restore. Internal callbacks connect these operations. The
preceding generic node-animation family ends at `0x080283F8`; the next screen
initializer starts at `0x08029250` and uses a different metadata family. These
behavioral relationships and adjacent transitions support an inferred boundary;
no original object-boundary metadata is claimed.

Owned data consists of eight 8-byte sprite parts, four coordinate rows, and
six tables of eight symbolic pointers to external text assets. The sprite
renderer at `0x0801FDA0` corroborates the halfword tile, attribute bytes, signed
x/y offsets, continuation byte and 8-byte stride. The four-part definition at
`0x08EDB954` is retained despite no direct pointer found anywhere in the ROM:
its format and continuation sequence agree with that renderer and it lies
inside the otherwise referenced contiguous sprite group. This is inferred
internal metadata, not proof of an original declaration or current reachability.

Whole-ROM stored-pointer scans, including unaligned positions, found only this
family's consumers for references into the owned block. Neighboring sprite
records before `0x08EDB94C` belong to other screen families. The halfword text
records starting at `0x08EDBA6C` have a different format and are not claimed.
Pointer scans cannot exclude computed references. Text, font, compressed graphics
and palette assets remain external: their contents are not included here.

The compiled `.data` and `.bss` sections are empty. All accessed RAM remains
external. In particular, the `0x03005200..0x0300526F` record/control region has
numerous users outside this family; proximity is not private-BSS evidence.
Node, position, allocation, input, record and settings types describe observed
accesses. Prefix views do not establish complete allocation sizes. Names and
field meanings are reconstruction descriptions, not cross-platform discoveries.

## Compiler and reconstruction constraints

The pinned EGCS C++ pipeline uses the ordinary TU-wide flags
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. Other tested options included
`-fno-cse-follow-jumps`, `-fno-thread-jumps`, `-fno-peephole` and
`-fno-cse-skip-blocks`; none matched the complete TU. No backend changes or
per-function compiler settings are used. Symbol-size overrides affect ELF
metadata only; the independent comparison includes all pools and alignment.

Nineteen functions match without register bindings or inline assembly. The
input callback at `0x080288B4` uses 19 register-bound declarations and five
**empty** inline-assembly constraints. These preserve observed register
lifetimes; they are explicitly reconstruction choices, not original-source
evidence. This differs from the unconstrained C++ used by preceding TU
submissions. All actual loads, stores, arithmetic and control flow remain C++;
there are no assembly instruction bodies, opaque instruction bytes or patches.

Four empty read/write constraints preserve the initial one, the second one,
the host reset value, and the peer reset count. The fifth consumes the r0
value after the final signed command load. Each preceding child-graphics branch
records the graphics address that the emitted store already leaves in r0.
Keeping that value live makes the compiler select the retail r4 scratch for
signed-halfword extension, rather than r0. The assignments add no instructions
in the verified output. These constraints are not claims of portable behavior
under arbitrary compilers or optimizations.

Other emission-sensitive choices include indexed name scanning, explicit
unsigned-byte palette results, separate initialization cursors, and consistent
record-column address views. Typed function pointers supply Thumb linkage;
the code does not add one to already typed callback addresses. BIOS and existing
helper declarations follow their reviewed call interfaces. No asset payloads,
extracted assembly or comparison masks are added.

## Verification

`python tools/check_unit_bytes.py main/unknown_080283F8` independently links
the compiled object with reviewed typed external symbols and compares both
entire ROM sections without masking. The check is required in CI and the
contribution checklist. Objdiff's source-composed target alone is not independent
verification; the byte checker supplies that additional gate.

The integrated report records 20/20 functions at 100%, with seven newly exact
functions and no exact-function regressions: the global set grows from 799 to
806. The text is partitioned into 3,458 function bytes and 214 pool/alignment
bytes; all 3,672 are independently checked. Splitting the remaining code bucket
and separating owned metadata increases the reviewed inventory from 1,929 to
1,931 units without changing 1,300 functions or 16 MiB ROM coverage.

Local verification passed: a clean BSBE78 build (all 1,997 build steps; the only
supported target), all 59 automated tests, all 17 complete C++ TU byte checks,
formatting, 28 Python syntax checks, map/proprietary checks, report nonregression
and the ROM SHA-1 gate. The bootstrap builder copies
the verified base ROM: its SHA-1 is not proof of a fully source-linked ROM.
No runtime or physical-hardware validation is claimed.
