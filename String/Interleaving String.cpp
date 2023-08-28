/*
Question : 97. Interleaving String
Date : 25-08-23
Problem Difficulty level : Medium
Related Topics : String and DP

Problem Statement:
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
        return false;

        if(s1.length() < s2.length())
        {
            swap(s1,s2);
        }

        vector<bool> dp ( s2.length() + 1 , false);
        dp[0] = true;

        for(int j=1; j<=s2.length();j++)
        {
            dp[j] = dp[j-1] && (s2[j-1] == s3[j-1]);
        }

        for(int i=1 ; i<=s1.length() ; i++)
        {
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);

            for(int j=1; j<=s2.length();j++)
            {
                dp[j] = (dp[j] && (s1[i-1] == s3[i+j-1])) || 
                          ( dp[j-1] && (s2[j-1] == s3[i+j-1]) );
            }
        }

        return dp[s2.length()];

    }

    // time complexity =  O(s1.length() * s2.length())
    // space complexity =  O(s2.length())
};