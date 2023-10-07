/*
Question : 343. Integer Break
Date : 08-10-23
Problem Difficulty level : Medium
Related Topics : Math and Dynammic Programming
Problem Statement:
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.


Constraints:
2 <= n <= 58
*/

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];

        // time complexity = O(n^2)
        // space complexity = O(n)
    }
};