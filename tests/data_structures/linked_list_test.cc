#include "linked_list.h"

#include <gtest/gtest.h>

#include <vector>
#include <iostream>


TEST(LinkedListTest, Basic) {
    std::vector<int> toAdd = {1, 2, 3};
    LinkedList<int> testList;
    for (const int elem : toAdd) {
        testList.insert(elem);
    }
    int result = testList.pop();
    EXPECT_EQ(result, 3);
    int result2 = testList.pop();
    EXPECT_EQ(result2, 2);
}


TEST(LinkedListTest, PopAll) {
    std::vector<int> toAdd = {1, 2, 3};
    LinkedList<int> testList;
    for (const int elem : toAdd) {
        testList.insert(elem);
    }
    int result = testList.pop();
    EXPECT_EQ(result, 3);
    result = testList.pop();
    EXPECT_EQ(result, 2);
    result = testList.pop();
    EXPECT_EQ(result, 1);
    result = testList.pop();
    EXPECT_EQ(result, 0);
    result = testList.pop();
    EXPECT_EQ(result, 0);
}


TEST(LinkedListTest, Append) {
    std::vector<int> toAdd = {1, 2, 3};
    LinkedList<int> testList;
    for (const int elem : toAdd) {
        testList.append(elem);
    }
    int result = testList.pop();
    EXPECT_EQ(result, 1);
    result = testList.pop();
    EXPECT_EQ(result, 2);
    result = testList.pop();
    EXPECT_EQ(result, 3);
    result = testList.pop();
    EXPECT_EQ(result, 0);
}