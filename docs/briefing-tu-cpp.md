# Briefing-screen translation unit

This inferred complete TU contains twelve functions at
`0x08030F38..0x080315BC`: 1,668 bytes of code, literals and alignment,
152 bytes of pointer/coordinate metadata, and 64 bytes of register settings.
All 1,884 owned ROM bytes match independently without masks. There is no
private BSS. No independent original-language evidence establishes C; C++
is the reconstruction fallback. Address-based `extern "C"` labels provide
synthetic reconstruction linkage, not original names or linkage. Types are
observed layout views, not recovered declarations or allocation capacities.

## Boundaries and behavior

The preceding text/options-menu family ends at this initializer. The twelve
routines prepare scene participants from save/configuration fields, load
graphics and palettes, sequence delayed sprite creation, scroll backgrounds,
animate a two-stage background transition, and fade into the next scene.
They share the register table and pointer/coordinate metadata described below.
The initializer at `0x080315BC` begins a different screen family using the
following position metadata and state at `0x030052FC`. These are inferred
behavioral TU boundaries, not recovered object-file boundaries.

The initializer copies character/configuration pairs into the shared scene
view, counts entries other than 255, and sets up the service nodes. The
sequencer uses 30/10/240-frame countdowns and chooses sprite indices according
to participant count. The background animation preserves signed halfword
updates, 60-frame waits, palette interpolation and register writes. Its final
state returns before the shared register updates. Coordinate value 255 is
preserved rather than assigned an unproven interpretation.

## Data ownership

`0x08EDC23C..0x08EDC2D4` contains ten graphics/palette pointer pairs (80 bytes),
six background pointers (24 bytes), nine tile offsets (18 bytes), nine signed
coordinates (18 bytes), nine palette indices, and three alignment bytes.
Tile offsets repeat 0/144/288; palette indices repeat 0/1/2. Coordinates are
0/72/144/36/108/255/72/255/255. The last two background pointers are equal.
The contiguous six-slot extent is retained without claiming original array
capacity or that all indices are reachable. Opaque graphics, palette and
sprite-part pointees remain external. The following position record at
`0x08EDC2D4` is referenced by the next screen's initializer.

`0x08130324..0x08130364` contains sixteen register-offset/value pairs. The
consumer writes each value to `0x04000000 + offset`. Following palettes and
compressed graphics remain external. The configuration records at
`0x0811DD40` are also external shared data.

Whole-ROM stored-pointer scans at all byte alignments found only references
from these twelve functions into the owned spans, plus one numeric coincidence
at `0x08125135` into the register table. That source is inside LZ77 asset 055,
`0x08124B9C..0x08125B4B`. Validation checked all back-reference distances and
the full 6,560-byte decoded length; it is compressed data, not a runtime pointer.
Stored-pointer scans cannot rule out every computed reference; ownership is
also supported by the observed consumers and adjacent metadata boundaries.

Scene state at `0x03001620`, save data at `0x03002110`, the service-node pool,
and the main callback remain shared and external. Per-node allocations are
accessed through observed views; no private global RAM extent is invented.

## Compiler and verification constraints

The pinned EGCS C++ pipeline uses TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. All operations are C++.
There are sixteen register bindings and six empty assembly constraints, all
in the initializer. Greedy cleanup removed 27 bindings and five empty
constraints, independently comparing all 1,884 bytes after each accepted
removal. This is not a global-minimality claim. The constraints preserve
register allocation, stack temporary placement, byte narrowing and load order;
they are reconstruction constraints, not original-source or portability proof.
The five-word fill array is a reconstruction of observed stack offsets, not
evidence of the original local declaration. There are no instruction assembly
bodies, opaque instruction arrays, compiler changes, byte patches or masks.
Function-size overrides affect ELF metadata only.

The byte checker now uses exact linker output-section selectors even without
BSS. GNU ld's default `.rodata.*` wildcard otherwise merges the separate
register table into `.rodata`, despite individual `--section-start` options.
This change neither alters input objects nor relaxes comparisons. Regression
tests check ROM-only script generation and link synthetic ARM constants to
verify both section contents and the relocated pointer between them. The
linking test explicitly skips if ARM tools are absent; it runs in the local
and private-build environments where those tools are installed.

`python tools/check_unit_bytes.py main/unknown_08030F38` independently links
the base object using typed address symbols and checks every byte of all
three sections. Objdiff's source-composed target borrows relocation metadata;
its 100% result is not a substitute for the independent gate.

Six duplicated legacy definitions are removed; unrelated functions remain.
All twelve routines match, including six previously exact routines. The
global exact-function count increases from 889 to 895 without losses.
The inventory remains 1,297 functions and 268,468 code / 16,508,748 data bytes;
the TU and register-data split increase the report to 1,940 units. Coverage
is exactly 16 MiB. Code/data accounting includes internal literal islands
within enclosing function extents, not an instruction census.

BSBE78 is the only supported target. The bootstrap ROM is a verified copy of
the reference ROM, not a ROM fully linked from reconstructed sources. Its
matching SHA-1 does not establish project-level source matching. Compilation
and byte comparison do not establish runtime or physical-hardware validation.
