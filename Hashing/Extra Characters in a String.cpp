/*
Question :2707. Extra Characters in a String
Date : 02-09-23
Problem Difficulty level : Medium
Related Topics : Array, Hash Table, String, Dynamic Programming and Trie
Problem Statement:
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping 
substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in 
any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 
Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. 
There is only 1 unused character (at index 4), so we return 1.

Constraints:
1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words


*/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        int max_value = n+1;
        vector<int> dp (n+1,max_value);
        dp[0] = 0;

        for(int i =1; i<=n;i++)
        {
            dp[i] = dp[i-1] + 1;
            for(int j=0; j<i;j++)
            {
                if (find(dictionary.begin(), dictionary.end(), s.substr(j, i - j))
                !=dictionary.end())
                {
                    dp[i] = min(dp[i] , dp[j]);
                }
            }
        }

        return dp.back();
    }
    //  time complexity is O(n^3)
    //  space complexity is O(n)
};