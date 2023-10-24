/*
Question : 1793. Maximum Score of a Good Subarray
Date : 22-10-23
Problem Difficulty level : Hard
Related Topics : Array, Two pointers, binary search, stack , monotonic stack
Problem Statement:

You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). \

A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

Example 1:
Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.

Example 2:
Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 2 * 10^4
0 <= k < nums.length

*/

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size() - 1;
        int left = k, right = k; // we start at index with val = k
        int min_value = nums[k]; // we initialise value of min of nums(i..k..j) as nums[k]
        int max_score = min_value;

        while (left > 0 || right < n) // we check both the bounds of array
        {
            if (left == 0 || (right < n && nums[right + 1] > nums[left - 1]))
                right++; // if value at right +1  > val at left - 1, we do right + 1
            else
                left--; // else we do left - 1

            min_value = min(min_value, min(nums[left], nums[right]));   // min is calculated
            max_score = max(max_score, min_value * (right - left + 1)); // calculated max_score
        }

        return max_score;
    }

    // Time complexity = O(n)
    // Space complexity = O(1)
};