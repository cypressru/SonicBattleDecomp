# BSBE78 binary analysis

This document records conclusions, confidence, and provenance. It does not contain extracted
assembly or proprietary tool output.

## Debug and symbol audit

The retail ROM is a flat 16 MiB GBA image, not an ELF. The main executable contains no detected
DWARF/STABS records, compiler banner, source paths, assertion filenames, mangled symbol table, or
other surviving developer symbol table. Random byte sequences resembling file extensions were
rejected after inspecting their surrounding non-text data.

`python tools/check_debug_metadata.py rom/baserom.gba` repeats the conservative string-level audit
in the private CI build. A passing result establishes absence of common embedded debug-section,
symbol-table, compiler-banner, and source-path strings; it cannot establish that no information was
discarded when the original ELF was converted to the retail flat binary.

The ROM does retain Nintendo library identification strings inside auxiliary payloads. These are
library/version evidence, not game debug symbols. An embedded GBA test program begins at ROM
offset `0xEEB690` and has header title `AGB TEST PRG`, code `AGBJ`, maker `8P`.

## Main executable map

| ROM range | GBA address | Classification | Confidence |
|---|---|---|---|
| `0x000000-0x0000C0` | `0x08000000-0x080000C0` | GBA header/reset branch | Exact |
| `0x0000C0-0x0001D0` | `0x080000C0-0x080001D0` | ARM startup/interrupt object (`crt0`) | Exact |
| `0x0001D0-0x000210` | `0x080001D0-0x08000210` | Nintendo `MultiSioRecvBufChange` ARM helper | Exact |
| `0x000210-0x000778` | `0x08000210-0x08000778` | Sonic Team engine `core` object | Strong linker-order correlation |
| `0x000778-0x0007FC` | `0x08000778-0x080007FC` | Main object containing `AgbMain` | Strong linker-order correlation |
| `0x0007FC-0x018678` | `0x080007FC-0x08018678` | Game/engine Thumb code; internal TUs unresolved | Exact outer range |
| `0x018678-0x018C8C` | `0x08018678-0x08018C8C` | Nintendo `MultiSioSync` object | Exact outer range; strong source correlation |
| `0x018C8C-0x019568` | `0x08018C8C-0x08019568` | Nintendo `multi_boot` object | Exact |
| `0x019568-0x0198B0` | `0x08019568-0x080198B0` | Nintendo `sio32_multi_load` object | Exact |
| `0x0198B0-0x04833C` | `0x080198B0-0x0804833C` | Game/engine Thumb code; internal TUs unresolved | Exact outer range |
| `0x04833C-0x048F74` | `0x0804833C-0x08048F74` | Nintendo M4A `m4a0` object | Exact |
| `0x048F74-0x04A590` | `0x08048F74-0x0804A590` | Nintendo M4A `m4a` object | Exact |
| `0x04A590-0x04A5F8` | `0x0804A590-0x0804A5F8` | Nintendo BIOS-call veneer archive objects | Exact |
| `0x04A5F8-0x04AF68` | `0x0804A5F8-0x0804AF68` | Nintendo cartridge-backup library (four TUs in project config) | Exact |
| `0x04AF68-0x04B61C` | `0x0804AF68-0x0804B61C` | `libgcc` objects listed in project config | Exact |
| `0x04B61C-0x04B718` | `0x0804B61C-0x0804B718` | `libc`: `memcmp`, `memcpy`, `memset` | Exact |
| `0x04B718-0xEEB690` | | Main ROM data/assets and auxiliary payload data | Exact outer range |
| `0xEEB690-...` | | Embedded `AGB TEST PRG` GBA program | Exact start |

Static analysis currently records 1,293 accepted function starts in the reviewed CSV. The
inventory combines whole-ROM Thumb function pointers, decoded direct calls, and
recursive disassembly; it is stored in `config/BSBE78/functions.csv` with generic names and
per-symbol provenance. Of these starts, 804 have aligned ROM pointers, 450 are direct-call targets,
and 47 currently rely on recursive-disassembly recovery alone (categories overlap). Five
pointer-shaped asset words are explicitly rejected: one lands in an inline DMA literal sequence,
and four land inside pointer-table data. Each accepted
start is correlated with the recursive-disassembly end inventory; an extent is capped at the next
accepted start and its enclosing object boundary directly in the reviewed CSV. This gives objdiff explicit target function
sizes instead of extending each function through its following literal pool or alignment gap. The
game category consequently contains 0x39546 instruction bytes and 0xD9AE owned non-code bytes.
These analyzer-derived extents remain provisional: the inventory is sufficient to give objdiff
symbol-bearing target code, but it is not accepted as proof that every start or end is correct or
as proof of translation-unit boundaries.

### Translation-unit inventory status

Executable-byte coverage and translation-unit recovery are separate measurements. Every byte in
the executable range is represented in objdiff, but the game TU inventory is not complete. Two
explicit placeholder objects currently contain nearly all unresolved game code:

| Placeholder | ROM range | Analyzed functions | Instruction bytes | Owned non-code bytes |
|---|---:|---:|---:|---:|
| `main/unknown_080007FC` | `0x0007FC-0x018444` | 185 | 70,100 | 27,252 |
| `main/unknown_080198B0` | `0x0198B0-0x04833C` | 979 | 162,954 | 28,162 |

These objects are conservative coverage buckets, not claims that either range was one original
source file. Consequently, decomp.dev's size-weighted unit treemap is structurally incomplete even
though its byte totals and progress denominators are complete. A placeholder is split only after
function order, literal-pool ownership, private-data references, alignment, related-title linker
order, or independently correlated metadata supports the boundary. Arbitrary visual subdivision
would misrepresent guesses as original TUs.

Related-title linker order is supporting evidence, not a boundary by itself. The public
[Sonic Advance 3 linker script](https://github.com/SAT-R/sa3/blob/master/ldscript.txt) places
`core.o`, `main.o`, and `task.o` consecutively, which makes the start
of `main/unknown_080007FC` a reasonable place to test for a task-module boundary. We compiled its
public `task.c` and `background.c` with the same pinned agbcc toolchain and compared normalized Thumb
instruction streams against every analyzed function in the placeholder. Neither module produced a
strong function-level correlation. The proposed `task.o` split is therefore rejected for now; no
unit boundary or source name is inferred from linker order alone.

The boundary audit also recovered an otherwise unreferenced function at `0x08018410`. Its 30-byte
Thumb body constructs two DMA descriptors, terminates with a normal return, and owns the aligned
literal pool ending at the next accepted function at `0x08018444`. It has no decoded direct caller
or stored function pointer, which explains why call-closure discovery missed it. The function is
reconstructed in C and matches all 30 instruction bytes in objdiff. Its source is attached to the
conservative placeholder object and does not assert an original filename or TU boundary; the
surrounding TU boundary remains unresolved.

Six additional graphics-queue leaf routines in the unresolved tail now reconstruct as ordinary C:
`0x08017ED0`, `0x08017EEC`, `0x08017F00`, `0x08017F34`, `0x08017F58`, and
`0x08017F6C`. Their queue shapes and background-register state independently correlate with the
public Sonic Advance 2 and Sonic Advance 3 engine interfaces, but that related-title evidence does
not establish Sonic Battle's original filename or TU boundary. All 120 owned instruction bytes
match in objdiff, so the functions remain attached to the conservative placeholder.

That audit also rejected the pointer-closure candidate at `0x080182E0`. The four bytes decode as
the IWRAM address `0x030016C8` and form a literal immediately before the real function at
`0x080182E4`; they are now mapped as data rather than counted as a zero-body function.

The following display-state pass reconstructed another six ordinary-C helpers at `0x080182E4`,
`0x08018300`, `0x08018390`, `0x0801839C`, `0x080183C4`, and `0x080183D0`. They cover signed state
interpolation, a byte target setter, and direct GBA blend-register packing. All 138 instruction
bytes match. The audit also recovered `0x080183C4-0x080183CA`, a coherent leaf with an owned aligned
literal that call and pointer closure had missed; the reviewed inventory now counts it as code.

A subsequent fixed-point helper pass reconstructed `0x08018204`, `0x080182AC`, and `0x08018318`.
The first projects two signed values through the SDK `DivArm` ABI, the second updates a derived
ratio, and the third performs two mode-dependent smoothing updates. All 214 instruction bytes match
with ordinary C. `0x08018318` contains a branch-skipped two-word literal island; marking that island
as data is required for an honest instruction comparison and does not change its accepted function
extent.

The next inverse-projection and queue pass reconstructed `0x0801808C`, `0x080180D4`, and
`0x0801824C`, totaling 168 matching instruction bytes. `0x080180D4-0x080180EA` is another coherent
leaf with an owned literal that closure missed; it copies three halfwords from the shared state at
`0x030048E0` and is now counted as code. The projection helper uses the already identified runtime
`__divsi3` routine, while the queue wrapper preserves the five-argument call ABI naturally in C.

The fixed-point rotation helper at `0x0801816C` now matches all 134 instruction bytes. It subtracts
two shared offsets and applies the signed lookup table at `0x0804DF7C` as a paired sine/cosine
rotation. Expressing both output formulas directly is significant: the intervening output store may
alias the shared angle, so agbcc correctly reloads it for the second result exactly as retail does.

A following queue-record and ring-scan pass reconstructed `0x08018004` and `0x080180F0`, totaling
252 matching instruction bytes. `0x08018004` fills an eleven-field, four-word record from nine
arguments and submits it to the same `0x030033E0` queue and `0x030017CC` count that `0x08017F00`
uses, through the SDK `CpuFastSet` ABI. The retail emission builds the record in one stack slot and
copies it to a second slot immediately before the call, so the source assigns the aggregate to a
second local rather than passing the first one; the interleaved store order also fixes the field
layout independently of argument order. `0x080180F0` scans up to `count` entries of an eleven-slot
halfword ring at offset `0x14` of the 64-byte records at `0x03001B30`, masking each entry and
returning on the first hit. Its ring index is a `u16` that is separately read through a signed
16-bit variable: retail keeps both the zero-extended and the sign-extended forms live across the
wrap test, which reproduces only when the signed reader is a distinct variable rather than a cast of
the unsigned one. The function branches around an aligned in-function literal island at
`0x08018146-0x0801814C`; mapping the alignment halfword and its literal word as data is required for
an honest instruction comparison and does not change the accepted extent. Both functions were also
confirmed byte-for-byte against the retail ROM outside objdiff, comparing the compiled `.text` bytes
with the ROM image and excluding only the relocated words.

A display-reset and frame-submit pass then reconstructed `0x08017C5C`, `0x08017C74`,
`0x08017CB0`, `0x08017CD8` and `0x08017D58`, totaling 138 matching instruction bytes. The two
clear routines drive DMA3 directly from a stack-local zero value, one filling `0x02000000` and
`0x03000000` in 32-bit units and one filling VRAM in 16-bit units; the palette routine propagates
entry 0 across the remaining 511 entries through the SDK `CpuSet` ABI. Both fills only reproduce
when the stack temporary is `volatile` and the DMA register pointer is materialized after that
temporary is cleared: retail recomputes `sp` a second time in the 16-bit case, which a
non-volatile local optimizes away.

The adjacent background-control cluster `0x08017D78`, `0x08017DE8` and `0x08017E5C` follows, adding
326 matching instruction bytes. All three OR a value into the halfword shadow array at `0x03003178`
indexed by background layer, then write that entry through to `BG0CNT`-`BG3CNT` with a four-way
switch, differing only in whether the value is shifted left by 0, 2 or 8. Reproducing them needs the
shadow array to be `volatile` - retail re-reads the element between the OR and the store, which is
GCC 2.95's read-back of a volatile assignment used as a statement - and needs the ORed value to pass
through a `volatile` 16-bit stack temporary, which is why retail truncates with a `strh`/`ldrh`
round trip instead of the usual shift pair. Each switch branches around four in-function literal
islands, now mapped as data.

### agbcc source-shape idioms established in this unit

Seven source shapes were established by matching, and generalize to the rest of the placeholder.

Shared state that is read back by the hardware or by an interrupt is `volatile`, and GCC 2.95
re-reads a volatile lvalue after an assignment used as a statement. The background shadow array at
`0x03003178` reproduces only with that read-back; a plain array drops it.

A value handed to a narrow store is passed through a `volatile` 16-bit stack temporary rather than a
register, which is why retail truncates with a `strh`/`ldrh` round trip through the stack slot
instead of the usual `lsl`/`lsr` pair.

An index used both to subscript an array and to drive a `switch` must be assigned to its own local
first. Without that, agbcc splits it across a scratch register and a callee-saved copy, which is the
entire difference in the `BG0CNT`-`BG3CNT` helpers.

A table base that is indexed once and then accessed through immediate offsets is taken into its own
local before the subscript. Writing `record = &table[index]` directly makes agbcc materialize the
base after the index arithmetic and reuse the index register for it, leaving one extra
register-to-register move; assigning the base to a local first keeps it live across the scaling,
which is what retail does. `0x0800BAAC` matches only in that form. The idiom is specific to this
shape and does not generalize: applied to `0x0801694C` and `0x080066D8`, whose retail code holds the
base in a register and adds a field offset per access, it lets agbcc fold the offsets into immediate
addressing and moves those functions further from retail rather than closer.

A global expression used more than once, with a call in between, is written out at each use rather
than cached in a local. Retail re-materializes both the pool address and the load after the call and
keeps no callee-saved register; a cached local forces the address to live across the call and adds
register saves. `0x080153E0` is the clearest case: it pushes only `lr`.

A record array whose stride is a plain multiple of its element size is declared as a two-dimensional
array and subscripted twice, not as an array of structs. The two forms differ in where the constant
field offset binds: `array[i].field` produces `(base + i * stride) + offset`, while
`array[i][k]` produces `(base + offset) + i * stride` and lets agbcc hoist `base + offset` out of a
loop or keep it in a separate register. This is what the move table in `0x080034F0`
(`const u8 [][10]`), the link receive slots in `0x080179D0` (`s16 [][8]`) and the record read in
`0x080178D0` all need. A third spelling, `(base + offset)[i * stride]`, is not equivalent: it folds
the offset into the literal-pool word instead of emitting an `adds`.

A value read out of narrow memory and then used in arithmetic is an `int`-width local, not a `u16`
one, even though every value involved fits in sixteen bits. With a `u16` local agbcc loads into the
address register and copies to the long-lived register afterwards; the `int`-width pseudo lets the
load target that register directly. `0x080178D0` matches only with `value`, `previous` and the
`changed` mask declared `u32`, while the two masks that are actually stored back stay `u16`.

A cascade of tests that all yield a value assigns to one result local and returns it once; a
cascade that yields an early exit uses `return` directly. The two differ in which arm becomes the
fall-through, and therefore in where the shared tail lands. `0x080034F0` needs the result-local form
(with `return` per branch, agbcc inverts the last conditional and the tail lands two bytes late),
and `0x080179D0` needs the early-`return` form for its `255` case.

### Address-association shapes

Two different address associations appear in this placeholder and are not interchangeable. Most
routines associate `(base + index * stride) + field_offset`, which is what a plain
`array[index].field` produces and what the matched `0x08012B60` and `0x080178D0` use. A second group
associates `(base + field_offset) + index * stride`: retail keeps the raw array base in a register,
adds the constant field offset, and only then adds the scaled index, walking the field offset by the
element size across consecutive statements. `0x0801694C` is the clearest instance - it copies
sixteen halfwords from a 32-byte record into the BG affine registers at `0x04000020`-`0x0400003E`
and walks `base + 2k` while re-reading the record index for every element, because the volatile
register stores invalidate the cached read.

Writing the second association explicitly, as
`*(u16 *)((u8 *)&array[k] + index * stride)`, reproduces that shape and brings `0x0801694C` to every
instruction but three: retail materializes the array base into `ip` before loading the index
address, while agbcc emits the index address first, which also swaps two literal-pool slots. The
operand order in the source does not change this - the multiply makes the index side the costlier
operand, and agbcc expands it first regardless of how the addition is written.

### An unresolved register-allocation difference

Two routines in this placeholder reproduce every instruction except one redundant
register-to-register copy, where retail writes a value straight into its final register and the
pinned agbcc emits an extra `adds rD, rS, #0`. It remains at `0x08017F80` and `0x08017FB0`, the two
queue-submit wrappers around `FUN_080200D8`.

Four routines that were in this list are now matched, and the two causes turned out to be source
shapes rather than allocator noise. `0x080178D0` needed `int`-width locals for the values read out
of memory; `0x080179D0` needed the early-`return` form and the double-shift spelling of its bitfield
extraction; `0x08017CF4` and `0x08015FA4` needed the OAM loop written as an ascending `for` over a
post-incremented `volatile u16 *`. Both idioms are recorded above. `0x08017F80` and `0x08017FB0`
have been retried against all of them and are unchanged, so their divergence is a different cause.

At `0x08015E30` the whole body, the register assignment and the 272-byte size all reproduce, and the
only difference is where the two 16-bit arguments are extended: retail copies them unextended in the
prologue and sign-extends each once at its first use, while the pinned agbcc converts both in the
prologue and then uses the converted value directly. Declaring those parameters `s16`, `u16`, `s32`
or `u32`, with and without an explicit `(s16)` cast at the use, and an old-style parameter list, all
produce the prologue conversion. This also fixes `FUN_08018004`'s first two parameters as signed:
retail sign-extends the values passed there.

A second, related shape accounts for the rest. In `0x0801694C` and `0x080066D8` the whole body
reproduces and only the prologue differs: retail materializes the array base into a register before
computing the scaled record index, while the pinned agbcc emits that pool load after the index
arithmetic. `0x0800BAAC` had the same divergence and was resolved by the table-base local idiom
above; neither of these two responds to it, nor to parameter type, pointer spelling, or the
two-dimensional array declaration.

Both shapes are therefore one-instruction divergences over otherwise fully reconstructed functions:
the field maps, control flow, types and constants are established, and only instruction placement or
register choice differs. That is the state to resume from rather than re-deriving the semantics.

This is not a compiler-flag effect. The emission is unchanged by `-fno-regmove`,
`-fno-cse-follow-jumps`, `-fno-expensive-optimizations`, `-fno-strength-reduce`,
`-fno-rerun-cse-after-loop`, `-fno-cse-skip-blocks`, `-fno-gcse`, `-fno-caller-saves`,
`-fno-thread-jumps`, `-fno-defer-pop`, `-fno-function-cse`, `-fno-peephole` and
`-freduce-all-givs`, and the `old_agbcc` build produces byte-identical output to the pinned
`agbcc`. `-fmove-all-movables` and `-fno-omit-frame-pointer` both make the divergence larger,
not smaller, and `-O1`, `-Os` and `-O3` are all worse than `-O2`.

`-fmove-all-movables` deserves its own note because it is the flag whose description matches the
symptom most closely. Six of the parked routines share one signature: retail hoists or materialises
a value earlier than the pinned agbcc does. Forcing every loop-invariant computation out of the loop
is the obvious candidate for that, and it is wrong - on `0x08016A44` it moves the difference from 33
bytes to 45. So the shared symptom is not loop-invariant motion, and the remaining question is
narrower than "agbcc hoists differently": it is why retail materialises a constant or a load one
instruction earlier within a single basic block. No flag change is therefore
justified and none was made; the remaining difference is a source shape that has not been found yet.
Around twenty source spellings were tried per function, including local reordering, loop form,
pointer versus subscript access, union views and explicit temporaries.

### Decoded but not yet reconstructed: `0x08016A44`

This function only became self-contained after the eighteen long-branch fragments were absorbed; it
previously had `0x08016AFE` sitting inside it. It tints a whole 256-entry palette: for each colour it
adds three signed per-channel offsets read from `0x030016B8`, `0x030020FC` and `0x03001B20`, clamps
every channel first against 31 and then against 0, repacks as BGR555 into a 512-byte stack buffer,
and uploads it with `CpuFastSet` to `0x05000000` as 128 words. The loop counter is `s16` and runs
0..255; the channel extraction is the same `((colour << 16) >> 21) & 31` shape already recorded for
`0x08000CF4`, with `colour` an `int`-width local.

A reconstruction of that shape compiles to the exact 236-byte size and differs in 33 bytes over two
tight clusters. The first is one instruction: retail materialises both `31` constants back to back
before loading any of the three globals, while agbcc emits the second one after the first global
load. The second is scheduling: retail groups both `lsrs` shifts of the CSE'd `colour << 16`
immediately after it and ahead of the red channel, while agbcc defers the `>> 26` until the blue
channel needs it. Everything else, including the clamp order and the pack, is identical.

Three shapes that look like they should force the grouping all lose the common subexpression instead
and land 130 bytes further away: an explicit `shifted` local, raw per-channel locals extracted before
the tints are added, and computing green and blue before red. The lever is not statement order.

### Decoded but not yet reconstructed: `0x0800673C`

The 616-byte routine at `0x0800673C` is fully decoded and is recorded here so the analysis is not
repeated. It has not been written as C yet.

It takes one `u8` participant index, returns early when that index exceeds 3, and otherwise picks a
camera target from the 252-byte participant records at `0x03001C40`. Two guard bytes at record
offsets 110 and 112 select between three paths, and inside the first two a four-way `switch` on the
byte at record offset 125 selects which *other* record to pair with: case 0 uses record 0, case 1
record 1, case 2 record 2, case 3 record 3, addressed as `base`, `base + 252`, `base + 504` and
`base + 756`. The first path writes the midpoints `(a + b) >> 1` of the signed halfwords at record
offsets 0 and 2 into `0x03001374` and `0x03001B24`; the second path compares the signed halfword at
offset 4 of the two records and takes the larger one's value, doubled, into `0x03002100`.

The tail is a quadrant classification of the camera angle returned by `FUN_08018390`, written as
four range tests against `0x03001370`:

| Range | Value stored |
|---|---:|
| outside `0x400 .. 0x1C00` | 0 |
| `0x401 .. 0xBFF` | 2 |
| `0xC01 .. 0x13FF` | 1 |
| `0x1401 .. 0x1BFF` | 3 |

The first test appears in the `<< 16` domain (`(angle << 16) + 0xFC000000` against `0x18000000`)
because agbcc reuses the register still holding the sign-extension of the `s16` return value; the
other three are ordinary `u16` range tests. Both forms are the standard
`(unsigned)(x - lo) > (hi - lo)` transform and should fall out of plain `&&` comparisons.

The function carries roughly ten single-word literal islands, each dumped after a `b` barrier in the
usual `thumb_reorg` position, so it will need that many code/data mapping pairs. The pool words are
`0x03001C40`, `0x03001374`, `0x03001B24`, `0x03002100`, `0x03001370`, the record displacement 758,
and the four range constants -1025, -3073, -5121 and 2046.

A first reconstruction of that shape compiles to the right size, 624 bytes including the trailing
pool, and differs in 145 bytes spread over 28 runs. Most of those runs are one or two halfwords and
are a single register renumbering: retail holds the index in `r5` and `index * 64` in `r6`, one
higher than the pinned agbcc, which suggests retail has one more pseudo competing for `r4`. Two runs
are structural and are where the work should resume - 40 and 38 halfwords covering
`0x0800686E-0x080068D2`, the four larger-of-two cases. Retail loads both records' halfword twice
each, once with `ldrh` for the value and once with `ldrsh` for the comparison, and then cross-jumps
only the final `strh`, so each arm keeps its own literal-pool word for `0x03002100`. Writing the
comparison as a `?:` or hoisting the other record into a pointer both move further away: a `record`
pointer local for the indexed accesses costs another 24 bytes and loses the head entirely.

The two loads per location are already reproduced - the pinned agbcc emits the same `ldrh` and
`ldrsh` pair from a `u16` field read once plainly and once through an `(s16)` cast. What differs is
only placement: retail hoists both `ldrh`s above the branch, so each arm just shifts an
already-loaded register, while agbcc leaves each `ldrh` inside the arm that needs it. Declaring the
field as a `union { u16 u; s16 s; }` is worse, not better - it drops to 612 bytes and 411 differing
bytes because the two members stop sharing an address for CSE. Declaring the field `s16` and casting
to `(u16)` for the stored value is byte-identical to the `u16`-plus-`(s16)`-cast form, since agbcc
folds the cast back into the same load. Neither is the lever; the remaining question is what makes
agbcc hoist a load out of one arm of a branch when the same address is already dereferenced by the
condition.

### Accepted starts that are long-branch targets, not functions

An independent Thumb control-flow walk was built for this placeholder to establish extents without
relying on the analyzer inventory. It follows every reachable basic block from a start, refuses to
decode or branch into words proven to be literal-pool targets, and stops at `bx`, `pop {..., pc}`
and at any independently confirmed entry. Calibrated against the thirty functions in this unit whose
bytes are already verified against the ROM, it reproduces all thirty accepted extents exactly.

Run across the whole placeholder, that walk shows the inventory is mostly sound but contains a
systematic class of false starts. Nineteen of the 185 accepted starts are not preceded by a return,
an unconditional branch, or pool/alignment bytes; each sits inside a basic block and therefore
cannot be a function entry:

`0x080029BC`, `0x0800343E`, `0x080034C2`, `0x08003798`, `0x08003A20`, `0x0800410C`, `0x080043C2`,
`0x0800B086`, `0x0800BAA6`, `0x0800C780`, `0x0800F028`, `0x08010D5E`, `0x08010F1C`, `0x08010F1E`,
`0x0801103C`, `0x08011C2E`, `0x08011C32`, `0x08015374`, `0x08016AFE`.

Fifteen of them are recorded with `direct-call` provenance, so a decoded Thumb `BL` really does
target them. The `BL` is not a call. GCC's Thumb-1 output reaches intra-function labels further away
than the +/-2 KiB `B` range by emitting `BL` instead, which is safe wherever `lr` is already dead.
Every decoded `BL` site for these targets is between 2,030 and 12,688 bytes away, and the targets
themselves are epilogue fragments: `0x0800B086` is `pop {r4, r5, r6}` / `pop {r0}` / `bx r0` with
four such sites, and `0x08011C2C`-`0x08011C36` is a six-instruction "store 3 and return" tail
entered at three different offsets from five sites inside `0x080110F0`. None of the fifteen has a
stored ROM pointer.

The consequence is recorded rather than acted on here: the analyzer's `direct-call` evidence class
cannot distinguish a call from a long intra-function jump, so every routine in this placeholder that
contains a far branch is currently split into several entries with extents truncated at the jump
target. Those routines cannot be matched as units until the inventory separates the two cases. The
functions matched so far are unaffected - none of them contains a far branch, and each compiled
symbol size equals its accepted extent.

### Translation-unit boundary status inside the placeholder

Splitting this placeholder was re-examined with whole-executable data rather than by inspection. For
every IWRAM/EWRAM global, the complete set of accepted functions that reference it was indexed
across the entire main executable, and every candidate split point was scored by how many
tightly-clustered globals straddle it. The metric is sound in the negative direction: it is zero at
all seven independently established object boundaries, and it rules out 113 of the 184 candidate
splits inside the placeholder. It is not sufficient in the positive direction - 72 candidates also
score zero, so it cannot select among them.

Only one positive signal stands out. Eleven distinct IWRAM globals in `0x030029C0`-`0x03002C80`
begin their entire whole-ROM reference run at `0x080110F0`, and several of them
(`0x030029C0`, `0x03002A80`, `0x03002AD0`, `0x03002B7C`, `0x03002B84`, `0x03002B90`) are referenced
by no function outside `0x080110F0`-`0x080127D0`. That is consistent with a file-private data block
belonging to a translation unit starting at `0x080110F0`, but four neighbouring globals in the same
address range (`0x03002B70`, `0x03002B74`, `0x03002B80`, `0x03002BD0`) are also referenced from
`0x0801B394`, well outside the placeholder, so the block is not fully private and the run's upper
edge is not established. Referenced-`.rodata` ordering, which would normally pin object order, does
not help here: the addresses these functions reference lie in the raw asset area rather than in
compiler-emitted `.rodata`, and their order does not follow `.text` order.

A third line of evidence, call-graph cohesion, was also tested and calibrated the same way. For a
candidate range, the decoded `BL` edges were split into calls that stay inside the range, calls that
leave it, and calls that enter it from outside, with intra-function long-branch `BL`s excluded so
they are not miscounted as calls. The calibration settles the question: the two independently
established objects nearest this placeholder, `engine/core` and `main/unknown_08018444`, score 0.03
and 0.02 internal-edge ratios. Real translation units in this game are not call-cohesive at all -
they are collections of leaf helpers called from elsewhere. The best candidate range inside the
placeholder, `0x080110F0-0x08011C7C`, scores 0.40, which is far *above* both known objects and
therefore evidence against it being a whole TU rather than for it.

Compiler-flag change, the remaining boundary indicator, was tested last and is also negative. If
part of this placeholder had been built at a different optimization level, the unmatched routines
would fit some other level better than the `-O2 -mthumb-interwork` that the matched functions
use. They do not. On `0x080066D8`, whose address arithmetic diverges most from the pinned
compiler's, `-O2` scores 35.1% against retail while `-Os` scores 21.8% and `-O1` 14.4%; `-Os` only
appears closer in isolated prologue instructions. The residual differences in the unmatched routines
are therefore source shape, not build settings, and no flag boundary exists to split on.

That exhausts every boundary indicator this project recognizes: literal-pool ownership and alignment
(via the calibrated control-flow walk), private-data and static-symbol reuse, contiguous data
ownership, related-title linker order, call-graph cohesion, and compiler-flag change. All have been
tested against known object boundaries and none supports a split inside this placeholder.

No split is therefore proposed. Three independent lines of evidence have now been tested and
calibrated against known object boundaries: private-static reference locality excludes 113 of 184
candidate splits but confirms none, referenced-`.rodata` ordering does not apply because these
functions reference the raw asset area rather than compiler-emitted `.rodata`, and call-graph
cohesion is not a discriminator in this codebase at all. The evidence available today excludes many
boundaries and confirms none, which is the same conclusion the earlier `task.o` audit reached by a
different route. Splitting the placeholder on anything weaker would publish a guess as an original
TU, which this project's inventory policy rejects.

The same audit rejected four impossible one-byte function extents at `0x0800B210`, `0x0800B770`,
`0x0800B904`, and `0x08011C54`. The first three addresses lie inside pointer-table data; unrelated
asset words happen to encode their Thumb-tagged addresses. The fourth was reached only by recursive
linear disassembly. None can contain a complete Thumb instruction, so they are retained as rejected
analyzer evidence rather than counted as functions.

The range `0x08018444-0x08018678` is now represented as the address-named game unit
`main/unknown_08018444`. Its lower boundary follows the complete return, alignment, and literal pool
of the distinct DMA routine at `0x08018410`; its ten functions form a compact communications-wrapper
cluster. Its upper boundary is the independently correlated start of Nintendo's `multi_sio_sync`
object. The address-based name deliberately avoids claiming an original source filename. During
this split, the boundary audit recovered the previously missed function at
`0x080185A8-0x080185C8`; its five calls and global-byte clear reconstruct as ordinary C and all 32
instruction bytes match in objdiff.
All ten functions in the unit now reconstruct as ordinary C with the pinned agbcc toolchain. Every
owned section matches byte-for-byte in objdiff: 446 instruction bytes and 118 non-code bytes. The
unit is marked complete. This establishes that C is sufficient to reproduce this TU's retail
emission; it does not by itself settle the source language of the unresolved game TUs.

The private CI command `python tools/check_function_map.py config/BSBE78/config.yml
rom/baserom.gba` additionally decodes every Thumb `BL` inside those accepted extents. It requires
every in-range destination to be present either in the analyzed function inventory or as an
explicit SDK/runtime symbol in the unit configuration. It also checks every halfword-aligned Thumb-tagged
pointer found outside accepted instruction extents. This proves direct-call and function-pointer
closure for the current inventory and prevents newly exposed call targets from remaining anonymous.

The startup vector's literal calls Thumb address `0x08000779`, establishing `AgbMain` at
`0x08000778` independently of analyzer naming. Public Sonic Advance 2 and Sonic Advance 3 linker
layouts both place `core.o` immediately after the early MultiSio assembly object and `main.o`
immediately after `core.o`; their `main.c` begins with the same `AgbMain` ABI entry. In Sonic Battle,
the preceding accepted function and its literals end exactly at `0x778`, while `AgbMain` and its
literal pool end at the next accepted function at `0x7FC`. Together these facts support separate
`engine/core` (`0x210-0x778`) and `main/main` (`0x778-0x7FC`) target objects. This is recorded as a
strong linker-order correlation rather than a retail-symbol claim.

The `core` object contains six real functions, not the seven initially inferred from raw pointer
scanning. The candidate at `0x08000422` lands in the middle of an inline DMA descriptor sequence
owned by the function at `0x080003A8`: surrounding words are consecutive graphics source,
`0x06000000` destination, and DMA-control values, and live control flow resumes after the pool.
The sole pointer-shaped word targeting `0x08000422` occurs at `0x08514CD0` in asset data and is
therefore recorded as a rejected coincidence. CI verifies both that exact source word and the
rejected destination so a changed ROM or mapping cannot silently preserve the exception.

All Thumb/data transitions in `core` are now explicit. Three small helpers at `0x080006D0`,
`0x080006EC`, and `0x08000724` compile from C with agbcc `-O2 -mthumb-interwork` and match their
complete 28-, 38-, and 68-byte comparison extents. Their calls, IWRAM references, callback
pointers, and trailing literal ownership all match. Generic names are retained because behavior
establishes the implementations but does not yet supply original game symbol names.

The remaining three `core` functions also reconstruct as C with the same pinned compiler. In
particular, `FUN_080005ac` uses a pre-tested `while` loop whose control-flow island owns two early
literals, followed by explicit DMA0-DMA3 register cleanup; that source shape reproduces the retail
pool and register-emission order without inline assembly or nonstandard optimizer flags. The full
object is marked complete: all six functions, 1,216 instruction bytes, and 168 owned data bytes
match byte-for-byte.

The `crt0` target is also source-backed. Clean ARM startup source reproduces both `start_vector`
and `IntrMain`, including the IRQ/system stack literals, interrupt-vector installation, prioritized
interrupt dispatch, CPSR/SPSR transitions, handler table lookup, and the complete literal pools.
Its 252 code bytes and 20 owned data bytes match byte-for-byte.

All ROM bytes are represented in the generated objdiff project. Bytes after the main executable
are conservatively split at the independently validated embedded-program header: main ROM
data/assets occupy `0x4B718-0xEEB690`, and the embedded payload occupies
`0xEEB690-0x1000000`. Within the main data range, 440 aligned LZ77 streams are validated by their
headers, complete back-reference semantics, and at least one aligned ROM pointer to each stream.
Their starts and intervening unknown-data ranges are recorded in `config/BSBE78/data_symbols.csv`.
The build expands that map into distinct `.rodata` gap units and compressed-asset units. This
classification follows the observed linker layout used by the closely related Sonic Advance 2:
initialized IWRAM objects are `NOLOAD`, while ROM bytes following all executable objects are the
ordered `.rodata` and asset inputs. The terminal raw-asset area is split at `0xBF2118`, where the
M4A event jump table begins. The SDK-correlated table sequence has exact boundaries through
`gXcmdTable` at `0xBF23C0-0xBF23F0`; the bytes at `0xBF23F0` begin M4A tone/voicegroup records.
The six-entry `gMPlayTable` occupies `0xBF71FC-0xBF7244`, followed by the 833-entry
`gSongTable` through `0xBF8C4C`. Song headers establish 16 distinct voicegroup starts; every
resulting range through `0xBF71FC` is an exact multiple of the 12-byte `ToneData` record. Voicegroup
references establish 437 distinct `WaveData` starts. Each sample object ends at the size encoded in
its 16-byte header, with its following alignment or inter-record gap represented separately. The
song table also establishes 249 distinct validated song-header starts. `configure.py` derives these
target units from the verified ROM and rejects unexpected counts, pointer ranges, record strides,
sample sizes, overlaps, or song headers. The preceding `0x3F4418-0xBF2118` raw graphics/asset tail
is now split at 152 aligned ROM targets read from literal pools and other owned non-instruction
bytes in the executable. Source sites inside accepted instruction extents are excluded, preventing
pixel words that happen to resemble `0x08xxxxxx` pointers from becoming evidence. These are proven
symbol starts inside the raw asset area, not yet claims that every resulting interval is one
semantic asset; format-specific parsing must refine them further. Most of the tail following the
final known song start also remains coarse. That tail now excludes the exact 256-byte compiler
`__clz_tab` at
`0xED66A8-0xED67A8`: its bytes uniquely match `_udivdi3.o` from the pinned source-built `libgcc`
archive and are independently validated as the complete 0-through-255 bit-length table. The compact
reconstruction in `src/libgcc/clz_tab.c` independently compiles to a byte-identical `.rodata`
section. The objdiff target keeps the table in its original `_udivdi3` translation unit rather than
counting it again as a standalone object.

Twenty 32-byte character-palette objects within the raw asset area are separately identified from
the offsets published by the public [`sbhax/docs`](https://github.com/sbhax/docs) research project.
The retail ROM independently confirms a complete 16-entry record at every cited offset; explicit
end markers keep adjacent unknown bytes out of each palette unit. Only symbolic offsets and record
sizes are recorded here—no extracted palettes or other asset bytes are included.

The embedded payload is split further into its GBA header, three-symbol ARM bootstrap, six
consecutive validated LZ77 streams, and trailing zero padding. `tools/check_payload_map.py`
independently reparses the streams and verifies the padding. The semantic types of the decompressed
assets and the main data range's remaining internal objects are not yet established.

## Runtime boundary evidence

The pinned `agbcc` build produces runtime objects whose sizes and non-relocated instruction
sequences correlate consecutively with the retail ROM. The resulting boundaries are recorded in
`config/BSBE78/config.yml`. Seven source-built `libgcc` members match complete retail sections:
`_call_via_rX`, `_divsi3`, `_dvmd_tls`, `_modsi3`, `_udivdi3`, `_udivsi3`, and `_umodsi3`.
`_udivdi3` requires a multi-section target object because its linked `.text` is at `0x04B10C` while
its `.rodata` table is at `0xED66A8`; the target preserves the source-built member's relocation and
mapping-symbol metadata while replacing both allocatable sections with independently verified ROM
bytes. `memcmp`, `memcpy`, and `memset` also match their complete `libc` object bodies.

The M4A start is independently correlated by its mixed Thumb/ARM multiply helper and `SoundMain`
layout against the public implementation used by related GBA titles. The `m4a0` assembly-object
function order and offsets correlate through its final event handlers; this retail revision is
`0x1C` bytes larger than the Sonic Advance 2 reference. Its last return is at `0x48F70`, followed by
alignment and the first separately compiled C function at `0x48F74`. The latter object runs
contiguously to the first BIOS-call veneer at `0x4A590`, establishing both M4A TU boundaries.
Relocation-masked comparisons against the byte-identical public Sonic Advance 2 build additionally
establish 32 individual library names in Sonic Battle, including the event handlers through
`MP2K_event_mod`, `m4aMPlayFadeOut`, and the terminal extended-command handlers. Revision-specific
functions that do not independently correlate remain generically named.

The BIOS-call veneer names and boundaries are established by their documented SWI numbers,
calling-convention shims, public SDK ABI, and object alignment. `SoftResetExram` ends at `0x4A5F8`.
All 15 veneers now have clean ABI-level assembly base objects and match their complete target
sections byte-for-byte. Opcode verification also corrected three early labels: SWI `0x12` is
`LZ77UnCompVram`, SWI `0x11` is `LZ77UnCompWram`, and SWI `0x01` is `RegisterRamReset`.
The following function order and object-relative offsets correlate with the public Nintendo flash
library used by Sonic Advance 2. Compiled object sizes, including the previously missed function at
`0x4AAB0`, establish four consecutive TUs: `agb_flash` (`0x4A5F8-0x4AAF8`), the 512-Kbit setup/common
writer (`0x4AAF8-0x4AC14`), `agb_flash_le_512k` (`0x4AC14-0x4AEBC`), and
`agb_flash_mx_512k` (`0x4AEBC-0x4AF68`). Names here come from that public SDK correlation rather
than from retail symbols.

The public Sonic Advance 2 reconstruction at commit
`393357f7c9d46b5c10b6c41a57b80fe3b58f3c8d` builds byte-identically with the same compiler family
and retains separate `multi_boot.o` and `sio32_multi_load.o` objects. Relocation-masked comparisons
match `MultiBootStartProbe`, `MultiBootStartMaster`, `MultiBootHandShake`,
`MultiBootCheckComplete`, and `Sio32MultiLoadMain` uniquely against Sonic Battle. The complete
`multi_boot` function sequence has the same object-relative starts, and its 0x8DC-byte extent lands
exactly at `0x19568`. The following 0x348-byte serial-loader object begins with the matching
`Sio32MultiLoadMain` and lands exactly at the next accepted function at `0x198B0`. Those independent
size, order, offset, and byte correlations establish both object boundaries. Names that did not
individually byte-match are recorded as object-order correlations rather than direct matches.

Compiling the reconstructed `multi_boot` source with agbcc `-O2 -mthumb-interwork` reproduces the
complete 0x8DC-byte `.text` section and its six-byte static `.bss` object. All eight functions,
literal pools, calls, switch-table section relocations, and BSS relocations match the retail object.
The halfword at `0x1915A` is part of `MultiBootMain` after an inline literal pool, not a separate
function: it resumes with live registers and shares the enclosing function's epilogue. The corrected
`MultiBootMain` extent is therefore `0x18C8C-0x191A8`.

The adjacent Nintendo `sio32_multi_load` object at `0x19568-0x198B0` also compiles byte-for-byte
with agbcc `-O2 -mthumb-interwork`. Its three real functions own the complete 0x348-byte `.text`
section: `Sio32MultiLoadMain` (0x1E4), `Sio32MultiLoadIntr` (0xC8), and `Sio32MultiLoadInit`
(0x9C). The alleged function at `0x19808` is instead the interrupt routine's trailing literal pool;
the values are independently consumed as `0x2002`, `0x04000128`, and `0x0400010E`. The work-area
literal fixes `gSio32MultiLoadArea` at `0x03003D70`, with the public SDK layout establishing its
24-byte common-storage size.

The retained `MultiSioSync4Sio32Load020820` string identifies the serial library revision used by
Sonic Battle. A [public reconstruction of the same MultiSioSync family](https://github.com/testyourmine/cvaos/blob/bc23d849d578c35ae12a5cec4e66549c3021a5be/src/agb_multi_sio_sync.c)
at cvaos commit `bc23d849d578c35ae12a5cec4e66549c3021a5be` independently correlates the register operations,
work-area layout, two-player buffer loops, and function order. This corrects an earlier association
with Sonic Advance 2's older `MultiSio4Sio32Load010528` library. The ARM helper at `0x1D0` is
`MultiSioRecvBufChange`; its complete 0x40-byte object now has a byte-identical reconstructed base.
The C object at `0x18678-0x18C8C` begins with `MultiSioSyncInitialize`, contains the correlated
VSync and serial-interrupt handlers, and ends immediately before the independently established
`multi_boot` boundary. Only names explicitly present in the public reference or established by
distinct behavior are retained; the remaining ordered helpers stay generic.

The Battle revision expands the public reference's two-player 0xF0-byte work area to a four-player
0x180-byte layout. Its buffer starts are `0x30`, `0x48`, `0x60`, `0xC0`, and `0x120`; the low nibble
at work-area offset 2 is the live peer mask, while `MultiSioSyncInitialize` stores its parameter in
the high nibble. Compiling the reconstructed initializer, sync/update helper, and packet builder
with agbcc `-O2 -mthumb-interwork` reproduces all three functions byte-for-byte, including inline
literal pools and the interworking return sequences. The explicit mapping-symbol transitions in
the target object distinguish those inline pools from executable Thumb instructions.

The openly licensed newlib-correlated `memcmp`, `memcpy`, and `memset` sources compile through the
pinned `old_agbcc -O2 -fno-builtin` library path and match their full target sections byte-for-byte.
`memcpy` and `memset` have respective 0x5E and 0x52 function sizes followed by two owned
zero-padding bytes; mapping symbols prevent that padding from inflating the function sizes.

## Original source language

Undetermined pending the complete TU inventory. Current negative evidence: the main executable
contains no detected C++ mangling, RTTI/typeinfo strings, vtable labels, exception runtime names,
`operator new`/`operator delete` identifiers, static-constructor markers, or C++ source suffixes.
This is consistent with C but is not, by itself, proof that every game TU was C.
