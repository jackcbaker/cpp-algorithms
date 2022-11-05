add_library(
    dp SHARED
    dp/knapsack.cc
)

target_include_directories(dp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dp")