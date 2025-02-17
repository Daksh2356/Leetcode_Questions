/*
Question: 930. Binary Subarrays With Sum
Date : 14-03-24
Problem Difficulty level : Medium
Related Topics : Array, Hash Table, Sliding Window, Prefix Sum
Problem Statement:

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Constraints:
1 <= nums.length <= 3 * 10^4
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int count = 0;
        int n = nums.size();

        // we will have sum = 0 in a binary subarray at sometime so we initialise it with 1
        prefixSum[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int complement = sum - goal;
            if (prefixSum.find(complement) != prefixSum.end())
            {
                count += prefixSum[complement];
            }

            prefixSum[sum]++;
        }

        return count;

        // time and space = O(n)
    }
};