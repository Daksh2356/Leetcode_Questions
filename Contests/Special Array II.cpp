/*

Question : 3152. Special Array II  ( contest 398 q2)
Date : 19-05-24
Problem Difficulty level : Medium
Related Topics : Dynammic Programming 

Problem Statement:

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray, nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 
Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parityBreaks(n, 0);

        // Precompute parity breaks
        for (int i = 1; i < n; ++i) {
            if ((nums[i - 1] % 2 == nums[i] % 2)) {
                parityBreaks[i] = 1;
            }
        }

        // Create a prefix sum array of parity breaks
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + parityBreaks[i];
        }

        vector<bool> result;
        
        // Answer queries
        for (auto& query : queries) {
            int from = query[0];
            int to = query[1];

            if (from == to) {
                // A single element or zero length subarray is always special
                result.push_back(true);
            } else {
                // Check if there are any parity breaks in the subarray
                int breaks = prefix[to] - prefix[from];
                result.push_back(breaks == 0);
            }
        }

        return result;
    }
};  