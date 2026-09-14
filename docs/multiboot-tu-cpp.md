# Multiboot wrapper translation unit

The inferred complete TU owns seven functions at `0x08021268..0x080215A8`,
144 bytes of pointer tables at `0x08ED8B88..0x08ED8C18`, and 88 bytes of
discontiguous zero-initialized RAM. Its complete compiled ROM sections match
all 976 retail bytes, including calls, pools and alignment. Five functions
previously matched as C fragments; the initializer and master-start wrapper
are newly matching. No independent evidence establishes the original language.
C++ is the repository's reconstruction fallback, not a language deduction from
matching bytes. Address-based `extern "C"` names are synthetic linkage.

## Boundaries and behavior

The preceding allocator TU ends at `0x08021268`. This family initializes the
multiboot payload and SDK state, counts participating clients, starts the
master, resets into external RAM, polls completion, copies a selected payload,
and decompresses it. The final helper's complete pool ends at `0x080215A8`.
The following function initializes persistent game/settings state at
`0x03002110`, rather than multiboot state. Function order, coherent behavior,
shared accesses and complete matching sections support this inferred boundary;
no original object-file boundary metadata survives here.

The first table contains six language-dependent pairs, referenced from
`0x080212F8`. The second contains four rows of six pointers, referenced from
`0x0802134C`, `0x08021398`, `0x080213D8` and `0x08021414`. Whole-ROM scans at
every byte position find no other exact base/interior references to these
tables. The next table at `0x08ED8C18` has consumers at `0x08021BAC` and
`0x08034FA8`, outside this family, and is not owned here. The 36 initializers
are minimal symbolic pointer facts, not copied assets. Every pointed-to asset
remains external. Numeric scans cannot exclude computed or indirect accesses.

The SDK `MultiBootParam` layout and function declarations come from the
repository's reviewed `multi_boot.c` implementation, including its 76-byte
state, client flags and master pointer. SDK provenance does not establish the
language of these game wrappers. Other types are inferred from GBA access
widths and dataflow. No cross-platform binary metadata or other game's source
was used for this TU.

## RAM ownership

| Address | Bytes | Evidence and treatment |
| --- | ---: | --- |
| `03004D40` | 76 | SDK state, referenced by initialization, count, start and poll; owned |
| `03004D8C` | 4 | Payload size, also written by serial-transfer code outside this TU; external |
| `03004D90` | 4 | Initializer zero store; owned, purpose otherwise unclassified |
| `03004D94` | 4 | Selected payload pointer, read by both local transfer helpers; owned |
| `03004D98` | 4 | External serial progress counter; not owned |
| `03004D9C` | 4 | Master transfer length, initialized and consumed here; owned |

State-base literals occur at `0x0802147C`, `0x080214BC`, `0x080214D8` and
`0x08021548`. The size word also has references at `0x08032DFC`, `0x08032FE0`
and `0x0803302C`. The neighboring progress word has references at
`0x08032CB8`, `0x08032DF8` and `0x08032E90`; it is passed to the reviewed
`Sio32MultiLoadMain` routine, which writes one progress word. These consumers
preclude treating the whole contiguous RAM span as private multiboot storage.
The four bytes preceding `03004D40` are not claimed either.

Three reconstruction-only `.bss.boot_*` sections place the small owned words
without claiming either shared word. Explicit zero initializers make this
compiler honor the named sections; the assembler emits NOBITS, not ROM data.
These are layout annotations, not recovered original section names or proof of
original private linkage. The checker validates each separate address, size
and NOBITS type, rejecting overlapping spans or non-RAM addresses. Objdiff
coalesces the input sections into a 92-byte `.bss` presentation with alignment;
that presentation is not a 92-byte contiguous ownership claim. The linked
sections independently establish exactly 76 + 4 + 4 + 4 owned bytes.

## Emission and verification

The pinned EGCS C++ pipeline uses `-O2 -mthumb-interwork -fno-exceptions
-fno-rtti`. No backend, optimization flags, assembly, register constraints,
instruction patches or relocation masks were added. Symbol-size overrides
correct ELF metadata only. The seven function sizes follow the reviewed
function extents; their complete `.text` section includes every intervening pool.

The bootstrap-end expression `gUnknown_08eeb868` and existing payload-start
symbol `agb_test_lz77_0` deliberately remain distinct symbolic boundaries at
the same address. The verified payload map independently establishes the first
compressed stream's start there. Combining the expressions changes address
liveness across `CpuSet` and does not match. The master-start wrapper retains
an unused word argument for existing callers; its observed code does not read
that argument. Legacy caller declarations are retained where needed to avoid
changing unrelated C emission; they are not recovered original prototypes.

`python tools/check_unit_bytes.py main/unknown_08021268` independently links
the compiled object with reviewed, typed symbol definitions, compares both ROM
sections without masking, and validates all four RAM sections. Objdiff reports
all seven functions and complete sections at 100%. The global exact-function
set increases from 790 to 792 with none lost. Splitting the unresolved code
bucket and surrounding data bucket adds two report units; total ROM coverage,
code/data accounting and the 1,300-function inventory are unchanged.

Every supported target (BSBE78 only), automated tests, maps, formatting,
proprietary-content checks, independent TU checks and the ROM SHA-1 gate are
required before submission. The bootstrap builder copies the verified base
ROM, so its SHA-1 is not proof of a fully source-linked ROM. No runtime or
physical-hardware validation is claimed.
