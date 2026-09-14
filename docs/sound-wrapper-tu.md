# Sound-wrapper TU (`0x0801F5EC-0x0801F780`)

Fifteen contiguous game functions form a complete 404-byte sound-interface
reconstruction. All were previously matched as individual C fragments within the
larger unresolved bucket. They are now submitted as one standalone C++ TU, not as
fifteen new function matches. Original source language remains unknown; C++ is the
requested fallback and `extern "C"` preserves only synthetic reconstruction labels.

## Boundary evidence and limits

The lower boundary follows the completed condition interpreter's terminal return
and literal pool at `0x0801F5EC`. The next function initializes the SDK sound
driver and sets its mode. The following fourteen wrappers exclusively call SDK
sound services, either directly or after translating a song index through the
SDK player/song tables. The last wrapper starts at `0x0801F770`; its return and
alignment end at `0x0801F780`.

At that exact upper boundary, the next function initializes the unrelated
100-entry list allocator, its free-index bytes, and queue state. That subsystem
continues through the already separated random-helper TU boundary. Complete pools,
contiguous sound-only operations, external dependency coherence, and both
neighboring subsystem transitions support this inferred grouping. There is no
surviving retail object metadata proving an original object boundary or filename.
The unsolved list range remains a conservative bucket; it is not marked complete.

The only non-code dependencies in the fifteen functions are the six-entry SDK
player table at `0x08BF71FC` and the SDK song table at `0x08BF7244`. Their existing
ownership and layouts are independently documented in `binary-analysis.md`.
They are not reclassified as private game-TU data. The address-named table views
retain the observed 12-byte and 8-byte strides, pointer field, and halfword index
at offset four; the unused fields remain anonymous padding descriptions.

The standalone object emits `.text` of exactly `0x194` bytes and no nonempty
`.data`, `.bss`, or `.rodata`. Thus the submitted ownership includes all 332
instruction bytes and all 72 literal/alignment bytes, without a remote section
or shared data claim. The target is sliced independently from the ROM using the
existing reviewed mapping and relocation entries.

## Verification

The pinned C++ pipeline from `cpp-tus.md` uses `-O2 -mthumb-interwork
-fno-exceptions -fno-rtti`, plus diagnostic-only `-quiet -Werror`. The moved bodies
retain their existing behavior and types; no assembly or fixed-register constraints
are introduced. Objdiff matches all fifteen functions and every owned byte.
`tools/check_unit_bytes.py main/unknown_0801F5EC` independently links the complete
object and compares **404/404 bytes** without relocation masking; CI runs it.

The split adds one unit (1918 total) but changes no function, code-byte, data-byte,
or ROM-coverage denominators. All supported targets (BSBE78 only), tests, map/report
checks and the ROM SHA-1 gate are required for submission. The ROM bootstrap still
copies its verified input; its SHA-1 alone is not proof of source reconstruction.
No runtime or physical-hardware validation is claimed.
