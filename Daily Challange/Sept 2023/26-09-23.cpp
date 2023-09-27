/*
Question : 316. Remove Duplicate Letters
Date : 26-09-23
Problem Difficulty level : Medium
Related Topics: String, Set, Stack, Monotonic Stack, Hash Map, Greedy
Problem Statement:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> stk;
        unordered_set<char> seen;          // space - O(n) for both map and set, where n is size of string
        unordered_map<char, int> last_occ; // space - O(k) where 'k' is number of distinct characters in string s

        for (int i = 0; i < s.size(); i++) // mapping each char of s to it's last index
        {
            last_occ[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (seen.find(c) == seen.end()) // check if set has the current char or not
            {
                while (!stk.empty() && c < stk.top() && i < last_occ[stk.top()])
                {
                    seen.erase(stk.top()); // if top is larger, remove it from set and stack
                    stk.pop();
                }

                seen.insert(c); // else add current character to set and stack
                stk.push(c);
            }
        }

        string res = "";

        while (!stk.empty())
        {
            res = stk.top() + res; // char at top of stack is added to the result string
            stk.pop();
        }

        return res;
    }
    // Time Complexity = O(n^2)
    // Space Complexity = O(n+k)
};