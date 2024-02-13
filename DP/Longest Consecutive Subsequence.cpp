/*
Question : 128. Longest Increasing Subsequence
Date : 12-02-24
Problem Difficulty level : Medium
Related Topics : Array, Hash Table, Union Find

Problem Statement:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &A)
    {
        int N = A.size();
        unordered_map<int, bool> mp;

        for (auto i : A)
        {
            mp[i] = true;
        }

        for (auto i : A)
        {
            if (mp.find(i - 1) != mp.end())
            {                  // finding prev element
                mp[i] = false; // mark curr as false if prev found
            }
        }

        int ctr = 0;

        for (int i = 0; i < N; i++)
        {
            if (mp[A[i]])
            {
                int j = 0;

                // counting all the consecutive elements from prev element found ( marked as true )
                while (mp.count(A[i] + j) > 0)
                {
                    j++;
                }

                ctr = max(ctr, j);
            }
        }

        return ctr;
    }

    // time = O(n)
    // space = O(n)
};