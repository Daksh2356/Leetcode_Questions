/*
Question : 229. Majority Element II
// Date : 04-10-23
? Date : 22/02/25
Problem Difficulty level : Medium
Related Topics : Array, Hash Table, Sorting and Counting
Problem Statement:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3] 
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]


Constraints:
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9


Follow up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        
        int candidate_1 = -1, candidate_2 = -1, c1 = 0, c2=0;
        
        for(int num : nums){
            
            if(num == candidate_1)
                c1++;
            else if(num == candidate_2)
                c2++;
            else if(c1==0){
                candidate_1 = num;
                c1=1;
            }
            else if(c2 == 0){
                candidate_2 = num;
                c2 =1;
            }
            else{
                c1--; 
                c2--;
            }
        }
            
        c1 =0;
        c2 = 0;
        
        for(int num : nums){

            if(num == candidate_1) c1++;
            else if(num == candidate_2) c2++;
        }
        
        if(c1 > n/3 ) ans.add(candidate_1);
        if(c2 > n/3) ans.add(candidate_2);
        
        return ans;

        // time complexity = O(N)
        // space complexity = O(1) [ Since the space used is of the output List of Integer type]

    }
}