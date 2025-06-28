/*
Date : 22/06/25
Platform : GFG
Track : GFG-160-problems
Difficulty: Hard

Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

?Examples:
Input: s = "abc"
?Output: 2
*Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

Input: s = "aacecaaaa"
?Output: 2
*Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

!Constraints:
! 1 <= s.size() <= 10^6

*/

code:

class Solution {
    
    public static int[] computeLPS(String s){
        int len = 0;
        int i = 1;
        int m = s.length();
        int[] lps = new int[m];
        lps[0] = 0;
        
        while(i<m){
            if(s.charAt(i) == s.charAt(len)){
                len++;
                lps[i] = len;
                i++;
            }else{
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
    
    public static int minChar(String s) {
       int n = s.length();
       String reversed = new StringBuilder(s).reverse().toString();
       s = s + '$' + reversed;
       
       int[] lps = computeLPS(s);
       
       return n - lps[lps.length-1];
    }
}

// time complexity = O(n)
// space complexity = O(n)