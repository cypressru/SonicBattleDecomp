# Transfer-command TU C++ fallback

`main/unknown_08020244` is the complete inferred transfer-command TU at
`0x08020244-0x08020500`: one dispatcher, one reset and six enqueue functions.
It owns 700 ROM bytes and a reconstructed 528-byte private RAM span. The
dispatcher is newly reconstructed; the seven existing C helpers move into the
complete C++ TU. Original source language is unknown, so C++ is the requested
fallback. Address names and `extern "C"` are synthetic linkage, not recovered
retail names or proof of original C linkage.

## Boundaries and behavior

The lower boundary follows the complete input TU and its timing setter's pool.
The dispatcher processes the same six record types produced by the six enqueue
helpers. Each enqueue checks a 32-entry capacity; the reset and dispatcher clear
the shared count. The final enqueue owns its trailing pool through `0x08020500`,
where palette-color convergence begins and no longer uses this command queue.
These contiguous APIs, complete boundary pools and closed direct state-base
references support an inferred TU, not surviving original object metadata.

| Type | Observed dispatch operation |
| --- | --- |
| 0 | CpuFastSet from the second pointer to the first, with a masked length |
| 1 | Offset tile-rectangle copy using two packed halfword dimensions |
| 2 | LZ77 decompression into VRAM |
| 3 | Copy a 1,152-byte source block to a 32-byte-indexed object-VRAM slot |
| 4 | Copy a 1,152-byte source block to a 1,152-byte-indexed object-VRAM slot |
| 5 | Copy a variable span from a 32-byte-indexed source to a 512-byte-indexed slot |

The 16-byte record view preserves three words, a halfword parameter and a
halfword command tag at offsets 0, 4, 8, 12 and 14. Generic field names are
retained because their meanings vary by command. Loads and stores establish
the widths; field names and the aggregate declaration are reconstruction choices.
SDK names follow the already reviewed CpuFastSet and LZ77UnCompVram veneers.
No related game's source, private cross-platform metadata or original game
source was used for this reconstruction.

## Private storage and uncertainty

A halfword-aligned whole-ROM scan finds the count's exact base `0x030048F0`
only at `0x0802035C`, `0x08020368`, `0x0802039C`, `0x08020400`, `0x08020438`,
`0x08020474`, `0x080204B0` and `0x080204F8`. The record array's exact base
`0x03004900` appears only at `0x08020268`, `0x080203A0`, `0x08020404`,
`0x0802043C`, `0x08020478`, `0x080204B4` and `0x080204FC`. All are used by this
family. A scan for numeric addresses inside `0x030048F4-0x03004900` finds none;
these scans do not exclude indirect or computed references.

The inferred private span contains a four-byte count, twelve unclassified bytes,
and 32 records of sixteen bytes, ending at `0x03004B00`, the next palette-state
address. The count wrapper explicitly preserves the observed twelve-byte gap.
It does not claim a recovered sixteen-byte count declaration, original padding
rule or known meanings for those bytes. A plain count followed by the array
would place the array at offset eight with this compiler and fails the linked
literal comparison. An explicit sixteen-byte alignment control was rejected by
the pinned compiler and was not adopted; no compiler alignment limit was changed.
The accepted storage view emits `.bss` size `0x210`, alignment eight, with the
array at offset `0x10`. There is no initialized data or remote ROM data.

## Emission and verification

The pinned EGCS C++ pipeline uses `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`, plus diagnostic-only `-quiet -Werror`. Halfword extraction from the
packed dimension word reproduces the shared address calculation in case 1.
The explicit `(second << 16) >> 19` preserves case 5's observed word load and
shifts; a mask expression instead narrowed the load and failed. Both are
unsigned expressions. No assembly, fixed registers, backend changes, instruction
patches or relocation masks are used. Symbol-size overrides affect ELF metadata
only. Switch-table addresses are reviewed relative to this complete TU.

Objdiff reports all eight functions and both `.text` and `.bss` at 100%.
`python tools/check_unit_bytes.py main/unknown_08020244` independently links the
actual compiled object, resolves every call/table/literal, compares 700/700 ROM
bytes, and checks BSS NOBITS type, address `0x030048F0` and size `0x210`.
NOBITS storage is not counted as ROM coverage. Function-extent accounting reports
632 code and 68 non-code ROM bytes; internal literal islands remain inside the
function extents, so this is not an instruction-only count.

Every supported target (BSBE78 only), repository tests, formatting, proprietary
checks, map validation, normalized report validation and the ROM SHA-1 gate are
required before submission. Inventory increases by one unit, not by extra ROM
bytes or functions. The bootstrap builder copies a verified base ROM; its SHA-1
gate is not source-built ROM proof. No runtime or hardware validation is claimed.
