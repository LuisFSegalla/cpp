cmake_minimum_required(VERSION 3.5.1)
project(mains)
set (CMAKE_CXX_STANDARD 11)

set(MAIN_TEST 1.0)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/spotify-api-plusplus/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/spotify-api-plusplus/src/models")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/spotify-api-plusplus/src/utils")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/spotify-api-plusplus/build/src")

add_executable(main main.cpp)

target_link_libraries(
        main
        pthread
        libspotify-api-plusplus.so
        curl
)