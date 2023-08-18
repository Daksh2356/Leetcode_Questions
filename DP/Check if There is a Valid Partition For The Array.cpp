/*
Question : 2369. Check if There is a Valid Partition For The Array
Date : 13-08-23
Problem Difficulty level : Medium
Related Topics : Array and Dyannmic Programming

Problem Statement:
You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.
 

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.

*/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool>dp = {true, false, nums[0] == nums[1] };
        for(int i=2;i<nums.size();i++)
        {
            bool current = false;
            if(nums[i] == nums[i-1] && dp[1])
            {
                current = true;
            }

            else if(nums[i] == nums[i-1] && nums[i-1] == nums[i-2] && dp[0])
            current = true;
            
            else if( nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1 && dp[0])
            current = true;

            else current = false;

            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current;
        }

        return dp[2] ;
    }
    // time complexty = O(n)
    // space complexity = O(1)
};