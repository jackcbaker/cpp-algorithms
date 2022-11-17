#include "tree.h"

#include <vector>
#include <iostream>


// LeetCode problem 222: count the number of nodes 
// on a complete binary tree in O(n) time.


int treeCounter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    // Create a vec to store nodes in current level of tree.
    std::vector<TreeNode*> levelNodes = {root};
    int levelCurr = 0;
    int totalCount = 1;
    bool isCompleteLevel = true;

    while (isCompleteLevel) {
        // Initialise array for new level
        std::vector<TreeNode*> newLevelNodes = {};
        int numNodesLevel = levelNodes.size();
        for (int i{0}; i < numNodesLevel; i++) {
            TreeNode* currentNode = levelNodes[i];
            if (currentNode->left == nullptr) {
                isCompleteLevel = false;
                break;
            }
            totalCount++;
            newLevelNodes.push_back(currentNode->left);
            if (currentNode->right == nullptr) {
                isCompleteLevel = false;
                break;
            }
            totalCount++;
            newLevelNodes.push_back(currentNode->right);
        }
        levelNodes = newLevelNodes;        
    }
    return totalCount;
}