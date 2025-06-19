/*
Date : 16/06/25
Platform : GFG
Track : GFG-160-problems
Difficulty: Hard

Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all 
the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

?Examples:

Input: txt = "abcab", pat = "ab"
?Output: [0, 3]
*Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

Input: txt = "abesdu", pat = "edu"
?Output: []
*Explanation: There's no substring "edu" present in txt.

Input: txt = "aabaacaadaabaaba", pat = "aaba"
?Output: [0, 9, 12]
Explanation:
https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/703119/Web/Other/blobid0_1731391225.png

!Constraints:
! 1 ≤ txt.size() ≤ 10^6
! 1 ≤ pat.size() < txt.size()
! Both the strings consist of lowercase English alphabets.
*/

code:
// User function Template for Java

class Solution {
    
    void constructLPS(String pat, int[] lps){
        lps[0] = 0;
        int i = 1;
        int m = pat.length();
        int len = 0;
        
        while(i<m){
            if(pat.charAt(i) == pat.charAt(len)){
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
    }

    ArrayList<Integer> search(String pat, String txt) {
        // your code here
        int n = txt.length();
        int m = pat.length();
        
        int[] lps = new int[m];
        ArrayList<Integer> res = new ArrayList<>();
        
        constructLPS(pat, lps);
        
        int i =0, j=0;
        
        while(i<n){
            if(txt.charAt(i) == pat.charAt(j)){
                i++;
                j++;
                
                if(j == m){
                    
                    res.add(i-j);
                    j = lps[j-1];
                }
                
            }
            else{
                
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        
        return res;
        
    }
}