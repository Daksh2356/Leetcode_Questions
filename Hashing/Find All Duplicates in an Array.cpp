/*
Question: 442. Find All Duplicates in an Array
Date : 25-03-24
Problem Difficulty level : Medium
Related Topics : Array, Hash Table
Problem Statement:
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []
 
Constraints:
n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

// code : 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int map[n + 1];
        
        vector<int> answer;

        for(int i =0; i<n+1; i++){
            map[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        for (int i = 1; i <=n; i++) {
            if (map[i] > 1) {
                answer.push_back(i );
            }
        }

        return answer;
    }
    // space = O(n)
    // time = O(n)
};