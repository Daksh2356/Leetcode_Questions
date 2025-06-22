/*
Date : 17/06/25
Platform : GFG
Track : GFG-160-problems
Problem Difficulty: Easy

Problem Statement:
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.
*Note: The characters in the strings are in lowercase.

Example 1:
Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.

Example 2:
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.

Constraints:
1 ≤s1.size(), s2.size()≤ 10^5
*/

code :


class Solution {
    // Function to check if two strings are rotations of each other or not.
    public static int[] computeLPS(String s){
        int m = s.length();
        int[] lps = new int[m];
        int i=1;
        lps[0] = 0;
        int len =0; // behaves like j pointer in the "KMP" implementation
        
        while(i<m){
            if(s.charAt(i) == s.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    public static boolean areRotations(String s1, String s2) {
        String s3 = s1 + s1;
        int n = s3.length();
        int m = s2.length();
        int[] lps = computeLPS(s2);
        int i=0, j=0;
        
        while(i<n){
            if(s3.charAt(i) == s2.charAt(j)){
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