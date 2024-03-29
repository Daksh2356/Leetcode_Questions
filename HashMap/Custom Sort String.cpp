/*
Question : 791. Custom Sort String
Date : 11-03-24
Problem Difficulty level : Medium
Related Topics : Hash Table, String and Sorting
Problem Statement:
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before 
y in the permuted string.

Return any permutation of s that satisfies this property.

Example 1:
Input:  order = "cba", s = "abcd" 
Output:  "cbad" 
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input:  order = "bcafg", s = "abcd" 
Output:  "bcad" 
Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.
Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. 
The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.


Constraints:
1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.
*/

class Solution {
    public String customSortString(String order, String s) {
        int map[] = new int[26];
        StringBuilder str = new StringBuilder();

        for(int i=0; i<s.length(); i++){
            map[s.charAt(i) - 'a']++;
        }

        for(int i=0; i<order.length(); i++){
            for(int j=0; j<map[order.charAt(i) - 'a']; j++){
                str.append(order.charAt(i));
            }

            map[order.charAt(i)-'a'] = 0;
        }

        for(int i=0; i<26; i++){
            for(int j=0; j<map[i]; j++){
                str.append((char) ('a' + i));
            }
        }

        return str.toString();
    }

    // time complexity = O(n + m) where n = s.length() and m = order.length()
    // space complexity = O(1)  [the map is of a constant size of 26 ]
}
