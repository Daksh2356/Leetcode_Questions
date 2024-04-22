/*

Question : 1992. Find All Groups of Farmland
Date : 20-04-24
Problem Difficulty level : Medium
Related Topics : Array, Matrix, Depth First Search and Breadth First Search

Problem Statement:
You are given a 0-indexed m x n binary matrix land where a '0' represents a hectare of forested land and a '1' represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are 
called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different 
group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is 
(m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner 
at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland,
return an empty array. You may return the answer in any order.

 
Example 1:
Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

Example 2:
Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].

Example 3:
Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.
 

Constraints:
m == land.length
n == land[i].length
1 <= m, n <= 300
land consists of only 0's and 1's.
Groups of farmland are rectangular in shape.
*/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();

        unordered_set<string> visited; // for visited farmlands
        vector<vector<int>> result;    // output variable

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (land[i][j] == 1 &&
                    visited.find(to_string(i) + "," + to_string(j)) ==
                        visited.end()) {
                    vector<int> bounds = dfs(land, visited, i, j);
                    result.push_back(bounds);
                }
            }
        }
        return result;
    }

    vector<int> dfs(vector<vector<int>>& land, unordered_set<string>& visited,
                    int x, int y) {
        stack<pair<int, int>> s;
        s.push({x, y}); // current coordinates are pushed
        visited.insert(to_string(x) + "," +
                       to_string(y)); // curr are marked too

        int maxR = x; int maxC = y;
        int minR = x; int minC = y;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while (!s.empty()) {     // till end of stack
            auto curr = s.top(); // top most pair is popped
            s.pop();

            int currX = curr.first;
            int currY = curr.second;

            for (auto& dir : directions) {
                int nx = currX + dir.first;
                int ny = currY + dir.second;

                if (nx >= 0 && nx < land.size() && ny >= 0 &&
                    ny < land[0].size() && land[nx][ny] == 1 &&
                    visited.find(to_string(nx) + "," + to_string(ny)) ==
                        visited.end()) {
                    s.push({nx, ny});
                    visited.insert(to_string(nx) + "," + to_string(ny));
                    maxR = max(maxR, nx);
                    maxC = max(maxC, ny);
                    minR = min(minR, nx);
                    minC = min(minC, ny);
                }
            }
        }

        return {minR, minC, maxR, maxC};

        //the time complexity is O(M * N * A), 
        // and the space complexity is O(M * N), 
        // where M is the number of rows, N is the number of columns, 
        // and A is the average size of each farmland area.
    }
};