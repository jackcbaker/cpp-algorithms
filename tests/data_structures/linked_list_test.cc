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
    int result = testList.popLeft();
    EXPECT_EQ(result, 3);
    int result2 = testList.popLeft();
    EXPECT_EQ(result2, 2);
}


TEST(LinkedListTest, PopAll) {
    std::vector<int> toAdd = {1, 2, 3};
    LinkedList<int> testList;
    for (const int elem : toAdd) {
        testList.insert(elem);
    }
    int result = testList.popLeft();
    EXPECT_EQ(result, 3);
    result = testList.popLeft();
    EXPECT_EQ(result, 2);
    result = testList.popLeft();
    EXPECT_EQ(result, 1);
    result = testList.popLeft();
    EXPECT_EQ(result, int());
    result = testList.popLeft();
    EXPECT_EQ(result, int());
}


TEST(LinkedListTest, Append) {
    std::vector<int> toAdd = {1, 2, 3};
    LinkedList<int> testList;
    for (const int elem : toAdd) {
        testList.append(elem);
    }
    int result = testList.popLeft();
    EXPECT_EQ(result, 1);
    result = testList.popLeft();
    EXPECT_EQ(result, 2);
    result = testList.popLeft();
    EXPECT_EQ(result, 3);
    result = testList.popLeft();
    EXPECT_EQ(result, int());
}


TEST(LinkedListTest, Pop) {
    std::vector<char> toAdd = {'a', 'b', 'c'};
    LinkedList<char> testList;
    for (const char elem : toAdd) {
        testList.append(elem);
    }
    char result = testList.pop();
    EXPECT_EQ(result, 'c');
    result = testList.pop();
    EXPECT_EQ(result, 'b');
    result = testList.pop();
    EXPECT_EQ(result, 'a');
    result = testList.pop();
    EXPECT_EQ(result, char());
}


TEST(LinkedListTest, Empty) {
    LinkedList<char> testList;
    char result = testList.pop();
    EXPECT_EQ(result, char());
}