/*
Question : 63. Unique Paths II
Date : 12-08-23
Problem Difficulty level : Medium
Related Topics : Array, Dynamic Programming and Matrix

Problem Statement:
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1 )
        return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> previous(n,0);
        vector<int> current(n,0);
        previous[0] = 1;


        for( int i = 0 ; i<m ; i++)
        {
            current[0] = obstacleGrid[i][0] == 1 ? 0 : previous[0];
            for( int j = 1; j < n; j++ )
            {
                current[j] = obstacleGrid[i][j] == 1 ? 0 : current[j-1] + previous[j];
            }
            previous = current;
        }

        return previous[n-1];
    }

    // time complexity = O(m*n)
    // space complexity = O(n)
};