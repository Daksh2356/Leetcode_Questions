/*
Question: 41. First Missing Positive
Date : 26-03-24
Problem Difficulty level : Hard
Related Topics : Array, Hash Table
Problem Statement:

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/

// code : 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i]; // current element
            /*
            x>=1 and x<=n => for positive integer
            x != i+1 => check if element at i is at correct place
            nums[x-1]!=x => check if element at x-1 is at correct place
            */
            while (x >= 1 && x <= n && x != i + 1 && nums[x - 1] != x) {
                swap(nums[i], nums[x - 1]);
                x = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }

    // time = O(n)
    // space = O(1)
};