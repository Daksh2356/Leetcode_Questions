/*
 Date : 12/06/25
 Platform : GFG
 Track : GFG-160-problems

Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

?Examples:

Input: s = "geeksforgeeks"
?Output: 'f'
*Explanation: In the given string, 'f' is the first character in the string which does not repeat.

Input: s = "racecar"
?Output: 'e'
*Explanation: In the given string, 'e' is the first character in the string which does not repeat.

Input: s = "aabbccc"
?Output: -1
*Explanation: All the characters in the given string are repeating.


! Constraints:
! 1 ≤ s.size() ≤ 10^5

*/

code:


class Solution {
    static char nonRepeatingChar(String s) {
        int[] freq = new int[26];
        for(Character ch : s.toCharArray()){
            freq[ch-'a']++;
        }
        
        for(Character ch : s.toCharArray()){
            if(freq[ch - 'a'] == 1)
                return ch;
        }
        
        
        return '$';
    }
}


// time complexity = O(n) + O(n) => O(2n)
// space complexity = O(1)

// approach 2: (optimized)

class Solution {
    private static final int MAX_CHAR = 26;
    
    static char nonRepeatingChar(String s) {
        int[] visited = new int[MAX_CHAR];
        Arrays.fill(visited, -1);
        
        for(int i=0; i<s.length(); i++){
            int idx = s.charAt(i) - 'a';
            if(visited[idx] == -1){
                visited[idx] = i;
            }else{
                visited[idx] = -2;
            }
        }
        
        int minIdx = Integer.MAX_VALUE;
        for(int i=0; i<MAX_CHAR; i++){
            if(visited[i] >=0 ){
                minIdx = Math.min(minIdx, visited[i]);
            }
        }
        
        return minIdx == Integer.MAX_VALUE ? '$' : s.charAt(minIdx);
        
        // time complexoty = O(n) + O(26) => O(n)
        // space complexity O(26) => O(1)
    }
}
