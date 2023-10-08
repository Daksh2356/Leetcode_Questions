/*
Question : 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
Date : 08-10-23
Problem Difficulty level : Hard
Related Topics : Dynammic Programming and Prefix Sum
Problem Statement:
You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

You should build the array arr which has the following properties:
1) arr has exactly n integers.
2) 1 <= arr[i] <= m where (0 <= i < n).
3) After applying the mentioned algorithm to arr, the value search_cost is equal to k.

Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be
computed modulo 10^9 + 7.

Example 1:
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.

Example 3:
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

Constraints:
1 <= n <= 50
1 <= m <= 100
0 <= k <= n
*/

class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prefix(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevDp(m + 1, vector<int>(k + 1, 0));
        vector<vector<int>> prevPrefix(m + 1, vector<int>(k + 1, 0));

        const int mod = 1e9 + 7;

        // setting up the initial state
        for (int j = 1; j <= m; j++)
        {
            prevDp[j][1] = 1;
            prevPrefix[j][1] = j;
        }

        // checking the condition for n -> arr.length
        for (int i = 2; i <= n; i++)
        {

            dp.assign(m + 1, vector<int>(k + 1, 0));
            prefix.assign(m + 1, vector<int>(k + 1, 0));
            // checking the maximum value in the array
            for (int max = 1; max <= m; max++)
            {
                // finding the search cost
                for (int cost = 1; cost <= k; cost++)
                {
                    dp[max][cost] = (static_cast<long long>(max) * prevDp[max][cost]) % mod;

                    if (max > 1 && cost > 1)
                    {
                        dp[max][cost] = (dp[max][cost] + prevPrefix[max - 1][cost - 1]) % mod;
                    }

                    prefix[max][cost] = (prefix[max - 1][cost] + dp[max][cost]) % mod;
                }
            }

            prevDp = dp;
            prevPrefix = prefix;
        }

        return prefix[m][k]; // return the value at bottom right corner of the prefix vector
    }

    // time complexity = O(n*m*k) -> for each arr.length, then each max value & then each cost
    // space complexity = O(m*k) -> for each max value and then each search cost
};