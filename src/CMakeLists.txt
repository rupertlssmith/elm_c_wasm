# Add lib subdirectory first (for wingetopt on Windows)
add_subdirectory(lib)

# Add kernel subdirectory
add_subdirectory(kernel)

# Add test subdirectory if enabled
if(BUILD_TESTS)
    add_subdirectory(test)
endif()
