# Additional targets to perform clang-format/clang-tidy
# Get all project files
file(GLOB_RECURSE
     ENDF6_SRC
     ${PROJECT_SOURCE_DIR}/solidity_prepass/*.cpp
     ${PROJECT_SOURCE_DIR}/solidity_prepass/*.hpp
     ${PROJECT_SOURCE_DIR}/yul_prepass/*.hpp
     ${PROJECT_SOURCE_DIR}/yul_prepass/*.cpp
     )

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
  add_custom_target(
    clang-format
    COMMAND /usr/bin/clang-format
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
    )
endif()
