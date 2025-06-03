/*
Date : 11/05/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Medium

Problem Statement:
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Example 1:
Input: nums = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

Example 2:
Input: nums = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.

Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 

Constraints:
1 ≤ arr.size() ≤ 10^6
-10  ≤  arr[i]  ≤  10
*/

code :
class Solution {
    
    int maxProduct(int[] arr) {
        
        int minend = arr[0], maxend = arr[0], res = arr[0];
        
        for(int i=1; i<arr.length; i++){
            int temp = minend; 
            minend = Math.min(arr[i], Math.min(arr[i]*minend, arr[i]*maxend));
            maxend = Math.max(arr[i], Math.max(arr[i]*temp, arr[i]*maxend));
            res = Math.max(res, maxend);
        }
        
        return res;
        
    }
}

// time complexity = O(n)
// space complexity = O(1)