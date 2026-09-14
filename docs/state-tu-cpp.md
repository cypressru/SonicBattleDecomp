# Complete state TU: C++ and unmasked byte audit

The existing `main/unknown_080460AC` boundary is retained: thirteen functions at
`0x080460AC-0x080470E4`, plus `0x44` bytes at `0x08EDDA24-0x08EDDA68`.
The latter contains two four-entry callback arrays, fifteen halfword sound IDs,
a four-byte lookup, and two terminal zero bytes. The callbacks and table consumers
are represented in this TU; the next callback arrays belong to `unknown_080470E4`.
This preserves the accepted inferred grouping, not a claim of recovered object
metadata or an original filename.

The original language is unknown, so the complete source uses C++ fallback with
the compiler described in `cpp-tus.md`: `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`, plus diagnostic-only `-quiet -Werror`. `extern "C"` maintains synthetic
address labels, not original retail linkage. Existing field layouts are retained.
The negative constant assigned to a `u16` explicitly requests modulo conversion.

## Data ownership

C++ eliminates the old unreferenced scalar representing the last two zero bytes.
Making it externally visible emits it before the private arrays and is rejected.
The four-byte lookup and its two trailing zero bytes are therefore represented
as one packed, constant storage wrapper. Packing avoids this compiler's default
word-rounded structure size. This wrapper describes the measured owned storage;
it is not evidence of an original struct, and adds no instructions or relocations.
Its sole indexed consumer still addresses exactly the four lookup bytes.

## Corrected bindings

Unmasked linking found three previously accepted incorrect external bindings:

- `.text` offsets `0xEC` and `0x101C` contain DMA3's address `0x040000D4`, not
  `0x030000D4`. The synthetic name is corrected to `gUnknown_040000d4`.
- Offset `0xA3C` contains `0x030048E0`, not `0x03005440`. The consumer in
  `FUN_08046aa4` loads a halfword at offset four, represented by the already
  recovered input structure's `third` field. All other external call destinations
  and address-labeled literal bindings were audited against the ROM.

The full source object links at its configured addresses and compares **4220/4220
ROM bytes**, including all relocations: `.text` `0x1038`, `.rodata` `0x44`.
No assembly, fixed-register constraints, binary patching, or relocation masking
is used. CI permanently runs `tools/check_unit_bytes.py main/unknown_080460AC`.

Submission also requires a clean build of BSBE78 (the sole supported target), all
automated tests, the normalized report checks, and the bootstrap ROM SHA-1 gate.
The ROM builder copies the verified base ROM; its SHA-1 alone does not establish
source matching. No runtime or physical-hardware validation is claimed.
