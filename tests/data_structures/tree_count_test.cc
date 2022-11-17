#include "tree.h"

#include <gtest/gtest.h>

#include <vector>
#include <iostream>


TEST(TreeCount, Basic) {
    TreeNode left = TreeNode(3);
    TreeNode root = TreeNode(2, &left, nullptr);
    int count = treeCounter(&root);
    EXPECT_EQ(count, 2);
}


TEST(TreeCount, Larger) {
    TreeNode leafNode1 = TreeNode(4);
    TreeNode leafNode2 = TreeNode(5);
    TreeNode leafNode3 = TreeNode(6);
    TreeNode left = TreeNode(3, &leafNode1, &leafNode2);
    TreeNode right = TreeNode(3, &leafNode3, nullptr);
    TreeNode root = TreeNode(2, &left, &right);
    int count = treeCounter(&root);
    EXPECT_EQ(count, 6);
}


TEST(TreeCount, Size1) {
    TreeNode root = TreeNode(2);
    int count = treeCounter(&root);
    EXPECT_EQ(count, 1);
}


TEST(TreeCount, LeftEnd) {
    TreeNode leafNode = TreeNode(4);
    TreeNode Node1 = TreeNode(5, &leafNode, nullptr);
    TreeNode Node2 = TreeNode(6);
    TreeNode Node3 = TreeNode(6);
    TreeNode Node4 = TreeNode(6);
    TreeNode left = TreeNode(3, &Node1, &Node2);
    TreeNode right = TreeNode(3, &Node3, &Node4);
    TreeNode root = TreeNode(2, &left, &right);
    int count = treeCounter(&root);
    EXPECT_EQ(count, 8);
}


TEST(TreeCount, Empty) {
    int count = treeCounter(nullptr);
    EXPECT_EQ(count, 0);
}