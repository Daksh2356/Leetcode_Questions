/*
!  Question 322: Coin Change
* Problem Difficulty level : Medium
? Related Topics : Array, Dynammic Programming and Breadth-First Search
? Date : 17/03/2025

! Problem Statement:

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of 
money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of 
the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

? Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

? Example 2:
Input: coins = [2], amount = 3
Output: -1

? Example 3:
Input: coins = [1], amount = 0
Output: 0

! Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/


//!  CODE :
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); // Fill with a large number (unreachable state)
        dp[0] = 0; // Base case: No coins needed for sum 0

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = Math.min(dp[j], dp[j - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount]; // If no valid solution, return -1
    }
}
