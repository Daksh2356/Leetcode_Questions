/*
!Question : 59. Spiral Matrix II
?Date : 28-02-25
Problem Difficulty level : Medium
Related Topics : Array, Matrix, Simulation

Problem Statement:
! Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 
Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]


! Constraints:
? 1 <= n <= 20

*/
class Solution {
    public int[][] generateMatrix(int n) {

        int[][] matrix = new int[n][n];
        int num = 1;
        int di = 0;

        int r = 0, c = 0;
        int[] dr = { 0, 1, 0, -1 };
        int[] dc = { 1, 0, -1, 0 };

        for (int i = 0; i < n * n; i++) {
            matrix[r][c] = num++;

            int newRow = r + dr[di];
            int newCol = c + dc[di];

            if (0 <= newRow && newRow < n && 0 <= newCol && newCol < n &&
                    matrix[newRow][newCol] == 0) {
                r = newRow;
                c = newCol;
            } else {
                 di = (di+1)%4;
                 r += dr[di];
                 c += dc[di];
            }
        }

        return matrix;
    }
}