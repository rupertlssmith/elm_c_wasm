cmake_minimum_required(VERSION 3.16)
project(elm-compiler C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Build options
option(BUILD_TESTS "Build test executables" ON)
option(ENABLE_DEBUG "Enable debug features" OFF)
option(ENABLE_PERF_TIMER "Enable performance timing" OFF)

# Set build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Global compiler flags
if(ENABLE_DEBUG)
    add_compile_definitions(DEBUG)
endif()

if(ENABLE_PERF_TIMER)
    add_compile_definitions(PERF_TIMER_ENABLED=1)
else()
    add_compile_definitions(PERF_TIMER_ENABLED=0)
endif()

# Add TEST macro for test builds
add_compile_definitions(TEST)

# Platform-specific settings
if(WIN32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_definitions(REPLACE_GETOPT)
endif()

# Include directories
include_directories(src/kernel/core)
include_directories(src/lib)

# Add subdirectories
add_subdirectory(src)

# Install targets
if(TARGET elm-kernel)
    install(TARGETS elm-kernel
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
endif()
