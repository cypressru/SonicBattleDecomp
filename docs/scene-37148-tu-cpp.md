# Settings scene family at 0x08037148

This inferred complete TU covers `0x08037148..0x08038A84`: 29 functions,
6,460 text bytes including literals and alignment, 632 interpreted ROM-data
bytes, and fifteen minimum-observed BSS bytes in five placed spans.

## Language, linkage and boundaries

Original source language is unknown. C++ is the repository-required fallback,
not a conclusion from matching output. Address-based `extern "C"` labels
provide synthetic reconstruction linkage, not recovered retail symbol names.
Names and minimum structure views come from this GBA executable's access
widths, offsets, calls and behavior. No original declarations or metadata
from another platform/build are asserted.

The leading renderers at `0x08037148` and `0x080375D8` draw mode-specific
labels and numeric values. The selection helpers, initializer at
`0x08037D44`, frame/input/fade routines and node callbacks through
`0x08038A20` share their state, language tables and display coordinates.
The preceding text-entry family ends at this renderer and at the beginning
of these position records. The next routine, `0x08038A84`, begins a different
family using state at `0x030053BC` onward and metadata at `0x08EDCF00`.
These are inferred reference, behavior and layout boundaries, not recovered
compiler-object boundaries.

An all-alignment whole-ROM stored-function-pointer survey found only one
outside pointer into this family: `0x0803A3B4` selects the initializer.
Scanning mapped code found no external Thumb BL candidates into the owned
text. Such scans cannot exclude arbitrary computed references. The newly
mapped `0x08037C30` helper has an independently decoded Thumb entry, complete
four-case control flow and return at `0x08037D22`, and compiles exactly with
its interspersed literals and final pool through `0x08037D44`. No caller or
stored entry pointer was found; it is explicitly recorded as recovered
unreferenced code, not assigned invented call evidence. Its reviewed symbol
extent is `0x08037C30..0x08037D24`.

## Interpreted ROM data and storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDCD0C..0x08EDCD2C` | Two sixteen-byte position records |
| `0x08EDCD2C..0x08EDCD38` | Five display halfwords, two alignment bytes |
| `0x08EDCD38..0x08EDCED0` | Six arrays of seventeen symbolic text pointers |
| `0x08EDCED0..0x08EDCEE8` | Six pointers selecting those language arrays |
| `0x08EDCEE8..0x08EDCEF4` | Five cursor coordinates, two alignment bytes |
| `0x08EDCEF4..0x08EDCF00` | Five part coordinates, two alignment bytes |
| `0x08158674..0x081586B4` | Sixteen display-register offset/value pairs |
| `0x081586B4..0x081586F8` | Seventeen four-byte label records |

Label records contain byte x/y coordinates, text index and alignment mode;
alignment values one and two subtract full and half text width. Six adjacent
records select language labels. The record at `0x081586D0` has no observed
consumer; its ownership is inferred from the contiguous homogeneous layout
between used records. No claim that every entry is reachable is made. Normal
selection cycles over modes zero through three; mode four is a separate
confirmation display. Graphics, palette, sprite and text pointees remain
external assets. No extracted payloads or assembly are included.

`0x03005390` is a four-byte language-table pointer. `0x03005394` and
`0x0300539C` are byte numeric selections. `0x030053A0` is a four-halfword
numeric text buffer. The intervening byte at `0x03005398` is exported shared
state: outside routine `0x0803BC70` reads and toggles it. Its placement in this
TU is a storage-ownership inference, not proof of an original private/static
declaration. Only minimum accessed sizes are defined; alignment gaps are not
invented storage. Shared save/input/node state and fields at `0x030052E0`
onward remain external.

The all-alignment reference audit found only family consumers for the four
other owned state spans and interpreted tables. Two non-code numeric matches
were resolved independently: `0x08F403CC` lies in a valid embedded LZ stream
`0x08F35258..0x08F5F04C` (232,176 output bytes), and `0x08DDD4DA` lies in
sample payload `0x08DDB8A0..0x08DDFCF5`. They are not pointer fields. LZ
back-reference distances and declared output length were validated.

## Preserved behavior and compiler constraints

Numeric selections wrap at 38 and 197. Leading zero glyphs are replaced with
zero while terminators remain `0xFFFE`; drawing/width operations preserve
the observed distinction between the full buffer and its skipped prefix.
Byte arithmetic and coordinate wrapping are retained. Input checks remain
sequential, including vertical then horizontal repeats; no early-return
behavior is introduced. The clear at `0x08038264` targets `0x06017A00`.
The frame counter uses the observed paired 64-bit increment. Child allocation
byte 21 retains the negated text-width-plus-twelve calculation.

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` with the pinned
C++ frontend. Emission order follows the complete ROM text span. There is no
opcode assembly. Full-owned-object removal tests eliminated 179 of the 254
initial register/empty constraints. Seventy-one fixed-register bindings and
four empty constraints remain; a final pass independently tested all 75
against the same reduced source and none could be removed while preserving
every owned section and BSS check. This is an individual-removal fixed point,
not proof of global minimality.

An unused volatile word reproduces the renderer's observed extra stack word.
Removing it changes only the stack adjustments at text offsets `0xA` and
`0x478`, from twelve bytes to eight. It emits no load/store. The declaration
is an explicit layout constraint; original name, type and volatility are
unknown. It was tested alongside the final 75 constraints and retained.

## Verification

The integrated byte gate verifies all 7,092 linked ROM bytes in three sections
without masks, plus ELF32 NOBITS addresses and sizes for all five BSS spans.
Clean BSBE78 compilation passes (2,055 steps), as do all 61 tool tests, all
29 documented unit-byte gates, proprietary-content, payload-map,
debug-metadata, function-map and Python-syntax checks. The expected ROM SHA-1
matches `8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.

The normalized report verifies 1,952 units, 1,300 functions, 268,880 code bytes
and 16,508,336 data bytes: exactly 16 MiB, with no duplicate ownership. The
new function reclassifies 244 bytes previously counted as data. The added
remaining-code unit balances removal of the settings-only data unit; the
remaining metadata bucket is renamed, leaving the unit count unchanged.
All 29 functions and owned ROM
sections report 100% matching. Against parent `d12b052` (PR #79), eleven of
these functions were already exact in the broad bucket. Global exact functions
increase from 949 to 967, with none lost; code matching rises from 42.7255% to
44.7278%, and complete-TU code from 33.8264% to 36.0071%. These are branch
results, not a claim that main has merged them.

BSBE78 is the only supported target. Compilation does not establish runtime
or physical-hardware validation. The bootstrap ROM build copies the verified
base ROM; its SHA-1 is not proof of a fully source-linked ROM.
