#include "stack.h"

#include <gtest/gtest.h>

#include <vector>
#include <iostream>


TEST(StackTest, Basic) {
    std::vector<int> toAdd = {1, 2, 3};
    Stack<int> testStack;
    for (const int elem : toAdd) {
        testStack.insert(elem);
    }
    int result = testStack.peek();
    EXPECT_EQ(result, 3);
    result = testStack.pop();
    EXPECT_EQ(result, 3);
    result = testStack.pop();
    EXPECT_EQ(result, 2);
}