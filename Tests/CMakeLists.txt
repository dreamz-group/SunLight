# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../ ./)

file(GLOB SOURCE "*.cpp" "../*.cpp")

add_executable(SunLight_tests ${SOURCE} )

target_link_libraries(SunLight_tests  SunLight ${GTEST_LIBRARIES} pthread)

add_test (NAME SunLight COMMAND SunLight_tests)