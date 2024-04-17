/*
Question : 623. Add One Row to Tree 
Date : 16-04-24
roblem Difficulty level : Medium
Related Topics : Tree, DFS, BFS, Binary Tree

Problem Statement:

Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:
1) Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree
 root and right subtree root.
2) cur's original left subtree should be the left subtree of the new left subtree root.
3) cur's original right subtree should be the right subtree of the new right subtree root.
4) If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original 
tree, and the original tree is the new root's left subtree.
 
Example 1:
Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]

Example 2:
Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]
 
Constraints:
The number of nodes in the tree is in the range [1, 10^4].
The depth of the tree is in the range [1, 10^4].
-100 <= Node.val <= 100
-10^5 <= val <= 10^5
1 <= depth <= the depth of tree + 1
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val); // new root is made
            newRoot->left = root; // org tree becomes left subtree of new root
            return newRoot;
        }

        queue<TreeNode*>
            q; // make a queue to hold all the node till depth-1 ( deepest lvl)
        q.push(root); // first the root node is pushed
        int currDepth = 1;

        while (!q.empty() && currDepth < depth - 1) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // check for current node's left and right child
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ++currDepth;
        }

        while(!q.empty()){
            TreeNode* node = q.front(); 
            q.pop();

            TreeNode* leftChild = new TreeNode(val);  // creation of new nodes 
            TreeNode* rightChild = new TreeNode(val);

            leftChild->left = node->left;
            rightChild->right = node->right ;

            node->left = leftChild ;  // handling left and right subtree nodes
            node->right = rightChild;

          
        }

        return root;

        // time complexity = O(n+k)
        // space complexity = O(k) 

        // n => no of nodes in tree
        // k => no of nodes at deepest level ( depth - 1 )



    }
};