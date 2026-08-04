# BSBE78 binary analysis

This document records conclusions, confidence, and provenance. It does not contain extracted
assembly or proprietary tool output.

## Debug and symbol audit

The retail ROM is a flat 16 MiB GBA image, not an ELF. The main executable contains no detected
DWARF/STABS records, compiler banner, source paths, assertion filenames, mangled symbol table, or
other surviving developer symbol table. Random byte sequences resembling file extensions were
rejected after inspecting their surrounding non-text data.

The ROM does retain Nintendo library identification strings inside auxiliary payloads. These are
library/version evidence, not game debug symbols. An embedded GBA test program begins at ROM
offset `0xEEB690` and has header title `AGB TEST PRG`, code `AGBJ`, maker `8P`.

## Main executable map

| ROM range | GBA address | Classification | Confidence |
|---|---|---|---|
| `0x000000-0x0000C0` | `0x08000000-0x080000C0` | GBA header/reset branch | Exact |
| `0x0000C0-0x000210` | `0x080000C0-0x08000210` | ARM startup/interrupt object (`crt0`) | Exact |
| `0x000210-0x04833C` | `0x08000210-0x0804833C` | Game/engine Thumb code; internal TUs unresolved | Exact outer range |
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
accepted start and its enclosing object boundary. This gives objdiff explicit target function
sizes instead of extending each function through its following literal pool or alignment gap. The
main game object consequently contains 0x3A66A instruction bytes and 0xDAC2 owned non-code bytes.
These analyzer-derived extents remain provisional: the inventory is sufficient to give objdiff
symbol-bearing target code, but it is not accepted as proof that every start or end is correct or
as proof of translation-unit boundaries.

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
`gSongTable` through `0xBF8C4C`. Voicegroup references establish 437 distinct `WaveData` starts,
and the song table establishes 249 distinct validated song-header starts. `configure.py` derives
those target units from the verified ROM and rejects unexpected counts, pointer ranges, sample
sizes, or song headers. The preceding `0x3F4418-0xBF2118` raw graphics/asset tail, internal
voicegroup boundaries, and the tail following the final known song start still require finer
format-specific parsing.

The embedded payload is split further into its GBA header, three-symbol ARM bootstrap, six
consecutive validated LZ77 streams, and trailing zero padding. `tools/check_payload_map.py`
independently reparses the streams and verifies the padding. The semantic types of the decompressed
assets and the main data range's remaining internal objects are not yet established.

## Runtime boundary evidence

The pinned `agbcc` build produces runtime objects whose sizes and non-relocated instruction
sequences correlate consecutively with the retail ROM. The resulting boundaries are recorded in
`config/BSBE78/config.yml`. `memcmp`, `memcpy`, and `memset` also match their `libc` object bodies.

The M4A start is independently correlated by its mixed Thumb/ARM multiply helper and `SoundMain`
layout against the public implementation used by related GBA titles. The `m4a0` assembly-object
function order and offsets correlate through its final event handlers; this retail revision is
`0x1C` bytes larger than the Sonic Advance 2 reference. Its last return is at `0x48F70`, followed by
alignment and the first separately compiled C function at `0x48F74`. The latter object runs
contiguously to the first BIOS-call veneer at `0x4A590`, establishing both M4A TU boundaries.

The BIOS-call veneer names and boundaries are established by their documented SWI numbers,
calling-convention shims, public SDK ABI, and object alignment. `SoftResetExram` ends at `0x4A5F8`.
The following function order and object-relative offsets correlate with the public Nintendo flash
library used by Sonic Advance 2. Compiled object sizes, including the previously missed function at
`0x4AAB0`, establish four consecutive TUs: `agb_flash` (`0x4A5F8-0x4AAF8`), the 512-Kbit setup/common
writer (`0x4AAF8-0x4AC14`), `agb_flash_le_512k` (`0x4AC14-0x4AEBC`), and
`agb_flash_mx_512k` (`0x4AEBC-0x4AF68`). Names here come from that public SDK correlation rather
than from retail symbols.

The openly licensed newlib-correlated `memcmp`, `memcpy`, and `memset` sources compile through the
pinned `old_agbcc -O2 -fno-builtin` library path and match their full target sections byte-for-byte.
`memcpy` and `memset` have respective 0x5E and 0x52 function sizes followed by two owned
zero-padding bytes; mapping symbols prevent that padding from inflating the function sizes.

## Original source language

Undetermined pending the complete TU inventory. Current negative evidence: the main executable
contains no detected C++ mangling, RTTI/typeinfo strings, vtable labels, exception runtime names,
`operator new`/`operator delete` identifiers, static-constructor markers, or C++ source suffixes.
This is consistent with C but is not, by itself, proof that every game TU was C.
