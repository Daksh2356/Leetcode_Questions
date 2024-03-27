/*
INTERVIEW BIT QUESTION

Problem Description
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Problem Constraints
1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20


Input Format
The first argument is a string, A.
The second argument is an array of strings, B.


Output Format
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.

Example Input
Input 1:
A = "myinterviewtrainer",
B = ["trainer", "my", "interview"]

Input 2:
A = "a"
B = ["aaa"]


Example Output
Output 1:
1
Output 2:
0

Example Explanation
Explanation 1:
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Explanation 2:
Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".

*/

// code: 
int Solution::wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<bool> dp (n+1, false);
    dp[0] = true;   // marking first element as true as we will go from 1 to nth position
    
    int maxLength = 0;
    for (const string& word : wordDict) {
        maxLength = max(maxLength, (int)word.size());
    }

    for(int i=1; i<=n; i++){    // i=0 is already handled by dp[0] = true
        for(int j = i - 1; j >= max(i - maxLength - 1, 0); j--){   // we will check for every substring from j to i-j
            if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j,i-j)) != wordDict.end()){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n] ? 1 : 0;
     // time complexity = O(n^2.m) where n is length of string A and m is size of vector of strings B (wordDict)
    // space complexity = O(n)  => vector dp is used to store all the possibilities of words found
}
