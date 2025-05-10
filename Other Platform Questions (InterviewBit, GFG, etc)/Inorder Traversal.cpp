/*
Problem Description
 Given a binary tree, return the inorder traversal of its nodes values.

NOTE: Using recursion is not allowed.

Problem Constraints
 1 <= number of nodes <= 105

Input Format
First and only argument is root node of the binary tree, A.

Output Format
Return an integer array denoting the inorder traversal of the given binary tree.


Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [1, 3, 2]
Output 2:

 [6, 1, 3, 2]

Example Explanation
 Explanation 1:  The Inorder Traversal of the given tree is [1, 3, 2].
 Explanation 2 : The Inorder Traversal of the given tree is [6, 1, 3, 2].

*/

// code : 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* curr = A;

    while (curr != NULL || !s.empty()) {
        // Traverse to the leftmost node
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // Pop the top node from the stack and add its value to the result
        curr = s.top();
        s.pop();
        result.push_back(curr->val);

        // Move to the right subtree
        curr = curr->right;
    }

    return result;
}
