/*
Question: 1220. Count Vowels Permutation
Date : 28-10-23
Problem Difficulty level : Hard
Related Topics : Dynamic Programming
Problem Statement:

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3:

Input: n = 5
Output: 68


Constraints:

1 <= n <= 2 * 10^4
*/

class Solution
{
public:
    int countVowelPermutation(int n)
    {

        const int MOD = 1e9 + 7;

        long long a = 1, e = 1, i = 1, o = 1, u = 1; // 5 strings of size 1 are possible

        for (int j = 1; j < n; j++) // for strings of size > 1
        {
            long long a_next = e; // next vowel depends on prev vowel in str of len= i-1
            long long e_next = (a + i) % MOD;
            long long i_next = (a + e + o + u) % MOD;
            long long o_next = (i + u) % MOD;
            long long u_next = a;

            a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;

            // updating the prev vowel with their new values for next iteration
        }

        return (a + e + i + o + u) % MOD; // sum of each string ending in these vowels is returned
    }

    // Time complexity = O(n) => linear approach is used from 1 till n-1
    // Space complexity = O(1)  => no additional space/data structure is used
};