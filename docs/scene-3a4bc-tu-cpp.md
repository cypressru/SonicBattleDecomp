# Character menu at 0x0803A4BC

This inferred full TU contains 35 functions in `0x0803A4BC..0x0803BFCC`,
6,928 text bytes including pools/alignment, and 668 interpreted ROM-data
bytes. All 7,596 owned ROM bytes are compared without masks after typed
relocation. Nine independently placed BSS spans contain eighteen state bytes.

## Language, names and boundaries

Original source language is unknown; C++ is the repository-required fallback,
not a deduction from matching bytes. Address-based `extern "C"` labels are
synthetic reconstruction linkage, not recovered retail names or linkage.
Types and field names describe observed GBA widths, offsets and behavior.
No declarations from another platform or build are asserted.

The preceding main menu ends at `0x0803A4BC` and its metadata ends at
`0x08EDD344`. This family's page and preview renderers, initializer, display
interrupt callbacks, border helpers, input/navigation transitions and node
callbacks share the character-menu state and layout. The next entry at
`0x0803BFCC` renders a results page using the earlier statistics helpers and
a distinct state cluster beginning at `0x03005404`. Its initializer at
`0x0803C378` references the next position record at `0x08EDD560`, through
the literal at `0x0803C82C`. These are behavioral/reference/layout boundary
inferences, not recovered compiler-object boundaries.

An all-alignment stored-pointer survey found two external code references to
this initializer: `0x0801BE4C` in the return path at `0x0801BD90`, and
`0x0803A380` in the preceding menu dispatcher. Other observed stored entry
pointers are internal. Mapped Thumb BL scans found no external calls into
the interval. Internal calls link the renderers, border helpers and display
cleanup routines to the initializer and input/transition callbacks. Such
scans cannot exclude arbitrary computed references. Numeric coincidences
inside assets or the embedded test payload do not establish callable entries.

## Interpreted data and shared storage

| ROM span | Interpretation |
| --- | --- |
| `0x08EDD344..0x08EDD364` | Two sixteen-byte position records |
| `0x08EDD364..0x08EDD370` | Five halfword scanline coordinates plus alignment |
| `0x08EDD370..0x08EDD4F0` | Six sixteen-pointer language tables |
| `0x08EDD4F0..0x08EDD540` | Two ten-pointer character-name tables |
| `0x08EDD540..0x08EDD54C` | Five halfword cursor coordinates plus alignment |
| `0x08EDD54C..0x08EDD554` | Five byte scroll targets plus alignment |
| `0x08EDD554..0x08EDD560` | Five halfword secondary-cursor coordinates plus alignment |
| `0x0816EBEC..0x0816EC2C` | Sixteen display-register offset/value pairs |
| `0x0816EC2C..0x0816EC6C` | Sixteen four-byte label-layout records |

The position records contain symbolic sprite-part pointers, coordinates
(72,16)/(192,12), tiles 97/161 and six zero attribute/state bytes each.
Text and sprite-part pointees remain external assets. Name tables are shared:
earlier initializers at `0x0802B6E8`, `0x0802B980`, `0x0803984C`, and the
later initializer at `0x0803CB64` also reference one or both tables. Their
physical placement and this menu's state cluster support ownership here;
they are not described as private data.

One flat label array preserves the initializer's first-eight-record traversal,
the seven option-label view at offset eight and the final record at offset
fifteen. Synthetic address macros identify interior views, not separate
original array declarations. Each record contains byte x/y, text index and
alignment mode. All sixteen labels index 0..15. The following bytes begin a
validated LZ77 stream at `0x0816EC6C`, ending at `0x0816ECC9`, producing
608 bytes with valid backreferences. That opaque stream is not embedded in
this source. The display/layout block has only local code references.

Three apparent non-code pointers into the language metadata were located
inside validated MP2K sample payloads: `0x08D5F779` in sample 164,
`0x08E1E413` in sample 313, and `0x08DF7C79` in sample 294. Voicegroup
pointers and WaveData lengths independently establish those payload spans;
these byte coincidences are not stored pointer fields.

BSS bases `0x030053E0`, `0x030053E8`, `0x030053F0`, `0x030053F4`,
`0x030053F8` and `0x030053FC` are byte-sized selections/limits. The first,
second, third and fifth are also cleared by the preceding main menu.
`0x030053E4`, `0x030053EC` and `0x03005400` are four-byte text-table pointers.
The character-name pointer at `0x030053EC` is also read/written by the earlier
statistics scene. These are exported/shared fields, not exclusively private
state. Unaccessed alignment gaps are not invented variables. The following
word at `0x03005404` is independently accessed by the results scene.

The character map at `0x030052D0`, selection at `0x030052E0`, scroll at
`0x030052E4`, width cache at `0x030052E8`, transition byte at `0x030052F8`
and confirmation flag at `0x03005398` remain shared external storage.
Save/input/player/node-pool storage and allocator-owned node allocations also
remain external. The sixteen-byte Node and Position types describe observed
accesses. Copying sixteen bytes from `0x0816FAF4` through a Position-shaped
view in the secondary-cursor initializer describes copy layout only; it is
not a claim about the original asset's semantic type.

## Preserved behavior

Initialization constructs the selectable-character map from save byte 121:
entries 0..6, optional 7 for bit 4, optional 8 for bit 2, and entry 9.
Its count is capped at ten. Another option count is eleven when bit 1 is set,
otherwise ten. Language zero selects its own graphics and name table;
languages 2..5 select their corresponding label tables; language 1 and the
default case select the second table. The original invalid-language default
is preserved. Display storage, palettes, tile maps, renderers and node/IRQ
callbacks are initialized with the observed addresses and ordering.

The page renderer clears 24 rows of sixteen words with a 640-byte stride for
each of five cases, renders descriptor-positioned labels, and right-aligns
selected names/options. It rereads descriptor y and recomputes widths after
rendering when retail does; these lookups/calls are not cached away. The
preview renders into `0x06017A00` with y zero, not the descriptor y. Both
retain byte coordinate wrapping, terminator `0xFFFE`, and glyph value 2.
The special clear helper also clears `0x06017A00`, not `0x06007A00`.

Input has three independent phases, not one early-return chain. First,
pressed buttons select start, confirm or cancel transitions. Second, repeated
up/down input may install navigation callbacks. Third, the repeat field is
read again for left/right value changes and both renderers are called. Later
phases can replace a callback installed earlier in the same frame. Prefix
increment tests, byte wrapping, limit reloads and alias-sensitive rereads are
preserved. No new bounds checks or corrupted-state repairs are introduced.

Navigation animates the transition byte through four, clears/redraws borders
and wraps the five menu selections. Cancel selects the final entry. A
separate confirmation state toggles the existing shared flag. Palette exit
tests retain low-byte truncation of the actual word-returning fade routine.
Transition setup retains signed -1 versus unsigned 255 materializations in
different player-state fields. Cursor/scroll callbacks use their distinct
coordinate arrays; the secondary cursor uses `0x08EDD554`, not `0x08EDD540`.

## Compiler constraints and inventory

The pinned C++ frontend uses `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`.
Whole-owned-object ablation tested 213 initial register/empty constraints,
removing 128 on pass one and two on pass two. Pass three removed none of the
83 survivors: 78 register bindings and five empty operand constraints. Every
trial compiled all 35 functions and compared all three relocated ROM sections
and all nine BSS placements. No fragment-only trial established acceptance.

Retained register bindings preserve loop state, lookup/call handoffs, input
widths, palette result paths and cursor-copy allocation. Four empty read/write
operands retain a clear-loop stride, the final label handoff and two interrupt
register-value handoffs. The fifth is an empty memory output reserving the
renderer frame's four unaccessed bytes beyond its eight outgoing-argument
bytes. Removing it changes only the stack adjustments from twelve to eight.
It reproduces observed frame layout, not an asserted original semantic local.
No constraint emits an injected opcode or embeds asset bytes.

The report's exact-function inventory rises from 988 to 1,003 with no losses.
Twenty of these 35 functions were already exact inside the unresolved bucket;
all 35 now belong to a fully verified TU. The remaining bucket begins at
`0x0803BFCC`. No function-map entry or extent changes.

Full-symbol sizes include 584 bytes of already-covered literal/alignment data
previously classified outside function symbols. This is classification, not
584 newly discovered instructions or extra ROM coverage. The inventory is
1,956 units, 1,300 functions, 269,906 code bytes and 16,507,310 data bytes,
still exactly 16 MiB. The two extra units arise from the remaining code bucket
and an additional external data gap after the label block; the old following
metadata gap is replaced by the gap at `0x08EDD560`. Owned metadata ranges
are excluded from standalone data coverage to avoid double counting.

On this stacked branch, matched code rises from 47.0834166616% to
49.2541846215%, and complete code from 38.4350331573% to 40.9157262158%.
These are branch figures, not a claim that main has received the change.

## Verification

The production byte gate verifies all 7,596 ROM bytes and eighteen minimum
BSS bytes. A clean BSBE78 build passed all 2,068 steps; all 61 automated tests
and all 32 documented byte gates passed. Policy, formatting, Python syntax,
payload, debug-metadata and function-map checks passed. Clean and incremental
normalized reports are identical and pass the reviewed inventory guard.
The bootstrap ROM SHA-1 is `8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.
PR CI and its uploaded report are recorded in the PR.
BSBE78 is the only documented supported target. Bootstrap ROM
SHA-1 verification checks the existing verified-base assembly path; it is not
proof of a fully source-linked ROM. No runtime/emulator or physical-hardware
validation is claimed.
