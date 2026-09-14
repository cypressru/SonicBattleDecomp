# Input TU C++ fallback

The complete inferred input TU is `0x08020198-0x08020244`: keypad polling,
state reset and repeat-timing configuration, three functions and 172 ROM bytes.
Polling is newly reconstructed; reset and configuration move from the unresolved
C coverage bucket. Original language is unknown. C++ is the requested fallback;
address labels and `extern "C"` are synthetic reconstruction linkage, not retail
names or proof of original C linkage.

## Boundary and ownership evidence

The lower boundary is the accepted end of the random-helper TU's complete pool.
The three contiguous functions exclusively implement input maintenance: the
first reads KEYINPUT at `0x04000130`, the second resets the input record and calls
the third, and the third sets the initial delay and repeat interval. Their
complete pools end at `0x08020244`, where a six-case transfer-command dispatcher
starts using the separate queue at `0x03004900` and count at `0x030048F0`.
This supports an inferred source-unit boundary, not surviving object metadata.

The input record at `0x030048E0` is shared with existing frame, game and interrupt
code and remains external. This change does not infer the defining RAM object
from references alone. No private storage or remote ROM data is identified for
this TU; the compiled object has no nonempty `.data`, `.rodata` or `.bss`.
Every literal and alignment byte in its 172-byte `.text` belongs to the submitted
unit. The remaining `0x08020244-0x08021050` object is an unresolved coverage
bucket, not another asserted original TU.

`InputState08020198` and its descriptive fields are inferred views, not recovered
names. Halfword accesses establish held, inverted, pressed, released and repeat
fields at offsets 0, 2, 4, 6 and 8; byte accesses establish the timer, initial
delay and interval at 10, 11 and 12. The mask `0xFC00` and complement recover the
active-high keypad state. The ROM compares the new held value numerically with
the old value using unsigned `>`, not `!=`; that behavior is preserved. Timer
decrement wraps as an eight-bit value. Reset does not initialize every field,
and the reconstruction does not add such initialization.

## Related public reconstruction and emission

The locally available public [SAT-R/sa2 Chao Garden input reconstruction](https://github.com/SAT-R/sa2/blob/393357f7c9d46b5c10b6c41a57b80fe3b58f3c8d/chao_garden/src/input.c)
suggested an early-return organization: no input, increased input, nonexpired
timer, then repeat. Battle's independently checked disassembly supports that
order and the same comparison/mask pattern. Battle additionally maintains a
released-key field, has a separate repeat-configuration function and does not
contain that reference's soft-reset sequence in this function. None of those
differences was imported from the related game. The public reconstruction is
algorithmic corroboration, not evidence of Battle's original language, symbols,
exact declaration layout or linker boundaries. No private cross-platform
executable, metadata or source was used.

The pinned EGCS C++ pipeline uses `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`, plus diagnostic-only `-quiet -Werror`. Nested-condition and shared
exit candidates emitted the correct total size but different registers and
branches. The early-return reconstruction matches the full TU without changing
compiler flags or backend behavior. A temporary raw-input local also changed
register allocation and was rejected. No assembly, fixed registers, instruction
patches or relocation masks are used. Function-size overrides adjust ELF
metadata only.

## Verification scope

`python tools/check_unit_bytes.py main/unknown_08020198` independently links the
actual compiled object at the retail address and compares 172/172 bytes,
including resolved input-state addresses and the internal call. Objdiff must
also report all three functions and the entire `.text` at 100%.

All supported targets (BSBE78 only), repository tests, formatting, proprietary
checks, map validation, normalized report validation and the ROM SHA-1 gate
are required before submission. The inventory adds one unit without adding
functions or ROM coverage. The bootstrap builder copies its verified input;
the SHA-1 gate is not source-built ROM proof. No runtime or physical-hardware
validation is claimed.
