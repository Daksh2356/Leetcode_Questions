/*

Question : 70. Climbing Stairs
Date : 11-02-24
Problem Difficulty level : Easy
Related Topics : Math, Dynammic Programming and Memoization

Problem Statement:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

// Solution 1 :
class Solution
{
public
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;

        int dp[] = new int[n];
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }

    // space = O(n)
    // time = O(n)
}

// Solution 2 :
class Solution
{
public
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;

        int prev1 = 1;
        int prev2 = 2;
        int curr = 0;

        for (int i = 3; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }

    // space = O(1)
    // time = O(n)
}