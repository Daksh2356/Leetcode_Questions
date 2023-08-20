/*
Question :81. Search in Rotated Sorted Array II
Date : 10-08-23
Problem Difficulty level : Medium
Related Topics : Array and Binary Search

Problem Statement:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
            return true;


            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }

            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <=target && target<=nums[mid])
                high = mid -1;
                else low = mid+1;
            }

            else
            {
                if(nums[mid] <=target && target<=nums[high])
                low = mid+1;
                else high = mid-1;
            }
        }

        return false;
    }

    // time complexity = O(n) (worst case) & O(logn) (average case)
    // space complexity = O(1)
    // Because of having duplicates, we have to traverse more in order to find which half of the array is sorted 
    // as we may have the condition that low and high positions have same value as the mid position
};