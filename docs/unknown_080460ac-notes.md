# `unknown_080460AC` matching notes

`FUN_08046bc4` is the only non-matching function in this translation unit. The other 12
functions and the unit's `.rodata` match. The function occupies `0x33c` bytes in the ROM.

## Observed target behavior

- The byte at `state->field27` is loaded before the initial mode checks, retained for the
  mode-2 increment, and reloaded before the final switch.
- Mode 0 performs a direct load/add/store of `field27`; the compiler currently tail-merges
  that store.
- The script interpreter keeps `&state->field36` in `r8`, the `0xce << 2` sentinel in `r10`,
  and the sound table in `r9`.
- The interpreter's loop exit compares a literal `1`, rather than a long-lived `done`
  register. This suggests the remaining mismatch is primarily control-flow and lifetime
  shape, rather than a scalar type mismatch.

## Rejected source shapes

- Saving `field27` for mode 2 improves the local instruction comparison, but makes the
  translation unit's `.text` four bytes smaller than its required `0x1038` size.
- Hoisting the empty-command sentinel improves its register assignment but loses the
  persistent sound-table register and grows `.text` by four bytes.
- Rewriting the interpreter as `while (done == 0)`, moving `done = 1` into exit cases, or
  expressing exits with `continue` all produce worse control flow.
- Changing the mode and loop-control scalar widths, reordering declarations, and making
  the mode-0 assignment volatile do not improve the emitted code.

Resume by reconstructing the interpreter exit structure while preserving the target's
three long-lived registers. Do not retain the saved-mode experiment unless another genuine
source correction restores the missing four bytes and the full unit still builds.
