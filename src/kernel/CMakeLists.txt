# Add core subdirectory
add_subdirectory(core)

# Main kernel library target
add_library(elm-kernel STATIC
    $<TARGET_OBJECTS:elm-kernel-core>
)

target_link_libraries(elm-kernel
    elm-kernel-core
)

# Platform-specific libraries
if(UNIX AND NOT APPLE)
    target_link_libraries(elm-kernel m)
endif()

if(WIN32 AND TARGET wingetopt)
    target_link_libraries(elm-kernel wingetopt)
endif()
