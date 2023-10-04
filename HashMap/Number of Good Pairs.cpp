/*
Question : 1512. Number of Good Pairs
Date : 03-10-23
Problem Difficulty level : Easy
Related Topics : Math, Array, Hash Table and Counting
Problem Statement:

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100

*/
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int count = 0;
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            if (freqMap.count(num))
            {
                count += freqMap[num];
            }
            freqMap[num]++;
        }

        return count;
    }

    // Time Complexity = O(N)
    // Space Complexity = O(N)
};