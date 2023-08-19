/*
Question : 95. Unique Binary Search Trees II
Date : 05-08-23
Problem Difficulty level : Medium
Related Topics : Dp, backtracking, Tree and Binary Search Tree

Problem Statement:
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
*/
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
    vector<TreeNode*> generateTrees(int n) {
        return n ? generate_Trees(1,n) : vector<TreeNode*>();
    }

private:
    vector<TreeNode*> generate_Trees(int start, int end)
    {
        if(start>end) return {nullptr};
        vector<TreeNode*> allTrees;
        for(int i = start; i<=end; i++)
        {
            vector<TreeNode*> leftTrees = generate_Trees(start,i-1);
            vector<TreeNode*> rightTrees = generate_Trees(i+1,end);

            for(TreeNode* l : leftTrees)
            {
              for(TreeNode* r : rightTrees)
              {
                TreeNode* currentTree = new TreeNode(i);
                currentTree-> left = l;
                currentTree-> right = r;
                allTrees.push_back(currentTree); 

              }
            }
        }

        return allTrees;
    }

    // time - O(N*G(N)) - G(N) finds all the unique BST and grows exponentially with N
    // space - O(N*G(N))
};