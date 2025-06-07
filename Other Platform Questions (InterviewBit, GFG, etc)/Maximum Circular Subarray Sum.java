/*
Date : 07/06/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Hard

Problem Statement:
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Example 1:
Input: nums = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 
12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

Example 2:
Input: nums = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].

Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52 
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.

Constraints:
1 ≤ arr.size() ≤ 10^5
-10^4  ≤  arr[i]  ≤  10^4
*/

code :
class Solution {
    public int circularSubarraySum(int arr[]) {
        
        int n = arr.length;
        int maxEnd =0, minEnd = 0, maxSum = arr[0], minSum = arr[0], total = 0;
        
        for(int i=0; i<n; i++){
            maxEnd = Math.max(maxEnd + arr[i], arr[i]);
            maxSum = Math.max(maxEnd, maxSum);
            
            minEnd = Math.min(minEnd + arr[i], arr[i]);
            minSum = Math.min(minEnd, minSum);
            
            total += arr[i];
        }
        
        if(total == minSum)
            return maxSum;
            
        int circularSum = total - minSum;
        
        return Math.max(circularSum, maxSum);
    }
}

// time complexity = O(n)
// space complexity = O(1)