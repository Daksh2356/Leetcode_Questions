/*

Question : 77. Combinations
Date : 01-08-23
Problem Difficulty level : Medium
Related Topics : Array and Backtracking

Problem Statement:
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.



*/

class Solution {
public:
    vector<vector<int>> ans;
    void combo(int start, int end, int k, vector<int> arr)
    {
        if(arr.size() == k)
        {
            ans.push_back(arr);
            return;
        }

        for(int i=start; i<=end; i++)
        {
            arr.push_back(i);
            combo(i+1,end,k,arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {   
        vector<int> arr;
        combo(1,n,k,arr);

        return ans;
    }
    // time and space complextity = O(C(n,k))
};