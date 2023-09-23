/*
Question : 392. Is Subsequence
Date : 22-09-23
Problem Difficulty level : Easy
Related Topics: Two pointers, String and DP
Problem Statement:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the
characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde"
while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        int j = 0;

        while (i < t.length() && j < s.length())
        {
            if (t[i] == s[j])
                j++;

            i++;
        }

        return j == s.length();
    }

    // time complexity = O(n) where 'n' is t.length()
    // space complexity = O(1) -> constant space is used
};

// For follow up
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = true;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
    // time complexity = O(m*n)
    // space complexity = O(m*n)
};