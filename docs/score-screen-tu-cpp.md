# Score-screen translation unit

The inferred complete TU at `0x080336DC..0x08033D10` contains eleven routines,
1,588 text bytes including literals and alignment, 480 position metadata bytes
at `0x08EDC648..0x08EDC828`, and 64 register-setting bytes at
`0x0814BE24..0x0814BE64`. All 2,132 ROM bytes match independently without masks.
No private BSS is identified or claimed.

Original language is unknown: C++ is the repository-required fallback, not a
language-provenance claim. Address-based extern-C labels are synthetic linkage;
types and member names are observed layout views, not recovered declarations.
No GameCube, PS2, PC or other proprietary build metadata is used.

## Boundaries and behavior

The preceding transfer scene ends at this screen initializer. The new family
shares display setup, two groups of score-screen nodes, palette transitions,
timer/input exits and a main-loop service callback. The initializer displays
six decimal score digits, replacing leading zeros with blank glyphs. Values
above 999,998 display six nines. Two screen variants build eight or fifteen
static-position nodes and wait 180 or 300 frames, respectively, with an input
path that ends the wait early. Palette completion advances the callback state;
the exit fades the display before restoring the main callback.

The following routines at `0x08033D10`, `0x08033E60`, and `0x08033F68` are
text helpers for the next menu family, not additional score-screen routines.
Direct-call scans over accepted function extents found their callers only in
`0x08033F68..0x08034CFA`, including the initializer at `0x080340B8` and its
controller. None is called from this score-screen family. The next metadata
at `0x08EDC828` is referenced at `0x08034400`, beyond the proposed boundary.
These are inferred behavioral and layout boundaries, not recovered object
file boundaries. Exported helpers may precede their menu initializer.

## Owned metadata and shared state

Four arrays of observed 16-byte position views occupy the complete metadata
span: eight records at `0x08EDC648`, one at `0x08EDC6C8`, six digit positions
at `0x08EDC6D8`, and fifteen records at `0x08EDC738`. Initializer and callback
consumers copy the complete records, including the packed attribute bytes.
The register table contains sixteen offset/value pairs consumed by the display
register initializer. Sprite parts, graphics and palettes remain external;
the submitted data contains interpreted layouts and symbolic pointers only.

All-alignment whole-ROM scans found four live references into the position
metadata, at `0x08033854`, `0x08033A10`, `0x08033B58`, and `0x08033C6C`, all
inside this family. One additional numerical value at `0x08DDDB46` lies inside
validated M4A sample 282 (`0x08DDB890..0x08DDFCF5`), not a reference table.
The register table has one reference at `0x080337B8`. These scans cannot rule
out all computed references; ownership also relies on complete consumers,
adjacent metadata and the different surrounding screen families.

The observed RAM references are shared engine state: the callback table at
`0x03003150`, node pool at `0x03003E20`, scene state at `0x03001620`, main
callback at `0x03002030`, and input at `0x030048E0`. They remain external.
Per-node allocations and the initializer's six-byte digit buffer are not
private global storage. No RAM gaps or original array capacities are inferred.

## Compiler and verification

The pinned EGCS C++ frontend/agbcc backend use TU-wide
`-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. Greedy cleanup removed ten
register bindings and two empty constraints while checking all three owned
sections after every accepted removal. Three bindings remain in the initializer
(row counter, root node and digit callback); seven empty constraints remain
in the two palette callbacks and the fifteen-node setup loop. These preserve
allocation, narrow-value lifetime and address evaluation order, not original
source declarations. There are no assembly instructions, byte patches, masks,
opaque instruction arrays or compiler changes. No global-minimality claim is
made. Function-size overrides affect ELF metadata only.

`python tools/check_unit_bytes.py main/unknown_080336DC` independently links
the base object with typed address symbols and compares every owned ROM byte.
Objdiff's source-composed target borrows relocation metadata and does not
replace this check. Owned standalone table entries are excluded from coverage
accounting. Six duplicate legacy definitions are removed; unrelated functions
remain unchanged.

The clean BSBE78 build passed all 2,032 steps. All 25 documented independent
byte gates, 61 tool tests, 28 Python syntax checks, 40 source/header formatting
checks, proprietary-file check, payload/debug/function-map checks and ROM
SHA-1 passed. All eleven routines and all reported sections match 100%.
The global exact-function count rises from 919 to 924 without losses. The
reviewed inventory is 1,943 units, 1,298 functions, 268,608 code bytes and
16,508,608 data bytes, exactly 16 MiB. Only the unit-count guard changes for
this split; no new function extents are introduced. Code accounting includes
literal islands inside accepted extents and is not an instruction census.

BSBE78 is the only supported target. The bootstrap ROM is a verified copy of
the reference ROM, not a ROM fully linked from reconstructed sources; its
matching SHA-1 does not establish project-level source matching. No runtime
or physical-hardware validation is claimed.
