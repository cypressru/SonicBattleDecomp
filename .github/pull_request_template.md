## What

<!-- Describe the reconstructed behavior and exact scope. -->

<!-- State whether the complete translation unit was verified byte-for-byte in objdiff. -->

## Evidence

- [ ] I identified the source language and linkage from evidence, not from the current file extension or a byte match alone.
- [ ] I recorded whether names/types came from GameCube, PS2, PC, another GBA build, or a known library reference, and marked guesses as guesses.
- [ ] If I used metadata from another platform/build, I kept proprietary executables and tool output local and included only the minimum symbolic fact and independent GBA correlation.
- [ ] If I changed compiler or inline flags, I documented the source/emission order and compared each candidate in objdiff.
- [ ] I did not add game binaries, assets, extracted assembly, leaked source, tool output, or links to those materials.

### Evidence and references

<!-- Explain the independent evidence for names, types, boundaries, language, linkage, and flags. -->

## Verification

- [ ] `python tools/check_no_proprietary.py`
- [ ] `clang-format -i` on changed files under `src/` and `include/`
- [ ] objdiff result recorded below
- [ ] PR CI uploaded `BSBE78_report` for decomp.dev
- [ ] `ninja` passes
- [ ] `sha1sum -c config/BSBE78/build.sha1` passes

### Objdiff before/after

```text
Before: ?/? functions reconstructed by this TU
After: ?/? functions matching
.text: 0x?/0x?
Every owned section matches byte-for-byte: yes/no
```

<!-- State explicitly whether the full ROM SHA-1 matches. -->
