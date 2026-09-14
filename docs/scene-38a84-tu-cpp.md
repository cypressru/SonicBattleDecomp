# Statistics scene and shared numeric renderers at 0x08038A84

This inferred TU covers nineteen functions in `0x08038A84..0x08039DD8`,
4,948 text bytes including literals/alignment, and 1,092 interpreted ROM-data
bytes. Its five placed BSS spans contain ten minimum state bytes and a
32-byte inferred formatting-buffer span. The latter is not a safe-capacity
claim; the preserved retail code can write past its inferred boundary.

## Language, linkage and boundaries

Original source language is unknown. C++ is the repository-required fallback,
not a conclusion from a byte match. Address-based `extern "C"` names provide
synthetic reconstruction linkage, not recovered retail symbol names. Types,
field names and array views describe observed GBA access widths, offsets and
behavior; no declarations from another platform or build are asserted.

The preceding settings scene ends at `0x08038A84` and at the start of the
position metadata at `0x08EDCF00`. The numeric renderers, page renderer,
statistics initializer, drawing/copy helpers, frame/input/fade routines and
cursor callbacks share their language pool, formatting buffer and state.
The next entry, `0x08039DD8`, is an animated-tile callback installed by the
following main-menu initializer at `0x08039E20` and by `0x080284B4`, not by
this initializer. The following initializer starts a new position record
at `0x08EDD304`. These are reference, behavior and layout inferences, not
recovered compiler-object boundaries.

An all-alignment stored-pointer survey found one outside pointer into the
owned text: `0x0803A3A0` selects `0x0803984C`. Mapped Thumb BL scans show
that the formatters, generic drawer and clear helper are exported/shared:
`0x0803BFCC`, `0x0803C854` and `0x0803CB64` call them. In particular,
`0x0803CB64` also calls the generic drawer four times. These uses do not
make those later scenes part of this TU. No caller or stored entry pointer
was found for the copy helper at `0x08039C1C`; it remains explicitly
unreferenced reconstructed code. Scans cannot exclude arbitrary computed
references.

## Interpreted data and shared storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDCF00..0x08EDCF30` | Three sixteen-byte position records |
| `0x08EDCF30..0x08EDD2EC` | Physical pool of 239 symbolic text pointers |
| `0x08EDD2EC..0x08EDD304` | Six language-view pointers into that pool |
| `0x0815A0AC..0x0815A0EC` | Sixteen display-register offset/value pairs |

The language views start at pointer offsets 0, 40, 80, 120, 160 and 199.
Their physical spans are therefore 40, 40, 40, 40, 39 and 40 pointers.
One flat physical pool preserves the fifth view's short span and allows
its index 39 to read the first pointer of the sixth view, as retail does.
It does not assert the original number or dimensions of C/C++ arrays.
The statistics page uses indices 0..15 on its normal selection range 0..10.
The later results page draws five labels starting at index 24+selection;
its input handler permits selection 0..11, so its last label can use 39.
The fifth language view is not padded or repaired.

The selector is also referenced by initializers at `0x0803C378` and
`0x0803CB64`, which both assign the shared language pointer at `0x030053BC`.
The display-register table and three position records have only the local
initializer as an observed consumer. Graphics, palettes, sprite-part records
and text pointees remain external assets. The shared character-name tables
at `0x08EDD4F0` and `0x08EDD518`, and their pointer at `0x030053EC`, belong
to the following menu-state cluster and remain external here.

`0x030053B0` is a u32 percentage; `0x030053B4` and `0x030053B8` are byte
maximum/minimum selections. Only this scene references those three bases.
`0x030053BC` is an exported four-byte language pointer, not private state.
The formatting-buffer base at `0x030053C0` is used by the eight numeric
renderers. A 32-byte storage extent is inferred from the next independently
addressed menu byte at `0x030053E0`; it is not a recovered array declaration.
That menu byte is explicitly cleared at `0x0803A34C`, with separate menu
fields at `0x030053E8`, `0x030053F0` and `0x030053F8`. Alignment gaps between
the first four owned spans are not invented variables.

Five non-code numeric matches into the metadata were independently located
inside validated MP2K direct-sound sample payloads: `0x08EAED22` in sample
436, `0x08E3518F` in 320, `0x08E2DD26` in 318, `0x08D19C2A` in 135 and
`0x08E7AA1D` in 411. Voicegroup pointers and WaveData lengths validate those
payload intervals; these byte coincidences are not stored pointer fields.

## Preserved behavior and bounds caveats

Time values clamp at `0x157529FF`. The hours/minutes/seconds renderer omits
zero leading fields; absent tens glyphs become glyph zero, not digit glyph
16. Other formatters clamp at 9,999, 99,999 or 999,999 and retain their
different suffix rules. Coordinates and selection increments wrap at the
observed byte/halfword widths. Copying stops before `0xFFFE`, and the
standalone copy helper does not copy that terminator.

`0x08039374` tests the first glyph of language entry 20 but copies entry
23. For language view 4, entry 20 starts with glyph 5 and entry 23 has
sixteen halfwords before its terminator. Thus this formatter writes
18..23 halfwords for one..six digits: `0x030053C0..0x030053E4` through
`0x030053C0..0x030053EE`, with exclusive ends. These writes cross the
inferred buffer boundary and overlap addresses used by menu state. The
later results initializer assigns this view and calls its page renderer
with selection zero at `0x0803C6C0`; the page calls this formatter at
`0x0803C0A6` for every numeric value. This is a concrete static call-path
finding, not a runtime/hardware observation or a claim about original
allocation intent. No buffer enlargement, suffix correction or new bounds
check is introduced.

The hours/minutes/seconds helper can also exceed 32 bytes for unrestricted
inputs. Its only observed caller, however, supplies a u16 divided by 30,
limiting the argument to 0..2184. Its largest output over the six language
views on that path is sixteen halfwords. This is distinct from the
demonstrated results-page suffix issue; arbitrary computed calls cannot be
excluded. Byte verification preserves both behaviors rather than treating
the inferred storage extent as proof that every write stays within it.

The initializer counts 309 save bytes unequal to FF and computes a capped
percentage. Equal extrema write FF; only strict improvements replace the
selected index. Alias-sensitive rereads after byte stores are retained.
Language values outside 0..5 skip the asset-selection switch but still
index the language selector afterward, as in retail. The page's ignored
fifth numeric-renderer argument is represented as a word for consistent
caller/definition contracts, not proof of original function arity.

## Compiler constraints and verification

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` with the pinned
C++ frontend. Emission follows the complete retail text span. No opcode
assembly is present. Full-owned-object ablation removed 90 of 131 initial
fixed-register/empty constraints over three passes; a fourth pass tested
all 41 survivors independently and removed none. Thirty-six register
bindings and five empty constraints remain. These describe compiler
allocation/order requirements, not original declarations or volatility.

The production independent byte gate matches all 6,040 bytes in three ROM
sections and verifies all five NOBITS placements. Objdiff reports all
nineteen functions and owned sections at 100%. Thirteen functions become
newly exact (six were already exact in the unresolved bucket), taking the
global exact-function count from 967 to 980 with no lost exact matches.

The inventory remains 1,300 functions and 16,777,216 ROM bytes, now in 1,953
units. Ten completed function symbol extents include 208 bytes of literals
previously counted as anonymous data; objdiff's symbol-based code/data
classification changes from 268,880/16,508,336 to 269,088/16,508,128.
Those 208 bytes are not newly discovered instructions or additional ROM
coverage. The branch report's code metric changes from 44.7277596% to
46.4747590%; these are branch values, not a claim that main has changed.

The only supported target, BSBE78, passes a clean 2,059-step build, all 61
tool tests, all 30 documented independent byte gates, payload/debug/function
map checks, source formatting, Python syntax and proprietary-file policy.
Its full-ROM SHA-1 is `8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.
Clean and incremental objdiff reports agree in every unit and aggregate.
Compilation does not establish runtime or physical-hardware validation.
The bootstrap full-ROM SHA check is not
proof of a fully source-linked ROM; the independent complete-section byte
gate is the relevant evidence for this TU.
