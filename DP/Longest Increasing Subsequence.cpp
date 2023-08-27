/*
Question : 300. Longest Increasing Subsequence
Date : 27-08-23
Problem Difficulty level : Medium
Related Topics : Array, Dynamic Programming and Binary Search ( this is left to be done)

Problem Statement:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        vector<int> dp(n,1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }

        int max_length = *max_element(dp.begin(), dp.end());
        return max_length;
    }

    // time complexity = O(n^2)
    // space complexity = O(n)
};