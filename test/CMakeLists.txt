cmake_minimum_required (VERSION 2.8.11)
project (JsonParser)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test jsonTest.cpp ../jsonparser.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
