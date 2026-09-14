# Complete game TUs using the C++ fallback

The original language of the two game TUs below remains undetermined. Their earlier C matches
established reconstructed behavior and compiler output, not C source-language evidence. They now
use the requested C++ fallback. `extern "C"` preserves the project's existing synthetic linker
labels; it is not a recovered retail linkage declaration. No functions, guessed names, field
layouts, or behavior changed, and no assembly or fixed-register constraints were added.

| TU | Existing boundary evidence | Owned sections | Result |
|---|---|---|---|
| `main/unknown_08018444` | Ten contiguous frame/link service helpers between the display TU's terminal pool and the independently correlated Nintendo MultiSioSync object | `.text` `0x234` | 10/10 functions; every section byte at 100% |
| `main/unknown_0801F080` | Sixteen-function condition interpreter with fourteen table entries and two consumers; its private callback table and unrelated neighbors establish ownership | `.text` `0x56C`, `.rodata` `0x38` | 16/16 functions; every section byte at 100% |

The first unit contains 446 instruction bytes and 118 literal/alignment bytes. The second contains
1,328 instruction bytes, 60 literal/alignment bytes, and the 56-byte callback table at
`0x08ED8B04-0x08ED8B3C`. The existing maps, names, field types, and TU boundaries are preserved.
The frame unit's globals are externally shared; this change does not claim additional private RAM
ownership. These are full-TU language migrations, not newly matched functions or speculative splits.

## Compiler evidence and compatibility

The earlier GCC 2.95.2 C++ frontend plus pinned Thumb backend matches the compact random TU,
but gives five mismatching functions in the condition interpreter and a shorter frame initializer.
Compiling the interpreter as C through that same GCC 2.95.2 middle end produces the same five
mismatches. This control isolates the compiler-version difference from the choice of C or C++.

Using the pinned `gcc_arm` tree's complete compiler pipeline with the EGCS 1.1.2 C++ frontend
reproduces both full TUs, including switch-selector register copies and nested-loop output.
The compiler inputs are:

- GNU EGCS 1.1.2: <https://gcc.gnu.org/pub/gcc/releases/egcs-1.1.2/egcs-1.1.2.tar.gz>, SHA-256
  `44fd01124aaec140b8115a0a23bf1f14e2e516a6e13dfd139017f962c22c12a2`.
- The complete `gcc_arm` tree and its support files from public `pret/agbcc` revision
  `da598c1d918402c42c0c0d7128ba14567f3175e9`.

The archive also agrees with the GNU release server's published SHA-512. The setup retains all
downloaded sources and their original license notices in ignored `tools/gcc_cpp/` directories.

The compatibility patch includes the C++ option table, adds the frontend's missing host-header
search path, omits registration of two obsolete builtins absent from the pinned backend, and
supplies the C++ string-constness flag expected by the shared string combiner. It also follows
agbcc's explicit zero alignment convention for modern GNU as. No instruction-selection,
optimization, or register-allocation routines are changed. The compiler runs on a 32-bit host ABI,
so Linux x86-64 hosts need a multilib C development environment.

Both TUs use `-O2 -mthumb-interwork -fno-exceptions -fno-rtti`. The C++ wrapper additionally uses
`-quiet -Werror`: EGCS otherwise accepts an invalid implicit `void *` conversion with a warning.
Integration tests verify C++ preprocessing, overloads, templates, rejection of that conversion,
and rejection of routing a C++ source through the old C compiler. The complete random-helper TU
continues to match with this compiler as a regression control.

## Independent verification

`tools/check_unit_bytes.py` links the actual source-built object at every configured ROM section
address and compares the complete sections directly against the verified ROM. External function
addresses come from the reviewed function/unit maps; generic address aliases must designate an
accepted entry. Generic data labels supply their encoded addresses. These bindings are tested by
the final unmasked byte comparison rather than assumed sufficient for a match.

The checker emits a temporary object containing only typed absolute symbol definitions, with no
instructions or data. This retains ARM/Thumb function metadata: raw linker `--defsym` values can
cause spurious interworking veneers. It does not patch the compiled object or replace calls.

```sh
python tools/check_unit_bytes.py main/unknown_08018444  # 564/564 ROM bytes
python tools/check_unit_bytes.py main/unknown_0801F080  # 1444/1444 ROM bytes, both sections
python tools/check_unit_bytes.py main/unknown_08020134  # 100/100 ROM bytes, regression control
```

Objdiff and the independent linker comparison cover every owned section and relocation. The
repository's full BSBE78 build and SHA-1 gate are also required, but the bootstrap ROM builder
still copies the base ROM; its SHA-1 alone does not establish source reconstruction. No emulator
or physical-hardware validation is claimed.
