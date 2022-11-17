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
  dp_tests
  tests/dp/knapsack_test.cc
  tests/dp/job_sequencing_test.cc
)

target_link_libraries(
  dp_tests
  PUBLIC
  dp
  GTest::gtest_main
)

add_executable(
  data_structures_tests
  tests/data_structures/linked_list_test.cc
  tests/data_structures/stack_test.cc
  tests/data_structures/tree_count_test.cc
)

target_link_libraries(
  data_structures_tests
  PUBLIC
  data_structures
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dp_tests)
gtest_discover_tests(data_structures_tests)
