/*
Question : 896. Monotonic Array
Date : 29-09-23
Problem Difficulty level : Easy
Related Topics: Array
Problem Statement:
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j,
nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true

Example 2:
Input: nums = [6,5,4,4]
Output: true

Example 3:
Input: nums = [1,3,2]
Output: false
 

Constraints:
1 <= nums.length <= 10^5
-105^ <= nums[i] <= 10^5
*/

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
            return true;

        int direction = 0; // '0' is no direction, '1' is forward and '-1' is backward

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                if (direction == 0)
                    direction = 1;
                else if (direction == -1)
                    return false;
            }

            else if (nums[i] > nums[i + 1])
            {
                if (direction == 0)
                    direction = -1;
                else if (direction == 1)
                    return false;
            }
        }

        return true;
    }

    // Time Complexiy = O(N)
    // Space Complexity = O(1)
};