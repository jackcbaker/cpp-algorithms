#include "knapsack.h"

#include <vector>

#include <gtest/gtest.h>

TEST(KnapsackTest, Basic) {
  std::vector<int> vals = {1, 2, 3};
  std::vector<int> wts = {1, 2, 3};
  int W = 4;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 4);
}
