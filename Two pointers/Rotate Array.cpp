/*
! Question: 823. Best Time to Buy and Sell Stocks
* Problem Difficulty level : Easy
? Related Topics : Array, DP

Problem Statement:

! Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

? Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

? Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
? Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?


*/


//!  CODE :

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) {
            int N = prices.size();
            int min = INT_MAX;
            int max = 0 ;
            for(int i = 0 ; i<N;i++)
            {
                if(min > prices[i])
                {
                    min = prices[i];
                }
                if(max < (prices[i]-min))
                {
                    max = prices[i]-min;
                }
            }
            return max;
        }
    // time complexity = O(N)
    // space complexity = O(1)
};  