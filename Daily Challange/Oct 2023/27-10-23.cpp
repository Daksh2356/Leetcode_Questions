/*
Question: 5. Longest Palindromic Substring
Date : 27-10-23
Problem Difficulty level : Medium
Related Topics : String and Dynamic Programming
Problem Statement:

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"


Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s; // Handle base case

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp to store palindromes

        int start = 0;     // Start of the longest palindromic substring
        int maxLength = 1; // Length of the longest palindromic substring

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length >= 3
        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j])
                {
                    dp[i][j] = true;
                    if (k > maxLength)
                    {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }

    // Time - O(n^2)  => two loops at the end ( k and i variables)
    // Space - O(n^2)  => 2D dp array to store the resutls of shorter palindromic substrs
};
