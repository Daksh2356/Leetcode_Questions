/*
Question : 905. Sort Array By Parity
Date : 28-09-23
Problem Difficulty level : Easy
Related Topics: Array, Two Pointers and Sorting
Problem Statement:
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]

Constraints:
1 <= nums.length <= 5000
0 <= nums[i] <= 5000
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left =0;  // left starts with first index and moves forward
        int right = nums.size() - 1;  // right starts with last index and moves backward

        while(left < right)
        {
            while(nums[left]%2==0 && left < right)
            {
                left++;    // we increement left till we get an odd value
            }

            while(nums[right]%2 != 0 && left<right)
            {
                right--;     // we decreement right till we get an even value
            }

            if(left < right)
            {
                swap(nums[left], nums[right]);
            }
        }

        return nums;
        // Time Complexity = O(n)
        // Space Complexity = O(1)
    }
};