# Complete core and entrypoint TUs

The accepted boundaries remain `engine/core` at `0x08000210-0x08000778` and
`main/main` at `0x08000778-0x080007FC`. The startup vector fixes the `AgbMain`
entrypoint; the preceding and following pools end at those boundaries. The
related-title linker ordering documented in `binary-analysis.md` supports the
grouping, but does not recover Sonic Battle's original filenames or source language.
Both full units therefore use the requested C++ fallback. Their `extern "C"`
blocks preserve reconstruction labels and the startup ABI, not original game linkage.

Compiler inputs are documented in `cpp-tus.md`. Core retains `-O2
-mthumb-interwork`; main retains `-O2`. Both add `-fno-exceptions -fno-rtti` and
the wrapper's diagnostic-only `-quiet -Werror`.

## Core corrections from the unmasked audit

Five external calls in the three final existing core functions had labels displaced
by exactly `0x210`. Decoding the retail Thumb calls establishes these destinations:

| TU offset | Previous label | Correct destination |
|---|---|---|
| `0x4CA` | `FUN_0804a3c0` | `VBlankIntrWait`, `0x0804A5D0` |
| `0x4D4` | `FUN_0801835c` | `FUN_0801856c` |
| `0x4E8` | `FUN_080202f0` | `FUN_08020500` |
| `0x522` | `FUN_0802046c` | `FUN_0802067c` |
| `0x546` | `FUN_0804a384` | `CpuFastSet`, `0x0804A594` |

Source and target relocation labels are corrected together. Palette helper
declarations agree with their existing definitions: halfword pointers/counts,
`u8` result for `FUN_08020500`, and `u32` for `FUN_0802067c`. Explicit `u8`
result casts preserve the observed caller-side truncation for the latter.

The literal at TU offset `0x4B0` is `0x030048E0`, not `0x04000128`. The loop
therefore reads the first halfword of the already declared volatile link-state
array. The descriptive `gMainCallback` binding is renamed to the project's
address-based `gUnknown_03002030`; all five retail pointer literals agree with
that address, which `AgbMain` also accesses directly.

## Recovered terminal leaf

The previous core source emitted `0x564` bytes against a `0x568`-byte target.
Its final three-word pool ends at `0x08000774`. The next halfword is `bx lr`,
followed by two zero-alignment bytes and the independently fixed `AgbMain` entry.
It is not part of the preceding pool or reachable fall-through from the preceding
function's return. An empty `void FUN_08000774(void) {}` emits these exact four
bytes with the pinned compiler. This is an inferred unreferenced leaf, not a
recovered name; its accepted two-byte executable extent is recorded separately
from its two padding bytes. Core now contains seven reconstructed functions.
The reviewed inventory gains one function and two code bytes, with two fewer
unclassified data bytes; total ROM coverage and the 1917-unit count are unchanged.

The earlier 100% objdiff section score did not establish full size or relocation
correctness. Independent linking now compares all **1384/1384 core bytes** and
**132/132 main bytes**, without masking or instruction patches. These checks run
in CI. Both entire TUs, not isolated functions, are submitted.

The clean BSBE78 build (the sole supported target), automated tests, map/report
checks and ROM SHA-1 gate remain required. The bootstrap ROM builder copies its
verified input; SHA-1 alone is not source reconstruction proof. No runtime or
physical-hardware validation is claimed.
