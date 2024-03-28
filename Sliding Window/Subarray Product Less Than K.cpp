/*
Question : 713. Subarray Product Less Than K
Date : 27-03-24
Problem Difficulty level : Medium
Related Topics : Array, Sliding Window

Problem Statement:
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the 
subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:
1 <= nums.length <= 3 * 10^4
1 <= nums[i] <= 1000
0 <= k <= 10^6
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0, prod = 1, left = 0, right =0;

        if(k == 0 )
            return 0;

        while(right < n){        // traversing the array from index 0 
           prod *= nums[right]; 

           while(prod >= k && left<=right){  // dividing the product from element at left 
                prod /= nums[left];          // till the product becomes less than k
                left++;
           }

           count += right-left+1;        // count is increemented
           right++;                  // the right pointer is moves forward in each iteration
        }

        return count;

        // time complexity = O(n)
        // space complexity = O(1)
    }
};