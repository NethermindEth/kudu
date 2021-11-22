#!/usr/bin/env sh

mkdir -p build
cd build || exit
# See https://github.com/Homebrew/homebrew-core/issues/67427#issuecomment-756511468
# for an explanation why we adjust LIBRARY_PATH for macos
case "$(uname -s)" in
    Darwin*)
        LIBRARY_PATH="${LIBRARY_PATH}:$(brew --prefix icu4c)/lib"
        export LIBRARY_PATH
        ;;
esac
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j"$(getconf _NPROCESSORS_ONLN)"
status=$?
cp kudu ../
exit $status
