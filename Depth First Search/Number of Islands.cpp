/*

Question : 200. Number of Islands
Date : 19-04-24
Problem Difficulty level : Medium
Related Topics : Matrix, Depth First Search, Breadth First Search, Union Find, Array

Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the 
grid are all surrounded by water.
 

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {  
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1'){   // if 'land' is encountered
                        ans +=1;   // increase the number of islands by '1'
                        dfs(grid, i, j);  // check for all the adjacent cells
                    }
            }
        }

        return ans;  // output variable => total number of islands


        // time complexity = O(m*n) 
        // space complexity = O(m*n) [ ]space of call stack ]
        // where 'm' and 'n' are number of rows and cols of grid/ stack respectively

    }

    void dfs(vector<vector<char>>& A, int i , int j){

        // check for all the boundary conditions and already visited cell
        if(i<0 || i>=A.size() || j<0 || j>=A[0].size() || A[i][j] == '0') 
            return;
        
        A[i][j] = '0';  // make the cell as 'visited'

        dfs(A,i-1,j);  // Up
        dfs(A,i+1,j);  // Down
        dfs(A,i,j-1);  // Left
        dfs(A,i,j+1);  // Right
    }
};