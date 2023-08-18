/*

Question : 542. 01 Matrix
Date : 17-08-23
Problem Difficulty level : Medium
Related Topics : Matrix, Dynammic Programming and Breadth First Search

Problem Statement:
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())
        {
            return {};
        }

        int m = mat.size();
        int n = mat[0].size();
        int MAX_VALUE = m*n;

        queue<pair<int,int>> queue; // for keeping the visited values from the matrix

        for(int i=0; i<m ;i ++ )
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                queue.push({i,j});
                else
                mat[i][j] = MAX_VALUE;
            }
        }


        vector<pair<int,int>> neighbours = {{1,0},{-1,0},{0,1},{0,-1}}; // for neighbours

        while(!queue.empty())
        {
            auto[row, col] = queue.front();
            queue.pop();

            for(auto[nr , nc] : neighbours)  // check at top, bottom, left and right pos
            {
                int r = row + nr ;  // effective row
                int c = col + nc;  // effective col

                if(r>=0 && r<m && c>=0 && c<n && mat[r][c] > mat[row][col] + 1)
                {
                    queue.push({r,c});     // pushing unvisited values into the queue
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }

        return mat;
    }
    // time complextiy = O(m*n)
    // space complextiy = O(m*n)
};