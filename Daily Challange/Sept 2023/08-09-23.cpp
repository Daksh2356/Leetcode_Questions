/*
Question : 118. Pascal's Triangle
Date : 08-09-23
Problem Difficulty level : Easy
Related Topics : Array and DP

Problem Statement:

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown in examples below :

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:

1 <= numRows <= 30

*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> dp(numRows);

        for (int i = 0; i < numRows; i++)
        {
            dp[i].resize(i + 1);
            dp[i][0] = 1;
            for (int j = 1; j <= i; j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }

        return dp;
    }

    // time complexity = O(numRows*2)
    // space complexity = O(numRows*2)
};
