/*
Question  14. Longest Common Prefix
Date : 04-04-24
Problem Difficulty level : Easy
Related Topics : String

Problem Statement:
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
class Solution {
public:

    int findMinLength ( vector<string>& strs)
    {
        int minLength = strs[0].length();
        for(int i = 1 ; i <strs.size(); i++ )
        {
            if( minLength > strs[i].length())
            {
                minLength = strs[i].length();
            }
        }
        return minLength;
    }

    string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
     int n = strs.size();
     int minlen = findMinLength(strs);

     for(int i =0 ; i<minlen; i++)
     {
         char ch = strs[0][i];
         for(int j=0; j< n ; j++)
         {
             if(ch != strs[j][i])
             {
                return ans;
             } 
         }
         ans.push_back(ch);
     }
     return ans;

    }
};