/*
Question : 215. Kth Largest Element in an Array
Date : 14-08-23
Problem Difficulty level : Medium
Related Topics : Array, Divide and Conquer, Sorting, Heap (Priority Queue) and Quickselect

Problem Statement:
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min_heap (nums.begin(),nums.begin() + k);

        for(int i =k; i<nums.size();i++)
        {
            if(nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
        
    }

    // time complexity = O(Nlogk)
    // space complexity = O(k)
};