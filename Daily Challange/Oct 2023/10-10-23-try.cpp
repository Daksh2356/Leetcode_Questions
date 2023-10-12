// solution try
/*
Question : 2009. Minimum Number of Operations to Make Array Continuous
Date : 09-10-23
Problem Difficulty level : Hard
Related Topics : Array and Binary Search
Problem Statement:
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.
nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/
class Solution
{
private:
    int binarySearch(vector<int> &arr, int target) // time => O(logn)
    {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0, result = -1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] <= target)
            {
                low = mid + 1;
                result = mid;
            }
            else
                high = mid - 1;
        }

        return result;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // time => O(nlogn)
        int minOperations = n;

        for (int i = 0; i < n; i++) // time => O(n)
        {
            int rightIndex = binarySearch(nums, nums[i] + n - 1); // (nums[i] + n-1) is the rightmost element required for satisfying the diff condition

            int operations = n - (rightIndex - i + 1);
            minOperations = min(minOperations, operations);
        }

        return minOperations;
    }

    // Time complexity = O(nlogn) -> sorting has same time as (linear loop + binary search)
    // Space Complexity = O(1) -> constant extra space is used in this solution
};