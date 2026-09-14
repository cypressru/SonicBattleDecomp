# List-editor translation unit

The inferred TU at `0x08033D10..0x08034F28` contains sixteen routines and
4,632 text bytes, including literals and alignment. Its interpreted metadata
occupies `0x08EDC828..0x08EDC980` (344 bytes) and
`0x0814CE1C..0x0814CE80` (100 bytes). All 5,076 ROM bytes match in an
independent unmasked link. Five private BSS spans total eight bytes.

Original language is unknown. C++ is the required reconstruction fallback,
not a claim about the original language. Address-based extern-C symbols,
member names and layout views are synthetic, not recovered declarations.
No other platform's executable or source metadata is used.

## Boundaries and behavior

Three leading helpers draw rows, pack twelve entries into outgoing halfwords,
and redraw changed incoming entries. Their direct callers are within this
menu family, not the preceding score screen. The initializer creates the
display and node layouts, allocates a temporary palette, and selects the
visible list window. Two controllers add, remove, select and scroll entries;
handshake callbacks select subsequent fade-and-exit paths.

The next initializer at `0x08034F28` starts a different setup: four calls to
the player-reset helper, clearing scene bytes 24 through 27, and selecting
language-dependent pointers at `0x03004DB4` and `0x03004DA4`. The next metadata
at `0x08EDC980` is consumed at `0x08035930` and `0x08035964`. These behavioral,
reference and layout boundaries are inferred, not recovered object boundaries.

## Metadata ownership

Eight 16-byte position records occupy `0x08EDC828..0x08EDC8A8`: three copied
by the initializer, two unreferenced records, and three callback templates.
The unreferenced records at `0x08EDC858` and `0x08EDC868` have the arrow
setup's coordinates and tile values. Their inclusion follows contiguous
record layout and family context, not a claim that they are reached.

The following arrays contain twelve graphics pointers, eleven Japanese-label
pointers, eleven other-label pointers, and twenty numbered-label pointers.
The full arrays end at the following family's metadata. All graphics, palette,
sprite-part and text pointees remain external; only symbolic pointers and
interpreted layout values are defined here. The twelfth graphics pointer and
all twenty numbered-label pointers are preserved without claiming that every
entry is reachable from ordinary input.

Whole-ROM all-alignment scans found eleven live references into this metadata
inside the family. Six more are genuine shared-label consumers: `0x0803AF5C`
references `0x08EDC8D8`; `0x0803AF98`, `0x0803AFD4`, `0x0803B010`,
`0x0803B04C` and `0x0803B138` reference `0x08EDC904`. Shared consumers do
not turn those references into private state or imply a second definition.

Two other numeric occurrences were checked independently:

- `0x08350D24` is inside raw background graphics at
  `0x08350834..0x08352574`. The consumer at `0x0803ED7C` programs DMA3 to
  copy 0xEA0 halfwords to background VRAM; the end equals the next DMA source.
- `0x08D27CAC` lies inside validated M4A sample 142,
  `0x08D26A58..0x08D29CD5`.

The second owned ROM span contains sixteen display-register offset/value
pairs, six 32-bit row offsets and twelve identity palette indices. Their
references are at `0x080341F4`, `0x08033DB0`, `0x08033E14`, `0x08033E20`
and `0x08033E54`. Following unreferenced patterns at `0x0814CE80` are not
claimed; adjacency alone does not establish ownership. Raw palette values
starting at `0x0814D044` also remain external assets.

## RAM ownership and layout limits

Private minimum spans are one byte each at `0x03005318`, `0x0300531C`,
`0x03005320`, and `0x03005328`, plus the four-byte palette pointer at
`0x03005324`. Independent ELF checks require NOBITS type, exact address and
exact size for every span. Intervening RAM alignment gaps are not owned.
All 35 live literal references into this interval are within the family.

Three other numeric occurrences are within compressed streams. Complete
decompression checked every back-reference and the exact output length:

- `0x08158FAE`: asset 214, `0x08158E1C..0x08159311`, 3,072 output bytes.
- `0x08190BCB`: asset 375, `0x0818E164..0x0819134D`, 25,536 output bytes.
- `0x08F0845D`: embedded stream 1, `0x08EEF9C0..0x08F16058`, 184,760 bytes.

Save data, the input state, node pool, send/receive buffers and main callback
remain shared externals. The save view exposes thirteen entry bytes because
the delete loop can read index twelve while shifting through the configured
limit. This is a minimum observed view, not a recovered storage capacity.
The twelve transmitted entries do not prove a twelve-byte storage bound.
The existing loop bounds and accesses are preserved rather than corrected.

## Compiler and verification

Flags are `-O2 -mthumb-interwork -fno-exceptions -fno-rtti` with the pinned
EGCS frontend and agbcc backend. Full-owned-section cleanup removed two of
eleven register bindings and five of nine empty constraints. Nine bindings
and four empty constraints remain to preserve allocation and value lifetime.
There are no assembly instructions, byte patches, masks, opaque instruction
arrays or compiler changes. No global-minimality claim is made.

The independent byte gate covers all three ROM sections and all five BSS
spans. Objdiff's borrowed relocation metadata is not a substitute for that
gate. The bootstrap ROM is copied from the verified reference; its SHA-1
does not establish a ROM fully linked from reconstructed source. No runtime
or physical-hardware validation is claimed.

Local verification passed the clean BSBE78 build (the only supported target,
2,037 steps), all 26 documented byte gates, 61 automated tests, 28 Python
syntax checks, 41 source/header format checks, proprietary-file checks,
payload/debug checks and the function-map check (1,232 extents and 24 long
branches). All sixteen routines and every reported section are 100% in
objdiff. Exact functions increase from 924 to 936 with no losses against the
PR76 CI report. Coverage remains 268,608 code plus 16,508,608 data bytes,
exactly 16 MiB; the split adds two units, for 1,945 units and 1,298 functions.

Objdiff aggregates BSS into a padded 20-byte report section; the independent
gate verifies the five actual owned spans totaling eight bytes. Padding in
the report is not a claim to own the intervening RAM. The bootstrap SHA-1
passes as `8cf4fbbe73f6b1907ab9997caab4c4e7d9708937`.
