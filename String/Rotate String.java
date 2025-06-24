/*
Question: 796. Rotate String
Problem Difficulty level : Easy
Related Topics : String and String Matching

Problem Statement:

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

Constraints:
1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/

code:

class Solution {
    public static int[] computeLPS(String s) {
        int m = s.length();
        int[] lps = new int[m];
        int i = 1;
        lps[0] = 0;
        int len = 0; // behaves like j pointer in the "KMP" implementation

        while (i < m) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    public boolean rotateString(String s, String goal) {
        int n = s.length();
        int m = goal.length();
        if(n !=m)
            return false;

        String s1 = s + s;
        n = s1.length();

        int[] lps = computeLPS(goal);
        int i=0, j=0;
        
        while(i<n){
            if(s1.charAt(i) == goal.charAt(j)){
                i++;
                j++;
                
                if(j == m){
                    return true;
                }
            }
            
            else {
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        
        return false;
        
        // time complexity = O(m) + O(n)
        // space complexity = O(m)
    }
}