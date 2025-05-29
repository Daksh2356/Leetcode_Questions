/*
!  Weekly Contest 451 - Question 2 ( Medium )

? Resutlant String After Adjacent Removals

You are given a string s consisting of lowercase English letters.

You must repeatedly perform the following operation while the string s has at least two consecutive characters:

Remove the leftmost pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
Shift the remaining characters to the left to fill the gap.
Return the resulting string after no more operations can be performed.

Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.

! Example 1:

Input: s = "abc"

? Output: "c"

* Explanation:
* Remove "ab" from the string, leaving "c" as the remaining string.
* No further operations are possible. Thus, the resulting string after all possible removals is "c".

! Example 2:

Input: s = "adcb"

? Output: ""

* Explanation:
* Remove "dc" from the string, leaving "ab" as the remaining string.
* Remove "ab" from the string, leaving "" as the remaining string.
* No further operations are possible. Thus, the resulting string after all possible removals is "".

! Example 3:

Input: s = "zadb"
? Output: "db"

* Explanation:
* Remove "za" from the string, leaving "db" as the remaining string.
* No further operations are possible. Thus, the resulting string after all possible removals is "db".


Constraints:
? 1 <= s.length <= 10^5
? s consists only of lowercase English letters.

*/
class Solution {
    public String resultingString(String s) {
        
        StringBuilder str = new StringBuilder();

        for(char ch : s.toCharArray()){
            int n = str.length();
            if(n > 0 && areConsecutive(str.charAt(n-1), ch)){
                str.deleteCharAt(n-1);
            } else{
                str.append(ch);
            }
        }

        return str.toString();
    }

    private boolean areConsecutive( char a, char b){
        int diff = Math.abs(a-b);
        return diff == 1 || diff == 25;
    }
}
