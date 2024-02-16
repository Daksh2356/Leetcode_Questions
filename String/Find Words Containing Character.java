/*
Question : 2942. Find Words Containing Character
Date : 15-02-24
Problem Difficulty level : Easy
Related Topics : Array, String
1 <= words.length <= 50
1 <= words[i].length <= 50
x is a lowercase English letter.
words[i] consists only of lowercase English letters.

*/
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> arr = new ArrayList<Integer>();
        int n = words.length;
        for(int i=0; i<n; i++){
            if(words[i].indexOf(x) != -1 ){
                arr.add(i);
            }
        }

        return arr;
    }

    // time complexity = O(n*m) => n is no of words and m is avg len of words
    // space complexity = O(n) => n is no of words ( worst case) / O(k) 
}