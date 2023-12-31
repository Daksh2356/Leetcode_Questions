/*
Question :518. Coin Change II
Date : 11-08-23
Problem Difficulty level : Medium
Related Topics : Array and Dynamic Programming

Problem Statement:
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=0;i<coins.size();i++)
        {
            int coinValue = coins[i];
            for(int j=coinValue;j<=amount;j++)
            {
                dp[j] += dp[j-coinValue];
            }
        }
        return dp[amount];
    }

    // time complexity =O(amount*n)
    // space complexity = O(n)
};