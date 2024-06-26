/*
Question : 977. Squares of a Sorted Array
Date : 02-03-24
Problem Difficulty level : Easy
Related Topics : Array, Two Pointers, Sorting
Problem Statement:
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 
Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=0; i<n; i++){
            nums[i] *= nums[i];
        }

        int l=0, r= n-1;

        while(l <= r){
            if(nums[l] < nums[r]){
                res.push_back(nums[r]);
                r--;
            }
            else{
                res.push_back(nums[l]);
                l++;
            }
        }

        reverse(res.begin(), res.end());

        return res;

        // time = O(n)
        // space = O(n)
    }
};