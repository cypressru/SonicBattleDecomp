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
| `0x0000C0-0x000210` | `0x080000C0-0x08000210` | ARM startup/interrupt object (`crt0`) | Exact |
| `0x000210-0x018678` | `0x08000210-0x08018678` | Game/engine Thumb code; internal TUs unresolved | Exact outer range |
| `0x018678-0x01886C` | `0x08018678-0x0801886C` | Nintendo `multi_sio_asm` object | Strong correlation |
| `0x01886C-0x018C8C` | `0x0801886C-0x08018C8C` | Nintendo `multi_sio` object | Strong correlation |
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

Static analysis currently records 1,298 non-thunk function starts before the confirmed SDK
veneers. The inventory combines whole-ROM Thumb function pointers, decoded direct calls, and
recursive disassembly; it is stored in `config/BSBE78/functions.csv` with generic names and
per-symbol provenance. Of these starts, 814 have aligned ROM pointers, 450 are direct-call targets,
and 47 currently rely on recursive-disassembly recovery alone (categories overlap). Each accepted
start is correlated with the recursive-disassembly end inventory; an extent is capped at the next
accepted start and its enclosing object boundary directly in the reviewed CSV. This gives objdiff explicit target function
sizes instead of extending each function through its following literal pool or alignment gap. The
main game object consequently contains 0x3A64E instruction bytes and 0xDADE owned non-code bytes.
These analyzer-derived extents remain provisional: the inventory is sufficient to give objdiff
symbol-bearing target code, but it is not accepted as proof that every start or end is correct or
as proof of translation-unit boundaries.

The private CI command `python tools/check_function_map.py config/BSBE78/config.yml
rom/baserom.gba` additionally decodes every Thumb `BL` inside those accepted extents. It requires
every in-range destination to be present either in the analyzed function inventory or as an
explicit SDK/runtime symbol in the unit configuration. It also checks every halfword-aligned Thumb-tagged
pointer found outside accepted instruction extents. This proves direct-call and function-pointer
closure for the current inventory and prevents newly exposed call targets from remaining anonymous.

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

The two immediately preceding objects correlate to Sonic Advance 2's `multi_sio_asm.o` and
`multi_sio.o`. Sonic Battle has the same ordered sequence of two low-level serial functions and six
C interface functions. Their combined `0x614`-byte size is identical; the transition between the
two source sequences is the accepted `MultiSioInit` start at `0x1886C`, and the final
`MultiSioStop` ends at the independently established `multi_boot` boundary. Individual bodies have
revision-specific field offsets and sizes, so these names are explicitly recorded as ordered-object
correlations rather than byte matches.

The openly licensed newlib-correlated `memcmp`, `memcpy`, and `memset` sources compile through the
pinned `old_agbcc -O2 -fno-builtin` library path and match their full target sections byte-for-byte.
`memcpy` and `memset` have respective 0x5E and 0x52 function sizes followed by two owned
zero-padding bytes; mapping symbols prevent that padding from inflating the function sizes.

## Original source language

Undetermined pending the complete TU inventory. Current negative evidence: the main executable
contains no detected C++ mangling, RTTI/typeinfo strings, vtable labels, exception runtime names,
`operator new`/`operator delete` identifiers, static-constructor markers, or C++ source suffixes.
This is consistent with C but is not, by itself, proof that every game TU was C.
