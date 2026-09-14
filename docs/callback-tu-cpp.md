# Complete callback TU: C++ and unmasked byte audit

`main/unknown_080470E4` retains its established full boundary: 36 functions from
`0x080470E4` through the final game-code boundary at `0x0804833C`, plus the two
private callback arrays at `0x08EDDA68-0x08EDDA88`. Their eight entries refer only
to this unit, both arrays are consumed here, and the following table has another
owner. No additional split or original filename is inferred.

Original source language remains undetermined. The source now uses the C++ fallback
and compiler documented in `cpp-tus.md`, with `-O2 -mthumb-interwork
-fno-exceptions -fno-rtti` and diagnostic-only `-quiet -Werror`. The `extern "C"`
block preserves synthetic address labels, not recovered original linkage. Field
layouts and address-based names remain reconstruction descriptions.

The strict C++ compile requires a declaration for `FUN_0801f744`; its existing
definition takes two `u16` arguments and returns `void`. Two negative constants
assigned to `u16` fields now explicitly request the same modulo conversion, without
changing layouts or generated instructions.

## Corrections established by unmasked linking

An initial 100% objdiff section result was not sufficient. Linking the actual
source object at its ROM addresses exposed previously accepted reconstruction
errors. These corrections follow the ROM, not a compiler-output patch:

- Thumb calls at TU offsets `0x114`, `0x12A`, `0x70E`, and `0x722` target
  `0x0804A5A4`, the independently identified SDK `Mod` veneer, not `Div` at
  `0x0804A59C`. Source calls and target relocation labels are corrected together.
  Every other external Thumb call in the object was audited against its decoded
  retail destination.
- DMA3 literals contain `0x040000D4`, not the earlier synthetic RAM label
  `gUnknown_030000d4`. The replacement `gUnknown_040000d4` preserves the existing
  volatile register-structure access while binding it to the correct address.
- The literal at TU offset `0xE90` is `0x06009B80`, not `0x06019B80`.

No assembly, register constraints, replacement instruction bytes, or relocation
masking are used. `tools/check_unit_bytes.py main/unknown_080470E4` now compares
all `0x1258` text bytes and `0x20` table bytes: **4728/4728 identical**. CI runs this
check permanently alongside the three preceding C++ TUs. This supersedes the
older broad claim that the C version's objdiff score established all relocations.

The full BSBE78 build (the only supported target), automated tests, report checks,
and ROM SHA-1 are required for submission. The bootstrap ROM builder copies its
verified input; that SHA-1 does not independently prove source matching. No runtime
or physical-hardware validation is claimed.
