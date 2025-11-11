# Test sources
set(TEST_SOURCES
    test.c
    test-compiled.c
    test-imports.c
    gc_test.c
    string_test.c
)

# Create test executable
add_executable(elm-tests ${TEST_SOURCES})

target_link_libraries(elm-tests elm-kernel-core)

# Add wingetopt for Windows
if(WIN32 AND TARGET wingetopt)
    target_link_libraries(elm-tests wingetopt)
endif()

# Add math library on Unix systems
if(UNIX AND NOT APPLE)
    target_link_libraries(elm-tests m)
endif()

target_include_directories(elm-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/kernel/core
    ${CMAKE_SOURCE_DIR}/src/lib/wingetopt
)

# Test target
enable_testing()
add_test(NAME elm-kernel-tests COMMAND elm-tests --all)

# Individual test targets for convenience
add_test(NAME elm-types-test COMMAND elm-tests -t)
add_test(NAME elm-utils-test COMMAND elm-tests -u)
add_test(NAME elm-basics-test COMMAND elm-tests -b)
add_test(NAME elm-string-test COMMAND elm-tests -s)
add_test(NAME elm-char-test COMMAND elm-tests -c)
add_test(NAME elm-list-test COMMAND elm-tests -l)
add_test(NAME elm-debug-test COMMAND elm-tests -d)
add_test(NAME elm-json-test COMMAND elm-tests -j)
add_test(NAME elm-platform-test COMMAND elm-tests -p)
add_test(NAME elm-gc-test COMMAND elm-tests -g)
