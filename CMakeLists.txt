
cmake_minimum_required(VERSION 3.5...4.0)

# This section turns on and off this feature
option( INCLUDE_LIBSUNLIGHT "Include libSunLight" ON )
if( NOT ${INCLUDE_LIBSUNLIGHT} )
    return()
endif()
option( make_tests "Build g tests" OFF )
project(SunLight)




add_library(SunLight Date.cpp
                     SunCalc.cpp
                     SunLight.cpp)


target_include_directories(SunLight PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (SunLight LINK_PUBLIC -lm)

if(${BUILD_SHARED_LIBS})
    install(TARGETS    SunLight       DESTINATION /usr/local/lib )    
endif()

if(${make_tests})
    add_subdirectory (Tests)
endif()
