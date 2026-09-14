# Save-choice menu at 0x0803CB64

This inferred complete TU contains seven functions in
`0x0803CB64..0x0803D1A0`, including 1,596 text/pool/alignment bytes,
600 pointer-table bytes and 64 display-register bytes. All 2,260 owned ROM
bytes match without masks after typed relocation. The four-byte BSS pointer
at `0x03005420` has its address and NOBITS size checked independently.

## Language, provenance and boundaries

The original language is unknown. C++ is the repository-required fallback,
not a conclusion from byte matching. Address-based `extern "C"` names are
synthetic reconstruction linkage, not recovered original symbols or linkage.
Types and descriptive field names infer observed GBA widths, offsets and
behavior; no other-platform declarations or original structure names are claimed.

The preceding results-scene family ends at `0x0803CB64` and uses a distinct
state cluster through `0x0300541C`. This initializer installs the wrapper at
`0x0803CF9C` and a twenty-byte controller whose setup, fade, input, cancel and
confirm callbacks comprise the rest of this family. The next function at
`0x0803D1A0` begins a different fade/reset transition and is neither called
nor installed by this TU. These are behavioral and layout inferences, not
recovered compiler-object boundaries.

An all-alignment stored-entry-pointer survey found the initializer pointer
at `0x0803A2DC`, in the preceding menu dispatcher `0x0803A260`. Other true
stored entry pointers are internal. A mapped Thumb BL scan found no calls
into this interval from outside. This cannot exclude arbitrary computed
references. The owned BSS pointer's code references are in this initializer;
the next word at `0x03005424` is independently used by startup and a later
scene and remains external. Unaccessed alignment is not invented storage.

## Owned metadata and external assets

| ROM span | Interpreted contents |
| --- | --- |
| `0x08EDD5B0..0x08EDD670` | Six eight-pointer label tables |
| `0x08EDD670..0x08EDD73C` | Fifty-one location-name pointers for languages 1..5 |
| `0x08EDD73C..0x08EDD808` | Fifty-one location-name pointers for language 0 |
| `0x08171164..0x081711A4` | Sixteen display-register offset/value pairs |

All pointer entries are symbolic references to external text assets. No text,
palette, compressed graphics, tilemap or sprite-part asset bytes are embedded.
Each metadata base's observed code references belong to the initializer.
The next metadata address, `0x08EDD808`, is referenced at `0x0803FA00` in
`0x0803F8DC`, independently supporting the end boundary. The bytes following
the register table are external palettes, not part of the register table.

Three apparent unaligned numeric references into the metadata are inside
MP2K WaveData sample payloads: `0x08BFEE13` in sample 004, `0x08EB042A` in
sample 436 and `0x08D5CDE8` in sample 163. Voicegroup/sample extent checks
classify these as byte coincidences, not stored pointer fields.

The character-name tables at `0x08EDD4F0` and `0x08EDD518` remain owned by
the earlier character-menu TU. The shared language pointer at `0x030053BC`
and its table at `0x08EDD2EC` remain owned by the statistics TU. Save/input
storage, node-pool storage and allocator-managed allocations remain external.
The sixteen-byte Node/Position layouts and twenty-byte Controller describe
observed access widths and allocation size, not recovered original types.

## Preserved behavior

Save byte 1160 being zero bypasses this menu for `0x0802CC78`. Language 0
and 2..5 select dedicated label tables; language 1 and invalid values select
the default table. The subsequent shared-language lookup remains unchecked.
Initialization preserves display/reset ordering, separate stack zero words,
VRAM clears and decompression, tile copies, label placement and saved-time
division by sixty. Saved character names use the external translation table.
Location byte 255 skips location rendering; no new bounds check is added for
other corrupted values. Fifty-one is the observed metadata extent, not an
assertion that every possible saved byte is valid. The signed negative-language
branch and label-based control-flow shape reproduce the observed instructions.

Fade completion accumulates the three palette results with the observed
assignment/OR ordering and byte truncations. It stores the actual zero result
into selection and blend, then installs input handling. Input gives A priority
over B and up/down. Selection animation still runs in the same frame after
installing a confirm/cancel callback. Halfword wrapping, blend clamping and
position interpolation are preserved. Cancel selects `0x08039E20`; confirmation
selects `0x0802CC78` or `0x0803FB2C` according to selection. Exit fade tests
truncate the word-returning helper to a byte. Controller setup initializes only
the observed position fields; untouched fields are not newly cleared.

## Compiler constraints and coverage

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` with the pinned
C++ frontend. Whole-owned-object ablation reduced eighteen initial constraints
to four on pass one, then two on pass two; pass three removed none. Every trial
compiled all seven functions and checked all three ROM sections and BSS.
Only the fade result's `r0` binding and input halfword's `r1` binding remain.
Removing them produces 1,588 text bytes with 443 differing bytes, or 1,600
text bytes with 343 differences, respectively. No empty assembly constraints
or injected instruction opcodes remain. The bindings reproduce result reuse
and input register allocation; they are not claims about original source.

The exact-function inventory rises from 1,003 to 1,006 without losses. Four
of these seven functions were already exact inside the unresolved bucket.
The earlier unresolved interval `0x0803BFCC..0x0803CB64` remains incomplete;
it is not included in this submission. The following bucket starts at
`0x0803D1A0`. No function-map entries or extents change.

Full-symbol sizes reclassify 82 already-covered literal/alignment bytes as
code coverage; this does not represent 82 new instructions. The reviewed
inventory is 1,960 units, 1,300 functions, 269,988 code bytes and 16,507,228
data bytes, exactly 16 MiB. Four extra units are the new complete TU, new
following code bucket and two external data gaps. Owned data ranges are
excluded from standalone coverage. Branch matched code rises from
49.2541846215% to 49.7748046697%, and complete code from 40.9157262158%
to 41.4936960161%. These are stacked-branch figures, not main's progress.

## Verification

The production byte gate verifies all 2,260 ROM bytes and four BSS bytes.
All 61 automated tests and all 33 documented byte gates pass. A clean BSBE78
build passed all 2,076 steps. Policy, formatting, Python syntax, payload,
debug-metadata and function-map checks pass. Clean and incremental normalized
reports are identical and pass the reviewed inventory guard. The bootstrap ROM
SHA-1 is `8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`. PR-CI results are recorded
in the PR. BSBE78 is the only documented supported target.
Bootstrap ROM SHA-1 checking validates the verified-base assembly path, not
a fully source-linked ROM. No runtime/emulator or hardware validation is claimed.
