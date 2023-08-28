/*
Question : 403. Frog Jump
Date : 27-08-23
Problem Difficulty level : Hard
Related Topics : Array and DP
Problem Statement:
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. 
The frog can jump on a stone, but it must not jump into the water. 
Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river 
by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.


Example 1:
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

*/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp (n,vector<bool>(n+1,false));
        dp[0][0]= true;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff = stones[i] - stones[j];

                if(diff <= j+1)
                {
                    dp[i][diff] = dp[j][diff-1] || dp[j][diff] || dp[j][diff+1];
                    if(i == n-1 && dp[i][diff]) return true;
                }
            }
        }

        return false;
    }
    // time complexity = O(n^2)
    // space complexity = O(n^2)
};