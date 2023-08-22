/*
Question : 171. Excel Sheet Column Number
Date : 22-08-23
Problem Difficulty level : Easy
Related Topics : String and Math
Problem Statement:
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

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
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701

*/

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (char c : columnTitle)
        {
            int digit = c - 'A' + 1;
            ans = ans * 26 + digit;
        }

        return ans;
    }

    // time complexity = O(length)
    // space complexity = O(1)
};