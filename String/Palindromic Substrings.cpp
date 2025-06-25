/*
Question : 647. Palindromic Substrings
Date : 16-02-24
Problem Difficulty level : Medium
Related Topics : String, DP
Problem Statement:

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // length 1 palindromes
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }

        // length 2 palindromes
        for (int i = 0; i < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                count++;
            }
        }

        // more than length 2 palindromes
        for (int len = 3; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;
                if (s[start] == s[end] && dp[start + 1][end - 1])
                {
                    dp[start][end] = true;
                    count++;
                }
            }
        }

        return count;
    }

    // time = O(n^2)
    // space = O(n^2)
};


// another approach (with constant space)
class Solution {
public:
    int expandAroundCenter(string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            count += expandAroundCenter(s, i, i);     // Odd length
            count += expandAroundCenter(s, i, i + 1); // Even length
        }

        return count;
    }
    
    // time = O(n^2) [worst-case]
    // space = O(1)
};