cmake_minimum_required(VERSION 3.16)

project(Encoder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(asciix_core STATIC
    src/Encoder.cpp
)
target_include_directories(asciix_core PUBLIC include)
target_compile_features(asciix_core PUBLIC cxx_std_17)

add_executable(asciix_cli src/main.cpp)
target_link_libraries(asciix_cli PRIVATE asciix_core)

option(ASCIIX_BUILD_TESTS "Build unit tests" ON)
if(ASCIIX_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()