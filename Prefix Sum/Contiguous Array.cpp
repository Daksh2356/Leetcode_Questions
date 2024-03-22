/*
Question : 525. Contiguous Array
Date : 16-03-24 
Problem Difficulty level : Medium
Related Topics : Array, Hash Table and Prefix Sum
Problem Statement:
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     unordered_map<int,int> map;
     map[0] = -1;
     int maxLen = 0, count =0;
     int n = nums.size();

     for(int i=0; i<n; i++){
        count += (nums[i] == 1 )? 1 : -1; // increment count for 1 and decrement for 0
        if(map.find(count) != map.end()){ // cummulative count found in map
            // cout<<i<<" and "<<map[count];
            maxLen = max(maxLen, i - map[count]); // update maxlen if curr subarr length is longer
        }
        else{
            map[count] = i;  // insert new count in map if not found 
        }
     }

    //  time and space = O(n)

     return maxLen;

    }
};