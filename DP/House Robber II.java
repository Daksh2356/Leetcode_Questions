/*
!  Question 198: House Robber II
* Problem Difficulty level : Medium
? Related Topics : Array, Dynammic Programming
? Date : 09/03/2025

! Problem Statement:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses 
at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have
 a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same 
 night.

! Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob 
! tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

? Example 3:
Input: nums = [1,2,3]
Output: 3
    

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/


//!  CODE :
class Solution {

    public int solve(int index, int[] nums, int[] dp){
        if(index < 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        dp[index] = Math.max(nums[index] + solve(index-2, nums,dp), solve(index-1, nums,dp));

        return dp[index];
    }

    public int robRange(int[] nums, int start, int end){
        int n = end - start + 1;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        int[] subNums = Arrays.copyOfRange(nums, start, end+1);

        return solve(n-1, subNums, dp);

    }

    public int rob(int[] nums) {
        int n = nums.length;
        if(n==1)
            return nums[0];
        
        return Math.max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));

    }
    // time complexity = O(n)
    // space complexity = O(n)

}