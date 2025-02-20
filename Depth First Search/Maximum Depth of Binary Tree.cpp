/*
! Question: 104. Maximum Depth of Binary Tree
* Problem Difficulty level : Easy
? Related Topics : Tree, Depth First Search, Breadth First Search

Problem Statement:

! Given the root of a binary tree, return its maximum depth.

! A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

? Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

? Example 2:
Input: root = [1,null,2]
Output: 2

? Example 3:
Input: s = "a good   example"
Output: "example good a"
* Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
? Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100

*/


//!  CODE :
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
        int maxDepth(TreeNode* root) {
           if(root == NULL)
                return 0;
            
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
    
            if(lDepth > rDepth) 
                return lDepth + 1;
            else
                return rDepth + 1;
        }

        // time complexity - O(N) for both balanced and skewed trees
        //* space complexity - O(log N) for balanced and O(N) for the skewed trees (worst case-> linked-list like!)
    };