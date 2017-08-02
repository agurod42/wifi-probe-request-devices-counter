project(people-wifi-counter)

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_library(TINS_LIBRARY tins)
find_package(Threads REQUIRED)

#include(CMakeToolsHelpers OPTIONAL)
#include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)

#conan_basic_setup()

add_executable(people-wifi-counter src/main.cpp)

#target_link_libraries(people-wifi-counter ${CONAN_LIBS})
target_link_libraries(people-wifi-counter ${TINS_LIBRARY})
target_link_libraries(people-wifi-counter Threads::Threads)