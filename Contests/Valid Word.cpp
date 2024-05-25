/*
Question : 3136. Valid Word  ( contest 396 q1 )
Date : 05-05-24
Problem Difficulty level : Easy
Related Topics : String

Problem Statement:

A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 
Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.


Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

*/

class Solution {
public:
    bool isValid(string word) {
        bool hasDigit = false;
        bool hasUpperCase = false;
        bool hasLowerCase = false;
        bool hasVowel = false;
        bool hasConsonant = false;
        bool hasExtra = false;
        
        if(word.length() < 3)
            return false;
        
        for(char c : word){
            
            if(isdigit(c))
                hasDigit = true;
            
            if(isupper(c))
                hasUpperCase = true;
            
            if(islower(c))
                hasLowerCase  =true;
            
            if(tolower(c) == 'a' || tolower(c)=='e' ||  tolower(c)=='i' ||  tolower(c)=='o' ||  tolower(c)=='u'){
                hasVowel = true;
            }
            else if(isalpha(c))
                hasConsonant = true;
            else if(!isdigit(c) && !isalpha(c))
                hasExtra = true;
        }
        
        return (hasDigit || hasUpperCase || hasLowerCase) && hasVowel && hasConsonant && !hasExtra;
    }
};