/*
Question : 214. Shortest Palindrome
Date : 22-06-25
Problem Difficulty level : Hard
Related Topics : String, Rolling Hash, String Matching and Hash Function

Problem Statement :
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

? Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

? Example 2:
Input: s = "abcd"
Output: "dcbabcd"

Constraints:
!0 <= s.length <= 5 * 10^4
!s consists of lowercase English letters only.

*/

class Solution {

    private static int[] computeLPS(String s) {
        int len = 0;
        int i = 1;
        int m = s.length();
        int[] lps = new int[m];
        lps[0] = 0;

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

    public String shortestPalindrome(String s) {
        int n = s.length();
        String reversed = new StringBuilder(s).reverse().toString();
        String combined = s + '$' + reversed;

        int[] lps = computeLPS(combined);
        int charsToAdd = n - lps[lps.length - 1];

        String prefixToAdd = reversed.substring(0, charsToAdd);
        return (prefixToAdd + s);
    }

    // time = O(n)
    // space = O(n)
}