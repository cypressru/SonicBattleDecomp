# Contributing

Every source change must document its evidence and pass byte-level objdiff verification. A full
ROM SHA-1 match is required before a change may claim project-level matching.

Run:

```sh
python tools/check_no_proprietary.py
clang-format -i <changed C and header files>
python configure.py
ninja
sha1sum -c config/BSBE78/build.sha1
```

PRs must use the repository template. Record source-language/linkage evidence, provenance of
names and types, compiler flags tested, objdiff section results, and the final SHA-1 status.
