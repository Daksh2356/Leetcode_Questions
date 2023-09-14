/*
Question : 1647. Minimum Deletions to Make Character Frequencies Unique
Date : 12-09-23
Problem Difficulty level : Medium
Related Topics : Hash Table, String, Greedy and Sorting

Problem Statement:
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string.

For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.


Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).

Constraints:
1 <= s.length <= 10^5
s contains only lowercase English letters.
*/

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> fmap;

        for (char c : s)
        {
            fmap[c]++;
        }

        unordered_set<int> fset;

        int deletions = 0;

        for (auto &entry : fmap)
        {
            int f = entry.second;
            while (fset.count(f) > 0)
            {
                f--;
                deletions++;
            }

            if (f > 0)
            {
                fset.insert(f);
            }
        }

        return deletions;
    }
    // time complexity = O(n^2)
    // space complexity = O(n)
};