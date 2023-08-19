/*
Question :74. Search a 2D Matrix
Date : 07-08-23
Problem Difficulty level : Medium
Related Topics : Array, Matrix and Binary Search 

Problem Statement:
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m*n - 1;
        while(low<=high)
        {
            int mid = (low + high) / 2;
            int midValue =  matrix[mid/n][mid%n];
            if( midValue == target)
            return true;
            else if(midValue < target)
            low = mid + 1;
            else high = mid - 1;

        }
        return false;
    }
    // time complexity = O(log(m*n))
    // space complexity = O(1)
};