/*
Question : 1631. Path With Minimum Effort
Date : 16-09-23
Problem Difficulty level : Medium
Related Topics : Array, Binary Search, DFS, BFS, Heap ( Priority Queue), Union Find and Matrix
Problem Statement:

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] 
represents the height of cell (row, col). 

You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 10^6

*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(); // m
        int cols = heights[0].size(); // n
        vector<vector<int>> dist (rows, vector<int> (cols, INT_MAX));  
        // space and time for dist 2d vector/graph is = O(m*n)
        priority_queue <tuple<int,int,int> , vector<tuple<int,int,int>>, greater<>> minHeap; 
        // time is O(1) and space is O(m*n)
        minHeap.emplace(0,0,0);
        dist[0][0] = 0;

        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!minHeap.empty()) 
        // O(m * n * log(m * n)) for the operations involving the priority queue.
        {
            auto[effort,x,y] = minHeap.top();
            minHeap.pop();

            if(effort > dist[x][y]) continue;

            if(x== rows-1 && y== cols-1) return effort;

            for(auto& dir: directions)
            {
                int nx = x + dir[0] , ny = y + dir[1];
                if(nx >=0 && nx<rows && ny>=0 && ny<cols)
                {
                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if(new_effort < dist[nx][ny])
                    {
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }
        return -1;
    }

    // time complexity = O(m*n*log(m*n))
    // space complexity = O(m*n)
};
