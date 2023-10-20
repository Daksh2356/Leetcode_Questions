/*
Question : 844. Backspace String Compare
Date : 19-10-23
Problem Difficulty level : Easy
Related Topics : String, Stack, Two pointers and Simulation
Problem Statement:
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Follow up: Can you solve it in O(n) time and O(1) space?

*/
class Solution
{
public:
    int nextChar(string str, int curr) // time taken is O(n)
    {
        while (curr > -1 && str[curr] == '#')
        {
            int count = 1;
            curr--;
            while (curr > -1 && count > 0)
            {
                if (str[curr] == '#')
                    count++;
                else
                    count--;
                curr--;
            }
        }
        return curr;
    }

    bool backspaceCompare(string s, string t)
    { // time - O(n) for nextChar function()
        int i = nextChar(s, s.length() - 1);
        int j = nextChar(t, t.length() - 1);

        while (i > -1 && j > -1)
        {
            if (s[i] != t[j])
                return false;

            i = nextChar(s, i - 1);
            j = nextChar(t, j - 1);
        }

        return i == -1 && j == -1;
    }

    // Time complexity = O(n) => Linear time taken
    // Space complexity = O(1) => Constant space used
};