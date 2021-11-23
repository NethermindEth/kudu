cmake_minimum_required(VERSION 3.20)
include(cmake/clang-format-tool.cmake)

project(warp_solidity
        VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

option(SANITIZE "Turn on sanitizers")

if (SANITIZE)
  add_compile_options(-fsanitize=address -fsanitize=leak -fsanitize=undefined)
  add_link_options(-fsanitize=address -fsanitize=leak -fsanitize=undefined)
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror -O3 -Wno-unused-parameter -Wno-uninitialized)

find_package(Boost 1.65.0 QUIET REQUIRED COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS})

include(FetchContent)

FetchContent_Declare(
        solidity

        GIT_REPOSITORY "https://github.com/NethermindEth/nethersolc.git"
        GIT_TAG "31d80771df272300e97d7674ea35a5e673b0c51b"
        )

if (NOT solidity_POPULATED)
  FetchContent_Populate(solidity)
endif()

include(${solidity_SOURCE_DIR}/cmake/EthDependencies.cmake)
include(${solidity_SOURCE_DIR}/cmake/jsoncpp.cmake)
include(${solidity_SOURCE_DIR}/cmake/range-v3.cmake)

include(ExternalProject)

include(ProcessorCount)
ProcessorCount(NPROCS)

ExternalProject_Add(
        solidity-project

        SOURCE_DIR ${solidity_SOURCE_DIR}
        BINARY_DIR ${solidity_BINARY_DIR}

        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
            -DUSE_Z3=OFF -DUSE_CVC4=OFF

        BUILD_COMMAND
            make -j${NPROCS}

        INSTALL_COMMAND ""
        )

add_library(solutil SHARED IMPORTED)
set_target_properties(solutil PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/libsolutil/libsolutil.a)
target_link_libraries(solutil INTERFACE jsoncpp Boost::boost Boost::filesystem Boost::system range-v3)

add_library(langutil SHARED IMPORTED)
set_target_properties(langutil PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/liblangutil/liblangutil.a)
target_link_libraries(langutil INTERFACE solutil)

add_library(smtutil SHARED IMPORTED)
set_target_properties(smtutil PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/libsmtutil/libsmtutil.a)
target_link_libraries(smtutil INTERFACE solutil Boost::boost)

add_library(evmasm SHARED IMPORTED)
set_target_properties(evmasm PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/libevmasm/libevmasm.a)
target_link_libraries(evmasm INTERFACE solutil)

add_library(yul SHARED IMPORTED)
set_target_properties(yul PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/libyul/libyul.a)
target_link_libraries(yul INTERFACE evmasm solutil langutil smtutil)

add_library(solidity SHARED IMPORTED)
set_target_properties(solidity PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/libsolidity/libsolidity.a)
target_link_libraries(solidity INTERFACE yul evmasm langutil smtutil solutil Boost::boost)

add_library(solcli SHARED IMPORTED)
set_target_properties(solcli PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/solc/libsolcli.a)
target_link_libraries(solcli INTERFACE solidity Boost::boost Boost::program_options)

add_library(phaser SHARED IMPORTED)
set_target_properties(phaser PROPERTIES
        IMPORTED_LOCATION ${solidity_BINARY_DIR}/tools/libphaser.a)
target_link_libraries(phaser INTERFACE solidity Boost::boost Boost::program_options)

add_library(full-solidity INTERFACE)
target_link_libraries(full-solidity INTERFACE solidity solcli phaser)
target_include_directories(full-solidity SYSTEM
         INTERFACE ${solidity_SOURCE_DIR} ${solidity_BINARY_DIR}/deps/include)
add_dependencies(full-solidity solidity-project)


set (WARP_LIBS libwarp/common/json.hpp libwarp/common/library.hpp libwarp/common/library.cpp
        libwarp/yul_prepass/YulVisitor.hpp libwarp/yul_prepass/YulVisitor.cpp
        libwarp/yul_prepass/YulCleaner.hpp libwarp/yul_prepass/YulCleaner.cpp
        libwarp/solidity_prepass/WarpVisitor.hpp libwarp/solidity_prepass/WarpVisitor.cpp)

add_library(warp-solidity ${WARP_LIBS})
add_dependencies(warp-solidity solidity-project)
target_include_directories(warp-solidity
        PUBLIC ${CMAKE_SOURCE_DIR} ${solidity_SOURCE_DIR} ${solidity_BINARY_DIR}/deps/include)
target_link_libraries(warp-solidity full-solidity Boost::regex)


add_executable(kudu kudu.cpp)
target_link_libraries(kudu warp-solidity)
