# Windows getopt library
if(WIN32)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/wingetopt/wingetopt.c")
        add_library(wingetopt STATIC
            wingetopt/wingetopt.c
            wingetopt/wingetopt.h
        )
        
        target_include_directories(wingetopt PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/wingetopt
        )
    endif()
endif()
