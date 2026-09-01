cmake_minimum_required(VERSION 3.16)
project(BarcodeTests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)

enable_testing()

add_executable(asciix_tests 
    tests/EncoderTests.cpp
    src/Encoder.cpp
)

target_include_directories(asciix_tests PRIVATE 
    "C:/Users/dell/source/repos/BarcodeEncoder/googletest/googletest/include"
    "C:/Users/dell/source/repos/BarcodeEncoder/include" 
)

target_link_libraries(asciix_tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(asciix_tests)
