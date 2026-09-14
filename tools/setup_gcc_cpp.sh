#!/usr/bin/env bash
# GCC's C++ frontend with the public Thumb ELF backend used by the pinned agbcc.
set -euo pipefail

cd "$(dirname "$0")/.."
readonly GCC_CPP_DIR=tools/gcc_cpp
readonly GCC_CPP_ARCHIVE_SHA256=064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482
readonly AGBCC_REVISION=da598c1d918402c42c0c0d7128ba14567f3175e9

if [[ "$(git -C tools/agbcc rev-parse HEAD)" != "$AGBCC_REVISION" ]]; then
    echo 'Run tools/setup_agbcc.sh to install the pinned backend first.' >&2
    exit 1
fi

mkdir -p "$GCC_CPP_DIR"
if [[ ! -f "$GCC_CPP_DIR/gcc-2.95.2.tar.gz" ]]; then
    curl -L --fail --show-error https://ftp.gnu.org/gnu/gcc/gcc-2.95.2.tar.gz \
        -o "$GCC_CPP_DIR/gcc-2.95.2.tar.gz"
fi
printf '%s  %s\n' "$GCC_CPP_ARCHIVE_SHA256" "$GCC_CPP_DIR/gcc-2.95.2.tar.gz" | sha256sum -c -

# A fresh build directory prevents stale objects after backend/compatibility changes.
GCC_CPP_BUILD=$(mktemp -d "$GCC_CPP_DIR/build.XXXXXX")
tar -xzf "$GCC_CPP_DIR/gcc-2.95.2.tar.gz" -C "$GCC_CPP_BUILD"
for backend_file in thumb.c thumb.h thumb.md telf.h; do
    git -C tools/agbcc show "$AGBCC_REVISION:gcc_arm/config/arm/$backend_file" \
        > "$GCC_CPP_BUILD/gcc-2.95.2/gcc/config/arm/$backend_file"
done
patch -d "$GCC_CPP_BUILD/gcc-2.95.2" -p1 < tools/gcc_cpp_compat.patch
mkdir "$GCC_CPP_BUILD/build"
(
    cd "$GCC_CPP_BUILD/build"
    # The historical frontend assumes a 32-bit host. No target libraries are needed.
    CC='gcc -m32 -std=gnu89 -fcommon -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types' \
        ../gcc-2.95.2/configure --host=i686-pc-linux-gnu --build=i686-pc-linux-gnu \
        --target=thumb-elf --enable-languages=c,c++ --disable-nls --without-headers
    make -C gcc -j"${GCC_CPP_JOBS:-4}" cc1plus
)
cp "$GCC_CPP_BUILD/build/gcc/cc1plus" "$GCC_CPP_DIR/cc1plus"
echo "C++ compiler installed; source and build retained in $GCC_CPP_BUILD"
