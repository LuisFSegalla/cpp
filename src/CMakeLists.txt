add_library(card card.cpp)
add_library(apiWrapper apiWrapper.cpp)
add_library(collection collection.cpp)
add_library(deck deck.cpp)

find_package(CURL)
set(LIBS ${LIBS} ${CURL_LIBRARIES})
include_directories(${CURL_INCLUDE_DIRS})


target_link_libraries(
    apiWrapper
    pthread
    curl
    curlpp
)

