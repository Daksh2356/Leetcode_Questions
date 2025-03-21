/*
!  Question 1155: Number of Dice Rolls With Target Sum
* Problem Difficulty level : Medium
? Related Topics : Dynammic Programming
? Date : 16/03/2025

! Problem Statement:

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of 
the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

? Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

? Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

? Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


! Constraints:
1 <= n, k <= 30
1 <= target <= 1000
*/


//!  CODE :
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n+1][target + 1];
        for(int row[] : dp){
            Arrays.fill(row, -1);
        }
        return solve(n, k, target, dp);
    }

    public int solve(int dice, int faces, int target, int[][] dp){

        // If no dice or negative target left, then valid only if 0 target
        if(dice == 0 || target < 0 ) return target == 0 ? 1 : 0 ; 

        if(dp[dice][target] != -1) return dp[dice][target];

        int ways =0, mod = 1000000007;

        for(int face =1; face <= faces; face++){
            ways = ( ways + solve(dice -1, faces, target - face, dp)) % mod;
        }

        return dp[dice][target] = ways; // Store result in DP table
    }
}