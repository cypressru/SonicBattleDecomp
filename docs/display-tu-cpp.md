# Display/control TU C++ fallback

The existing complete `main/unknown_08017C5C` TU spans `0x08017C5C-0x08018444`:
33 display, background-control, transfer-queue, transform, camera and blend helpers.
This change migrates that entire TU to C++; it does not claim 33 new matches.
Original source language is unknown. Address-based names and `extern "C"` are
synthetic reconstruction linkage, not evidence of original names or C linkage.
No other platform's private metadata or source was used.

## Ownership and provenance

The lower boundary follows the normal return and aligned literal pool of
`FUN_08017b74`. The last function, `FUN_08018410`, constructs two DMA descriptors;
its return and complete pool end at the accepted following frame TU's boundary.
These contiguous operations and complete boundary pools support the existing
inferred grouping, not a claim of surviving retail object metadata.

All 1,734 instruction bytes and 290 literal/alignment bytes are included in the
2,024-byte `.text` section. The object emits no nonempty `.data`, `.rodata` or
`.bss`. Shared RAM arrays remain external: no ownership is inferred merely from
a reference. Existing record views preserve observed strides, load/store widths
and field offsets; descriptive helper/type names remain reconstruction choices.
The source comments retain their field-level evidence and uncertainties.

## Compiler and emission

The pinned EGCS C++ pipeline described in `cpp-tus.md` uses `-O2
-mthumb-interwork -fno-exceptions -fno-rtti`, plus diagnostic-only `-quiet -Werror`.
No compiler backend, optimization flags or register constraints were changed.
The direct C++ conversion matched 32 functions, but `FUN_08017fb0` interchanged
the queue-base load and index shift. An inline index-upload helper now computes
the queue address before delegating to the existing by-value entry-upload helper.
That source organization reproduces the original order and register allocation.
The helper is an emission reconstruction, not proof of an original helper name
or inline boundary. No assembly, instruction patches or relocation masks are used.

The complete C++ object independently links at the retail address and compares
2,024/2,024 bytes, including every resolved call and literal. CI also runs
`python tools/check_unit_bytes.py main/unknown_08017C5C`. Objdiff checks all 33
functions and both code/non-code classifications within `.text`.

All supported targets (BSBE78 only), automated tests, map/report checks and the
ROM SHA-1 gate are required before submission. The bootstrap ROM builder copies
its verified input; that SHA-1 alone is not source-built ROM proof. No runtime or
physical-hardware validation is claimed. Coverage denominators are unchanged.
