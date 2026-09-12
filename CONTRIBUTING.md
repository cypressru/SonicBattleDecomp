# Contributing

Every source change must document its evidence and pass byte-level objdiff verification. A full
ROM SHA-1 match is required before a change may claim project-level matching.

For new game TUs, use C where independent source-language evidence supports it and C++ otherwise.
Record C++ as the reconstruction fallback when the original language is unknown. Address-based
`extern "C"` labels provide linkage to the reconstruction; they do not establish retail symbol
names or original linkage. Submit complete, evidence-bounded TUs, including their owned literals,
alignment, and data, rather than isolated functions from unresolved coverage buckets.

Run:

```sh
python tools/check_no_proprietary.py
clang-format -i <changed C, C++, and header files>
python configure.py
ninja
sha1sum -c config/BSBE78/build.sha1
python tools/check_unit_bytes.py main/unknown_08020134
python tools/check_unit_bytes.py main/unknown_08018444
python tools/check_unit_bytes.py main/unknown_0801F080
python tools/check_unit_bytes.py main/unknown_080470E4
python tools/check_unit_bytes.py main/unknown_080460AC
python tools/check_unit_bytes.py engine/core
python tools/check_unit_bytes.py main/main
python tools/check_unit_bytes.py main/unknown_0801F5EC
python tools/check_unit_bytes.py main/unknown_08017C5C
python tools/check_unit_bytes.py main/unknown_08021050
python tools/check_unit_bytes.py main/unknown_08020198
python tools/check_unit_bytes.py main/unknown_08020244
python tools/check_unit_bytes.py main/unknown_08020500
python tools/check_unit_bytes.py main/unknown_08020978
python tools/check_unit_bytes.py main/unknown_08021268
```

PRs must use the repository template. Record source-language/linkage evidence, provenance of
names and types, compiler flags tested, objdiff section results, and the final SHA-1 status.
