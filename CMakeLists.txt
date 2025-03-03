cmake_minimum_required(VERSION 3.5.1)
project(mains)
set (CMAKE_CXX_STANDARD 20)

set(MAIN_TEST 1.0)

set(TEST_DIR ${mains_SOURCE_DIR}/test)

set(SRC_DIR ${mains_SOURCE_DIR}/src)

add_subdirectory(src)
# add_library(userWrapper userWrapper.cpp)
include_directories(${SRC_DIR})


add_executable(main main.cpp)

target_link_libraries(
        main
        pthread
        curl
        curlpp
        apiWrapper
        card
        collection
        deck
)

add_subdirectory(${TEST_DIR})