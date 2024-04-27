/*

Question : 1289. Minimum Falling Path Sum II
Date : 26-04-24
Problem Difficulty level : Hard
Related Topics : Array, Dynammic Programming and Matrix

Problem Statement:
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent 
rows are in the same column.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:
Input: grid = [[7]]
Output: 7
 
Constraints:
n == grid.length == grid[i].length
1 <= n <= 200
-99 <= grid[i][j] <= 99

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();  // number of rows in grid
        // dp vector to store the sum of elements till a specific grid cell
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dp[0][i] =
                grid[0][i]; // first row of dp is filled from first row of grid
        }

        for (int i = 0; i < n - 1; ++i) { // first to (n-1)th row
            for (int j = 0; j < n; ++j) { // first to last col
                for (int k = 0; k < n; ++k) {  // for checking same column condition
                    if( k!=j){
                        int sum = dp[i][j] + grid[i+1][k];
                        dp[i+1][k] = min(dp[i+1][k], sum);
                    }
                }
            }
        }

        // last row of dp array has the final fall path sums from each row
        auto ans = min_element(dp[n-1].begin(), dp[n-1].end());  // finding minimum element

        return *ans;

        // time complexity = O(n^3)
        // space complexity = O(n^2)
    }
};