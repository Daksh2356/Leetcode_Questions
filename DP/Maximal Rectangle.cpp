/*

Question : 85. Maximal Rectangle
Date : 13-04-24
Problem Difficulty level : Hard
Related Topics : Array, Matrix, Dynammic Programming, Stack and Monotonic Stack

Problem Statement:
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
 

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/

// code : 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        if(matrix.empty() || matrix[0].empty() )
            return 0;

        vector<int> heights(cols+1, 0); // for storing the height of histograms

        for(const auto& row : matrix){
            for(int i=0; i<cols; i++){
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0 ;  // only update when
            }                                         // consecutive 1's are found

            stack<int> stk; // stack for calculation of maxArea
            for(int i=0; i<heights.size(); i++){
                while(!stk.empty() && heights[i] < heights[stk.top()]){
                    int h = heights[stk.top()]; // curr height of rectangle formed
                    stk.pop(); // top most index is removed
                    int w = stk.empty() ? i : i - stk.top() -1;  // curr width of rect formed
                    maxArea = max(maxArea, h*w);  // maxArea calculated
                }

                stk.push(i);
            }
        }

        return maxArea;

        // time complexity = O(rows*cols)
        // space complexity = O(cols)
    }
};