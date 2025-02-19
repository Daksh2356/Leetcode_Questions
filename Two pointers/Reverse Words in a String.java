/*
! Question: 151. Reverse Words in a String
* Problem Difficulty level : Medium
? Related Topics : Two Pointers, String
? Date : 19th Feb 2025

Problem Statement:

! Given an input string s, reverse the order of the words.

! A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

! Return a string of the words in reverse order concatenated by a single space.

* Note that s may contain leading or trailing spaces or multiple spaces between two words. 
* The returned string should only have a single space separating the words. Do not include any extra spaces.

? Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

? Example 2:
Input: s = "  hello world  "
Output: "world hello"
* Explanation: Your reversed string should not contain leading or trailing spaces.

? Example 3:
Input: s = "a good   example"
Output: "example good a"
* Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
? Constraints:
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

?? Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

*/


//!  CODE :
class Solution {
    public String reverseWords(String s) {

    StringBuilder res = new StringBuilder();
    StringBuilder word = new StringBuilder();
    s = s.trim();

    for(int i=s.length()-1; i>=0; i--)
    {
        char ch = s.charAt(i);

        if(ch != ' ')
            word.append(ch);
        else
        {
            if(word.length() > 0)
            {
                if(res.length() > 0)
                {
                    res.append(" ");
                }

                res.append(word.reverse());
                word.setLength(0);
            }
        }
    }
    // Append the last word
    if (word.length() > 0) {
        if (res.length() > 0) {
            res.append(" ");
        }
        res.append(word.reverse());
    }   

    return res.toString();

  }
    // time complexity = O(n)
    // space complexity = O(n)
}