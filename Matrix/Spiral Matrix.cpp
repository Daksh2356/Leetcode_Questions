/*
!Question : 54. Spiral Matrix
?Date : 26-02-25
Problem Difficulty level : Medium
Related Topics : Array, Matrix, Simulation

Problem Statement:
!Given an m x n matrix, return all elements of the matrix in spiral order.
 
Example 1:
* Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
* Output: [1,2,3,6,9,8,7,4,5]

Example 2:
* Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
* Output: [1,2,3,4,8,12,11,10,9,5,6,7]


! Constraints:
? m == matrix.length
? n == matrix[i].length
? 1 <= m, n <= 10
? -100 <= matrix[i][j] <= 100

*/
// solution 1 :
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] seen = new boolean [m][n];

         // Edge case: if matrix is empty
        if (m == 0)
            return list;

        int r = 0, c = 0;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,0-1,0};

        int di = 0;

        for(int i=0; i<m*n; i++){
            list.add(matrix[r][c]);

            seen[r][c] = true;
            int newRow = r + dr[di];
            int newCol = c + dc[di];
            if(  0<= newRow && newRow<m && 0<=newCol && newCol<n && !seen[newRow][newCol]){
                r = newRow;
                c = newCol;
            }
            else{
                    di = (di+1)%4;
                    r += dr[di];
                    c += dc[di];
            }

        }

        return list;
    }

    // time complexity = O(M*N)
    // space complexity = O(M*N)
}


// solution 2: more optimized

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;

         // Edge case: if matrix is empty
        if (m == 0)
            return list;

        int r = 0, c = 0;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        int di = 0;

        for(int i=0; i<(m*n); i++){
            list.add(matrix[r][c]);
            matrix[r][c] = Integer.MIN_VALUE;

            int newRow = r + dr[di];
            int newCol = c + dc[di];
            if(  0<= newRow && newRow<m && 0<=newCol && newCol<n && 
            matrix[newRow][newCol] != Integer.MIN_VALUE){
                r = newRow;
                c = newCol;
            }
            else{
                    di = (di+1)%4;
                    r += dr[di];
                    c += dc[di];
            }

        }

        return list;
    }

    // time complexity = O(M*N)
    // space complexity = O(1)
}