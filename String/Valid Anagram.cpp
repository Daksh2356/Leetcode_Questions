/*
! Question: 242. Valid Anagram
* Problem Difficulty level : Easy
? Related Topics : String, Hash Table, Sorting

Problem Statement:

! Given two strings s and t, return true if t is an anagram of s, and false otherwise.

? Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

? Example 2:
Input: s = "rat", t = "car"
Output: false
 
? Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

? Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/


//!  CODE :

class Solution {
    public:
    
        string removews(string s){
            string res = "";
    
            for(char ch : s){
                if(ch != ' ')
                    res+=ch;
            }
    
            return res;
        }
    
        string sorting(string str){
            sort(str.begin(), str.end());
            return str;
        }
    
    
        bool isAnagram(string s, string t) {
            s = removews(s);
            t = removews(t);
    
            s = sorting(s);
            t = sorting(t);
    
            bool ans =( s == t);
            return ans;

        }

         // time complexity = O(nlogn) -> sorting
         // space complexity = O(n) -> creating new strings
};
