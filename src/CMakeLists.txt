add_library(userWrapper userWrapper.cpp)

find_package(CURL)
set(LIBS ${LIBS} ${CURL_LIBRARIES})
include_directories(${CURL_INCLUDE_DIRS})

target_link_libraries(userWrapper spotify-api-plusplus.so curl)