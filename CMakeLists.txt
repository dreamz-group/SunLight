
cmake_minimum_required(VERSION 3.5...4.0)

# This section turns on and off this feature
option( INCLUDE_LIBSUNLIGHT "Include libSunLight" ON )
if( NOT ${INCLUDE_LIBSUNLIGHT} )
    return()
endif()
option( make_tests "Build g tests" OFF )
project(SunLight)

# Build type option with Release as default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type (Debug, Release)" FORCE)
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release)

# Build options
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Compiler flags for different build types
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O3 -march=native)
    endif()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

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
