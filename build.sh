#!/usr/bin/env sh

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j20
cp gen-yul-json-ast ../
