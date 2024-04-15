/*
Question: 404. Sum of Left Leaves
Date : 14-04-24
Problem Difficulty level : Easy
Related Topics : Tree, DFS, BFS and Binary Tree
Problem Statement:

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0
 
Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(struct TreeNode* node, bool isLeft){
        if(node == nullptr)
            return 0;
        
        // check for left child and leave node ( leave node - with no children )
        if(isLeft && node->left == nullptr && node->right == nullptr)
            return node->val;
        
        // sum from left subtree
        int leftSum = dfs(node->left, true); // isLeft = true since it's left child

        // sum from right subtree
        int rightSum = dfs(node->right, false); // isLeft = false since it's n ot a left child

        return leftSum + rightSum;

        // time complexity = O(N)  => number of nodes in the binary tree
        // space complexity = O(H) => height of the binary tree

    }
    int sumOfLeftLeaves(TreeNode* root) {

        // check for empty root
        if(root == NULL)
            return 0;
        
        return dfs(root, false);
    }
};