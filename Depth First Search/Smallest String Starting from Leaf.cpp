/*
Question : 988. Smallest String Starting From Leaf
Date : 17-04-24
roblem Difficulty level : Medium
Related Topics : String, Tree, DFS, Binary Tree
Problem Statement:

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

Example 1:
Input: root = [0,1,2,3,4,3,4]
Output: "dba"

Example 2:
Input: root = [25,1,3,1,3,0,2]
Output: "adz"

Example 3:
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 
Constraints:
The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25
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
    string ans = "";

    void solve(TreeNode* node, string path){
        if(!node) return ;

        path = char('a' + node->val) + path;

        TreeNode* leftChild = node->left;
        TreeNode* rightChild = node->right;

       if(!leftChild && !rightChild){
        if(ans.empty() || path<ans){  // lexicographical comparsion between 'path' and 'ans'
            ans = path;   // storing the smaller string in 'ans' variable
            return;
        }
       }

       solve(leftChild, path);
       solve(rightChild, path);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return "";

        solve(root, "");

        return ans;

        // time complexity = O(n)
        // space complexity = O(n)
    }
};