#!/usr/bin/env sh

mkdir -p build
cd build || exit

# cmake doesn't redownload nethersolc when a GIT_TAG changes. So we
# delete the download timestamp.
rm -f ./solidity-project-prefix/src/solidity-project-stamp/solidity-project-download

# See https://github.com/Homebrew/homebrew-core/issues/67427#issuecomment-756511468
# for an explanation why we adjust LIBRARY_PATH for macos
case "$(uname -s)" in
    Darwin*)
        LIBRARY_PATH="${LIBRARY_PATH}:$(brew --prefix icu4c)/lib"
        export LIBRARY_PATH
        ;;
esac
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j"$(getconf _NPROCESSORS_ONLN)"
status=$?
exit $status
