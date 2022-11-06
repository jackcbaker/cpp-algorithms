add_library(
    dp SHARED
    dp/knapsack.cc
    dp/job_sequencing.cc
)

target_include_directories(dp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dp")