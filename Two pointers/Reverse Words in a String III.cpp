/*
Question : 557. Reverse Words in a String III
Date : 01-10-23
Problem Difficulty level : Easy
Related Topics : Two pointers and String
Problem Statement:
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"

Constraints:
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string str = "";
        string word = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ' || s[i] == '\n')
            {
                reverse(word.begin(), word.end());
                str += word + s[i];
                word = "";
            }
            else
            {
                word += s[i];
            }
        }

        reverse(word.begin(), word.end());
        str += word;

        return str;
    }

    // Time Complexity = O(n)
    // Space Complexity = O(n)
};