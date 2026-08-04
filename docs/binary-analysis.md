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
| `0x0000C0-0x000210` | `0x080000C0-0x08000210` | ARM startup and interrupt code | Exact |
| `0x000210-0x04833C` | `0x08000210-0x0804833C` | Game/engine Thumb code; internal TUs unresolved | Exact outer range |
| `0x04833C-...` | `0x0804833C-...` | Nintendo M4A sound engine | Exact start; end unresolved |
| `0x04A590-0x04A5F8` | `0x0804A590-0x0804A5F8` | Nintendo BIOS-call veneer archive objects | Exact |
| `0x04A5F8-0x04AF68` | `0x0804A5F8-0x0804AF68` | Nintendo cartridge-backup library | Exact outer range; internal TUs unresolved |
| `0x04AF68-0x04B61C` | `0x0804AF68-0x0804B61C` | `libgcc` objects listed in project config | Exact |
| `0x04B61C-0x04B718` | `0x0804B61C-0x0804B718` | `libc`: `memcmp`, `memcpy`, `memset` | Exact |
| `0x04B718-0xEEB690` | | Main ROM data/assets and auxiliary payload data | Exact outer range |
| `0xEEB690-...` | | Embedded `AGB TEST PRG` GBA program | Exact start |

Static analysis currently records 1,298 non-thunk function starts before the confirmed SDK
veneers. The inventory combines whole-ROM Thumb function pointers, decoded direct calls, and
recursive disassembly; it is stored in `config/BSBE78/functions.csv` with generic names and
per-symbol provenance. Of these starts, 814 have aligned ROM pointers, 450 are direct-call targets,
and 47 currently rely on recursive-disassembly recovery alone (categories overlap). The inventory
is sufficient to give objdiff symbol-bearing target code, but it is not accepted as proof that
every start is a true function or as proof of translation-unit boundaries.

All ROM bytes are represented in the generated objdiff project. Bytes after the main executable
are conservatively split at the independently validated embedded-program header: main ROM
data/assets occupy `0x4B718-0xEEB690`, and the embedded payload occupies
`0xEEB690-0x1000000`. Within the main data range, 440 aligned LZ77 streams are validated by their
headers, complete back-reference semantics, and at least one aligned ROM pointer to each stream.
Their starts and intervening unknown-data ranges are recorded in `config/BSBE78/data_symbols.csv`.

The embedded payload is split further into its GBA header, three-symbol ARM bootstrap, six
consecutive validated LZ77 streams, and trailing zero padding. `tools/check_payload_map.py`
independently reparses the streams and verifies the padding. The semantic types of the decompressed
assets and the main data range's remaining internal objects are not yet established.

## Runtime boundary evidence

The pinned `agbcc` build produces runtime objects whose sizes and non-relocated instruction
sequences correlate consecutively with the retail ROM. The resulting boundaries are recorded in
`config/BSBE78/config.yml`. `memcmp`, `memcpy`, and `memset` also match their `libc` object bodies.

The M4A start is independently correlated by its mixed Thumb/ARM multiply helper and `SoundMain`
layout against the public M4A implementation used by related GBA titles. Differences later in the
engine mean its end is not yet recorded as a TU boundary.

The BIOS-call veneer names and boundaries are established by their documented SWI numbers,
calling-convention shims, public SDK ABI, and object alignment. `SoftResetExram` ends at `0x4A5F8`;
the following function sequence independently matches the public Nintendo flash-library source,
establishing the start of the cartridge-backup library without yet proving all of its internal
object boundaries.

`src/libc/memcmp.c` is the first reconstructed-source candidate and is compiled into a real base
object by `tools/compile_agbcc.py`. It does not yet match the retail function and is not documented
as complete; its purpose is to verify the base-object build and diff path before matching work.

## Original source language

Undetermined pending the complete TU inventory. Current negative evidence: the main executable
contains no detected C++ mangling, RTTI/typeinfo strings, vtable labels, exception runtime names,
`operator new`/`operator delete` identifiers, static-constructor markers, or C++ source suffixes.
This is consistent with C but is not, by itself, proof that every game TU was C.
