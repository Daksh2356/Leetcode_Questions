/*
Question : 459. Repeated Substring Pattern
Date : 21-08-23
Problem Difficulty level : Easy
Related Topics : String and String Matching
Problem Statement:
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        int n = s.size()*2;
        str.erase(str.begin()+0);
        str.erase(n - 2 , 1);

        int pos = str.find(s);

        if (pos == -1)
        return false;
        else return true;
    }

    // time complexity  = O(n)
    // space complexity  = O(n)


};