#!/usr/bin/env bash
set -euo pipefail

readonly AGBCC_REVISION=da598c1d918402c42c0c0d7128ba14567f3175e9
readonly AGBCC_DIR=tools/agbcc

if [[ ! -d "$AGBCC_DIR/.git" ]]; then
    git clone https://github.com/pret/agbcc.git "$AGBCC_DIR"
fi

git -C "$AGBCC_DIR" fetch --depth 1 origin "$AGBCC_REVISION"
git -C "$AGBCC_DIR" checkout --detach "$AGBCC_REVISION"
(cd "$AGBCC_DIR" && ./build.sh)
