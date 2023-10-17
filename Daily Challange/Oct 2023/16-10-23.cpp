/*
Question : 119. Pascal's Triangle II
Date : 16-10-23
Problem Difficulty level : Easy
Related Topics : Array and Dynamic Programming
Problem Statement:

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]


Constraints:
0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

*/

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> answer;
        int n = rowIndex;
        int x = 0;
        answer.push_back(1);

        for (int i = 1; i <= n; i++)
        {
            x = (int)(((long long)answer.back() * (n - i + 1)) / (i));
            answer.push_back(x);
        }

        return answer;
    }

    //  Time complexity = O(rowIndex)
    //  Space complexity = O(rownIndex)
};