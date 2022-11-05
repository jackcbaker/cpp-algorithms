cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src)

add_executable(
  knapsack_test
  tests/dp/knapsack_test.cc
)

target_link_libraries(
  knapsack_test
  PUBLIC
  dp
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(knapsack_test)
