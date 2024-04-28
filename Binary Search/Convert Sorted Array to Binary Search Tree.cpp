/*
Question : 108. Convert Sorted Array to Binary Search Tree
Date : 27-04-24
Problem Difficulty level : Easy
Related Topics: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
Problem Statement:
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 
Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.
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

    TreeNode* bst(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;
        
        int mid = ( low + high )/ 2;

        TreeNode* node = new TreeNode(nums[mid]);  // the mid node is the root
        node->left = bst(nums, low, mid -1);   //  left subtree with high = mid -1 
        node->right = bst(nums, mid+1, high);   // right subtree with low = mid + 1

        return node;  // return root node 
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        TreeNode* ans = bst(nums, 0, n-1);   // pass low = 0, high = n - 1
        return ans;
    }

    // time complexity = O(n)
    // space complexity = O(logn)
};