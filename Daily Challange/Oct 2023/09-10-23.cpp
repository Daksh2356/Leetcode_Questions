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

// Latest appraoch :
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = -1, last = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                    first = i;

                last = i;
            }
        }

        return {first, last};
    }

    // Time Complexity = O(n)
    // Space Complexity = O(1)
};

// Initial Approach :

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        vector<int> ans(2, -1); // initializing the vector with value '-1' at both indices

        while (low <= high) // time => O(logn)
        {
            mid = (low + high) / 2;

            if (target < nums[mid])
                high = mid - 1;

            else if (target > nums[mid])
                low = mid + 1;

            else
            {
                ans[0] = ans[1] = mid; // we get our first position to start with

                while (ans[0] > 0 && nums[ans[0] - 1] == target) // time => O(n)
                {
                    ans[0]--; // finding the first position of target in a sorted array
                }

                while (ans[1] < n - 1 && nums[ans[1] + 1] == target) // time => O(n)
                {
                    ans[1]++; // finding the last position of target in a sorted array
                }

                break;
            }
        }
        return ans;

        // Time complexity = O(n) (effective)
        // Space complexity = O(1)
    }
};