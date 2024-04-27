/*

Question : 931. Minimum Falling Path Sum
Date : 27-04-24
Problem Difficulty level : Medium
Related Topics : Array, Dynammic Programming and Matrix

Problem Statement:
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 
 
Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // number of rows in matrix
        // dp vector to store the sum of elements till a specific matrix cell
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dp[0][i] =matrix[0][i]; // first row of dp is filled from first row of matrix
        }

        for (int i = 1; i < n; ++i) { // remaining rows
            for (int j = 0; j < n; ++j) { // all columns
                int min_prev = dp[i-1][j];
                if(j>0) min_prev = min(min_prev, dp[i-1][j-1]); // upper left cell
                if(j<n-1) min_prev = min(min_prev, dp[i-1][j+1]);  // upper right cell

                dp[i][j] = min_prev + matrix[i][j];  // updating the DP vector
            }
        }

        // last row of dp array has the final fall path sums from each row
        // finding minimum element
        return *min_element(dp[n - 1].begin(), dp[n - 1].end()); 

        // time complexity = O(n^2)
        // space complexity = O(n^2)
    }
};