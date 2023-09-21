/*
Question : 1658. Minimum Operations to Reduce X to Zero
Date : 20-09-23
Problem Difficulty level : Medium
Related Topics: Array, Hash table, Binary Search, Sliding Window, Prefix Sum

Problem Statement:
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element
from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total)
to reduce x to zero.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
1 <= x <= 10^9
*/
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int max_length = -1;
        int curr_sum = 0;
        int count_left = 0;

        for (int right_pointer = 0; right_pointer < nums.size(); ++right_pointer)
        {
            curr_sum += nums[right_pointer];
            while (count_left <= right_pointer && curr_sum > total_sum - x)
            {
                curr_sum -= nums[count_left];
                count_left++;
            }
            if (curr_sum == total_sum - x)
            {
                max_length = max(max_length, right_pointer - count_left + 1);
            }
        }

        return (max_length == -1) ? -1 : nums.size() - max_length;
    }
};
