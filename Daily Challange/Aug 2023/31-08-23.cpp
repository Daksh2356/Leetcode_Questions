/*
Question : 1326. Minimum Number of Taps to Open to Water a Garden
Date : 31-08-23
Problem Difficulty level : Hard
Related Topics : Array, DP and Greedy
Problem Statement:
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n, i.e The length of the garden is n.
There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means 
the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

Constraints:
1 <= n <= 10^4
ranges.length == n + 1
0 <= ranges[i] <= 100
*/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> right_most(n+1,-1);
        for(int i=0;i<=n;i++)
        {
            int min_idx = max(0,i-ranges[i]);
            int max_idx = min(n,i+ranges[i]);

            right_most[min_idx] = max(right_most[min_idx],max_idx);
        }

        int count =0;
        int furthest = 0;
        int current =0;

        for(int i=0;i<=n;i++)
        {
            if(i>furthest)
            {
                return -1;
            }

            if(i>current)
            {
                count +=1;
                current = furthest;
            }

            furthest = max(furthest,right_most[i]);
        }

        return count;
    }

    // time complexity = O(n)
    // space complexity = O(n)
};