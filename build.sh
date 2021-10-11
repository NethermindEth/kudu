#!/usr/bin/env sh

mkdir -p build
cd build
# See https://github.com/Homebrew/homebrew-core/issues/67427#issuecomment-756511468
# for an explanation why we adjust LIBRARY_PATH for macos
case $(uname | tr '[:upper:]' '[:lower:]') in
    darwin*)
        export LIBRARY_PATH="${LIBRARY_PATH}:$(brew --prefix icu4c)/lib"
        ;;
esac
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j20
status=$?
cp kudu ../
exit $status
