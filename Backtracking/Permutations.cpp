/*
Question : 46. Permutations
Date : 02-08-23
Problem Difficulty level : Medium
Related Topics : Array and backtracking

Problem Statement:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return answer;
    }

    void helper(vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            answer.push_back(nums);
        }
        
        for(int j=index; j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            helper(nums,index+1);
            swap(nums[index],nums[j]);
        }
    }

    // time complexity = O(n!)
    // space complexity = O(n*n!)
};