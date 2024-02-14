/*
Question : 509. Fibonacci Number
Date : 14-02-24
Problem Difficulty level : Easy
Related Topics : Math, Dynamic Programming, Recursion, Memoization

Problem Statement:
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
0 <= n <= 10^9

*/
// The following solution is a mix of both recursive and memoization approach, taken in conisderation of the constraints (Interview Bit Q*)

class Solution
{
public:
    int fib(int A)
    {
        const int MOD = 1000000007;
        if (A == 0)
            return 0;
        if (A == 1 || A == 2)
            return 1;

        vector<vector<long long>> base = {{1, 1}, {1, 0}};
        vector<vector<long long>> result = {{1, 0}, {0, 1}};

        A = A - 1; // For 0-based indexing

        while (A > 0)
        {
            if (A % 2 == 1)
            {
                vector<vector<long long>> new_result(2, vector<long long>(2, 0));
                for (int i = 0; i < 2; ++i)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        for (int k = 0; k < 2; ++k)
                        {
                            new_result[i][j] = (new_result[i][j] + (result[i][k] * base[k][j]) % MOD) % MOD;
                        }
                    }
                }
                result = new_result;
            }
            vector<vector<long long>> new_base(2, vector<long long>(2, 0));
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    for (int k = 0; k < 2; ++k)
                    {
                        new_base[i][j] = (new_base[i][j] + (base[i][k] * base[k][j]) % MOD) % MOD;
                    }
                }
            }
            base = new_base;
            A /= 2;
        }

        return result[0][0] % MOD;
    }
};