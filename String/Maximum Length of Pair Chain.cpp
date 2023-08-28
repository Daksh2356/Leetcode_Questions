/*
Question : 646. Maximum Length of Pair Chain
Date : 26-08-23
Problem Difficulty level : Medium
Related Topics : Array, String, Greedy and DP

Problem Statement:
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.


Example 1:
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Example 2:
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int  n = pairs.size();
        if(n<=1)
        return n;

        sort(pairs.begin(),pairs.end(), [] (const vector<int>&a , const vector<int>& b){
            return a[1]<b[1];
        });

        vector<int> dp (n,1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxChainLength = *max_element(dp.begin(), dp.end());
        return maxChainLength;
    }
    // time complexity = O(n^2) due to two loops formed
    // space complexity = O(n) due to dp vector formed
};