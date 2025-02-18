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
    public String sorting(String str){
        char[] charArr = str.toCharArray(); // breaking string into group of characters
        Arrays.sort(charArr);  // sorting the array of characters from string
        
        return new String(charArr); // returning a string made of characters
    }
    
    public boolean isAnagram(String s, String t) {
        s = s.trim();   // trim() removes all whitespace characters
        t = t.trim();
        
        if(s.length() != t.length())   
        return false;  // anagrams must be of same length!
        
        return sorting(s).equals(sorting(t)); // sorting method invoked
    }
    
    // time complexity = O(nlogn) -> sorting
    // space complexity = O(n) -> storage of character array and new strings
};