/*
Date : 22/05/25
Platform : GFG
Track : GFG-160-problems
Difficulty: Medium

Given an integer array arr[]. You need to find the maximum sum of a subarray.

?Examples:

Input: arr[] = [2,3,-8,7,-1,2,3]
?Output: 11
*Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

Input: prices[] = [-2, -4]
?Output: -2
*Explanation: The subarray {-2} has the largest sum -2.

Input: prices[] = [5, 4, 1, 7, 8]
?Output: 25
*Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

!Constraints:
! 1 <= arr.size() <= 10^5
! -10^9 <= arr[i] <= 10^9
*/

code:

// User function Template for Java
class Solution {
    int maxSubarraySum(int[] arr) {
        int maxSum = 0;
        int maxTillNow = Integer.MIN_VALUE;
        
        for( int num : arr ){
            maxSum += num;
            
            maxTillNow = Math.max(maxTillNow, maxSum);
            
            if(maxSum < 0)
                maxSum = 0;
        }
        
        return maxTillNow;
    }
}   