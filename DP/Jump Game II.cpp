/*
! Question : 45. Jump Game II
? Date : 21-03-25
* Problem Difficulty level : Medium
Related Topics : Array, Dynamic Programming and Greedy

Problem Statement:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump 
to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
 

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
 
Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

*/

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;

        if (n == 1)
            return 0;

        int jumps=0, maxend=0, currend =0;

        for(int i=0; i<n-1; i++){
            maxend = Math.max(maxend, i + nums[i]);

            if(i == currend){
                jumps++;
                currend = maxend;
            }

            if(currend >= n-1) break;
        }

        return jumps;

        // time complexity = O(n)
        // space complexity = O(1)
    }
}

// recursive solution with dp:

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);  // Initialize memoization array
        return minJumps(nums, 0, dp);
    }

    private int minJumps(int[] nums, int index, int[] dp) {
        int n = nums.length;
        if (index >= n - 1) return 0;  // Base case: reached last index
        
        if (dp[index] != -1) return dp[index];  // Return stored result

        int minJumps = Integer.MAX_VALUE;
        for (int jump = 1; jump <= nums[index]; jump++) {
            int nextIndex = index + jump;
            if (nextIndex < n) {
                int jumpsFromNext = minJumps(nums, nextIndex, dp);
                if (jumpsFromNext != Integer.MAX_VALUE)
                    minJumps = Math.min(minJumps, 1 + jumpsFromNext);
            }
        }

        return dp[index] = minJumps;  // Store and return result
    }
}
