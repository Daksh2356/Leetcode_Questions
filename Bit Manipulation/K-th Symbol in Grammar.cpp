/*
Question: 342. K-th Symbol in Grammar
Date : 25-10-23
Problem Difficulty level : Medium
Related Topics : Math, Bit Manipulation and Recursion
Problem Statement:

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each
occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

Example 1:
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0

Example 2:
Input: n = 2, k = 1
Output: 0
Explanation:
row 1: 0
row 2: 01

Example 3:
Input: n = 2, k = 2
Output: 1
Explanation:
row 1: 0
row 2: 01


Constraints:
1 <= n <= 30
1 <= k <= 2^(n - 1)

*/

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;

        int length = pow(2, n - 2); // calculating the length of (n-1)th row

        if (k <= length) // key 'k' is found in the first half of the nth row
            return kthGrammar(n - 1, k);
        else // key 'k' is found in the second half of the nth row
            return 1 - kthGrammar(n - 1, k - length);
    }

    // Time complexity = O(n) -> single recursive call for every row or level of n
    // Space complexity = O(n) -> stack space used by the recursive calls
};