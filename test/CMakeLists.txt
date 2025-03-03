include_directories(${SRC_DIR})

enable_testing()

add_executable(CardTest cardTest.cpp)
target_link_libraries(CardTest 
                      pthread
                      curl
                      curlpp
                      apiWrapper
                      card
                      collection
                      deck
                      boost_unit_test_framework)
add_test(NAME CardTest
         COMMAND CardTest)

file(COPY ./output DESTINATION .)