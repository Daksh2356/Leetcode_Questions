// Problem Description
 
// Given a sentence represented as an array A of strings that contains all lowercase alphabets.
// Chech if it is a pangram or not.
// A pangram is a unique sentence in which every letter of the lowercase alphabet is used at least once.

// Problem Constraints
// 1 <= |A| <= 10^5
// 1 <= |Ai|<= 5


// Input Format
// Given an array of strings A.


// Output Format
// Return an integer.


// Example Input
// Input 1:
// A = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]

// Input 2:
// A = ["bit", "scale"]


// Example Output
// Output 1:
// 1

// Output 2:
// 0


// Example Explanation
// Explanation 1:
// We can check that all english alphabets are present in given sentence.

// Explanation 2:
// Not all english alphabets are present.


// code : 
int Solution::solve(vector<string> &A) {
    int map[26] = {0};
    
    for(string str : A){
        for(char ch : str){
            map[ch-'a']++;
        }
    }
    
    bool flag = true;
    
    for(int i=0; i<26; i++){
        if(map[i] == 0){
            flag = false;
            break;
        }
    }
    
    return flag ? 1 : 0;
}
