add_library(
    dp SHARED
    dp/knapsack.cc
    dp/job_sequencing.cc
)

target_include_directories(dp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dp")

add_library(
    data_structures SHARED
    data_structures/linked_list.cc
    data_structures/linked_list_simple.cc
    data_structures/stack.cc
    data_structures/tree.cc
)

target_include_directories(data_structures PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/data_structures")