/*
Question: 515. Find Largest Value in Each Tree Row
Date : 24-10-23
Problem Difficulty level : Medium
Related Topics : Tree, DFS, BFS and Binary Tree
Problem Statement:
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]


Constraints:
The number of nodes in the tree will be in the range [0, 10^4].
-2^31 <= Node.val <= 2^31 - 1

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
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {

        if (!root)
            return {}; // check for null element at ROOT of tree

        vector<int> result;  // for storing the max value at each row of given tree
        queue<TreeNode *> q; // for traversing through each element of the tree
        q.push(root);

        while (!q.empty()) // traversal method - BFS
        {
            int curr_size = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < curr_size; i++)
            {
                TreeNode *node = q.front(); // the element at front of queue is chosen
                q.pop();                    // front element is removed from queue

                max_val = max(max_val, node->val); // calculating the max_val for this row

                if (node->left)
                    q.push(node->left); // inserting left children of the current node
                if (node->right)
                    q.push(node->right); // inserting right children of the current node
            }

            result.push_back(max_val); // max value is pushed into the result vector
        }

        return result; // return the vector with large values from each row of tree
    }

    // time complexity = O(n)
    // space complexity = O(n)
};