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
