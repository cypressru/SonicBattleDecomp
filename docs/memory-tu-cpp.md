# Allocator TU C++ fallback

`main/unknown_08021050` owns the complete inferred allocator TU at
`0x08021050-0x08021268`: nine functions, 536 ROM bytes and 524 bytes of private
NOBITS storage. Four allocation/free implementations are newly reconstructed;
five existing reset/free helpers move out of the unresolved C coverage bucket.
Original source language is unknown, so C++ is the reconstruction fallback.
Address-based labels and `extern "C"` provide synthetic reconstruction linkage,
not evidence of original names, linkage or language. No other platform's private
source or metadata was used.

## Boundaries and storage

The lower boundary follows the tile-rectangle offset-copy helper's complete
return and literal pool. The upper boundary follows the bitset-free helper's
complete pool and precedes the multiplayer link-state family. The nine adjacent
functions form three allocator APIs with adjacent private state:

| Functions | Inferred operation | Private state |
| --- | --- | --- |
| `08021050`, `080210D8`, `080210F8` | Allocate/reset/free four-byte slots | 256 halfwords at `03004B30` |
| `0802110C`, `08021128`, `08021180` | Reset/allocate/free a linked heap | Head pointer at `03004D30` |
| `080211D8`, `080211F0`, `08021244` | Reset/allocate/free bitset slots | Mask at `03004D34`, limit at `03004D38` |

These subsystem transitions, complete pools and coherent state support an
inferred TU boundary, not a claim of surviving retail object metadata. Exact
base-address literal references to these four private objects occur only in
these nine functions. A broader scan for any word numerically inside the state
range also finds opaque ROM-data values; those are not established pointers and
do not prove semantic ownership or complete reference closure.

The static objects emit `.bss` size `0x20C`, alignment eight, at offsets zero,
`0x200`, `0x204` and `0x208`. Linking at `0x03004B30` reproduces each observed
address. The following four bytes before link state at `0x03004D40` are not
claimed. The heap backing buffer at `0x030033E0` remains external: earlier
display/transfer functions also reference it. Its eight-byte block-header view
does not claim ownership of that shared buffer.

Names and types are reconstruction choices supported by observed accesses:
four-byte next pointers, signed sizes, eight-byte headers, negative allocated
sizes and positive free sizes. Allocation rounds to eight bytes, splits when
at least 24 bytes remain beyond the request, and freeing coalesces neighboring
free list entries. The accepted interior-pointer exception into `08021088`
remains unchanged; it is a live basic block, not a new function boundary.

## Emission and verification

The pinned EGCS pipeline in `cpp-tus.md` uses `-O2 -mthumb-interwork
-fno-exceptions -fno-rtti`, plus diagnostic-only `-quiet -Werror`. The table
scanner's explicit control flow and the bitset scanner's pointer-based limit
expression recover the observed register allocation. These are emission
reconstructions, not proof of original source syntax. A volatile-state variant
was tested and rejected; the matching implementation needs no volatile state.
No compiler changes, assembly, fixed registers, instruction patches or masked
comparisons are used. Symbol-size overrides affect ELF metadata only.

The complete `.text` independently links and matches 536/536 unmasked ROM bytes,
including every call, literal and alignment byte. Both `.text` and `.bss` match
100% in objdiff, with all nine functions exact. The independent checker also
asserts the linked BSS section's NOBITS type, address and size. BSS has no ROM
bytes and is excluded from ROM coverage.

Two formerly omitted internal pool mappings (TU offsets `0xFA-0x100` and
`0x174-0x178`) are now explicit. Objdiff's function-extent accounting includes
internal pools: it reports 488 code and 48 non-code ROM bytes for this TU, not
an instruction-only count. The reviewed global denominators remain 266,470 code
and 16,510,746 data bytes, with 1,300 functions. Splitting the surrounding
unresolved bucket adds two units, giving 1,920, without adding ROM coverage.

Submission requires a clean build of every supported target (BSBE78 only), all
automated tests, formatting and proprietary-content checks, map validation, the
normalized report and independent whole-section comparisons. The bootstrap ROM
builder copies a verified base ROM; its SHA-1 gate is not source-built ROM proof.
No runtime or physical-hardware validation is claimed.
