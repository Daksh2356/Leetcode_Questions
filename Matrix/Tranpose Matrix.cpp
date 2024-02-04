/*
Question : 867. Transpose Matrix
Date : 03-02-24
Problem Difficulty level : Easy
Related Topics : Array, Matrix and Simulation
Problem Statement:
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-10^9 <= matrix[i][j] <= 10^9

*/
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();

        vector<vector<int>> result(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][i] = A[i][j];
            }
        }

        return result;
    }
};