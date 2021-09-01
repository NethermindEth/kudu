#!/usr/bin/env sh

mkdir -p cmake-build-debug
pushd cmake-build-debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --target check -- -j 4
chmod +x ./check
./check ../ERC20.sol
popd
