/*
Question : 746. Min Cost Climbing Stairs
Date : 19-09-23
Problem Difficulty level : Easy
Related Topics : Array and DP

Problem Statement:
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or
two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999

*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 2, 0); // initially, we assume the cost for each step to be 0

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
            // min cost is the sum of cost of the current step and the minimum cost    of          reaching the next two steps.
        }

        return min(dp[0], dp[1]);
    }
    // time is O(N)
    // space is O(N)
};