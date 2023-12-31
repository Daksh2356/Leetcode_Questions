/*
Question : 168. Excel Sheet Column Title
Date : 22-08-23
Problem Difficulty level : Easy
Related Topics : String and Math
Problem Statement:
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"
*/

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            int rem = (columnNumber - 1) % 26;
            char letter = 'A' + rem;
            ans = letter + ans;
            columnNumber = (columnNumber - 1) / 26;
        }

        return ans;
    }

    // time complexity = O(log(columnNumber))
    // space complexity = O(1)
};