/*
Question : 73. Set Matrix Zeroes
Date : 31-01-24
Problem Difficulty level : Medium
Related Topics: Array, Hash Table, Matrix

Problem Statement:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++)
        {

            //  checking first col
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < C; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //  check for values of 0 in other cells
        for (int i = 1; i < R; i++)
        {
            for (int j = 1; j < C; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // setting first row

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < C; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // setting first col

        if (isCol)
        {
            for (int i = 0; i < R; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }

    // time complexity = O(m*n)
    // space complexity = O(1)
};