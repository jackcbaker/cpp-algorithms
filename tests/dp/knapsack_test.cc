#include "knapsack.h"

#include <gtest/gtest.h>

#include <vector>
#include <iostream>


TEST(KnapsackTest, Basic) {
  std::vector<int> vals = {1, 2, 3};
  std::vector<int> wts = {1, 2, 3};
  int W = 4;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 4);
}


TEST(KnapsackTest, Basic2) {
  std::vector<int> vals = {6, 7, 2, 9, 2, 3};
  std::vector<int> wts = {4, 4, 1, 5, 3, 2};
  int W = 13;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 22);
}


TEST(KnapsackTest, Basic3) {
  std::vector<int> vals = {60, 100, 120};
  std::vector<int> wts = {10, 20, 30};
  int W = 53;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 220);
}


TEST(KnapsackTest, EqualValues) {
  std::vector<int> vals = {4, 4, 4, 4, 4, 4};
  std::vector<int> wts = {4, 4, 4, 4, 4, 4};
  int W = 11;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 8);
}


TEST(KnapsackTest, NoItems) {
  std::vector<int> vals = {};
  std::vector<int> wts = {};
  int W = 11;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 0);
}


TEST(KnapsackTest, NoWeight) {
  std::vector<int> vals = {1, 2, 3};
  std::vector<int> wts = {1, 2, 3};
  int W = 0;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 0);
}


TEST(KnapsackTest, NoSpace) {
  std::vector<int> vals = {1, 2, 3};
  std::vector<int> wts = {2, 2, 3};
  int W = 1;
  int result = knapsack(vals, wts, W);
  EXPECT_EQ(result, 0);
}