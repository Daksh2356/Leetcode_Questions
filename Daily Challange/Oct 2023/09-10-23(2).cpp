/*
Question : 34. Find First and Last Position of Element in Sorted Array
Date : 09-10-23
Problem Difficulty level : Medium
Related Topics : Array and Binary Search
Problem Statement:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

// Optimised approach with O(logn) time complexity
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                ans[0] = mid;
                high = mid - 1;
            }
        }

        low = 0;
        high = n - 1;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
            {
                ans[1] = mid;
                low = mid + 1;
            }
        }

        return ans;
    }

    //  Time complexity = O(logn)
    //  Space complexity = O(1)
};