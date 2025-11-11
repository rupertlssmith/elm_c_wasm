# Core kernel sources
set(CORE_SOURCES
    types.c
)

# Debug sources (if they exist)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/debug/debug-c.c")
    list(APPEND CORE_SOURCES debug/debug-c.c)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/debug/log.c")
    list(APPEND CORE_SOURCES debug/log.c)
endif()

# GC sources (if they exist)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/gc/allocate.c")
    list(APPEND CORE_SOURCES gc/allocate.c)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/gc/header.c")
    list(APPEND CORE_SOURCES gc/header.c)
endif()

# Create object library for core kernel
add_library(elm-kernel-core OBJECT ${CORE_SOURCES})

target_include_directories(elm-kernel-core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Platform-specific compile definitions
if(EMSCRIPTEN)
    target_compile_definitions(elm-kernel-core PRIVATE __EMSCRIPTEN__)
endif()

if(MSVC)
    target_compile_definitions(elm-kernel-core PRIVATE _MSC_VER)
endif()

# Add math library on Unix systems
if(UNIX AND NOT APPLE)
    target_link_libraries(elm-kernel-core m)
endif()
