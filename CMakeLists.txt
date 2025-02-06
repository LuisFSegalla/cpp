cmake_minimum_required(VERSION 3.5.1)
project(mains)
set (CMAKE_CXX_STANDARD 20)

set(MAIN_TEST 1.0)

add_subdirectory(src)
# add_library(userWrapper userWrapper.cpp)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")


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

# target_include_directories()