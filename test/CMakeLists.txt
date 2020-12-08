cmake_minimum_required (VERSION 2.8.11)
project (SZE-MOSZE-2020)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(jsontest jsonTest.cpp ../jsonparser.cpp)
target_link_libraries(jsontest ${GTEST_LIBRARIES} pthread)


add_executable(unittest unitTest.cpp ../character.cpp)
target_link_libraries(unittest ${GTEST_LIBRARIES} pthread)
