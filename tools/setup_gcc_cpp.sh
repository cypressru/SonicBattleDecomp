#!/usr/bin/env bash
# Historical C++ frontend with the pinned compiler's complete code generator.
set -euo pipefail

cd "$(dirname "$0")/.."
readonly GCC_CPP_DIR=tools/gcc_cpp
readonly GCC_CPP_ARCHIVE_SHA256=44fd01124aaec140b8115a0a23bf1f14e2e516a6e13dfd139017f962c22c12a2
readonly AGBCC_REVISION=da598c1d918402c42c0c0d7128ba14567f3175e9

if [[ "$(git -C tools/agbcc rev-parse HEAD)" != "$AGBCC_REVISION" ]]; then
    echo 'Run tools/setup_agbcc.sh to install the pinned backend first.' >&2
    exit 1
fi

mkdir -p "$GCC_CPP_DIR"
if [[ ! -f "$GCC_CPP_DIR/egcs-1.1.2.tar.gz" ]]; then
    curl -L --fail --show-error https://gcc.gnu.org/pub/gcc/releases/egcs-1.1.2/egcs-1.1.2.tar.gz \
        -o "$GCC_CPP_DIR/egcs-1.1.2.tar.gz"
fi
printf '%s  %s\n' "$GCC_CPP_ARCHIVE_SHA256" "$GCC_CPP_DIR/egcs-1.1.2.tar.gz" | sha256sum -c -

# A fresh build directory prevents stale objects after backend/compatibility changes.
GCC_CPP_BUILD=$(mktemp -d "$GCC_CPP_DIR/build.XXXXXX")
tar -xzf "$GCC_CPP_DIR/egcs-1.1.2.tar.gz" -C "$GCC_CPP_BUILD"
mkdir "$GCC_CPP_BUILD/source"
git -C tools/agbcc archive "$AGBCC_REVISION" gcc_arm libiberty include config.if config.sub \
    | tar -x -C "$GCC_CPP_BUILD/source"
cp -a "$GCC_CPP_BUILD/egcs-1.1.2/gcc/cp" "$GCC_CPP_BUILD/source/gcc_arm/cp"
cp "$GCC_CPP_BUILD/egcs-1.1.2/install-sh" "$GCC_CPP_BUILD/source/install-sh"
cp "$GCC_CPP_BUILD/egcs-1.1.2/config.guess" "$GCC_CPP_BUILD/source/config.guess"
patch -d "$GCC_CPP_BUILD/source" -p1 < tools/gcc_cpp_compat.patch
mkdir "$GCC_CPP_BUILD/build"
(
    cd "$GCC_CPP_BUILD/build"
    # The historical frontend assumes a 32-bit host. No target libraries are needed.
    CC='gcc -m32 -std=gnu89 -fcommon -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types' \
        ../source/gcc_arm/configure --host=i686-pc-linux-gnu --build=i686-pc-linux-gnu \
        --target=thumb-elf --enable-languages=c,c++ --disable-nls --without-headers
    make -j"${GCC_CPP_JOBS:-4}" cc1plus \
        CFLAGS='-g -std=gnu89 -fcommon -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types'
)
cp "$GCC_CPP_BUILD/build/cc1plus" "$GCC_CPP_DIR/cc1plus"
echo "C++ compiler installed; source and build retained in $GCC_CPP_BUILD"
