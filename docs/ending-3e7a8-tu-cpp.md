# Ending sequences at 0x0803E7A8

This inferred complete TU contains five functions in
`0x0803E7A8..0x0803F81C`: the initializer, two slideshow callbacks,
a localized-title hold callback, and the palette-fade exit. All 4,212
text, literal-pool, switch-table, and alignment bytes match after typed
relocation, without masks. It defines no separate data, rodata, or BSS.

## Language and provenance

The original source language is unknown. C++ is the required reconstruction
fallback, not a conclusion from matching bytes. Address-based `extern "C"`
labels provide synthetic reconstruction linkage; neither original names nor
original linkage are claimed. Types and local names describe observed GBA
access widths and behavior, not recovered original declarations. No other
platform's executable, source, or metadata was used.

The source uses the existing agbcc C++ configuration: `-O2
-mthumb-interwork -fno-exceptions -fno-rtti`. There are no fixed-register
bindings, empty assembly operands, or injected opcodes. Four temporary
constraints used while investigating scroll allocation were individually
removed with recompilation and byte comparison; the combined object also
matches without them.

## Boundary and ownership evidence

The initializer independently resets rendering, configures the display,
and chooses between the two slideshows using shared ending-selection state.
Both flows terminate through the final fade callback. An all-alignment ROM
survey found the only external stored function-entry pointer at
`0x08045578`, in the ending dispatcher `0x080454D0`, pointing to this
initializer. Other actual callback entries and both switch tables are
internal. A mapped Thumb BL survey found no calls into this interval.
These observations cannot exclude arbitrary computed references.

The preceding callback at `0x0803E74C` belongs to an independently entered
intro sequence and exits to `0x0801C930`. It is not called or installed by
the ending family. The following function at `0x0803F81C` is a match-result
predicate using match-state storage at `0x03001620`, with an external call
at `0x080402C8` in `0x080402B0`. It conditionally calls `0x0803F8DC`, which
uses the next metadata family at `0x08EDD808`. Neither function participates
in this ending callback graph. These are behavioral and layout inferences,
not recovered compiler-object boundaries.

Apparent interior-pointer values outside code were independently classified:
101 occurrences lie inside validated MP2K WaveData sample payloads; ten lie
inside the embedded test program's validated LZ77 streams; and one at
`0x08136999` lies inside the compressed stream `lz77_asset_116`, starting at
`0x08136304`. None of those locations is a stored pointer field. No surveyed
occurrence was left unclassified.

The halfword at `0x03005424` is also used by startup, and the byte at
`0x03005428` is also used by the external ending dispatcher. They remain
external, as do shared engine counters, rendering queues, input, save data,
and the current callback pointer. There is no inferred private allocation
or invented alignment storage. All referenced graphics, tilemaps, and
palettes remain external opaque assets; the source reproduces no asset bytes.

## Behavior preserved

The longer sequence has 17 stages and alternating background pages; the
character-ending sequence has five stages, seven character portrait choices,
and six localized title choices. DMA sizes, destinations, ordering, and
control-register readbacks are preserved. Stage-specific fades and music
transitions retain their original comparisons and byte truncation.

Both slideshows advance the position once every three callbacks. Scroll
calculations use one halfword position value for two signed offsets and
write matching background offsets before submitting the six sprite pieces.
The character-ending callback still executes the remaining update/render
path after selecting its successor. The title-hold callback retains its
separate early and late fade tests and its input-triggered jump to the late
phase. The exit clears the palette and returns to startup; it does not add
a display-disable operation.

The required independent byte gate is
`python tools/check_unit_bytes.py main/unknown_0803E7A8` and is included in
CI and the contributor build matrix. BSBE78 is the supported target.
Compilation and byte equality do not establish runtime or physical-hardware
validation. The bootstrap ROM SHA check is not proof of a fully source-linked ROM.

## Reviewed report inventory

Splitting the unresolved coverage bucket creates two additional units:
1,960 becomes 1,962, with the function inventory unchanged at 1,300.
The new complete function sizes include 160 bytes previously classified as
unresolved pool/table data, so code/data accounting changes from
269,988/16,507,228 to 270,148/16,507,068 bytes; total coverage remains 16 MiB.
These 160 bytes are a classification change, not additional recovered instructions.

All five functions match in the complete TU. Four become newly exact in the
project report; the final fade callback was already exact in the old bucket.
Global exact functions increase from 1,006 to 1,010, with no losses.
On this branch, matched code increases from 49.7748% to 51.2793%, and
complete code from 41.4937% to 43.0283%. These are branch results, not
claims about unmerged main-branch progress.
