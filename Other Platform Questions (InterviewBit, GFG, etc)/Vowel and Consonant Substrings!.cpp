// Problem Description
 
// Given a string A consisting of lowercase characters.

// You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.

// Return the count of substring modulo 109 + 7.

// Problem Constraints:
// 1 <= |A| <= 10^5

// A consists only of lower-case characters.


// Input Format
// First argument is an string A.

// Output Format
// Return a integer denoting the the number of substrings in A which starts with vowel and end with consonants or vice-versa with modulo 109 + 7.



// Example Input
// Input 1:

//  A = "aba"
// Input 2:

//  A = "a"


// Example Output
// Output 1:

//  2
// Output 2:

//  0


// Example Explanation
// Explanation 1:
//  Substrings of S are : [a, ab, aba, b, ba, a]Out of these only 'ab' and 'ba' satisfy the condition for special Substring. 
// So the answer is 2.

// Explanation 2:
//  No possible substring that start with vowel and end with consonant or vice-versa.


// code : 
int Solution::solve(string A) {
    
    int count = 0, consonant = 0, vowel = 0;
    const int MOD = 1000000000 + 7;
    
    for(char c : A){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel++;
        else
         consonant ++;
        
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count = (count + consonant) % MOD;
        else 
            count = (count + vowel) % MOD;
    }
    
    return count;
    
    // time complexity = O(n)
    // space complexity = O(1)
}
